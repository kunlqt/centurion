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

struct QueryDocumentsHandler
{
	template<class Body, class Allocator>
	http::response<http::string_body> handle(std::shared_ptr<centurion::DatabaseManager> dbm,
		const http::request<Body, http::basic_fields<Allocator>>& req) {
		auto log = spdlog::get("root");
		try {
			log->trace("handling /query sql request");
			http::response<http::string_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "application/json");
			rapidjson::StringBuffer resultsString;
			rapidjson::Writer<rapidjson::StringBuffer> writer(resultsString);
			rapidjson::Document results;
			handle(dbm, req.body(), results);
			if (results.Accept(writer)) {
				res.body() = resultsString.GetString();
			}
			res.keep_alive(req.keep_alive());
			return res;
		} catch (std::runtime_error& err)
		{
			log->error("An error while query db: {0}", err.what());
			http::response<http::string_body> res{ http::status::bad_request, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "application/json");
			rapidjson::Document doc(rapidjson::kObjectType);
			doc.AddMember(rapidjson::StringRef("status"), rapidjson::StringRef("error"), doc.GetAllocator());
			doc.AddMember(rapidjson::StringRef("message"), rapidjson::StringRef(err.what()), doc.GetAllocator());
			rapidjson::StringBuffer result;
			rapidjson::Writer<rapidjson::StringBuffer> writer(result);
			doc.Accept(writer);
			res.body() = result.GetString();
			res.keep_alive(req.keep_alive());
			res.prepare_payload();
			return res;
		} catch (...)
		{
			log->error("Unknown error while query DB");
			http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, "application/json");
			rapidjson::Document doc(rapidjson::kObjectType);
			doc.AddMember(rapidjson::StringRef("status"), rapidjson::StringRef("error"), doc.GetAllocator());
			doc.AddMember(rapidjson::StringRef("message"), rapidjson::StringRef("Internal error"), doc.GetAllocator());
			rapidjson::StringBuffer result;
			rapidjson::Writer<rapidjson::StringBuffer> writer(result);
			doc.Accept(writer);
			res.body() = result.GetString();
			res.keep_alive(req.keep_alive());
			res.prepare_payload();
			return res;
		}
	}


private:
	void handle(std::shared_ptr<centurion::DatabaseManager> dbm, const std::string& query, rapidjson::Document& results);
};
