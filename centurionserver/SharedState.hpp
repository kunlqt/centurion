#pragma once

#include <boost/filesystem/path.hpp>
#include <memory>
#include <string>
#include <unordered_set>

// Forward declaration
class websocket_session;

// Represents the shared server state
class shared_state
{
	boost::filesystem::path doc_root_;

    // This simple method of tracking
    // sessions only works with an implicit
    // strand (i.e. a single-threaded server)
    std::unordered_set<websocket_session*> sessions_;

public:
    explicit shared_state(boost::filesystem::path doc_root);

	boost::filesystem::path const&
    doc_root() const noexcept
    {
        return doc_root_;
    }

    void join  (websocket_session& session);
    void leave (websocket_session& session);
    void send  (std::string message);
};

