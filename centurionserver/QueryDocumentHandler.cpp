#include "QueryDocumentHandler.h"
#include "SearchIteratorBuilder.h"
#include "DatabaseManager.h"
#include <spdlog/spdlog.h>
#include <string>
#include <sstream>

namespace  centurion {
	void QueryDocumentHandler::handle(DatabaseManager& dbm, const std::string& query, rapidjson::Document& results)
	{
		auto log = spdlog::get("root")->clone("QueryDocumentHandler");
		centurion::SearchIteratorBuilder builder;
		log->trace("creating build query...");
		std::stringstream ss(query);
		const auto res = builder.buildQuery(ss);
		log->trace("creating search documents...");
		size_t totalDocumentsFound = 0;
		if (res->rootSearchIterator() != nullptr) {
			totalDocumentsFound = dbm.searchDocuments(res->qualifiedNames(), res->rootSearchIterator(), results, 0, 100);
		}
		delete res;
		log->trace("Search documents finished, found {}", totalDocumentsFound);
	}
}
