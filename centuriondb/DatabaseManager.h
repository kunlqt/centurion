#pragma once
#include "DocumentId.h"
#include "SearchIterator.h"
#include "DocumentStore.h"
#include "IndexNameStore.h"
#include "StringValueIndexStore.h"
#include "DoubleValueIndexStore.h"
#include "BooleanValueIndexStore.h"
#include "StringArrayValueIndexStore.h"
#include <rapidjson/document.h>
#include <boost/filesystem/path.hpp>
#include <string>
#include <vector>

namespace centurion
{
	static const char* insDirName = "instore";
	static const char* isvDirName = "isvstore";
	static const char* idvDirName = "idvstore";
	static const char* ibvDirName = "ibvstore";
	static const char* iasDirName = "isavistore";
	static const char* docDirName = "docstore";

	class DatabaseManager
	{
	public:
		DatabaseManager(std::shared_ptr<boost::filesystem::path> databaseRootDir);
		size_t searchDocuments(
			std::vector<std::string> qualifiedNames,
			SearchIterator* rootSearchIterator,
			rapidjson::Document& results,
			DocumentId startFrom,
			size_t limit);
		DocumentId insertSingleDocument(DocumentId documentId, const rapidjson::Document& rootDoc, std::function<void(size_t)> onProgress);
		void insertMultipleDocuments(DocumentIds& documentIds, const rapidjson::Document::Array& rootDocs, std::function<void(size_t)> onProgress);

		std::vector<bool> removeDocuments(const DocumentIds& documentIds);
		const DocumentStore& documentStore() const { return documentStore_; };
		const IndexNameStore& indexNameStore() const { return indexNameStore_; };
		const StringValueIndexStore& isvs() const { return isvs_; };
		const DoubleValueIndexStore& idvs() const { return idvs_; };
		const BooleanValueIndexStore& ibvs() const { return ibvs_; };
		const StringArrayValueIndexStore& savs() const { return savs_; };

	private:

		std::shared_ptr<spdlog::logger> logger_;
		DocumentStore documentStore_;
		IndexNameStore indexNameStore_;
		StringValueIndexStore isvs_;
		DoubleValueIndexStore idvs_;
		BooleanValueIndexStore ibvs_;
		StringArrayValueIndexStore savs_;
	};
}
