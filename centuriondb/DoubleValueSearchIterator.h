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
		*((IndexId*)dst) = indexId;
		*((double*)(dst + sizeof(indexId))) = value;
		return { dst, dstSize };
	}

	static const double DefaultComparisionPrecision = 10e-8;

	struct DoubleValueSearchIterator : SearchIterator
	{
		DoubleValueSearchIterator(const DoubleValueSearchIterator&) = delete;
		DoubleValueSearchIterator(DoubleValueSearchIterator&& other) = delete;

		static DoubleValueSearchIterator* eq(DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, val, val, eps);
		}

		static DoubleValueSearchIterator* lt(DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, std::numeric_limits<double>::min(), val, eps);
		}

		static DoubleValueSearchIterator* gt(DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, val, std::numeric_limits<double>::max(), eps);
		}

		static DoubleValueSearchIterator* between(DoubleValueIndexStore& store, IndexId indexId, double lower, double upper, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, lower, upper, eps);
		}

		virtual ~DoubleValueSearchIterator()
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		DocumentId next() override
		{
			const DocumentId result = current();
			iterator_->Next();
			return result;
		}

		DocumentId current() const override
		{
			if (iterator_->Valid()) {
				return *(DocumentId*)(iterator_->key().data() + sizeof(indexId_) + sizeof(double));
			} else {
				auto console = spdlog::get("console");
				console->trace("DoubleValueSearchIterator.current().valid()=false");
			}
			throw std::runtime_error("Invalid iterator");
		}

		bool valid() const override
		{
			if (iterator_->Valid())
			{
				const char* kd = iterator_->key().data();
				const IndexId idxA = GetIndexId(kd);
				const IndexId idxB = GetIndexId(lowerSliceBuf_);
				if (idxA == idxB) {
					const double valueFound = *reinterpret_cast<const double*>(kd + sizeof(indexId_));
					return (lowerBound_ <= valueFound) && (valueFound <= upperBound_);
				}
			}
			return false;
		}

		IndexId indexId() const { return indexId_; }

	private:
		DoubleValueSearchIterator(DoubleValueIndexStore& store, IndexId indexId, double lowerBound, double upperBound, double eps)
			:
			store_(store),
			indexId_(indexId),
			lowerBound_(lowerBound - eps),
			lowerSliceBufSize_(sizeof(indexId) + sizeof(double)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildDoubleSlice(indexId, lowerBound_, lowerSliceBuf_, lowerSliceBufSize_)),
			upperBound_(upperBound + eps),
			upperSliceBufSize_(sizeof(indexId) + sizeof(double)),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildDoubleSlice(indexId, upperBound_, upperSliceBuf_, upperSliceBufSize_))
		{
			auto console = spdlog::get("console");
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;
			iterator_ = store_.newIterator(opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (!iterator_->Valid()) {
				console->error("Invalid DoubleValueSearchIterator when searching for double values between {0} and {1}", lowerBound_, upperBound_);
			}
		}

		DoubleValueIndexStore& store_;
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

	};

}
