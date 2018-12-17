#include <CentSqlBaseVisitor.h>
#include <CentSqlLexer.h>
#include <CentSqlParser.h>
#include <CaseInsensitiveStream.h>
#include <AstBuilder.h>
#include <ParsingOptions.h>
#include <antlr4-runtime.h>
#include <atn/ParserATNSimulator.h>

#include "SearchIteratorBuilder.h"
#include "SearchIterator.h"
#include "DefaultTraversalVisitor.h"


namespace centurion {
	
	SearchIterator* SearchIteratorBuilder::buildQuery(DatabaseManager& dbm, std::istream& query)
	{
		auto console = spdlog::get("console");
		console->trace("Starting SQL parser...");
		antlr4::CaseInsensitiveStream input(query);
		CentSqlLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		CentSqlParser parser(&tokens);
		antlr4::ParserRuleContext* tree;
		const ParsingOptions options(ParsingOptions::AS_DECIMAL);
		try {
			parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());
			parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
			AstBuilder astBuilder(options);
			console->trace("Visiting single sql statetment");
			tree = parser.singleStatement();
			auto statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
			DefaultTraversalVisitor visitor(dbm);
			auto result = visitor.process(statement);
			console->trace("Parsing done, returning results");
			return result;
		} catch (const antlr4::ParseCancellationException& exc) {
			std::cout << exc.what() << std::endl;
			throw;
			/*
			tokens.reset();
			parser.reset();
			parser.setErrorHandler(std::make_shared<antlr4::DefaultErrorStrategy>());
			parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);
			AstBuilder astBuilder(options);
			tree = parser.singleStatement();
			CentSqlBaseVisitor visitor;
			auto statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
			*/
		}
	}
}


