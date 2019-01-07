#pragma once

#include "SharedState.hpp"
#include "DatabaseManager.h"
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <spdlog/logger.h>
#include <memory>

namespace net = boost::asio;                    // from <boost/asio.hpp>
namespace beast = boost::beast;                 // from <boost/beast.hpp>
namespace http = beast::http;                   // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;         // from <boost/beast/websocket.hpp>
using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>

/** Represents an established HTTP connection
*/
class http_session : public std::enable_shared_from_this<http_session>
{
	std::shared_ptr<spdlog::logger> log_;
    tcp::socket socket_;
    beast::flat_buffer buffer_;
    std::shared_ptr<shared_state> state_;
    // http::request<http::string_body> req_;
	http::request_parser<http::string_body> parser_;
	std::shared_ptr<centurion::DatabaseManager> dbm_;

    struct send_lambda
    {
        http_session& self_;

        explicit send_lambda(http_session& self)
            : self_(self)
        {
			
        }

        template<bool isRequest, class Body, class Fields>
        void operator()(http::message<isRequest, Body, Fields>&& msg) const;
    };

    void fail(beast::error_code ec, char const* what);
    void on_read(beast::error_code ec, std::size_t);
    void on_write(beast::error_code ec, std::size_t, bool close);

public:
    http_session(
        tcp::socket socket,
        std::shared_ptr<shared_state> const& state,
		std::shared_ptr<centurion::DatabaseManager> dbm);

    void run();
};

