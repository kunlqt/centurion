#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "StringArrayValueIndexComparator.h"
#include "IndexedValuesStore.h"
#include <rocksdb/write_batch.h>
#include <rocksdb/slice.h>
#include <string>

namespace centurion {
	class StringArrayValueIndexStore : public IndexedValuesStore<StringArrayValueIndexComparator>
	{
	public:
		StringArrayValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(filename, dropIfExist)
		{
		}

		virtual ~StringArrayValueIndexStore()
		{
		}

		bool add(IndexId indexId, std::uint32_t arrayElementIndex, const std::string& str, DocumentId documentId, bool removeFromIndex) const
		{
			return add(indexId, arrayElementIndex, str.data(), str.size(), documentId, removeFromIndex);
		}

		bool add(IndexId indexId, std::uint32_t arrayElementIndex, const char* str, StringSizeType strSize, DocumentId documentId, bool removeFromIndex) const
		{
			rocksdb::WriteBatch w;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&strSize, sizeof strSize),
				rocksdb::Slice(str, strSize),
				rocksdb::Slice((const char*)&arrayElementIndex, sizeof arrayElementIndex),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			if (removeFromIndex)
			{
				w.Delete(rocksdb::SliceParts(slices, 5));
			} else {
				w.Put(rocksdb::SliceParts(slices, 5), rocksdb::SliceParts());
			}
			return writeSlice(&w);
		}
		
	};
}
