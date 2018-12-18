#include "gtest/gtest.h"
#include "IndexNameStore.h"
#include "DocumentIndexer.h"
#include "BooleanValueIndexStore.h"
#include "BooleanValueSearchIterator.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

TEST(TestIndexedBooleanValueStore, TestBooleanStringValue) {
	auto console = spdlog::get("root");
	centurion::IndexNameStore indexNameStore("instore", true);
	centurion::BooleanValueIndexStore isvs("ivstore", true);
	centurion::IndexId idx = 4;	
	centurion::DocumentId docId = 56789;
	ASSERT_TRUE(isvs.add(idx, false, docId));
	auto eqIterator = centurion::BooleanValueSearchIterator::eq(isvs, idx, false);
	ASSERT_TRUE(eqIterator->valid());
	ASSERT_EQ(eqIterator->current(), docId);
	eqIterator->next();
	ASSERT_FALSE(eqIterator->valid());
	delete eqIterator;
}
