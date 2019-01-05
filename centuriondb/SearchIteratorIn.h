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
			currentDocumentId_(InvalidDocumentId),
			prevDocumentId_(InvalidDocumentId)
		{
			auto console = spdlog::get("root");
		}

		virtual ~SearchIteratorIn() override
		{
			for (auto it : iterators_) {
				delete it;
			}
		}

		void seek(DocumentId documentId) override
		{			
			if (!iterators_.empty()) {
				for (auto it = iterators_.begin(); it != iterators_.end(); ) {
					(*it)->seek(documentId);
					if (!(*it)->valid()) {
						it = iterators_.erase(it);
					} else {
						++it;
					}
				}
				std::make_heap(iterators_.begin(), iterators_.end(), [](const auto& a, const auto& b) { return a->current() > b->current(); });
			}
			if (iterators_.empty())
			{
				setState(AfterLast);
			}
		}

		virtual void next() override
		{			
			do {
				if (iterators_.empty())
				{
					setState(AfterLast);
					return;
				}
				std::pop_heap(iterators_.begin(), iterators_.end(), [](const auto& a, const auto& b) { return a->current() > b->current(); });
				SearchIterator* it = iterators_.back();
				prevDocumentId_ = currentDocumentId_;
				currentDocumentId_ = it->current();
				it->next();
				if (it->valid()) {
					std::push_heap(iterators_.begin(), iterators_.end(), [](const auto& a, const auto& b) { return a->current() > b->current(); });
				} else {
					iterators_.pop_back();
				}
				setState(None);
			} while (currentDocumentId_ == prevDocumentId_);
		}

		virtual DocumentId current() const override
		{
			return currentDocumentId_;
		}


	private:
		std::vector<SearchIterator*> iterators_;
		DocumentId currentDocumentId_;
		DocumentId prevDocumentId_;
	};
}
