#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "Utils.h"
#include <rocksdb/comparator.h>

namespace centurion {
	class StringValueIndexComparator : public rocksdb::Comparator {

	public:
		virtual int Compare(const rocksdb::Slice& a, const rocksdb::Slice& b) const override {
			const IndexId idxA = GetIndexId(a.data());
			const IndexId idxB = GetIndexId(b.data());
			if (idxA < idxB) return -1;
			if (idxA > idxB) return +1;
			const StringSizeType strSizeA = GetStringSize(a.data());
			const StringSizeType strSizeB = GetStringSize(b.data());
			const auto minStrSize = std::min(strSizeA, strSizeB);
			const int cmpResult = memcmp(
				a.data() + StringBufferOffset,
				b.data() + StringBufferOffset,
				minStrSize);
			if (cmpResult != 0)
			{
				return cmpResult;
			}
			if (strSizeA != strSizeB)
			{
				if (strSizeA < strSizeB) return -1;
				if (strSizeA > strSizeB) return +1;
			}
			const DocumentId docA = *(DocumentId*)(a.data() + StringBufferOffset + strSizeA);
			const DocumentId docB = *(DocumentId*)(b.data() + StringBufferOffset + strSizeB);
			if (docA < docB) return -1;
			if (docA > docB) return +1;
			return 0;
		}

		virtual const char* Name() const override { return "StringValueIndexComparator"; }
		virtual void FindShortestSeparator(std::string*, const rocksdb::Slice&) const override { }
		virtual void FindShortSuccessor(std::string*) const override { }
	};

}
