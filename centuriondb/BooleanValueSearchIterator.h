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
		CreateBooleanIndex(dst, indexId, value);
		return { dst, dstSize };
	}

	struct BooleanValueSearchIterator : SearchIterator
	{
		BooleanValueSearchIterator(const BooleanValueSearchIterator&) = delete;
		BooleanValueSearchIterator(BooleanValueSearchIterator&& other) = delete;

		static BooleanValueSearchIterator* eq(const BooleanValueIndexStore& store, IndexId indexId, bool val)
		{
			return new BooleanValueSearchIterator(store, indexId, val);
		}

		virtual ~BooleanValueSearchIterator() override
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void seek(DocumentId documentId) override
		{
			auto console = spdlog::get("root");
			iterator_ = store_.newIterator(opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (iterator_->Valid())
			{
				if (checkUpperBound())
				{
					setState(First);
					currentDocumentId_ = ExtractDocumentIdFromBoolean(iterator_->key().data());
				} else {
					setState(AfterLast);
					currentDocumentId_ = InvalidDocumentId;
				}
			} else {
				console->error("Invalid Boolean search iterator");
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
						currentDocumentId_ = ExtractDocumentIdFromBoolean(iterator_->key().data());
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
			console->trace("BooleanSearchIterator returned: {}", currentDocumentId_);

		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		BooleanValueSearchIterator(const IndexedValuesStore& store, IndexId indexId, bool val)
			:
			store_(store),
			indexId_(indexId),
			lowerBoundVal_(val ? 1 : 0),
			lowerSliceBufSize_(sizeof(indexId) + sizeof(std::uint8_t) + sizeof(DocumentId)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildBooleanSlice(indexId, val, lowerSliceBuf_, lowerSliceBufSize_)),
			upperSliceBufSize_(sizeof(indexId) + sizeof(std::uint8_t) + sizeof(DocumentId)),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildBooleanSlice(val ? indexId + 1: indexId, !val, upperSliceBuf_, upperSliceBufSize_))
		{
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;
		}

		bool checkUpperBound() const
		{
			const char* kd = iterator_->key().data();
			const IndexId idxA = GetIndexId(kd);
			if (idxA == indexId_) {
				const std::uint8_t valueFound = *reinterpret_cast<const std::uint8_t*>(kd + sizeof(indexId_));
				return (lowerBoundVal_ == valueFound);
			}
			return false;
		}

		const IndexedValuesStore& store_;
		IndexId indexId_;
		std::uint8_t lowerBoundVal_;
		size_t lowerSliceBufSize_;
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;
		size_t upperSliceBufSize_;
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;
		rocksdb::ReadOptions opts_;
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;

	};

}
