#include "gtest/gtest.h"
#include "TestCommon.h"
#include "DocumentIndexer.h"
#include "BooleanValueIndexStore.h"
#include "BooleanValueSearchIterator.h"

namespace {
	using namespace centurion;

	class TestIndexedBooleanValueStore : public ::testing::Test {
	public:
		TestIndexedBooleanValueStore() : valueIndexStore_(nullptr) {}

	protected:
		static void SetUpTestSuite() {
		}

		static void TearDownTestSuite() {
		}

		void SetUp() override {
			valueIndexStore_ = new BooleanValueIndexStore(BooleanValueIndexStoreName, true);
		}

		void TearDown() override {
			delete valueIndexStore_;
			valueIndexStore_ = nullptr;
		}

		BooleanValueIndexStore* valueIndexStore_;
	};

	TEST_F(TestIndexedBooleanValueStore, FindSingleDocumentContainingBoolean) {
		const IndexId fieldIndexId = 4;

		const bool indexedValue = true;

		const DocumentId indexedDocumentId = 56789;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId));

		auto searchIterator = BooleanValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue);

		searchIterator->seek([fieldIndexId](const std::string&) { return fieldIndexId; }, MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedBooleanValueStore, FindMultipleDocumentsContainingBoolean) {
		const IndexId fieldIndexId = 4;

		const bool indexedValue = true;

		const DocumentId indexedDocumentId1 = 123;
		const DocumentId indexedDocumentId2 = 234;
		const DocumentId indexedDocumentId3 = 345;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId3));

		auto searchIterator = BooleanValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue);

		searchIterator->seek([fieldIndexId](const std::string&) { return fieldIndexId; }, MinDocumentId);
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

	TEST_F(TestIndexedBooleanValueStore, FindSingleDocumentContainingBooleanWithinMultipleBooleans) {
		const IndexId fieldIndexId = 4;

		const bool indexedValue1 = true;
		const bool indexedValue2 = false;
		const bool indexedValue3 = true;

		const DocumentId indexedDocumentId = 56789;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId));

		auto searchIterator = BooleanValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue2);

		searchIterator->seek([fieldIndexId](const std::string&) { return fieldIndexId; }, MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedBooleanValueStore, FindMultipleDocumentContainingBooleanWithinMultipleBooleans) {
		const IndexId fieldIndexId = 4;

		const bool indexedValue1 = true;
		const bool indexedValue2 = false;
		const bool indexedValue3 = true;

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

		auto searchIterator = BooleanValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue2);

		searchIterator->seek([fieldIndexId](const std::string&) { return fieldIndexId; }, MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId1);

		searchIterator->next();
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId2);

		searchIterator->next();
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId3);

		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());

		delete searchIterator;
	}
};
