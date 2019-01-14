#pragma once

#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include <spdlog/spdlog.h>

namespace centurion
{
	inline rocksdb::Slice buildDoubleSlice(IndexId indexId, double value, char* dst, size_t dstSize)
	{
		CreateDoubleIndex(dst, indexId, value);
		return { dst, dstSize };
	}

	struct DoubleValueSearchIterator : SearchIterator
	{
		DoubleValueSearchIterator(const DoubleValueSearchIterator&) = delete;
		DoubleValueSearchIterator(DoubleValueSearchIterator&& other) = delete;

		static DoubleValueSearchIterator* eq(std::string fieldName, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueSearchIterator(fieldName, val - eps, val + eps);
		}

		virtual ~DoubleValueSearchIterator()
		{
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;
			delete iterator_;
		}

		void seek(
			std::function<IndexId(FieldType, const std::string&)> fieldNameResolver,
			std::function<rocksdb::Iterator*(FieldType, rocksdb::ReadOptions& opts)> iteratorBuilder,
			DocumentId documentId) override
		{	
			auto console = spdlog::get("root");
			delete[] lowerSliceBuf_;
			lowerSliceBuf_ = nullptr;
			delete[] upperSliceBuf_;
			upperSliceBuf_ = nullptr;
			delete iterator_;
			iterator_ = nullptr;
			indexId_ = fieldNameResolver(kDouble, fieldName_);
			if (indexId_ == InvalidIndexId)
			{
				console->error("Field name: {0} not found", fieldName_);
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
				return;
			}
			const size_t lowerSliceBufSize = (sizeof(indexId_) + sizeof(double) + sizeof(DocumentId));			
			lowerSliceBuf_ = (new char[lowerSliceBufSize]);
			lowerBoundSlice_ = (buildDoubleSlice(indexId_, lowerBound_, lowerSliceBuf_, lowerSliceBufSize));
			const size_t upperSliceBufSize = (sizeof(indexId_) + sizeof(double) + sizeof(DocumentId));			
			upperSliceBuf_ = (new char[upperSliceBufSize]);
			upperBoundSlice_ = (buildDoubleSlice(indexId_, upperBound_, upperSliceBuf_, upperSliceBufSize));
			opts_.iterate_lower_bound = &lowerBoundSlice_;
			opts_.iterate_upper_bound = &upperBoundSlice_;			
			iterator_ = iteratorBuilder(kDouble, opts_);
			iterator_->Seek(lowerBoundSlice_);
			if (iterator_->Valid())
			{
				if (checkUpperBound())
				{
					setState(First);
					currentDocumentId_ = ExtractDocumentIdFromDouble(iterator_->key().data());
				} else {
					setState(AfterLast);
					currentDocumentId_ = InvalidDocumentId;
				}
			} else {
				auto logger = spdlog::get("root");
				logger->error("Invalid Double search iterator");
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
						currentDocumentId_ = ExtractDocumentIdFromDouble(iterator_->key().data());
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
			console->trace("DoubleSearchIterator returned: {}", currentDocumentId_);

		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}
				
		IndexId indexId() const { return indexId_; }

	private:
		DoubleValueSearchIterator(std::string fieldName, double lowerBound, double upperBound)
			:
			fieldName_(fieldName),			
			indexId_(InvalidIndexId),
			lowerBound_(lowerBound),
			lowerSliceBuf_(nullptr),
			upperBound_(upperBound),
			upperSliceBuf_(nullptr),
			iterator_(nullptr),
			currentDocumentId_(InvalidDocumentId)
		{
		}

		bool checkUpperBound() const {
			const char* kd = iterator_->key().data();
			const IndexId idxA = GetIndexId(kd);
			if (idxA == indexId_) {
				const double valueFound = *reinterpret_cast<const double*>(kd + sizeof(indexId_));
				return (lowerBound_ <= valueFound) && (valueFound <= upperBound_);
			}
			return false;
		}
		std::string fieldName_;
		IndexId indexId_;
		double lowerBound_;
		char* lowerSliceBuf_;
		rocksdb::Slice lowerBoundSlice_;
		double upperBound_;		
		char* upperSliceBuf_;
		rocksdb::Slice upperBoundSlice_;
		rocksdb::ReadOptions opts_;
		rocksdb::Iterator* iterator_;
		DocumentId currentDocumentId_;
	};

}
