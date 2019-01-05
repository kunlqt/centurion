#pragma once
#include "DocumentId.h"
#include "IndexId.h"
#include "Utils.h"
#include <rocksdb/slice.h>

namespace centurion {
	inline void DumpStringIndex(const rocksdb::Slice& a)
	{
		const centurion::IndexId idxA = GetIndexId(a.data());
		const StringSizeType strSizeA = GetStringSize(a.data());
		const char* data = a.data() + StringBufferOffset;
		const DocumentId docA = ExtractDocumentIdFromString(a.data());
		std::cout << "Index Id: " << idxA << *" String: " << std::string(data, strSizeA) << " Document Id: " << docA << std::endl;
	}

	inline void DumpDoubleIndex(const rocksdb::Slice& a)
	{
		const centurion::IndexId idxA = GetIndexId(a.data());
		const double d = ExtractDouble(a.data());
		const DocumentId docA = ExtractDocumentIdFromDouble(a.data());
		std::cout << "Index Id: " << idxA << *" Double: " << d << " Document Id: " << docA << std::endl;
	}

}
