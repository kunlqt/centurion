#include "DatabaseManager.h"
#include "Listener.hpp"
#include "SharedState.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	auto rootLogger = spdlog::stdout_color_mt("root");
	rootLogger->set_level(spdlog::level::err);

	// Check command line arguments.
	if (argc != 5)
	{
		std::cerr <<
			"Usage: centurion <address> <port> <database_root> <public_doc_root>\n" <<
			"Example:\n" << "    centurion 0.0.0.0 8080 .\n";
		return EXIT_FAILURE;
	}
	auto address = net::ip::make_address(argv[1]);
	auto port = static_cast<unsigned short>(std::atoi(argv[2]));
	auto db_root = boost::filesystem::path(argv[3]);
	auto doc_root = boost::filesystem::path(argv[4]);

	if (!boost::filesystem::exists(db_root))
	{
		rootLogger->error("DB directory {} does not exists", db_root.string());
		return 0;
	}

	if (!boost::filesystem::exists(doc_root))
	{
		rootLogger->error("html document directory {} does not exists", doc_root.string());
		return 0;
	}

	if (!boost::filesystem::exists(doc_root / "index.html"))
	{
		rootLogger->error("index.html doesn't exist in the document directory {}", doc_root.string());
		return 0;
	}


	// The io_context is required for all I/O
	net::io_context ioc;

	// Create and launch a listening port
	std::make_shared<listener>(
		ioc,
		tcp::endpoint{ address, port },
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

	// (If we get here, it means we got a SIGINT or SIGTERM)

	return EXIT_SUCCESS;
}


#if 0

#endif

/*
int main(int argc, char* argv[]) {

	rootLogger->info("CenturionDB service started");
	//loadDocuments();
	query();

}
*/
