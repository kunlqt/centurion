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
		SetIndexId(dst, indexId);
		SetStringSize(dst, strSize);
		SetStringData(dst, str, strSize);
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
				return *(DocumentId*)(iterator_->key().data() + GetDocumentIdOffsetInString(GetStringSize(iterator_->key().data())));
			} else {
				auto console = spdlog::get("root");
				console->trace("StringValueSearchIterator.current().valid()=false");
			}
			throw std::runtime_error("Invalid iterator");
		}

		bool valid() const override
		{
			return isValid_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		StringValueSearchIterator(const StringValueIndexStore& store, IndexId indexId, const char* str, std::uint32_t strSize)
			:
			indexId_(indexId),
			strSize_(strSize),
			lowerSliceBufSize_(GetDocumentIdOffsetInString(strSize)),
			lowerSliceBuf_(new char[lowerSliceBufSize_]),
			lowerBoundSlice_(buildStringSlice(indexId, str, strSize, lowerSliceBuf_, lowerSliceBufSize_)),
			upperSliceBufSize_(StringBufferOffset),
			upperSliceBuf_(new char[upperSliceBufSize_]),
			upperBoundSlice_(buildStringSlice(indexId + 1, nullptr, 0, upperSliceBuf_, upperSliceBufSize_)),
			isValid_(true)
		{
			auto console = spdlog::get("root");
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;
			iterator_ = store.newIterator(opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (iterator_->Valid())
			{
				isValid_ = checkUpperBound();
			} else {
				console->error("Invalid StringValueSearchIterator when searching for string value: {0}", str);
				isValid_ = false;
			} 
		}

		bool checkUpperBound() const
		{
			const char* kd = iterator_->key().data();
			const IndexId idxA = GetIndexId(kd);
			const IndexId idxB = GetIndexId(lowerSliceBuf_);
			if (idxA == idxB) {
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
		bool isValid_;
	};

}
