#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "BooleanIndexComparator.h"
#include <rocksdb/db.h>
#include <string>
#include "IndexedValuesStore.h"

namespace centurion {
	class BooleanValueIndexStore : public IndexedValuesStore
	{
	public:
		BooleanValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(filename, new BooleanIndexComparator(), dropIfExist)
		{
		}

		virtual ~BooleanValueIndexStore()
		{
			delete comparator_;
		}

		bool add(IndexId indexId, bool b, DocumentId documentId) const
		{
			rocksdb::WriteBatch w;
			std::uint8_t value = b ? 1 : 0;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&value, sizeof value),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			w.Put(rocksdb::SliceParts(slices, sizeof slices / sizeof slices[0]), emptySliceParts_);
			auto status = db_->Write(writeOptions_, &w);
			if (!status.ok())
			{
				auto console = spdlog::get("console");
				console->error("Error indexing string value. Error: {}", status.ToString());
				return false;
			}
			return true;

		}
	};
}
