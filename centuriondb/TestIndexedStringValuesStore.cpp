#include "gtest/gtest.h"
#include "DocumentIndexer.h"
#include "IndexNameStore.h"
#include "StringValueIndexStore.h"
#include "StringValueSearchIterator.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


TEST(TestIndexedStringValueStore, TestIndexStringValue) {
	auto console = spdlog::get("console");
	centurion::IndexNameStore indexNameStore("instore", true);
	centurion::StringValueIndexStore isvs("ivstore", true);
	centurion::IndexId idx = 4;
	std::string indexedValue = "blabla";
	centurion::DocumentId docId = 56789;
	ASSERT_TRUE(isvs.add(idx, indexedValue, docId));
	auto eqIterator = centurion::StringValueSearchIterator::eq(isvs, idx, indexedValue);
	ASSERT_TRUE(eqIterator->valid());
	ASSERT_EQ(eqIterator->current(), docId);
	eqIterator->next();
	ASSERT_FALSE(eqIterator->valid());
	delete eqIterator;
}
