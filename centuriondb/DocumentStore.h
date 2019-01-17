#pragma once
#include "DocumentId.h"
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <rocksdb/db.h>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <boost/filesystem/path.hpp>
#include <mutex>
#include <string>

namespace centurion {
	inline const char* lastDocumentIdKey = "__last_document_id__";
	inline const char* isDirtyKey = "__is_dirty__";

	class DocumentStore
	{
	public:
		DocumentStore(const DocumentStore&) = delete;
		DocumentStore(DocumentStore&&) = delete;

		DocumentStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			db_(nullptr),
			filename_(std::move(filename)),
			dropIfExist_(dropIfExist),
			maxDocumentId_(0)
		{
			logger_ = spdlog::get("root")->clone("document_store");
			rocksdb::Options opts;
			opts.create_if_missing = true;
			opts.manual_wal_flush = true;
			opts.enable_pipelined_write = true;
			opts.max_background_jobs = 8;
			opts.IncreaseParallelism();
			if (dropIfExist) rocksdb::DestroyDB(filename_.string(), opts);
			logger_->trace("Opening db: {}...", filename_);
			rocksdb::Status s = rocksdb::DB::Open(opts, filename_.string(), &db_);
			if (!s.ok())
			{
				logger_->critical("Failed opening db: {}", filename_);
				throw std::runtime_error("db error: " + s.ToString());
			}
			logger_->trace("Opened db: {}!", filename_);
			restoreMaxIndexId();
		}

		virtual ~DocumentStore()
		{
			storeMaxIndexId();
			db_->FlushWAL(true);
			db_->SyncWAL();
			db_->Close();
			delete db_;
			if (dropIfExist_) rocksdb::DestroyDB(filename_.string(), rocksdb::Options());
		}

		DocumentId storeDocument(const rapidjson::Value& doc)
		{
			DocumentId documentId = ++maxDocumentId_;
			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			if (doc.Accept(writer)) {
				auto putResult = db_->Put(
					rocksdb::WriteOptions(),
					rocksdb::Slice(reinterpret_cast<char*>(&documentId), sizeof(documentId)),
					rocksdb::Slice(buffer.GetString(), buffer.GetSize()));
				if (putResult.ok())
				{
					return documentId;
				}
				throw std::runtime_error(putResult.ToString());
			}
			throw std::runtime_error("Empty document");			
		}

		rapidjson::Value loadDocument(DocumentId documentId, rapidjson::Document::AllocatorType& allocator) const
		{
			std::string documentPayload;
			auto getResult = db_->Get(
				rocksdb::ReadOptions(),
				rocksdb::Slice(reinterpret_cast<char*>(&documentId), sizeof(documentId)),
				&documentPayload);
			if (getResult.ok()) {
				rapidjson::Document doc;
				doc.Parse(documentPayload.c_str(), documentPayload.size());
				return rapidjson::Value(doc, allocator);
			}
			return rapidjson::Value(rapidjson::kNullType);
		}

	private:
		void storeMaxIndexId()
		{
			std::lock_guard<std::mutex> guard(mutex_);
			std::string s;
			DocumentId currentDocId = 0;
			if (db_->Get(rocksdb::ReadOptions(), lastDocumentIdKey, &s).ok())
			{
				currentDocId = *(reinterpret_cast<const DocumentId*>(s.data()));
			}
			DocumentId tmp = maxDocumentId_;
			if (currentDocId < tmp) {
				if (!db_->Put(rocksdb::WriteOptions(), 
					lastDocumentIdKey, 
					rocksdb::Slice(reinterpret_cast<const char*>(&tmp), sizeof tmp)).ok())
				{
					throw std::runtime_error("put __last_index_id__ error");
				}
			}
			if (checkIsDirty()) {
				logger_->trace("Marking DB as clean");
				cleanDirty();
			} else {
				logger_->critical("DB is not dirty");
				throw std::runtime_error("DB Not dirty");
			}
		}

		void restoreMaxIndexId()
		{
			std::lock_guard<std::mutex> guard(mutex_);
			logger_->trace("Restoring MaxIndexId...");
			if (checkIsDirty())
			{
				logger_->warn("Last DB Shutdown was not clean, will perform full scan to recover MaxIndexId...");
				// scan all keys
				auto iterator = db_->NewIterator(rocksdb::ReadOptions());
				iterator->SeekToFirst();
				DocumentId currDocumentId = 0;
				while (iterator->Valid())
				{
					currDocumentId++;
					iterator->Next();
				}
				delete iterator;
				maxDocumentId_ = currDocumentId;
				logger_->warn("MaxIndexId recovered using full scan. MaxIndexId: {}", currDocumentId);
			} 
			else
			{
				logger_->trace("Last DB shutdown was clean, reading MaxIndexId from key...");
				std::string s;
				if (db_->Get(rocksdb::ReadOptions(), lastDocumentIdKey, &s).ok())
				{
					maxDocumentId_ = *(reinterpret_cast<const DocumentId*>(s.data()));
					logger_->trace("God MaxIndexId from DB: {}", maxDocumentId_);
				} else {
					maxDocumentId_ = 0;
					logger_->trace("MaxIndexId not found in DB, using default value of: 0");
				}				
				makeDirty();
			}			
		}

		bool checkIsDirty() const
		{
			logger_->trace("Checking if previous DB Shutdown was clean...");
			std::string val;
			rocksdb::Status s = db_->Get(rocksdb::ReadOptions(), isDirtyKey, &val);
			if (s.IsNotFound()) {
				logger_->trace("No clean shutdown key found, assuming this is first run, do a full scan");
				return true;
			}
			if (!s.ok()) {
				logger_->critical("An error occurred while reading clean db shutdown key");
				throw std::runtime_error("get __is_dirty__ error");
			}
			return (val == "Y");
		}

		void makeDirty() const
		{
			logger_->trace("Marking DB as not clean...");
			if (!db_->Put(rocksdb::WriteOptions(), isDirtyKey, "Y").ok())
			{				
				throw std::runtime_error("put __is_dirty__ error");
			}
			logger_->trace("Done marking DB as not clean!");
		}

		void cleanDirty() const
		{
			logger_->trace("Resetting DB clean flag...");
			if (!db_->Put(rocksdb::WriteOptions(), isDirtyKey, "N").ok())
			{				
				throw std::runtime_error("put __is_dirty__ error");
			}
			logger_->trace("Done resetting DB clean flag...");
		}

		rocksdb::DB* db_;
		std::atomic<DocumentId> maxDocumentId_;
		boost::filesystem::path filename_;
		bool dropIfExist_;
		std::mutex mutex_;
		std::shared_ptr<spdlog::logger> logger_;
	};
}
