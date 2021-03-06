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
			currentDocumentId_(InvalidDocumentId)
		{
			auto console = spdlog::get("root");
			
		}

		virtual ~SearchIteratorOr() override
		{
			delete left_;
			delete right_;
		}

		void seek(std::function<IndexId(FieldType, const std::string&)> fieldNameResolver,
			std::function<rocksdb::Iterator*(FieldType, const rocksdb::Slice*, const rocksdb::Slice*)> iteratorBuilder,
			DocumentId documentId) override
		{
			left_->seek(fieldNameResolver, iteratorBuilder, documentId);
			right_->seek(fieldNameResolver, iteratorBuilder, documentId);
			if (!left_->valid() && !right_->valid())
			{
				setState(AfterLast);
				return;
			}
			next();
		}

		virtual void next() override
		{
			if (!left_->valid())
			{
				if (!right_->valid())
				{
					setState(AfterLast);
					return;
				}
				currentDocumentId_ = right_->current();
				setState(None);
				right_->next();
				return;
			} 
			if (!right_->valid())
			{
				currentDocumentId_ = left_->current();
				setState(None);
				left_->next();
				return;
			}
			const DocumentId doc1 = left_->current();
			const DocumentId doc2 = right_->current();
			if (doc1 < doc2)
			{
				currentDocumentId_ = doc1;
				left_->next();
				setState(None);
			} else if (doc1 > doc2) {
				currentDocumentId_ = doc2;
				right_->next();
				setState(None);
			} else {
				currentDocumentId_ = doc2;
				left_->next();
				right_->next();
				setState(None);
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
