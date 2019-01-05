#include "gtest/gtest.h"
#include "TestCommon.h"
#include "DocumentIndexer.h"
#include "IndexNameStore.h"
#include "DoubleValueIndexStore.h"
#include "DoubleValueSearchIterator.h"

namespace {
	using namespace centurion;

	class TestIndexedDoubleValueStore : public ::testing::Test {
	public:
		TestIndexedDoubleValueStore() : valueIndexStore_(nullptr) {}

	protected:
		static void SetUpTestSuite() {
			indexNameStore_ = new IndexNameStore(IndexNameStoreName, true);
		}

		static void TearDownTestSuite() {
			delete indexNameStore_;
			indexNameStore_ = nullptr;
		}

		void SetUp() override
		{
			valueIndexStore_ = new DoubleValueIndexStore(DoubleValueIndexStoreName, true);
		}

		void TearDown() override
		{
			delete valueIndexStore_;
			valueIndexStore_ = nullptr;
		}

		static IndexNameStore* indexNameStore_;
		DoubleValueIndexStore* valueIndexStore_;
	};

	IndexNameStore* TestIndexedDoubleValueStore::indexNameStore_ = nullptr;

	TEST_F(TestIndexedDoubleValueStore, FindSingleDocumentContainingDouble) {
		const IndexId fieldIndexId = 4;

		const double indexedValue = 7.5;

		const DocumentId indexedDocumentId = 56789;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId));

		auto searchIterator = DoubleValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, FindMultipleDocumentsContainingDouble) {
		const IndexId fieldIndexId = 4;

		const double indexedValue = 6.8;

		const DocumentId indexedDocumentId1 = 123;
		const DocumentId indexedDocumentId2 = 234;
		const DocumentId indexedDocumentId3 = 345;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId3));

		auto searchIterator = DoubleValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId1);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), indexedDocumentId2);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), indexedDocumentId3);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, FindSingleDocumentContainingDoubleWithinMultipleDoubles) {
		const IndexId fieldIndexId = 4;

		const double indexedValue1 = 3.5;
		const double indexedValue2 = 4.5;
		const double indexedValue3 = 5.5;

		const DocumentId indexedDocumentId = 56789;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId));

		auto searchIterator = DoubleValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue2);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, FindMultipleDocumentContainingDoubleWithinMultipleDoubles) {
		const IndexId fieldIndexId = 4;

		const double indexedValue1 = 3.5;
		const double indexedValue2 = 4.5;
		const double indexedValue3 = 5.5;

		const DocumentId indexedDocumentId1 = 123;
		const DocumentId indexedDocumentId2 = 234;
		const DocumentId indexedDocumentId3 = 345;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId3));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId3));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId3));

		auto searchIterator = DoubleValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue2);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId1);
		searchIterator->next();

		ASSERT_EQ(searchIterator->current(), indexedDocumentId2);
		searchIterator->next();

		ASSERT_EQ(searchIterator->current(), indexedDocumentId3);
		searchIterator->next();

		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

};