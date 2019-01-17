#include "DatabaseManager.h"
#include "DocumentIndexer.h"
#include <rapidjson/pointer.h>

namespace centurion {

	DatabaseManager::DatabaseManager(boost::filesystem::path databaseRootDir)
		:
		databaseRootDir_(std::move(databaseRootDir)),
		documentStore_(databaseRootDir_ / docDirName),
		indexNameStore_(databaseRootDir_ / insDirName),
		isvs_(databaseRootDir_ / isvDirName),
		idvs_(databaseRootDir_ / idvDirName),
		ibvs_(databaseRootDir_ / ibvDirName),
		savs_(databaseRootDir_ / iasDirName)
	{}

	size_t DatabaseManager::searchDocuments(
		std::vector<std::string> selectedFields,
		std::shared_ptr<SearchIterator> rootSearchIterator,
		rapidjson::Document& results, 
		DocumentId startFrom, 
		size_t limit)
	{
		auto console = spdlog::get("root");
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
			console->trace("Found document id: {}", documentId);
			totalDocumentsFound++;
			auto result = documentStore_.loadDocument(documentId, allocator);
			if (result.IsNull()) {
				console->error("Document with id: {} not found in database", documentId);
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
		console->trace("Total: {} documents found", totalDocumentsFound);
		return totalDocumentsFound;
	}

	DocumentIds DatabaseManager::insertDocuments(rapidjson::StringStream& is, std::function<void(size_t)> onProgress)
	{
		DocumentIds result;
		centurion::DocumentIndexer documentIndexer(documentStore_, indexNameStore_, isvs_, idvs_, ibvs_, savs_);

		bool dropDatabase = false;
		auto console = spdlog::get("root");

		console->trace("Loading json file...");
		const size_t readBufferSize = 16535 * 1024;
		const auto readBuffer = new char[readBufferSize];
		rapidjson::Document rootDoc;
		console->trace("Parsing json file...");
		rootDoc.ParseStream(is);
		if (rootDoc.HasParseError())
		{
			throw std::runtime_error("an error occured while parsing JSON document");
		}
		if (rootDoc.IsObject())
		{
			result.push_back(documentIndexer.indexDocument(rootDoc));
			return result;
		}
		if (!rootDoc.IsArray())
		{
			throw std::runtime_error("Only json object or json array are supported as root object");
		}
		auto docs = rootDoc.GetArray();
		size_t total = docs.Size();
		console->trace("Parsing done!");
		if (total == 0) {
			throw std::runtime_error("Empty array of objects");
		}
		console->trace("Inserting {} documents...", total);
		const auto start = std::chrono::system_clock::now();
		size_t cnt = 0;		
		// report progress on each 10% but not more than 1k and not less than 1
		size_t div = std::min(1ull, std::max(total / 10, 1000ull));
		for (const auto& doc : docs)
		{
			result.push_back(documentIndexer.indexDocument(doc));
			cnt++;
			if ((cnt % div) == 0)
			{
				onProgress(((double)cnt/(double)total)*100.0f);
			}
		}
		onProgress(100.0f);
		std::cout << std::endl;
		const auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		const auto speed = docs.Size() / elapsed_seconds.count();
		console->trace("Insertion done! Total elapsed time: {}s. Insertion speed: {} docs/sec", elapsed_seconds.count(), speed);
		delete[] readBuffer;
		return result;
	}


}
