#pragma once
#include <cstdint>

namespace centurion {
	using IndexId = std::uint64_t;
	static const IndexId InvalidIndexId = 0;
	/*inline std::ostream& operator<<(std::ostream& strm, IndexId indexId)
	{
		IndexId idxIdPrint = indexId;
		for (size_t idx = 0; idx < sizeof(indexId); idx++)
		{
			strm << std::setfill('0') << std::setw(2) << std::hex << (int)(idxIdPrint & 0xff);
			idxIdPrint >>= 8;
		}
		return strm;
	}*/

}
