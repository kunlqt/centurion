#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "StringValueIndexComparator.h"
#include "IndexedValuesStore.h"
#include "Dumper.h"
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>
#include <string>

namespace centurion {
	class StringValueIndexStore : public IndexedValuesStore
	{
	public:
		StringValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(
				filename, 
				new centurion::StringValueIndexComparator(), 
				dropIfExist)
		{
		}

		virtual ~StringValueIndexStore()
		{
			delete comparator_;
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
			w.Put(rocksdb::SliceParts(slices, 4), emptySliceParts_);
			auto status = db_->Write(writeOptions_, &w);
			if (!status.ok())
			{
				auto console = spdlog::get("root");
				console->error("Error indexing string value. Error: {}", status.ToString());
				return false;
			}
			return true;
		}
		/*
		
		*/
	};
}
