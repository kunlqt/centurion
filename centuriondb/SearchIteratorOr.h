#pragma once

#include "SearchIterator.h"
#include "DocumentId.h"
#include <spdlog/spdlog.h>

namespace centurion
{
	struct SearchIteratorOr : SearchIterator
	{
		SearchIteratorOr(const SearchIteratorOr&) = delete;
		SearchIteratorOr(SearchIteratorOr&&) = delete;

		SearchIteratorOr(SearchIterator* left, SearchIterator* right)
			:
			left_(left),
			right_(right),
			currentDocumentId_(InvalidDocumentId),
			isValid_(true)
		{
			auto console = spdlog::get("root");
			if (!left_->valid() || !right_->valid())
			{
				console->error("some of the iterators passed to SearchIteratorOr are invalid");
				isValid_ = false;
			}
			next();
		}

		virtual ~SearchIteratorOr() override
		{
			delete left_;
			delete right_;
		}

		virtual void next() override
		{
			if (!isValid_)
			{
				return;
			}
			while (true) {
				if (!left_->valid())
				{
					if (!right_->valid())
					{
						isValid_ = false;
						return;
					}
					currentDocumentId_ = right_->current();
					right_->next();
					return;
				}
				if (!right_->valid())
				{
					currentDocumentId_ = left_->current();
					left_->next();
					return;
				}

				DocumentId doc1 = left_->current();
				DocumentId doc2 = right_->current();
				if (doc1 < doc2)
				{
					currentDocumentId_ = doc1;
					left_->next();
					return;
				}
				if (doc1 > doc2)
				{
					currentDocumentId_ = doc2;
					right_->next();
					return;
				}
				currentDocumentId_ = doc2;
				left_->next();
				right_->next();
				return;
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
		SearchIterator * left_;
		SearchIterator* right_;
		DocumentId currentDocumentId_;
		bool isValid_;
	};
}
