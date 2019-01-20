#pragma once
#include "QualifiedNameBuilder.h"

namespace centurion {
	class SearchIteratorBuilder
	{
	public:
		QualifiedNameBuilder* buildQuery(std::istream& query);

	};
}
