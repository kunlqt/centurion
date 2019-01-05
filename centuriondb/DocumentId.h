#pragma once
#include "CityHash.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <sstream>

namespace centurion {
	using DocumentId = std::uint64_t;
	static const DocumentId InvalidDocumentId = 0;
	/*
	inline std::ostream& operator<<(std::ostream& strm, const DocumentId docId)
	{
		DocumentId docIdPrint = docId;
		for (size_t idx = 0; idx < sizeof docId; idx++)
		{
			strm << std::setfill('0') << std::setw(2) << std::hex << (int)(docIdPrint & 0xff);
			docIdPrint >>= 8;
		}
		return strm;
	}
	*/

	struct DocumentIdHasher {
		size_t operator()(const DocumentId& docId) const {
			return CityHash64(reinterpret_cast<const char*>(&docId), sizeof docId);
		}
	};

	struct DocumentIdComparator {
		bool operator()(const DocumentId& docId1, const DocumentId& docId2) const {
			return docId1 == docId2;
		}
	};

}
