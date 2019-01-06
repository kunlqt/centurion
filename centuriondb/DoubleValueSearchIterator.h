#pragma once

#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include "DoubleValueIndexStore.h"
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>

namespace centurion
{
	inline rocksdb::Slice buildDoubleSlice(IndexId indexId, double value, char* dst, size_t dstSize)
	{
		CreateDoubleIndex(dst, indexId, value);
		return { dst, dstSize };
	}

	static const double DefaultComparisionPrecision = 10e-8;

	struct DoubleValueSearchIterator : SearchIterator
	{
		DoubleValueSearchIterator(const DoubleValueSearchIterator&) = delete;
		DoubleValueSearchIterator(DoubleValueSearchIterator&& other) = delete;

		static DoubleValueSearchIterator* eq(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, val - eps, val + eps);
		}


		virtual ~DoubleValueSearchIterator()
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void seek(DocumentId documentId) override
		{
			iterator_ = store_.newIterator(opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (iterator_->Valid())
			{
				if (checkUpperBound())
				{
					setState(First);
					currentDocumentId_ = ExtractDocumentIdFromDouble(iterator_->key().data());
				} else {
					setState(AfterLast);
					currentDocumentId_ = InvalidDocumentId;
				}
			} else {
				auto logger = spdlog::get("root");
				logger->error("Invalid Double search iterator");
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
			}
		}

		void next() override
		{
			if (valid() && iterator_->Valid()) {
				iterator_->Next();
				if (iterator_->Valid())
				{
					if (checkUpperBound())
					{
						if (getState() == First)
						{
							setState(None);
						}
						currentDocumentId_ = ExtractDocumentIdFromDouble(iterator_->key().data());
					} else {
						setState(AfterLast);
						currentDocumentId_ = InvalidDocumentId;
					}
				} else {
					setState(AfterLast);
					currentDocumentId_ = InvalidDocumentId;
				}
			} else {
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
			}
			auto console = spdlog::get("root");
			console->trace("DoubleSearchIterator returned: {}", currentDocumentId_);

		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}
				
		IndexId indexId() const { return indexId_; }

	private:
		DoubleValueSearchIterator(const IndexedValuesStore& store, IndexId indexId, double lowerBound, double upperBound)
			:
			store_(store),
			indexId_(indexId),
			lowerBound_(lowerBound),
			lowerSliceBufSize_(sizeof(indexId) + sizeof(double) + sizeof(DocumentId)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildDoubleSlice(indexId, lowerBound_, lowerSliceBuf_, lowerSliceBufSize_)),
			upperBound_(upperBound),
			upperSliceBufSize_(sizeof(indexId) + sizeof(double) + sizeof(DocumentId)),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildDoubleSlice(indexId, upperBound_, upperSliceBuf_, upperSliceBufSize_))
		{
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;
		}

		bool checkUpperBound() const
		{
			const char* kd = iterator_->key().data();
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
		size_t lowerSliceBufSize_;
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;
		double upperBound_;
		size_t upperSliceBufSize_;
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;
		rocksdb::ReadOptions opts_;
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;
	};

}
