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
		SetIndexId(dst, indexId);
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

		static DoubleValueSearchIterator* lt(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, std::numeric_limits<double>::min(), val - eps);
		}

		static DoubleValueSearchIterator* gt(const DoubleValueIndexStore& store, IndexId indexId, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, val + eps, std::numeric_limits<double>::max());
		}

		static DoubleValueSearchIterator* between(const DoubleValueIndexStore& store, IndexId indexId, double lower, double upper, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(store, indexId, lower + eps, upper - eps);
		}

		virtual ~DoubleValueSearchIterator()
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void next() override
		{
			if (iterator_ == nullptr)
			{
				iterator_ = store_.newIterator(opts_);
				iterator_->Seek(lowerBoundSlice_);
				if (iterator_->Valid())
				{
					isValid_ = checkUpperBound();
				} else {
					auto console = spdlog::get("root");
					console->error("Invalid DoubleValueSearchIterator when searching for double values between {0} and {1}", lowerBound_, upperBound_);
					isValid_ = false;
				}
				return;
			}
			if (isValid_ && iterator_->Valid()) {
				iterator_->Next();
				if (iterator_->Valid())
				{
					isValid_ = checkUpperBound();
				} else
				{
					isValid_ = false;
				}
			} else {
				isValid_ = false;
			}
		}

		DocumentId current() const override
		{
			if (isValid_) {
				return *(DocumentId*)(iterator_->key().data() + sizeof(indexId_) + sizeof(double));
			} else {
				auto console = spdlog::get("root");
				console->trace("DoubleValueSearchIterator.current().valid()=false");
			}
			throw std::runtime_error("Invalid iterator");
		}

		bool valid() const override
		{
			return isValid_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		DoubleValueSearchIterator(const DoubleValueIndexStore& store, IndexId indexId, double lowerBound, double upperBound)
			:
			iterator_(nullptr),
			store_(store),
			indexId_(indexId),
			lowerBound_(lowerBound),
			lowerSliceBufSize_(sizeof(indexId) + sizeof(double)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildDoubleSlice(indexId, lowerBound_, lowerSliceBuf_, lowerSliceBufSize_)),
			upperBound_(upperBound),
			upperSliceBufSize_(sizeof(indexId) + sizeof(double)),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildDoubleSlice(indexId, upperBound_, upperSliceBuf_, upperSliceBufSize_))
		, isValid_(true)
		{
			auto console = spdlog::get("root");
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

		const DoubleValueIndexStore& store_;
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
		bool isValid_;
	};

}
