#include "WebsocketSession.hpp"

websocket_session::websocket_session(
    tcp::socket socket,
    std::shared_ptr<shared_state> const& state)
    : ws_(std::move(socket))
    , state_(state)
{
}

websocket_session::~websocket_session()
{
    // Remove this session from the list of active sessions
    state_->leave(*this);
}

void websocket_session::fail(beast::error_code ec, char const* what)
{
    // Don't report these
    if( ec == net::error::operation_aborted ||
        ec == websocket::error::closed)
        return;
	log_->error(what);
	log_->error(ec.message());
}

void websocket_session::on_accept(beast::error_code ec)
{
    // Handle the error, if any
    if(ec)
        return fail(ec, "accept");

    // Add this session to the list of active sessions
    state_->join(*this);

    // Read a message
    ws_.async_read(
        buffer_,
        std::bind(
            &websocket_session::on_read,
            shared_from_this(),
            std::placeholders::_1,
            std::placeholders::_2));
}

void websocket_session::on_read(beast::error_code ec, std::size_t)
{
    // Handle the error, if any
    if(ec)
        return fail(ec, "read");

    // Send to all connections
    state_->send(beast::buffers_to_string(buffer_.data()));

    // Clear the buffer
    buffer_.consume(buffer_.size());

    // Read another message
    ws_.async_read(
        buffer_,
        std::bind(
            &websocket_session::on_read,
            shared_from_this(),
            std::placeholders::_1,
            std::placeholders::_2));
}

void websocket_session::send(std::shared_ptr<std::string const> const& ss)
{
    // Always add to queue
    queue_.push_back(ss);

    // Are we already writing?
    if(queue_.size() > 1)
        return;

    // We are not currently writing, so send this immediately
    ws_.async_write(
        net::buffer(*queue_.front()),
        std::bind(
            &websocket_session::on_write,
            shared_from_this(),
            std::placeholders::_1,
            std::placeholders::_2));
}

void websocket_session::on_write(beast::error_code ec, std::size_t)
{
    // Handle the error, if any
    if(ec)
        return fail(ec, "write");

    // Remove the string from the queue
    queue_.erase(queue_.begin());

    // Send the next message if any
    if(! queue_.empty())
        ws_.async_write(
            net::buffer(*queue_.front()),
            std::bind(
                &websocket_session::on_write,
                shared_from_this(),
                std::placeholders::_1,
                std::placeholders::_2));
}
