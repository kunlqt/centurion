#pragma once

#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include "BooleanValueIndexStore.h"
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace centurion
{
	inline rocksdb::Slice buildBooleanSlice(IndexId indexId, bool value, char* dst, size_t dstSize)
	{
		*((IndexId*)dst) = indexId;
		*((std::uint8_t*)(dst + sizeof(indexId))) = (value ? 1 : 0);
		return { dst, dstSize };
	}

	struct BooleanValueSearchIterator : SearchIterator
	{
		BooleanValueSearchIterator(const BooleanValueSearchIterator&) = delete;
		BooleanValueSearchIterator(BooleanValueSearchIterator&& other) = delete;

		static BooleanValueSearchIterator* eq(BooleanValueIndexStore& store, IndexId indexId, bool val)
		{
			return new BooleanValueSearchIterator(store, indexId, val);
		}

		virtual ~BooleanValueSearchIterator() override
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void next() override
		{
			iterator_->Next();
		}

		DocumentId current() const override
		{
			if (iterator_->Valid()) {
				return *(DocumentId*)(iterator_->key().data() + sizeof(indexId_) + sizeof(std::uint8_t));
			} else {
				auto console = spdlog::get("root");
				console->trace("BooleanValueSearchIterator.current().valid()=false");
			}
			throw std::runtime_error("Invalid iterator");
		}

		bool valid() const override
		{
			if (iterator_->Valid())
			{
				const char* kd = iterator_->key().data();
				const IndexId idxA = *(IndexId*)kd;
				const IndexId idxB = *(IndexId*)(lowerSliceBuf_);
				if (idxA == idxB) {
					const bool valueFound = (*reinterpret_cast<const std::uint8_t*>(kd + sizeof(indexId_))) == 1;
					return (valueFound == lowerBoundVal_);
				}
			}
			return false;
		}

		IndexId indexId() const { return indexId_; }

	private:
		BooleanValueSearchIterator(BooleanValueIndexStore& store, IndexId indexId, bool val)
			:
			store_(store),
			indexId_(indexId),
			lowerBoundVal_(val),
			lowerSliceBufSize_(sizeof(indexId) + sizeof(std::uint8_t)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildBooleanSlice(indexId, val, lowerSliceBuf_, lowerSliceBufSize_)),
			upperSliceBufSize_(sizeof(indexId) + sizeof(std::uint8_t)),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildBooleanSlice(val ? indexId + 1: indexId, !val, upperSliceBuf_, upperSliceBufSize_))
		{
			auto console = spdlog::get("root");
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;
			iterator_ = store_.newIterator(opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (!iterator_->Valid())
			{
				console->error("Invalid StringValueSearchIterator when searching for bool value: {0}", val);
			}
		}

		BooleanValueIndexStore& store_;
		IndexId indexId_;
		bool lowerBoundVal_;
		size_t lowerSliceBufSize_;
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;
		size_t upperSliceBufSize_;
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;
		rocksdb::ReadOptions opts_;
		rocksdb::Iterator* iterator_;

	};

}
