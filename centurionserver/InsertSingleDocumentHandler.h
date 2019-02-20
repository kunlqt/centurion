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


struct InsertSingleDocumentHandler {
	template<class Body, class Allocator>
	http::response<http::string_body> handle(
		std::shared_ptr<centurion::DatabaseManager> dbm,
		http::request<Body, http::basic_fields<Allocator>>&& req, 
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
			auto docsInserted = dbm->insertSingleDocument(
				centurion::InvalidDocumentId,
				rootDoc,
				[&progress](size_t value) { progress(value); }
			);
			http::response<http::string_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, ServerFullName);
			res.set(http::field::content_type, "application/json");
			const auto insertResult = buildInsertSingleResult(docsInserted);
			// state->send(insertResult);
			res.body() = insertResult;
			res.keep_alive(req.keep_alive());
			return res;
		} catch (std::runtime_error& err)
		{
			http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
			res.set(http::field::server, ServerFullName);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.body() = "An error occurred: '" + std::string(err.what()) + "'";
			res.prepare_payload();
			return res;
		}
	}

	std::string buildInsertSingleResult(centurion::DocumentId docInserted) {
		rapidjson::Document doc(rapidjson::kObjectType);
		doc.AddMember(rapidjson::StringRef("status"), rapidjson::StringRef("insert_done"), doc.GetAllocator());
		rapidjson::Value documentId(rapidjson::kNumberType);
		documentId.SetInt64(docInserted);
		doc.AddMember(rapidjson::StringRef("document"), documentId, doc.GetAllocator());
		rapidjson::StringBuffer result;
		rapidjson::Writer<rapidjson::StringBuffer> writer(result);
		doc.Accept(writer);
		return std::string(result.GetString(), result.GetSize());
	}	
};

