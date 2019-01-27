#include "QueryDocumentsHandler.h"
#include "SearchIteratorBuilder.h"
#include <spdlog/spdlog.h>
#include <string>
#include <sstream>


void QueryDocumentsHandler::handle(std::shared_ptr<centurion::DatabaseManager> dbm, const std::string& query, rapidjson::Document& results)
{
	auto log = spdlog::get("root")->clone("QueryDocumentHandler");
	centurion::SearchIteratorBuilder builder;
	log->trace("creating build query...");
	std::stringstream ss(query);
	const auto res = builder.buildQuery(ss);
	log->trace("creating search documents...");
	size_t totalDocumentsFound = 0;
	if (res->rootSearchIterator() != nullptr) {
		totalDocumentsFound = dbm->searchDocuments(res->selectedColumns(), res->rootSearchIterator(), results, 0, 100);
	}
	log->trace("Search documents finished, found {}", totalDocumentsFound);
}
