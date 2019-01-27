#include "DatabaseManager.h"
#include "DocumentIndexer.h"
#include <rapidjson/pointer.h>

namespace centurion {

	DatabaseManager::DatabaseManager(std::shared_ptr<boost::filesystem::path> databaseRootDir)
		:
		documentStore_(*databaseRootDir / docDirName),
		indexNameStore_(*databaseRootDir / insDirName),
		isvs_(*databaseRootDir / isvDirName),
		idvs_(*databaseRootDir / idvDirName),
		ibvs_(*databaseRootDir / ibvDirName),
		savs_(*databaseRootDir / iasDirName)
	{
		logger_ = spdlog::get("root");
	}

	size_t DatabaseManager::searchDocuments(
		std::vector<std::string> selectedFields,
		SearchIterator* rootSearchIterator,
		rapidjson::Document& results, 
		DocumentId startFrom, 
		size_t limit)
	{
		auto selectFields = std::move(selectedFields);
		MergeOverlappingFields(selectFields);
		rootSearchIterator->seek(
			[this](FieldType fieldType, const std::string& fieldName) { return indexNameStore_.findIndexId(fieldName); },
			[this](FieldType fieldType, const rocksdb::Slice* lowerBound, const rocksdb::Slice* upperBound)
			{
				rocksdb::ReadOptions opts;
				opts.iterate_lower_bound = lowerBound;
				opts.iterate_upper_bound = upperBound;
				switch (fieldType)
				{
					case kDouble: return idvs_.newIterator(opts);
					case kBoolean: return ibvs_.newIterator(opts);
					case kString: return isvs_.newIterator(opts);
					case kStringArray: return savs_.newIterator(opts);
					default:
						throw std::runtime_error("Unsupported field type");
				}
			},
			MinDocumentId);
		results.SetArray();
		rapidjson::Value::AllocatorType& allocator = results.GetAllocator();
		results.Reserve(limit, allocator);
		size_t totalDocumentsFound = 0;
		for (size_t cnt = 0; cnt < limit; cnt++) {
			if (!rootSearchIterator->valid()) {
				break;
			}
			const auto documentId = rootSearchIterator->current();
			logger_->trace("Found document id: {}", documentId);
			totalDocumentsFound++;
			auto result = documentStore_.loadDocument(documentId, allocator);
			if (result.IsNull()) {
				logger_->error("Document with id: {} not found in database", documentId);
			} else {
				if (selectFields.empty()) {
					results.PushBack(result, allocator);
				} else {
					rapidjson::Document resultFitered(rapidjson::kObjectType);
					for (auto selectField : selectFields)
					{
						rapidjson::Value* selectedFieldValue = rapidjson::Pointer(selectField.c_str()).Get(result);
						if (selectedFieldValue != nullptr) {
							rapidjson::Pointer(selectField.c_str()).Set(resultFitered, *selectedFieldValue, allocator);
						}
					}
					results.PushBack(resultFitered, allocator);
				}
			}
			rootSearchIterator->next();
		}
		logger_->trace("Total: {} documents found", totalDocumentsFound);
		return totalDocumentsFound;
	}

	std::vector<bool> DatabaseManager::removeDocuments(const DocumentIds& documentIds)
	{
		DocumentIndexer documentIndexer(documentStore_, indexNameStore_, isvs_, idvs_, ibvs_, savs_);
		std::vector<bool> result;
		for (const auto& documentId : documentIds)
		{
			result.push_back(documentIndexer.unindexDocument(documentId));
		}
		return result;
	}

	DocumentIds DatabaseManager::insertDocuments(DocumentIds documentIds, rapidjson::Document& rootDoc, std::function<void(size_t)> onProgress)
	{
		if (rootDoc.IsObject())
		{
			if (documentIds.size() == 1) {
				return DocumentIds{ insertSingleDocument(documentIds.front(), rootDoc, onProgress) };
			}
		}
		if (rootDoc.IsArray())
		{
			return insertMultipleDocuments(documentIds, rootDoc, onProgress);
		}
		throw std::runtime_error("Only json object or json array are supported as root object");	
		
	}

	DocumentId DatabaseManager::insertSingleDocument(DocumentId documentId, rapidjson::Document& rootDoc, std::function<void(size_t)> onProgress)
	{
		DocumentIndexer documentIndexer(documentStore_, indexNameStore_, isvs_, idvs_, ibvs_, savs_);
		return (documentIndexer.indexDocument(documentId, rootDoc));
	}

	DocumentIds DatabaseManager::insertMultipleDocuments(DocumentIds documentIds, rapidjson::Document& rootDoc, std::function<void(size_t)> onProgress)
	{
		DocumentIds result;
		auto docs = rootDoc.GetArray();
		size_t total = docs.Size();
		if (total != documentIds.size())
		{
			throw std::runtime_error("The count of document ids doesn't match with count of provided documents");
		}
		size_t min_div = 1;
		size_t max_div = 1000;
		size_t div_perc = 10;
		logger_->trace("Parsing done!");
		if (total == 0) {
			throw std::runtime_error("Empty array of objects");
		}
		logger_->trace("Inserting {} documents...", total);
		const auto start = std::chrono::system_clock::now();
		// report progress on each 10% but not more than 1k and not less than 1
		size_t div = std::min(min_div, std::max(total / div_perc, max_div));
		DocumentIndexer documentIndexer(documentStore_, indexNameStore_, isvs_, idvs_, ibvs_, savs_);
		size_t cnt = 0;
		for (const auto& doc : docs)
		{
			result.push_back(documentIndexer.indexDocument(documentIds[cnt++], doc));
			if ((cnt % div) == 0)
			{
				onProgress(((double)cnt / (double)total)*100.0f);
			}
		}
		onProgress(100.0f);
		const auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		const auto speed = docs.Size() / elapsed_seconds.count();
		logger_->trace("Insertion done! Total elapsed time: {}s. Insertion speed: {} docs/sec", elapsed_seconds.count(), speed);
		return result;
	}

}
