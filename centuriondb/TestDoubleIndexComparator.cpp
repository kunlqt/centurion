#include "gtest/gtest.h"
#include "DoubleIndexComparator.h"
#include "Utils.h"

using namespace centurion;

TEST(TestDoubleIndexComparator, IndexAIsLessThanIndexB) {
	using namespace  rocksdb;
	DoubleIndexComparator comp;
	Slice slice1;
	CreateDoubleIndexSlice(1, 5, slice1);
	Slice slice2;
	CreateDoubleIndexSlice(1, 7, slice2);
	ASSERT_EQ(comp.Compare(slice1, slice2), -1);
}

TEST(TestDoubleIndexComparator, IndexAIsGreaterThanIndexB) {
	using namespace  rocksdb;
	DoubleIndexComparator comp;
	Slice slice1;
	CreateDoubleIndexSlice(1, 6, slice1);
	Slice slice2;
	CreateDoubleIndexSlice(1, 4, slice2);
	ASSERT_EQ(comp.Compare(slice1, slice2), +1);
}
