#pragma once
#include "InsertSingleDocumentHandler.h"
#include "InsertMultipleDocumentsHandler.h"
#include "QueryDocumentsHandler.h"
#include "SharedState.hpp"
#include "DatabaseManager.h"
#include "MimeTypes.h"
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
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

	if (req.method() == http::verb::post)
	{
		if (boost::iends_with(req.target(), "/insert")) {
			if (req[http::field::content_type] == "application/json") {
				InsertSingleDocumentHandler insertSingleDocumentHandler;
				return send(
					insertSingleDocumentHandler.handle<Body, Allocator>(
						dbm,
						req,
						[&buildStatusProgress, &state](size_t progress) { state->send(buildStatusProgress(progress)); })
					);
			}
		}

		if (boost::iends_with(req.target(), "/insert_multiple")) {
			if (req[http::field::content_type] == "application/json") {
				InsertMultipleDocumentsHandler insertMutipleDocumentsHandler;
				return send(
					insertMutipleDocumentsHandler.handle<Body, Allocator>(
						dbm,
						req,
						[&buildStatusProgress, &state](size_t progress) { state->send(buildStatusProgress(progress)); })
				);
			}
		}

		if (boost::iends_with(req.target(), "/query")) {
			if (req[http::field::content_type] == "application/sql") {
				QueryDocumentsHandler queryDocumentsHandler;
				return send(queryDocumentsHandler.handle<Body, Allocator>(dbm,req));
			}
		}
	}

	// Make sure we can handle the method
	if (req.method() != http::verb::get &&
		req.method() != http::verb::head)
		return send(bad_request("Unknown HTTP-method"));

	// Request path must be absolute and not contain "..".
	if (req.target().empty() ||
		req.target()[0] != '/' ||
		req.target().find("..") != beast::string_view::npos)
		return send(bad_request("Illegal request-target"));

	// Build the path to the requested file
	boost::filesystem::path path = *doc_root / req.target().to_string();
	if (req.target().back() == '/')
		path.append("index.html");

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
