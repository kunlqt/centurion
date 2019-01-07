#pragma once
#include "DatabaseManager.h"
#include <rapidjson/document.h>

namespace centurion {
	class QueryDocumentHandler {	
	public:
		void handle(DatabaseManager& dbm, const std::string& query, rapidjson::Document& results);
	};
}
