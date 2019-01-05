#include "gtest/gtest.h"
#include "TestCommon.h"
#include "DocumentIndexer.h"
#include "IndexNameStore.h"
#include "StringValueIndexStore.h"
#include "StringValueSearchIterator.h"

namespace {
	using namespace centurion;

	class TestIndexedStringValueStore : public ::testing::Test {
	public:
		TestIndexedStringValueStore(): valueIndexStore_(nullptr) {}

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
			valueIndexStore_ = new StringValueIndexStore(StringValueIndexStoreName, true);
		}

		void TearDown() override
		{
			delete valueIndexStore_;
			valueIndexStore_ = nullptr;
		}

		static IndexNameStore* indexNameStore_;
		StringValueIndexStore* valueIndexStore_;
	};

	IndexNameStore* TestIndexedStringValueStore::indexNameStore_ = nullptr;

	TEST_F(TestIndexedStringValueStore, FindSingleDocumentContainingString) {
		const IndexId fieldIndexId = 4;
		
		const std::string indexedValue = "string-value-1";
		
		const DocumentId indexedDocumentId = 56789;
		
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId));
		
		auto searchIterator = StringValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue);
		
		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId);
		
		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedStringValueStore, FindMultipleDocumentsContainingString) {
		const IndexId fieldIndexId = 4;
		
		const std::string indexedValue = "string-value-1";
		
		const DocumentId indexedDocumentId1 = 123;
		const DocumentId indexedDocumentId2 = 234;
		const DocumentId indexedDocumentId3 = 345;
		
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue, indexedDocumentId3));
		
		auto searchIterator = StringValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue);
		
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

	TEST_F(TestIndexedStringValueStore, FindSingleDocumentContainingStringWithinMultipleStrings) {
		const IndexId fieldIndexId = 4;
		
		const std::string indexedValue1 = "string-value-1";
		const std::string indexedValue2 = "string-value-2";
		const std::string indexedValue3 = "string-value-3";
		
		const DocumentId indexedDocumentId = 56789;
		
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId));
		
		auto searchIterator = StringValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue2);
		
		searchIterator->seek(MinDocumentId);
		ASSERT_TRUE(searchIterator->valid());
		ASSERT_EQ(searchIterator->current(), indexedDocumentId);
		
		searchIterator->next();
		ASSERT_FALSE(searchIterator->valid());
		delete searchIterator;
	}

	TEST_F(TestIndexedStringValueStore, FindMultipleDocumentContainingStringWithinMultipleStrings) {
		const IndexId fieldIndexId = 4;

		const std::string indexedValue1 = "string-value-1";
		const std::string indexedValue2 = "string-value-2";
		const std::string indexedValue3 = "string-value-3";

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

		auto searchIterator = StringValueSearchIterator::eq(*valueIndexStore_, fieldIndexId, indexedValue2);
		
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
