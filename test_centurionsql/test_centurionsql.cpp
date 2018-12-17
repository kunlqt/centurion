#include <sstream>
#include <iostream>
#include <antlr4-runtime.h>
#include <atn/ParserATNSimulator.h>
#include "CentSqlBaseVisitor.h"
#include "CentSqlLexer.h"
#include "CentSqlParser.h"
#include "CaseInsensitiveStream.h"
#include "AstBuilder.h"
#include "ParsingOptions.h"
#include "DefaultTraversalVisitor.h"

using namespace std;



int main(int argc, const char * argv[]) {
	using namespace centurion;
	std::stringstream stream;
	stream << "SELeCT person FROM students WHERE person.student.name='vasko'";
	antlr4::CaseInsensitiveStream input(stream);
	CentSqlLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	CentSqlParser parser(&tokens);
	antlr4::ParserRuleContext* tree;
	const ParsingOptions options(ParsingOptions::AS_DECIMAL);
	try {
		parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());
		parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
		AstBuilder astBuilder(options);
		tree = parser.singleStatement();
		auto statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
		DefaultTraversalVisitor visitor;
		visitor.process(statement);

	} catch (const antlr4::ParseCancellationException& exc) {
		std::cout << exc.what() << std::endl;
		tokens.reset();
		parser.reset();
		parser.setErrorHandler(std::make_shared<antlr4::DefaultErrorStrategy>());
		parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);
		AstBuilder astBuilder(options);
		tree = parser.singleStatement();
		CentSqlBaseVisitor visitor;
		auto statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
	}
	return 0;
}
