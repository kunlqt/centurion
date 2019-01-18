#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "BooleanIndexComparator.h"
#include <rocksdb/db.h>
#include <string>
#include "IndexedValuesStore.h"

namespace centurion {
	class BooleanValueIndexStore : public IndexedValuesStore<BooleanIndexComparator>
	{
	public:
		BooleanValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(filename, dropIfExist)
		{
		}

		virtual ~BooleanValueIndexStore()
		{	
		}

		bool add(IndexId indexId, bool b, DocumentId documentId) const
		{
			rocksdb::WriteBatch w;
			std::uint8_t value = b ? 1 : 0;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&value, sizeof value),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			w.Put(rocksdb::SliceParts(slices, sizeof slices / sizeof slices[0]), rocksdb::SliceParts());
			return writeSlice(&w);
		}
	};
}
