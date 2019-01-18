#pragma once
#include "IndexId.h"
#include "DocumentId.h"
#include "DoubleIndexComparator.h"
#include "IndexedValuesStore.h"
#include <rocksdb/write_batch.h>
#include <rocksdb/slice.h>
#include <string>

namespace centurion {
	class DoubleValueIndexStore : public IndexedValuesStore<DoubleIndexComparator>
	{
	public:
		DoubleValueIndexStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			IndexedValuesStore(filename, dropIfExist)
		{
			//dump();
		}

		virtual ~DoubleValueIndexStore()
		{
		}

		bool add(IndexId indexId, double value, DocumentId documentId) const
		{
			rocksdb::WriteBatch w;
			rocksdb::Slice slices[] = {
				rocksdb::Slice((const char*)&indexId, sizeof indexId),
				rocksdb::Slice((const char*)&value, sizeof value),
				rocksdb::Slice((const char*)&documentId, sizeof documentId) };
			w.Put(rocksdb::SliceParts(slices, sizeof slices / sizeof slices[0]), rocksdb::SliceParts());
			return writeSlice(&w);
		}

		/*
		void dump()
		{
			rocksdb::Iterator* iterator = db_->NewIterator(rocksdb::ReadOptions());
			iterator->SeekToFirst();
			while (iterator->Valid())
			{
				DumpDoubleIndex(iterator->key());
				iterator->Next();
			}
			delete iterator;
		}
		*/
	};
}
