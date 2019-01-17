#pragma once

#include "Utils.h"
#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include <spdlog/spdlog.h>

namespace centurion
{
	struct BooleanValueSearchIterator : SearchIterator
	{
		BooleanValueSearchIterator(const BooleanValueSearchIterator&) = delete;
		BooleanValueSearchIterator(BooleanValueSearchIterator&& other) = delete;

		static BooleanValueSearchIterator* eq(std::string fieldName, bool value)
		{
			return new BooleanValueSearchIterator(fieldName, value);
		}

		virtual ~BooleanValueSearchIterator() override
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void seek(
			std::function<IndexId(FieldType, const std::string&)> fieldNameResolver,
			std::function<rocksdb::Iterator*(FieldType, const rocksdb::Slice*, const rocksdb::Slice*)> iteratorBuilder,
			DocumentId documentId) override
		{	
			auto console = spdlog::get("root");
			delete[] lowerSliceBuf_;
			lowerSliceBuf_ = nullptr;
			delete[] upperSliceBuf_;
			upperSliceBuf_ = nullptr;
			delete iterator_;
			iterator_ = nullptr;
			indexId_ = fieldNameResolver(kBoolean, fieldName_);
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
			CreateBooleanIndex(lowerSliceBuf_, indexId_, value_);
			lowerBoundSlice_ = rocksdb::Slice(lowerSliceBuf_, lowerSliceBufSize_);
			size_t upperSliceBufSize_ = (sizeof(indexId_) + sizeof(std::uint8_t) + sizeof(DocumentId));			
			upperSliceBuf_ = (new char[upperSliceBufSize_]);
			CreateBooleanIndex(upperSliceBuf_, value_ ? indexId_ + 1 : indexId_, !value_);
			upperBoundSlice_ = rocksdb::Slice(upperSliceBuf_, upperSliceBufSize_);
			iterator_ = iteratorBuilder(kBoolean, &lowerBoundSlice_, &upperBoundSlice_);
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
		BooleanValueSearchIterator(std::string fieldName, bool value)
			:
			fieldName_(std::move(fieldName)),			
			indexId_(InvalidIndexId),
			value_(value),
			lowerSliceBuf_(nullptr),
			upperSliceBuf_(nullptr),
			iterator_(nullptr) { }

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

		std::string fieldName_;
		IndexId indexId_;
		bool value_;
		std::uint8_t lowerBoundVal_;		
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;		
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;		
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;
	};

}
