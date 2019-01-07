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

		static BooleanValueSearchIterator* eq(const BooleanValueIndexStore& store, std::string fieldName, bool value)
		{
			return new BooleanValueSearchIterator(store, fieldName, value);
		}

		virtual ~BooleanValueSearchIterator() override
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void seek(std::function<IndexId(const std::string&)> fieldNameResolver, DocumentId documentId) override
		{	
			auto console = spdlog::get("root");
			delete[] lowerSliceBuf_;
			lowerSliceBuf_ = nullptr;
			delete[] upperSliceBuf_;
			upperSliceBuf_ = nullptr;
			delete iterator_;
			iterator_ = nullptr;
			indexId_ = fieldNameResolver(fieldName_);
			if (indexId_ == InvalidIndexId)
			{
				console->error("Field name: {0} not found", fieldName_);
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
				return;
			}
			lowerBoundVal_ = (value_ ? 1 : 0);
			size_t lowerSliceBufSize_ = (sizeof(indexId_) + sizeof(std::uint8_t) + sizeof(DocumentId));			
			lowerSliceBuf_ = (new char[lowerSliceBufSize_]);
			lowerBoundSlice_ = (buildBooleanSlice(indexId_, value_, lowerSliceBuf_, lowerSliceBufSize_));
			size_t upperSliceBufSize_ = (sizeof(indexId_) + sizeof(std::uint8_t) + sizeof(DocumentId));			
			upperSliceBuf_ = (new char[upperSliceBufSize_]);
			upperBoundSlice_ = (buildBooleanSlice(value_ ? indexId_ + 1 : indexId_, !value_, upperSliceBuf_, upperSliceBufSize_));
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;			
			iterator_ = store_.newIterator(opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (iterator_->Valid()) {
				if (checkUpperBound()) {
					setState(First);
					currentDocumentId_ = ExtractDocumentIdFromBoolean(iterator_->key().data());
				} else {
					setState(AfterLast);
					currentDocumentId_ = InvalidDocumentId;
				}
			} else {
				auto console = spdlog::get("root");
				console->error("Invalid Boolean search iterator");
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
			}
		}

		void next() override
		{
			if (valid() && iterator_->Valid()) {
				iterator_->Next();
				if (iterator_->Valid()) {
					if (checkUpperBound()) {
						if (getState() == First) {
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
		BooleanValueSearchIterator(const IndexedValuesStore& store, std::string fieldName, bool value)
			:
			store_(store),
			fieldName_(fieldName),			
			indexId_(InvalidIndexId),
			value_(value),
			lowerSliceBuf_(nullptr),
			upperSliceBuf_(nullptr),
			iterator_(nullptr)
		{
		
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
		std::string fieldName_;
		IndexId indexId_;
		bool value_;
		std::uint8_t lowerBoundVal_;		
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;		
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;
		rocksdb::ReadOptions opts_;
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;
	};

}
