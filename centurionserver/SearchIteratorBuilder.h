#pragma once
#include "DefaultVisitorResult.h"

namespace centurion {
	class SearchIteratorBuilder
	{
	public:
		std::shared_ptr<DefaultVisitorResult> buildQuery(std::istream& query);

	};
}
