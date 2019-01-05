#include "gtest/gtest.h"
#include "StringValueIndexComparator.h"
#include "Utils.h"

using namespace centurion;


TEST(StringValueIndexComparator, IndexAIsLessThanIndexB) {
	using namespace  rocksdb;
	StringValueIndexComparator comp;
	Slice slice1;
	CreateStringIndexSlice(1, nullptr, 0, slice1);
	Slice slice2;
	CreateStringIndexSlice(2, nullptr, 0, slice2);
	ASSERT_EQ(comp.Compare(slice1, slice2), -1);
}

TEST(StringValueIndexComparator, IndexAIsGreaterThanIndexB) {
	using namespace  rocksdb;
	StringValueIndexComparator comp;
	Slice slice1;
	CreateStringIndexSlice(2, nullptr, 0, slice1);
	Slice slice2;
	CreateStringIndexSlice(1, nullptr, 0, slice2);
	ASSERT_EQ(comp.Compare(slice1, slice2), +1);
}

TEST(StringValueIndexComparator, IndexAIsEqualToIndexB) {
	StringValueIndexComparator comp;
}
