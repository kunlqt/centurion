#pragma once

#include "SearchIterator.h"
#include "DocumentId.h"
#include <vector>
#include <queue>

namespace centurion
{
	struct MergeIterator : SearchIterator
	{
		MergeIterator(const MergeIterator&) = delete;
		MergeIterator(MergeIterator&&) = delete;

		MergeIterator(std::vector<SearchIterator*> iterators) 
		: 
			iterators_(std::move(iterators)),
			totalDocumentsToMatch_(iterators_.size()),
			currentDocumentId_(InvalidDocumentId),
			isValid_(true)
		{
			auto console = spdlog::get("root");
			if (std::any_of(iterators_.begin(), iterators_.end(), [](auto it) { return !it->valid(); }))
			{
				console->error("some of the iterators passed to MergeIterator are invalid");
				isValid_ = false;
			} 
		}

		virtual ~MergeIterator() override
		{
			for (SearchIterator* it : iterators_)
			{
				delete it;
			}
		}

		virtual void next() override
		{
			DocumentId maxDocumentId = InvalidDocumentId;
			if (!valid())
			{
				isValid_ = false;
				return;
			}
			while (true) {
				size_t matchCount = 0;
				for (SearchIterator* it : iterators_)
				{
					if (!it->valid())
					{
						isValid_ = false;
						return;
					}
					DocumentId currDocumentId = it->current();
					if (currDocumentId > maxDocumentId)
					{
						maxDocumentId = currDocumentId;
						matchCount = 1;
						break;
					} else if (currDocumentId < maxDocumentId) {
						while (currDocumentId < maxDocumentId)
						{
							if (!it->valid())
							{
								isValid_ = false;
								return;
							}
							currDocumentId = it->current();
							it->next();							
						}
						if (currDocumentId > maxDocumentId)
						{
							maxDocumentId = currDocumentId;
							matchCount = 1;
							break;
						}
					}
					matchCount++;
				}
				if (matchCount == totalDocumentsToMatch_)
				{
					currentDocumentId_ = maxDocumentId;
					for (SearchIterator* it : iterators_)
					{
						if (it->valid())
						{
							it->next();
						}
					}
				}
			}			
		}

		virtual DocumentId current() const override
		{	
			return currentDocumentId_;
		}

		virtual bool valid() const override
		{
			return isValid_;
		}

	private:
		std::vector<SearchIterator*> iterators_;
		size_t totalDocumentsToMatch_;
		DocumentId currentDocumentId_;
		bool isValid_;
	};
}
