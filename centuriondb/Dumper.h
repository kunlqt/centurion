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
		const DocumentId docA = *(DocumentId*)(a.data() + StringBufferOffset + strSizeA);
		std::cout << "Index Id: " << (DocumentId)idxA << *" String: " << std::string(data, strSizeA) << " Document Id: " << docA << std::endl;
	}
}
