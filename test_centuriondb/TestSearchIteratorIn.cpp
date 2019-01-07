#include "gtest/gtest.h"
#include "TestCommon.h"
#include "StringValueIndexStore.h"
#include "StringValueSearchIterator.h"
#include "SearchIteratorIn.h"

namespace {
	using namespace centurion;

	class TestSearchIteratorIn : public ::testing::Test {
	public:
		TestSearchIteratorIn() : valueIndexStore_(nullptr) {}

	protected:
		static void SetUpTestSuite() {
		}

		static void TearDownTestSuite() {
		}

		void SetUp() override {
			valueIndexStore_ = new StringValueIndexStore(StringValueIndexStoreName, true);
		}

		void TearDown() override {
			delete valueIndexStore_;
			valueIndexStore_ = nullptr;
		}

		StringValueIndexStore* valueIndexStore_;
	};


	TEST_F(TestSearchIteratorIn, TestMultipleLeftEqualsMultipleRight) {
		const IndexId fieldIndexId = 4;

		const std::string indexedValue1 = "string-value-1";
		const std::string indexedValue2 = "string-value-2";
		const std::string indexedValue3 = "string-value-3";

		const DocumentId indexedDocumentId1 = 10;
		const DocumentId indexedDocumentId2 = 11;
		const DocumentId indexedDocumentId3 = 12;

		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue1, indexedDocumentId3));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue2, indexedDocumentId3));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId1));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId2));
		ASSERT_TRUE(valueIndexStore_->add(fieldIndexId, indexedValue3, indexedDocumentId3));

		SearchIterator* searchIterator = new SearchIteratorIn(
			std::vector<SearchIterator*> {
				StringValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue1),
				StringValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue2),
				StringValueSearchIterator::eq(*valueIndexStore_, "field1", indexedValue3)
			}
		);

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
}
