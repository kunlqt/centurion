#include "gtest/gtest.h"
#include "IndexNameStore.h"
#include "TestCommon.h"

namespace {
	using namespace centurion;

	class TestIndexNameStore : public ::testing::Test {
	public:
		TestIndexNameStore() : indexNameStore_(nullptr) {}

	protected:
		static void SetUpTestSuite() { }

		static void TearDownTestSuite() { }

		void SetUp() override {
			indexNameStore_ = new IndexNameStore(IndexNameStoreName, true);
		}

		void TearDown() override {
			delete indexNameStore_;
			indexNameStore_ = nullptr;
		}

		IndexNameStore* indexNameStore_;
	};

	TEST_F(TestIndexNameStore, TestEnsureIndexName) {
		centurion::IndexId idx1 = indexNameStore_->findIndexId("index1");
		ASSERT_EQ(idx1, InvalidIndexId);
		centurion::IndexId idx2 = indexNameStore_->ensureIndexId("index2");
		ASSERT_NE(idx2, InvalidIndexId);
	}
}
