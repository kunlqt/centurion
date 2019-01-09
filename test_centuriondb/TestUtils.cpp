#include "gtest/gtest.h"
#include <Utils.h>
#include <spdlog/spdlog.h>

TEST(TestUtils, TestRemoveSubfields) {
	auto console = spdlog::get("root");
	std::vector<std::string> result = { "a", "a.b", "a.b.c", "b.c.a", "b.c", "b", "c" };
	mergeOverlappingFields(result);
	ASSERT_EQ(result.size(), 3);
	ASSERT_EQ(result[0], "a");
	ASSERT_EQ(result[1], "b");
	ASSERT_EQ(result[2], "c");
}
