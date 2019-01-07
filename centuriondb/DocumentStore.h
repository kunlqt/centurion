#pragma once
#include "DocumentId.h"
#include <string>
#include <rocksdb/db.h>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <boost/filesystem/path.hpp>
#include <mutex>

namespace centurion {
	inline const char* lastDocumentIdKey = "__last_document_id__";

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
			rocksdb::Options opts;
			opts.create_if_missing = true;
			opts.manual_wal_flush = true;
			opts.enable_pipelined_write = true;
			opts.max_background_jobs = 8;
			opts.IncreaseParallelism();
			if (dropIfExist) rocksdb::DestroyDB(filename_.string(), opts);
			rocksdb::Status s = rocksdb::DB::Open(opts, filename_.string(), &db_);
			if (!s.ok())
			{
				throw std::runtime_error("db error: " + s.ToString());
			}
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
					rocksdb::Slice((char*)&documentId, sizeof(documentId)),
					rocksdb::Slice(buffer.GetString(), buffer.GetSize()));
				if (putResult.ok())
				{
					return documentId;
				}
				throw std::runtime_error(putResult.ToString());
			}
			throw std::runtime_error("Empty document");			
		}

		rapidjson::Value findDocument(DocumentId documentId, rapidjson::Document::AllocatorType& allocator) const
		{
			std::string documentPayload;
			auto getResult = db_->Get(
				rocksdb::ReadOptions(),
				rocksdb::Slice((char*)&documentId, sizeof(documentId)),
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
				if (!db_->Put(rocksdb::WriteOptions(), lastDocumentIdKey, rocksdb::Slice(reinterpret_cast<const char*>(&tmp), sizeof tmp)).ok())
				{
					throw std::runtime_error("put __last_index_id__ error");
				}
			}
		}

		void restoreMaxIndexId()
		{
			std::lock_guard<std::mutex> guard(mutex_);
			std::string s;
			if (db_->Get(rocksdb::ReadOptions(), lastDocumentIdKey, &s).ok())
			{
				maxDocumentId_ = *(reinterpret_cast<const DocumentId*>(s.data()));
			} else {
				maxDocumentId_ = 0;
			}
		}

		rocksdb::DB* db_;
		std::atomic<DocumentId> maxDocumentId_;
		boost::filesystem::path filename_;
		bool dropIfExist_;
		std::mutex mutex_;
	};
}
