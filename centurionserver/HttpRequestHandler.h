#pragma once
#include "InsertSingleDocumentHandler.h"
#include "InsertMultipleDocumentsHandler.h"
#include "QueryDocumentsHandler.h"
#include "SharedState.hpp"
#include "DatabaseManager.h"
#include "MimeTypes.h"
#include "UriExtractor.h"
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/algorithm/string.hpp>
#include <spdlog/logger.h>
#include <memory>

namespace net = boost::asio;                    // from <boost/asio.hpp>
namespace beast = boost::beast;                 // from <boost/beast.hpp>
namespace http = beast::http;                   // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;         // from <boost/beast/websocket.hpp>
using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>

//------------------------------------------------------------------------------


// This function produces an HTTP response for the given
// request. The type of the response object depends on the
// contents of the request, so the interface requires the
// caller to pass a generic lambda for receiving the response.
template<class Body, class Allocator, class Send>
	void handle_request(
		tcp::endpoint ep,
		std::shared_ptr<centurion::DatabaseManager> dbm,
		std::shared_ptr<shared_state> const& state,
		std::shared_ptr<boost::filesystem::path> doc_root,
		http::request<Body, http::basic_fields<Allocator>>&& req,
		Send&& send)
{
	auto log = spdlog::get("root");

	// Returns a bad request response
	auto const bad_request =
		[&req](beast::string_view why)
	{
		http::response<http::string_body> res{ http::status::bad_request, req.version() };
		res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
		res.set(http::field::content_type, "text/html");
		res.keep_alive(req.keep_alive());
		res.body() = why.to_string();
		res.prepare_payload();
		return res;
	};

	// Returns a not found response
	auto const not_found =
		[&req](beast::string_view target)
	{
		http::response<http::string_body> res{ http::status::not_found, req.version() };
		res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
		res.set(http::field::content_type, "text/html");
		res.keep_alive(req.keep_alive());
		res.body() = "The resource '" + target.to_string() + "' was not found.";
		res.prepare_payload();
		return res;
	};

	// Returns a server error response
	auto const server_error =
		[&req](beast::string_view what)
	{
		http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
		res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
		res.set(http::field::content_type, "text/html");
		res.keep_alive(req.keep_alive());
		res.body() = "An error occurred: '" + what.to_string() + "'";
		res.prepare_payload();
		return res;
	};

	auto const buildStatusProgress = [](size_t progress) {
		rapidjson::Document doc(rapidjson::kObjectType);
		doc.AddMember(rapidjson::StringRef("status"), rapidjson::StringRef("insert_in_progress"), doc.GetAllocator());
		doc.AddMember(rapidjson::StringRef("progress"), rapidjson::Value().SetInt64(progress), doc.GetAllocator());
		rapidjson::StringBuffer result;
		rapidjson::Writer<rapidjson::StringBuffer> writer(result);
		doc.Accept(writer);
		return std::string(result.GetString(), result.GetSize());
	};		
	UriExtractor uriExtractor;
	std::vector<std::string> pathComponents;
	std::vector<std::pair<std::string, std::string>> queryParams;
	uriExtractor.Parse(req.target(), pathComponents, queryParams);
	if (req.method() == http::verb::post)
	{
		if (pathComponents.size() == 1)
		{
			if (req[http::field::content_type] == "application/sql") {
				QueryDocumentsHandler queryDocumentsHandler;
				return send(queryDocumentsHandler.handle<Body, Allocator>(dbm, pathComponents[0], req));
			}
			if (pathComponents.front() == "system")
			{
				// todo: handle this
			}
			return send(bad_request("Invalid POST method, valid insert document format: POST /database/collection Content-Type: application/json, valid query format: POST /database Content-Type: application/sql"));
		}
		if (pathComponents.size() != 2)
		{
			return send(bad_request("Invalid POST method, valid insert document format: POST /database/collection Content-Type: application/json, valid query format: POST /database Content-Type: application/sql"));
		}
		if (req[http::field::content_type] != "application/json") {
			return send(bad_request("Invalid POST method, valid insert document format: POST /database/collection Content-Type: application/json, valid query format: POST /database Content-Type: application/sql"));
		}
		InsertMultipleDocumentsHandler insertMutipleDocumentsHandler;
		return send(
			insertMutipleDocumentsHandler.handle<Body, Allocator>(
				dbm,
				pathComponents[0],
				pathComponents[1],
				req,
				[&buildStatusProgress, &state](size_t progress) { state->send(buildStatusProgress(progress)); })
		);
	}

	if (req.method() == http::verb::delete_)
	{
		if (pathComponents.size() <= 2)
		{
			return send(bad_request("Invalid DELETE method, valid delete documents format: DELETE /database/collection/documentId1/documentId2/documentIdN"));
		}
	}

	if (req.method() == http::verb::put || req.method() == http::verb::patch)
	{
		if (pathComponents.size() <= 2)
		{
			return send(bad_request("Invalid PUT or PATCH method, valid update (complete update using PUT or partial update using PATCH) documents format: PUT or PATCH /database/collection/documentId1/documentId2/documentIdN"));
		}
		if (req[http::field::content_type] != "application/json") {
			return send(bad_request("Invalid content type for PUT or PATCH method, only application/json is supported"));
		}
	}

	if ((req.method() == http::verb::get || req.method() == http::verb::head))
	{
		// Build the path to the requested file
		boost::filesystem::path path = *doc_root;
		if (pathComponents.empty()) {
			path.append("index.html");
		} else {
			for (const auto& pathComponent : pathComponents) {
				if (pathComponent == "." || pathComponent == "..") {
					return send(bad_request("Invalid URL"));
				}
				path /= pathComponent;
			}
		}
		if (!boost::starts_with(path.string(), doc_root->string())) {
			return send(bad_request("Invalid URL"));
		}
		// Attempt to open the file
		beast::error_code ec;
		http::file_body::value_type body;
		body.open(path.string().c_str(), beast::file_mode::scan, ec);

		// Handle the case where the file doesn't exist
		if (ec == boost::system::errc::no_such_file_or_directory)
			return send(not_found(req.target()));

		// Handle an unknown error
		if (ec)
			return send(server_error(ec.message()));

		// Cache the size since we need it after the move
		auto const size = body.size();
		// Respond to HEAD request
		if (req.method() == http::verb::head)
		{
			http::response<http::empty_body> res{ http::status::ok, req.version() };
			res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
			res.set(http::field::content_type, mime_type(path));
			res.content_length(size);
			res.keep_alive(req.keep_alive());
			return send(std::move(res));
		}
		// Respond to GET request
		http::response<http::file_body> res{
			std::piecewise_construct,
			std::make_tuple(std::move(body)),
			std::make_tuple(http::status::ok, req.version()) };
		res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
		res.set(http::field::content_type, mime_type(path));
		res.content_length(size);
		res.keep_alive(req.keep_alive());
		return send(std::move(res));
	}	
	return send(bad_request("Unsupported method or object not found"));
}
