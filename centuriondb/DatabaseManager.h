#pragma once

#include "DocumentIndexer.h"
#include "SearchIterator.h"
#include "MergeIterator.h"
#include "IndexNameStore.h"
#include "DocumentStore.h"
#include "StringValueIndexStore.h"
#include "StringValueSearchIterator.h"
#include "DoubleValueSearchIterator.h"
#include "DoubleValueIndexStore.h"
#include "BooleanValueIndexStore.h"
#include "BooleanValueSearchIterator.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rocksdb/db.h>
#include <boost/filesystem/path.hpp>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

namespace centurion
{
	static const char* insDirName = "instore";
	static const char* isvDirName = "isvstore";
	static const char* idvDirName = "idvstore";
	static const char* ibvDirName = "ibvstore";
	static const char* iasDirName = "isavistore";
	static const char* docDirName = "docstore";

	class DatabaseManager
	{

	public:
		DatabaseManager(boost::filesystem::path databaseRootDir)
		: 
			databaseRootDir_(std::move(databaseRootDir)),
			documentStore_(databaseRootDir_ / docDirName),
			indexNameStore_(databaseRootDir_ / insDirName),
			isvs_(databaseRootDir_ / isvDirName),
			idvs_(databaseRootDir_ / idvDirName),
			ibvs_(databaseRootDir_ / ibvDirName),
			savs_(databaseRootDir_ / iasDirName)
		{}
		
		size_t execQuery(rapidjson::StringStream& query, rapidjson::Value& results, rapidjson::Document::AllocatorType& allocator)
		{
			auto searchIterators = buildSearchIterators(query);
			return searchDocuments(searchIterators, results, allocator);
		}

		size_t insertDocuments(rapidjson::StringStream& is)
		{
			centurion::DocumentIndexer documentIndexer(documentStore_, indexNameStore_, isvs_, idvs_, ibvs_, savs_);

			bool dropDatabase = false;
			auto console = spdlog::get("console");

			console->trace("Loading json file...");
			const size_t readBufferSize = 16535 * 1024;
			const auto readBuffer = new char[readBufferSize];
			rapidjson::Document rootDoc;
			console->trace("Parsing json file...");
			rootDoc.ParseStream(is);
			if (rootDoc.HasParseError())
			{
				throw std::runtime_error("an error occured while parsing JSON document");
			}
			if (rootDoc.IsObject())
			{
				documentIndexer.indexDocument(rootDoc);
				return 1;
			}
			if (!rootDoc.IsArray())
			{
				throw std::runtime_error("Only json object or json array are supported as root object");
			}
			//auto docs = rootDoc["rows"].GetArray();
			auto docs = rootDoc.GetArray();
			console->trace("Parsing done!");
			console->trace("Inserting {} documents...", docs.Size());
			const auto start = std::chrono::system_clock::now();
			size_t cnt = 0;
			for (const auto& doc : docs)
			{
				documentIndexer.indexDocument(doc);
				cnt++;
				if ((cnt % 1000) == 0)
				{
					std::cout << ".";
				}
			}
			std::cout << std::endl;
			const auto end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			const auto speed = docs.Size() / elapsed_seconds.count();
			console->trace("Insertion done! Total elapsed time: {}s. Insertion speed: {} docs/sec", elapsed_seconds.count(), speed);
			delete[] readBuffer;
			return cnt;
		}

	private:
		std::vector<centurion::SearchIterator*> buildSearchIterators(rapidjson::StringStream& query)
		{
			std::vector<centurion::SearchIterator*> searchIterators;
			auto console = spdlog::get("console");
			rapidjson::Document doc;
			doc.ParseStream(query);
			if (doc.HasParseError())
			{
				throw std::runtime_error("json query parse error");
			}
			if (doc.IsArray())
			{
				for (const auto& searchTerm : doc.GetArray())
				{
					searchIterators.push_back(buildSearchIterator(searchTerm));
				}
			} else if (doc.IsObject())
			{
				searchIterators.push_back(buildSearchIterator(doc));
			} else {
				throw std::runtime_error("json query is not and object or array of search terms");
			}

			return searchIterators;
		}

		size_t searchDocuments(std::vector<centurion::SearchIterator*>& searchIterators, rapidjson::Value& results, rapidjson::Document::AllocatorType& allocator)
		{
			auto console = spdlog::get("console");
			centurion::MergeIterator m(searchIterators);
			size_t documentsFound = 0;
			rapidjson::Document doc;
			while (m.valid()) {
				const auto documentId = m.next();
				if (documentId == 0) {
					break;
				}
				documentsFound++;
				if (documentStore_.findDocument(documentId, doc)) {
#ifdef GetObject
#undef GetObject
#endif			
					results.PushBack(doc.GetObject(), allocator);
				} else {
					throw std::runtime_error("Document not found in the document store");
				}
			}
			return documentsFound;
		}


		centurion::SearchIterator* buildSearchIterator(const rapidjson::Value& searchTerm)
		{
			if (!searchTerm.IsObject())
			{
				throw std::runtime_error("json query array of search terms element is not an object");
			}
			if (!searchTerm.HasMember("path"))
			{
				throw std::runtime_error("missing query field: 'path'");
			}
			if (!searchTerm.HasMember("op"))
			{
				throw std::runtime_error("missing query field: 'op'");
			}
			if (!searchTerm.HasMember("value"))
			{
				throw std::runtime_error("missing query field: 'value'");
			}

			std::string field = searchTerm["path"].GetString();
			const auto indexId = indexNameStore_.getIndexId(field);
			std::string op = searchTerm["op"].GetString();
			const auto& val = searchTerm["value"];
			if (val.IsString())
			{
				return(centurion::StringValueSearchIterator::eq(isvs_, indexId, val.GetString()));
			} else if (val.IsNumber())
			{
				if (op == "eq") {
					return(centurion::DoubleValueSearchIterator::eq(idvs_, indexId, val.GetDouble()));
				}
			} else if (val.IsBool()) {
				if (op == "eq") {
					return(centurion::BooleanValueSearchIterator::eq(ibvs_, indexId, val.GetBool()));
				}
			}
			throw std::runtime_error("error");
		}


		boost::filesystem::path databaseRootDir_;
		centurion::DocumentStore documentStore_;
		centurion::IndexNameStore indexNameStore_;
		centurion::StringValueIndexStore isvs_;
		centurion::DoubleValueIndexStore idvs_;
		centurion::BooleanValueIndexStore ibvs_;
		centurion::StringArrayValueIndexStore savs_;

	};
}
