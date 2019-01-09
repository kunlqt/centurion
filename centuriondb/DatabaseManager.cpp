#include "DatabaseManager.h"
#include "StringValueSearchIterator.h"
#include "DoubleValueSearchIterator.h"
#include "BooleanValueSearchIterator.h"


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

	inline std::vector<std::string> DatabaseManager::createSelectedFields(SelectedFields* selectFields) const
	{
		std::vector<std::string> result;
		auto fields = selectFields;
		bool selectAllFields = true;
		if (!fields->empty()) {
			for (auto fieldIter = fields->begin();
				fieldIter != fields->end();
				++fieldIter)
			{
				if (*fieldIter == "/")
				{
					return std::vector<std::string>();
				}
				result.push_back(fieldIter->c_str());
			}
			mergeOverlappingFields(result);
		}
		return result;
	}

	size_t DatabaseManager::searchDocuments(TraversalVisitorResult* visitorResult, rapidjson::Document& results, DocumentId startFrom, size_t limit)
	{
		auto console = spdlog::get("root");
		auto selectFields = createSelectedFields(visitorResult->selectFields);
		visitorResult->searchRootIterator->seek([this](const std::string& fieldName) { return indexNameStore_.findIndexId(fieldName); },  MinDocumentId);
		results.SetArray();
		rapidjson::Value::AllocatorType& allocator = results.GetAllocator();
		results.Reserve(limit, allocator);
		size_t totalDocumentsFound = 0;
		for (size_t cnt = 0; cnt < limit; cnt++) {
			if (!visitorResult->searchRootIterator->valid()) {
				break;
			}
			const auto documentId = visitorResult->searchRootIterator->current();
			console->trace("Found document id: {}", documentId);
			totalDocumentsFound++;
			auto result = documentStore_.findDocument(documentId, allocator);
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
			visitorResult->searchRootIterator->next();
		}
		console->trace("Total: {} documents found", totalDocumentsFound);
		return totalDocumentsFound;
	}

	std::vector<DocumentId> DatabaseManager::insertDocuments(rapidjson::StringStream& is)
	{
		std::vector<DocumentId> result;
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
		//auto docs = rootDoc["rows"].GetArray();
		auto docs = rootDoc.GetArray();
		console->trace("Parsing done!");
		console->trace("Inserting {} documents...", docs.Size());
		const auto start = std::chrono::system_clock::now();
		size_t cnt = 0;
		for (const auto& doc : docs)
		{
			result.push_back(documentIndexer.indexDocument(doc));
			cnt++;
			if ((cnt % 1000) == 0)
			{
				std::cout << ".";
			}
		}
		std::cout << std::endl;
		const auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		const auto speed = docs.Size() / elapsed_seconds.count();
		console->trace("Insertion done! Total elapsed time: {}s. Insertion speed: {} docs/sec", elapsed_seconds.count(), speed);
		delete[] readBuffer;
		return result;
	}

	std::vector<centurion::SearchIterator*> DatabaseManager::buildSearchIterators(rapidjson::StringStream& query) const
	{
		std::vector<centurion::SearchIterator*> searchIterators;
		auto console = spdlog::get("root");
		rapidjson::Document doc;
		doc.ParseStream(query);
		if (doc.HasParseError())
		{
			throw std::runtime_error("json query parse error");
		}
		if (doc.IsArray())
		{
			for (const auto& searchTerm : doc.GetArray())
			{
				searchIterators.push_back(buildSearchIterator(searchTerm));
			}
		} else if (doc.IsObject())
		{
			searchIterators.push_back(buildSearchIterator(doc));
		} else {
			throw std::runtime_error("json query is not and object or array of search terms");
		}

		return searchIterators;
	}
	
	centurion::SearchIterator* DatabaseManager::buildSearchIterator(const rapidjson::Value& searchTerm) const
	{
		if (!searchTerm.IsObject())
		{
			throw std::runtime_error("json query array of search terms element is not an object");
		}
		if (!searchTerm.HasMember("path"))
		{
			throw std::runtime_error("missing query field: 'path'");
		}
		if (!searchTerm.HasMember("op"))
		{
			throw std::runtime_error("missing query field: 'op'");
		}
		if (!searchTerm.HasMember("value"))
		{
			throw std::runtime_error("missing query field: 'value'");
		}

		std::string field = searchTerm["path"].GetString();
		std::string op = searchTerm["op"].GetString();
		const auto& val = searchTerm["value"];
		if (val.IsString())
		{
			return(StringValueSearchIterator::eq(isvs_, field, val.GetString()));
		} else if (val.IsNumber())
		{
			if (op == "eq") {
				return(DoubleValueSearchIterator::eq(idvs_, field, val.GetDouble()));
			}
		} else if (val.IsBool()) {
			if (op == "eq") {
				return(BooleanValueSearchIterator::eq(ibvs_, field, val.GetBool()));
			}
		}
		throw std::runtime_error("error");
	}

}
