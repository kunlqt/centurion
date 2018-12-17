#pragma once

#include "DocumentId.h"
#include <iterator>

namespace centurion
{
	//struct SearchIterator : public std::iterator<std::forward_iterator_tag, DocumentId>
	struct SearchIterator
	{		
		virtual ~SearchIterator() {};
		virtual bool valid() const = 0;
		virtual DocumentId current() const = 0;
		virtual void next() = 0;
	};
}
