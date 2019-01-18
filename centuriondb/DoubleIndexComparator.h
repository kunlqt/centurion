#pragma once
#include "Utils.h"
#include "IndexId.h"
#include "DocumentId.h"
#include <rocksdb/comparator.h>

namespace centurion {
	class DoubleIndexComparator : public rocksdb::Comparator {

	public:
		virtual int Compare(const rocksdb::Slice& a, const rocksdb::Slice& b) const override {
			IndexId idxA = GetIndexId(a.data());
			IndexId idxB = GetIndexId(b.data());
			if (idxA < idxB) return -1;
			if (idxA > idxB) return +1;
			double valueA = *(double*)(a.data() + sizeof(idxA));
			double valueB = *(double*)(b.data() + sizeof(idxB));
			if (valueA < valueB) return -1;
			if (valueA > valueB) return +1;
			DocumentId docA = *(DocumentId*)(a.data() + sizeof idxA + sizeof valueA);
			DocumentId docB = *(DocumentId*)(b.data() + sizeof idxB + sizeof valueB);
			if (docA < docB) return -1;
			if (docA > docB) return +1;
			return 0;
		}

		virtual const char* Name() const override { return "DoubleIndexComparator"; }
		virtual void FindShortestSeparator(std::string*, const rocksdb::Slice&) const override { }
		virtual void FindShortSuccessor(std::string*) const override { }
	};
}
