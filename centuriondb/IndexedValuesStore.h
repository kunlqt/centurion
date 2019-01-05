#pragma once
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>
#include <boost/filesystem/path.hpp>

namespace centurion {
	class IndexedValuesStore
	{
	public:
		IndexedValuesStore(const IndexedValuesStore&) = delete;
		IndexedValuesStore(IndexedValuesStore&&) = delete;

		IndexedValuesStore(boost::filesystem::path filename, const rocksdb::Comparator* cmp, bool dropIfExist = false)
			:
			db_(nullptr),
			filename_(std::move(filename)),
			comparator_(cmp),
			dropIfExist_(dropIfExist)
		{
			log_ = spdlog::get("root")->clone("IndexedValuesStore");			
			opts_.create_if_missing = true;
			opts_.manual_wal_flush = true;
			opts_.enable_pipelined_write = true;
			opts_.max_background_jobs = 8;
			opts_.IncreaseParallelism();
			if (dropIfExist) {
				rocksdb::DestroyDB(filename_.string(), opts_);
			}
			opts_.comparator = cmp;			
			log_->trace("Opening db index value store: {}...", filename_.string());
			rocksdb::Status s1 = rocksdb::DB::Open(opts_, filename_.string(), &db_);
			if (s1.ok()) {
				log_->trace("Index value store opened!");
			} else {
				log_->error("An error occured while opening db index value store, error: {}", s1.ToString());
			}
		}

		virtual ~IndexedValuesStore() {
			log_->trace("Releasing index value store!");
			db_->FlushWAL(true);
			db_->SyncWAL();
			db_->Close();
			delete db_;
			if (dropIfExist_) {
				rocksdb::DestroyDB(filename_.string(), rocksdb::Options());
			}
		}

		rocksdb::Iterator* newIterator(rocksdb::ReadOptions& opts) const
		{
			return db_->NewIterator(opts);
		}
		
	protected:			
		rocksdb::Options opts_;
		rocksdb::WriteOptions writeOptions_;
		rocksdb::SliceParts emptySliceParts_;
		rocksdb::DB* db_;
		boost::filesystem::path filename_;
		const rocksdb::Comparator* comparator_;
		bool dropIfExist_;

	private:
		std::shared_ptr<spdlog::logger> log_;
	};
}
