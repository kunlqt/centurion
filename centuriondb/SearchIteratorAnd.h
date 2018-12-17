#pragma once

#include "SearchIterator.h"
#include "DocumentId.h"
#include <spdlog/spdlog.h>

namespace centurion
{
	struct SearchIteratorAnd : SearchIterator
	{
		SearchIteratorAnd(const SearchIteratorAnd&) = delete;
		SearchIteratorAnd(SearchIteratorAnd&&) = delete;

		SearchIteratorAnd(SearchIterator* left, SearchIterator* right)
			:
			left_(left), 
			right_(right),
			currentDocumentId_(InvalidDocumentId),
			isValid_(true)
		{
			auto console = spdlog::get("console");
			if (!left_->valid() || !right_->valid())
			{
				console->error("some of the iterators passed to SearchIteratorAnd are invalid");
				isValid_ = false;
			}
			next();
		}

		virtual ~SearchIteratorAnd() override
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
				if (!left_->valid() || !right_->valid())
				{
					isValid_ = false;
					return;
				}
				DocumentId doc1 = left_->current();
				DocumentId doc2 = right_->current();
				while (doc1 < doc2) {
					if (!left_->valid())
					{
						isValid_ = false;
						return;
					}
					left_->next();
					doc1 = left_->current();
				}
				while (doc1 > doc2) {
					if (!right_->valid())
					{
						isValid_ = false;
						return;
					}
					right_->next();
					doc2 = right_->current();
				}
				if (doc1 == doc2)
				{
					currentDocumentId_ = doc1;
					left_->next();
					right_->next();
					return;
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
		SearchIterator * left_;
		SearchIterator* right_;
		DocumentId currentDocumentId_;
		bool isValid_;
	};
}
