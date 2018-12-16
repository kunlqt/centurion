#include "HttpSession.hpp"
#include "WebsocketSession.hpp"
#include <boost/config.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>

#define BOOST_NO_CXX14_GENERIC_LAMBDAS

//------------------------------------------------------------------------------

// Return a reasonable mime type based on the extension of a file.
beast::string_view
mime_type(beast::string_view path)
{
    using beast::iequals;
    auto const ext = [&path]
    {
        auto const pos = path.rfind(".");
        if(pos == beast::string_view::npos)
            return beast::string_view{};
        return path.substr(pos);
    }();
    if(iequals(ext, ".htm"))  return "text/html";
    if(iequals(ext, ".html")) return "text/html";
    if(iequals(ext, ".php"))  return "text/html";
    if(iequals(ext, ".css"))  return "text/css";
    if(iequals(ext, ".txt"))  return "text/plain";
    if(iequals(ext, ".js"))   return "application/javascript";
    if(iequals(ext, ".json")) return "application/json";
    if(iequals(ext, ".xml"))  return "application/xml";
    if(iequals(ext, ".swf"))  return "application/x-shockwave-flash";
    if(iequals(ext, ".flv"))  return "video/x-flv";
    if(iequals(ext, ".png"))  return "image/png";
    if(iequals(ext, ".jpe"))  return "image/jpeg";
    if(iequals(ext, ".jpeg")) return "image/jpeg";
    if(iequals(ext, ".jpg"))  return "image/jpeg";
    if(iequals(ext, ".gif"))  return "image/gif";
    if(iequals(ext, ".bmp"))  return "image/bmp";
    if(iequals(ext, ".ico"))  return "image/vnd.microsoft.icon";
    if(iequals(ext, ".tiff")) return "image/tiff";
    if(iequals(ext, ".tif"))  return "image/tiff";
    if(iequals(ext, ".svg"))  return "image/svg+xml";
    if(iequals(ext, ".svgz")) return "image/svg+xml";
    return "application/text";
}

// Append an HTTP rel-path to a local filesystem path.
// The returned path is normalized for the platform.
std::string
path_cat(
    beast::string_view base,
    beast::string_view path)
{
    if(base.empty())
        return path.to_string();
    std::string result = base.to_string();
#if BOOST_MSVC
    char constexpr path_separator = '\\';
    if(result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());
    for(auto& c : result)
        if(c == '/')
            c = path_separator;
#else
    char constexpr path_separator = '/';
    if(result.back() == path_separator)
        result.resize(result.size() - 1);
    result.append(path.data(), path.size());
#endif
    return result;
}

// This function produces an HTTP response for the given
// request. The type of the response object depends on the
// contents of the request, so the interface requires the
// caller to pass a generic lambda for receiving the response.
template<
    class Body, class Allocator,
    class Send>
