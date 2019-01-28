#pragma once

#include "DatabaseManager.h"
#include <rapidjson/document.h>
#include <spdlog/logger.h>
#include <boost/asio.hpp>
#include <boost/beast.hpp>

namespace net = boost::asio;                    // from <boost/asio.hpp>
namespace beast = boost::beast;                 // from <boost/beast.hpp>
namespace http = beast::http;                   // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;         // from <boost/beast/websocket.hpp>
using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>


struct InsertMultipleDocumentsHandler {
	template<class Body, class Allocator>
	http::response<http::string_body> handle(
		std::shared_ptr<centurion::DatabaseManager> dbm,
		const std::string& databaseName,
		const std::string& collectionName,
		const http::request<Body, http::basic_fields<Allocator>>& req,
		std::function<void(size_t)> progress) {
		auto log = spdlog::get("root");
		try {
			rapidjson::Document rootDoc;
			log->trace("Parsing json file...");
			rootDoc.Parse(req.body().data());
			if (rootDoc.HasParseError())
			{
				throw std::runtime_error("an error occured while parsing JSON document");
			}
			centurion::DocumentIds documentIds;
			if (rootDoc.IsArray())
			{
				const auto& rootDocs = rootDoc.GetArray();
				documentIds.resize(rootDocs.Size(), centurion::InvalidDocumentId);
				dbm->insertMultipleDocuments(
					documentIds,
					rootDocs,
					[&progress](size_t val) { progress(val); }
				);
			} else if (rootDoc.IsObject()) {
				documentIds.push_back(dbm->insertSingleDocument(
					centurion::InvalidDocumentId,
					rootDoc,
					[&progress](size_t val) { progress(val); })
				);
			} else {
				throw std::runtime_error("Unsupported JSON root object, only Object and Array are supported as root element");
			}
			http::response<http::string_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "application/json");
			const auto insertResult = buildInsertMultipleResult(documentIds);
			// state->send(insertResult);
			res.body() = insertResult;
			res.keep_alive(req.keep_alive());
			return res;
		} catch (std::runtime_error& err) {
			http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.body() = "An error occurred: '" + std::string(err.what()) + "'";
			res.prepare_payload();
			return res;
		}
	}

	std::string buildInsertMultipleResult(const centurion::DocumentIds& docsInserted) {
		rapidjson::Document doc(rapidjson::kObjectType);
		doc.AddMember(rapidjson::StringRef("status"), rapidjson::StringRef("insert_done"), doc.GetAllocator());
		rapidjson::Value documentIds(rapidjson::kArrayType);
		rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
		documentIds.Reserve(docsInserted.size(), allocator);
		for (auto docInserted : docsInserted) {
			documentIds.PushBack(docInserted, allocator);
		}
		doc.AddMember(rapidjson::StringRef("documents"), documentIds, doc.GetAllocator());
		rapidjson::StringBuffer result;
		rapidjson::Writer<rapidjson::StringBuffer> writer(result);
		doc.Accept(writer);
		return std::string(result.GetString(), result.GetSize());
	}
};

