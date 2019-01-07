#include "QueryDocumentHandler.h"
#include "SearchIteratorBuilder.h"
#include "DatabaseManager.h"
#include <spdlog/spdlog.h>
#include <string>
#include <sstream>

namespace  centurion {
	void QueryDocumentHandler::handle(DatabaseManager& dbm, const std::string& query, rapidjson::Document& results)
	{
		auto log = spdlog::get("root");
		centurion::SearchIteratorBuilder builder;
		log->trace("creating build query...");
		std::stringstream ss(query);
		const auto traversalVisitorResult = builder.buildQuery(dbm, ss);
		log->trace("creating search documents...");		
		size_t totalDocumentsFound = dbm.searchDocuments(traversalVisitorResult.get(), results, 0, 100);
		log->trace("Search documents finished, found {}", totalDocumentsFound);

	}
}
