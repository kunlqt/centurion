#pragma once

#include "SharedState.hpp"
#include <boost/beast.hpp>
#include <boost/asio.hpp>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

namespace net = boost::asio;                    // from <boost/asio.hpp>
namespace beast = boost::beast;                 // from <boost/beast.hpp>
namespace http = beast::http;                   // from <boost/beast/http.hpp>
namespace websocket = beast::websocket;         // from <boost/beast/websocket.hpp>
using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>

// Forward declaration
class shared_state;

/** Represents an active WebSocket connection to the server
*/
class websocket_session : public std::enable_shared_from_this<websocket_session>
{
    beast::flat_buffer buffer_;
    websocket::stream<tcp::socket> ws_;
    std::shared_ptr<shared_state> state_;
    std::vector<std::shared_ptr<std::string const>> queue_;

    void fail(beast::error_code ec, char const* what);
    void on_accept(beast::error_code ec);
    void on_read(beast::error_code ec, std::size_t bytes_transferred);
    void on_write(beast::error_code ec, std::size_t bytes_transferred);

public:
    websocket_session(
        tcp::socket socket,
        std::shared_ptr<shared_state> const& state);

    ~websocket_session();

    template<class Body, class Allocator>
    void run(http::request<Body, http::basic_fields<Allocator>> req);

    // Send a message
    void send(std::shared_ptr<std::string const> const& ss);
};

template<class Body, class Allocator>
void websocket_session::run(http::request<Body, http::basic_fields<Allocator>> req)
{
    // Accept the websocket handshake
    ws_.async_accept(
        req,
        std::bind(
            &websocket_session::on_accept,
            shared_from_this(),
            std::placeholders::_1));
}
