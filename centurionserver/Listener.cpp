#include "Listener.hpp"
#include "HttpSession.hpp"
#include <iostream>

listener::listener(
    net::io_context& ioc,
    tcp::endpoint endpoint,
    std::shared_ptr<shared_state> const& state,
	std::shared_ptr<centurion::DatabaseManager> dbm)
    : acceptor_(ioc)
    , socket_(ioc)
    , state_(state)
	, dbm_(dbm)
{
    beast::error_code ec;

    // Open the acceptor
    acceptor_.open(endpoint.protocol(), ec);
    if(ec)
    {
        fail(ec, "open");
        return;
    }

    // Allow address reuse
    acceptor_.set_option(net::socket_base::reuse_address(true));
    if(ec)
    {
        fail(ec, "set_option");
        return;
    }

    // Bind to the server address
    acceptor_.bind(endpoint, ec);
    if(ec)
    {
        fail(ec, "bind");
        return;
    }

    // Start listening for connections
    acceptor_.listen(net::socket_base::max_listen_connections, ec);
    if(ec)
    {
        fail(ec, "listen");
        return;
    }
}

void listener::run()
{
    // Start accepting a connection
    acceptor_.async_accept(
        socket_,
        std::bind(
            &listener::on_accept,
            shared_from_this(),
            std::placeholders::_1));
}

// Report a failure
void listener::fail(beast::error_code ec, char const* what)
{
    // Don't report on canceled operations
    if(ec == net::error::operation_aborted)
        return;
    std::cerr << what << ": " << ec.message() << "\n";
}

// Handle a connection
void listener::on_accept(beast::error_code ec)
{
    if(ec)
        return fail(ec, "accept");
    else
        // Launch a new session for this connection
        std::make_shared<http_session>(
            std::move(socket_),
            state_,
			dbm_)->run();

    // Accept another connection
    acceptor_.async_accept(
        socket_,
        std::bind(
            &listener::on_accept,
            shared_from_this(),
            std::placeholders::_1));
}
