#include "gtest/gtest.h"
#include "TestCommon.h"
#include "DocumentIndexer.h"
#include "DoubleValueIndexStore.h"
#include "DoubleValueSearchIterator.h"
#include "DoubleValueRangeSearchIterator.h"
#include "DoubleValueRangeSearchIterator.h"

namespace {
	using namespace centurion;

	class TestIndexedDoubleValueStore : public ::testing::Test {
	public:
		TestIndexedDoubleValueStore() : valueIndexStore_(nullptr) {}

	protected:
		static void SetUpTestSuite() {
		}

		static void TearDownTestSuite() {
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
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId2);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), indexedDocumentId3);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, GreaterThanDescDocumentId) {
		const IndexId fieldIndexId = 4;

		const double indexedValue1 = 35;
		const DocumentId indexedDocumentId1 = 12;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId1));

		const double indexedValue2 = 38;
		const DocumentId indexedDocumentId2 = 11;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId2));

		auto searchIterator = DoubleValueRangeSearchIterator::gt(*valueIndexStore_, fieldIndexId, indexedValue1);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId2);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, GreaterThanAscDocumentId) {
		const IndexId fieldIndexId = 4;

		const double indexedValue1 = 35;
		const DocumentId indexedDocumentId1 = 11;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId1));

		const double indexedValue2 = 38;
		const DocumentId indexedDocumentId2 = 12;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId2));

		auto searchIterator = DoubleValueRangeSearchIterator::gt(*valueIndexStore_, fieldIndexId, indexedValue1);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId2);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, LessThanDescDocumentId) {
		const IndexId fieldIndexId = 4;

		const double indexedValue1 = 35;
		const DocumentId indexedDocumentId1 = 12;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId1));

		const double indexedValue2 = 38;
		const DocumentId indexedDocumentId2 = 11;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId2));

		auto searchIterator = DoubleValueRangeSearchIterator::lt(*valueIndexStore_, fieldIndexId, indexedValue2);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId1);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, LessThanAscDocumentId) {
		const IndexId fieldIndexId = 4;

		const double indexedValue1 = 35;
		const DocumentId indexedDocumentId1 = 11;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId1));

		const double indexedValue2 = 38;
		const DocumentId indexedDocumentId2 = 12;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId2));

		auto searchIterator = DoubleValueRangeSearchIterator::lt(*valueIndexStore_, fieldIndexId, indexedValue2);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId1);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}

	TEST_F(TestIndexedDoubleValueStore, GreaterThanAscDocumentIdReverseInsert) {
		const IndexId fieldIndexId = 4;
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 37.0, 14));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 37.0, 12));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 37.0, 11));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 38.0, 10));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 38.0, 13));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 39.0, 11));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 39.0, 7));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, 39.0, 13));
		auto searchIterator = DoubleValueRangeSearchIterator::gt(*valueIndexStore_, fieldIndexId, 35.0);

		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), 7.0);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), 10.0);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), 11.0);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), 12.0);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), 13.0);

		searchIterator->next();
		ASSERT_EQ(searchIterator->current(), 14.0);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}


};