void
handle_request(
	centurion::DatabaseManager* dbm,
    beast::string_view doc_root,
    http::request<Body, http::basic_fields<Allocator>>&& req,
    Send&& send)
{
    // Returns a bad request response
    auto const bad_request =
    [&req](beast::string_view why)
    {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
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
        http::response<http::string_body> res{http::status::not_found, req.version()};
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
        http::response<http::string_body> res{http::status::internal_server_error, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "An error occurred: '" + what.to_string() + "'";
        res.prepare_payload();
        return res;
    };

	if (req.method() == http::verb::post)
	{
		if (boost::iends_with(req.target(), "/insert")) {
			if (req[http::field::content_type] == "application/json") {
				try {
					rapidjson::StringStream ss(req.body().data());
					auto docsInserted = dbm->insertDocuments(ss);
					http::response<http::string_body> res{ http::status::ok, req.version() };
					res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
					res.set(http::field::content_type, "application/json");
					res.body() = "Inserted total of: " + std::to_string(docsInserted) + " documents";
					res.keep_alive(req.keep_alive());
					return send(std::move(res));
				} catch (std::runtime_error& err)
				{
					http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
					res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
					res.set(http::field::content_type, "text/html");
					res.keep_alive(req.keep_alive());
					res.body() = "An error occurred: '" + std::string(err.what()) + "'";
					res.prepare_payload();
					return send(std::move(res));
				}
			}
		}
		if (boost::iends_with(req.target(), "/query")) {
			if (req[http::field::content_type] == "application/json") {
				try {
					rapidjson::StringStream ss(req.body().data());
					rapidjson::StringBuffer output;
					auto docsInserted = dbm->execQuery(ss, output);
					http::response<http::string_body> res{ http::status::ok, req.version() };
					res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
					res.set(http::field::content_type, "application/json");
					res.body() = output.GetString();
					res.keep_alive(req.keep_alive());
					return send(std::move(res));
				} catch (std::runtime_error& err)
				{
					http::response<http::string_body> res{ http::status::internal_server_error, req.version() };
					res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
					res.set(http::field::content_type, "text/html");
					res.keep_alive(req.keep_alive());
					res.body() = "An error occurred: '" + std::string(err.what()) + "'";
					res.prepare_payload();
					return send(std::move(res));
				}
			}
		}

	}

    // Make sure we can handle the method
    if( req.method() != http::verb::get &&
        req.method() != http::verb::head)
        return send(bad_request("Unknown HTTP-method"));

    // Request path must be absolute and not contain "..".
    if( req.target().empty() ||
        req.target()[0] != '/' ||
        req.target().find("..") != beast::string_view::npos)
        return send(bad_request("Illegal request-target"));

    // Build the path to the requested file
    std::string path = path_cat(doc_root, req.target());
    if(req.target().back() == '/')
        path.append("index.html");

    // Attempt to open the file
    beast::error_code ec;
    http::file_body::value_type body;
    body.open(path.c_str(), beast::file_mode::scan, ec);

    // Handle the case where the file doesn't exist
    if(ec == boost::system::errc::no_such_file_or_directory)
        return send(not_found(req.target()));

    // Handle an unknown error
    if(ec)
        return send(server_error(ec.message()));

    // Cache the size since we need it after the move
    auto const size = body.size();

    // Respond to HEAD request
    if(req.method() == http::verb::head)
    {
        http::response<http::empty_body> res{http::status::ok, req.version()};
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
        std::make_tuple(http::status::ok, req.version())};
    res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
    res.set(http::field::content_type, mime_type(path));
    res.content_length(size);
    res.keep_alive(req.keep_alive());
    return send(std::move(res));
}

//------------------------------------------------------------------------------

http_session::http_session(
    tcp::socket socket,
    std::shared_ptr<shared_state> const& state,
	std::shared_ptr<centurion::DatabaseManager> dbm)
    : socket_(std::move(socket))
    , state_(state)
	, dbm_(dbm)
{
	parser_.body_limit((std::numeric_limits<std::uint64_t>::max)());
}

void http_session::run()
{
	http::async_read(socket_, buffer_, parser_, 
		std::bind(
			&http_session::on_read,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2)
	);
	
	/*
    // Read a request
	http::async_read(socket_, buffer_, req_,
        std::bind(
            &http_session::on_read,
            shared_from_this(),
            std::placeholders::_1,
            std::placeholders::_2));
	*/
}

// Report a failure
void http_session::fail(beast::error_code ec, char const* what)
{
    // Don't report on canceled operations
    if(ec == net::error::operation_aborted)
        return;

    std::cerr << what << ": " << ec.message() << "\n";
}

template<bool isRequest, class Body, class Fields>
void http_session::send_lambda::operator()(http::message<isRequest, Body, Fields>&& msg) const
{
    // The lifetime of the message has to extend
    // for the duration of the async operation so
    // we use a shared_ptr to manage it.
    auto sp = std::make_shared<
        http::message<isRequest, Body, Fields>>(std::move(msg));

    // Write the response
    auto self = self_.shared_from_this();
    http::async_write(
        self_.socket_,
        *sp,
        [self, sp](beast::error_code ec, std::size_t bytes)
        {
            self->on_write(ec, bytes, sp->need_eof());
        });
}

void http_session::on_read(beast::error_code ec, std::size_t)
{
    // This means they closed the connection
    if(ec == http::error::end_of_stream)
    {
        socket_.shutdown(tcp::socket::shutdown_send, ec);
        return;
    }

    // Handle the error, if any
    if(ec)
        return fail(ec, "read");

    // See if it is a WebSocket Upgrade
    if(websocket::is_upgrade(parser_.get() /*req_*/))
    {
        // Create a WebSocket session by transferring the socket
        std::make_shared<websocket_session>(std::move(socket_), state_)->run(std::move(parser_.get() /*req_*/));
        return;
    }

    // Send the response
#ifndef BOOST_NO_CXX14_GENERIC_LAMBDAS
    //
    // The following code requires generic
    // lambdas, available in C++14 and later.
    //
    handle_request(
        state_->doc_root(),
        std::move(req_),
        [this](auto&& response)
        {
            // The lifetime of the message has to extend
            // for the duration of the async operation so
            // we use a shared_ptr to manage it.
            using response_type = typename std::decay<decltype(response)>::type;
            auto sp = std::make_shared<response_type>(std::forward<decltype(response)>(response));

        #if 0
            // NOTE This causes an ICE in gcc 7.3
            // Write the response
            http::async_write(this->socket_, *sp,
				[self = shared_from_this(), sp](
					beast::error_code ec, std::size_t bytes)
				{
					self->on_write(ec, bytes, sp->need_eof()); 
				});
        #else
            // Write the response
            auto self = shared_from_this();
            http::async_write(this->socket_, *sp,
				[self, sp](
					beast::error_code ec, std::size_t bytes)
				{
					self->on_write(ec, bytes, sp->need_eof()); 
				});
        #endif
        });
#else
    //
    // This code uses the function object type send_lambda in
    // place of a generic lambda which is not available in C++11
    //
    handle_request(
		dbm_.get(),
        state_->doc_root().string(),
        std::move(parser_.get() /* req_ */),
        send_lambda(*this));

#endif
}

void http_session::on_write(beast::error_code ec, std::size_t, bool close)
{
    // Handle the error, if any
    if(ec)
        return fail(ec, "write");

    if(close)
    {
        // This means we should close the connection, usually because
        // the response indicated the "Connection: close" semantic.
        socket_.shutdown(tcp::socket::shutdown_send, ec);
        return;
    }

    // Clear contents of the request message,
    // otherwise the read behavior is undefined.
 //   req_ = {};

    // Read another request
	http::request_parser<http::string_body> parser;
	parser.body_limit((std::numeric_limits<std::uint64_t>::max)());

/*
	http::async_read(socket_, buffer_, req_,
        std::bind(
            &http_session::on_read,
            shared_from_this(),
            std::placeholders::_1,
            std::placeholders::_2));
*/
}
