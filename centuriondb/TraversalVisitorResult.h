#pragma once

#include "SearchIterator.h"
#include <string>
#include <vector>

namespace centurion {
	struct TraversalVisitorResult {
		std::vector<std::string>* selectFields;
		SearchIterator* searchRootIterator;
	};
}
