#include <CentSqlBaseVisitor.h>
#include <CentSqlLexer.h>
#include <CentSqlParser.h>
#include <CaseInsensitiveStream.h>
#include <AstBuilder.h>
#include <ParsingOptions.h>
#include <antlr4-runtime.h>
#include <atn/ParserATNSimulator.h>
#include "SearchIteratorBuilder.h"
#include "DefaultVisitorResult.h"
#include <spdlog/logger.h>
#include "AstNodes.h"
#include "DefaultVisitor.h"

namespace centurion {
	class QueryErrorErrorStrategy : public antlr4::DefaultErrorStrategy {
		void reportInputMismatch(antlr4::Parser *recognizer, const antlr4::InputMismatchException &e) override {
			std::string msg = "mismatched input " + getTokenErrorDisplay(e.getOffendingToken()) +
				" expecting " + e.getExpectedTokens().toString(recognizer->getVocabulary());
			recognizer->notifyErrorListeners(e.getOffendingToken(), msg, std::make_exception_ptr(e));
		}		
	};

	class QueryErrorListener : public antlr4::DiagnosticErrorListener {
		void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
			size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override {			
			logger_->error("Error, line: {}", line);
			errors.push_back({ line, charPositionInLine, msg });
		}

		void reportAttemptingFullContext(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex,
			size_t stopIndex, const antlrcpp::BitSet &/*conflictingAlts*/, antlr4::atn::ATNConfigSet * /*configs*/) override {
		}

		void reportContextSensitivity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex,
			size_t stopIndex, size_t /*prediction*/, antlr4::atn::ATNConfigSet * /*configs*/) override {
		}

		std::shared_ptr<spdlog::logger> logger_;

	public:		
		QueryErrorListener() : logger_(spdlog::get("root")) {

		}
		std::vector<std::tuple<size_t, size_t, std::string>> errors;
	};

	std::shared_ptr<DefaultVisitorResult> SearchIteratorBuilder::buildQuery(std::istream& query)
	{
		auto console = spdlog::get("root");
		console->trace("Starting SQL parser...");
		antlr4::CaseInsensitiveStream input(query);
		CentSqlLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);		
		const ParsingOptions options(ParsingOptions::AS_DECIMAL);
		try {
			CentSqlParser parser(&tokens);
			parser.setErrorHandler(std::make_shared<antlr4::BailErrorStrategy>());
			parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::SLL);
			AstBuilder astBuilder(options);
			console->trace("Visiting single sql statement");
			antlr4::ParserRuleContext* tree = parser.singleStatement();
 			std::shared_ptr<Statement> statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
			DefaultVisitor visitor;
			auto parserContext = std::make_shared<DefaultVisitorResult>();
			visitor.process(statement.get(), parserContext.get());
			console->trace("Parsing done, returning results");
			return parserContext;
		} catch (const antlr4::ParseCancellationException& exc) {
			console->error("SQL parse error: {}", exc.what());
			tokens.reset();
			input.reset();
			query.seekg(0);
			CentSqlParser parser(&tokens);
			parser.setErrorHandler(std::make_shared<QueryErrorErrorStrategy>());
			auto errorListener = std::make_shared<QueryErrorListener>();
			parser.addErrorListener(errorListener.get());
			parser.getInterpreter<antlr4::atn::ParserATNSimulator>()->setPredictionMode(antlr4::atn::PredictionMode::LL);
			AstBuilder astBuilder(options);
			antlr4::ParserRuleContext* tree = parser.singleStatement();
			Statement* statement = astBuilder.visitSingleStatement(dynamic_cast<CentSqlParser::SingleStatementContext*>(tree));
			DefaultVisitor visitor;
			DefaultVisitorResult parserContext;
			visitor.process(statement, &parserContext);			
			std::stringstream errorMessage;
			for (const auto& [line, col, err ] : errorListener->errors) {
				errorMessage << "line: " << line << " column: " << col << " error: " << err;
			}
			throw std::runtime_error(errorMessage.str());
		}
	}
}


