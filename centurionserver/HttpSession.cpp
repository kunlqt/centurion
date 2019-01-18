#include "HttpSession.hpp"
#include "WebsocketSession.hpp"
#include "QueryDocumentHandler.h"
#include <boost/config.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include "HttpRequestHandler.h"

#define BOOST_NO_CXX14_GENERIC_LAMBDAS

//------------------------------------------------------------------------------

http_session::http_session(
    tcp::socket socket,
    std::shared_ptr<shared_state> const& state,
	std::shared_ptr<centurion::DatabaseManager> dbm)
    : socket_(std::move(socket))
    , state_(state)
	, dbm_(dbm)
{
	log_ = spdlog::get("root")->clone("http_session");
	parser_.body_limit((std::numeric_limits<std::uint64_t>::max)());
}

void http_session::run()
{
	log_->trace("started");
	http::async_read(socket_, buffer_, parser_, 
		std::bind(
			&http_session::on_read,
			shared_from_this(),
			std::placeholders::_1,
			std::placeholders::_2)
	);
}

// Report a failure
void http_session::fail(beast::error_code ec, char const* what) const
{
    // Don't report on canceled operations
    if(ec == net::error::operation_aborted)
        return;
	log_->error(what);
	log_->error(ec.message());
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
		state_,
        state_->doc_root().string(),
        std::move(parser_.get()),
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
 
    // Read another request
	http::request_parser<http::string_body> parser;
	parser.body_limit((std::numeric_limits<std::uint64_t>::max)());

}
