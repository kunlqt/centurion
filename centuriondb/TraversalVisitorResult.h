#pragma once

#include "SearchIterator.h"
#include <string>
#include <vector>

namespace centurion {
	using SelectedFields = std::vector<std::string>;

	struct TraversalVisitorResult {
		SelectedFields* selectFields;
		SearchIterator* searchRootIterator;

		virtual ~TraversalVisitorResult()
		{
			delete selectFields;
			delete searchRootIterator;
		}
	};
}
