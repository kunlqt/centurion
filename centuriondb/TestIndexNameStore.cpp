#include "gtest/gtest.h"
#include "IndexNameStore.h"

TEST(TestIndexNameStore, TestAddIndexName) {
	centurion::IndexNameStore ins("instore", true);
	centurion::IndexId idx1 = ins.getIndexId("index1", 6);
	centurion::IndexId idx2 = ins.getIndexId("index2", 6);
	centurion::IndexId idx3 = ins.getIndexId("index1", 6);
	ASSERT_EQ(idx1, idx3);
	ASSERT_GT(idx2, idx1);
}
