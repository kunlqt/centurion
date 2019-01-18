#pragma once
#include <rocksdb/db.h>
#include <spdlog/spdlog.h>
#include <boost/filesystem/path.hpp>

namespace centurion {
	template<typename Comp>
	class IndexedValuesStore
	{
	public:
		IndexedValuesStore(const IndexedValuesStore&) = delete;
		IndexedValuesStore(IndexedValuesStore&&) = delete;

		IndexedValuesStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			db_(nullptr),
			filename_(std::move(filename)),
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
			opts_.comparator = new Comp();
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
			delete opts_.comparator;
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
		bool writeSlice(rocksdb::WriteBatch* w) const
		{
			auto status = db_->Write(rocksdb::WriteOptions(), w);
			if (!status.ok()) {
				auto console = spdlog::get("root");
				console->error("Error indexing value. Error: {}", status.ToString());
				return false;
			}
			return true;
		}

	private:
		rocksdb::DB* db_;
		rocksdb::Options opts_;
		boost::filesystem::path filename_;
		bool dropIfExist_;
		std::shared_ptr<spdlog::logger> log_;
	};
}
