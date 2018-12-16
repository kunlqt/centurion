#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "DoubleIndexComparator.h"
#include "IndexedValuesStore.h"
#include <rocksdb/db.h>
#include <string>

namespace centurion {
	class DoubleValueIndexStore : public IndexedValuesStore
	{
	public:
		DoubleValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(filename, new DoubleIndexComparator(), dropIfExist)
		{
		}

		virtual ~DoubleValueIndexStore()
		{
			delete comparator_;
		}

		bool add(IndexId indexId, double value, DocumentId documentId) const
		{
			rocksdb::WriteBatch w;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&value, sizeof value),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			w.Put(rocksdb::SliceParts(slices, sizeof slices / sizeof slices[0]), rocksdb::SliceParts());
			auto status = db_->Write(rocksdb::WriteOptions(), &w);
			if (!status.ok())
			{
				auto console = spdlog::get("console");
				console->error("Error indexing double value. Error: {}", status.ToString());
				return false;
			}
			return true;
		}

	};
}
