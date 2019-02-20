#pragma once
#include "ServiceConfig.h"
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


struct DeleteMultipleDocumentsHandler {
	template<class Body, class Allocator>
	http::response<http::string_body> handle(
		std::shared_ptr<centurion::DatabaseManager> dbm,
		const std::vector<std::string>& pathComponents,
		http::request<Body, http::basic_fields<Allocator>>&& req,
		std::function<void(size_t)> progress) {
		auto log = spdlog::get("root");
		try {			
			centurion::DocumentIds documentIds;
			for (size_t pathIdx = 2; pathIdx < pathComponents.size(); pathIdx++)
			{
				documentIds.push_back(std::stol(pathComponents[pathIdx]));
			}
			auto deletedDocumentIds = dbm->removeDocuments(documentIds);
			const auto deleteResult = buildDeleteMultipleResult(deletedDocumentIds);
			http::response<http::string_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, ServerFullName);
			res.set(http::field::content_type, "application/json");
			// state->send(deleteResult);
			res.body() = deleteResult;
			res.keep_alive(req.keep_alive());
			return res;
		} catch (std::runtime_error& err) {
			http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
			res.set(http::field::server, ServerFullName);
			res.set(http::field::content_type, "text/html");
			res.keep_alive(req.keep_alive());
			res.body() = "An error occurred: '" + std::string(err.what()) + "'";
			res.prepare_payload();
			return res;
		}
	}

	std::string buildDeleteMultipleResult(const std::vector<std::pair<centurion::DocumentId, bool>>& docsDeleted) {
		rapidjson::Document doc(rapidjson::kObjectType);
		doc.AddMember(rapidjson::StringRef("status"), rapidjson::StringRef("delete_done"), doc.GetAllocator());
		rapidjson::Value documentIds(rapidjson::kArrayType);
		rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
		documentIds.Reserve(docsDeleted.size(), allocator);
		for (const auto& docDeleted : docsDeleted) {
			if (docDeleted.second) {
				documentIds.PushBack(docDeleted.first, allocator);
			}
		}
		doc.AddMember(rapidjson::StringRef("documents"), documentIds, doc.GetAllocator());
		rapidjson::StringBuffer result;
		rapidjson::Writer<rapidjson::StringBuffer> writer(result);
		doc.Accept(writer);
		return std::string(result.GetString(), result.GetSize());
	}
};

