#include "gtest/gtest.h"
#include "IndexId.h"
#include "DocumentStore.h"


TEST(TestDocumentStore, TestStoreDocument) {
	centurion::DocumentStore store("docstore", true);
	rapidjson::Document doc;
	doc.Parse("{\"ime\":\"vasko\"}");
	auto result = store.storeDocument(doc);
	ASSERT_GT(result, 0);
}
