#include <CentSqlBaseVisitor.h>
#include <CentSqlLexer.h>
#include <CentSqlParser.h>
#include <CaseInsensitiveStream.h>
#include <AstBuilder.h>
#include <ParsingOptions.h>
#include <antlr4-runtime.h>
#include <atn/ParserATNSimulator.h>

#include "SearchIteratorBuilder.h"
#include "QualifiedNameBuilderVisitor.h"

namespace centurion {
	
	QualifiedNameBuilder SearchIteratorBuilder::buildQuery(std::istream& query)
	{
		auto console = spdlog::get("root");
		console->trace("Starting SQL parser...");
		antlr4::CaseInsensitiveStream input(query);
		CentSqlLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		CentSqlParser parser(&tokens);
		// antlr4::ParserRuleContext* tree;
		const ParsingOptions options(ParsingOptions::AS_DECIMAL);
		try {
			parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());
			parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
			AstBuilder astBuilder(options);
			console->trace("Visiting single sql statement");
			antlr4::ParserRuleContext* tree = parser.singleStatement();
			Statement* statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
			QualifiedNameBuilderVisitor visitor;
			QualifiedNameBuilder parserContext;
			visitor.process(statement, &parserContext);
			console->trace("Parsing done, returning results");
			return parserContext;
		} catch (const antlr4::ParseCancellationException& exc) {
			console->error("SQL parse error: {}", exc.what());
			throw std::runtime_error(exc.what());
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


