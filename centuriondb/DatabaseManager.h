#pragma once

#include "TraversalVisitorResult.h"
#include "DocumentIndexer.h"
#include "SearchIterator.h"
#include "IndexNameStore.h"
#include "DocumentStore.h"
#include "StringValueIndexStore.h"
#include "DoubleValueIndexStore.h"
#include "BooleanValueIndexStore.h"
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
		DatabaseManager(boost::filesystem::path databaseRootDir);
		size_t searchDocuments(TraversalVisitorResult* visitorResult, rapidjson::Document& results, DocumentId startFrom, size_t limit);
		std::vector<DocumentId> insertDocuments(rapidjson::StringStream& is);
		std::vector<centurion::SearchIterator*> buildSearchIterators(rapidjson::StringStream& query) const;
		centurion::SearchIterator* buildSearchIterator(const rapidjson::Value& searchTerm) const;

		const DocumentStore& documentStore() const { return documentStore_; };
		const IndexNameStore& indexNameStore() const { return indexNameStore_; };
		const StringValueIndexStore& isvs() const { return isvs_; };
		const DoubleValueIndexStore& idvs() const { return idvs_; };
		const BooleanValueIndexStore& ibvs() const { return ibvs_; };
		const StringArrayValueIndexStore& savs() const { return savs_; };

	private:
		inline std::vector<std::string> createSelectedFields(SelectedFields* selectFields) const;

		boost::filesystem::path databaseRootDir_;
		centurion::DocumentStore documentStore_;
		centurion::IndexNameStore indexNameStore_;
		centurion::StringValueIndexStore isvs_;
		centurion::DoubleValueIndexStore idvs_;
		centurion::BooleanValueIndexStore ibvs_;
		centurion::StringArrayValueIndexStore savs_;

	};
}
