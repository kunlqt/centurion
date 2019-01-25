// #define _CRTDBG_MAP_ALLOC  
// #include <stdlib.h>  
// #include <crtdbg.h>  

#include "DatabaseManager.h"
#include "Listener.hpp"
#include "SharedState.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <iostream>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

struct ServiceConfig {
	std::shared_ptr<tcp::endpoint> listenEndpoint;
        std::shared_ptr<shared_state> sharedState;
        std::shared_ptr<fs::path> dbRoot;
       	std::shared_ptr<fs::path> webRoot;
       	std::shared_ptr<std::string> jwtSecret;
};

void startService(ServiceConfig& config);

int main(int argc, char* argv[])
{
	std::string address;
	std::uint16_t port;
	fs::path db_root;
	fs::path doc_root;
	int logLevel;
	std::string jwtSecret;

	po::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("ip", po::value<std::string>(&address)->required()->default_value(net::ip::address_v4::loopback().to_string()), "listen on ip address")
		("port", po::value<std::uint16_t>(&port)->required()->default_value(8080), "listen on port")
		("db", po::value<fs::path>(&db_root)->required(), "database files directory")
		("web", po::value<fs::path>(&doc_root)->required(), "website static files directory")
		("jwt", po::value<std::string>(&jwtSecret)->required(), "JWT secret used to sign JWT tokens")
		("log-level", po::value<int>(&logLevel)->default_value(spdlog::level::trace), "log level: 0 - trace, 1 - debug, 2 - info, 3 - warnings, 4 - errors, 5 - critical, 6 - disable logging")
	;
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	try {
		po::notify(vm);
	} catch (const po::required_option& exc) {
		std::cerr << exc.what() << std::endl;
		std::cerr << desc << std::endl;
		return EXIT_FAILURE;
	}
	if (vm.count("help")) {
		std::cerr << desc << std::endl;
		return EXIT_FAILURE;
	}

	auto rootLogger = spdlog::stdout_color_mt("root");
	rootLogger->set_level(static_cast<spdlog::level::level_enum>(logLevel));
	rootLogger->info("Service started...");
	boost::system::error_code ec;
	auto ipAddress = net::ip::make_address(address, ec);
	if (ec) {
		rootLogger->error("Invalid ip address argument: {}", ec.message());
		return EXIT_FAILURE;
	}

	if (!boost::filesystem::exists(db_root))
	{
		rootLogger->error("DB directory {} does not exists", db_root.string());
		return EXIT_FAILURE;
	}

	if (!boost::filesystem::exists(doc_root))
	{
		rootLogger->error("html document directory {} does not exists", doc_root.string());
		return EXIT_FAILURE;
	}

	if (!boost::filesystem::exists(doc_root / "index.html"))
	{
		rootLogger->error("index.html doesn't exist in the document directory {}", doc_root.string());
		return EXIT_FAILURE;
	}

	rootLogger->trace("Service started..");	
	startService(ipAddress, port, db_root, doc_root);
	rootLogger->info("Service stopped!");

	// rootLogger->trace("Dumping memory...");
	// _CrtDumpMemoryLeaks();
	// rootLogger->trace("Finished dumping memory!");

	// (If we get here, it means we got a SIGINT or SIGTERM)
	return EXIT_SUCCESS;
}

void startService(ServiceConfig& config) {
	// The io_context is required for all I/O
	net::io_context ioc;
	// Create and launch a listening port
	std::make_shared<listener>(
		ioc,
		tcp::endpoint{ ipAddress, port },
		std::make_shared<shared_state>(doc_root),
		std::make_shared<centurion::DatabaseManager>(db_root))->run();

	// Capture SIGINT and SIGTERM to perform a clean shutdown
	net::signal_set signals(ioc, SIGINT, SIGTERM);
	signals.async_wait(
		[&ioc](boost::system::error_code const&, int)
	{
		// Stop the io_context. This will cause run()
		// to return immediately, eventually destroying the
		// io_context and any remaining handlers in it.
		ioc.stop();
	});

	// Run the I/O service on the main thread
	ioc.run();
}
