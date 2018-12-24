#pragma once

#include "Sha2.h"
#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include "StringValueIndexStore.h"
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>
#include <string>

namespace centurion
{
	inline rocksdb::Slice buildStringSlice(IndexId indexId, const char* str, StringSizeType strSize, char* dst, size_t dstSize)
	{		
		CreateStringIndex(dst, indexId, str, strSize);
		return { dst, dstSize };
	}

	struct StringValueSearchIterator : SearchIterator
	{
		StringValueSearchIterator(const StringValueSearchIterator&) = delete;
		StringValueSearchIterator(StringValueSearchIterator&& other) = delete;			

		static StringValueSearchIterator* eq(const StringValueIndexStore& store, IndexId indexId, const std::string& str)
		{
			return new StringValueSearchIterator(store, indexId, str.data(), str.size());
		}

		static StringValueSearchIterator* eq(const StringValueIndexStore& store, IndexId indexId, const char* str, std::uint32_t strSize)
		{
			return new StringValueSearchIterator(store, indexId, str, strSize);
		}

		virtual ~StringValueSearchIterator() override
		{	
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void next() override
		{
			auto console = spdlog::get("root");
			if (getState() == BeforeFirst) {
				iterator_ = store_.newIterator(opts_);
				iterator_->Seek(lowerBoundSlice_);
				if (iterator_->Valid())
				{
					if (checkUpperBound())
					{
						setState(First);
						currentDocumentId_ = ExtractDocumentIdFromString(iterator_->key().data());
					} else {
						setState(AfterLast);
						currentDocumentId_ = InvalidDocumentId;
					}
				} else {					
					console->error("Invalid string search iterator");
					setState(AfterLast);
					currentDocumentId_ = InvalidDocumentId;
				}
			} else if (valid() && iterator_->Valid()) {
				iterator_->Next();
				if (iterator_->Valid())
				{
					if (checkUpperBound())
					{
						if (getState() == First)
						{
							setState(None);
						}
						currentDocumentId_ = ExtractDocumentIdFromString(iterator_->key().data());
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
			console->trace("StringSearchIterator returned: {}", currentDocumentId_);
		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		StringValueSearchIterator(const IndexedValuesStore& store, IndexId indexId, const char* str, std::uint32_t strSize)
			:
			store_(store),
			indexId_(indexId),
			strSize_(strSize),
			lowerSliceBufSize_(GetDocumentIdOffsetInString(strSize)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildStringSlice(indexId, str, strSize, lowerSliceBuf_, lowerSliceBufSize_)),
			upperSliceBufSize_(StringBufferOffset),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildStringSlice(indexId + 1, nullptr, 0, upperSliceBuf_, upperSliceBufSize_)),
			iterator_(nullptr),
			currentDocumentId_(InvalidDocumentId)
		{
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;
		}

		bool checkUpperBound() const
		{
			const char* kd = iterator_->key().data();
			const IndexId idxA = GetIndexId(kd);
			if (idxA == indexId_) {
				const auto strSizeFound = GetStringSize(kd);
				if (strSizeFound == strSize_) {
					if (iterator_->key().size() >= lowerSliceBufSize_)
					{
						return memcmp(kd + StringBufferOffset, lowerSliceBuf_ + StringBufferOffset, strSizeFound) == 0;
					}
				}
			}
			return false;
		}
		const IndexedValuesStore& store_;
		IndexId indexId_;
		StringSizeType strSize_;
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
