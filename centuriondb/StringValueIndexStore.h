#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "StringValueIndexComparator.h"
#include "IndexedValuesStore.h"
#include <rocksdb/write_batch.h>
#include <rocksdb/slice.h>
#include <string>

namespace centurion {
	class StringValueIndexStore : public IndexedValuesStore<StringValueIndexComparator>
	{
	public:
		StringValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(
				filename, 
				dropIfExist)
		{
		}

		virtual ~StringValueIndexStore()
		{
			
		}

		bool add(IndexId indexId, const std::string& str, DocumentId documentId) const
		{
			return add(indexId, str.data(), str.size(), documentId);
		}

		bool add(IndexId indexId, const char* str, StringSizeType strSize, DocumentId documentId) const
		{
			rocksdb::WriteBatch w;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&strSize, sizeof strSize),
				rocksdb::Slice(str, strSize),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			w.Put(rocksdb::SliceParts(slices, 4), rocksdb::SliceParts());
			return writeSlice(&w);
		}		
	};
}
