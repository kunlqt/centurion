#include <gtest/gtest.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main(int argc, char* argv[])
{
	auto rootLogger = spdlog::stdout_color_mt("root");
	rootLogger->set_level(spdlog::level::trace);

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
