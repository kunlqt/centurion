#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include <rocksdb/db.h>

namespace centurion {
	class BooleanIndexComparator : public rocksdb::Comparator {

	public:
		virtual int Compare(const rocksdb::Slice& a, const rocksdb::Slice& b) const override {
			IndexId idxA = GetIndexId(a.data());
			IndexId idxB = GetIndexId(b.data());
			if (idxA < idxB) return -1;
			if (idxA > idxB) return +1;
			std::uint8_t valueA = *(std::uint8_t*)(a.data() + sizeof idxA);
			std::uint8_t valueB = *(std::uint8_t*)(b.data() + sizeof idxB);
			if (valueA < valueB) return -1;
			if (valueA > valueB) return +1;
			DocumentId docA = *(DocumentId*)(a.data() + sizeof idxA + sizeof valueA);
			DocumentId docB = *(DocumentId*)(b.data() + sizeof idxB + sizeof valueB);
			if (docA < docB) return -1;
			if (docA > docB) return +1;
			return 0;
		}

		virtual const char* Name() const override { return "BooleanIndexComparator"; }
		virtual void FindShortestSeparator(std::string*, const rocksdb::Slice&) const override { }
		virtual void FindShortSuccessor(std::string*) const override { }
	};
}
