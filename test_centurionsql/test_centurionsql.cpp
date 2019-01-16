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
#include <QualifiedNameBuilderVisitor.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

using namespace std;



int main(int argc, const char * argv[]) {
	auto rootLogger = spdlog::stdout_color_mt("root");
	rootLogger->set_level(spdlog::level::trace);
	using namespace centurion;
	std::stringstream stream;
	stream << "SELeCT field1.subfield2.*, field3.subfield4 as xxx, *";
	stream << " FROM supercategory as fld LEFT JOIN blabla as t ON (fld.x=5) ";
	stream << "WHERE ";
	stream << "term1.subterm2='vas'+'ko' and term3.sub4.sub5.sub6=(((3+9)/2)*7)-4 and ";
	stream << "field>3.1-4 or fieldx<50 and z>1.34 and field in ('a','b') ";
	stream << " group by x, y ";
	stream << " order by a asc, b desc ";

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
		std::wstring s = antlrcpp::s2ws(tree->toStringTree(&parser));
		std::wcout << s << std::endl;
		Statement* statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
		QualifiedNameBuilderVisitor visitor;
		QualifiedNameBuilder builder;
		visitor.process(statement, &builder);
		std::cout << builder.toString() << std::endl;
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
