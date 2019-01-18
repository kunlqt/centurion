#pragma once
#include "DatabaseManager.h"
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <spdlog/logger.h>
#include <memory>
#include <string>

namespace beast = boost::beast;                 // from <boost/beast.hpp>
namespace http = beast::http;                   // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;         // from <boost/beast/websocket.hpp>
namespace net = boost::asio;                    // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>

// Forward declaration
class shared_state;

// Accepts incoming connections and launches the sessions
class listener : public std::enable_shared_from_this<listener>
{
	std::shared_ptr<spdlog::logger> log_;
    tcp::acceptor acceptor_;
    tcp::socket socket_;
    std::shared_ptr<shared_state> state_;
	std::shared_ptr<centurion::DatabaseManager> dbm_;

    void fail(beast::error_code ec, char const* what);
    void on_accept(beast::error_code ec);

public:
    listener(
        net::io_context& ioc,
        tcp::endpoint endpoint,
        std::shared_ptr<shared_state> const& state,
		std::shared_ptr<centurion::DatabaseManager> dbm);

    // Start accepting incoming connections
    void run();
};

