#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "StringArrayValueIndexComparator.h"
#include "IndexedValuesStore.h"
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>
#include <string>

namespace centurion {
	class StringArrayValueIndexStore : public IndexedValuesStore
	{
	public:
		StringArrayValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(filename, new StringArrayValueIndexComparator(), dropIfExist)
		{
		}

		virtual ~StringArrayValueIndexStore()
		{
			delete comparator_;
		}

		bool add(IndexId indexId, std::uint32_t arrayElementIndex, const std::string& str, DocumentId documentId) const
		{
			return add(indexId, arrayElementIndex, str.data(), str.size(), documentId);
		}

		bool add(IndexId indexId, std::uint32_t arrayElementIndex, const char* str, StringSizeType strSize, DocumentId documentId) const
		{
			rocksdb::WriteBatch w;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&strSize, sizeof strSize),
				rocksdb::Slice(str, strSize),
				rocksdb::Slice((const char*)&arrayElementIndex, sizeof arrayElementIndex),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			w.Put(rocksdb::SliceParts(slices, 5), emptySliceParts_);
			auto status = db_->Write(writeOptions_, &w);
			if (!status.ok())
			{
				auto console = spdlog::get("console");
				console->error("Error indexing array string element value. Error: {}", status.ToString());
				return false;
			}
			return true;
		}
		
	};
}
