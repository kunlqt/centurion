#pragma once

#include "IndexId.h"
#include "DocumentId.h"
#include "SearchIterator.h"
#include "Utils.h"
#include <spdlog/spdlog.h>

namespace centurion
{	
	struct DoubleValueRangeSearchIterator : SearchIterator
	{				
		DoubleValueRangeSearchIterator(const DoubleValueRangeSearchIterator&) = delete;
		DoubleValueRangeSearchIterator(DoubleValueRangeSearchIterator&& other) = delete;

		virtual ~DoubleValueRangeSearchIterator()
		{
			
		}

		static DoubleValueRangeSearchIterator* lt(std::string fieldName, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(fieldName, std::numeric_limits<double>::min(), val - eps);
		}

		static DoubleValueRangeSearchIterator* gt(std::string fieldName, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(fieldName, val + eps, std::numeric_limits<double>::max());
		}

		static DoubleValueRangeSearchIterator* lte(std::string fieldName, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(fieldName, std::numeric_limits<double>::min(), val + (eps / 2));
		}

		static DoubleValueRangeSearchIterator* gte(std::string fieldName, double val, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(fieldName, val - (eps / 2), std::numeric_limits<double>::max());
		}

		static DoubleValueRangeSearchIterator* between(std::string fieldName, double lower, double upper, double eps = DefaultComparisionPrecision)
		{
			return new DoubleValueRangeSearchIterator(fieldName, lower + eps, upper - eps);
		}

		void seek(std::function<IndexId(FieldType, const std::string&)> fieldNameResolver,
			std::function<rocksdb::Iterator*(FieldType, const rocksdb::Slice*, const rocksdb::Slice*)> iteratorBuilder,
			DocumentId documentId) override
		{
			auto console = spdlog::get("root");
			documentBufferPos_ = 0;
			indexId_ = fieldNameResolver(kDouble, fieldName_);
			if (indexId_ == InvalidIndexId)
			{
				console->error("Field name: {0} not found", fieldName_);
				setState(AfterLast);
				currentDocumentId_ = InvalidDocumentId;
				return;
			}			
			size_t lowerSliceBufSize_ = (sizeof(IndexId) + sizeof(double) + sizeof(DocumentId));
			char* lowerSliceBuf_ = (new char[lowerSliceBufSize_]);
			size_t upperSliceBufSize_ = (sizeof(IndexId) + sizeof(double) + sizeof(DocumentId));
			char* upperSliceBuf_ = (new char[upperSliceBufSize_]);

			rocksdb::Slice lowerBoundSlice_ = (buildDoubleSlice(indexId_, lowerBound_, lowerSliceBuf_, lowerSliceBufSize_));
			rocksdb::Slice upperBoundSlice_ = (buildDoubleSlice(indexId_, upperBound_, upperSliceBuf_, upperSliceBufSize_));

			rocksdb::Iterator* iterator = iteratorBuilder(kDouble, &lowerBoundSlice_, &upperBoundSlice_);
			iterator->Seek(lowerBoundSlice_);
			while (iterator->Valid()) {
				if (checkUpperBound(iterator->key().data()))
				{
					documentBuffer_.push_back(ExtractDocumentIdFromDouble(iterator->key().data()));
					iterator->Next();
				} else {
					break;
				}
			}
			delete iterator;
			delete[] lowerSliceBuf_;
			delete[] upperSliceBuf_;

			if (documentBuffer_.empty())
			{
				setState(AfterLast);
				documentBufferPos_ = 0;
				return;
			}
			std::sort(documentBuffer_.begin(), documentBuffer_.end());
			documentBufferPos_ = 1;
			currentDocumentId_ = documentBuffer_.front();
			setState(First);
		}

		void next() override
		{
			if (documentBufferPos_ == documentBuffer_.size()) {
				setState(AfterLast);
				return;
			}
			while (documentBufferPos_ < documentBuffer_.size()) {
				const DocumentId tmpDocumentId = documentBuffer_[documentBufferPos_];
				documentBufferPos_++;
				if (tmpDocumentId != currentDocumentId_)
				{
					currentDocumentId_ = tmpDocumentId;
					break;
				}				
			}			
		}

		DocumentId current() const override
		{
			return currentDocumentId_;
		}

		IndexId indexId() const { return indexId_; }

	private:
		DoubleValueRangeSearchIterator(std::string fieldName, double lowerBound, double upperBound)
			:
			fieldName_(std::move(fieldName)),
			indexId_(InvalidIndexId),
			lowerBound_(lowerBound),
			upperBound_(upperBound),
			currentDocumentId_(InvalidDocumentId) { }
		
		inline rocksdb::Slice buildDoubleSlice(IndexId indexId, double value, char* dst, size_t dstSize)
		{
			CreateDoubleIndex(dst, indexId, value);
			return { dst, dstSize };
		}

		bool checkUpperBound(const char* kd) const
		{
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
		double upperBound_;
		std::vector<DocumentId> documentBuffer_;
		size_t documentBufferPos_;
		DocumentId currentDocumentId_;
	};

}
