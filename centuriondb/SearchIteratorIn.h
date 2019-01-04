#pragma once

#include "SearchIterator.h"
#include "DocumentId.h"
#include <spdlog/spdlog.h>
#include <algorithm>

namespace centurion
{
	struct SearchIteratorIn : SearchIterator
	{
		SearchIteratorIn(const SearchIteratorIn&) = delete;
		SearchIteratorIn(SearchIteratorIn&&) = delete;

		SearchIteratorIn(std::vector<SearchIterator*> iterators)
			:
			iterators_(std::move(iterators)),
			currentDocumentId_(InvalidDocumentId)
		{
			auto console = spdlog::get("root");
		}

		virtual ~SearchIteratorIn() override
		{
			for (auto it : iterators_) {
				delete it;
			}
		}

		virtual void next() override
		{
			if (getState() == BeforeFirst) {				
				for (auto it = iterators_.begin(); it != iterators_.end(); ) {
					(*it)->next();
					if (!(*it)->valid()) {
						iterators_.erase(it);
					} else {
						++it;
					}
				}
				if (iterators_.empty()) {
					setState(AfterLast);
					return;
				}
			}
			std::make_heap(iterators_.begin(), iterators_.end(), [](const auto& a, const auto& b) { return a->current() > b->current(); });
			while (true) {
				
				setState(None);
				return;
			}
		}

		virtual DocumentId current() const override
		{
			return currentDocumentId_;
		}


	private:
		std::vector<SearchIterator*> iterators_;
		DocumentId currentDocumentId_;
	};
}
