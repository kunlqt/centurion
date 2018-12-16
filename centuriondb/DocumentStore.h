#pragma once
#include "DocumentId.h"
#include <string>
#include <rocksdb/db.h>
#include <random>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <boost/filesystem/path.hpp>

namespace centurion {
	class DocumentStore
	{
	public:
		DocumentStore(const DocumentStore&) = delete;
		DocumentStore(DocumentStore&&) = delete;

		DocumentStore(boost::filesystem::path filename, bool dropIfExist = false)
			:
			db_(nullptr),
			mte_(rd_()),
			filename_(std::move(filename)),
			dropIfExist_(dropIfExist)
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
		}

		virtual ~DocumentStore()
		{
			db_->FlushWAL(true);
			db_->SyncWAL();
			db_->Close();
			delete db_;
			if (dropIfExist_) rocksdb::DestroyDB(filename_.string(), rocksdb::Options());
		}

		DocumentId storeDocument(const rapidjson::Value& doc)
		{
			DocumentId documentId = dis_(mte_);
			rapidjson::StringBuffer buffer;
			rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
			doc.Accept(writer);
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

		bool findDocument(DocumentId documentId, rapidjson::Document& doc)
		{
			std::string documentPayload;
			auto putResult = db_->Get(
				rocksdb::ReadOptions(),
				rocksdb::Slice((char*)&documentId, sizeof(documentId)),
				&documentPayload);
			if (putResult.ok()) {
				doc.Parse(documentPayload.c_str(), documentPayload.size());
				return !doc.HasParseError();
			}
			return false;
		}

	private:
		
		rocksdb::DB* db_;
		std::random_device rd_;
		std::mt19937 mte_;
		std::uniform_int_distribution<DocumentId> dis_;
		boost::filesystem::path filename_;
		bool dropIfExist_;
	};
}
