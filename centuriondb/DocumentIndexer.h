#pragma once
#include "DocumentStore.h"
#include "IndexNameStore.h"
#include "StringValueIndexStore.h"
#include "StringArrayValueIndexStore.h"
#include "DoubleValueIndexStore.h"
#include "BooleanValueIndexStore.h"
#include <rapidjson/pointer.h>
#include <rapidjson/document.h>

namespace centurion {
	class DocumentIndexer
	{
	public:
		DocumentIndexer(DocumentStore& documentStore, 
			IndexNameStore& indexNameStore, 
			StringValueIndexStore& stringValueIndexStore,
			DoubleValueIndexStore& indexedDoubleValuesStore,
			BooleanValueIndexStore& indexedBooleanValuesStore,
			StringArrayValueIndexStore& stringArrayValueIndexStore)
			: 
			documentStore_(documentStore),
			indexNameStore_(indexNameStore),
			stringValueIndexStore_(stringValueIndexStore),
			indexedDoubleValuesStore_(indexedDoubleValuesStore),
			indexedBooleanValuesStore_(indexedBooleanValuesStore),
			stringArrayValueIndexStore_(stringArrayValueIndexStore)
		{
			
		}

		void indexDocument(const rapidjson::Value& doc)
		{
			auto documentId = documentStore_.storeDocument(doc);
			const rapidjson::Pointer root;
			extractPaths(doc, root, [&](const char* fieldName, size_t fieldNameSize, const rapidjson::Value& fieldValue) {
				const auto indexId = indexNameStore_.getIndexId(fieldName, fieldNameSize);
				bool addResult;
				if (fieldValue.IsArray()) {
					const auto& arr = fieldValue.GetArray();
					for (size_t idx = 0; idx < arr.Size(); idx++)
					{
						const auto& arrayElement = arr[idx];
						if (arrayElement.IsString())
						{
							addResult = stringArrayValueIndexStore_.add(indexId, idx, arrayElement.GetString(), arrayElement.GetStringLength(), documentId);
						}
					}
				} else {
					if (fieldValue.IsString()) {
						addResult = stringValueIndexStore_.add(indexId, fieldValue.GetString(), fieldValue.GetStringLength(), documentId);
					} else if (fieldValue.IsNumber()) {
						addResult = indexedDoubleValuesStore_.add(indexId, fieldValue.GetDouble(), documentId);
					} else if (fieldValue.IsBool()) {
						addResult = indexedBooleanValuesStore_.add(indexId, fieldValue.GetBool(), documentId);
					} else if (fieldValue.IsNull()) {
						// ignore for now
					} else {
						throw std::runtime_error("unsupported type");
					}
				}
			});
		}

	private:
		static void extractPaths(
			const rapidjson::Value& v,
			const rapidjson::Pointer& parent,
			std::function<void(const char*, size_t, const rapidjson::Value&)> onPath) {
			if (v.IsObject()) {
				for (rapidjson::Value::ConstMemberIterator itr = v.MemberBegin(); itr != v.MemberEnd(); ++itr) {
					extractPaths(itr->value, parent.Append(itr->name.GetString(), itr->name.GetStringLength()), onPath);
				}
				/*} else if (v.IsArray()) {
					for (rapidjson::SizeType i = 0; i < v.Size(); i++) {
						extractPaths(v[i], parent.Append(i), onPath);
					}*/
			}
			else {
				rapidjson::StringBuffer sb1;
				if (parent.Stringify(sb1)) {
					onPath(sb1.GetString(), sb1.GetSize(), v);
				}
			}
		}


		DocumentStore& documentStore_;
		IndexNameStore& indexNameStore_;
		StringValueIndexStore& stringValueIndexStore_;
		DoubleValueIndexStore& indexedDoubleValuesStore_;
		BooleanValueIndexStore& indexedBooleanValuesStore_;
		StringArrayValueIndexStore& stringArrayValueIndexStore_;
	};
}
