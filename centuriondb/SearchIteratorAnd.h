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
			currentDocumentId_(InvalidDocumentId)
		{
					
		}

		virtual ~SearchIteratorAnd() override
		{
			delete left_;
			delete right_;
		}
		
		void seek(std::function<IndexId(const std::string&)> fieldNameResolver, DocumentId documentId) override
		{
			left_->seek(fieldNameResolver, documentId);
			if (!left_->valid())
			{
				setState(AfterLast);
				return;
			}
			right_->seek(fieldNameResolver, documentId);
			if (!right_->valid())
			{
				setState(AfterLast);
				return;
			}
			next();
		}

		virtual void next() override
		{
			if (getState() == AfterLast)
			{
				auto logger = spdlog::get("root");
				logger->error("Trying to move iterator after last element");
				currentDocumentId_ = InvalidDocumentId;
				return;
			}
			if (valid()) {
				left_->next();
				if (!left_->valid())
				{
					setState(AfterLast);
					return;
				}
				right_->next();
				if (!right_->valid())
				{
					setState(AfterLast);
					return;
				}
			}
			while (true) {
				while (left_->current() < right_->current()) {
					left_->next();
					if (!left_->valid()) {
						setState(AfterLast);
						return;
					}										
				}
				while (left_->current() > right_->current()) {
					right_->next();
					if (!right_->valid()) {
						setState(AfterLast);
						return;
					}
				}
				if (left_->current() == right_->current()) {
					currentDocumentId_ = left_->current();
					if (getState() == BeforeFirst) {
						setState(First);
					} else if (getState() == First) {
						setState(None);
					}
					return;
				}
			}
		}

		virtual DocumentId current() const override
		{
			return currentDocumentId_;
		}


	private:
		SearchIterator * left_;
		SearchIterator* right_;
		DocumentId currentDocumentId_;
	};
}
