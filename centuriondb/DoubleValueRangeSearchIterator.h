#pragma once

#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include "Utils.h"
#include "IndexedValuesStore.h"
#include "DoubleValueIndexStore.h"
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>

namespace centurion
{	
	struct DoubleValueRangeSearchIterator : SearchIterator
	{				
		DoubleValueRangeSearchIterator(const DoubleValueRangeSearchIterator&) = delete;
		DoubleValueRangeSearchIterator(DoubleValueRangeSearchIterator&& other) = delete;

		virtual ~DoubleValueRangeSearchIterator()
		{
			
		}

		static DoubleValueRangeSearchIterator* lt(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(store, indexId, std::numeric_limits<double>::min(), val - eps);
		}

		static DoubleValueRangeSearchIterator* gt(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(store, indexId, val + eps, std::numeric_limits<double>::max());
		}

		static DoubleValueRangeSearchIterator* lte(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(store, indexId, std::numeric_limits<double>::min(), val + (eps / 2));
		}

		static DoubleValueRangeSearchIterator* gte(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(store, indexId, val - (eps / 2), std::numeric_limits<double>::max());
		}

		static DoubleValueRangeSearchIterator* between(const DoubleValueIndexStore& store, IndexId indexId, double lower, double upper, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(store, indexId, lower + eps, upper - eps);
		}

		void seek(DocumentId documentId) override
		{
			size_t lowerSliceBufSize_ = (sizeof(IndexId) + sizeof(double) + sizeof(DocumentId));
			char* lowerSliceBuf_ = (new char[lowerSliceBufSize_]);
			size_t upperSliceBufSize_ = (sizeof(IndexId) + sizeof(double) + sizeof(DocumentId));
			char* upperSliceBuf_ = (new char[upperSliceBufSize_]);

			rocksdb::Slice lowerBoundSlice_ = (buildDoubleSlice(indexId_, lowerBound_, lowerSliceBuf_, lowerSliceBufSize_));
			rocksdb::Slice upperBoundSlice_ = (buildDoubleSlice(indexId_, upperBound_, upperSliceBuf_, upperSliceBufSize_));

			rocksdb::ReadOptions opts_;
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;

			rocksdb::Iterator* iterator = store_.newIterator(opts_);
			iterator->Seek(lowerBoundSlice_);
			while (iterator->Valid()) {
				if (checkUpperBound(iterator->key().data()))
				{
					documentBuffer_.push_back(ExtractDocumentIdFromDouble(iterator->key().data()));
					iterator->Next();
				} else {
					break;
				}
			}
			delete iterator;
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;

			if (documentBuffer_.empty())
			{
				setState(AfterLast);
				documentBufferPos_ = 0;
				return;
			}
			std::sort(documentBuffer_.begin(), documentBuffer_.end());
			documentBufferPos_ = 1;
			currentDocumentId_ = documentBuffer_.front();
			setState(First);
		}

		void next() override
		{
			if (documentBufferPos_ == documentBuffer_.size()) {
				setState(AfterLast);
				return;
			}
			while (documentBufferPos_ < documentBuffer_.size()) {
				DocumentId tmpDocumentId = documentBuffer_[documentBufferPos_++];
				if (tmpDocumentId != currentDocumentId_)
				{
					currentDocumentId_ = tmpDocumentId;
					break;
				}				
			}			
		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		DoubleValueRangeSearchIterator(const IndexedValuesStore& store, IndexId indexId, double lowerBound, double upperBound)
			:
			store_(store),
			indexId_(indexId),
			lowerBound_(lowerBound),
			upperBound_(upperBound),
			currentDocumentId_(InvalidDocumentId)
		{

		}
		
		inline rocksdb::Slice buildDoubleSlice(IndexId indexId, double value, char* dst, size_t dstSize)
		{
			CreateDoubleIndex(dst, indexId, value);
			return { dst, dstSize };
		}

		bool checkUpperBound(const char* kd) const
		{
			const IndexId idxA = GetIndexId(kd);
			if (idxA == indexId_) {
				const double valueFound = *reinterpret_cast<const double*>(kd + sizeof(indexId_));
				return (lowerBound_ <= valueFound) && (valueFound <= upperBound_);
			}
			return false;
		}

		const IndexedValuesStore& store_;
		IndexId indexId_;
		double lowerBound_;
		double upperBound_;
		std::vector<DocumentId> documentBuffer_;
		size_t documentBufferPos_;
		DocumentId currentDocumentId_;
	};

}
