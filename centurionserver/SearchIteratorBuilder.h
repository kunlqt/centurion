#pragma once

#include "DatabaseManager.h"
#include "SearchIterator.h"
#include <vector>

namespace centurion {
	class SearchIteratorBuilder
	{
	public:
		SearchIterator* buildQuery(DatabaseManager& dbm, std::istream& query);

	};
}
