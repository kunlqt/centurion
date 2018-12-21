#pragma once

#include "DatabaseManager.h"
#include "TraversalVisitorResult.h"

namespace centurion {
	class SearchIteratorBuilder
	{
	public:
		TraversalVisitorResult* buildQuery(DatabaseManager& dbm, std::istream& query);

	};
}
