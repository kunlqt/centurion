#pragma once

#include "DatabaseManager.h"
#include "TraversalVisitorResult.h"

namespace centurion {
	class SearchIteratorBuilder
	{
	public:
		std::shared_ptr<TraversalVisitorResult> buildQuery(DatabaseManager& dbm, std::istream& query);

	};
}
