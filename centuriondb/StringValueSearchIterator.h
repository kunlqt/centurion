#pragma once

#include "Utils.h"
#include "Sha2.h"
#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include <spdlog/spdlog.h>
#include <string>

namespace centurion
{
	struct StringValueSearchIterator : SearchIterator
	{
		StringValueSearchIterator(const StringValueSearchIterator&) = delete;
		StringValueSearchIterator(StringValueSearchIterator&& other) = delete;			

		static StringValueSearchIterator* eq(std::string fieldName, std::string fieldValue)
		{
			return new StringValueSearchIterator(fieldName, fieldValue);
		}

		static StringValueSearchIterator* eq(std::string fieldName, const char* fieldValue, std::uint32_t fieldValueSize)
		{
			return new StringValueSearchIterator(fieldName, std::string(fieldValue, fieldValueSize));
		}

		virtual ~StringValueSearchIterator() override
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
			indexId_ = fieldNameResolver(kString, fieldName_);
			if (indexId_ == InvalidIndexId)
			{
				console->error("Field name: {0} not found", fieldName_);
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
				return;
			}
			size_t lowerSliceBufSize = (GetDocumentIdOffsetInString(fieldValue_.size()) + sizeof(DocumentId));
			lowerSliceBuf_ = (new char[lowerSliceBufSize]);
			size_t upperSliceBufSize = (StringBufferOffset + sizeof(DocumentId));
			upperSliceBuf_ = (new char[upperSliceBufSize]);
			CreateStringIndex(lowerSliceBuf_, indexId_, fieldValue_.c_str(), fieldValue_.size());
			lowerBoundSlice_ = rocksdb::Slice(lowerSliceBuf_, lowerSliceBufSize);
			CreateStringIndex(upperSliceBuf_, indexId_ + 1, "", 0);
			upperBoundSlice_ = rocksdb::Slice(upperSliceBuf_, upperSliceBufSize);
			iterator_ = iteratorBuilder(kString, &lowerBoundSlice_, &upperBoundSlice_);
			iterator_->Seek(lowerBoundSlice_);
			if (iterator_->Valid()) {
				if (checkUpperBound()) {
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
			 auto console = spdlog::get("root");
			console->trace("StringSearchIterator returned: {}", currentDocumentId_);
		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		StringValueSearchIterator(std::string fieldName, std::string fieldValue)
			:
			fieldName_(std::move(fieldName)),
			fieldValue_(std::move(fieldValue)),
			indexId_(InvalidIndexId),
			lowerSliceBuf_(nullptr),
			upperSliceBuf_(nullptr),
			iterator_(nullptr),
			currentDocumentId_(InvalidDocumentId) { }

		bool checkUpperBound() const
		{
			const char* kd = iterator_->key().data();
			const IndexId idxA = GetIndexId(kd);
			if (idxA == indexId_) {
				const auto strSizeFound = GetStringSize(kd);
				if ((strSizeFound == fieldValue_.size()) && (iterator_->key().size() >= lowerBoundSlice_.size())) {
					return memcmp(kd + StringBufferOffset, lowerSliceBuf_ + StringBufferOffset, strSizeFound) == 0;
				}
			}
			return false;
		}
		
		std::string fieldName_;
		IndexId indexId_;
		std::string fieldValue_;
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;		
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;
	};

}
