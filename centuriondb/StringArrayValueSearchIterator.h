#pragma once

#include "Sha2.h"
#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include <spdlog/spdlog.h>
#include <string>

namespace centurion
{
	struct StringArrayValueSearchIterator : SearchIterator
	{
		StringArrayValueSearchIterator(const StringArrayValueSearchIterator&) = delete;
		StringArrayValueSearchIterator(StringArrayValueSearchIterator&& other) = delete;

		static StringArrayValueSearchIterator* eq(std::string fieldName, const std::string& str)
		{
			return new StringArrayValueSearchIterator(fieldName, str);
		}

		static StringArrayValueSearchIterator* eq(std::string fieldName, const char* str, std::uint32_t strSize)
		{
			return new StringArrayValueSearchIterator(fieldName, str);
		}

		virtual ~StringArrayValueSearchIterator() override
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
			indexId_ = fieldNameResolver(kStringArray, fieldName_);
			if (indexId_ == InvalidIndexId)
			{
				console->error("Field name: {0} not found", fieldName_);
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
				return;
			}
			size_t lowerSliceBufSize = (GetDocumentIdOffsetInString(value_.size()) + sizeof(DocumentId));
			lowerSliceBuf_ = (new char[lowerSliceBufSize]);
			size_t upperSliceBufSize = (StringBufferOffset + sizeof(DocumentId));
			upperSliceBuf_ = (new char[upperSliceBufSize]);
			CreateStringIndex(lowerSliceBuf_, indexId_, value_.c_str(), value_.size());
			lowerBoundSlice_ = rocksdb::Slice(lowerSliceBuf_, lowerSliceBufSize);
			CreateStringIndex(upperSliceBuf_, indexId_ + 1, "", 0);
			upperBoundSlice_ = rocksdb::Slice(upperSliceBuf_, upperSliceBufSize);			
			iterator_ = iteratorBuilder(kStringArray, &lowerBoundSlice_, &upperBoundSlice_);
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
		StringArrayValueSearchIterator(std::string fieldName, std::string value)
			:
			fieldName_(fieldName),
			value_(std::move(value)),
			indexId_(InvalidIndexId),
			lowerSliceBuf_(nullptr),
			upperSliceBuf_(nullptr),
			iterator_(nullptr),
			currentDocumentId_(InvalidDocumentId)
		{

		}

		bool checkUpperBound() const
		{
			const char* kd = iterator_->key().data();
			const IndexId idxA = GetIndexId(kd);
			if (idxA == indexId_) {
				const auto strSizeFound = GetStringSize(kd);
				if (strSizeFound == value_.size()) {
					if (iterator_->key().size() >= lowerBoundSlice_.size())
					{
						return memcmp(kd + StringBufferOffset, lowerSliceBuf_ + StringBufferOffset, strSizeFound) == 0;
					}
				}
			}
			return false;
		}
		std::string fieldName_;
		IndexId indexId_;
		std::string value_;
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;		
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;
	};

}
