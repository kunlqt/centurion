#pragma once

#include "SearchIterator.h"
#include <vector>

namespace centurion {

	class SearchIteratorBuilder
	{
		std::vector<centurion::SearchIterator*> buildQuery(std::istream& query);
	};
}
