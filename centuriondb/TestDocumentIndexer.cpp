#include "gtest/gtest.h"
#include "DocumentStore.h"
#include "StringValueIndexStore.h"
#include "IndexNameStore.h"
#include "DocumentIndexer.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <rapidjson/filereadstream.h>
#include <chrono>

#if 0
TEST(TestDocumentIndexer, TestInsertDocuments) {
	auto console = spdlog::get("root");

	centurion::IndexNameStore indexNameStore("instore", true);
	centurion::StringValueIndexStore isvs("ivstore", true);
	centurion::IndexedDoubleValuesStore idvs("ivstore", true);
	centurion::IndexedBooleanValuesStore ibvs("ivstore", true);
	centurion::DocumentStore documentStore("docstore", true);
	centurion::DocumentIndexer documentIndexer(documentStore, indexNameStore, isvs, idvs, ibvs);

	FILE* fp;
	console->trace("Loading sample file");
	fopen_s(&fp, "sample_data/jeopardy.json", "rb");
	if (fp != nullptr) {
		console->trace("Inserting data...");
		char readBuffer[65536];
		rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
		rapidjson::Document rootDoc;
		rootDoc.ParseStream(is);
		auto docs = rootDoc.GetArray();
		console->trace("Inserting: {} documents...", docs.Size());
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
		fclose(fp);		
		console->trace("Insertion done! Total elapsed time: {}s. Insertion speed: {} docs/sec", elapsed_seconds.count(),  speed);

	}
}
#endif
