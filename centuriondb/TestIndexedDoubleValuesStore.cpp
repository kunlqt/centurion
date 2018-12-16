#include "gtest/gtest.h"
#include "IndexNameStore.h"
#include "DoubleValueIndexStore.h"
#include "DoubleValueSearchIterator.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

TEST(TestIndexedDoubleValueStore, TestIndexDoubleValue) {
	auto console = spdlog::get("console");
	centurion::IndexNameStore indexNameStore("instore", true);
	centurion::DoubleValueIndexStore isvs("ivstore", true);
	centurion::IndexId idx = 5;
	ASSERT_TRUE(isvs.add(idx, 234, 5));
	ASSERT_TRUE(isvs.add(idx, 246, 7));
	ASSERT_TRUE(isvs.add(idx, 279, 3));
	ASSERT_TRUE(isvs.add(idx, 380, 8));
	auto eqIterator = centurion::DoubleValueSearchIterator::eq(isvs, idx, 246/*, 10e-5*/);
	ASSERT_TRUE(eqIterator->valid());
	ASSERT_EQ(eqIterator->current(), 7);
	eqIterator->next();
	ASSERT_FALSE(eqIterator->valid());
	delete eqIterator;
}
