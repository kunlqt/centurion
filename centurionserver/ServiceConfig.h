#pragma once
#include <boost/filesystem.hpp>
#include <boost/asio/ip/address.hpp>
#include <memory>
#include <string>
#include <boost/asio/ip/tcp.hpp>

namespace fs = boost::filesystem;

struct ServiceConfig {
	std::shared_ptr<boost::asio::ip::tcp::endpoint> listenEndpoint;
	std::shared_ptr<fs::path> dbRoot;
	std::shared_ptr<fs::path> webRoot;
	std::shared_ptr<std::string> jwtSecret;
};
