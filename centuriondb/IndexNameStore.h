#pragma once
#include "IndexId.h"
#include <rocksdb/db.h>
#include <boost/filesystem/path.hpp>
#include <string>

namespace centurion {
	class IndexNameStore
	{
	public:
		IndexNameStore(const IndexNameStore&) = delete;
		IndexNameStore(IndexNameStore&&) = delete;

		IndexNameStore(boost::filesystem::path fileName, bool dropIfExist = false)
		:
			db_(nullptr), 
			maxIndexId_(0),
			fileName_(std::move(fileName)),
			dropIfExist_(dropIfExist)
		{
			rocksdb::Options opts;
			opts.create_if_missing = true;
			opts.manual_wal_flush = true;
			opts.enable_pipelined_write = true;
			opts.max_background_jobs = 8;
			opts.IncreaseParallelism();
			if (dropIfExist) rocksdb::DestroyDB(fileName_.string(), opts);
			rocksdb::Status s = rocksdb::DB::Open(opts, fileName_.string(), &db_);
			if (!s.ok())
			{
				throw std::runtime_error("an error occurred while opening db: " + fileName_.string());
			}
			restoreMaxIndexId();
		}

		virtual ~IndexNameStore()
		{
			storeMaxIndexId();
			db_->FlushWAL(true);
			db_->SyncWAL();
			db_->Close();
			delete db_;
			if (dropIfExist_) rocksdb::DestroyDB(fileName_.string(), rocksdb::Options());
		}

		const IndexId getIndexId(const std::string& indexName) const
		{
			return getIndexId(indexName.c_str(), indexName.size());
		}

		const IndexId getIndexId(const char* indexName, size_t indexNameSize) const
		{
			std::string s;
			const rocksdb::Slice slice(indexName, indexNameSize);
			if (db_->Get(rocksdb::ReadOptions(), slice, &s).ok())
			{
				return *(reinterpret_cast<const IndexId*>(s.data()));
			} 
			throw std::runtime_error("put indexName error");			
		}

		IndexId getIndexId(const std::string& indexName)
		{
			return getIndexId(indexName.c_str(), indexName.size());
		}

		IndexId getIndexId(const char* indexName, size_t indexNameSize)
		{
			std::string s;
			const rocksdb::Slice slice(indexName, indexNameSize);
			if (db_->Get(rocksdb::ReadOptions(), slice, &s).ok())
			{
				return *(reinterpret_cast<const IndexId*>(s.data()));
			}
			++maxIndexId_;
			IndexId tmp = maxIndexId_;
			if (!db_->Put(rocksdb::WriteOptions(), slice, rocksdb::Slice(reinterpret_cast<const char*>(&tmp), sizeof tmp)).ok())
			{
				throw std::runtime_error("put indexName error");
			}
			return tmp;
		}

	private:
		void storeMaxIndexId() const
		{
			IndexId tmp = maxIndexId_;
			if (!db_->Put(rocksdb::WriteOptions(), "__last_index_id__", rocksdb::Slice(reinterpret_cast<const char*>(&tmp), sizeof tmp)).ok())
			{
				throw std::runtime_error("put __last_index_id__ error");
			}
		}

		void restoreMaxIndexId()
		{
			std::string s;
			if (db_->Get(rocksdb::ReadOptions(), "__last_index_id__", &s).ok())
			{
				maxIndexId_ = *(reinterpret_cast<const IndexId*>(s.data()));
			} else {
				maxIndexId_ = 0;
			}
		}
		rocksdb::DB* db_;
		std::atomic<IndexId> maxIndexId_;
		boost::filesystem::path fileName_;
		bool dropIfExist_;
	};
}
