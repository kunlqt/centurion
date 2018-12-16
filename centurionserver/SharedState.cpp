#include "SharedState.hpp"
#include "WebsocketSession.hpp"

shared_state::shared_state(boost::filesystem::path doc_root)
    : doc_root_(std::move(doc_root))
{
}

void shared_state::join(websocket_session& session)
{
    sessions_.insert(&session);
}

void shared_state::leave(websocket_session& session)
{
    sessions_.erase(&session);
}

void shared_state::send(std::string message)
{
    auto const ss = std::make_shared<std::string const>(std::move(message));
	for(auto session : sessions_)
        session->send(ss);
}
