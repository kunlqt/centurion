#pragma once

#include "SearchIterator.h"
#include <string>
#include <vector>

namespace centurion {
	using SelectedFields = std::vector<std::string>;

	struct TraversalVisitorResult {
		std::shared_ptr<SelectedFields> selectFields;
		std::shared_ptr<SearchIterator> searchRootIterator;
	};
}
