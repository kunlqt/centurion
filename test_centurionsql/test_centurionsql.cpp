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
#include "QualifiedNameBuilderVisitor.h"

using namespace std;



int main(int argc, const char * argv[]) {
	auto rootLogger = spdlog::stdout_color_mt("root");
	rootLogger->set_level(spdlog::level::err);
	using namespace centurion;
	std::stringstream stream;
	stream << "SELeCT field1.subfield2.*, field3.subfield4, * FROM supercategory WHERE term1.subterm2='vasko' and term3.sub4.sub5.sub6=39 and field>34 or fieldx<50";
	//stream << "SELeCT field1.subfield2.subfield3";
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
		// std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser));
		//std::wcout << s << std::endl;
		auto statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
		QualifiedNameBuilderVisitor visitor;
		QualifiedNameBuilder builder;
		antlrcpp::Any result = visitor.process(statement, &builder);
		std::cout << result.isNull();
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
