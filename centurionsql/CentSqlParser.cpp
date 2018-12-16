
// Generated from /Users/vasko/IdeaProjects/untitled/src/CentSql.g4 by ANTLR 4.7


#include "CentSqlListener.h"
#include "CentSqlVisitor.h"

#include "CentSqlParser.h"


using namespace antlrcpp;
using namespace centurion;
using namespace antlr4;

CentSqlParser::CentSqlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CentSqlParser::~CentSqlParser() {
  delete _interpreter;
}

std::string CentSqlParser::getGrammarFileName() const {
  return "CentSql.g4";
}

const std::vector<std::string>& CentSqlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CentSqlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SingleStatementContext ------------------------------------------------------------------

CentSqlParser::SingleStatementContext::SingleStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::StatementContext* CentSqlParser::SingleStatementContext::statement() {
  return getRuleContext<CentSqlParser::StatementContext>(0);
}

tree::TerminalNode* CentSqlParser::SingleStatementContext::EOF() {
  return getToken(CentSqlParser::EOF, 0);
}


size_t CentSqlParser::SingleStatementContext::getRuleIndex() const {
  return CentSqlParser::RuleSingleStatement;
}

void CentSqlParser::SingleStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleStatement(this);
}

void CentSqlParser::SingleStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleStatement(this);
}


antlrcpp::Any CentSqlParser::SingleStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSingleStatement(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::SingleStatementContext* CentSqlParser::singleStatement() {
  SingleStatementContext *_localctx = _tracker.createInstance<SingleStatementContext>(_ctx, getState());
  enterRule(_localctx, 0, CentSqlParser::RuleSingleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    statement();
    setState(125);
    match(CentSqlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StandaloneExpressionContext ------------------------------------------------------------------

CentSqlParser::StandaloneExpressionContext::StandaloneExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::ExpressionContext* CentSqlParser::StandaloneExpressionContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::StandaloneExpressionContext::EOF() {
  return getToken(CentSqlParser::EOF, 0);
}


size_t CentSqlParser::StandaloneExpressionContext::getRuleIndex() const {
  return CentSqlParser::RuleStandaloneExpression;
}

void CentSqlParser::StandaloneExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStandaloneExpression(this);
}

void CentSqlParser::StandaloneExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStandaloneExpression(this);
}


antlrcpp::Any CentSqlParser::StandaloneExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitStandaloneExpression(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::StandaloneExpressionContext* CentSqlParser::standaloneExpression() {
  StandaloneExpressionContext *_localctx = _tracker.createInstance<StandaloneExpressionContext>(_ctx, getState());
  enterRule(_localctx, 2, CentSqlParser::RuleStandaloneExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    expression();
    setState(128);
    match(CentSqlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StandalonePathSpecificationContext ------------------------------------------------------------------

CentSqlParser::StandalonePathSpecificationContext::StandalonePathSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::PathSpecificationContext* CentSqlParser::StandalonePathSpecificationContext::pathSpecification() {
  return getRuleContext<CentSqlParser::PathSpecificationContext>(0);
}

tree::TerminalNode* CentSqlParser::StandalonePathSpecificationContext::EOF() {
  return getToken(CentSqlParser::EOF, 0);
}


size_t CentSqlParser::StandalonePathSpecificationContext::getRuleIndex() const {
  return CentSqlParser::RuleStandalonePathSpecification;
}

void CentSqlParser::StandalonePathSpecificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStandalonePathSpecification(this);
}

void CentSqlParser::StandalonePathSpecificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStandalonePathSpecification(this);
}


antlrcpp::Any CentSqlParser::StandalonePathSpecificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitStandalonePathSpecification(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::StandalonePathSpecificationContext* CentSqlParser::standalonePathSpecification() {
  StandalonePathSpecificationContext *_localctx = _tracker.createInstance<StandalonePathSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 4, CentSqlParser::RuleStandalonePathSpecification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    pathSpecification();
    setState(131);
    match(CentSqlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CentSqlParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::StatementContext::getRuleIndex() const {
  return CentSqlParser::RuleStatement;
}

void CentSqlParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExplainContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ExplainContext::EXPLAIN() {
  return getToken(CentSqlParser::EXPLAIN, 0);
}

CentSqlParser::StatementContext* CentSqlParser::ExplainContext::statement() {
  return getRuleContext<CentSqlParser::StatementContext>(0);
}

tree::TerminalNode* CentSqlParser::ExplainContext::ANALYZE() {
  return getToken(CentSqlParser::ANALYZE, 0);
}

tree::TerminalNode* CentSqlParser::ExplainContext::VERBOSE() {
  return getToken(CentSqlParser::VERBOSE, 0);
}

std::vector<CentSqlParser::ExplainOptionContext *> CentSqlParser::ExplainContext::explainOption() {
  return getRuleContexts<CentSqlParser::ExplainOptionContext>();
}

CentSqlParser::ExplainOptionContext* CentSqlParser::ExplainContext::explainOption(size_t i) {
  return getRuleContext<CentSqlParser::ExplainOptionContext>(i);
}

CentSqlParser::ExplainContext::ExplainContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ExplainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplain(this);
}
void CentSqlParser::ExplainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplain(this);
}

antlrcpp::Any CentSqlParser::ExplainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExplain(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrepareContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::PrepareContext::PREPARE() {
  return getToken(CentSqlParser::PREPARE, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::PrepareContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::PrepareContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

CentSqlParser::StatementContext* CentSqlParser::PrepareContext::statement() {
  return getRuleContext<CentSqlParser::StatementContext>(0);
}

CentSqlParser::PrepareContext::PrepareContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::PrepareContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrepare(this);
}
void CentSqlParser::PrepareContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrepare(this);
}

antlrcpp::Any CentSqlParser::PrepareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitPrepare(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreateTableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CreateTableContext::CREATE() {
  return getToken(CentSqlParser::CREATE, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::CreateTableContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

std::vector<CentSqlParser::TableElementContext *> CentSqlParser::CreateTableContext::tableElement() {
  return getRuleContexts<CentSqlParser::TableElementContext>();
}

CentSqlParser::TableElementContext* CentSqlParser::CreateTableContext::tableElement(size_t i) {
  return getRuleContext<CentSqlParser::TableElementContext>(i);
}

tree::TerminalNode* CentSqlParser::CreateTableContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableContext::COMMENT() {
  return getToken(CentSqlParser::COMMENT, 0);
}

CentSqlParser::StringContext* CentSqlParser::CreateTableContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateTableContext::WITH() {
  return getToken(CentSqlParser::WITH, 0);
}

CentSqlParser::PropertiesContext* CentSqlParser::CreateTableContext::properties() {
  return getRuleContext<CentSqlParser::PropertiesContext>(0);
}

CentSqlParser::CreateTableContext::CreateTableContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CreateTableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateTable(this);
}
void CentSqlParser::CreateTableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateTable(this);
}

antlrcpp::Any CentSqlParser::CreateTableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCreateTable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StartTransactionContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::StartTransactionContext::START() {
  return getToken(CentSqlParser::START, 0);
}

tree::TerminalNode* CentSqlParser::StartTransactionContext::TRANSACTION() {
  return getToken(CentSqlParser::TRANSACTION, 0);
}

std::vector<CentSqlParser::TransactionModeContext *> CentSqlParser::StartTransactionContext::transactionMode() {
  return getRuleContexts<CentSqlParser::TransactionModeContext>();
}

CentSqlParser::TransactionModeContext* CentSqlParser::StartTransactionContext::transactionMode(size_t i) {
  return getRuleContext<CentSqlParser::TransactionModeContext>(i);
}

CentSqlParser::StartTransactionContext::StartTransactionContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::StartTransactionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStartTransaction(this);
}
void CentSqlParser::StartTransactionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStartTransaction(this);
}

antlrcpp::Any CentSqlParser::StartTransactionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitStartTransaction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreateTableAsSelectContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::CREATE() {
  return getToken(CentSqlParser::CREATE, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::CreateTableAsSelectContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::AS() {
  return getToken(CentSqlParser::AS, 0);
}

CentSqlParser::QueryContext* CentSqlParser::CreateTableAsSelectContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

CentSqlParser::ColumnAliasesContext* CentSqlParser::CreateTableAsSelectContext::columnAliases() {
  return getRuleContext<CentSqlParser::ColumnAliasesContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::COMMENT() {
  return getToken(CentSqlParser::COMMENT, 0);
}

CentSqlParser::StringContext* CentSqlParser::CreateTableAsSelectContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

std::vector<tree::TerminalNode *> CentSqlParser::CreateTableAsSelectContext::WITH() {
  return getTokens(CentSqlParser::WITH);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::WITH(size_t i) {
  return getToken(CentSqlParser::WITH, i);
}

CentSqlParser::PropertiesContext* CentSqlParser::CreateTableAsSelectContext::properties() {
  return getRuleContext<CentSqlParser::PropertiesContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::DATA() {
  return getToken(CentSqlParser::DATA, 0);
}

tree::TerminalNode* CentSqlParser::CreateTableAsSelectContext::NO() {
  return getToken(CentSqlParser::NO, 0);
}

CentSqlParser::CreateTableAsSelectContext::CreateTableAsSelectContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CreateTableAsSelectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateTableAsSelect(this);
}
void CentSqlParser::CreateTableAsSelectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateTableAsSelect(this);
}

antlrcpp::Any CentSqlParser::CreateTableAsSelectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCreateTableAsSelect(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UseContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::UseContext::USE() {
  return getToken(CentSqlParser::USE, 0);
}

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::UseContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::UseContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}

CentSqlParser::UseContext::UseContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::UseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUse(this);
}
void CentSqlParser::UseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUse(this);
}

antlrcpp::Any CentSqlParser::UseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitUse(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowStatsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowStatsContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowStatsContext::STATS() {
  return getToken(CentSqlParser::STATS, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ShowStatsContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::ShowStatsContext::FOR() {
  return getToken(CentSqlParser::FOR, 0);
}

tree::TerminalNode* CentSqlParser::ShowStatsContext::ON() {
  return getToken(CentSqlParser::ON, 0);
}

CentSqlParser::ShowStatsContext::ShowStatsContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowStatsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowStats(this);
}
void CentSqlParser::ShowStatsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowStats(this);
}

antlrcpp::Any CentSqlParser::ShowStatsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowStats(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeallocateContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DeallocateContext::DEALLOCATE() {
  return getToken(CentSqlParser::DEALLOCATE, 0);
}

tree::TerminalNode* CentSqlParser::DeallocateContext::PREPARE() {
  return getToken(CentSqlParser::PREPARE, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::DeallocateContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::DeallocateContext::DeallocateContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DeallocateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeallocate(this);
}
void CentSqlParser::DeallocateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeallocate(this);
}

antlrcpp::Any CentSqlParser::DeallocateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDeallocate(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RenameTableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RenameTableContext::ALTER() {
  return getToken(CentSqlParser::ALTER, 0);
}

tree::TerminalNode* CentSqlParser::RenameTableContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

tree::TerminalNode* CentSqlParser::RenameTableContext::RENAME() {
  return getToken(CentSqlParser::RENAME, 0);
}

tree::TerminalNode* CentSqlParser::RenameTableContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

std::vector<CentSqlParser::QualifiedNameContext *> CentSqlParser::RenameTableContext::qualifiedName() {
  return getRuleContexts<CentSqlParser::QualifiedNameContext>();
}

CentSqlParser::QualifiedNameContext* CentSqlParser::RenameTableContext::qualifiedName(size_t i) {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(i);
}

CentSqlParser::RenameTableContext::RenameTableContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RenameTableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenameTable(this);
}
void CentSqlParser::RenameTableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenameTable(this);
}

antlrcpp::Any CentSqlParser::RenameTableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRenameTable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CommitContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CommitContext::COMMIT() {
  return getToken(CentSqlParser::COMMIT, 0);
}

tree::TerminalNode* CentSqlParser::CommitContext::WORK() {
  return getToken(CentSqlParser::WORK, 0);
}

CentSqlParser::CommitContext::CommitContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CommitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommit(this);
}
void CentSqlParser::CommitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommit(this);
}

antlrcpp::Any CentSqlParser::CommitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCommit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RevokeContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RevokeContext::REVOKE() {
  return getToken(CentSqlParser::REVOKE, 0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::ON() {
  return getToken(CentSqlParser::ON, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::RevokeContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::RevokeContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

std::vector<CentSqlParser::PrivilegeContext *> CentSqlParser::RevokeContext::privilege() {
  return getRuleContexts<CentSqlParser::PrivilegeContext>();
}

CentSqlParser::PrivilegeContext* CentSqlParser::RevokeContext::privilege(size_t i) {
  return getRuleContext<CentSqlParser::PrivilegeContext>(i);
}

tree::TerminalNode* CentSqlParser::RevokeContext::ALL() {
  return getToken(CentSqlParser::ALL, 0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::PRIVILEGES() {
  return getToken(CentSqlParser::PRIVILEGES, 0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::GRANT() {
  return getToken(CentSqlParser::GRANT, 0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::OPTION() {
  return getToken(CentSqlParser::OPTION, 0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::FOR() {
  return getToken(CentSqlParser::FOR, 0);
}

tree::TerminalNode* CentSqlParser::RevokeContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::RevokeContext::RevokeContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RevokeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRevoke(this);
}
void CentSqlParser::RevokeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRevoke(this);
}

antlrcpp::Any CentSqlParser::RevokeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRevoke(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DropColumnContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DropColumnContext::ALTER() {
  return getToken(CentSqlParser::ALTER, 0);
}

tree::TerminalNode* CentSqlParser::DropColumnContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

tree::TerminalNode* CentSqlParser::DropColumnContext::DROP() {
  return getToken(CentSqlParser::DROP, 0);
}

tree::TerminalNode* CentSqlParser::DropColumnContext::COLUMN() {
  return getToken(CentSqlParser::COLUMN, 0);
}

std::vector<CentSqlParser::QualifiedNameContext *> CentSqlParser::DropColumnContext::qualifiedName() {
  return getRuleContexts<CentSqlParser::QualifiedNameContext>();
}

CentSqlParser::QualifiedNameContext* CentSqlParser::DropColumnContext::qualifiedName(size_t i) {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(i);
}

CentSqlParser::DropColumnContext::DropColumnContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DropColumnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropColumn(this);
}
void CentSqlParser::DropColumnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropColumn(this);
}

antlrcpp::Any CentSqlParser::DropColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDropColumn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DropViewContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DropViewContext::DROP() {
  return getToken(CentSqlParser::DROP, 0);
}

tree::TerminalNode* CentSqlParser::DropViewContext::VIEW() {
  return getToken(CentSqlParser::VIEW, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::DropViewContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::DropViewContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::DropViewContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

CentSqlParser::DropViewContext::DropViewContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DropViewContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropView(this);
}
void CentSqlParser::DropViewContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropView(this);
}

antlrcpp::Any CentSqlParser::DropViewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDropView(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeleteContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DeleteContext::DELETE() {
  return getToken(CentSqlParser::DELETE, 0);
}

tree::TerminalNode* CentSqlParser::DeleteContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::DeleteContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::DeleteContext::WHERE() {
  return getToken(CentSqlParser::WHERE, 0);
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::DeleteContext::booleanExpression() {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(0);
}

CentSqlParser::DeleteContext::DeleteContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DeleteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete(this);
}
void CentSqlParser::DeleteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete(this);
}

antlrcpp::Any CentSqlParser::DeleteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDelete(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowTablesContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowTablesContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowTablesContext::TABLES() {
  return getToken(CentSqlParser::TABLES, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ShowTablesContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::ShowTablesContext::LIKE() {
  return getToken(CentSqlParser::LIKE, 0);
}

tree::TerminalNode* CentSqlParser::ShowTablesContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

tree::TerminalNode* CentSqlParser::ShowTablesContext::IN() {
  return getToken(CentSqlParser::IN, 0);
}

std::vector<CentSqlParser::StringContext *> CentSqlParser::ShowTablesContext::string() {
  return getRuleContexts<CentSqlParser::StringContext>();
}

CentSqlParser::StringContext* CentSqlParser::ShowTablesContext::string(size_t i) {
  return getRuleContext<CentSqlParser::StringContext>(i);
}

tree::TerminalNode* CentSqlParser::ShowTablesContext::ESCAPE() {
  return getToken(CentSqlParser::ESCAPE, 0);
}

CentSqlParser::ShowTablesContext::ShowTablesContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowTablesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowTables(this);
}
void CentSqlParser::ShowTablesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowTables(this);
}

antlrcpp::Any CentSqlParser::ShowTablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowTables(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DescribeInputContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DescribeInputContext::DESCRIBE() {
  return getToken(CentSqlParser::DESCRIBE, 0);
}

tree::TerminalNode* CentSqlParser::DescribeInputContext::INPUT() {
  return getToken(CentSqlParser::INPUT, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::DescribeInputContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::DescribeInputContext::DescribeInputContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DescribeInputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescribeInput(this);
}
void CentSqlParser::DescribeInputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescribeInput(this);
}

antlrcpp::Any CentSqlParser::DescribeInputContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDescribeInput(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowStatsForQueryContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowStatsForQueryContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowStatsForQueryContext::STATS() {
  return getToken(CentSqlParser::STATS, 0);
}

tree::TerminalNode* CentSqlParser::ShowStatsForQueryContext::FOR() {
  return getToken(CentSqlParser::FOR, 0);
}

CentSqlParser::QuerySpecificationContext* CentSqlParser::ShowStatsForQueryContext::querySpecification() {
  return getRuleContext<CentSqlParser::QuerySpecificationContext>(0);
}

CentSqlParser::ShowStatsForQueryContext::ShowStatsForQueryContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowStatsForQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowStatsForQuery(this);
}
void CentSqlParser::ShowStatsForQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowStatsForQuery(this);
}

antlrcpp::Any CentSqlParser::ShowStatsForQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowStatsForQuery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowCatalogsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowCatalogsContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowCatalogsContext::CATALOGS() {
  return getToken(CentSqlParser::CATALOGS, 0);
}

tree::TerminalNode* CentSqlParser::ShowCatalogsContext::LIKE() {
  return getToken(CentSqlParser::LIKE, 0);
}

CentSqlParser::StringContext* CentSqlParser::ShowCatalogsContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

CentSqlParser::ShowCatalogsContext::ShowCatalogsContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowCatalogsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowCatalogs(this);
}
void CentSqlParser::ShowCatalogsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowCatalogs(this);
}

antlrcpp::Any CentSqlParser::ShowCatalogsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowCatalogs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StatementDefaultContext ------------------------------------------------------------------

CentSqlParser::QueryContext* CentSqlParser::StatementDefaultContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::StatementDefaultContext::StatementDefaultContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::StatementDefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementDefault(this);
}
void CentSqlParser::StatementDefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementDefault(this);
}

antlrcpp::Any CentSqlParser::StatementDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitStatementDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RenameColumnContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RenameColumnContext::ALTER() {
  return getToken(CentSqlParser::ALTER, 0);
}

tree::TerminalNode* CentSqlParser::RenameColumnContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

tree::TerminalNode* CentSqlParser::RenameColumnContext::RENAME() {
  return getToken(CentSqlParser::RENAME, 0);
}

tree::TerminalNode* CentSqlParser::RenameColumnContext::COLUMN() {
  return getToken(CentSqlParser::COLUMN, 0);
}

tree::TerminalNode* CentSqlParser::RenameColumnContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::RenameColumnContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::RenameColumnContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::RenameColumnContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}

CentSqlParser::RenameColumnContext::RenameColumnContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RenameColumnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenameColumn(this);
}
void CentSqlParser::RenameColumnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenameColumn(this);
}

antlrcpp::Any CentSqlParser::RenameColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRenameColumn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SetSessionContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SetSessionContext::SET() {
  return getToken(CentSqlParser::SET, 0);
}

tree::TerminalNode* CentSqlParser::SetSessionContext::SESSION() {
  return getToken(CentSqlParser::SESSION, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::SetSessionContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::SetSessionContext::EQ() {
  return getToken(CentSqlParser::EQ, 0);
}

CentSqlParser::ExpressionContext* CentSqlParser::SetSessionContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::SetSessionContext::SetSessionContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SetSessionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetSession(this);
}
void CentSqlParser::SetSessionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetSession(this);
}

antlrcpp::Any CentSqlParser::SetSessionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSetSession(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreateViewContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CreateViewContext::CREATE() {
  return getToken(CentSqlParser::CREATE, 0);
}

tree::TerminalNode* CentSqlParser::CreateViewContext::VIEW() {
  return getToken(CentSqlParser::VIEW, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::CreateViewContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateViewContext::AS() {
  return getToken(CentSqlParser::AS, 0);
}

CentSqlParser::QueryContext* CentSqlParser::CreateViewContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateViewContext::OR() {
  return getToken(CentSqlParser::OR, 0);
}

tree::TerminalNode* CentSqlParser::CreateViewContext::REPLACE() {
  return getToken(CentSqlParser::REPLACE, 0);
}

CentSqlParser::CreateViewContext::CreateViewContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CreateViewContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateView(this);
}
void CentSqlParser::CreateViewContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateView(this);
}

antlrcpp::Any CentSqlParser::CreateViewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCreateView(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowCreateTableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowCreateTableContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowCreateTableContext::CREATE() {
  return getToken(CentSqlParser::CREATE, 0);
}

tree::TerminalNode* CentSqlParser::ShowCreateTableContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ShowCreateTableContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::ShowCreateTableContext::ShowCreateTableContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowCreateTableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowCreateTable(this);
}
void CentSqlParser::ShowCreateTableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowCreateTable(this);
}

antlrcpp::Any CentSqlParser::ShowCreateTableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowCreateTable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowSchemasContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowSchemasContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowSchemasContext::SCHEMAS() {
  return getToken(CentSqlParser::SCHEMAS, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::ShowSchemasContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::ShowSchemasContext::LIKE() {
  return getToken(CentSqlParser::LIKE, 0);
}

tree::TerminalNode* CentSqlParser::ShowSchemasContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

tree::TerminalNode* CentSqlParser::ShowSchemasContext::IN() {
  return getToken(CentSqlParser::IN, 0);
}

std::vector<CentSqlParser::StringContext *> CentSqlParser::ShowSchemasContext::string() {
  return getRuleContexts<CentSqlParser::StringContext>();
}

CentSqlParser::StringContext* CentSqlParser::ShowSchemasContext::string(size_t i) {
  return getRuleContext<CentSqlParser::StringContext>(i);
}

tree::TerminalNode* CentSqlParser::ShowSchemasContext::ESCAPE() {
  return getToken(CentSqlParser::ESCAPE, 0);
}

CentSqlParser::ShowSchemasContext::ShowSchemasContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowSchemasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowSchemas(this);
}
void CentSqlParser::ShowSchemasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowSchemas(this);
}

antlrcpp::Any CentSqlParser::ShowSchemasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowSchemas(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DropTableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DropTableContext::DROP() {
  return getToken(CentSqlParser::DROP, 0);
}

tree::TerminalNode* CentSqlParser::DropTableContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::DropTableContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::DropTableContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::DropTableContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

CentSqlParser::DropTableContext::DropTableContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DropTableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropTable(this);
}
void CentSqlParser::DropTableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropTable(this);
}

antlrcpp::Any CentSqlParser::DropTableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDropTable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowColumnsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowColumnsContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowColumnsContext::COLUMNS() {
  return getToken(CentSqlParser::COLUMNS, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ShowColumnsContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::ShowColumnsContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

tree::TerminalNode* CentSqlParser::ShowColumnsContext::IN() {
  return getToken(CentSqlParser::IN, 0);
}

tree::TerminalNode* CentSqlParser::ShowColumnsContext::DESCRIBE() {
  return getToken(CentSqlParser::DESCRIBE, 0);
}

tree::TerminalNode* CentSqlParser::ShowColumnsContext::DESC() {
  return getToken(CentSqlParser::DESC, 0);
}

CentSqlParser::ShowColumnsContext::ShowColumnsContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowColumnsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowColumns(this);
}
void CentSqlParser::ShowColumnsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowColumns(this);
}

antlrcpp::Any CentSqlParser::ShowColumnsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowColumns(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RollbackContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RollbackContext::ROLLBACK() {
  return getToken(CentSqlParser::ROLLBACK, 0);
}

tree::TerminalNode* CentSqlParser::RollbackContext::WORK() {
  return getToken(CentSqlParser::WORK, 0);
}

CentSqlParser::RollbackContext::RollbackContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RollbackContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRollback(this);
}
void CentSqlParser::RollbackContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRollback(this);
}

antlrcpp::Any CentSqlParser::RollbackContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRollback(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddColumnContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::AddColumnContext::ALTER() {
  return getToken(CentSqlParser::ALTER, 0);
}

tree::TerminalNode* CentSqlParser::AddColumnContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

tree::TerminalNode* CentSqlParser::AddColumnContext::ADD() {
  return getToken(CentSqlParser::ADD, 0);
}

tree::TerminalNode* CentSqlParser::AddColumnContext::COLUMN() {
  return getToken(CentSqlParser::COLUMN, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::AddColumnContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::ColumnDefinitionContext* CentSqlParser::AddColumnContext::columnDefinition() {
  return getRuleContext<CentSqlParser::ColumnDefinitionContext>(0);
}

CentSqlParser::AddColumnContext::AddColumnContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::AddColumnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddColumn(this);
}
void CentSqlParser::AddColumnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddColumn(this);
}

antlrcpp::Any CentSqlParser::AddColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitAddColumn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ResetSessionContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ResetSessionContext::RESET() {
  return getToken(CentSqlParser::RESET, 0);
}

tree::TerminalNode* CentSqlParser::ResetSessionContext::SESSION() {
  return getToken(CentSqlParser::SESSION, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ResetSessionContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::ResetSessionContext::ResetSessionContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ResetSessionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResetSession(this);
}
void CentSqlParser::ResetSessionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResetSession(this);
}

antlrcpp::Any CentSqlParser::ResetSessionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitResetSession(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InsertIntoContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::InsertIntoContext::INSERT() {
  return getToken(CentSqlParser::INSERT, 0);
}

tree::TerminalNode* CentSqlParser::InsertIntoContext::INTO() {
  return getToken(CentSqlParser::INTO, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::InsertIntoContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::QueryContext* CentSqlParser::InsertIntoContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::ColumnAliasesContext* CentSqlParser::InsertIntoContext::columnAliases() {
  return getRuleContext<CentSqlParser::ColumnAliasesContext>(0);
}

CentSqlParser::InsertIntoContext::InsertIntoContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::InsertIntoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsertInto(this);
}
void CentSqlParser::InsertIntoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsertInto(this);
}

antlrcpp::Any CentSqlParser::InsertIntoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitInsertInto(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SetPathContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SetPathContext::SET() {
  return getToken(CentSqlParser::SET, 0);
}

tree::TerminalNode* CentSqlParser::SetPathContext::PATH() {
  return getToken(CentSqlParser::PATH, 0);
}

CentSqlParser::PathSpecificationContext* CentSqlParser::SetPathContext::pathSpecification() {
  return getRuleContext<CentSqlParser::PathSpecificationContext>(0);
}

CentSqlParser::SetPathContext::SetPathContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SetPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetPath(this);
}
void CentSqlParser::SetPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetPath(this);
}

antlrcpp::Any CentSqlParser::SetPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSetPath(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowSessionContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowSessionContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowSessionContext::SESSION() {
  return getToken(CentSqlParser::SESSION, 0);
}

CentSqlParser::ShowSessionContext::ShowSessionContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowSessionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowSession(this);
}
void CentSqlParser::ShowSessionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowSession(this);
}

antlrcpp::Any CentSqlParser::ShowSessionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowSession(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreateSchemaContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CreateSchemaContext::CREATE() {
  return getToken(CentSqlParser::CREATE, 0);
}

tree::TerminalNode* CentSqlParser::CreateSchemaContext::SCHEMA() {
  return getToken(CentSqlParser::SCHEMA, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::CreateSchemaContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::CreateSchemaContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::CreateSchemaContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

tree::TerminalNode* CentSqlParser::CreateSchemaContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

tree::TerminalNode* CentSqlParser::CreateSchemaContext::WITH() {
  return getToken(CentSqlParser::WITH, 0);
}

CentSqlParser::PropertiesContext* CentSqlParser::CreateSchemaContext::properties() {
  return getRuleContext<CentSqlParser::PropertiesContext>(0);
}

CentSqlParser::CreateSchemaContext::CreateSchemaContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CreateSchemaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateSchema(this);
}
void CentSqlParser::CreateSchemaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateSchema(this);
}

antlrcpp::Any CentSqlParser::CreateSchemaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCreateSchema(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExecuteContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ExecuteContext::EXECUTE() {
  return getToken(CentSqlParser::EXECUTE, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::ExecuteContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::ExecuteContext::USING() {
  return getToken(CentSqlParser::USING, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::ExecuteContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::ExecuteContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

CentSqlParser::ExecuteContext::ExecuteContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ExecuteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecute(this);
}
void CentSqlParser::ExecuteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecute(this);
}

antlrcpp::Any CentSqlParser::ExecuteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExecute(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CallContext::CALL() {
  return getToken(CentSqlParser::CALL, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::CallContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

std::vector<CentSqlParser::CallArgumentContext *> CentSqlParser::CallContext::callArgument() {
  return getRuleContexts<CentSqlParser::CallArgumentContext>();
}

CentSqlParser::CallArgumentContext* CentSqlParser::CallContext::callArgument(size_t i) {
  return getRuleContext<CentSqlParser::CallArgumentContext>(i);
}

CentSqlParser::CallContext::CallContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void CentSqlParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

antlrcpp::Any CentSqlParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RenameSchemaContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RenameSchemaContext::ALTER() {
  return getToken(CentSqlParser::ALTER, 0);
}

tree::TerminalNode* CentSqlParser::RenameSchemaContext::SCHEMA() {
  return getToken(CentSqlParser::SCHEMA, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::RenameSchemaContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::RenameSchemaContext::RENAME() {
  return getToken(CentSqlParser::RENAME, 0);
}

tree::TerminalNode* CentSqlParser::RenameSchemaContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::RenameSchemaContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::RenameSchemaContext::RenameSchemaContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RenameSchemaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRenameSchema(this);
}
void CentSqlParser::RenameSchemaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRenameSchema(this);
}

antlrcpp::Any CentSqlParser::RenameSchemaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRenameSchema(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowGrantsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowGrantsContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowGrantsContext::GRANTS() {
  return getToken(CentSqlParser::GRANTS, 0);
}

tree::TerminalNode* CentSqlParser::ShowGrantsContext::ON() {
  return getToken(CentSqlParser::ON, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ShowGrantsContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::ShowGrantsContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::ShowGrantsContext::ShowGrantsContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowGrantsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowGrants(this);
}
void CentSqlParser::ShowGrantsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowGrants(this);
}

antlrcpp::Any CentSqlParser::ShowGrantsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowGrants(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowFunctionsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowFunctionsContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowFunctionsContext::FUNCTIONS() {
  return getToken(CentSqlParser::FUNCTIONS, 0);
}

CentSqlParser::ShowFunctionsContext::ShowFunctionsContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowFunctionsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowFunctions(this);
}
void CentSqlParser::ShowFunctionsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowFunctions(this);
}

antlrcpp::Any CentSqlParser::ShowFunctionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowFunctions(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DescribeOutputContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DescribeOutputContext::DESCRIBE() {
  return getToken(CentSqlParser::DESCRIBE, 0);
}

tree::TerminalNode* CentSqlParser::DescribeOutputContext::OUTPUT() {
  return getToken(CentSqlParser::OUTPUT, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::DescribeOutputContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::DescribeOutputContext::DescribeOutputContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DescribeOutputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescribeOutput(this);
}
void CentSqlParser::DescribeOutputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescribeOutput(this);
}

antlrcpp::Any CentSqlParser::DescribeOutputContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDescribeOutput(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DropSchemaContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DropSchemaContext::DROP() {
  return getToken(CentSqlParser::DROP, 0);
}

tree::TerminalNode* CentSqlParser::DropSchemaContext::SCHEMA() {
  return getToken(CentSqlParser::SCHEMA, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::DropSchemaContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::DropSchemaContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::DropSchemaContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

tree::TerminalNode* CentSqlParser::DropSchemaContext::CASCADE() {
  return getToken(CentSqlParser::CASCADE, 0);
}

tree::TerminalNode* CentSqlParser::DropSchemaContext::RESTRICT() {
  return getToken(CentSqlParser::RESTRICT, 0);
}

CentSqlParser::DropSchemaContext::DropSchemaContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DropSchemaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDropSchema(this);
}
void CentSqlParser::DropSchemaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDropSchema(this);
}

antlrcpp::Any CentSqlParser::DropSchemaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDropSchema(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GrantContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> CentSqlParser::GrantContext::GRANT() {
  return getTokens(CentSqlParser::GRANT);
}

tree::TerminalNode* CentSqlParser::GrantContext::GRANT(size_t i) {
  return getToken(CentSqlParser::GRANT, i);
}

tree::TerminalNode* CentSqlParser::GrantContext::ON() {
  return getToken(CentSqlParser::ON, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::GrantContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::GrantContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::GrantContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

std::vector<CentSqlParser::PrivilegeContext *> CentSqlParser::GrantContext::privilege() {
  return getRuleContexts<CentSqlParser::PrivilegeContext>();
}

CentSqlParser::PrivilegeContext* CentSqlParser::GrantContext::privilege(size_t i) {
  return getRuleContext<CentSqlParser::PrivilegeContext>(i);
}

tree::TerminalNode* CentSqlParser::GrantContext::ALL() {
  return getToken(CentSqlParser::ALL, 0);
}

tree::TerminalNode* CentSqlParser::GrantContext::PRIVILEGES() {
  return getToken(CentSqlParser::PRIVILEGES, 0);
}

tree::TerminalNode* CentSqlParser::GrantContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

tree::TerminalNode* CentSqlParser::GrantContext::WITH() {
  return getToken(CentSqlParser::WITH, 0);
}

tree::TerminalNode* CentSqlParser::GrantContext::OPTION() {
  return getToken(CentSqlParser::OPTION, 0);
}

CentSqlParser::GrantContext::GrantContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::GrantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGrant(this);
}
void CentSqlParser::GrantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGrant(this);
}

antlrcpp::Any CentSqlParser::GrantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitGrant(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShowCreateViewContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ShowCreateViewContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::ShowCreateViewContext::CREATE() {
  return getToken(CentSqlParser::CREATE, 0);
}

tree::TerminalNode* CentSqlParser::ShowCreateViewContext::VIEW() {
  return getToken(CentSqlParser::VIEW, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::ShowCreateViewContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::ShowCreateViewContext::ShowCreateViewContext(StatementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ShowCreateViewContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShowCreateView(this);
}
void CentSqlParser::ShowCreateViewContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShowCreateView(this);
}

antlrcpp::Any CentSqlParser::ShowCreateViewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitShowCreateView(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::StatementContext* CentSqlParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, CentSqlParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(519);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::StatementDefaultContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(133);
      query();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::UseContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(134);
      match(CentSqlParser::USE);
      setState(135);
      dynamic_cast<UseContext *>(_localctx)->schema = identifier();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::UseContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(136);
      match(CentSqlParser::USE);
      setState(137);
      dynamic_cast<UseContext *>(_localctx)->catalog = identifier();
      setState(138);
      match(CentSqlParser::T__0);
      setState(139);
      dynamic_cast<UseContext *>(_localctx)->schema = identifier();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::CreateSchemaContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(141);
      match(CentSqlParser::CREATE);
      setState(142);
      match(CentSqlParser::SCHEMA);
      setState(146);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(143);
        match(CentSqlParser::IF);
        setState(144);
        match(CentSqlParser::NOT);
        setState(145);
        match(CentSqlParser::EXISTS);
        break;
      }

      }
      setState(148);
      qualifiedName();
      setState(151);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WITH) {
        setState(149);
        match(CentSqlParser::WITH);
        setState(150);
        properties();
      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DropSchemaContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(153);
      match(CentSqlParser::DROP);
      setState(154);
      match(CentSqlParser::SCHEMA);
      setState(157);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(155);
        match(CentSqlParser::IF);
        setState(156);
        match(CentSqlParser::EXISTS);
        break;
      }

      }
      setState(159);
      qualifiedName();
      setState(161);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::CASCADE || _la == CentSqlParser::RESTRICT) {
        setState(160);
        _la = _input->LA(1);
        if (!(_la == CentSqlParser::CASCADE || _la == CentSqlParser::RESTRICT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::RenameSchemaContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(163);
      match(CentSqlParser::ALTER);
      setState(164);
      match(CentSqlParser::SCHEMA);
      setState(165);
      qualifiedName();
      setState(166);
      match(CentSqlParser::RENAME);
      setState(167);
      match(CentSqlParser::TO);
      setState(168);
      identifier();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::CreateTableAsSelectContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(170);
      match(CentSqlParser::CREATE);
      setState(171);
      match(CentSqlParser::TABLE);
      setState(175);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(172);
        match(CentSqlParser::IF);
        setState(173);
        match(CentSqlParser::NOT);
        setState(174);
        match(CentSqlParser::EXISTS);
        break;
      }

      }
      setState(177);
      qualifiedName();
      setState(179);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::T__1) {
        setState(178);
        columnAliases();
      }
      setState(183);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::COMMENT) {
        setState(181);
        match(CentSqlParser::COMMENT);
        setState(182);
        string();
      }
      setState(187);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WITH) {
        setState(185);
        match(CentSqlParser::WITH);
        setState(186);
        properties();
      }
      setState(189);
      match(CentSqlParser::AS);
      setState(195);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(190);
        query();
        break;
      }

      case 2: {
        setState(191);
        match(CentSqlParser::T__1);
        setState(192);
        query();
        setState(193);
        match(CentSqlParser::T__2);
        break;
      }

      }
      setState(202);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WITH) {
        setState(197);
        match(CentSqlParser::WITH);
        setState(199);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::NO) {
          setState(198);
          match(CentSqlParser::NO);
        }
        setState(201);
        match(CentSqlParser::DATA);
      }
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::CreateTableContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(204);
      match(CentSqlParser::CREATE);
      setState(205);
      match(CentSqlParser::TABLE);
      setState(209);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(206);
        match(CentSqlParser::IF);
        setState(207);
        match(CentSqlParser::NOT);
        setState(208);
        match(CentSqlParser::EXISTS);
        break;
      }

      }
      setState(211);
      qualifiedName();
      setState(212);
      match(CentSqlParser::T__1);
      setState(213);
      tableElement();
      setState(218);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(214);
        match(CentSqlParser::T__3);
        setState(215);
        tableElement();
        setState(220);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(221);
      match(CentSqlParser::T__2);
      setState(224);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::COMMENT) {
        setState(222);
        match(CentSqlParser::COMMENT);
        setState(223);
        string();
      }
      setState(228);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WITH) {
        setState(226);
        match(CentSqlParser::WITH);
        setState(227);
        properties();
      }
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DropTableContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(230);
      match(CentSqlParser::DROP);
      setState(231);
      match(CentSqlParser::TABLE);
      setState(234);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
      case 1: {
        setState(232);
        match(CentSqlParser::IF);
        setState(233);
        match(CentSqlParser::EXISTS);
        break;
      }

      }
      setState(236);
      qualifiedName();
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::InsertIntoContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(237);
      match(CentSqlParser::INSERT);
      setState(238);
      match(CentSqlParser::INTO);
      setState(239);
      qualifiedName();
      setState(241);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(240);
        columnAliases();
        break;
      }

      }
      setState(243);
      query();
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DeleteContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(245);
      match(CentSqlParser::DELETE);
      setState(246);
      match(CentSqlParser::FROM);
      setState(247);
      qualifiedName();
      setState(250);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WHERE) {
        setState(248);
        match(CentSqlParser::WHERE);
        setState(249);
        booleanExpression(0);
      }
      break;
    }

    case 12: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::RenameTableContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(252);
      match(CentSqlParser::ALTER);
      setState(253);
      match(CentSqlParser::TABLE);
      setState(254);
      dynamic_cast<RenameTableContext *>(_localctx)->from = qualifiedName();
      setState(255);
      match(CentSqlParser::RENAME);
      setState(256);
      match(CentSqlParser::TO);
      setState(257);
      dynamic_cast<RenameTableContext *>(_localctx)->to = qualifiedName();
      break;
    }

    case 13: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::RenameColumnContext>(_localctx));
      enterOuterAlt(_localctx, 13);
      setState(259);
      match(CentSqlParser::ALTER);
      setState(260);
      match(CentSqlParser::TABLE);
      setState(261);
      dynamic_cast<RenameColumnContext *>(_localctx)->tableName = qualifiedName();
      setState(262);
      match(CentSqlParser::RENAME);
      setState(263);
      match(CentSqlParser::COLUMN);
      setState(264);
      dynamic_cast<RenameColumnContext *>(_localctx)->from = identifier();
      setState(265);
      match(CentSqlParser::TO);
      setState(266);
      dynamic_cast<RenameColumnContext *>(_localctx)->to = identifier();
      break;
    }

    case 14: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DropColumnContext>(_localctx));
      enterOuterAlt(_localctx, 14);
      setState(268);
      match(CentSqlParser::ALTER);
      setState(269);
      match(CentSqlParser::TABLE);
      setState(270);
      dynamic_cast<DropColumnContext *>(_localctx)->tableName = qualifiedName();
      setState(271);
      match(CentSqlParser::DROP);
      setState(272);
      match(CentSqlParser::COLUMN);
      setState(273);
      dynamic_cast<DropColumnContext *>(_localctx)->column = qualifiedName();
      break;
    }

    case 15: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::AddColumnContext>(_localctx));
      enterOuterAlt(_localctx, 15);
      setState(275);
      match(CentSqlParser::ALTER);
      setState(276);
      match(CentSqlParser::TABLE);
      setState(277);
      dynamic_cast<AddColumnContext *>(_localctx)->tableName = qualifiedName();
      setState(278);
      match(CentSqlParser::ADD);
      setState(279);
      match(CentSqlParser::COLUMN);
      setState(280);
      dynamic_cast<AddColumnContext *>(_localctx)->column = columnDefinition();
      break;
    }

    case 16: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::CreateViewContext>(_localctx));
      enterOuterAlt(_localctx, 16);
      setState(282);
      match(CentSqlParser::CREATE);
      setState(285);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::OR) {
        setState(283);
        match(CentSqlParser::OR);
        setState(284);
        match(CentSqlParser::REPLACE);
      }
      setState(287);
      match(CentSqlParser::VIEW);
      setState(288);
      qualifiedName();
      setState(289);
      match(CentSqlParser::AS);
      setState(290);
      query();
      break;
    }

    case 17: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DropViewContext>(_localctx));
      enterOuterAlt(_localctx, 17);
      setState(292);
      match(CentSqlParser::DROP);
      setState(293);
      match(CentSqlParser::VIEW);
      setState(296);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
      case 1: {
        setState(294);
        match(CentSqlParser::IF);
        setState(295);
        match(CentSqlParser::EXISTS);
        break;
      }

      }
      setState(298);
      qualifiedName();
      break;
    }

    case 18: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::CallContext>(_localctx));
      enterOuterAlt(_localctx, 18);
      setState(299);
      match(CentSqlParser::CALL);
      setState(300);
      qualifiedName();
      setState(301);
      match(CentSqlParser::T__1);
      setState(310);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::T__1)
        | (1ULL << CentSqlParser::T__4)
        | (1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CASE)
        | (1ULL << CentSqlParser::CAST)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::CURRENT_DATE)
        | (1ULL << CentSqlParser::CURRENT_PATH)
        | (1ULL << CentSqlParser::CURRENT_TIME)
        | (1ULL << CentSqlParser::CURRENT_TIMESTAMP)
        | (1ULL << CentSqlParser::CURRENT_USER)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXISTS)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::EXTRACT)
        | (1ULL << CentSqlParser::FALSE_VALUE)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::GROUPING - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOCALTIME - 64))
        | (1ULL << (CentSqlParser::LOCALTIMESTAMP - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NORMALIZE - 64))
        | (1ULL << (CentSqlParser::NOT - 64))
        | (1ULL << (CentSqlParser::NULL_VALUE - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRUE_VALUE - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 197) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 197)) & ((1ULL << (CentSqlParser::PLUS - 197))
        | (1ULL << (CentSqlParser::MINUS - 197))
        | (1ULL << (CentSqlParser::STRING - 197))
        | (1ULL << (CentSqlParser::UNICODE_STRING - 197))
        | (1ULL << (CentSqlParser::BINARY_LITERAL - 197))
        | (1ULL << (CentSqlParser::INTEGER_VALUE - 197))
        | (1ULL << (CentSqlParser::DECIMAL_VALUE - 197))
        | (1ULL << (CentSqlParser::DOUBLE_VALUE - 197))
        | (1ULL << (CentSqlParser::IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DOUBLE_PRECISION - 197)))) != 0)) {
        setState(302);
        callArgument();
        setState(307);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(303);
          match(CentSqlParser::T__3);
          setState(304);
          callArgument();
          setState(309);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(312);
      match(CentSqlParser::T__2);
      break;
    }

    case 19: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::GrantContext>(_localctx));
      enterOuterAlt(_localctx, 19);
      setState(314);
      match(CentSqlParser::GRANT);
      setState(325);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
      case 1: {
        setState(315);
        privilege();
        setState(320);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(316);
          match(CentSqlParser::T__3);
          setState(317);
          privilege();
          setState(322);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(323);
        match(CentSqlParser::ALL);
        setState(324);
        match(CentSqlParser::PRIVILEGES);
        break;
      }

      }
      setState(327);
      match(CentSqlParser::ON);
      setState(329);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::TABLE) {
        setState(328);
        match(CentSqlParser::TABLE);
      }
      setState(331);
      qualifiedName();
      setState(332);
      match(CentSqlParser::TO);
      setState(333);
      dynamic_cast<GrantContext *>(_localctx)->grantee = identifier();
      setState(337);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WITH) {
        setState(334);
        match(CentSqlParser::WITH);
        setState(335);
        match(CentSqlParser::GRANT);
        setState(336);
        match(CentSqlParser::OPTION);
      }
      break;
    }

    case 20: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::RevokeContext>(_localctx));
      enterOuterAlt(_localctx, 20);
      setState(339);
      match(CentSqlParser::REVOKE);
      setState(343);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
      case 1: {
        setState(340);
        match(CentSqlParser::GRANT);
        setState(341);
        match(CentSqlParser::OPTION);
        setState(342);
        match(CentSqlParser::FOR);
        break;
      }

      }
      setState(355);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
      case 1: {
        setState(345);
        privilege();
        setState(350);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(346);
          match(CentSqlParser::T__3);
          setState(347);
          privilege();
          setState(352);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(353);
        match(CentSqlParser::ALL);
        setState(354);
        match(CentSqlParser::PRIVILEGES);
        break;
      }

      }
      setState(357);
      match(CentSqlParser::ON);
      setState(359);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::TABLE) {
        setState(358);
        match(CentSqlParser::TABLE);
      }
      setState(361);
      qualifiedName();
      setState(362);
      match(CentSqlParser::FROM);
      setState(363);
      dynamic_cast<RevokeContext *>(_localctx)->grantee = identifier();
      break;
    }

    case 21: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowGrantsContext>(_localctx));
      enterOuterAlt(_localctx, 21);
      setState(365);
      match(CentSqlParser::SHOW);
      setState(366);
      match(CentSqlParser::GRANTS);
      setState(372);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::ON) {
        setState(367);
        match(CentSqlParser::ON);
        setState(369);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::TABLE) {
          setState(368);
          match(CentSqlParser::TABLE);
        }
        setState(371);
        qualifiedName();
      }
      break;
    }

    case 22: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ExplainContext>(_localctx));
      enterOuterAlt(_localctx, 22);
      setState(374);
      match(CentSqlParser::EXPLAIN);
      setState(376);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::ANALYZE) {
        setState(375);
        match(CentSqlParser::ANALYZE);
      }
      setState(379);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::VERBOSE) {
        setState(378);
        match(CentSqlParser::VERBOSE);
      }
      setState(392);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
      case 1: {
        setState(381);
        match(CentSqlParser::T__1);
        setState(382);
        explainOption();
        setState(387);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(383);
          match(CentSqlParser::T__3);
          setState(384);
          explainOption();
          setState(389);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(390);
        match(CentSqlParser::T__2);
        break;
      }

      }
      setState(394);
      statement();
      break;
    }

    case 23: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowCreateTableContext>(_localctx));
      enterOuterAlt(_localctx, 23);
      setState(395);
      match(CentSqlParser::SHOW);
      setState(396);
      match(CentSqlParser::CREATE);
      setState(397);
      match(CentSqlParser::TABLE);
      setState(398);
      qualifiedName();
      break;
    }

    case 24: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowCreateViewContext>(_localctx));
      enterOuterAlt(_localctx, 24);
      setState(399);
      match(CentSqlParser::SHOW);
      setState(400);
      match(CentSqlParser::CREATE);
      setState(401);
      match(CentSqlParser::VIEW);
      setState(402);
      qualifiedName();
      break;
    }

    case 25: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowTablesContext>(_localctx));
      enterOuterAlt(_localctx, 25);
      setState(403);
      match(CentSqlParser::SHOW);
      setState(404);
      match(CentSqlParser::TABLES);
      setState(407);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::FROM

      || _la == CentSqlParser::IN) {
        setState(405);
        _la = _input->LA(1);
        if (!(_la == CentSqlParser::FROM

        || _la == CentSqlParser::IN)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(406);
        qualifiedName();
      }
      setState(415);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::LIKE) {
        setState(409);
        match(CentSqlParser::LIKE);
        setState(410);
        dynamic_cast<ShowTablesContext *>(_localctx)->pattern = string();
        setState(413);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::ESCAPE) {
          setState(411);
          match(CentSqlParser::ESCAPE);
          setState(412);
          dynamic_cast<ShowTablesContext *>(_localctx)->escape = string();
        }
      }
      break;
    }

    case 26: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowSchemasContext>(_localctx));
      enterOuterAlt(_localctx, 26);
      setState(417);
      match(CentSqlParser::SHOW);
      setState(418);
      match(CentSqlParser::SCHEMAS);
      setState(421);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::FROM

      || _la == CentSqlParser::IN) {
        setState(419);
        _la = _input->LA(1);
        if (!(_la == CentSqlParser::FROM

        || _la == CentSqlParser::IN)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(420);
        identifier();
      }
      setState(429);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::LIKE) {
        setState(423);
        match(CentSqlParser::LIKE);
        setState(424);
        dynamic_cast<ShowSchemasContext *>(_localctx)->pattern = string();
        setState(427);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::ESCAPE) {
          setState(425);
          match(CentSqlParser::ESCAPE);
          setState(426);
          dynamic_cast<ShowSchemasContext *>(_localctx)->escape = string();
        }
      }
      break;
    }

    case 27: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowCatalogsContext>(_localctx));
      enterOuterAlt(_localctx, 27);
      setState(431);
      match(CentSqlParser::SHOW);
      setState(432);
      match(CentSqlParser::CATALOGS);
      setState(435);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::LIKE) {
        setState(433);
        match(CentSqlParser::LIKE);
        setState(434);
        dynamic_cast<ShowCatalogsContext *>(_localctx)->pattern = string();
      }
      break;
    }

    case 28: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowColumnsContext>(_localctx));
      enterOuterAlt(_localctx, 28);
      setState(437);
      match(CentSqlParser::SHOW);
      setState(438);
      match(CentSqlParser::COLUMNS);
      setState(439);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::FROM

      || _la == CentSqlParser::IN)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(440);
      qualifiedName();
      break;
    }

    case 29: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowStatsContext>(_localctx));
      enterOuterAlt(_localctx, 29);
      setState(441);
      match(CentSqlParser::SHOW);
      setState(442);
      match(CentSqlParser::STATS);
      setState(443);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::FOR

      || _la == CentSqlParser::ON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(444);
      qualifiedName();
      break;
    }

    case 30: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowStatsForQueryContext>(_localctx));
      enterOuterAlt(_localctx, 30);
      setState(445);
      match(CentSqlParser::SHOW);
      setState(446);
      match(CentSqlParser::STATS);
      setState(447);
      match(CentSqlParser::FOR);
      setState(448);
      match(CentSqlParser::T__1);
      setState(449);
      querySpecification();
      setState(450);
      match(CentSqlParser::T__2);
      break;
    }

    case 31: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowColumnsContext>(_localctx));
      enterOuterAlt(_localctx, 31);
      setState(452);
      match(CentSqlParser::DESCRIBE);
      setState(453);
      qualifiedName();
      break;
    }

    case 32: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowColumnsContext>(_localctx));
      enterOuterAlt(_localctx, 32);
      setState(454);
      match(CentSqlParser::DESC);
      setState(455);
      qualifiedName();
      break;
    }

    case 33: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowFunctionsContext>(_localctx));
      enterOuterAlt(_localctx, 33);
      setState(456);
      match(CentSqlParser::SHOW);
      setState(457);
      match(CentSqlParser::FUNCTIONS);
      break;
    }

    case 34: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ShowSessionContext>(_localctx));
      enterOuterAlt(_localctx, 34);
      setState(458);
      match(CentSqlParser::SHOW);
      setState(459);
      match(CentSqlParser::SESSION);
      break;
    }

    case 35: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::SetSessionContext>(_localctx));
      enterOuterAlt(_localctx, 35);
      setState(460);
      match(CentSqlParser::SET);
      setState(461);
      match(CentSqlParser::SESSION);
      setState(462);
      qualifiedName();
      setState(463);
      match(CentSqlParser::EQ);
      setState(464);
      expression();
      break;
    }

    case 36: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ResetSessionContext>(_localctx));
      enterOuterAlt(_localctx, 36);
      setState(466);
      match(CentSqlParser::RESET);
      setState(467);
      match(CentSqlParser::SESSION);
      setState(468);
      qualifiedName();
      break;
    }

    case 37: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::StartTransactionContext>(_localctx));
      enterOuterAlt(_localctx, 37);
      setState(469);
      match(CentSqlParser::START);
      setState(470);
      match(CentSqlParser::TRANSACTION);
      setState(479);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::ISOLATION

      || _la == CentSqlParser::READ) {
        setState(471);
        transactionMode();
        setState(476);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(472);
          match(CentSqlParser::T__3);
          setState(473);
          transactionMode();
          setState(478);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      break;
    }

    case 38: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::CommitContext>(_localctx));
      enterOuterAlt(_localctx, 38);
      setState(481);
      match(CentSqlParser::COMMIT);
      setState(483);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WORK) {
        setState(482);
        match(CentSqlParser::WORK);
      }
      break;
    }

    case 39: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::RollbackContext>(_localctx));
      enterOuterAlt(_localctx, 39);
      setState(485);
      match(CentSqlParser::ROLLBACK);
      setState(487);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::WORK) {
        setState(486);
        match(CentSqlParser::WORK);
      }
      break;
    }

    case 40: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::PrepareContext>(_localctx));
      enterOuterAlt(_localctx, 40);
      setState(489);
      match(CentSqlParser::PREPARE);
      setState(490);
      identifier();
      setState(491);
      match(CentSqlParser::FROM);
      setState(492);
      statement();
      break;
    }

    case 41: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DeallocateContext>(_localctx));
      enterOuterAlt(_localctx, 41);
      setState(494);
      match(CentSqlParser::DEALLOCATE);
      setState(495);
      match(CentSqlParser::PREPARE);
      setState(496);
      identifier();
      break;
    }

    case 42: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::ExecuteContext>(_localctx));
      enterOuterAlt(_localctx, 42);
      setState(497);
      match(CentSqlParser::EXECUTE);
      setState(498);
      identifier();
      setState(508);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::USING) {
        setState(499);
        match(CentSqlParser::USING);
        setState(500);
        expression();
        setState(505);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(501);
          match(CentSqlParser::T__3);
          setState(502);
          expression();
          setState(507);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      break;
    }

    case 43: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DescribeInputContext>(_localctx));
      enterOuterAlt(_localctx, 43);
      setState(510);
      match(CentSqlParser::DESCRIBE);
      setState(511);
      match(CentSqlParser::INPUT);
      setState(512);
      identifier();
      break;
    }

    case 44: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::DescribeOutputContext>(_localctx));
      enterOuterAlt(_localctx, 44);
      setState(513);
      match(CentSqlParser::DESCRIBE);
      setState(514);
      match(CentSqlParser::OUTPUT);
      setState(515);
      identifier();
      break;
    }

    case 45: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<CentSqlParser::SetPathContext>(_localctx));
      enterOuterAlt(_localctx, 45);
      setState(516);
      match(CentSqlParser::SET);
      setState(517);
      match(CentSqlParser::PATH);
      setState(518);
      pathSpecification();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryContext ------------------------------------------------------------------

CentSqlParser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::QueryNoWithContext* CentSqlParser::QueryContext::queryNoWith() {
  return getRuleContext<CentSqlParser::QueryNoWithContext>(0);
}

CentSqlParser::WithContext* CentSqlParser::QueryContext::with() {
  return getRuleContext<CentSqlParser::WithContext>(0);
}


size_t CentSqlParser::QueryContext::getRuleIndex() const {
  return CentSqlParser::RuleQuery;
}

void CentSqlParser::QueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuery(this);
}

void CentSqlParser::QueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuery(this);
}


antlrcpp::Any CentSqlParser::QueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQuery(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::QueryContext* CentSqlParser::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 8, CentSqlParser::RuleQuery);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(522);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::WITH) {
      setState(521);
      with();
    }
    setState(524);
    queryNoWith();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithContext ------------------------------------------------------------------

CentSqlParser::WithContext::WithContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::WithContext::WITH() {
  return getToken(CentSqlParser::WITH, 0);
}

std::vector<CentSqlParser::NamedQueryContext *> CentSqlParser::WithContext::namedQuery() {
  return getRuleContexts<CentSqlParser::NamedQueryContext>();
}

CentSqlParser::NamedQueryContext* CentSqlParser::WithContext::namedQuery(size_t i) {
  return getRuleContext<CentSqlParser::NamedQueryContext>(i);
}

tree::TerminalNode* CentSqlParser::WithContext::RECURSIVE() {
  return getToken(CentSqlParser::RECURSIVE, 0);
}


size_t CentSqlParser::WithContext::getRuleIndex() const {
  return CentSqlParser::RuleWith;
}

void CentSqlParser::WithContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWith(this);
}

void CentSqlParser::WithContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWith(this);
}


antlrcpp::Any CentSqlParser::WithContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitWith(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::WithContext* CentSqlParser::with() {
  WithContext *_localctx = _tracker.createInstance<WithContext>(_ctx, getState());
  enterRule(_localctx, 10, CentSqlParser::RuleWith);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(526);
    match(CentSqlParser::WITH);
    setState(528);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::RECURSIVE) {
      setState(527);
      match(CentSqlParser::RECURSIVE);
    }
    setState(530);
    namedQuery();
    setState(535);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CentSqlParser::T__3) {
      setState(531);
      match(CentSqlParser::T__3);
      setState(532);
      namedQuery();
      setState(537);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableElementContext ------------------------------------------------------------------

CentSqlParser::TableElementContext::TableElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::ColumnDefinitionContext* CentSqlParser::TableElementContext::columnDefinition() {
  return getRuleContext<CentSqlParser::ColumnDefinitionContext>(0);
}

CentSqlParser::LikeClauseContext* CentSqlParser::TableElementContext::likeClause() {
  return getRuleContext<CentSqlParser::LikeClauseContext>(0);
}


size_t CentSqlParser::TableElementContext::getRuleIndex() const {
  return CentSqlParser::RuleTableElement;
}

void CentSqlParser::TableElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTableElement(this);
}

void CentSqlParser::TableElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTableElement(this);
}


antlrcpp::Any CentSqlParser::TableElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTableElement(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::TableElementContext* CentSqlParser::tableElement() {
  TableElementContext *_localctx = _tracker.createInstance<TableElementContext>(_ctx, getState());
  enterRule(_localctx, 12, CentSqlParser::RuleTableElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(540);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE:
      case CentSqlParser::IDENTIFIER:
      case CentSqlParser::DIGIT_IDENTIFIER:
      case CentSqlParser::QUOTED_IDENTIFIER:
      case CentSqlParser::BACKQUOTED_IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(538);
        columnDefinition();
        break;
      }

      case CentSqlParser::LIKE: {
        enterOuterAlt(_localctx, 2);
        setState(539);
        likeClause();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnDefinitionContext ------------------------------------------------------------------

CentSqlParser::ColumnDefinitionContext::ColumnDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::IdentifierContext* CentSqlParser::ColumnDefinitionContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::TypeContext* CentSqlParser::ColumnDefinitionContext::type() {
  return getRuleContext<CentSqlParser::TypeContext>(0);
}

tree::TerminalNode* CentSqlParser::ColumnDefinitionContext::COMMENT() {
  return getToken(CentSqlParser::COMMENT, 0);
}

CentSqlParser::StringContext* CentSqlParser::ColumnDefinitionContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

tree::TerminalNode* CentSqlParser::ColumnDefinitionContext::WITH() {
  return getToken(CentSqlParser::WITH, 0);
}

CentSqlParser::PropertiesContext* CentSqlParser::ColumnDefinitionContext::properties() {
  return getRuleContext<CentSqlParser::PropertiesContext>(0);
}


size_t CentSqlParser::ColumnDefinitionContext::getRuleIndex() const {
  return CentSqlParser::RuleColumnDefinition;
}

void CentSqlParser::ColumnDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumnDefinition(this);
}

void CentSqlParser::ColumnDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumnDefinition(this);
}


antlrcpp::Any CentSqlParser::ColumnDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitColumnDefinition(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::ColumnDefinitionContext* CentSqlParser::columnDefinition() {
  ColumnDefinitionContext *_localctx = _tracker.createInstance<ColumnDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 14, CentSqlParser::RuleColumnDefinition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    identifier();
    setState(543);
    type(0);
    setState(546);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::COMMENT) {
      setState(544);
      match(CentSqlParser::COMMENT);
      setState(545);
      string();
    }
    setState(550);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::WITH) {
      setState(548);
      match(CentSqlParser::WITH);
      setState(549);
      properties();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LikeClauseContext ------------------------------------------------------------------

CentSqlParser::LikeClauseContext::LikeClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::LikeClauseContext::LIKE() {
  return getToken(CentSqlParser::LIKE, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::LikeClauseContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::LikeClauseContext::PROPERTIES() {
  return getToken(CentSqlParser::PROPERTIES, 0);
}

tree::TerminalNode* CentSqlParser::LikeClauseContext::INCLUDING() {
  return getToken(CentSqlParser::INCLUDING, 0);
}

tree::TerminalNode* CentSqlParser::LikeClauseContext::EXCLUDING() {
  return getToken(CentSqlParser::EXCLUDING, 0);
}


size_t CentSqlParser::LikeClauseContext::getRuleIndex() const {
  return CentSqlParser::RuleLikeClause;
}

void CentSqlParser::LikeClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLikeClause(this);
}

void CentSqlParser::LikeClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLikeClause(this);
}


antlrcpp::Any CentSqlParser::LikeClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitLikeClause(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::LikeClauseContext* CentSqlParser::likeClause() {
  LikeClauseContext *_localctx = _tracker.createInstance<LikeClauseContext>(_ctx, getState());
  enterRule(_localctx, 16, CentSqlParser::RuleLikeClause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(CentSqlParser::LIKE);
    setState(553);
    qualifiedName();
    setState(556);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::EXCLUDING

    || _la == CentSqlParser::INCLUDING) {
      setState(554);
      dynamic_cast<LikeClauseContext *>(_localctx)->optionType = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::EXCLUDING

      || _la == CentSqlParser::INCLUDING)) {
        dynamic_cast<LikeClauseContext *>(_localctx)->optionType = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(555);
      match(CentSqlParser::PROPERTIES);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertiesContext ------------------------------------------------------------------

CentSqlParser::PropertiesContext::PropertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CentSqlParser::PropertyContext *> CentSqlParser::PropertiesContext::property() {
  return getRuleContexts<CentSqlParser::PropertyContext>();
}

CentSqlParser::PropertyContext* CentSqlParser::PropertiesContext::property(size_t i) {
  return getRuleContext<CentSqlParser::PropertyContext>(i);
}


size_t CentSqlParser::PropertiesContext::getRuleIndex() const {
  return CentSqlParser::RuleProperties;
}

void CentSqlParser::PropertiesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperties(this);
}

void CentSqlParser::PropertiesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperties(this);
}


antlrcpp::Any CentSqlParser::PropertiesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitProperties(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::PropertiesContext* CentSqlParser::properties() {
  PropertiesContext *_localctx = _tracker.createInstance<PropertiesContext>(_ctx, getState());
  enterRule(_localctx, 18, CentSqlParser::RuleProperties);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(558);
    match(CentSqlParser::T__1);
    setState(559);
    property();
    setState(564);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CentSqlParser::T__3) {
      setState(560);
      match(CentSqlParser::T__3);
      setState(561);
      property();
      setState(566);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(567);
    match(CentSqlParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

CentSqlParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::IdentifierContext* CentSqlParser::PropertyContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::PropertyContext::EQ() {
  return getToken(CentSqlParser::EQ, 0);
}

CentSqlParser::ExpressionContext* CentSqlParser::PropertyContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}


size_t CentSqlParser::PropertyContext::getRuleIndex() const {
  return CentSqlParser::RuleProperty;
}

void CentSqlParser::PropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty(this);
}

void CentSqlParser::PropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty(this);
}


antlrcpp::Any CentSqlParser::PropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitProperty(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::PropertyContext* CentSqlParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 20, CentSqlParser::RuleProperty);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    identifier();
    setState(570);
    match(CentSqlParser::EQ);
    setState(571);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryNoWithContext ------------------------------------------------------------------

CentSqlParser::QueryNoWithContext::QueryNoWithContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::QueryTermContext* CentSqlParser::QueryNoWithContext::queryTerm() {
  return getRuleContext<CentSqlParser::QueryTermContext>(0);
}

tree::TerminalNode* CentSqlParser::QueryNoWithContext::ORDER() {
  return getToken(CentSqlParser::ORDER, 0);
}

tree::TerminalNode* CentSqlParser::QueryNoWithContext::BY() {
  return getToken(CentSqlParser::BY, 0);
}

std::vector<CentSqlParser::SortItemContext *> CentSqlParser::QueryNoWithContext::sortItem() {
  return getRuleContexts<CentSqlParser::SortItemContext>();
}

CentSqlParser::SortItemContext* CentSqlParser::QueryNoWithContext::sortItem(size_t i) {
  return getRuleContext<CentSqlParser::SortItemContext>(i);
}

tree::TerminalNode* CentSqlParser::QueryNoWithContext::LIMIT() {
  return getToken(CentSqlParser::LIMIT, 0);
}

tree::TerminalNode* CentSqlParser::QueryNoWithContext::INTEGER_VALUE() {
  return getToken(CentSqlParser::INTEGER_VALUE, 0);
}

tree::TerminalNode* CentSqlParser::QueryNoWithContext::ALL() {
  return getToken(CentSqlParser::ALL, 0);
}


size_t CentSqlParser::QueryNoWithContext::getRuleIndex() const {
  return CentSqlParser::RuleQueryNoWith;
}

void CentSqlParser::QueryNoWithContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueryNoWith(this);
}

void CentSqlParser::QueryNoWithContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueryNoWith(this);
}


antlrcpp::Any CentSqlParser::QueryNoWithContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQueryNoWith(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::QueryNoWithContext* CentSqlParser::queryNoWith() {
  QueryNoWithContext *_localctx = _tracker.createInstance<QueryNoWithContext>(_ctx, getState());
  enterRule(_localctx, 22, CentSqlParser::RuleQueryNoWith);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    queryTerm(0);
    setState(584);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::ORDER) {
      setState(574);
      match(CentSqlParser::ORDER);
      setState(575);
      match(CentSqlParser::BY);
      setState(576);
      sortItem();
      setState(581);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(577);
        match(CentSqlParser::T__3);
        setState(578);
        sortItem();
        setState(583);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(588);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::LIMIT) {
      setState(586);
      match(CentSqlParser::LIMIT);
      setState(587);
      dynamic_cast<QueryNoWithContext *>(_localctx)->limit = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::ALL || _la == CentSqlParser::INTEGER_VALUE)) {
        dynamic_cast<QueryNoWithContext *>(_localctx)->limit = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryTermContext ------------------------------------------------------------------

CentSqlParser::QueryTermContext::QueryTermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::QueryTermContext::getRuleIndex() const {
  return CentSqlParser::RuleQueryTerm;
}

void CentSqlParser::QueryTermContext::copyFrom(QueryTermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- QueryTermDefaultContext ------------------------------------------------------------------

CentSqlParser::QueryPrimaryContext* CentSqlParser::QueryTermDefaultContext::queryPrimary() {
  return getRuleContext<CentSqlParser::QueryPrimaryContext>(0);
}

CentSqlParser::QueryTermDefaultContext::QueryTermDefaultContext(QueryTermContext *ctx) { copyFrom(ctx); }

void CentSqlParser::QueryTermDefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueryTermDefault(this);
}
void CentSqlParser::QueryTermDefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueryTermDefault(this);
}

antlrcpp::Any CentSqlParser::QueryTermDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQueryTermDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SetOperationContext ------------------------------------------------------------------

std::vector<CentSqlParser::QueryTermContext *> CentSqlParser::SetOperationContext::queryTerm() {
  return getRuleContexts<CentSqlParser::QueryTermContext>();
}

CentSqlParser::QueryTermContext* CentSqlParser::SetOperationContext::queryTerm(size_t i) {
  return getRuleContext<CentSqlParser::QueryTermContext>(i);
}

tree::TerminalNode* CentSqlParser::SetOperationContext::INTERSECT() {
  return getToken(CentSqlParser::INTERSECT, 0);
}

CentSqlParser::SetQuantifierContext* CentSqlParser::SetOperationContext::setQuantifier() {
  return getRuleContext<CentSqlParser::SetQuantifierContext>(0);
}

tree::TerminalNode* CentSqlParser::SetOperationContext::UNION() {
  return getToken(CentSqlParser::UNION, 0);
}

tree::TerminalNode* CentSqlParser::SetOperationContext::EXCEPT() {
  return getToken(CentSqlParser::EXCEPT, 0);
}

CentSqlParser::SetOperationContext::SetOperationContext(QueryTermContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SetOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetOperation(this);
}
void CentSqlParser::SetOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetOperation(this);
}

antlrcpp::Any CentSqlParser::SetOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSetOperation(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::QueryTermContext* CentSqlParser::queryTerm() {
   return queryTerm(0);
}

CentSqlParser::QueryTermContext* CentSqlParser::queryTerm(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CentSqlParser::QueryTermContext *_localctx = _tracker.createInstance<QueryTermContext>(_ctx, parentState);
  CentSqlParser::QueryTermContext *previousContext = _localctx;
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, CentSqlParser::RuleQueryTerm, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<QueryTermDefaultContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(591);
    queryPrimary();
    _ctx->stop = _input->LT(-1);
    setState(607);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(605);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<SetOperationContext>(_tracker.createInstance<QueryTermContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleQueryTerm);
          setState(593);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(594);
          dynamic_cast<SetOperationContext *>(_localctx)->oper = match(CentSqlParser::INTERSECT);
          setState(596);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CentSqlParser::ALL

          || _la == CentSqlParser::DISTINCT) {
            setState(595);
            setQuantifier();
          }
          setState(598);
          dynamic_cast<SetOperationContext *>(_localctx)->right = queryTerm(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<SetOperationContext>(_tracker.createInstance<QueryTermContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleQueryTerm);
          setState(599);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(600);
          dynamic_cast<SetOperationContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CentSqlParser::EXCEPT || _la == CentSqlParser::UNION)) {
            dynamic_cast<SetOperationContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(602);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == CentSqlParser::ALL

          || _la == CentSqlParser::DISTINCT) {
            setState(601);
            setQuantifier();
          }
          setState(604);
          dynamic_cast<SetOperationContext *>(_localctx)->right = queryTerm(2);
          break;
        }

        } 
      }
      setState(609);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- QueryPrimaryContext ------------------------------------------------------------------

CentSqlParser::QueryPrimaryContext::QueryPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::QueryPrimaryContext::getRuleIndex() const {
  return CentSqlParser::RuleQueryPrimary;
}

void CentSqlParser::QueryPrimaryContext::copyFrom(QueryPrimaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SubqueryContext ------------------------------------------------------------------

CentSqlParser::QueryNoWithContext* CentSqlParser::SubqueryContext::queryNoWith() {
  return getRuleContext<CentSqlParser::QueryNoWithContext>(0);
}

CentSqlParser::SubqueryContext::SubqueryContext(QueryPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SubqueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubquery(this);
}
void CentSqlParser::SubqueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubquery(this);
}

antlrcpp::Any CentSqlParser::SubqueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSubquery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QueryPrimaryDefaultContext ------------------------------------------------------------------

CentSqlParser::QuerySpecificationContext* CentSqlParser::QueryPrimaryDefaultContext::querySpecification() {
  return getRuleContext<CentSqlParser::QuerySpecificationContext>(0);
}

CentSqlParser::QueryPrimaryDefaultContext::QueryPrimaryDefaultContext(QueryPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::QueryPrimaryDefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueryPrimaryDefault(this);
}
void CentSqlParser::QueryPrimaryDefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueryPrimaryDefault(this);
}

antlrcpp::Any CentSqlParser::QueryPrimaryDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQueryPrimaryDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::TableContext::TABLE() {
  return getToken(CentSqlParser::TABLE, 0);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::TableContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::TableContext::TableContext(QueryPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::TableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable(this);
}
void CentSqlParser::TableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable(this);
}

antlrcpp::Any CentSqlParser::TableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InlineTableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::InlineTableContext::VALUES() {
  return getToken(CentSqlParser::VALUES, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::InlineTableContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::InlineTableContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

CentSqlParser::InlineTableContext::InlineTableContext(QueryPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::InlineTableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInlineTable(this);
}
void CentSqlParser::InlineTableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInlineTable(this);
}

antlrcpp::Any CentSqlParser::InlineTableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitInlineTable(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::QueryPrimaryContext* CentSqlParser::queryPrimary() {
  QueryPrimaryContext *_localctx = _tracker.createInstance<QueryPrimaryContext>(_ctx, getState());
  enterRule(_localctx, 26, CentSqlParser::RuleQueryPrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(626);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::SELECT: {
        _localctx = dynamic_cast<QueryPrimaryContext *>(_tracker.createInstance<CentSqlParser::QueryPrimaryDefaultContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(610);
        querySpecification();
        break;
      }

      case CentSqlParser::TABLE: {
        _localctx = dynamic_cast<QueryPrimaryContext *>(_tracker.createInstance<CentSqlParser::TableContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(611);
        match(CentSqlParser::TABLE);
        setState(612);
        qualifiedName();
        break;
      }

      case CentSqlParser::VALUES: {
        _localctx = dynamic_cast<QueryPrimaryContext *>(_tracker.createInstance<CentSqlParser::InlineTableContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(613);
        match(CentSqlParser::VALUES);
        setState(614);
        expression();
        setState(619);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(615);
            match(CentSqlParser::T__3);
            setState(616);
            expression(); 
          }
          setState(621);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
        }
        break;
      }

      case CentSqlParser::T__1: {
        _localctx = dynamic_cast<QueryPrimaryContext *>(_tracker.createInstance<CentSqlParser::SubqueryContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(622);
        match(CentSqlParser::T__1);
        setState(623);
        queryNoWith();
        setState(624);
        match(CentSqlParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SortItemContext ------------------------------------------------------------------

CentSqlParser::SortItemContext::SortItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::ExpressionContext* CentSqlParser::SortItemContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::SortItemContext::NULLS() {
  return getToken(CentSqlParser::NULLS, 0);
}

tree::TerminalNode* CentSqlParser::SortItemContext::ASC() {
  return getToken(CentSqlParser::ASC, 0);
}

tree::TerminalNode* CentSqlParser::SortItemContext::DESC() {
  return getToken(CentSqlParser::DESC, 0);
}

tree::TerminalNode* CentSqlParser::SortItemContext::FIRST() {
  return getToken(CentSqlParser::FIRST, 0);
}

tree::TerminalNode* CentSqlParser::SortItemContext::LAST() {
  return getToken(CentSqlParser::LAST, 0);
}


size_t CentSqlParser::SortItemContext::getRuleIndex() const {
  return CentSqlParser::RuleSortItem;
}

void CentSqlParser::SortItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSortItem(this);
}

void CentSqlParser::SortItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSortItem(this);
}


antlrcpp::Any CentSqlParser::SortItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSortItem(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::SortItemContext* CentSqlParser::sortItem() {
  SortItemContext *_localctx = _tracker.createInstance<SortItemContext>(_ctx, getState());
  enterRule(_localctx, 28, CentSqlParser::RuleSortItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    expression();
    setState(630);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::ASC

    || _la == CentSqlParser::DESC) {
      setState(629);
      dynamic_cast<SortItemContext *>(_localctx)->ordering = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::ASC

      || _la == CentSqlParser::DESC)) {
        dynamic_cast<SortItemContext *>(_localctx)->ordering = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(634);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::NULLS) {
      setState(632);
      match(CentSqlParser::NULLS);
      setState(633);
      dynamic_cast<SortItemContext *>(_localctx)->nullOrdering = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::FIRST

      || _la == CentSqlParser::LAST)) {
        dynamic_cast<SortItemContext *>(_localctx)->nullOrdering = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuerySpecificationContext ------------------------------------------------------------------

CentSqlParser::QuerySpecificationContext::QuerySpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::QuerySpecificationContext::SELECT() {
  return getToken(CentSqlParser::SELECT, 0);
}

std::vector<CentSqlParser::SelectItemContext *> CentSqlParser::QuerySpecificationContext::selectItem() {
  return getRuleContexts<CentSqlParser::SelectItemContext>();
}

CentSqlParser::SelectItemContext* CentSqlParser::QuerySpecificationContext::selectItem(size_t i) {
  return getRuleContext<CentSqlParser::SelectItemContext>(i);
}

CentSqlParser::SetQuantifierContext* CentSqlParser::QuerySpecificationContext::setQuantifier() {
  return getRuleContext<CentSqlParser::SetQuantifierContext>(0);
}

tree::TerminalNode* CentSqlParser::QuerySpecificationContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

std::vector<CentSqlParser::RelationContext *> CentSqlParser::QuerySpecificationContext::relation() {
  return getRuleContexts<CentSqlParser::RelationContext>();
}

CentSqlParser::RelationContext* CentSqlParser::QuerySpecificationContext::relation(size_t i) {
  return getRuleContext<CentSqlParser::RelationContext>(i);
}

tree::TerminalNode* CentSqlParser::QuerySpecificationContext::WHERE() {
  return getToken(CentSqlParser::WHERE, 0);
}

tree::TerminalNode* CentSqlParser::QuerySpecificationContext::GROUP() {
  return getToken(CentSqlParser::GROUP, 0);
}

tree::TerminalNode* CentSqlParser::QuerySpecificationContext::BY() {
  return getToken(CentSqlParser::BY, 0);
}

CentSqlParser::GroupByContext* CentSqlParser::QuerySpecificationContext::groupBy() {
  return getRuleContext<CentSqlParser::GroupByContext>(0);
}

tree::TerminalNode* CentSqlParser::QuerySpecificationContext::HAVING() {
  return getToken(CentSqlParser::HAVING, 0);
}

std::vector<CentSqlParser::BooleanExpressionContext *> CentSqlParser::QuerySpecificationContext::booleanExpression() {
  return getRuleContexts<CentSqlParser::BooleanExpressionContext>();
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::QuerySpecificationContext::booleanExpression(size_t i) {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(i);
}


size_t CentSqlParser::QuerySpecificationContext::getRuleIndex() const {
  return CentSqlParser::RuleQuerySpecification;
}

void CentSqlParser::QuerySpecificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuerySpecification(this);
}

void CentSqlParser::QuerySpecificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuerySpecification(this);
}


antlrcpp::Any CentSqlParser::QuerySpecificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQuerySpecification(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::QuerySpecificationContext* CentSqlParser::querySpecification() {
  QuerySpecificationContext *_localctx = _tracker.createInstance<QuerySpecificationContext>(_ctx, getState());
  enterRule(_localctx, 30, CentSqlParser::RuleQuerySpecification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(636);
    match(CentSqlParser::SELECT);
    setState(638);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
    case 1: {
      setState(637);
      setQuantifier();
      break;
    }

    }
    setState(640);
    selectItem();
    setState(645);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(641);
        match(CentSqlParser::T__3);
        setState(642);
        selectItem(); 
      }
      setState(647);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
    }
    setState(657);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      setState(648);
      match(CentSqlParser::FROM);
      setState(649);
      relation(0);
      setState(654);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(650);
          match(CentSqlParser::T__3);
          setState(651);
          relation(0); 
        }
        setState(656);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx);
      }
      break;
    }

    }
    setState(661);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      setState(659);
      match(CentSqlParser::WHERE);
      setState(660);
      dynamic_cast<QuerySpecificationContext *>(_localctx)->where = booleanExpression(0);
      break;
    }

    }
    setState(666);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      setState(663);
      match(CentSqlParser::GROUP);
      setState(664);
      match(CentSqlParser::BY);
      setState(665);
      groupBy();
      break;
    }

    }
    setState(670);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx)) {
    case 1: {
      setState(668);
      match(CentSqlParser::HAVING);
      setState(669);
      dynamic_cast<QuerySpecificationContext *>(_localctx)->having = booleanExpression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupByContext ------------------------------------------------------------------

CentSqlParser::GroupByContext::GroupByContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CentSqlParser::GroupingElementContext *> CentSqlParser::GroupByContext::groupingElement() {
  return getRuleContexts<CentSqlParser::GroupingElementContext>();
}

CentSqlParser::GroupingElementContext* CentSqlParser::GroupByContext::groupingElement(size_t i) {
  return getRuleContext<CentSqlParser::GroupingElementContext>(i);
}

CentSqlParser::SetQuantifierContext* CentSqlParser::GroupByContext::setQuantifier() {
  return getRuleContext<CentSqlParser::SetQuantifierContext>(0);
}


size_t CentSqlParser::GroupByContext::getRuleIndex() const {
  return CentSqlParser::RuleGroupBy;
}

void CentSqlParser::GroupByContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroupBy(this);
}

void CentSqlParser::GroupByContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroupBy(this);
}


antlrcpp::Any CentSqlParser::GroupByContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitGroupBy(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::GroupByContext* CentSqlParser::groupBy() {
  GroupByContext *_localctx = _tracker.createInstance<GroupByContext>(_ctx, getState());
  enterRule(_localctx, 32, CentSqlParser::RuleGroupBy);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(673);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 76, _ctx)) {
    case 1: {
      setState(672);
      setQuantifier();
      break;
    }

    }
    setState(675);
    groupingElement();
    setState(680);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(676);
        match(CentSqlParser::T__3);
        setState(677);
        groupingElement(); 
      }
      setState(682);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupingElementContext ------------------------------------------------------------------

CentSqlParser::GroupingElementContext::GroupingElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::GroupingElementContext::getRuleIndex() const {
  return CentSqlParser::RuleGroupingElement;
}

void CentSqlParser::GroupingElementContext::copyFrom(GroupingElementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MultipleGroupingSetsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::MultipleGroupingSetsContext::GROUPING() {
  return getToken(CentSqlParser::GROUPING, 0);
}

tree::TerminalNode* CentSqlParser::MultipleGroupingSetsContext::SETS() {
  return getToken(CentSqlParser::SETS, 0);
}

std::vector<CentSqlParser::GroupingSetContext *> CentSqlParser::MultipleGroupingSetsContext::groupingSet() {
  return getRuleContexts<CentSqlParser::GroupingSetContext>();
}

CentSqlParser::GroupingSetContext* CentSqlParser::MultipleGroupingSetsContext::groupingSet(size_t i) {
  return getRuleContext<CentSqlParser::GroupingSetContext>(i);
}

CentSqlParser::MultipleGroupingSetsContext::MultipleGroupingSetsContext(GroupingElementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::MultipleGroupingSetsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultipleGroupingSets(this);
}
void CentSqlParser::MultipleGroupingSetsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultipleGroupingSets(this);
}

antlrcpp::Any CentSqlParser::MultipleGroupingSetsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitMultipleGroupingSets(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SingleGroupingSetContext ------------------------------------------------------------------

CentSqlParser::GroupingSetContext* CentSqlParser::SingleGroupingSetContext::groupingSet() {
  return getRuleContext<CentSqlParser::GroupingSetContext>(0);
}

CentSqlParser::SingleGroupingSetContext::SingleGroupingSetContext(GroupingElementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SingleGroupingSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleGroupingSet(this);
}
void CentSqlParser::SingleGroupingSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleGroupingSet(this);
}

antlrcpp::Any CentSqlParser::SingleGroupingSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSingleGroupingSet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CubeContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CubeContext::CUBE() {
  return getToken(CentSqlParser::CUBE, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::CubeContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::CubeContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

CentSqlParser::CubeContext::CubeContext(GroupingElementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CubeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCube(this);
}
void CentSqlParser::CubeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCube(this);
}

antlrcpp::Any CentSqlParser::CubeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCube(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RollupContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RollupContext::ROLLUP() {
  return getToken(CentSqlParser::ROLLUP, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::RollupContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::RollupContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

CentSqlParser::RollupContext::RollupContext(GroupingElementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RollupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRollup(this);
}
void CentSqlParser::RollupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRollup(this);
}

antlrcpp::Any CentSqlParser::RollupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRollup(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::GroupingElementContext* CentSqlParser::groupingElement() {
  GroupingElementContext *_localctx = _tracker.createInstance<GroupingElementContext>(_ctx, getState());
  enterRule(_localctx, 34, CentSqlParser::RuleGroupingElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(723);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<GroupingElementContext *>(_tracker.createInstance<CentSqlParser::SingleGroupingSetContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(683);
      groupingSet();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<GroupingElementContext *>(_tracker.createInstance<CentSqlParser::RollupContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(684);
      match(CentSqlParser::ROLLUP);
      setState(685);
      match(CentSqlParser::T__1);
      setState(694);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::T__1)
        | (1ULL << CentSqlParser::T__4)
        | (1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CASE)
        | (1ULL << CentSqlParser::CAST)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::CURRENT_DATE)
        | (1ULL << CentSqlParser::CURRENT_PATH)
        | (1ULL << CentSqlParser::CURRENT_TIME)
        | (1ULL << CentSqlParser::CURRENT_TIMESTAMP)
        | (1ULL << CentSqlParser::CURRENT_USER)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXISTS)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::EXTRACT)
        | (1ULL << CentSqlParser::FALSE_VALUE)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::GROUPING - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOCALTIME - 64))
        | (1ULL << (CentSqlParser::LOCALTIMESTAMP - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NORMALIZE - 64))
        | (1ULL << (CentSqlParser::NOT - 64))
        | (1ULL << (CentSqlParser::NULL_VALUE - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRUE_VALUE - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 197) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 197)) & ((1ULL << (CentSqlParser::PLUS - 197))
        | (1ULL << (CentSqlParser::MINUS - 197))
        | (1ULL << (CentSqlParser::STRING - 197))
        | (1ULL << (CentSqlParser::UNICODE_STRING - 197))
        | (1ULL << (CentSqlParser::BINARY_LITERAL - 197))
        | (1ULL << (CentSqlParser::INTEGER_VALUE - 197))
        | (1ULL << (CentSqlParser::DECIMAL_VALUE - 197))
        | (1ULL << (CentSqlParser::DOUBLE_VALUE - 197))
        | (1ULL << (CentSqlParser::IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DOUBLE_PRECISION - 197)))) != 0)) {
        setState(686);
        expression();
        setState(691);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(687);
          match(CentSqlParser::T__3);
          setState(688);
          expression();
          setState(693);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(696);
      match(CentSqlParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<GroupingElementContext *>(_tracker.createInstance<CentSqlParser::CubeContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(697);
      match(CentSqlParser::CUBE);
      setState(698);
      match(CentSqlParser::T__1);
      setState(707);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::T__1)
        | (1ULL << CentSqlParser::T__4)
        | (1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CASE)
        | (1ULL << CentSqlParser::CAST)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::CURRENT_DATE)
        | (1ULL << CentSqlParser::CURRENT_PATH)
        | (1ULL << CentSqlParser::CURRENT_TIME)
        | (1ULL << CentSqlParser::CURRENT_TIMESTAMP)
        | (1ULL << CentSqlParser::CURRENT_USER)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXISTS)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::EXTRACT)
        | (1ULL << CentSqlParser::FALSE_VALUE)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::GROUPING - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOCALTIME - 64))
        | (1ULL << (CentSqlParser::LOCALTIMESTAMP - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NORMALIZE - 64))
        | (1ULL << (CentSqlParser::NOT - 64))
        | (1ULL << (CentSqlParser::NULL_VALUE - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRUE_VALUE - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 197) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 197)) & ((1ULL << (CentSqlParser::PLUS - 197))
        | (1ULL << (CentSqlParser::MINUS - 197))
        | (1ULL << (CentSqlParser::STRING - 197))
        | (1ULL << (CentSqlParser::UNICODE_STRING - 197))
        | (1ULL << (CentSqlParser::BINARY_LITERAL - 197))
        | (1ULL << (CentSqlParser::INTEGER_VALUE - 197))
        | (1ULL << (CentSqlParser::DECIMAL_VALUE - 197))
        | (1ULL << (CentSqlParser::DOUBLE_VALUE - 197))
        | (1ULL << (CentSqlParser::IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DOUBLE_PRECISION - 197)))) != 0)) {
        setState(699);
        expression();
        setState(704);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(700);
          match(CentSqlParser::T__3);
          setState(701);
          expression();
          setState(706);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(709);
      match(CentSqlParser::T__2);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<GroupingElementContext *>(_tracker.createInstance<CentSqlParser::MultipleGroupingSetsContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(710);
      match(CentSqlParser::GROUPING);
      setState(711);
      match(CentSqlParser::SETS);
      setState(712);
      match(CentSqlParser::T__1);
      setState(713);
      groupingSet();
      setState(718);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(714);
        match(CentSqlParser::T__3);
        setState(715);
        groupingSet();
        setState(720);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(721);
      match(CentSqlParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupingSetContext ------------------------------------------------------------------

CentSqlParser::GroupingSetContext::GroupingSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::GroupingSetContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::GroupingSetContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}


size_t CentSqlParser::GroupingSetContext::getRuleIndex() const {
  return CentSqlParser::RuleGroupingSet;
}

void CentSqlParser::GroupingSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroupingSet(this);
}

void CentSqlParser::GroupingSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroupingSet(this);
}


antlrcpp::Any CentSqlParser::GroupingSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitGroupingSet(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::GroupingSetContext* CentSqlParser::groupingSet() {
  GroupingSetContext *_localctx = _tracker.createInstance<GroupingSetContext>(_ctx, getState());
  enterRule(_localctx, 36, CentSqlParser::RuleGroupingSet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(738);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(725);
      match(CentSqlParser::T__1);
      setState(734);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::T__1)
        | (1ULL << CentSqlParser::T__4)
        | (1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CASE)
        | (1ULL << CentSqlParser::CAST)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::CURRENT_DATE)
        | (1ULL << CentSqlParser::CURRENT_PATH)
        | (1ULL << CentSqlParser::CURRENT_TIME)
        | (1ULL << CentSqlParser::CURRENT_TIMESTAMP)
        | (1ULL << CentSqlParser::CURRENT_USER)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXISTS)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::EXTRACT)
        | (1ULL << CentSqlParser::FALSE_VALUE)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::GROUPING - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOCALTIME - 64))
        | (1ULL << (CentSqlParser::LOCALTIMESTAMP - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NORMALIZE - 64))
        | (1ULL << (CentSqlParser::NOT - 64))
        | (1ULL << (CentSqlParser::NULL_VALUE - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRUE_VALUE - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 197) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 197)) & ((1ULL << (CentSqlParser::PLUS - 197))
        | (1ULL << (CentSqlParser::MINUS - 197))
        | (1ULL << (CentSqlParser::STRING - 197))
        | (1ULL << (CentSqlParser::UNICODE_STRING - 197))
        | (1ULL << (CentSqlParser::BINARY_LITERAL - 197))
        | (1ULL << (CentSqlParser::INTEGER_VALUE - 197))
        | (1ULL << (CentSqlParser::DECIMAL_VALUE - 197))
        | (1ULL << (CentSqlParser::DOUBLE_VALUE - 197))
        | (1ULL << (CentSqlParser::IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DOUBLE_PRECISION - 197)))) != 0)) {
        setState(726);
        expression();
        setState(731);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(727);
          match(CentSqlParser::T__3);
          setState(728);
          expression();
          setState(733);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(736);
      match(CentSqlParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(737);
      expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedQueryContext ------------------------------------------------------------------

CentSqlParser::NamedQueryContext::NamedQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::NamedQueryContext::AS() {
  return getToken(CentSqlParser::AS, 0);
}

CentSqlParser::QueryContext* CentSqlParser::NamedQueryContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::IdentifierContext* CentSqlParser::NamedQueryContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::ColumnAliasesContext* CentSqlParser::NamedQueryContext::columnAliases() {
  return getRuleContext<CentSqlParser::ColumnAliasesContext>(0);
}


size_t CentSqlParser::NamedQueryContext::getRuleIndex() const {
  return CentSqlParser::RuleNamedQuery;
}

void CentSqlParser::NamedQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedQuery(this);
}

void CentSqlParser::NamedQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedQuery(this);
}


antlrcpp::Any CentSqlParser::NamedQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNamedQuery(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::NamedQueryContext* CentSqlParser::namedQuery() {
  NamedQueryContext *_localctx = _tracker.createInstance<NamedQueryContext>(_ctx, getState());
  enterRule(_localctx, 38, CentSqlParser::RuleNamedQuery);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(740);
    dynamic_cast<NamedQueryContext *>(_localctx)->name = identifier();
    setState(742);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::T__1) {
      setState(741);
      columnAliases();
    }
    setState(744);
    match(CentSqlParser::AS);
    setState(745);
    match(CentSqlParser::T__1);
    setState(746);
    query();
    setState(747);
    match(CentSqlParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetQuantifierContext ------------------------------------------------------------------

CentSqlParser::SetQuantifierContext::SetQuantifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::SetQuantifierContext::DISTINCT() {
  return getToken(CentSqlParser::DISTINCT, 0);
}

tree::TerminalNode* CentSqlParser::SetQuantifierContext::ALL() {
  return getToken(CentSqlParser::ALL, 0);
}


size_t CentSqlParser::SetQuantifierContext::getRuleIndex() const {
  return CentSqlParser::RuleSetQuantifier;
}

void CentSqlParser::SetQuantifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetQuantifier(this);
}

void CentSqlParser::SetQuantifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetQuantifier(this);
}


antlrcpp::Any CentSqlParser::SetQuantifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSetQuantifier(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::SetQuantifierContext* CentSqlParser::setQuantifier() {
  SetQuantifierContext *_localctx = _tracker.createInstance<SetQuantifierContext>(_ctx, getState());
  enterRule(_localctx, 40, CentSqlParser::RuleSetQuantifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(749);
    _la = _input->LA(1);
    if (!(_la == CentSqlParser::ALL

    || _la == CentSqlParser::DISTINCT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectItemContext ------------------------------------------------------------------

CentSqlParser::SelectItemContext::SelectItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::SelectItemContext::getRuleIndex() const {
  return CentSqlParser::RuleSelectItem;
}

void CentSqlParser::SelectItemContext::copyFrom(SelectItemContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SelectAllContext ------------------------------------------------------------------

CentSqlParser::QualifiedNameContext* CentSqlParser::SelectAllContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::SelectAllContext::ASTERISK() {
  return getToken(CentSqlParser::ASTERISK, 0);
}

CentSqlParser::SelectAllContext::SelectAllContext(SelectItemContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SelectAllContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectAll(this);
}
void CentSqlParser::SelectAllContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectAll(this);
}

antlrcpp::Any CentSqlParser::SelectAllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSelectAll(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelectSingleContext ------------------------------------------------------------------

CentSqlParser::ExpressionContext* CentSqlParser::SelectSingleContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::IdentifierContext* CentSqlParser::SelectSingleContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::SelectSingleContext::AS() {
  return getToken(CentSqlParser::AS, 0);
}

CentSqlParser::SelectSingleContext::SelectSingleContext(SelectItemContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SelectSingleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectSingle(this);
}
void CentSqlParser::SelectSingleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectSingle(this);
}

antlrcpp::Any CentSqlParser::SelectSingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSelectSingle(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::SelectItemContext* CentSqlParser::selectItem() {
  SelectItemContext *_localctx = _tracker.createInstance<SelectItemContext>(_ctx, getState());
  enterRule(_localctx, 42, CentSqlParser::RuleSelectItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(763);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SelectItemContext *>(_tracker.createInstance<CentSqlParser::SelectSingleContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(751);
      expression();
      setState(756);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx)) {
      case 1: {
        setState(753);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::AS) {
          setState(752);
          match(CentSqlParser::AS);
        }
        setState(755);
        identifier();
        break;
      }

      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SelectItemContext *>(_tracker.createInstance<CentSqlParser::SelectAllContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(758);
      qualifiedName();
      setState(759);
      match(CentSqlParser::T__0);
      setState(760);
      match(CentSqlParser::ASTERISK);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SelectItemContext *>(_tracker.createInstance<CentSqlParser::SelectAllContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(762);
      match(CentSqlParser::ASTERISK);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationContext ------------------------------------------------------------------

CentSqlParser::RelationContext::RelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::RelationContext::getRuleIndex() const {
  return CentSqlParser::RuleRelation;
}

void CentSqlParser::RelationContext::copyFrom(RelationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RelationDefaultContext ------------------------------------------------------------------

CentSqlParser::SampledRelationContext* CentSqlParser::RelationDefaultContext::sampledRelation() {
  return getRuleContext<CentSqlParser::SampledRelationContext>(0);
}

CentSqlParser::RelationDefaultContext::RelationDefaultContext(RelationContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RelationDefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationDefault(this);
}
void CentSqlParser::RelationDefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationDefault(this);
}

antlrcpp::Any CentSqlParser::RelationDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRelationDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- JoinRelationContext ------------------------------------------------------------------

std::vector<CentSqlParser::RelationContext *> CentSqlParser::JoinRelationContext::relation() {
  return getRuleContexts<CentSqlParser::RelationContext>();
}

CentSqlParser::RelationContext* CentSqlParser::JoinRelationContext::relation(size_t i) {
  return getRuleContext<CentSqlParser::RelationContext>(i);
}

tree::TerminalNode* CentSqlParser::JoinRelationContext::CROSS() {
  return getToken(CentSqlParser::CROSS, 0);
}

tree::TerminalNode* CentSqlParser::JoinRelationContext::JOIN() {
  return getToken(CentSqlParser::JOIN, 0);
}

CentSqlParser::JoinTypeContext* CentSqlParser::JoinRelationContext::joinType() {
  return getRuleContext<CentSqlParser::JoinTypeContext>(0);
}

CentSqlParser::JoinCriteriaContext* CentSqlParser::JoinRelationContext::joinCriteria() {
  return getRuleContext<CentSqlParser::JoinCriteriaContext>(0);
}

tree::TerminalNode* CentSqlParser::JoinRelationContext::NATURAL() {
  return getToken(CentSqlParser::NATURAL, 0);
}

CentSqlParser::SampledRelationContext* CentSqlParser::JoinRelationContext::sampledRelation() {
  return getRuleContext<CentSqlParser::SampledRelationContext>(0);
}

CentSqlParser::JoinRelationContext::JoinRelationContext(RelationContext *ctx) { copyFrom(ctx); }

void CentSqlParser::JoinRelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoinRelation(this);
}
void CentSqlParser::JoinRelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoinRelation(this);
}

antlrcpp::Any CentSqlParser::JoinRelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitJoinRelation(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::RelationContext* CentSqlParser::relation() {
   return relation(0);
}

CentSqlParser::RelationContext* CentSqlParser::relation(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CentSqlParser::RelationContext *_localctx = _tracker.createInstance<RelationContext>(_ctx, parentState);
  CentSqlParser::RelationContext *previousContext = _localctx;
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, CentSqlParser::RuleRelation, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<RelationDefaultContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(766);
    sampledRelation();
    _ctx->stop = _input->LT(-1);
    setState(786);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<JoinRelationContext>(_tracker.createInstance<RelationContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->left = previousContext;
        pushNewRecursionContext(newContext, startState, RuleRelation);
        setState(768);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(782);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case CentSqlParser::CROSS: {
            setState(769);
            match(CentSqlParser::CROSS);
            setState(770);
            match(CentSqlParser::JOIN);
            setState(771);
            dynamic_cast<JoinRelationContext *>(_localctx)->right = sampledRelation();
            break;
          }

          case CentSqlParser::FULL:
          case CentSqlParser::INNER:
          case CentSqlParser::JOIN:
          case CentSqlParser::LEFT:
          case CentSqlParser::RIGHT: {
            setState(772);
            joinType();
            setState(773);
            match(CentSqlParser::JOIN);
            setState(774);
            dynamic_cast<JoinRelationContext *>(_localctx)->rightRelation = relation(0);
            setState(775);
            joinCriteria();
            break;
          }

          case CentSqlParser::NATURAL: {
            setState(777);
            match(CentSqlParser::NATURAL);
            setState(778);
            joinType();
            setState(779);
            match(CentSqlParser::JOIN);
            setState(780);
            dynamic_cast<JoinRelationContext *>(_localctx)->right = sampledRelation();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(788);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 92, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- JoinTypeContext ------------------------------------------------------------------

CentSqlParser::JoinTypeContext::JoinTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::JoinTypeContext::INNER() {
  return getToken(CentSqlParser::INNER, 0);
}

tree::TerminalNode* CentSqlParser::JoinTypeContext::LEFT() {
  return getToken(CentSqlParser::LEFT, 0);
}

tree::TerminalNode* CentSqlParser::JoinTypeContext::OUTER() {
  return getToken(CentSqlParser::OUTER, 0);
}

tree::TerminalNode* CentSqlParser::JoinTypeContext::RIGHT() {
  return getToken(CentSqlParser::RIGHT, 0);
}

tree::TerminalNode* CentSqlParser::JoinTypeContext::FULL() {
  return getToken(CentSqlParser::FULL, 0);
}


size_t CentSqlParser::JoinTypeContext::getRuleIndex() const {
  return CentSqlParser::RuleJoinType;
}

void CentSqlParser::JoinTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoinType(this);
}

void CentSqlParser::JoinTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoinType(this);
}


antlrcpp::Any CentSqlParser::JoinTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitJoinType(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::JoinTypeContext* CentSqlParser::joinType() {
  JoinTypeContext *_localctx = _tracker.createInstance<JoinTypeContext>(_ctx, getState());
  enterRule(_localctx, 46, CentSqlParser::RuleJoinType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(804);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::INNER:
      case CentSqlParser::JOIN: {
        enterOuterAlt(_localctx, 1);
        setState(790);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::INNER) {
          setState(789);
          match(CentSqlParser::INNER);
        }
        break;
      }

      case CentSqlParser::LEFT: {
        enterOuterAlt(_localctx, 2);
        setState(792);
        match(CentSqlParser::LEFT);
        setState(794);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::OUTER) {
          setState(793);
          match(CentSqlParser::OUTER);
        }
        break;
      }

      case CentSqlParser::RIGHT: {
        enterOuterAlt(_localctx, 3);
        setState(796);
        match(CentSqlParser::RIGHT);
        setState(798);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::OUTER) {
          setState(797);
          match(CentSqlParser::OUTER);
        }
        break;
      }

      case CentSqlParser::FULL: {
        enterOuterAlt(_localctx, 4);
        setState(800);
        match(CentSqlParser::FULL);
        setState(802);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == CentSqlParser::OUTER) {
          setState(801);
          match(CentSqlParser::OUTER);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JoinCriteriaContext ------------------------------------------------------------------

CentSqlParser::JoinCriteriaContext::JoinCriteriaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::JoinCriteriaContext::ON() {
  return getToken(CentSqlParser::ON, 0);
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::JoinCriteriaContext::booleanExpression() {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::JoinCriteriaContext::USING() {
  return getToken(CentSqlParser::USING, 0);
}

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::JoinCriteriaContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::JoinCriteriaContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}


size_t CentSqlParser::JoinCriteriaContext::getRuleIndex() const {
  return CentSqlParser::RuleJoinCriteria;
}

void CentSqlParser::JoinCriteriaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoinCriteria(this);
}

void CentSqlParser::JoinCriteriaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoinCriteria(this);
}


antlrcpp::Any CentSqlParser::JoinCriteriaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitJoinCriteria(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::JoinCriteriaContext* CentSqlParser::joinCriteria() {
  JoinCriteriaContext *_localctx = _tracker.createInstance<JoinCriteriaContext>(_ctx, getState());
  enterRule(_localctx, 48, CentSqlParser::RuleJoinCriteria);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(820);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::ON: {
        enterOuterAlt(_localctx, 1);
        setState(806);
        match(CentSqlParser::ON);
        setState(807);
        booleanExpression(0);
        break;
      }

      case CentSqlParser::USING: {
        enterOuterAlt(_localctx, 2);
        setState(808);
        match(CentSqlParser::USING);
        setState(809);
        match(CentSqlParser::T__1);
        setState(810);
        identifier();
        setState(815);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(811);
          match(CentSqlParser::T__3);
          setState(812);
          identifier();
          setState(817);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(818);
        match(CentSqlParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SampledRelationContext ------------------------------------------------------------------

CentSqlParser::SampledRelationContext::SampledRelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::AliasedRelationContext* CentSqlParser::SampledRelationContext::aliasedRelation() {
  return getRuleContext<CentSqlParser::AliasedRelationContext>(0);
}

tree::TerminalNode* CentSqlParser::SampledRelationContext::TABLESAMPLE() {
  return getToken(CentSqlParser::TABLESAMPLE, 0);
}

CentSqlParser::SampleTypeContext* CentSqlParser::SampledRelationContext::sampleType() {
  return getRuleContext<CentSqlParser::SampleTypeContext>(0);
}

CentSqlParser::ExpressionContext* CentSqlParser::SampledRelationContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}


size_t CentSqlParser::SampledRelationContext::getRuleIndex() const {
  return CentSqlParser::RuleSampledRelation;
}

void CentSqlParser::SampledRelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSampledRelation(this);
}

void CentSqlParser::SampledRelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSampledRelation(this);
}


antlrcpp::Any CentSqlParser::SampledRelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSampledRelation(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::SampledRelationContext* CentSqlParser::sampledRelation() {
  SampledRelationContext *_localctx = _tracker.createInstance<SampledRelationContext>(_ctx, getState());
  enterRule(_localctx, 50, CentSqlParser::RuleSampledRelation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(822);
    aliasedRelation();
    setState(829);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      setState(823);
      match(CentSqlParser::TABLESAMPLE);
      setState(824);
      sampleType();
      setState(825);
      match(CentSqlParser::T__1);
      setState(826);
      dynamic_cast<SampledRelationContext *>(_localctx)->percentage = expression();
      setState(827);
      match(CentSqlParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SampleTypeContext ------------------------------------------------------------------

CentSqlParser::SampleTypeContext::SampleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::SampleTypeContext::BERNOULLI() {
  return getToken(CentSqlParser::BERNOULLI, 0);
}

tree::TerminalNode* CentSqlParser::SampleTypeContext::SYSTEM() {
  return getToken(CentSqlParser::SYSTEM, 0);
}


size_t CentSqlParser::SampleTypeContext::getRuleIndex() const {
  return CentSqlParser::RuleSampleType;
}

void CentSqlParser::SampleTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSampleType(this);
}

void CentSqlParser::SampleTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSampleType(this);
}


antlrcpp::Any CentSqlParser::SampleTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSampleType(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::SampleTypeContext* CentSqlParser::sampleType() {
  SampleTypeContext *_localctx = _tracker.createInstance<SampleTypeContext>(_ctx, getState());
  enterRule(_localctx, 52, CentSqlParser::RuleSampleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(831);
    _la = _input->LA(1);
    if (!(_la == CentSqlParser::BERNOULLI || _la == CentSqlParser::SYSTEM)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasedRelationContext ------------------------------------------------------------------

CentSqlParser::AliasedRelationContext::AliasedRelationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::RelationPrimaryContext* CentSqlParser::AliasedRelationContext::relationPrimary() {
  return getRuleContext<CentSqlParser::RelationPrimaryContext>(0);
}

CentSqlParser::IdentifierContext* CentSqlParser::AliasedRelationContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::AliasedRelationContext::AS() {
  return getToken(CentSqlParser::AS, 0);
}

CentSqlParser::ColumnAliasesContext* CentSqlParser::AliasedRelationContext::columnAliases() {
  return getRuleContext<CentSqlParser::ColumnAliasesContext>(0);
}


size_t CentSqlParser::AliasedRelationContext::getRuleIndex() const {
  return CentSqlParser::RuleAliasedRelation;
}

void CentSqlParser::AliasedRelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasedRelation(this);
}

void CentSqlParser::AliasedRelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasedRelation(this);
}


antlrcpp::Any CentSqlParser::AliasedRelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitAliasedRelation(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::AliasedRelationContext* CentSqlParser::aliasedRelation() {
  AliasedRelationContext *_localctx = _tracker.createInstance<AliasedRelationContext>(_ctx, getState());
  enterRule(_localctx, 54, CentSqlParser::RuleAliasedRelation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(833);
    relationPrimary();
    setState(841);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 103, _ctx)) {
    case 1: {
      setState(835);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::AS) {
        setState(834);
        match(CentSqlParser::AS);
      }
      setState(837);
      identifier();
      setState(839);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx)) {
      case 1: {
        setState(838);
        columnAliases();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnAliasesContext ------------------------------------------------------------------

CentSqlParser::ColumnAliasesContext::ColumnAliasesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::ColumnAliasesContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::ColumnAliasesContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}


size_t CentSqlParser::ColumnAliasesContext::getRuleIndex() const {
  return CentSqlParser::RuleColumnAliases;
}

void CentSqlParser::ColumnAliasesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumnAliases(this);
}

void CentSqlParser::ColumnAliasesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumnAliases(this);
}


antlrcpp::Any CentSqlParser::ColumnAliasesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitColumnAliases(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::ColumnAliasesContext* CentSqlParser::columnAliases() {
  ColumnAliasesContext *_localctx = _tracker.createInstance<ColumnAliasesContext>(_ctx, getState());
  enterRule(_localctx, 56, CentSqlParser::RuleColumnAliases);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(843);
    match(CentSqlParser::T__1);
    setState(844);
    identifier();
    setState(849);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CentSqlParser::T__3) {
      setState(845);
      match(CentSqlParser::T__3);
      setState(846);
      identifier();
      setState(851);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(852);
    match(CentSqlParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationPrimaryContext ------------------------------------------------------------------

CentSqlParser::RelationPrimaryContext::RelationPrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::RelationPrimaryContext::getRuleIndex() const {
  return CentSqlParser::RuleRelationPrimary;
}

void CentSqlParser::RelationPrimaryContext::copyFrom(RelationPrimaryContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SubqueryRelationContext ------------------------------------------------------------------

CentSqlParser::QueryContext* CentSqlParser::SubqueryRelationContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::SubqueryRelationContext::SubqueryRelationContext(RelationPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SubqueryRelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubqueryRelation(this);
}
void CentSqlParser::SubqueryRelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubqueryRelation(this);
}

antlrcpp::Any CentSqlParser::SubqueryRelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSubqueryRelation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedRelationContext ------------------------------------------------------------------

CentSqlParser::RelationContext* CentSqlParser::ParenthesizedRelationContext::relation() {
  return getRuleContext<CentSqlParser::RelationContext>(0);
}

CentSqlParser::ParenthesizedRelationContext::ParenthesizedRelationContext(RelationPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ParenthesizedRelationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedRelation(this);
}
void CentSqlParser::ParenthesizedRelationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedRelation(this);
}

antlrcpp::Any CentSqlParser::ParenthesizedRelationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitParenthesizedRelation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnnestContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::UnnestContext::UNNEST() {
  return getToken(CentSqlParser::UNNEST, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::UnnestContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::UnnestContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::UnnestContext::WITH() {
  return getToken(CentSqlParser::WITH, 0);
}

tree::TerminalNode* CentSqlParser::UnnestContext::ORDINALITY() {
  return getToken(CentSqlParser::ORDINALITY, 0);
}

CentSqlParser::UnnestContext::UnnestContext(RelationPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::UnnestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnnest(this);
}
void CentSqlParser::UnnestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnnest(this);
}

antlrcpp::Any CentSqlParser::UnnestContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitUnnest(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LateralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::LateralContext::LATERAL() {
  return getToken(CentSqlParser::LATERAL, 0);
}

CentSqlParser::QueryContext* CentSqlParser::LateralContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::LateralContext::LateralContext(RelationPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::LateralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLateral(this);
}
void CentSqlParser::LateralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLateral(this);
}

antlrcpp::Any CentSqlParser::LateralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitLateral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TableNameContext ------------------------------------------------------------------

CentSqlParser::QualifiedNameContext* CentSqlParser::TableNameContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

CentSqlParser::TableNameContext::TableNameContext(RelationPrimaryContext *ctx) { copyFrom(ctx); }

void CentSqlParser::TableNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTableName(this);
}
void CentSqlParser::TableNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTableName(this);
}

antlrcpp::Any CentSqlParser::TableNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTableName(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::RelationPrimaryContext* CentSqlParser::relationPrimary() {
  RelationPrimaryContext *_localctx = _tracker.createInstance<RelationPrimaryContext>(_ctx, getState());
  enterRule(_localctx, 58, CentSqlParser::RuleRelationPrimary);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(883);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<RelationPrimaryContext *>(_tracker.createInstance<CentSqlParser::TableNameContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(854);
      qualifiedName();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<RelationPrimaryContext *>(_tracker.createInstance<CentSqlParser::SubqueryRelationContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(855);
      match(CentSqlParser::T__1);
      setState(856);
      query();
      setState(857);
      match(CentSqlParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<RelationPrimaryContext *>(_tracker.createInstance<CentSqlParser::UnnestContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(859);
      match(CentSqlParser::UNNEST);
      setState(860);
      match(CentSqlParser::T__1);
      setState(861);
      expression();
      setState(866);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(862);
        match(CentSqlParser::T__3);
        setState(863);
        expression();
        setState(868);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(869);
      match(CentSqlParser::T__2);
      setState(872);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
      case 1: {
        setState(870);
        match(CentSqlParser::WITH);
        setState(871);
        match(CentSqlParser::ORDINALITY);
        break;
      }

      }
      break;
    }

    case 4: {
      _localctx = dynamic_cast<RelationPrimaryContext *>(_tracker.createInstance<CentSqlParser::LateralContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(874);
      match(CentSqlParser::LATERAL);
      setState(875);
      match(CentSqlParser::T__1);
      setState(876);
      query();
      setState(877);
      match(CentSqlParser::T__2);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<RelationPrimaryContext *>(_tracker.createInstance<CentSqlParser::ParenthesizedRelationContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(879);
      match(CentSqlParser::T__1);
      setState(880);
      relation(0);
      setState(881);
      match(CentSqlParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CentSqlParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::ExpressionContext::booleanExpression() {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(0);
}


size_t CentSqlParser::ExpressionContext::getRuleIndex() const {
  return CentSqlParser::RuleExpression;
}

void CentSqlParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void CentSqlParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any CentSqlParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::ExpressionContext* CentSqlParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 60, CentSqlParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(885);
    booleanExpression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanExpressionContext ------------------------------------------------------------------

CentSqlParser::BooleanExpressionContext::BooleanExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::BooleanExpressionContext::getRuleIndex() const {
  return CentSqlParser::RuleBooleanExpression;
}

void CentSqlParser::BooleanExpressionContext::copyFrom(BooleanExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicalNotContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::LogicalNotContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::LogicalNotContext::booleanExpression() {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(0);
}

CentSqlParser::LogicalNotContext::LogicalNotContext(BooleanExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::LogicalNotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalNot(this);
}
void CentSqlParser::LogicalNotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalNot(this);
}

antlrcpp::Any CentSqlParser::LogicalNotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitLogicalNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PredicatedContext ------------------------------------------------------------------

CentSqlParser::ValueExpressionContext* CentSqlParser::PredicatedContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

CentSqlParser::PredicateContext* CentSqlParser::PredicatedContext::predicate() {
  return getRuleContext<CentSqlParser::PredicateContext>(0);
}

CentSqlParser::PredicatedContext::PredicatedContext(BooleanExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::PredicatedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPredicated(this);
}
void CentSqlParser::PredicatedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPredicated(this);
}

antlrcpp::Any CentSqlParser::PredicatedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitPredicated(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalBinaryContext ------------------------------------------------------------------

std::vector<CentSqlParser::BooleanExpressionContext *> CentSqlParser::LogicalBinaryContext::booleanExpression() {
  return getRuleContexts<CentSqlParser::BooleanExpressionContext>();
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::LogicalBinaryContext::booleanExpression(size_t i) {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::LogicalBinaryContext::AND() {
  return getToken(CentSqlParser::AND, 0);
}

tree::TerminalNode* CentSqlParser::LogicalBinaryContext::OR() {
  return getToken(CentSqlParser::OR, 0);
}

CentSqlParser::LogicalBinaryContext::LogicalBinaryContext(BooleanExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::LogicalBinaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalBinary(this);
}
void CentSqlParser::LogicalBinaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalBinary(this);
}

antlrcpp::Any CentSqlParser::LogicalBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitLogicalBinary(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::booleanExpression() {
   return booleanExpression(0);
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::booleanExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CentSqlParser::BooleanExpressionContext *_localctx = _tracker.createInstance<BooleanExpressionContext>(_ctx, parentState);
  CentSqlParser::BooleanExpressionContext *previousContext = _localctx;
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, CentSqlParser::RuleBooleanExpression, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(894);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::T__1:
      case CentSqlParser::T__4:
      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CASE:
      case CentSqlParser::CAST:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::CURRENT_DATE:
      case CentSqlParser::CURRENT_PATH:
      case CentSqlParser::CURRENT_TIME:
      case CentSqlParser::CURRENT_TIMESTAMP:
      case CentSqlParser::CURRENT_USER:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXISTS:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::EXTRACT:
      case CentSqlParser::FALSE_VALUE:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::GROUPING:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOCALTIME:
      case CentSqlParser::LOCALTIMESTAMP:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NORMALIZE:
      case CentSqlParser::NULL_VALUE:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRUE_VALUE:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE:
      case CentSqlParser::PLUS:
      case CentSqlParser::MINUS:
      case CentSqlParser::STRING:
      case CentSqlParser::UNICODE_STRING:
      case CentSqlParser::BINARY_LITERAL:
      case CentSqlParser::INTEGER_VALUE:
      case CentSqlParser::DECIMAL_VALUE:
      case CentSqlParser::DOUBLE_VALUE:
      case CentSqlParser::IDENTIFIER:
      case CentSqlParser::DIGIT_IDENTIFIER:
      case CentSqlParser::QUOTED_IDENTIFIER:
      case CentSqlParser::BACKQUOTED_IDENTIFIER:
      case CentSqlParser::DOUBLE_PRECISION: {
        _localctx = _tracker.createInstance<PredicatedContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(888);
        dynamic_cast<PredicatedContext *>(_localctx)->valueExpressionContext = valueExpression(0);
        setState(890);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
        case 1: {
          setState(889);
          predicate(dynamic_cast<PredicatedContext *>(_localctx)->valueExpressionContext);
          break;
        }

        }
        break;
      }

      case CentSqlParser::NOT: {
        _localctx = _tracker.createInstance<LogicalNotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(892);
        match(CentSqlParser::NOT);
        setState(893);
        booleanExpression(3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(904);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(902);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<LogicalBinaryContext>(_tracker.createInstance<BooleanExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleBooleanExpression);
          setState(896);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(897);
          dynamic_cast<LogicalBinaryContext *>(_localctx)->oper = match(CentSqlParser::AND);
          setState(898);
          dynamic_cast<LogicalBinaryContext *>(_localctx)->right = booleanExpression(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<LogicalBinaryContext>(_tracker.createInstance<BooleanExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleBooleanExpression);
          setState(899);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(900);
          dynamic_cast<LogicalBinaryContext *>(_localctx)->oper = match(CentSqlParser::OR);
          setState(901);
          dynamic_cast<LogicalBinaryContext *>(_localctx)->right = booleanExpression(2);
          break;
        }

        } 
      }
      setState(906);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 111, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PredicateContext ------------------------------------------------------------------

CentSqlParser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CentSqlParser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState, antlr4::ParserRuleContext* value)
  : ParserRuleContext(parent, invokingState) {
  this->value = value;
}


size_t CentSqlParser::PredicateContext::getRuleIndex() const {
  return CentSqlParser::RulePredicate;
}

void CentSqlParser::PredicateContext::copyFrom(PredicateContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->value = ctx->value;
}

//----------------- ComparisonContext ------------------------------------------------------------------

CentSqlParser::ComparisonOperatorContext* CentSqlParser::ComparisonContext::comparisonOperator() {
  return getRuleContext<CentSqlParser::ComparisonOperatorContext>(0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::ComparisonContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

CentSqlParser::ComparisonContext::ComparisonContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}
void CentSqlParser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

antlrcpp::Any CentSqlParser::ComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitComparison(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LikeContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::LikeContext::LIKE() {
  return getToken(CentSqlParser::LIKE, 0);
}

std::vector<CentSqlParser::ValueExpressionContext *> CentSqlParser::LikeContext::valueExpression() {
  return getRuleContexts<CentSqlParser::ValueExpressionContext>();
}

CentSqlParser::ValueExpressionContext* CentSqlParser::LikeContext::valueExpression(size_t i) {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::LikeContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

tree::TerminalNode* CentSqlParser::LikeContext::ESCAPE() {
  return getToken(CentSqlParser::ESCAPE, 0);
}

CentSqlParser::LikeContext::LikeContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::LikeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLike(this);
}
void CentSqlParser::LikeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLike(this);
}

antlrcpp::Any CentSqlParser::LikeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitLike(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InSubqueryContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::InSubqueryContext::IN() {
  return getToken(CentSqlParser::IN, 0);
}

CentSqlParser::QueryContext* CentSqlParser::InSubqueryContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

tree::TerminalNode* CentSqlParser::InSubqueryContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

CentSqlParser::InSubqueryContext::InSubqueryContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::InSubqueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInSubquery(this);
}
void CentSqlParser::InSubqueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInSubquery(this);
}

antlrcpp::Any CentSqlParser::InSubqueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitInSubquery(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DistinctFromContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DistinctFromContext::IS() {
  return getToken(CentSqlParser::IS, 0);
}

tree::TerminalNode* CentSqlParser::DistinctFromContext::DISTINCT() {
  return getToken(CentSqlParser::DISTINCT, 0);
}

tree::TerminalNode* CentSqlParser::DistinctFromContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::DistinctFromContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::DistinctFromContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

CentSqlParser::DistinctFromContext::DistinctFromContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DistinctFromContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDistinctFrom(this);
}
void CentSqlParser::DistinctFromContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDistinctFrom(this);
}

antlrcpp::Any CentSqlParser::DistinctFromContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDistinctFrom(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InListContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::InListContext::IN() {
  return getToken(CentSqlParser::IN, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::InListContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::InListContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::InListContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

CentSqlParser::InListContext::InListContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::InListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInList(this);
}
void CentSqlParser::InListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInList(this);
}

antlrcpp::Any CentSqlParser::InListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitInList(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullPredicateContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::NullPredicateContext::IS() {
  return getToken(CentSqlParser::IS, 0);
}

tree::TerminalNode* CentSqlParser::NullPredicateContext::NULL_VALUE() {
  return getToken(CentSqlParser::NULL_VALUE, 0);
}

tree::TerminalNode* CentSqlParser::NullPredicateContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

CentSqlParser::NullPredicateContext::NullPredicateContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::NullPredicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullPredicate(this);
}
void CentSqlParser::NullPredicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullPredicate(this);
}

antlrcpp::Any CentSqlParser::NullPredicateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNullPredicate(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BetweenContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::BetweenContext::BETWEEN() {
  return getToken(CentSqlParser::BETWEEN, 0);
}

tree::TerminalNode* CentSqlParser::BetweenContext::AND() {
  return getToken(CentSqlParser::AND, 0);
}

std::vector<CentSqlParser::ValueExpressionContext *> CentSqlParser::BetweenContext::valueExpression() {
  return getRuleContexts<CentSqlParser::ValueExpressionContext>();
}

CentSqlParser::ValueExpressionContext* CentSqlParser::BetweenContext::valueExpression(size_t i) {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::BetweenContext::NOT() {
  return getToken(CentSqlParser::NOT, 0);
}

CentSqlParser::BetweenContext::BetweenContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::BetweenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBetween(this);
}
void CentSqlParser::BetweenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBetween(this);
}

antlrcpp::Any CentSqlParser::BetweenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBetween(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QuantifiedComparisonContext ------------------------------------------------------------------

CentSqlParser::ComparisonOperatorContext* CentSqlParser::QuantifiedComparisonContext::comparisonOperator() {
  return getRuleContext<CentSqlParser::ComparisonOperatorContext>(0);
}

CentSqlParser::ComparisonQuantifierContext* CentSqlParser::QuantifiedComparisonContext::comparisonQuantifier() {
  return getRuleContext<CentSqlParser::ComparisonQuantifierContext>(0);
}

CentSqlParser::QueryContext* CentSqlParser::QuantifiedComparisonContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::QuantifiedComparisonContext::QuantifiedComparisonContext(PredicateContext *ctx) { copyFrom(ctx); }

void CentSqlParser::QuantifiedComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuantifiedComparison(this);
}
void CentSqlParser::QuantifiedComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuantifiedComparison(this);
}

antlrcpp::Any CentSqlParser::QuantifiedComparisonContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQuantifiedComparison(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::PredicateContext* CentSqlParser::predicate(antlr4::ParserRuleContext* value) {
  PredicateContext *_localctx = _tracker.createInstance<PredicateContext>(_ctx, getState(), value);
  enterRule(_localctx, 64, CentSqlParser::RulePredicate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(968);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 120, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::ComparisonContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(907);
      comparisonOperator();
      setState(908);
      dynamic_cast<ComparisonContext *>(_localctx)->right = valueExpression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::QuantifiedComparisonContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(910);
      comparisonOperator();
      setState(911);
      comparisonQuantifier();
      setState(912);
      match(CentSqlParser::T__1);
      setState(913);
      query();
      setState(914);
      match(CentSqlParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::BetweenContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(917);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::NOT) {
        setState(916);
        match(CentSqlParser::NOT);
      }
      setState(919);
      match(CentSqlParser::BETWEEN);
      setState(920);
      dynamic_cast<BetweenContext *>(_localctx)->lower = valueExpression(0);
      setState(921);
      match(CentSqlParser::AND);
      setState(922);
      dynamic_cast<BetweenContext *>(_localctx)->upper = valueExpression(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::InListContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(925);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::NOT) {
        setState(924);
        match(CentSqlParser::NOT);
      }
      setState(927);
      match(CentSqlParser::IN);
      setState(928);
      match(CentSqlParser::T__1);
      setState(929);
      expression();
      setState(934);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(930);
        match(CentSqlParser::T__3);
        setState(931);
        expression();
        setState(936);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(937);
      match(CentSqlParser::T__2);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::InSubqueryContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(940);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::NOT) {
        setState(939);
        match(CentSqlParser::NOT);
      }
      setState(942);
      match(CentSqlParser::IN);
      setState(943);
      match(CentSqlParser::T__1);
      setState(944);
      query();
      setState(945);
      match(CentSqlParser::T__2);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::LikeContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(948);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::NOT) {
        setState(947);
        match(CentSqlParser::NOT);
      }
      setState(950);
      match(CentSqlParser::LIKE);
      setState(951);
      dynamic_cast<LikeContext *>(_localctx)->pattern = valueExpression(0);
      setState(954);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 117, _ctx)) {
      case 1: {
        setState(952);
        match(CentSqlParser::ESCAPE);
        setState(953);
        dynamic_cast<LikeContext *>(_localctx)->escape = valueExpression(0);
        break;
      }

      }
      break;
    }

    case 7: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::NullPredicateContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(956);
      match(CentSqlParser::IS);
      setState(958);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::NOT) {
        setState(957);
        match(CentSqlParser::NOT);
      }
      setState(960);
      match(CentSqlParser::NULL_VALUE);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<PredicateContext *>(_tracker.createInstance<CentSqlParser::DistinctFromContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(961);
      match(CentSqlParser::IS);
      setState(963);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::NOT) {
        setState(962);
        match(CentSqlParser::NOT);
      }
      setState(965);
      match(CentSqlParser::DISTINCT);
      setState(966);
      match(CentSqlParser::FROM);
      setState(967);
      dynamic_cast<DistinctFromContext *>(_localctx)->right = valueExpression(0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueExpressionContext ------------------------------------------------------------------

CentSqlParser::ValueExpressionContext::ValueExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::ValueExpressionContext::getRuleIndex() const {
  return CentSqlParser::RuleValueExpression;
}

void CentSqlParser::ValueExpressionContext::copyFrom(ValueExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ValueExpressionDefaultContext ------------------------------------------------------------------

CentSqlParser::PrimaryExpressionContext* CentSqlParser::ValueExpressionDefaultContext::primaryExpression() {
  return getRuleContext<CentSqlParser::PrimaryExpressionContext>(0);
}

CentSqlParser::ValueExpressionDefaultContext::ValueExpressionDefaultContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ValueExpressionDefaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValueExpressionDefault(this);
}
void CentSqlParser::ValueExpressionDefaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValueExpressionDefault(this);
}

antlrcpp::Any CentSqlParser::ValueExpressionDefaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitValueExpressionDefault(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConcatenationContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ConcatenationContext::CONCAT() {
  return getToken(CentSqlParser::CONCAT, 0);
}

std::vector<CentSqlParser::ValueExpressionContext *> CentSqlParser::ConcatenationContext::valueExpression() {
  return getRuleContexts<CentSqlParser::ValueExpressionContext>();
}

CentSqlParser::ValueExpressionContext* CentSqlParser::ConcatenationContext::valueExpression(size_t i) {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(i);
}

CentSqlParser::ConcatenationContext::ConcatenationContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ConcatenationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcatenation(this);
}
void CentSqlParser::ConcatenationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcatenation(this);
}

antlrcpp::Any CentSqlParser::ConcatenationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitConcatenation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticBinaryContext ------------------------------------------------------------------

std::vector<CentSqlParser::ValueExpressionContext *> CentSqlParser::ArithmeticBinaryContext::valueExpression() {
  return getRuleContexts<CentSqlParser::ValueExpressionContext>();
}

CentSqlParser::ValueExpressionContext* CentSqlParser::ArithmeticBinaryContext::valueExpression(size_t i) {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::ArithmeticBinaryContext::ASTERISK() {
  return getToken(CentSqlParser::ASTERISK, 0);
}

tree::TerminalNode* CentSqlParser::ArithmeticBinaryContext::SLASH() {
  return getToken(CentSqlParser::SLASH, 0);
}

tree::TerminalNode* CentSqlParser::ArithmeticBinaryContext::PERCENT() {
  return getToken(CentSqlParser::PERCENT, 0);
}

tree::TerminalNode* CentSqlParser::ArithmeticBinaryContext::PLUS() {
  return getToken(CentSqlParser::PLUS, 0);
}

tree::TerminalNode* CentSqlParser::ArithmeticBinaryContext::MINUS() {
  return getToken(CentSqlParser::MINUS, 0);
}

CentSqlParser::ArithmeticBinaryContext::ArithmeticBinaryContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ArithmeticBinaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmeticBinary(this);
}
void CentSqlParser::ArithmeticBinaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmeticBinary(this);
}

antlrcpp::Any CentSqlParser::ArithmeticBinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitArithmeticBinary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticUnaryContext ------------------------------------------------------------------

CentSqlParser::ValueExpressionContext* CentSqlParser::ArithmeticUnaryContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::ArithmeticUnaryContext::MINUS() {
  return getToken(CentSqlParser::MINUS, 0);
}

tree::TerminalNode* CentSqlParser::ArithmeticUnaryContext::PLUS() {
  return getToken(CentSqlParser::PLUS, 0);
}

CentSqlParser::ArithmeticUnaryContext::ArithmeticUnaryContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ArithmeticUnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmeticUnary(this);
}
void CentSqlParser::ArithmeticUnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmeticUnary(this);
}

antlrcpp::Any CentSqlParser::ArithmeticUnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitArithmeticUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtTimeZoneContext ------------------------------------------------------------------

CentSqlParser::ValueExpressionContext* CentSqlParser::AtTimeZoneContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::AtTimeZoneContext::AT() {
  return getToken(CentSqlParser::AT, 0);
}

CentSqlParser::TimeZoneSpecifierContext* CentSqlParser::AtTimeZoneContext::timeZoneSpecifier() {
  return getRuleContext<CentSqlParser::TimeZoneSpecifierContext>(0);
}

CentSqlParser::AtTimeZoneContext::AtTimeZoneContext(ValueExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::AtTimeZoneContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtTimeZone(this);
}
void CentSqlParser::AtTimeZoneContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtTimeZone(this);
}

antlrcpp::Any CentSqlParser::AtTimeZoneContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitAtTimeZone(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::valueExpression() {
   return valueExpression(0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::valueExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CentSqlParser::ValueExpressionContext *_localctx = _tracker.createInstance<ValueExpressionContext>(_ctx, parentState);
  CentSqlParser::ValueExpressionContext *previousContext = _localctx;
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, CentSqlParser::RuleValueExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(974);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::T__1:
      case CentSqlParser::T__4:
      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CASE:
      case CentSqlParser::CAST:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::CURRENT_DATE:
      case CentSqlParser::CURRENT_PATH:
      case CentSqlParser::CURRENT_TIME:
      case CentSqlParser::CURRENT_TIMESTAMP:
      case CentSqlParser::CURRENT_USER:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXISTS:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::EXTRACT:
      case CentSqlParser::FALSE_VALUE:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::GROUPING:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOCALTIME:
      case CentSqlParser::LOCALTIMESTAMP:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NORMALIZE:
      case CentSqlParser::NULL_VALUE:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRUE_VALUE:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE:
      case CentSqlParser::STRING:
      case CentSqlParser::UNICODE_STRING:
      case CentSqlParser::BINARY_LITERAL:
      case CentSqlParser::INTEGER_VALUE:
      case CentSqlParser::DECIMAL_VALUE:
      case CentSqlParser::DOUBLE_VALUE:
      case CentSqlParser::IDENTIFIER:
      case CentSqlParser::DIGIT_IDENTIFIER:
      case CentSqlParser::QUOTED_IDENTIFIER:
      case CentSqlParser::BACKQUOTED_IDENTIFIER:
      case CentSqlParser::DOUBLE_PRECISION: {
        _localctx = _tracker.createInstance<ValueExpressionDefaultContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(971);
        primaryExpression(0);
        break;
      }

      case CentSqlParser::PLUS:
      case CentSqlParser::MINUS: {
        _localctx = _tracker.createInstance<ArithmeticUnaryContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(972);
        dynamic_cast<ArithmeticUnaryContext *>(_localctx)->oper = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CentSqlParser::PLUS

        || _la == CentSqlParser::MINUS)) {
          dynamic_cast<ArithmeticUnaryContext *>(_localctx)->oper = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(973);
        valueExpression(4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(990);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(988);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 122, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(976);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(977);
          dynamic_cast<ArithmeticBinaryContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 199) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 199)) & ((1ULL << (CentSqlParser::ASTERISK - 199))
            | (1ULL << (CentSqlParser::SLASH - 199))
            | (1ULL << (CentSqlParser::PERCENT - 199)))) != 0))) {
            dynamic_cast<ArithmeticBinaryContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(978);
          dynamic_cast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticBinaryContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(979);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(980);
          dynamic_cast<ArithmeticBinaryContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CentSqlParser::PLUS

          || _la == CentSqlParser::MINUS)) {
            dynamic_cast<ArithmeticBinaryContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(981);
          dynamic_cast<ArithmeticBinaryContext *>(_localctx)->right = valueExpression(3);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ConcatenationContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(982);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(983);
          match(CentSqlParser::CONCAT);
          setState(984);
          dynamic_cast<ConcatenationContext *>(_localctx)->right = valueExpression(2);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AtTimeZoneContext>(_tracker.createInstance<ValueExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleValueExpression);
          setState(985);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(986);
          match(CentSqlParser::AT);
          setState(987);
          timeZoneSpecifier();
          break;
        }

        } 
      }
      setState(992);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

CentSqlParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::PrimaryExpressionContext::getRuleIndex() const {
  return CentSqlParser::RulePrimaryExpression;
}

void CentSqlParser::PrimaryExpressionContext::copyFrom(PrimaryExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DereferenceContext ------------------------------------------------------------------

CentSqlParser::PrimaryExpressionContext* CentSqlParser::DereferenceContext::primaryExpression() {
  return getRuleContext<CentSqlParser::PrimaryExpressionContext>(0);
}

CentSqlParser::IdentifierContext* CentSqlParser::DereferenceContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::DereferenceContext::DereferenceContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DereferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDereference(this);
}
void CentSqlParser::DereferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDereference(this);
}

antlrcpp::Any CentSqlParser::DereferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDereference(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeConstructorContext ------------------------------------------------------------------

CentSqlParser::IdentifierContext* CentSqlParser::TypeConstructorContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::StringContext* CentSqlParser::TypeConstructorContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

tree::TerminalNode* CentSqlParser::TypeConstructorContext::DOUBLE_PRECISION() {
  return getToken(CentSqlParser::DOUBLE_PRECISION, 0);
}

CentSqlParser::TypeConstructorContext::TypeConstructorContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::TypeConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeConstructor(this);
}
void CentSqlParser::TypeConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeConstructor(this);
}

antlrcpp::Any CentSqlParser::TypeConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTypeConstructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SpecialDateTimeFunctionContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SpecialDateTimeFunctionContext::CURRENT_DATE() {
  return getToken(CentSqlParser::CURRENT_DATE, 0);
}

tree::TerminalNode* CentSqlParser::SpecialDateTimeFunctionContext::CURRENT_TIME() {
  return getToken(CentSqlParser::CURRENT_TIME, 0);
}

tree::TerminalNode* CentSqlParser::SpecialDateTimeFunctionContext::INTEGER_VALUE() {
  return getToken(CentSqlParser::INTEGER_VALUE, 0);
}

tree::TerminalNode* CentSqlParser::SpecialDateTimeFunctionContext::CURRENT_TIMESTAMP() {
  return getToken(CentSqlParser::CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* CentSqlParser::SpecialDateTimeFunctionContext::LOCALTIME() {
  return getToken(CentSqlParser::LOCALTIME, 0);
}

tree::TerminalNode* CentSqlParser::SpecialDateTimeFunctionContext::LOCALTIMESTAMP() {
  return getToken(CentSqlParser::LOCALTIMESTAMP, 0);
}

CentSqlParser::SpecialDateTimeFunctionContext::SpecialDateTimeFunctionContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SpecialDateTimeFunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecialDateTimeFunction(this);
}
void CentSqlParser::SpecialDateTimeFunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecialDateTimeFunction(this);
}

antlrcpp::Any CentSqlParser::SpecialDateTimeFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSpecialDateTimeFunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubstringContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SubstringContext::SUBSTRING() {
  return getToken(CentSqlParser::SUBSTRING, 0);
}

std::vector<CentSqlParser::ValueExpressionContext *> CentSqlParser::SubstringContext::valueExpression() {
  return getRuleContexts<CentSqlParser::ValueExpressionContext>();
}

CentSqlParser::ValueExpressionContext* CentSqlParser::SubstringContext::valueExpression(size_t i) {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::SubstringContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

tree::TerminalNode* CentSqlParser::SubstringContext::FOR() {
  return getToken(CentSqlParser::FOR, 0);
}

CentSqlParser::SubstringContext::SubstringContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SubstringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubstring(this);
}
void CentSqlParser::SubstringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubstring(this);
}

antlrcpp::Any CentSqlParser::SubstringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSubstring(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CastContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CastContext::CAST() {
  return getToken(CentSqlParser::CAST, 0);
}

CentSqlParser::ExpressionContext* CentSqlParser::CastContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::CastContext::AS() {
  return getToken(CentSqlParser::AS, 0);
}

CentSqlParser::TypeContext* CentSqlParser::CastContext::type() {
  return getRuleContext<CentSqlParser::TypeContext>(0);
}

tree::TerminalNode* CentSqlParser::CastContext::TRY_CAST() {
  return getToken(CentSqlParser::TRY_CAST, 0);
}

CentSqlParser::CastContext::CastContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCast(this);
}
void CentSqlParser::CastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCast(this);
}

antlrcpp::Any CentSqlParser::CastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCast(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaContext ------------------------------------------------------------------

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::LambdaContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::LambdaContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}

CentSqlParser::ExpressionContext* CentSqlParser::LambdaContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::LambdaContext::LambdaContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::LambdaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambda(this);
}
void CentSqlParser::LambdaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambda(this);
}

antlrcpp::Any CentSqlParser::LambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitLambda(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpressionContext ------------------------------------------------------------------

CentSqlParser::ExpressionContext* CentSqlParser::ParenthesizedExpressionContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::ParenthesizedExpressionContext::ParenthesizedExpressionContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ParenthesizedExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesizedExpression(this);
}
void CentSqlParser::ParenthesizedExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesizedExpression(this);
}

antlrcpp::Any CentSqlParser::ParenthesizedExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParameterContext ------------------------------------------------------------------

CentSqlParser::ParameterContext::ParameterContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}
void CentSqlParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

antlrcpp::Any CentSqlParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NormalizeContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::NormalizeContext::NORMALIZE() {
  return getToken(CentSqlParser::NORMALIZE, 0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::NormalizeContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

CentSqlParser::NormalFormContext* CentSqlParser::NormalizeContext::normalForm() {
  return getRuleContext<CentSqlParser::NormalFormContext>(0);
}

CentSqlParser::NormalizeContext::NormalizeContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::NormalizeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNormalize(this);
}
void CentSqlParser::NormalizeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNormalize(this);
}

antlrcpp::Any CentSqlParser::NormalizeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNormalize(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntervalLiteralContext ------------------------------------------------------------------

CentSqlParser::IntervalContext* CentSqlParser::IntervalLiteralContext::interval() {
  return getRuleContext<CentSqlParser::IntervalContext>(0);
}

CentSqlParser::IntervalLiteralContext::IntervalLiteralContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::IntervalLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntervalLiteral(this);
}
void CentSqlParser::IntervalLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntervalLiteral(this);
}

antlrcpp::Any CentSqlParser::IntervalLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitIntervalLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumericLiteralContext ------------------------------------------------------------------

CentSqlParser::NumberContext* CentSqlParser::NumericLiteralContext::number() {
  return getRuleContext<CentSqlParser::NumberContext>(0);
}

CentSqlParser::NumericLiteralContext::NumericLiteralContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::NumericLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericLiteral(this);
}
void CentSqlParser::NumericLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericLiteral(this);
}

antlrcpp::Any CentSqlParser::NumericLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNumericLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanLiteralContext ------------------------------------------------------------------

CentSqlParser::BooleanValueContext* CentSqlParser::BooleanLiteralContext::booleanValue() {
  return getRuleContext<CentSqlParser::BooleanValueContext>(0);
}

CentSqlParser::BooleanLiteralContext::BooleanLiteralContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}
void CentSqlParser::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}

antlrcpp::Any CentSqlParser::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SimpleCaseContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SimpleCaseContext::CASE() {
  return getToken(CentSqlParser::CASE, 0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::SimpleCaseContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::SimpleCaseContext::END() {
  return getToken(CentSqlParser::END, 0);
}

std::vector<CentSqlParser::WhenClauseContext *> CentSqlParser::SimpleCaseContext::whenClause() {
  return getRuleContexts<CentSqlParser::WhenClauseContext>();
}

CentSqlParser::WhenClauseContext* CentSqlParser::SimpleCaseContext::whenClause(size_t i) {
  return getRuleContext<CentSqlParser::WhenClauseContext>(i);
}

tree::TerminalNode* CentSqlParser::SimpleCaseContext::ELSE() {
  return getToken(CentSqlParser::ELSE, 0);
}

CentSqlParser::ExpressionContext* CentSqlParser::SimpleCaseContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::SimpleCaseContext::SimpleCaseContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SimpleCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleCase(this);
}
void CentSqlParser::SimpleCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleCase(this);
}

antlrcpp::Any CentSqlParser::SimpleCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSimpleCase(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ColumnReferenceContext ------------------------------------------------------------------

CentSqlParser::IdentifierContext* CentSqlParser::ColumnReferenceContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::ColumnReferenceContext::ColumnReferenceContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ColumnReferenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumnReference(this);
}
void CentSqlParser::ColumnReferenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumnReference(this);
}

antlrcpp::Any CentSqlParser::ColumnReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitColumnReference(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::NullLiteralContext::NULL_VALUE() {
  return getToken(CentSqlParser::NULL_VALUE, 0);
}

CentSqlParser::NullLiteralContext::NullLiteralContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::NullLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullLiteral(this);
}
void CentSqlParser::NullLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullLiteral(this);
}

antlrcpp::Any CentSqlParser::NullLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNullLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RowConstructorContext ------------------------------------------------------------------

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::RowConstructorContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::RowConstructorContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::RowConstructorContext::ROW() {
  return getToken(CentSqlParser::ROW, 0);
}

CentSqlParser::RowConstructorContext::RowConstructorContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RowConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRowConstructor(this);
}
void CentSqlParser::RowConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRowConstructor(this);
}

antlrcpp::Any CentSqlParser::RowConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRowConstructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptContext ------------------------------------------------------------------

CentSqlParser::PrimaryExpressionContext* CentSqlParser::SubscriptContext::primaryExpression() {
  return getRuleContext<CentSqlParser::PrimaryExpressionContext>(0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::SubscriptContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

CentSqlParser::SubscriptContext::SubscriptContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SubscriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscript(this);
}
void CentSqlParser::SubscriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscript(this);
}

antlrcpp::Any CentSqlParser::SubscriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSubscript(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CurrentPathContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CurrentPathContext::CURRENT_PATH() {
  return getToken(CentSqlParser::CURRENT_PATH, 0);
}

CentSqlParser::CurrentPathContext::CurrentPathContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CurrentPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCurrentPath(this);
}
void CentSqlParser::CurrentPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCurrentPath(this);
}

antlrcpp::Any CentSqlParser::CurrentPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCurrentPath(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubqueryExpressionContext ------------------------------------------------------------------

CentSqlParser::QueryContext* CentSqlParser::SubqueryExpressionContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::SubqueryExpressionContext::SubqueryExpressionContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SubqueryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubqueryExpression(this);
}
void CentSqlParser::SubqueryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubqueryExpression(this);
}

antlrcpp::Any CentSqlParser::SubqueryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSubqueryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::BinaryLiteralContext::BINARY_LITERAL() {
  return getToken(CentSqlParser::BINARY_LITERAL, 0);
}

CentSqlParser::BinaryLiteralContext::BinaryLiteralContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::BinaryLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryLiteral(this);
}
void CentSqlParser::BinaryLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryLiteral(this);
}

antlrcpp::Any CentSqlParser::BinaryLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBinaryLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CurrentUserContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CurrentUserContext::CURRENT_USER() {
  return getToken(CentSqlParser::CURRENT_USER, 0);
}

CentSqlParser::CurrentUserContext::CurrentUserContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CurrentUserContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCurrentUser(this);
}
void CentSqlParser::CurrentUserContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCurrentUser(this);
}

antlrcpp::Any CentSqlParser::CurrentUserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCurrentUser(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExtractContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ExtractContext::EXTRACT() {
  return getToken(CentSqlParser::EXTRACT, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::ExtractContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

tree::TerminalNode* CentSqlParser::ExtractContext::FROM() {
  return getToken(CentSqlParser::FROM, 0);
}

CentSqlParser::ValueExpressionContext* CentSqlParser::ExtractContext::valueExpression() {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(0);
}

CentSqlParser::ExtractContext::ExtractContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ExtractContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExtract(this);
}
void CentSqlParser::ExtractContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExtract(this);
}

antlrcpp::Any CentSqlParser::ExtractContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExtract(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLiteralContext ------------------------------------------------------------------

CentSqlParser::StringContext* CentSqlParser::StringLiteralContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

CentSqlParser::StringLiteralContext::StringLiteralContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::StringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLiteral(this);
}
void CentSqlParser::StringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLiteral(this);
}

antlrcpp::Any CentSqlParser::StringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayConstructorContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ArrayConstructorContext::ARRAY() {
  return getToken(CentSqlParser::ARRAY, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::ArrayConstructorContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::ArrayConstructorContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

CentSqlParser::ArrayConstructorContext::ArrayConstructorContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ArrayConstructorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayConstructor(this);
}
void CentSqlParser::ArrayConstructorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayConstructor(this);
}

antlrcpp::Any CentSqlParser::ArrayConstructorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitArrayConstructor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

CentSqlParser::QualifiedNameContext* CentSqlParser::FunctionCallContext::qualifiedName() {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(0);
}

tree::TerminalNode* CentSqlParser::FunctionCallContext::ASTERISK() {
  return getToken(CentSqlParser::ASTERISK, 0);
}

CentSqlParser::FilterContext* CentSqlParser::FunctionCallContext::filter() {
  return getRuleContext<CentSqlParser::FilterContext>(0);
}

CentSqlParser::OverContext* CentSqlParser::FunctionCallContext::over() {
  return getRuleContext<CentSqlParser::OverContext>(0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::FunctionCallContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::FunctionCallContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::FunctionCallContext::ORDER() {
  return getToken(CentSqlParser::ORDER, 0);
}

tree::TerminalNode* CentSqlParser::FunctionCallContext::BY() {
  return getToken(CentSqlParser::BY, 0);
}

std::vector<CentSqlParser::SortItemContext *> CentSqlParser::FunctionCallContext::sortItem() {
  return getRuleContexts<CentSqlParser::SortItemContext>();
}

CentSqlParser::SortItemContext* CentSqlParser::FunctionCallContext::sortItem(size_t i) {
  return getRuleContext<CentSqlParser::SortItemContext>(i);
}

CentSqlParser::SetQuantifierContext* CentSqlParser::FunctionCallContext::setQuantifier() {
  return getRuleContext<CentSqlParser::SetQuantifierContext>(0);
}

CentSqlParser::FunctionCallContext::FunctionCallContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}
void CentSqlParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}

antlrcpp::Any CentSqlParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExistsContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ExistsContext::EXISTS() {
  return getToken(CentSqlParser::EXISTS, 0);
}

CentSqlParser::QueryContext* CentSqlParser::ExistsContext::query() {
  return getRuleContext<CentSqlParser::QueryContext>(0);
}

CentSqlParser::ExistsContext::ExistsContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ExistsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExists(this);
}
void CentSqlParser::ExistsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExists(this);
}

antlrcpp::Any CentSqlParser::ExistsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExists(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PositionContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::PositionContext::POSITION() {
  return getToken(CentSqlParser::POSITION, 0);
}

std::vector<CentSqlParser::ValueExpressionContext *> CentSqlParser::PositionContext::valueExpression() {
  return getRuleContexts<CentSqlParser::ValueExpressionContext>();
}

CentSqlParser::ValueExpressionContext* CentSqlParser::PositionContext::valueExpression(size_t i) {
  return getRuleContext<CentSqlParser::ValueExpressionContext>(i);
}

tree::TerminalNode* CentSqlParser::PositionContext::IN() {
  return getToken(CentSqlParser::IN, 0);
}

CentSqlParser::PositionContext::PositionContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::PositionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosition(this);
}
void CentSqlParser::PositionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosition(this);
}

antlrcpp::Any CentSqlParser::PositionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitPosition(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SearchedCaseContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SearchedCaseContext::CASE() {
  return getToken(CentSqlParser::CASE, 0);
}

tree::TerminalNode* CentSqlParser::SearchedCaseContext::END() {
  return getToken(CentSqlParser::END, 0);
}

std::vector<CentSqlParser::WhenClauseContext *> CentSqlParser::SearchedCaseContext::whenClause() {
  return getRuleContexts<CentSqlParser::WhenClauseContext>();
}

CentSqlParser::WhenClauseContext* CentSqlParser::SearchedCaseContext::whenClause(size_t i) {
  return getRuleContext<CentSqlParser::WhenClauseContext>(i);
}

tree::TerminalNode* CentSqlParser::SearchedCaseContext::ELSE() {
  return getToken(CentSqlParser::ELSE, 0);
}

CentSqlParser::ExpressionContext* CentSqlParser::SearchedCaseContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::SearchedCaseContext::SearchedCaseContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SearchedCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSearchedCase(this);
}
void CentSqlParser::SearchedCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSearchedCase(this);
}

antlrcpp::Any CentSqlParser::SearchedCaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSearchedCase(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GroupingOperationContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::GroupingOperationContext::GROUPING() {
  return getToken(CentSqlParser::GROUPING, 0);
}

std::vector<CentSqlParser::QualifiedNameContext *> CentSqlParser::GroupingOperationContext::qualifiedName() {
  return getRuleContexts<CentSqlParser::QualifiedNameContext>();
}

CentSqlParser::QualifiedNameContext* CentSqlParser::GroupingOperationContext::qualifiedName(size_t i) {
  return getRuleContext<CentSqlParser::QualifiedNameContext>(i);
}

CentSqlParser::GroupingOperationContext::GroupingOperationContext(PrimaryExpressionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::GroupingOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroupingOperation(this);
}
void CentSqlParser::GroupingOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroupingOperation(this);
}

antlrcpp::Any CentSqlParser::GroupingOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitGroupingOperation(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::PrimaryExpressionContext* CentSqlParser::primaryExpression() {
   return primaryExpression(0);
}

CentSqlParser::PrimaryExpressionContext* CentSqlParser::primaryExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CentSqlParser::PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, parentState);
  CentSqlParser::PrimaryExpressionContext *previousContext = _localctx;
  size_t startState = 68;
  enterRecursionRule(_localctx, 68, CentSqlParser::RulePrimaryExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<NullLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(994);
      match(CentSqlParser::NULL_VALUE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IntervalLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(995);
      interval();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<TypeConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(996);
      identifier();
      setState(997);
      string();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<TypeConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(999);
      match(CentSqlParser::DOUBLE_PRECISION);
      setState(1000);
      string();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NumericLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1001);
      number();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<BooleanLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1002);
      booleanValue();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<StringLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1003);
      string();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<BinaryLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1004);
      match(CentSqlParser::BINARY_LITERAL);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ParameterContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1005);
      match(CentSqlParser::T__4);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<PositionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1006);
      match(CentSqlParser::POSITION);
      setState(1007);
      match(CentSqlParser::T__1);
      setState(1008);
      valueExpression(0);
      setState(1009);
      match(CentSqlParser::IN);
      setState(1010);
      valueExpression(0);
      setState(1011);
      match(CentSqlParser::T__2);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<RowConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1013);
      match(CentSqlParser::T__1);
      setState(1014);
      expression();
      setState(1017); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1015);
        match(CentSqlParser::T__3);
        setState(1016);
        expression();
        setState(1019); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == CentSqlParser::T__3);
      setState(1021);
      match(CentSqlParser::T__2);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<RowConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1023);
      match(CentSqlParser::ROW);
      setState(1024);
      match(CentSqlParser::T__1);
      setState(1025);
      expression();
      setState(1030);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(1026);
        match(CentSqlParser::T__3);
        setState(1027);
        expression();
        setState(1032);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1033);
      match(CentSqlParser::T__2);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1035);
      qualifiedName();
      setState(1036);
      match(CentSqlParser::T__1);
      setState(1037);
      match(CentSqlParser::ASTERISK);
      setState(1038);
      match(CentSqlParser::T__2);
      setState(1040);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
      case 1: {
        setState(1039);
        filter();
        break;
      }

      }
      setState(1043);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 127, _ctx)) {
      case 1: {
        setState(1042);
        over();
        break;
      }

      }
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<FunctionCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1045);
      qualifiedName();
      setState(1046);
      match(CentSqlParser::T__1);
      setState(1058);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::T__1)
        | (1ULL << CentSqlParser::T__4)
        | (1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CASE)
        | (1ULL << CentSqlParser::CAST)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::CURRENT_DATE)
        | (1ULL << CentSqlParser::CURRENT_PATH)
        | (1ULL << CentSqlParser::CURRENT_TIME)
        | (1ULL << CentSqlParser::CURRENT_TIMESTAMP)
        | (1ULL << CentSqlParser::CURRENT_USER)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTINCT)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXISTS)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::EXTRACT)
        | (1ULL << CentSqlParser::FALSE_VALUE)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::GROUPING - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOCALTIME - 64))
        | (1ULL << (CentSqlParser::LOCALTIMESTAMP - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NORMALIZE - 64))
        | (1ULL << (CentSqlParser::NOT - 64))
        | (1ULL << (CentSqlParser::NULL_VALUE - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRUE_VALUE - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 197) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 197)) & ((1ULL << (CentSqlParser::PLUS - 197))
        | (1ULL << (CentSqlParser::MINUS - 197))
        | (1ULL << (CentSqlParser::STRING - 197))
        | (1ULL << (CentSqlParser::UNICODE_STRING - 197))
        | (1ULL << (CentSqlParser::BINARY_LITERAL - 197))
        | (1ULL << (CentSqlParser::INTEGER_VALUE - 197))
        | (1ULL << (CentSqlParser::DECIMAL_VALUE - 197))
        | (1ULL << (CentSqlParser::DOUBLE_VALUE - 197))
        | (1ULL << (CentSqlParser::IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DOUBLE_PRECISION - 197)))) != 0)) {
        setState(1048);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
        case 1: {
          setState(1047);
          setQuantifier();
          break;
        }

        }
        setState(1050);
        expression();
        setState(1055);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(1051);
          match(CentSqlParser::T__3);
          setState(1052);
          expression();
          setState(1057);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1070);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::ORDER) {
        setState(1060);
        match(CentSqlParser::ORDER);
        setState(1061);
        match(CentSqlParser::BY);
        setState(1062);
        sortItem();
        setState(1067);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(1063);
          match(CentSqlParser::T__3);
          setState(1064);
          sortItem();
          setState(1069);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1072);
      match(CentSqlParser::T__2);
      setState(1074);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 133, _ctx)) {
      case 1: {
        setState(1073);
        filter();
        break;
      }

      }
      setState(1077);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx)) {
      case 1: {
        setState(1076);
        over();
        break;
      }

      }
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<LambdaContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1079);
      identifier();
      setState(1080);
      match(CentSqlParser::T__5);
      setState(1081);
      expression();
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<LambdaContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1083);
      match(CentSqlParser::T__1);
      setState(1092);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 209) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 209)) & ((1ULL << (CentSqlParser::IDENTIFIER - 209))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 209))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 209))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 209)))) != 0)) {
        setState(1084);
        identifier();
        setState(1089);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(1085);
          match(CentSqlParser::T__3);
          setState(1086);
          identifier();
          setState(1091);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1094);
      match(CentSqlParser::T__2);
      setState(1095);
      match(CentSqlParser::T__5);
      setState(1096);
      expression();
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<SubqueryExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1097);
      match(CentSqlParser::T__1);
      setState(1098);
      query();
      setState(1099);
      match(CentSqlParser::T__2);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<ExistsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1101);
      match(CentSqlParser::EXISTS);
      setState(1102);
      match(CentSqlParser::T__1);
      setState(1103);
      query();
      setState(1104);
      match(CentSqlParser::T__2);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<SimpleCaseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1106);
      match(CentSqlParser::CASE);
      setState(1107);
      valueExpression(0);
      setState(1109); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1108);
        whenClause();
        setState(1111); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == CentSqlParser::WHEN);
      setState(1115);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::ELSE) {
        setState(1113);
        match(CentSqlParser::ELSE);
        setState(1114);
        dynamic_cast<SimpleCaseContext *>(_localctx)->elseExpression = expression();
      }
      setState(1117);
      match(CentSqlParser::END);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<SearchedCaseContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1119);
      match(CentSqlParser::CASE);
      setState(1121); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1120);
        whenClause();
        setState(1123); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == CentSqlParser::WHEN);
      setState(1127);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::ELSE) {
        setState(1125);
        match(CentSqlParser::ELSE);
        setState(1126);
        dynamic_cast<SearchedCaseContext *>(_localctx)->elseExpression = expression();
      }
      setState(1129);
      match(CentSqlParser::END);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<CastContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1131);
      match(CentSqlParser::CAST);
      setState(1132);
      match(CentSqlParser::T__1);
      setState(1133);
      expression();
      setState(1134);
      match(CentSqlParser::AS);
      setState(1135);
      type(0);
      setState(1136);
      match(CentSqlParser::T__2);
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<CastContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1138);
      match(CentSqlParser::TRY_CAST);
      setState(1139);
      match(CentSqlParser::T__1);
      setState(1140);
      expression();
      setState(1141);
      match(CentSqlParser::AS);
      setState(1142);
      type(0);
      setState(1143);
      match(CentSqlParser::T__2);
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<ArrayConstructorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1145);
      match(CentSqlParser::ARRAY);
      setState(1146);
      match(CentSqlParser::T__6);
      setState(1155);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::T__1)
        | (1ULL << CentSqlParser::T__4)
        | (1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CASE)
        | (1ULL << CentSqlParser::CAST)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::CURRENT_DATE)
        | (1ULL << CentSqlParser::CURRENT_PATH)
        | (1ULL << CentSqlParser::CURRENT_TIME)
        | (1ULL << CentSqlParser::CURRENT_TIMESTAMP)
        | (1ULL << CentSqlParser::CURRENT_USER)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXISTS)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::EXTRACT)
        | (1ULL << CentSqlParser::FALSE_VALUE)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::GROUPING - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOCALTIME - 64))
        | (1ULL << (CentSqlParser::LOCALTIMESTAMP - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NORMALIZE - 64))
        | (1ULL << (CentSqlParser::NOT - 64))
        | (1ULL << (CentSqlParser::NULL_VALUE - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRUE_VALUE - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 197) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 197)) & ((1ULL << (CentSqlParser::PLUS - 197))
        | (1ULL << (CentSqlParser::MINUS - 197))
        | (1ULL << (CentSqlParser::STRING - 197))
        | (1ULL << (CentSqlParser::UNICODE_STRING - 197))
        | (1ULL << (CentSqlParser::BINARY_LITERAL - 197))
        | (1ULL << (CentSqlParser::INTEGER_VALUE - 197))
        | (1ULL << (CentSqlParser::DECIMAL_VALUE - 197))
        | (1ULL << (CentSqlParser::DOUBLE_VALUE - 197))
        | (1ULL << (CentSqlParser::IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 197))
        | (1ULL << (CentSqlParser::DOUBLE_PRECISION - 197)))) != 0)) {
        setState(1147);
        expression();
        setState(1152);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(1148);
          match(CentSqlParser::T__3);
          setState(1149);
          expression();
          setState(1154);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1157);
      match(CentSqlParser::T__7);
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<ColumnReferenceContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1158);
      identifier();
      break;
    }

    case 25: {
      _localctx = _tracker.createInstance<SpecialDateTimeFunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1159);
      dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->name = match(CentSqlParser::CURRENT_DATE);
      break;
    }

    case 26: {
      _localctx = _tracker.createInstance<SpecialDateTimeFunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1160);
      dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->name = match(CentSqlParser::CURRENT_TIME);
      setState(1164);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx)) {
      case 1: {
        setState(1161);
        match(CentSqlParser::T__1);
        setState(1162);
        dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->precision = match(CentSqlParser::INTEGER_VALUE);
        setState(1163);
        match(CentSqlParser::T__2);
        break;
      }

      }
      break;
    }

    case 27: {
      _localctx = _tracker.createInstance<SpecialDateTimeFunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1166);
      dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->name = match(CentSqlParser::CURRENT_TIMESTAMP);
      setState(1170);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx)) {
      case 1: {
        setState(1167);
        match(CentSqlParser::T__1);
        setState(1168);
        dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->precision = match(CentSqlParser::INTEGER_VALUE);
        setState(1169);
        match(CentSqlParser::T__2);
        break;
      }

      }
      break;
    }

    case 28: {
      _localctx = _tracker.createInstance<SpecialDateTimeFunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1172);
      dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->name = match(CentSqlParser::LOCALTIME);
      setState(1176);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx)) {
      case 1: {
        setState(1173);
        match(CentSqlParser::T__1);
        setState(1174);
        dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->precision = match(CentSqlParser::INTEGER_VALUE);
        setState(1175);
        match(CentSqlParser::T__2);
        break;
      }

      }
      break;
    }

    case 29: {
      _localctx = _tracker.createInstance<SpecialDateTimeFunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1178);
      dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->name = match(CentSqlParser::LOCALTIMESTAMP);
      setState(1182);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx)) {
      case 1: {
        setState(1179);
        match(CentSqlParser::T__1);
        setState(1180);
        dynamic_cast<SpecialDateTimeFunctionContext *>(_localctx)->precision = match(CentSqlParser::INTEGER_VALUE);
        setState(1181);
        match(CentSqlParser::T__2);
        break;
      }

      }
      break;
    }

    case 30: {
      _localctx = _tracker.createInstance<CurrentUserContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1184);
      dynamic_cast<CurrentUserContext *>(_localctx)->name = match(CentSqlParser::CURRENT_USER);
      break;
    }

    case 31: {
      _localctx = _tracker.createInstance<CurrentPathContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1185);
      dynamic_cast<CurrentPathContext *>(_localctx)->name = match(CentSqlParser::CURRENT_PATH);
      break;
    }

    case 32: {
      _localctx = _tracker.createInstance<SubstringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1186);
      match(CentSqlParser::SUBSTRING);
      setState(1187);
      match(CentSqlParser::T__1);
      setState(1188);
      valueExpression(0);
      setState(1189);
      match(CentSqlParser::FROM);
      setState(1190);
      valueExpression(0);
      setState(1193);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::FOR) {
        setState(1191);
        match(CentSqlParser::FOR);
        setState(1192);
        valueExpression(0);
      }
      setState(1195);
      match(CentSqlParser::T__2);
      break;
    }

    case 33: {
      _localctx = _tracker.createInstance<NormalizeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1197);
      match(CentSqlParser::NORMALIZE);
      setState(1198);
      match(CentSqlParser::T__1);
      setState(1199);
      valueExpression(0);
      setState(1202);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == CentSqlParser::T__3) {
        setState(1200);
        match(CentSqlParser::T__3);
        setState(1201);
        normalForm();
      }
      setState(1204);
      match(CentSqlParser::T__2);
      break;
    }

    case 34: {
      _localctx = _tracker.createInstance<ExtractContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1206);
      match(CentSqlParser::EXTRACT);
      setState(1207);
      match(CentSqlParser::T__1);
      setState(1208);
      identifier();
      setState(1209);
      match(CentSqlParser::FROM);
      setState(1210);
      valueExpression(0);
      setState(1211);
      match(CentSqlParser::T__2);
      break;
    }

    case 35: {
      _localctx = _tracker.createInstance<ParenthesizedExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1213);
      match(CentSqlParser::T__1);
      setState(1214);
      expression();
      setState(1215);
      match(CentSqlParser::T__2);
      break;
    }

    case 36: {
      _localctx = _tracker.createInstance<GroupingOperationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(1217);
      match(CentSqlParser::GROUPING);
      setState(1218);
      match(CentSqlParser::T__1);
      setState(1227);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << CentSqlParser::ADD)
        | (1ULL << CentSqlParser::ALL)
        | (1ULL << CentSqlParser::ANALYZE)
        | (1ULL << CentSqlParser::ANY)
        | (1ULL << CentSqlParser::ARRAY)
        | (1ULL << CentSqlParser::ASC)
        | (1ULL << CentSqlParser::AT)
        | (1ULL << CentSqlParser::BERNOULLI)
        | (1ULL << CentSqlParser::CALL)
        | (1ULL << CentSqlParser::CASCADE)
        | (1ULL << CentSqlParser::CATALOGS)
        | (1ULL << CentSqlParser::COLUMN)
        | (1ULL << CentSqlParser::COLUMNS)
        | (1ULL << CentSqlParser::COMMENT)
        | (1ULL << CentSqlParser::COMMIT)
        | (1ULL << CentSqlParser::COMMITTED)
        | (1ULL << CentSqlParser::CURRENT)
        | (1ULL << CentSqlParser::DATA)
        | (1ULL << CentSqlParser::DATE)
        | (1ULL << CentSqlParser::DAY)
        | (1ULL << CentSqlParser::DESC)
        | (1ULL << CentSqlParser::DISTRIBUTED)
        | (1ULL << CentSqlParser::EXCLUDING)
        | (1ULL << CentSqlParser::EXPLAIN)
        | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
        | (1ULL << (CentSqlParser::FOLLOWING - 64))
        | (1ULL << (CentSqlParser::FORMAT - 64))
        | (1ULL << (CentSqlParser::FUNCTIONS - 64))
        | (1ULL << (CentSqlParser::GRANT - 64))
        | (1ULL << (CentSqlParser::GRANTS - 64))
        | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
        | (1ULL << (CentSqlParser::HOUR - 64))
        | (1ULL << (CentSqlParser::IF - 64))
        | (1ULL << (CentSqlParser::INCLUDING - 64))
        | (1ULL << (CentSqlParser::INPUT - 64))
        | (1ULL << (CentSqlParser::INTERVAL - 64))
        | (1ULL << (CentSqlParser::IO - 64))
        | (1ULL << (CentSqlParser::ISOLATION - 64))
        | (1ULL << (CentSqlParser::JSON - 64))
        | (1ULL << (CentSqlParser::LAST - 64))
        | (1ULL << (CentSqlParser::LATERAL - 64))
        | (1ULL << (CentSqlParser::LEVEL - 64))
        | (1ULL << (CentSqlParser::LIMIT - 64))
        | (1ULL << (CentSqlParser::LOGICAL - 64))
        | (1ULL << (CentSqlParser::MAP - 64))
        | (1ULL << (CentSqlParser::MINUTE - 64))
        | (1ULL << (CentSqlParser::MONTH - 64))
        | (1ULL << (CentSqlParser::NFC - 64))
        | (1ULL << (CentSqlParser::NFD - 64))
        | (1ULL << (CentSqlParser::NFKC - 64))
        | (1ULL << (CentSqlParser::NFKD - 64))
        | (1ULL << (CentSqlParser::NO - 64))
        | (1ULL << (CentSqlParser::NULLIF - 64))
        | (1ULL << (CentSqlParser::NULLS - 64))
        | (1ULL << (CentSqlParser::ONLY - 64))
        | (1ULL << (CentSqlParser::OPTION - 64))
        | (1ULL << (CentSqlParser::ORDINALITY - 64))
        | (1ULL << (CentSqlParser::OUTPUT - 64))
        | (1ULL << (CentSqlParser::OVER - 64))
        | (1ULL << (CentSqlParser::PARTITION - 64))
        | (1ULL << (CentSqlParser::PARTITIONS - 64))
        | (1ULL << (CentSqlParser::PATH - 64))
        | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
        | (1ULL << (CentSqlParser::PRIVILEGES - 128))
        | (1ULL << (CentSqlParser::PROPERTIES - 128))
        | (1ULL << (CentSqlParser::PUBLIC - 128))
        | (1ULL << (CentSqlParser::RANGE - 128))
        | (1ULL << (CentSqlParser::READ - 128))
        | (1ULL << (CentSqlParser::RENAME - 128))
        | (1ULL << (CentSqlParser::REPEATABLE - 128))
        | (1ULL << (CentSqlParser::REPLACE - 128))
        | (1ULL << (CentSqlParser::RESET - 128))
        | (1ULL << (CentSqlParser::RESTRICT - 128))
        | (1ULL << (CentSqlParser::REVOKE - 128))
        | (1ULL << (CentSqlParser::ROLLBACK - 128))
        | (1ULL << (CentSqlParser::ROW - 128))
        | (1ULL << (CentSqlParser::ROWS - 128))
        | (1ULL << (CentSqlParser::SCHEMA - 128))
        | (1ULL << (CentSqlParser::SCHEMAS - 128))
        | (1ULL << (CentSqlParser::SECOND - 128))
        | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
        | (1ULL << (CentSqlParser::SESSION - 128))
        | (1ULL << (CentSqlParser::SET - 128))
        | (1ULL << (CentSqlParser::SETS - 128))
        | (1ULL << (CentSqlParser::SHOW - 128))
        | (1ULL << (CentSqlParser::SOME - 128))
        | (1ULL << (CentSqlParser::START - 128))
        | (1ULL << (CentSqlParser::STATS - 128))
        | (1ULL << (CentSqlParser::SUBSTRING - 128))
        | (1ULL << (CentSqlParser::SYSTEM - 128))
        | (1ULL << (CentSqlParser::TABLES - 128))
        | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
        | (1ULL << (CentSqlParser::TEXT - 128))
        | (1ULL << (CentSqlParser::TIME - 128))
        | (1ULL << (CentSqlParser::TIMESTAMP - 128))
        | (1ULL << (CentSqlParser::TO - 128))
        | (1ULL << (CentSqlParser::TRANSACTION - 128))
        | (1ULL << (CentSqlParser::TRY_CAST - 128))
        | (1ULL << (CentSqlParser::TYPE - 128))
        | (1ULL << (CentSqlParser::UNBOUNDED - 128))
        | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
        | (1ULL << (CentSqlParser::USE - 128))
        | (1ULL << (CentSqlParser::VALIDATE - 128))
        | (1ULL << (CentSqlParser::VERBOSE - 128))
        | (1ULL << (CentSqlParser::VIEW - 128))
        | (1ULL << (CentSqlParser::WORK - 128))
        | (1ULL << (CentSqlParser::WRITE - 128))
        | (1ULL << (CentSqlParser::YEAR - 128))
        | (1ULL << (CentSqlParser::ZONE - 128)))) != 0) || ((((_la - 209) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 209)) & ((1ULL << (CentSqlParser::IDENTIFIER - 209))
        | (1ULL << (CentSqlParser::DIGIT_IDENTIFIER - 209))
        | (1ULL << (CentSqlParser::QUOTED_IDENTIFIER - 209))
        | (1ULL << (CentSqlParser::BACKQUOTED_IDENTIFIER - 209)))) != 0)) {
        setState(1219);
        qualifiedName();
        setState(1224);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(1220);
          match(CentSqlParser::T__3);
          setState(1221);
          qualifiedName();
          setState(1226);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(1229);
      match(CentSqlParser::T__2);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1242);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1240);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 152, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<SubscriptContext>(_tracker.createInstance<PrimaryExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->value = previousContext;
          pushNewRecursionContext(newContext, startState, RulePrimaryExpression);
          setState(1232);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(1233);
          match(CentSqlParser::T__6);
          setState(1234);
          dynamic_cast<SubscriptContext *>(_localctx)->index = valueExpression(0);
          setState(1235);
          match(CentSqlParser::T__7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DereferenceContext>(_tracker.createInstance<PrimaryExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->base = previousContext;
          pushNewRecursionContext(newContext, startState, RulePrimaryExpression);
          setState(1237);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(1238);
          match(CentSqlParser::T__0);
          setState(1239);
          dynamic_cast<DereferenceContext *>(_localctx)->fieldName = identifier();
          break;
        }

        } 
      }
      setState(1244);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

CentSqlParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::StringContext::getRuleIndex() const {
  return CentSqlParser::RuleString;
}

void CentSqlParser::StringContext::copyFrom(StringContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnicodeStringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::UnicodeStringLiteralContext::UNICODE_STRING() {
  return getToken(CentSqlParser::UNICODE_STRING, 0);
}

tree::TerminalNode* CentSqlParser::UnicodeStringLiteralContext::UESCAPE() {
  return getToken(CentSqlParser::UESCAPE, 0);
}

tree::TerminalNode* CentSqlParser::UnicodeStringLiteralContext::STRING() {
  return getToken(CentSqlParser::STRING, 0);
}

CentSqlParser::UnicodeStringLiteralContext::UnicodeStringLiteralContext(StringContext *ctx) { copyFrom(ctx); }

void CentSqlParser::UnicodeStringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnicodeStringLiteral(this);
}
void CentSqlParser::UnicodeStringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnicodeStringLiteral(this);
}

antlrcpp::Any CentSqlParser::UnicodeStringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitUnicodeStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BasicStringLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::BasicStringLiteralContext::STRING() {
  return getToken(CentSqlParser::STRING, 0);
}

CentSqlParser::BasicStringLiteralContext::BasicStringLiteralContext(StringContext *ctx) { copyFrom(ctx); }

void CentSqlParser::BasicStringLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicStringLiteral(this);
}
void CentSqlParser::BasicStringLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicStringLiteral(this);
}

antlrcpp::Any CentSqlParser::BasicStringLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBasicStringLiteral(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::StringContext* CentSqlParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 70, CentSqlParser::RuleString);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1251);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::STRING: {
        _localctx = dynamic_cast<StringContext *>(_tracker.createInstance<CentSqlParser::BasicStringLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(1245);
        match(CentSqlParser::STRING);
        break;
      }

      case CentSqlParser::UNICODE_STRING: {
        _localctx = dynamic_cast<StringContext *>(_tracker.createInstance<CentSqlParser::UnicodeStringLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(1246);
        match(CentSqlParser::UNICODE_STRING);
        setState(1249);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
        case 1: {
          setState(1247);
          match(CentSqlParser::UESCAPE);
          setState(1248);
          match(CentSqlParser::STRING);
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeZoneSpecifierContext ------------------------------------------------------------------

CentSqlParser::TimeZoneSpecifierContext::TimeZoneSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::TimeZoneSpecifierContext::getRuleIndex() const {
  return CentSqlParser::RuleTimeZoneSpecifier;
}

void CentSqlParser::TimeZoneSpecifierContext::copyFrom(TimeZoneSpecifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TimeZoneIntervalContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::TimeZoneIntervalContext::TIME() {
  return getToken(CentSqlParser::TIME, 0);
}

tree::TerminalNode* CentSqlParser::TimeZoneIntervalContext::ZONE() {
  return getToken(CentSqlParser::ZONE, 0);
}

CentSqlParser::IntervalContext* CentSqlParser::TimeZoneIntervalContext::interval() {
  return getRuleContext<CentSqlParser::IntervalContext>(0);
}

CentSqlParser::TimeZoneIntervalContext::TimeZoneIntervalContext(TimeZoneSpecifierContext *ctx) { copyFrom(ctx); }

void CentSqlParser::TimeZoneIntervalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeZoneInterval(this);
}
void CentSqlParser::TimeZoneIntervalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeZoneInterval(this);
}

antlrcpp::Any CentSqlParser::TimeZoneIntervalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTimeZoneInterval(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TimeZoneStringContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::TimeZoneStringContext::TIME() {
  return getToken(CentSqlParser::TIME, 0);
}

tree::TerminalNode* CentSqlParser::TimeZoneStringContext::ZONE() {
  return getToken(CentSqlParser::ZONE, 0);
}

CentSqlParser::StringContext* CentSqlParser::TimeZoneStringContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

CentSqlParser::TimeZoneStringContext::TimeZoneStringContext(TimeZoneSpecifierContext *ctx) { copyFrom(ctx); }

void CentSqlParser::TimeZoneStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeZoneString(this);
}
void CentSqlParser::TimeZoneStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeZoneString(this);
}

antlrcpp::Any CentSqlParser::TimeZoneStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTimeZoneString(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::TimeZoneSpecifierContext* CentSqlParser::timeZoneSpecifier() {
  TimeZoneSpecifierContext *_localctx = _tracker.createInstance<TimeZoneSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 72, CentSqlParser::RuleTimeZoneSpecifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<TimeZoneSpecifierContext *>(_tracker.createInstance<CentSqlParser::TimeZoneIntervalContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(1253);
      match(CentSqlParser::TIME);
      setState(1254);
      match(CentSqlParser::ZONE);
      setState(1255);
      interval();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<TimeZoneSpecifierContext *>(_tracker.createInstance<CentSqlParser::TimeZoneStringContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(1256);
      match(CentSqlParser::TIME);
      setState(1257);
      match(CentSqlParser::ZONE);
      setState(1258);
      string();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonOperatorContext ------------------------------------------------------------------

CentSqlParser::ComparisonOperatorContext::ComparisonOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::ComparisonOperatorContext::EQ() {
  return getToken(CentSqlParser::EQ, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonOperatorContext::NEQ() {
  return getToken(CentSqlParser::NEQ, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonOperatorContext::LT() {
  return getToken(CentSqlParser::LT, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonOperatorContext::LTE() {
  return getToken(CentSqlParser::LTE, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonOperatorContext::GT() {
  return getToken(CentSqlParser::GT, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonOperatorContext::GTE() {
  return getToken(CentSqlParser::GTE, 0);
}


size_t CentSqlParser::ComparisonOperatorContext::getRuleIndex() const {
  return CentSqlParser::RuleComparisonOperator;
}

void CentSqlParser::ComparisonOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonOperator(this);
}

void CentSqlParser::ComparisonOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonOperator(this);
}


antlrcpp::Any CentSqlParser::ComparisonOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitComparisonOperator(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::ComparisonOperatorContext* CentSqlParser::comparisonOperator() {
  ComparisonOperatorContext *_localctx = _tracker.createInstance<ComparisonOperatorContext>(_ctx, getState());
  enterRule(_localctx, 74, CentSqlParser::RuleComparisonOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1261);
    _la = _input->LA(1);
    if (!(((((_la - 191) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 191)) & ((1ULL << (CentSqlParser::EQ - 191))
      | (1ULL << (CentSqlParser::NEQ - 191))
      | (1ULL << (CentSqlParser::LT - 191))
      | (1ULL << (CentSqlParser::LTE - 191))
      | (1ULL << (CentSqlParser::GT - 191))
      | (1ULL << (CentSqlParser::GTE - 191)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonQuantifierContext ------------------------------------------------------------------

CentSqlParser::ComparisonQuantifierContext::ComparisonQuantifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::ComparisonQuantifierContext::ALL() {
  return getToken(CentSqlParser::ALL, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonQuantifierContext::SOME() {
  return getToken(CentSqlParser::SOME, 0);
}

tree::TerminalNode* CentSqlParser::ComparisonQuantifierContext::ANY() {
  return getToken(CentSqlParser::ANY, 0);
}


size_t CentSqlParser::ComparisonQuantifierContext::getRuleIndex() const {
  return CentSqlParser::RuleComparisonQuantifier;
}

void CentSqlParser::ComparisonQuantifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparisonQuantifier(this);
}

void CentSqlParser::ComparisonQuantifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparisonQuantifier(this);
}


antlrcpp::Any CentSqlParser::ComparisonQuantifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitComparisonQuantifier(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::ComparisonQuantifierContext* CentSqlParser::comparisonQuantifier() {
  ComparisonQuantifierContext *_localctx = _tracker.createInstance<ComparisonQuantifierContext>(_ctx, getState());
  enterRule(_localctx, 76, CentSqlParser::RuleComparisonQuantifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1263);
    _la = _input->LA(1);
    if (!(_la == CentSqlParser::ALL

    || _la == CentSqlParser::ANY || _la == CentSqlParser::SOME)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanValueContext ------------------------------------------------------------------

CentSqlParser::BooleanValueContext::BooleanValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::BooleanValueContext::TRUE_VALUE() {
  return getToken(CentSqlParser::TRUE_VALUE, 0);
}

tree::TerminalNode* CentSqlParser::BooleanValueContext::FALSE_VALUE() {
  return getToken(CentSqlParser::FALSE_VALUE, 0);
}


size_t CentSqlParser::BooleanValueContext::getRuleIndex() const {
  return CentSqlParser::RuleBooleanValue;
}

void CentSqlParser::BooleanValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanValue(this);
}

void CentSqlParser::BooleanValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanValue(this);
}


antlrcpp::Any CentSqlParser::BooleanValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBooleanValue(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::BooleanValueContext* CentSqlParser::booleanValue() {
  BooleanValueContext *_localctx = _tracker.createInstance<BooleanValueContext>(_ctx, getState());
  enterRule(_localctx, 78, CentSqlParser::RuleBooleanValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1265);
    _la = _input->LA(1);
    if (!(_la == CentSqlParser::FALSE_VALUE || _la == CentSqlParser::TRUE_VALUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntervalContext ------------------------------------------------------------------

CentSqlParser::IntervalContext::IntervalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::IntervalContext::INTERVAL() {
  return getToken(CentSqlParser::INTERVAL, 0);
}

CentSqlParser::StringContext* CentSqlParser::IntervalContext::string() {
  return getRuleContext<CentSqlParser::StringContext>(0);
}

std::vector<CentSqlParser::IntervalFieldContext *> CentSqlParser::IntervalContext::intervalField() {
  return getRuleContexts<CentSqlParser::IntervalFieldContext>();
}

CentSqlParser::IntervalFieldContext* CentSqlParser::IntervalContext::intervalField(size_t i) {
  return getRuleContext<CentSqlParser::IntervalFieldContext>(i);
}

tree::TerminalNode* CentSqlParser::IntervalContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

tree::TerminalNode* CentSqlParser::IntervalContext::PLUS() {
  return getToken(CentSqlParser::PLUS, 0);
}

tree::TerminalNode* CentSqlParser::IntervalContext::MINUS() {
  return getToken(CentSqlParser::MINUS, 0);
}


size_t CentSqlParser::IntervalContext::getRuleIndex() const {
  return CentSqlParser::RuleInterval;
}

void CentSqlParser::IntervalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterval(this);
}

void CentSqlParser::IntervalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterval(this);
}


antlrcpp::Any CentSqlParser::IntervalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitInterval(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::IntervalContext* CentSqlParser::interval() {
  IntervalContext *_localctx = _tracker.createInstance<IntervalContext>(_ctx, getState());
  enterRule(_localctx, 80, CentSqlParser::RuleInterval);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1267);
    match(CentSqlParser::INTERVAL);
    setState(1269);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::PLUS

    || _la == CentSqlParser::MINUS) {
      setState(1268);
      dynamic_cast<IntervalContext *>(_localctx)->sign = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::PLUS

      || _la == CentSqlParser::MINUS)) {
        dynamic_cast<IntervalContext *>(_localctx)->sign = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1271);
    string();
    setState(1272);
    dynamic_cast<IntervalContext *>(_localctx)->from = intervalField();
    setState(1275);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx)) {
    case 1: {
      setState(1273);
      match(CentSqlParser::TO);
      setState(1274);
      dynamic_cast<IntervalContext *>(_localctx)->to = intervalField();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntervalFieldContext ------------------------------------------------------------------

CentSqlParser::IntervalFieldContext::IntervalFieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::IntervalFieldContext::YEAR() {
  return getToken(CentSqlParser::YEAR, 0);
}

tree::TerminalNode* CentSqlParser::IntervalFieldContext::MONTH() {
  return getToken(CentSqlParser::MONTH, 0);
}

tree::TerminalNode* CentSqlParser::IntervalFieldContext::DAY() {
  return getToken(CentSqlParser::DAY, 0);
}

tree::TerminalNode* CentSqlParser::IntervalFieldContext::HOUR() {
  return getToken(CentSqlParser::HOUR, 0);
}

tree::TerminalNode* CentSqlParser::IntervalFieldContext::MINUTE() {
  return getToken(CentSqlParser::MINUTE, 0);
}

tree::TerminalNode* CentSqlParser::IntervalFieldContext::SECOND() {
  return getToken(CentSqlParser::SECOND, 0);
}


size_t CentSqlParser::IntervalFieldContext::getRuleIndex() const {
  return CentSqlParser::RuleIntervalField;
}

void CentSqlParser::IntervalFieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntervalField(this);
}

void CentSqlParser::IntervalFieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntervalField(this);
}


antlrcpp::Any CentSqlParser::IntervalFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitIntervalField(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::IntervalFieldContext* CentSqlParser::intervalField() {
  IntervalFieldContext *_localctx = _tracker.createInstance<IntervalFieldContext>(_ctx, getState());
  enterRule(_localctx, 82, CentSqlParser::RuleIntervalField);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1277);
    _la = _input->LA(1);
    if (!(((((_la - 45) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 45)) & ((1ULL << (CentSqlParser::DAY - 45))
      | (1ULL << (CentSqlParser::HOUR - 45))
      | (1ULL << (CentSqlParser::MINUTE - 45))
      | (1ULL << (CentSqlParser::MONTH - 45)))) != 0) || _la == CentSqlParser::SECOND

    || _la == CentSqlParser::YEAR)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NormalFormContext ------------------------------------------------------------------

CentSqlParser::NormalFormContext::NormalFormContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::NormalFormContext::NFD() {
  return getToken(CentSqlParser::NFD, 0);
}

tree::TerminalNode* CentSqlParser::NormalFormContext::NFC() {
  return getToken(CentSqlParser::NFC, 0);
}

tree::TerminalNode* CentSqlParser::NormalFormContext::NFKD() {
  return getToken(CentSqlParser::NFKD, 0);
}

tree::TerminalNode* CentSqlParser::NormalFormContext::NFKC() {
  return getToken(CentSqlParser::NFKC, 0);
}


size_t CentSqlParser::NormalFormContext::getRuleIndex() const {
  return CentSqlParser::RuleNormalForm;
}

void CentSqlParser::NormalFormContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNormalForm(this);
}

void CentSqlParser::NormalFormContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNormalForm(this);
}


antlrcpp::Any CentSqlParser::NormalFormContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNormalForm(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::NormalFormContext* CentSqlParser::normalForm() {
  NormalFormContext *_localctx = _tracker.createInstance<NormalFormContext>(_ctx, getState());
  enterRule(_localctx, 84, CentSqlParser::RuleNormalForm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1279);
    _la = _input->LA(1);
    if (!(((((_la - 105) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 105)) & ((1ULL << (CentSqlParser::NFC - 105))
      | (1ULL << (CentSqlParser::NFD - 105))
      | (1ULL << (CentSqlParser::NFKC - 105))
      | (1ULL << (CentSqlParser::NFKD - 105)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

CentSqlParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::TypeContext::ARRAY() {
  return getToken(CentSqlParser::ARRAY, 0);
}

std::vector<CentSqlParser::TypeContext *> CentSqlParser::TypeContext::type() {
  return getRuleContexts<CentSqlParser::TypeContext>();
}

CentSqlParser::TypeContext* CentSqlParser::TypeContext::type(size_t i) {
  return getRuleContext<CentSqlParser::TypeContext>(i);
}

tree::TerminalNode* CentSqlParser::TypeContext::MAP() {
  return getToken(CentSqlParser::MAP, 0);
}

tree::TerminalNode* CentSqlParser::TypeContext::ROW() {
  return getToken(CentSqlParser::ROW, 0);
}

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::TypeContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::TypeContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}

CentSqlParser::BaseTypeContext* CentSqlParser::TypeContext::baseType() {
  return getRuleContext<CentSqlParser::BaseTypeContext>(0);
}

std::vector<CentSqlParser::TypeParameterContext *> CentSqlParser::TypeContext::typeParameter() {
  return getRuleContexts<CentSqlParser::TypeParameterContext>();
}

CentSqlParser::TypeParameterContext* CentSqlParser::TypeContext::typeParameter(size_t i) {
  return getRuleContext<CentSqlParser::TypeParameterContext>(i);
}

tree::TerminalNode* CentSqlParser::TypeContext::INTERVAL() {
  return getToken(CentSqlParser::INTERVAL, 0);
}

tree::TerminalNode* CentSqlParser::TypeContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

std::vector<CentSqlParser::IntervalFieldContext *> CentSqlParser::TypeContext::intervalField() {
  return getRuleContexts<CentSqlParser::IntervalFieldContext>();
}

CentSqlParser::IntervalFieldContext* CentSqlParser::TypeContext::intervalField(size_t i) {
  return getRuleContext<CentSqlParser::IntervalFieldContext>(i);
}


size_t CentSqlParser::TypeContext::getRuleIndex() const {
  return CentSqlParser::RuleType;
}

void CentSqlParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void CentSqlParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any CentSqlParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}


CentSqlParser::TypeContext* CentSqlParser::type() {
   return type(0);
}

CentSqlParser::TypeContext* CentSqlParser::type(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CentSqlParser::TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, parentState);
  CentSqlParser::TypeContext *previousContext = _localctx;
  size_t startState = 86;
  enterRecursionRule(_localctx, 86, CentSqlParser::RuleType, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1328);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx)) {
    case 1: {
      setState(1282);
      match(CentSqlParser::ARRAY);
      setState(1283);
      match(CentSqlParser::LT);
      setState(1284);
      type(0);
      setState(1285);
      match(CentSqlParser::GT);
      break;
    }

    case 2: {
      setState(1287);
      match(CentSqlParser::MAP);
      setState(1288);
      match(CentSqlParser::LT);
      setState(1289);
      type(0);
      setState(1290);
      match(CentSqlParser::T__3);
      setState(1291);
      type(0);
      setState(1292);
      match(CentSqlParser::GT);
      break;
    }

    case 3: {
      setState(1294);
      match(CentSqlParser::ROW);
      setState(1295);
      match(CentSqlParser::T__1);
      setState(1296);
      identifier();
      setState(1297);
      type(0);
      setState(1304);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(1298);
        match(CentSqlParser::T__3);
        setState(1299);
        identifier();
        setState(1300);
        type(0);
        setState(1306);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1307);
      match(CentSqlParser::T__2);
      break;
    }

    case 4: {
      setState(1309);
      baseType();
      setState(1321);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx)) {
      case 1: {
        setState(1310);
        match(CentSqlParser::T__1);
        setState(1311);
        typeParameter();
        setState(1316);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == CentSqlParser::T__3) {
          setState(1312);
          match(CentSqlParser::T__3);
          setState(1313);
          typeParameter();
          setState(1318);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1319);
        match(CentSqlParser::T__2);
        break;
      }

      }
      break;
    }

    case 5: {
      setState(1323);
      match(CentSqlParser::INTERVAL);
      setState(1324);
      dynamic_cast<TypeContext *>(_localctx)->from = intervalField();
      setState(1325);
      match(CentSqlParser::TO);
      setState(1326);
      dynamic_cast<TypeContext *>(_localctx)->to = intervalField();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1334);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleType);
        setState(1330);

        if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
        setState(1331);
        match(CentSqlParser::ARRAY); 
      }
      setState(1336);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TypeParameterContext ------------------------------------------------------------------

CentSqlParser::TypeParameterContext::TypeParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::TypeParameterContext::INTEGER_VALUE() {
  return getToken(CentSqlParser::INTEGER_VALUE, 0);
}

CentSqlParser::TypeContext* CentSqlParser::TypeParameterContext::type() {
  return getRuleContext<CentSqlParser::TypeContext>(0);
}


size_t CentSqlParser::TypeParameterContext::getRuleIndex() const {
  return CentSqlParser::RuleTypeParameter;
}

void CentSqlParser::TypeParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeParameter(this);
}

void CentSqlParser::TypeParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeParameter(this);
}


antlrcpp::Any CentSqlParser::TypeParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTypeParameter(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::TypeParameterContext* CentSqlParser::typeParameter() {
  TypeParameterContext *_localctx = _tracker.createInstance<TypeParameterContext>(_ctx, getState());
  enterRule(_localctx, 88, CentSqlParser::RuleTypeParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1339);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::INTEGER_VALUE: {
        enterOuterAlt(_localctx, 1);
        setState(1337);
        match(CentSqlParser::INTEGER_VALUE);
        break;
      }

      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE:
      case CentSqlParser::IDENTIFIER:
      case CentSqlParser::DIGIT_IDENTIFIER:
      case CentSqlParser::QUOTED_IDENTIFIER:
      case CentSqlParser::BACKQUOTED_IDENTIFIER:
      case CentSqlParser::TIME_WITH_TIME_ZONE:
      case CentSqlParser::TIMESTAMP_WITH_TIME_ZONE:
      case CentSqlParser::DOUBLE_PRECISION: {
        enterOuterAlt(_localctx, 2);
        setState(1338);
        type(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseTypeContext ------------------------------------------------------------------

CentSqlParser::BaseTypeContext::BaseTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::BaseTypeContext::TIME_WITH_TIME_ZONE() {
  return getToken(CentSqlParser::TIME_WITH_TIME_ZONE, 0);
}

tree::TerminalNode* CentSqlParser::BaseTypeContext::TIMESTAMP_WITH_TIME_ZONE() {
  return getToken(CentSqlParser::TIMESTAMP_WITH_TIME_ZONE, 0);
}

tree::TerminalNode* CentSqlParser::BaseTypeContext::DOUBLE_PRECISION() {
  return getToken(CentSqlParser::DOUBLE_PRECISION, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::BaseTypeContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}


size_t CentSqlParser::BaseTypeContext::getRuleIndex() const {
  return CentSqlParser::RuleBaseType;
}

void CentSqlParser::BaseTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseType(this);
}

void CentSqlParser::BaseTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseType(this);
}


antlrcpp::Any CentSqlParser::BaseTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBaseType(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::BaseTypeContext* CentSqlParser::baseType() {
  BaseTypeContext *_localctx = _tracker.createInstance<BaseTypeContext>(_ctx, getState());
  enterRule(_localctx, 90, CentSqlParser::RuleBaseType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::TIME_WITH_TIME_ZONE: {
        enterOuterAlt(_localctx, 1);
        setState(1341);
        match(CentSqlParser::TIME_WITH_TIME_ZONE);
        break;
      }

      case CentSqlParser::TIMESTAMP_WITH_TIME_ZONE: {
        enterOuterAlt(_localctx, 2);
        setState(1342);
        match(CentSqlParser::TIMESTAMP_WITH_TIME_ZONE);
        break;
      }

      case CentSqlParser::DOUBLE_PRECISION: {
        enterOuterAlt(_localctx, 3);
        setState(1343);
        match(CentSqlParser::DOUBLE_PRECISION);
        break;
      }

      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE:
      case CentSqlParser::IDENTIFIER:
      case CentSqlParser::DIGIT_IDENTIFIER:
      case CentSqlParser::QUOTED_IDENTIFIER:
      case CentSqlParser::BACKQUOTED_IDENTIFIER: {
        enterOuterAlt(_localctx, 4);
        setState(1344);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhenClauseContext ------------------------------------------------------------------

CentSqlParser::WhenClauseContext::WhenClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::WhenClauseContext::WHEN() {
  return getToken(CentSqlParser::WHEN, 0);
}

tree::TerminalNode* CentSqlParser::WhenClauseContext::THEN() {
  return getToken(CentSqlParser::THEN, 0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::WhenClauseContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::WhenClauseContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}


size_t CentSqlParser::WhenClauseContext::getRuleIndex() const {
  return CentSqlParser::RuleWhenClause;
}

void CentSqlParser::WhenClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhenClause(this);
}

void CentSqlParser::WhenClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhenClause(this);
}


antlrcpp::Any CentSqlParser::WhenClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitWhenClause(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::WhenClauseContext* CentSqlParser::whenClause() {
  WhenClauseContext *_localctx = _tracker.createInstance<WhenClauseContext>(_ctx, getState());
  enterRule(_localctx, 92, CentSqlParser::RuleWhenClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1347);
    match(CentSqlParser::WHEN);
    setState(1348);
    dynamic_cast<WhenClauseContext *>(_localctx)->condition = expression();
    setState(1349);
    match(CentSqlParser::THEN);
    setState(1350);
    dynamic_cast<WhenClauseContext *>(_localctx)->result = expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FilterContext ------------------------------------------------------------------

CentSqlParser::FilterContext::FilterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::FilterContext::FILTER() {
  return getToken(CentSqlParser::FILTER, 0);
}

tree::TerminalNode* CentSqlParser::FilterContext::WHERE() {
  return getToken(CentSqlParser::WHERE, 0);
}

CentSqlParser::BooleanExpressionContext* CentSqlParser::FilterContext::booleanExpression() {
  return getRuleContext<CentSqlParser::BooleanExpressionContext>(0);
}


size_t CentSqlParser::FilterContext::getRuleIndex() const {
  return CentSqlParser::RuleFilter;
}

void CentSqlParser::FilterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilter(this);
}

void CentSqlParser::FilterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilter(this);
}


antlrcpp::Any CentSqlParser::FilterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitFilter(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::FilterContext* CentSqlParser::filter() {
  FilterContext *_localctx = _tracker.createInstance<FilterContext>(_ctx, getState());
  enterRule(_localctx, 94, CentSqlParser::RuleFilter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1352);
    match(CentSqlParser::FILTER);
    setState(1353);
    match(CentSqlParser::T__1);
    setState(1354);
    match(CentSqlParser::WHERE);
    setState(1355);
    booleanExpression(0);
    setState(1356);
    match(CentSqlParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OverContext ------------------------------------------------------------------

CentSqlParser::OverContext::OverContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::OverContext::OVER() {
  return getToken(CentSqlParser::OVER, 0);
}

tree::TerminalNode* CentSqlParser::OverContext::PARTITION() {
  return getToken(CentSqlParser::PARTITION, 0);
}

std::vector<tree::TerminalNode *> CentSqlParser::OverContext::BY() {
  return getTokens(CentSqlParser::BY);
}

tree::TerminalNode* CentSqlParser::OverContext::BY(size_t i) {
  return getToken(CentSqlParser::BY, i);
}

tree::TerminalNode* CentSqlParser::OverContext::ORDER() {
  return getToken(CentSqlParser::ORDER, 0);
}

std::vector<CentSqlParser::SortItemContext *> CentSqlParser::OverContext::sortItem() {
  return getRuleContexts<CentSqlParser::SortItemContext>();
}

CentSqlParser::SortItemContext* CentSqlParser::OverContext::sortItem(size_t i) {
  return getRuleContext<CentSqlParser::SortItemContext>(i);
}

CentSqlParser::WindowFrameContext* CentSqlParser::OverContext::windowFrame() {
  return getRuleContext<CentSqlParser::WindowFrameContext>(0);
}

std::vector<CentSqlParser::ExpressionContext *> CentSqlParser::OverContext::expression() {
  return getRuleContexts<CentSqlParser::ExpressionContext>();
}

CentSqlParser::ExpressionContext* CentSqlParser::OverContext::expression(size_t i) {
  return getRuleContext<CentSqlParser::ExpressionContext>(i);
}


size_t CentSqlParser::OverContext::getRuleIndex() const {
  return CentSqlParser::RuleOver;
}

void CentSqlParser::OverContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOver(this);
}

void CentSqlParser::OverContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOver(this);
}


antlrcpp::Any CentSqlParser::OverContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitOver(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::OverContext* CentSqlParser::over() {
  OverContext *_localctx = _tracker.createInstance<OverContext>(_ctx, getState());
  enterRule(_localctx, 96, CentSqlParser::RuleOver);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1358);
    match(CentSqlParser::OVER);
    setState(1359);
    match(CentSqlParser::T__1);
    setState(1370);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::PARTITION) {
      setState(1360);
      match(CentSqlParser::PARTITION);
      setState(1361);
      match(CentSqlParser::BY);
      setState(1362);
      dynamic_cast<OverContext *>(_localctx)->expressionContext = expression();
      dynamic_cast<OverContext *>(_localctx)->partition.push_back(dynamic_cast<OverContext *>(_localctx)->expressionContext);
      setState(1367);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(1363);
        match(CentSqlParser::T__3);
        setState(1364);
        dynamic_cast<OverContext *>(_localctx)->expressionContext = expression();
        dynamic_cast<OverContext *>(_localctx)->partition.push_back(dynamic_cast<OverContext *>(_localctx)->expressionContext);
        setState(1369);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1382);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::ORDER) {
      setState(1372);
      match(CentSqlParser::ORDER);
      setState(1373);
      match(CentSqlParser::BY);
      setState(1374);
      sortItem();
      setState(1379);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CentSqlParser::T__3) {
        setState(1375);
        match(CentSqlParser::T__3);
        setState(1376);
        sortItem();
        setState(1381);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1385);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CentSqlParser::RANGE

    || _la == CentSqlParser::ROWS) {
      setState(1384);
      windowFrame();
    }
    setState(1387);
    match(CentSqlParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WindowFrameContext ------------------------------------------------------------------

CentSqlParser::WindowFrameContext::WindowFrameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::WindowFrameContext::RANGE() {
  return getToken(CentSqlParser::RANGE, 0);
}

std::vector<CentSqlParser::FrameBoundContext *> CentSqlParser::WindowFrameContext::frameBound() {
  return getRuleContexts<CentSqlParser::FrameBoundContext>();
}

CentSqlParser::FrameBoundContext* CentSqlParser::WindowFrameContext::frameBound(size_t i) {
  return getRuleContext<CentSqlParser::FrameBoundContext>(i);
}

tree::TerminalNode* CentSqlParser::WindowFrameContext::ROWS() {
  return getToken(CentSqlParser::ROWS, 0);
}

tree::TerminalNode* CentSqlParser::WindowFrameContext::BETWEEN() {
  return getToken(CentSqlParser::BETWEEN, 0);
}

tree::TerminalNode* CentSqlParser::WindowFrameContext::AND() {
  return getToken(CentSqlParser::AND, 0);
}


size_t CentSqlParser::WindowFrameContext::getRuleIndex() const {
  return CentSqlParser::RuleWindowFrame;
}

void CentSqlParser::WindowFrameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWindowFrame(this);
}

void CentSqlParser::WindowFrameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWindowFrame(this);
}


antlrcpp::Any CentSqlParser::WindowFrameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitWindowFrame(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::WindowFrameContext* CentSqlParser::windowFrame() {
  WindowFrameContext *_localctx = _tracker.createInstance<WindowFrameContext>(_ctx, getState());
  enterRule(_localctx, 98, CentSqlParser::RuleWindowFrame);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1389);
      dynamic_cast<WindowFrameContext *>(_localctx)->frameType = match(CentSqlParser::RANGE);
      setState(1390);
      dynamic_cast<WindowFrameContext *>(_localctx)->start = frameBound();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1391);
      dynamic_cast<WindowFrameContext *>(_localctx)->frameType = match(CentSqlParser::ROWS);
      setState(1392);
      dynamic_cast<WindowFrameContext *>(_localctx)->start = frameBound();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1393);
      dynamic_cast<WindowFrameContext *>(_localctx)->frameType = match(CentSqlParser::RANGE);
      setState(1394);
      match(CentSqlParser::BETWEEN);
      setState(1395);
      dynamic_cast<WindowFrameContext *>(_localctx)->start = frameBound();
      setState(1396);
      match(CentSqlParser::AND);
      setState(1397);
      dynamic_cast<WindowFrameContext *>(_localctx)->end = frameBound();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1399);
      dynamic_cast<WindowFrameContext *>(_localctx)->frameType = match(CentSqlParser::ROWS);
      setState(1400);
      match(CentSqlParser::BETWEEN);
      setState(1401);
      dynamic_cast<WindowFrameContext *>(_localctx)->start = frameBound();
      setState(1402);
      match(CentSqlParser::AND);
      setState(1403);
      dynamic_cast<WindowFrameContext *>(_localctx)->end = frameBound();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FrameBoundContext ------------------------------------------------------------------

CentSqlParser::FrameBoundContext::FrameBoundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::FrameBoundContext::getRuleIndex() const {
  return CentSqlParser::RuleFrameBound;
}

void CentSqlParser::FrameBoundContext::copyFrom(FrameBoundContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BoundedFrameContext ------------------------------------------------------------------

CentSqlParser::ExpressionContext* CentSqlParser::BoundedFrameContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

tree::TerminalNode* CentSqlParser::BoundedFrameContext::PRECEDING() {
  return getToken(CentSqlParser::PRECEDING, 0);
}

tree::TerminalNode* CentSqlParser::BoundedFrameContext::FOLLOWING() {
  return getToken(CentSqlParser::FOLLOWING, 0);
}

CentSqlParser::BoundedFrameContext::BoundedFrameContext(FrameBoundContext *ctx) { copyFrom(ctx); }

void CentSqlParser::BoundedFrameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoundedFrame(this);
}
void CentSqlParser::BoundedFrameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoundedFrame(this);
}

antlrcpp::Any CentSqlParser::BoundedFrameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBoundedFrame(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnboundedFrameContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::UnboundedFrameContext::UNBOUNDED() {
  return getToken(CentSqlParser::UNBOUNDED, 0);
}

tree::TerminalNode* CentSqlParser::UnboundedFrameContext::PRECEDING() {
  return getToken(CentSqlParser::PRECEDING, 0);
}

tree::TerminalNode* CentSqlParser::UnboundedFrameContext::FOLLOWING() {
  return getToken(CentSqlParser::FOLLOWING, 0);
}

CentSqlParser::UnboundedFrameContext::UnboundedFrameContext(FrameBoundContext *ctx) { copyFrom(ctx); }

void CentSqlParser::UnboundedFrameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnboundedFrame(this);
}
void CentSqlParser::UnboundedFrameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnboundedFrame(this);
}

antlrcpp::Any CentSqlParser::UnboundedFrameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitUnboundedFrame(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CurrentRowBoundContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::CurrentRowBoundContext::CURRENT() {
  return getToken(CentSqlParser::CURRENT, 0);
}

tree::TerminalNode* CentSqlParser::CurrentRowBoundContext::ROW() {
  return getToken(CentSqlParser::ROW, 0);
}

CentSqlParser::CurrentRowBoundContext::CurrentRowBoundContext(FrameBoundContext *ctx) { copyFrom(ctx); }

void CentSqlParser::CurrentRowBoundContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCurrentRowBound(this);
}
void CentSqlParser::CurrentRowBoundContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCurrentRowBound(this);
}

antlrcpp::Any CentSqlParser::CurrentRowBoundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitCurrentRowBound(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::FrameBoundContext* CentSqlParser::frameBound() {
  FrameBoundContext *_localctx = _tracker.createInstance<FrameBoundContext>(_ctx, getState());
  enterRule(_localctx, 100, CentSqlParser::RuleFrameBound);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1416);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FrameBoundContext *>(_tracker.createInstance<CentSqlParser::UnboundedFrameContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(1407);
      match(CentSqlParser::UNBOUNDED);
      setState(1408);
      dynamic_cast<UnboundedFrameContext *>(_localctx)->boundType = match(CentSqlParser::PRECEDING);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FrameBoundContext *>(_tracker.createInstance<CentSqlParser::UnboundedFrameContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(1409);
      match(CentSqlParser::UNBOUNDED);
      setState(1410);
      dynamic_cast<UnboundedFrameContext *>(_localctx)->boundType = match(CentSqlParser::FOLLOWING);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FrameBoundContext *>(_tracker.createInstance<CentSqlParser::CurrentRowBoundContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(1411);
      match(CentSqlParser::CURRENT);
      setState(1412);
      match(CentSqlParser::ROW);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FrameBoundContext *>(_tracker.createInstance<CentSqlParser::BoundedFrameContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(1413);
      expression();
      setState(1414);
      dynamic_cast<BoundedFrameContext *>(_localctx)->boundType = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == CentSqlParser::FOLLOWING

      || _la == CentSqlParser::PRECEDING)) {
        dynamic_cast<BoundedFrameContext *>(_localctx)->boundType = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExplainOptionContext ------------------------------------------------------------------

CentSqlParser::ExplainOptionContext::ExplainOptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::ExplainOptionContext::getRuleIndex() const {
  return CentSqlParser::RuleExplainOption;
}

void CentSqlParser::ExplainOptionContext::copyFrom(ExplainOptionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExplainFormatContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ExplainFormatContext::FORMAT() {
  return getToken(CentSqlParser::FORMAT, 0);
}

tree::TerminalNode* CentSqlParser::ExplainFormatContext::TEXT() {
  return getToken(CentSqlParser::TEXT, 0);
}

tree::TerminalNode* CentSqlParser::ExplainFormatContext::GRAPHVIZ() {
  return getToken(CentSqlParser::GRAPHVIZ, 0);
}

tree::TerminalNode* CentSqlParser::ExplainFormatContext::JSON() {
  return getToken(CentSqlParser::JSON, 0);
}

CentSqlParser::ExplainFormatContext::ExplainFormatContext(ExplainOptionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ExplainFormatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplainFormat(this);
}
void CentSqlParser::ExplainFormatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplainFormat(this);
}

antlrcpp::Any CentSqlParser::ExplainFormatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExplainFormat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExplainTypeContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ExplainTypeContext::TYPE() {
  return getToken(CentSqlParser::TYPE, 0);
}

tree::TerminalNode* CentSqlParser::ExplainTypeContext::LOGICAL() {
  return getToken(CentSqlParser::LOGICAL, 0);
}

tree::TerminalNode* CentSqlParser::ExplainTypeContext::DISTRIBUTED() {
  return getToken(CentSqlParser::DISTRIBUTED, 0);
}

tree::TerminalNode* CentSqlParser::ExplainTypeContext::VALIDATE() {
  return getToken(CentSqlParser::VALIDATE, 0);
}

tree::TerminalNode* CentSqlParser::ExplainTypeContext::IO() {
  return getToken(CentSqlParser::IO, 0);
}

CentSqlParser::ExplainTypeContext::ExplainTypeContext(ExplainOptionContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ExplainTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExplainType(this);
}
void CentSqlParser::ExplainTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExplainType(this);
}

antlrcpp::Any CentSqlParser::ExplainTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitExplainType(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::ExplainOptionContext* CentSqlParser::explainOption() {
  ExplainOptionContext *_localctx = _tracker.createInstance<ExplainOptionContext>(_ctx, getState());
  enterRule(_localctx, 102, CentSqlParser::RuleExplainOption);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1422);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::FORMAT: {
        _localctx = dynamic_cast<ExplainOptionContext *>(_tracker.createInstance<CentSqlParser::ExplainFormatContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(1418);
        match(CentSqlParser::FORMAT);
        setState(1419);
        dynamic_cast<ExplainFormatContext *>(_localctx)->value = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CentSqlParser::GRAPHVIZ

        || _la == CentSqlParser::JSON || _la == CentSqlParser::TEXT)) {
          dynamic_cast<ExplainFormatContext *>(_localctx)->value = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case CentSqlParser::TYPE: {
        _localctx = dynamic_cast<ExplainOptionContext *>(_tracker.createInstance<CentSqlParser::ExplainTypeContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(1420);
        match(CentSqlParser::TYPE);
        setState(1421);
        dynamic_cast<ExplainTypeContext *>(_localctx)->value = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 51)) & ((1ULL << (CentSqlParser::DISTRIBUTED - 51))
          | (1ULL << (CentSqlParser::IO - 51))
          | (1ULL << (CentSqlParser::LOGICAL - 51)))) != 0) || _la == CentSqlParser::VALIDATE)) {
          dynamic_cast<ExplainTypeContext *>(_localctx)->value = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TransactionModeContext ------------------------------------------------------------------

CentSqlParser::TransactionModeContext::TransactionModeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::TransactionModeContext::getRuleIndex() const {
  return CentSqlParser::RuleTransactionMode;
}

void CentSqlParser::TransactionModeContext::copyFrom(TransactionModeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TransactionAccessModeContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::TransactionAccessModeContext::READ() {
  return getToken(CentSqlParser::READ, 0);
}

tree::TerminalNode* CentSqlParser::TransactionAccessModeContext::ONLY() {
  return getToken(CentSqlParser::ONLY, 0);
}

tree::TerminalNode* CentSqlParser::TransactionAccessModeContext::WRITE() {
  return getToken(CentSqlParser::WRITE, 0);
}

CentSqlParser::TransactionAccessModeContext::TransactionAccessModeContext(TransactionModeContext *ctx) { copyFrom(ctx); }

void CentSqlParser::TransactionAccessModeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransactionAccessMode(this);
}
void CentSqlParser::TransactionAccessModeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransactionAccessMode(this);
}

antlrcpp::Any CentSqlParser::TransactionAccessModeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitTransactionAccessMode(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IsolationLevelContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::IsolationLevelContext::ISOLATION() {
  return getToken(CentSqlParser::ISOLATION, 0);
}

tree::TerminalNode* CentSqlParser::IsolationLevelContext::LEVEL() {
  return getToken(CentSqlParser::LEVEL, 0);
}

CentSqlParser::LevelOfIsolationContext* CentSqlParser::IsolationLevelContext::levelOfIsolation() {
  return getRuleContext<CentSqlParser::LevelOfIsolationContext>(0);
}

CentSqlParser::IsolationLevelContext::IsolationLevelContext(TransactionModeContext *ctx) { copyFrom(ctx); }

void CentSqlParser::IsolationLevelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsolationLevel(this);
}
void CentSqlParser::IsolationLevelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsolationLevel(this);
}

antlrcpp::Any CentSqlParser::IsolationLevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitIsolationLevel(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::TransactionModeContext* CentSqlParser::transactionMode() {
  TransactionModeContext *_localctx = _tracker.createInstance<TransactionModeContext>(_ctx, getState());
  enterRule(_localctx, 104, CentSqlParser::RuleTransactionMode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1429);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::ISOLATION: {
        _localctx = dynamic_cast<TransactionModeContext *>(_tracker.createInstance<CentSqlParser::IsolationLevelContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(1424);
        match(CentSqlParser::ISOLATION);
        setState(1425);
        match(CentSqlParser::LEVEL);
        setState(1426);
        levelOfIsolation();
        break;
      }

      case CentSqlParser::READ: {
        _localctx = dynamic_cast<TransactionModeContext *>(_tracker.createInstance<CentSqlParser::TransactionAccessModeContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(1427);
        match(CentSqlParser::READ);
        setState(1428);
        dynamic_cast<TransactionAccessModeContext *>(_localctx)->accessMode = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == CentSqlParser::ONLY || _la == CentSqlParser::WRITE)) {
          dynamic_cast<TransactionAccessModeContext *>(_localctx)->accessMode = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LevelOfIsolationContext ------------------------------------------------------------------

CentSqlParser::LevelOfIsolationContext::LevelOfIsolationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::LevelOfIsolationContext::getRuleIndex() const {
  return CentSqlParser::RuleLevelOfIsolation;
}

void CentSqlParser::LevelOfIsolationContext::copyFrom(LevelOfIsolationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ReadUncommittedContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ReadUncommittedContext::READ() {
  return getToken(CentSqlParser::READ, 0);
}

tree::TerminalNode* CentSqlParser::ReadUncommittedContext::UNCOMMITTED() {
  return getToken(CentSqlParser::UNCOMMITTED, 0);
}

CentSqlParser::ReadUncommittedContext::ReadUncommittedContext(LevelOfIsolationContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ReadUncommittedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadUncommitted(this);
}
void CentSqlParser::ReadUncommittedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadUncommitted(this);
}

antlrcpp::Any CentSqlParser::ReadUncommittedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitReadUncommitted(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SerializableContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::SerializableContext::SERIALIZABLE() {
  return getToken(CentSqlParser::SERIALIZABLE, 0);
}

CentSqlParser::SerializableContext::SerializableContext(LevelOfIsolationContext *ctx) { copyFrom(ctx); }

void CentSqlParser::SerializableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSerializable(this);
}
void CentSqlParser::SerializableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSerializable(this);
}

antlrcpp::Any CentSqlParser::SerializableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitSerializable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadCommittedContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::ReadCommittedContext::READ() {
  return getToken(CentSqlParser::READ, 0);
}

tree::TerminalNode* CentSqlParser::ReadCommittedContext::COMMITTED() {
  return getToken(CentSqlParser::COMMITTED, 0);
}

CentSqlParser::ReadCommittedContext::ReadCommittedContext(LevelOfIsolationContext *ctx) { copyFrom(ctx); }

void CentSqlParser::ReadCommittedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadCommitted(this);
}
void CentSqlParser::ReadCommittedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadCommitted(this);
}

antlrcpp::Any CentSqlParser::ReadCommittedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitReadCommitted(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RepeatableReadContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::RepeatableReadContext::REPEATABLE() {
  return getToken(CentSqlParser::REPEATABLE, 0);
}

tree::TerminalNode* CentSqlParser::RepeatableReadContext::READ() {
  return getToken(CentSqlParser::READ, 0);
}

CentSqlParser::RepeatableReadContext::RepeatableReadContext(LevelOfIsolationContext *ctx) { copyFrom(ctx); }

void CentSqlParser::RepeatableReadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRepeatableRead(this);
}
void CentSqlParser::RepeatableReadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRepeatableRead(this);
}

antlrcpp::Any CentSqlParser::RepeatableReadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitRepeatableRead(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::LevelOfIsolationContext* CentSqlParser::levelOfIsolation() {
  LevelOfIsolationContext *_localctx = _tracker.createInstance<LevelOfIsolationContext>(_ctx, getState());
  enterRule(_localctx, 106, CentSqlParser::RuleLevelOfIsolation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1438);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 175, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LevelOfIsolationContext *>(_tracker.createInstance<CentSqlParser::ReadUncommittedContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(1431);
      match(CentSqlParser::READ);
      setState(1432);
      match(CentSqlParser::UNCOMMITTED);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LevelOfIsolationContext *>(_tracker.createInstance<CentSqlParser::ReadCommittedContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(1433);
      match(CentSqlParser::READ);
      setState(1434);
      match(CentSqlParser::COMMITTED);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LevelOfIsolationContext *>(_tracker.createInstance<CentSqlParser::RepeatableReadContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(1435);
      match(CentSqlParser::REPEATABLE);
      setState(1436);
      match(CentSqlParser::READ);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<LevelOfIsolationContext *>(_tracker.createInstance<CentSqlParser::SerializableContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(1437);
      match(CentSqlParser::SERIALIZABLE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallArgumentContext ------------------------------------------------------------------

CentSqlParser::CallArgumentContext::CallArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::CallArgumentContext::getRuleIndex() const {
  return CentSqlParser::RuleCallArgument;
}

void CentSqlParser::CallArgumentContext::copyFrom(CallArgumentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PositionalArgumentContext ------------------------------------------------------------------

CentSqlParser::ExpressionContext* CentSqlParser::PositionalArgumentContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::PositionalArgumentContext::PositionalArgumentContext(CallArgumentContext *ctx) { copyFrom(ctx); }

void CentSqlParser::PositionalArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositionalArgument(this);
}
void CentSqlParser::PositionalArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositionalArgument(this);
}

antlrcpp::Any CentSqlParser::PositionalArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitPositionalArgument(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NamedArgumentContext ------------------------------------------------------------------

CentSqlParser::IdentifierContext* CentSqlParser::NamedArgumentContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::ExpressionContext* CentSqlParser::NamedArgumentContext::expression() {
  return getRuleContext<CentSqlParser::ExpressionContext>(0);
}

CentSqlParser::NamedArgumentContext::NamedArgumentContext(CallArgumentContext *ctx) { copyFrom(ctx); }

void CentSqlParser::NamedArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNamedArgument(this);
}
void CentSqlParser::NamedArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNamedArgument(this);
}

antlrcpp::Any CentSqlParser::NamedArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNamedArgument(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::CallArgumentContext* CentSqlParser::callArgument() {
  CallArgumentContext *_localctx = _tracker.createInstance<CallArgumentContext>(_ctx, getState());
  enterRule(_localctx, 108, CentSqlParser::RuleCallArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1445);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 176, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<CallArgumentContext *>(_tracker.createInstance<CentSqlParser::PositionalArgumentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(1440);
      expression();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<CallArgumentContext *>(_tracker.createInstance<CentSqlParser::NamedArgumentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(1441);
      identifier();
      setState(1442);
      match(CentSqlParser::T__8);
      setState(1443);
      expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathElementContext ------------------------------------------------------------------

CentSqlParser::PathElementContext::PathElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::PathElementContext::getRuleIndex() const {
  return CentSqlParser::RulePathElement;
}

void CentSqlParser::PathElementContext::copyFrom(PathElementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- QualifiedArgumentContext ------------------------------------------------------------------

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::QualifiedArgumentContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::QualifiedArgumentContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}

CentSqlParser::QualifiedArgumentContext::QualifiedArgumentContext(PathElementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::QualifiedArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedArgument(this);
}
void CentSqlParser::QualifiedArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedArgument(this);
}

antlrcpp::Any CentSqlParser::QualifiedArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQualifiedArgument(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnqualifiedArgumentContext ------------------------------------------------------------------

CentSqlParser::IdentifierContext* CentSqlParser::UnqualifiedArgumentContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}

CentSqlParser::UnqualifiedArgumentContext::UnqualifiedArgumentContext(PathElementContext *ctx) { copyFrom(ctx); }

void CentSqlParser::UnqualifiedArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnqualifiedArgument(this);
}
void CentSqlParser::UnqualifiedArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnqualifiedArgument(this);
}

antlrcpp::Any CentSqlParser::UnqualifiedArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitUnqualifiedArgument(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::PathElementContext* CentSqlParser::pathElement() {
  PathElementContext *_localctx = _tracker.createInstance<PathElementContext>(_ctx, getState());
  enterRule(_localctx, 110, CentSqlParser::RulePathElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1452);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 177, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<PathElementContext *>(_tracker.createInstance<CentSqlParser::QualifiedArgumentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(1447);
      identifier();
      setState(1448);
      match(CentSqlParser::T__0);
      setState(1449);
      identifier();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<PathElementContext *>(_tracker.createInstance<CentSqlParser::UnqualifiedArgumentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(1451);
      identifier();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathSpecificationContext ------------------------------------------------------------------

CentSqlParser::PathSpecificationContext::PathSpecificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CentSqlParser::PathElementContext *> CentSqlParser::PathSpecificationContext::pathElement() {
  return getRuleContexts<CentSqlParser::PathElementContext>();
}

CentSqlParser::PathElementContext* CentSqlParser::PathSpecificationContext::pathElement(size_t i) {
  return getRuleContext<CentSqlParser::PathElementContext>(i);
}


size_t CentSqlParser::PathSpecificationContext::getRuleIndex() const {
  return CentSqlParser::RulePathSpecification;
}

void CentSqlParser::PathSpecificationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathSpecification(this);
}

void CentSqlParser::PathSpecificationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathSpecification(this);
}


antlrcpp::Any CentSqlParser::PathSpecificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitPathSpecification(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::PathSpecificationContext* CentSqlParser::pathSpecification() {
  PathSpecificationContext *_localctx = _tracker.createInstance<PathSpecificationContext>(_ctx, getState());
  enterRule(_localctx, 112, CentSqlParser::RulePathSpecification);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1454);
    pathElement();
    setState(1459);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CentSqlParser::T__3) {
      setState(1455);
      match(CentSqlParser::T__3);
      setState(1456);
      pathElement();
      setState(1461);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrivilegeContext ------------------------------------------------------------------

CentSqlParser::PrivilegeContext::PrivilegeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::PrivilegeContext::SELECT() {
  return getToken(CentSqlParser::SELECT, 0);
}

tree::TerminalNode* CentSqlParser::PrivilegeContext::DELETE() {
  return getToken(CentSqlParser::DELETE, 0);
}

tree::TerminalNode* CentSqlParser::PrivilegeContext::INSERT() {
  return getToken(CentSqlParser::INSERT, 0);
}

CentSqlParser::IdentifierContext* CentSqlParser::PrivilegeContext::identifier() {
  return getRuleContext<CentSqlParser::IdentifierContext>(0);
}


size_t CentSqlParser::PrivilegeContext::getRuleIndex() const {
  return CentSqlParser::RulePrivilege;
}

void CentSqlParser::PrivilegeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrivilege(this);
}

void CentSqlParser::PrivilegeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrivilege(this);
}


antlrcpp::Any CentSqlParser::PrivilegeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitPrivilege(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::PrivilegeContext* CentSqlParser::privilege() {
  PrivilegeContext *_localctx = _tracker.createInstance<PrivilegeContext>(_ctx, getState());
  enterRule(_localctx, 114, CentSqlParser::RulePrivilege);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1466);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(1462);
        match(CentSqlParser::SELECT);
        break;
      }

      case CentSqlParser::DELETE: {
        enterOuterAlt(_localctx, 2);
        setState(1463);
        match(CentSqlParser::DELETE);
        break;
      }

      case CentSqlParser::INSERT: {
        enterOuterAlt(_localctx, 3);
        setState(1464);
        match(CentSqlParser::INSERT);
        break;
      }

      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE:
      case CentSqlParser::IDENTIFIER:
      case CentSqlParser::DIGIT_IDENTIFIER:
      case CentSqlParser::QUOTED_IDENTIFIER:
      case CentSqlParser::BACKQUOTED_IDENTIFIER: {
        enterOuterAlt(_localctx, 4);
        setState(1465);
        identifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedNameContext ------------------------------------------------------------------

CentSqlParser::QualifiedNameContext::QualifiedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CentSqlParser::IdentifierContext *> CentSqlParser::QualifiedNameContext::identifier() {
  return getRuleContexts<CentSqlParser::IdentifierContext>();
}

CentSqlParser::IdentifierContext* CentSqlParser::QualifiedNameContext::identifier(size_t i) {
  return getRuleContext<CentSqlParser::IdentifierContext>(i);
}


size_t CentSqlParser::QualifiedNameContext::getRuleIndex() const {
  return CentSqlParser::RuleQualifiedName;
}

void CentSqlParser::QualifiedNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedName(this);
}

void CentSqlParser::QualifiedNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedName(this);
}


antlrcpp::Any CentSqlParser::QualifiedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQualifiedName(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::QualifiedNameContext* CentSqlParser::qualifiedName() {
  QualifiedNameContext *_localctx = _tracker.createInstance<QualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 116, CentSqlParser::RuleQualifiedName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1468);
    identifier();
    setState(1473);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 180, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1469);
        match(CentSqlParser::T__0);
        setState(1470);
        identifier(); 
      }
      setState(1475);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 180, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

CentSqlParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::IdentifierContext::getRuleIndex() const {
  return CentSqlParser::RuleIdentifier;
}

void CentSqlParser::IdentifierContext::copyFrom(IdentifierContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BackQuotedIdentifierContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::BackQuotedIdentifierContext::BACKQUOTED_IDENTIFIER() {
  return getToken(CentSqlParser::BACKQUOTED_IDENTIFIER, 0);
}

CentSqlParser::BackQuotedIdentifierContext::BackQuotedIdentifierContext(IdentifierContext *ctx) { copyFrom(ctx); }

void CentSqlParser::BackQuotedIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBackQuotedIdentifier(this);
}
void CentSqlParser::BackQuotedIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBackQuotedIdentifier(this);
}

antlrcpp::Any CentSqlParser::BackQuotedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitBackQuotedIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QuotedIdentifierContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::QuotedIdentifierContext::QUOTED_IDENTIFIER() {
  return getToken(CentSqlParser::QUOTED_IDENTIFIER, 0);
}

CentSqlParser::QuotedIdentifierContext::QuotedIdentifierContext(IdentifierContext *ctx) { copyFrom(ctx); }

void CentSqlParser::QuotedIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuotedIdentifier(this);
}
void CentSqlParser::QuotedIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuotedIdentifier(this);
}

antlrcpp::Any CentSqlParser::QuotedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitQuotedIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DigitIdentifierContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DigitIdentifierContext::DIGIT_IDENTIFIER() {
  return getToken(CentSqlParser::DIGIT_IDENTIFIER, 0);
}

CentSqlParser::DigitIdentifierContext::DigitIdentifierContext(IdentifierContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DigitIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDigitIdentifier(this);
}
void CentSqlParser::DigitIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDigitIdentifier(this);
}

antlrcpp::Any CentSqlParser::DigitIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDigitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnquotedIdentifierContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::UnquotedIdentifierContext::IDENTIFIER() {
  return getToken(CentSqlParser::IDENTIFIER, 0);
}

CentSqlParser::NonReservedContext* CentSqlParser::UnquotedIdentifierContext::nonReserved() {
  return getRuleContext<CentSqlParser::NonReservedContext>(0);
}

CentSqlParser::UnquotedIdentifierContext::UnquotedIdentifierContext(IdentifierContext *ctx) { copyFrom(ctx); }

void CentSqlParser::UnquotedIdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnquotedIdentifier(this);
}
void CentSqlParser::UnquotedIdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnquotedIdentifier(this);
}

antlrcpp::Any CentSqlParser::UnquotedIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitUnquotedIdentifier(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::IdentifierContext* CentSqlParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 118, CentSqlParser::RuleIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1481);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::IDENTIFIER: {
        _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<CentSqlParser::UnquotedIdentifierContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(1476);
        match(CentSqlParser::IDENTIFIER);
        break;
      }

      case CentSqlParser::QUOTED_IDENTIFIER: {
        _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<CentSqlParser::QuotedIdentifierContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(1477);
        match(CentSqlParser::QUOTED_IDENTIFIER);
        break;
      }

      case CentSqlParser::ADD:
      case CentSqlParser::ALL:
      case CentSqlParser::ANALYZE:
      case CentSqlParser::ANY:
      case CentSqlParser::ARRAY:
      case CentSqlParser::ASC:
      case CentSqlParser::AT:
      case CentSqlParser::BERNOULLI:
      case CentSqlParser::CALL:
      case CentSqlParser::CASCADE:
      case CentSqlParser::CATALOGS:
      case CentSqlParser::COLUMN:
      case CentSqlParser::COLUMNS:
      case CentSqlParser::COMMENT:
      case CentSqlParser::COMMIT:
      case CentSqlParser::COMMITTED:
      case CentSqlParser::CURRENT:
      case CentSqlParser::DATA:
      case CentSqlParser::DATE:
      case CentSqlParser::DAY:
      case CentSqlParser::DESC:
      case CentSqlParser::DISTRIBUTED:
      case CentSqlParser::EXCLUDING:
      case CentSqlParser::EXPLAIN:
      case CentSqlParser::FILTER:
      case CentSqlParser::FIRST:
      case CentSqlParser::FOLLOWING:
      case CentSqlParser::FORMAT:
      case CentSqlParser::FUNCTIONS:
      case CentSqlParser::GRANT:
      case CentSqlParser::GRANTS:
      case CentSqlParser::GRAPHVIZ:
      case CentSqlParser::HOUR:
      case CentSqlParser::IF:
      case CentSqlParser::INCLUDING:
      case CentSqlParser::INPUT:
      case CentSqlParser::INTERVAL:
      case CentSqlParser::IO:
      case CentSqlParser::ISOLATION:
      case CentSqlParser::JSON:
      case CentSqlParser::LAST:
      case CentSqlParser::LATERAL:
      case CentSqlParser::LEVEL:
      case CentSqlParser::LIMIT:
      case CentSqlParser::LOGICAL:
      case CentSqlParser::MAP:
      case CentSqlParser::MINUTE:
      case CentSqlParser::MONTH:
      case CentSqlParser::NFC:
      case CentSqlParser::NFD:
      case CentSqlParser::NFKC:
      case CentSqlParser::NFKD:
      case CentSqlParser::NO:
      case CentSqlParser::NULLIF:
      case CentSqlParser::NULLS:
      case CentSqlParser::ONLY:
      case CentSqlParser::OPTION:
      case CentSqlParser::ORDINALITY:
      case CentSqlParser::OUTPUT:
      case CentSqlParser::OVER:
      case CentSqlParser::PARTITION:
      case CentSqlParser::PARTITIONS:
      case CentSqlParser::PATH:
      case CentSqlParser::POSITION:
      case CentSqlParser::PRECEDING:
      case CentSqlParser::PRIVILEGES:
      case CentSqlParser::PROPERTIES:
      case CentSqlParser::PUBLIC:
      case CentSqlParser::RANGE:
      case CentSqlParser::READ:
      case CentSqlParser::RENAME:
      case CentSqlParser::REPEATABLE:
      case CentSqlParser::REPLACE:
      case CentSqlParser::RESET:
      case CentSqlParser::RESTRICT:
      case CentSqlParser::REVOKE:
      case CentSqlParser::ROLLBACK:
      case CentSqlParser::ROW:
      case CentSqlParser::ROWS:
      case CentSqlParser::SCHEMA:
      case CentSqlParser::SCHEMAS:
      case CentSqlParser::SECOND:
      case CentSqlParser::SERIALIZABLE:
      case CentSqlParser::SESSION:
      case CentSqlParser::SET:
      case CentSqlParser::SETS:
      case CentSqlParser::SHOW:
      case CentSqlParser::SOME:
      case CentSqlParser::START:
      case CentSqlParser::STATS:
      case CentSqlParser::SUBSTRING:
      case CentSqlParser::SYSTEM:
      case CentSqlParser::TABLES:
      case CentSqlParser::TABLESAMPLE:
      case CentSqlParser::TEXT:
      case CentSqlParser::TIME:
      case CentSqlParser::TIMESTAMP:
      case CentSqlParser::TO:
      case CentSqlParser::TRANSACTION:
      case CentSqlParser::TRY_CAST:
      case CentSqlParser::TYPE:
      case CentSqlParser::UNBOUNDED:
      case CentSqlParser::UNCOMMITTED:
      case CentSqlParser::USE:
      case CentSqlParser::VALIDATE:
      case CentSqlParser::VERBOSE:
      case CentSqlParser::VIEW:
      case CentSqlParser::WORK:
      case CentSqlParser::WRITE:
      case CentSqlParser::YEAR:
      case CentSqlParser::ZONE: {
        _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<CentSqlParser::UnquotedIdentifierContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(1478);
        nonReserved();
        break;
      }

      case CentSqlParser::BACKQUOTED_IDENTIFIER: {
        _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<CentSqlParser::BackQuotedIdentifierContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(1479);
        match(CentSqlParser::BACKQUOTED_IDENTIFIER);
        break;
      }

      case CentSqlParser::DIGIT_IDENTIFIER: {
        _localctx = dynamic_cast<IdentifierContext *>(_tracker.createInstance<CentSqlParser::DigitIdentifierContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(1480);
        match(CentSqlParser::DIGIT_IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CentSqlParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CentSqlParser::NumberContext::getRuleIndex() const {
  return CentSqlParser::RuleNumber;
}

void CentSqlParser::NumberContext::copyFrom(NumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DecimalLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DecimalLiteralContext::DECIMAL_VALUE() {
  return getToken(CentSqlParser::DECIMAL_VALUE, 0);
}

CentSqlParser::DecimalLiteralContext::DecimalLiteralContext(NumberContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DecimalLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecimalLiteral(this);
}
void CentSqlParser::DecimalLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecimalLiteral(this);
}

antlrcpp::Any CentSqlParser::DecimalLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDecimalLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoubleLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::DoubleLiteralContext::DOUBLE_VALUE() {
  return getToken(CentSqlParser::DOUBLE_VALUE, 0);
}

CentSqlParser::DoubleLiteralContext::DoubleLiteralContext(NumberContext *ctx) { copyFrom(ctx); }

void CentSqlParser::DoubleLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoubleLiteral(this);
}
void CentSqlParser::DoubleLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoubleLiteral(this);
}

antlrcpp::Any CentSqlParser::DoubleLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitDoubleLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerLiteralContext ------------------------------------------------------------------

tree::TerminalNode* CentSqlParser::IntegerLiteralContext::INTEGER_VALUE() {
  return getToken(CentSqlParser::INTEGER_VALUE, 0);
}

CentSqlParser::IntegerLiteralContext::IntegerLiteralContext(NumberContext *ctx) { copyFrom(ctx); }

void CentSqlParser::IntegerLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerLiteral(this);
}
void CentSqlParser::IntegerLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerLiteral(this);
}

antlrcpp::Any CentSqlParser::IntegerLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitIntegerLiteral(this);
  else
    return visitor->visitChildren(this);
}
CentSqlParser::NumberContext* CentSqlParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 120, CentSqlParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1486);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CentSqlParser::DECIMAL_VALUE: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CentSqlParser::DecimalLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(1483);
        match(CentSqlParser::DECIMAL_VALUE);
        break;
      }

      case CentSqlParser::DOUBLE_VALUE: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CentSqlParser::DoubleLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(1484);
        match(CentSqlParser::DOUBLE_VALUE);
        break;
      }

      case CentSqlParser::INTEGER_VALUE: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<CentSqlParser::IntegerLiteralContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(1485);
        match(CentSqlParser::INTEGER_VALUE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonReservedContext ------------------------------------------------------------------

CentSqlParser::NonReservedContext::NonReservedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ADD() {
  return getToken(CentSqlParser::ADD, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ALL() {
  return getToken(CentSqlParser::ALL, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ANALYZE() {
  return getToken(CentSqlParser::ANALYZE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ANY() {
  return getToken(CentSqlParser::ANY, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ARRAY() {
  return getToken(CentSqlParser::ARRAY, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ASC() {
  return getToken(CentSqlParser::ASC, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::AT() {
  return getToken(CentSqlParser::AT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::BERNOULLI() {
  return getToken(CentSqlParser::BERNOULLI, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::CALL() {
  return getToken(CentSqlParser::CALL, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::CASCADE() {
  return getToken(CentSqlParser::CASCADE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::CATALOGS() {
  return getToken(CentSqlParser::CATALOGS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::COLUMN() {
  return getToken(CentSqlParser::COLUMN, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::COLUMNS() {
  return getToken(CentSqlParser::COLUMNS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::COMMENT() {
  return getToken(CentSqlParser::COMMENT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::COMMIT() {
  return getToken(CentSqlParser::COMMIT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::COMMITTED() {
  return getToken(CentSqlParser::COMMITTED, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::CURRENT() {
  return getToken(CentSqlParser::CURRENT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::DATA() {
  return getToken(CentSqlParser::DATA, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::DATE() {
  return getToken(CentSqlParser::DATE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::DAY() {
  return getToken(CentSqlParser::DAY, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::DESC() {
  return getToken(CentSqlParser::DESC, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::DISTRIBUTED() {
  return getToken(CentSqlParser::DISTRIBUTED, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::EXCLUDING() {
  return getToken(CentSqlParser::EXCLUDING, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::EXPLAIN() {
  return getToken(CentSqlParser::EXPLAIN, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::FILTER() {
  return getToken(CentSqlParser::FILTER, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::FIRST() {
  return getToken(CentSqlParser::FIRST, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::FOLLOWING() {
  return getToken(CentSqlParser::FOLLOWING, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::FORMAT() {
  return getToken(CentSqlParser::FORMAT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::FUNCTIONS() {
  return getToken(CentSqlParser::FUNCTIONS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::GRANT() {
  return getToken(CentSqlParser::GRANT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::GRANTS() {
  return getToken(CentSqlParser::GRANTS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::GRAPHVIZ() {
  return getToken(CentSqlParser::GRAPHVIZ, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::HOUR() {
  return getToken(CentSqlParser::HOUR, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::IF() {
  return getToken(CentSqlParser::IF, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::INCLUDING() {
  return getToken(CentSqlParser::INCLUDING, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::INPUT() {
  return getToken(CentSqlParser::INPUT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::INTERVAL() {
  return getToken(CentSqlParser::INTERVAL, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::IO() {
  return getToken(CentSqlParser::IO, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ISOLATION() {
  return getToken(CentSqlParser::ISOLATION, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::JSON() {
  return getToken(CentSqlParser::JSON, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::LAST() {
  return getToken(CentSqlParser::LAST, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::LATERAL() {
  return getToken(CentSqlParser::LATERAL, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::LEVEL() {
  return getToken(CentSqlParser::LEVEL, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::LIMIT() {
  return getToken(CentSqlParser::LIMIT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::LOGICAL() {
  return getToken(CentSqlParser::LOGICAL, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::MAP() {
  return getToken(CentSqlParser::MAP, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::MINUTE() {
  return getToken(CentSqlParser::MINUTE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::MONTH() {
  return getToken(CentSqlParser::MONTH, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NFC() {
  return getToken(CentSqlParser::NFC, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NFD() {
  return getToken(CentSqlParser::NFD, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NFKC() {
  return getToken(CentSqlParser::NFKC, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NFKD() {
  return getToken(CentSqlParser::NFKD, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NO() {
  return getToken(CentSqlParser::NO, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NULLIF() {
  return getToken(CentSqlParser::NULLIF, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::NULLS() {
  return getToken(CentSqlParser::NULLS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ONLY() {
  return getToken(CentSqlParser::ONLY, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::OPTION() {
  return getToken(CentSqlParser::OPTION, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ORDINALITY() {
  return getToken(CentSqlParser::ORDINALITY, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::OUTPUT() {
  return getToken(CentSqlParser::OUTPUT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::OVER() {
  return getToken(CentSqlParser::OVER, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PARTITION() {
  return getToken(CentSqlParser::PARTITION, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PARTITIONS() {
  return getToken(CentSqlParser::PARTITIONS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PATH() {
  return getToken(CentSqlParser::PATH, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::POSITION() {
  return getToken(CentSqlParser::POSITION, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PRECEDING() {
  return getToken(CentSqlParser::PRECEDING, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PRIVILEGES() {
  return getToken(CentSqlParser::PRIVILEGES, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PROPERTIES() {
  return getToken(CentSqlParser::PROPERTIES, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::PUBLIC() {
  return getToken(CentSqlParser::PUBLIC, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::RANGE() {
  return getToken(CentSqlParser::RANGE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::READ() {
  return getToken(CentSqlParser::READ, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::RENAME() {
  return getToken(CentSqlParser::RENAME, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::REPEATABLE() {
  return getToken(CentSqlParser::REPEATABLE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::REPLACE() {
  return getToken(CentSqlParser::REPLACE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::RESET() {
  return getToken(CentSqlParser::RESET, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::RESTRICT() {
  return getToken(CentSqlParser::RESTRICT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::REVOKE() {
  return getToken(CentSqlParser::REVOKE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ROLLBACK() {
  return getToken(CentSqlParser::ROLLBACK, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ROW() {
  return getToken(CentSqlParser::ROW, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ROWS() {
  return getToken(CentSqlParser::ROWS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SCHEMA() {
  return getToken(CentSqlParser::SCHEMA, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SCHEMAS() {
  return getToken(CentSqlParser::SCHEMAS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SECOND() {
  return getToken(CentSqlParser::SECOND, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SERIALIZABLE() {
  return getToken(CentSqlParser::SERIALIZABLE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SESSION() {
  return getToken(CentSqlParser::SESSION, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SET() {
  return getToken(CentSqlParser::SET, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SETS() {
  return getToken(CentSqlParser::SETS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SHOW() {
  return getToken(CentSqlParser::SHOW, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SOME() {
  return getToken(CentSqlParser::SOME, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::START() {
  return getToken(CentSqlParser::START, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::STATS() {
  return getToken(CentSqlParser::STATS, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SUBSTRING() {
  return getToken(CentSqlParser::SUBSTRING, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::SYSTEM() {
  return getToken(CentSqlParser::SYSTEM, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TABLES() {
  return getToken(CentSqlParser::TABLES, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TABLESAMPLE() {
  return getToken(CentSqlParser::TABLESAMPLE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TEXT() {
  return getToken(CentSqlParser::TEXT, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TIME() {
  return getToken(CentSqlParser::TIME, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TIMESTAMP() {
  return getToken(CentSqlParser::TIMESTAMP, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TO() {
  return getToken(CentSqlParser::TO, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TRANSACTION() {
  return getToken(CentSqlParser::TRANSACTION, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TRY_CAST() {
  return getToken(CentSqlParser::TRY_CAST, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::TYPE() {
  return getToken(CentSqlParser::TYPE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::UNBOUNDED() {
  return getToken(CentSqlParser::UNBOUNDED, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::UNCOMMITTED() {
  return getToken(CentSqlParser::UNCOMMITTED, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::USE() {
  return getToken(CentSqlParser::USE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::VALIDATE() {
  return getToken(CentSqlParser::VALIDATE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::VERBOSE() {
  return getToken(CentSqlParser::VERBOSE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::VIEW() {
  return getToken(CentSqlParser::VIEW, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::WORK() {
  return getToken(CentSqlParser::WORK, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::WRITE() {
  return getToken(CentSqlParser::WRITE, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::YEAR() {
  return getToken(CentSqlParser::YEAR, 0);
}

tree::TerminalNode* CentSqlParser::NonReservedContext::ZONE() {
  return getToken(CentSqlParser::ZONE, 0);
}


size_t CentSqlParser::NonReservedContext::getRuleIndex() const {
  return CentSqlParser::RuleNonReserved;
}

void CentSqlParser::NonReservedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonReserved(this);
}

void CentSqlParser::NonReservedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CentSqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonReserved(this);
}


antlrcpp::Any CentSqlParser::NonReservedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CentSqlVisitor*>(visitor))
    return parserVisitor->visitNonReserved(this);
  else
    return visitor->visitChildren(this);
}

CentSqlParser::NonReservedContext* CentSqlParser::nonReserved() {
  NonReservedContext *_localctx = _tracker.createInstance<NonReservedContext>(_ctx, getState());
  enterRule(_localctx, 122, CentSqlParser::RuleNonReserved);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1488);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CentSqlParser::ADD)
      | (1ULL << CentSqlParser::ALL)
      | (1ULL << CentSqlParser::ANALYZE)
      | (1ULL << CentSqlParser::ANY)
      | (1ULL << CentSqlParser::ARRAY)
      | (1ULL << CentSqlParser::ASC)
      | (1ULL << CentSqlParser::AT)
      | (1ULL << CentSqlParser::BERNOULLI)
      | (1ULL << CentSqlParser::CALL)
      | (1ULL << CentSqlParser::CASCADE)
      | (1ULL << CentSqlParser::CATALOGS)
      | (1ULL << CentSqlParser::COLUMN)
      | (1ULL << CentSqlParser::COLUMNS)
      | (1ULL << CentSqlParser::COMMENT)
      | (1ULL << CentSqlParser::COMMIT)
      | (1ULL << CentSqlParser::COMMITTED)
      | (1ULL << CentSqlParser::CURRENT)
      | (1ULL << CentSqlParser::DATA)
      | (1ULL << CentSqlParser::DATE)
      | (1ULL << CentSqlParser::DAY)
      | (1ULL << CentSqlParser::DESC)
      | (1ULL << CentSqlParser::DISTRIBUTED)
      | (1ULL << CentSqlParser::EXCLUDING)
      | (1ULL << CentSqlParser::EXPLAIN)
      | (1ULL << CentSqlParser::FILTER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (CentSqlParser::FIRST - 64))
      | (1ULL << (CentSqlParser::FOLLOWING - 64))
      | (1ULL << (CentSqlParser::FORMAT - 64))
      | (1ULL << (CentSqlParser::FUNCTIONS - 64))
      | (1ULL << (CentSqlParser::GRANT - 64))
      | (1ULL << (CentSqlParser::GRANTS - 64))
      | (1ULL << (CentSqlParser::GRAPHVIZ - 64))
      | (1ULL << (CentSqlParser::HOUR - 64))
      | (1ULL << (CentSqlParser::IF - 64))
      | (1ULL << (CentSqlParser::INCLUDING - 64))
      | (1ULL << (CentSqlParser::INPUT - 64))
      | (1ULL << (CentSqlParser::INTERVAL - 64))
      | (1ULL << (CentSqlParser::IO - 64))
      | (1ULL << (CentSqlParser::ISOLATION - 64))
      | (1ULL << (CentSqlParser::JSON - 64))
      | (1ULL << (CentSqlParser::LAST - 64))
      | (1ULL << (CentSqlParser::LATERAL - 64))
      | (1ULL << (CentSqlParser::LEVEL - 64))
      | (1ULL << (CentSqlParser::LIMIT - 64))
      | (1ULL << (CentSqlParser::LOGICAL - 64))
      | (1ULL << (CentSqlParser::MAP - 64))
      | (1ULL << (CentSqlParser::MINUTE - 64))
      | (1ULL << (CentSqlParser::MONTH - 64))
      | (1ULL << (CentSqlParser::NFC - 64))
      | (1ULL << (CentSqlParser::NFD - 64))
      | (1ULL << (CentSqlParser::NFKC - 64))
      | (1ULL << (CentSqlParser::NFKD - 64))
      | (1ULL << (CentSqlParser::NO - 64))
      | (1ULL << (CentSqlParser::NULLIF - 64))
      | (1ULL << (CentSqlParser::NULLS - 64))
      | (1ULL << (CentSqlParser::ONLY - 64))
      | (1ULL << (CentSqlParser::OPTION - 64))
      | (1ULL << (CentSqlParser::ORDINALITY - 64))
      | (1ULL << (CentSqlParser::OUTPUT - 64))
      | (1ULL << (CentSqlParser::OVER - 64))
      | (1ULL << (CentSqlParser::PARTITION - 64))
      | (1ULL << (CentSqlParser::PARTITIONS - 64))
      | (1ULL << (CentSqlParser::PATH - 64))
      | (1ULL << (CentSqlParser::POSITION - 64)))) != 0) || ((((_la - 128) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 128)) & ((1ULL << (CentSqlParser::PRECEDING - 128))
      | (1ULL << (CentSqlParser::PRIVILEGES - 128))
      | (1ULL << (CentSqlParser::PROPERTIES - 128))
      | (1ULL << (CentSqlParser::PUBLIC - 128))
      | (1ULL << (CentSqlParser::RANGE - 128))
      | (1ULL << (CentSqlParser::READ - 128))
      | (1ULL << (CentSqlParser::RENAME - 128))
      | (1ULL << (CentSqlParser::REPEATABLE - 128))
      | (1ULL << (CentSqlParser::REPLACE - 128))
      | (1ULL << (CentSqlParser::RESET - 128))
      | (1ULL << (CentSqlParser::RESTRICT - 128))
      | (1ULL << (CentSqlParser::REVOKE - 128))
      | (1ULL << (CentSqlParser::ROLLBACK - 128))
      | (1ULL << (CentSqlParser::ROW - 128))
      | (1ULL << (CentSqlParser::ROWS - 128))
      | (1ULL << (CentSqlParser::SCHEMA - 128))
      | (1ULL << (CentSqlParser::SCHEMAS - 128))
      | (1ULL << (CentSqlParser::SECOND - 128))
      | (1ULL << (CentSqlParser::SERIALIZABLE - 128))
      | (1ULL << (CentSqlParser::SESSION - 128))
      | (1ULL << (CentSqlParser::SET - 128))
      | (1ULL << (CentSqlParser::SETS - 128))
      | (1ULL << (CentSqlParser::SHOW - 128))
      | (1ULL << (CentSqlParser::SOME - 128))
      | (1ULL << (CentSqlParser::START - 128))
      | (1ULL << (CentSqlParser::STATS - 128))
      | (1ULL << (CentSqlParser::SUBSTRING - 128))
      | (1ULL << (CentSqlParser::SYSTEM - 128))
      | (1ULL << (CentSqlParser::TABLES - 128))
      | (1ULL << (CentSqlParser::TABLESAMPLE - 128))
      | (1ULL << (CentSqlParser::TEXT - 128))
      | (1ULL << (CentSqlParser::TIME - 128))
      | (1ULL << (CentSqlParser::TIMESTAMP - 128))
      | (1ULL << (CentSqlParser::TO - 128))
      | (1ULL << (CentSqlParser::TRANSACTION - 128))
      | (1ULL << (CentSqlParser::TRY_CAST - 128))
      | (1ULL << (CentSqlParser::TYPE - 128))
      | (1ULL << (CentSqlParser::UNBOUNDED - 128))
      | (1ULL << (CentSqlParser::UNCOMMITTED - 128))
      | (1ULL << (CentSqlParser::USE - 128))
      | (1ULL << (CentSqlParser::VALIDATE - 128))
      | (1ULL << (CentSqlParser::VERBOSE - 128))
      | (1ULL << (CentSqlParser::VIEW - 128))
      | (1ULL << (CentSqlParser::WORK - 128))
      | (1ULL << (CentSqlParser::WRITE - 128))
      | (1ULL << (CentSqlParser::YEAR - 128))
      | (1ULL << (CentSqlParser::ZONE - 128)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool CentSqlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return queryTermSempred(dynamic_cast<QueryTermContext *>(context), predicateIndex);
    case 22: return relationSempred(dynamic_cast<RelationContext *>(context), predicateIndex);
    case 31: return booleanExpressionSempred(dynamic_cast<BooleanExpressionContext *>(context), predicateIndex);
    case 33: return valueExpressionSempred(dynamic_cast<ValueExpressionContext *>(context), predicateIndex);
    case 34: return primaryExpressionSempred(dynamic_cast<PrimaryExpressionContext *>(context), predicateIndex);
    case 43: return typeSempred(dynamic_cast<TypeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CentSqlParser::queryTermSempred(QueryTermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CentSqlParser::relationSempred(RelationContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool CentSqlParser::booleanExpressionSempred(BooleanExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 2);
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool CentSqlParser::valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);
    case 7: return precpred(_ctx, 1);
    case 8: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool CentSqlParser::primaryExpressionSempred(PrimaryExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 15);
    case 10: return precpred(_ctx, 13);

  default:
    break;
  }
  return true;
}

bool CentSqlParser::typeSempred(TypeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 11: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CentSqlParser::_decisionToDFA;
atn::PredictionContextCache CentSqlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CentSqlParser::_atn;
std::vector<uint16_t> CentSqlParser::_serializedATN;

std::vector<std::string> CentSqlParser::_ruleNames = {
  "singleStatement", "standaloneExpression", "standalonePathSpecification", 
  "statement", "query", "with", "tableElement", "columnDefinition", "likeClause", 
  "properties", "property", "queryNoWith", "queryTerm", "queryPrimary", 
  "sortItem", "querySpecification", "groupBy", "groupingElement", "groupingSet", 
  "namedQuery", "setQuantifier", "selectItem", "relation", "joinType", "joinCriteria", 
  "sampledRelation", "sampleType", "aliasedRelation", "columnAliases", "relationPrimary", 
  "expression", "booleanExpression", "predicate", "valueExpression", "primaryExpression", 
  "string", "timeZoneSpecifier", "comparisonOperator", "comparisonQuantifier", 
  "booleanValue", "interval", "intervalField", "normalForm", "type", "typeParameter", 
  "baseType", "whenClause", "filter", "over", "windowFrame", "frameBound", 
  "explainOption", "transactionMode", "levelOfIsolation", "callArgument", 
  "pathElement", "pathSpecification", "privilege", "qualifiedName", "identifier", 
  "number", "nonReserved"
};

std::vector<std::string> CentSqlParser::_literalNames = {
  "", "'.'", "'('", "')'", "','", "'?'", "'->'", "'['", "']'", "'=>'", "'ADD'", 
  "'ALL'", "'ALTER'", "'ANALYZE'", "'AND'", "'ANY'", "'ARRAY'", "'AS'", 
  "'ASC'", "'AT'", "'BERNOULLI'", "'BETWEEN'", "'BY'", "'CALL'", "'CASCADE'", 
  "'CASE'", "'CAST'", "'CATALOGS'", "'COLUMN'", "'COLUMNS'", "'COMMENT'", 
  "'COMMIT'", "'COMMITTED'", "'CONSTRAINT'", "'CREATE'", "'CROSS'", "'CUBE'", 
  "'CURRENT'", "'CURRENT_DATE'", "'CURRENT_PATH'", "'CURRENT_TIME'", "'CURRENT_TIMESTAMP'", 
  "'CURRENT_USER'", "'DATA'", "'DATE'", "'DAY'", "'DEALLOCATE'", "'DELETE'", 
  "'DESC'", "'DESCRIBE'", "'DISTINCT'", "'DISTRIBUTED'", "'DROP'", "'ELSE'", 
  "'END'", "'ESCAPE'", "'EXCEPT'", "'EXCLUDING'", "'EXECUTE'", "'EXISTS'", 
  "'EXPLAIN'", "'EXTRACT'", "'FALSE'", "'FILTER'", "'FIRST'", "'FOLLOWING'", 
  "'FOR'", "'FORMAT'", "'FROM'", "'FULL'", "'FUNCTIONS'", "'GRANT'", "'GRANTS'", 
  "'GRAPHVIZ'", "'GROUP'", "'GROUPING'", "'HAVING'", "'HOUR'", "'IF'", "'IN'", 
  "'INCLUDING'", "'INNER'", "'INPUT'", "'INSERT'", "'INTERSECT'", "'INTERVAL'", 
  "'INTO'", "'IO'", "'IS'", "'ISOLATION'", "'JSON'", "'JOIN'", "'LAST'", 
  "'LATERAL'", "'LEFT'", "'LEVEL'", "'LIKE'", "'LIMIT'", "'LOCALTIME'", 
  "'LOCALTIMESTAMP'", "'LOGICAL'", "'MAP'", "'MINUTE'", "'MONTH'", "'NATURAL'", 
  "'NFC'", "'NFD'", "'NFKC'", "'NFKD'", "'NO'", "'NORMALIZE'", "'NOT'", 
  "'NULL'", "'NULLIF'", "'NULLS'", "'ON'", "'ONLY'", "'OPTION'", "'OR'", 
  "'ORDER'", "'ORDINALITY'", "'OUTER'", "'OUTPUT'", "'OVER'", "'PARTITION'", 
  "'PARTITIONS'", "'PATH'", "'POSITION'", "'PRECEDING'", "'PREPARE'", "'PRIVILEGES'", 
  "'PROPERTIES'", "'PUBLIC'", "'RANGE'", "'READ'", "'RECURSIVE'", "'RENAME'", 
  "'REPEATABLE'", "'REPLACE'", "'RESET'", "'RESTRICT'", "'REVOKE'", "'RIGHT'", 
  "'ROLLBACK'", "'ROLLUP'", "'ROW'", "'ROWS'", "'SCHEMA'", "'SCHEMAS'", 
  "'SECOND'", "'SELECT'", "'SERIALIZABLE'", "'SESSION'", "'SET'", "'SETS'", 
  "'SHOW'", "'SOME'", "'START'", "'STATS'", "'SUBSTRING'", "'SYSTEM'", "'TABLE'", 
  "'TABLES'", "'TABLESAMPLE'", "'TEXT'", "'THEN'", "'TIME'", "'TIMESTAMP'", 
  "'TO'", "'TRANSACTION'", "'TRUE'", "'TRY_CAST'", "'TYPE'", "'UESCAPE'", 
  "'UNBOUNDED'", "'UNCOMMITTED'", "'UNION'", "'UNNEST'", "'USE'", "'USING'", 
  "'VALIDATE'", "'VALUES'", "'VERBOSE'", "'VIEW'", "'WHEN'", "'WHERE'", 
  "'WITH'", "'WORK'", "'WRITE'", "'YEAR'", "'ZONE'", "'='", "", "'<'", "'<='", 
  "'>'", "'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'||'"
};

std::vector<std::string> CentSqlParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "ADD", "ALL", "ALTER", "ANALYZE", 
  "AND", "ANY", "ARRAY", "AS", "ASC", "AT", "BERNOULLI", "BETWEEN", "BY", 
  "CALL", "CASCADE", "CASE", "CAST", "CATALOGS", "COLUMN", "COLUMNS", "COMMENT", 
  "COMMIT", "COMMITTED", "CONSTRAINT", "CREATE", "CROSS", "CUBE", "CURRENT", 
  "CURRENT_DATE", "CURRENT_PATH", "CURRENT_TIME", "CURRENT_TIMESTAMP", "CURRENT_USER", 
  "DATA", "DATE", "DAY", "DEALLOCATE", "DELETE", "DESC", "DESCRIBE", "DISTINCT", 
  "DISTRIBUTED", "DROP", "ELSE", "END", "ESCAPE", "EXCEPT", "EXCLUDING", 
  "EXECUTE", "EXISTS", "EXPLAIN", "EXTRACT", "FALSE_VALUE", "FILTER", "FIRST", 
  "FOLLOWING", "FOR", "FORMAT", "FROM", "FULL", "FUNCTIONS", "GRANT", "GRANTS", 
  "GRAPHVIZ", "GROUP", "GROUPING", "HAVING", "HOUR", "IF", "IN", "INCLUDING", 
  "INNER", "INPUT", "INSERT", "INTERSECT", "INTERVAL", "INTO", "IO", "IS", 
  "ISOLATION", "JSON", "JOIN", "LAST", "LATERAL", "LEFT", "LEVEL", "LIKE", 
  "LIMIT", "LOCALTIME", "LOCALTIMESTAMP", "LOGICAL", "MAP", "MINUTE", "MONTH", 
  "NATURAL", "NFC", "NFD", "NFKC", "NFKD", "NO", "NORMALIZE", "NOT", "NULL_VALUE", 
  "NULLIF", "NULLS", "ON", "ONLY", "OPTION", "OR", "ORDER", "ORDINALITY", 
  "OUTER", "OUTPUT", "OVER", "PARTITION", "PARTITIONS", "PATH", "POSITION", 
  "PRECEDING", "PREPARE", "PRIVILEGES", "PROPERTIES", "PUBLIC", "RANGE", 
  "READ", "RECURSIVE", "RENAME", "REPEATABLE", "REPLACE", "RESET", "RESTRICT", 
  "REVOKE", "RIGHT", "ROLLBACK", "ROLLUP", "ROW", "ROWS", "SCHEMA", "SCHEMAS", 
  "SECOND", "SELECT", "SERIALIZABLE", "SESSION", "SET", "SETS", "SHOW", 
  "SOME", "START", "STATS", "SUBSTRING", "SYSTEM", "TABLE", "TABLES", "TABLESAMPLE", 
  "TEXT", "THEN", "TIME", "TIMESTAMP", "TO", "TRANSACTION", "TRUE_VALUE", 
  "TRY_CAST", "TYPE", "UESCAPE", "UNBOUNDED", "UNCOMMITTED", "UNION", "UNNEST", 
  "USE", "USING", "VALIDATE", "VALUES", "VERBOSE", "VIEW", "WHEN", "WHERE", 
  "WITH", "WORK", "WRITE", "YEAR", "ZONE", "EQ", "NEQ", "LT", "LTE", "GT", 
  "GTE", "PLUS", "MINUS", "ASTERISK", "SLASH", "PERCENT", "CONCAT", "STRING", 
  "UNICODE_STRING", "BINARY_LITERAL", "INTEGER_VALUE", "DECIMAL_VALUE", 
  "DOUBLE_VALUE", "IDENTIFIER", "DIGIT_IDENTIFIER", "QUOTED_IDENTIFIER", 
  "BACKQUOTED_IDENTIFIER", "TIME_WITH_TIME_ZONE", "TIMESTAMP_WITH_TIME_ZONE", 
  "DOUBLE_PRECISION", "SIMPLE_COMMENT", "BRACKETED_COMMENT", "WS", "UNRECOGNIZED", 
  "DELIMITER"
};

dfa::Vocabulary CentSqlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CentSqlParser::_tokenNames;

CentSqlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xde, 0x5d5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x95, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x9a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0xa0, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xa4, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xb2, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xb6, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0xba, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xbe, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xc6, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xca, 0xa, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0xcd, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xd4, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0xdb, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xde, 0xb, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xe3, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xe7, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0xed, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xf4, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xfd, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x120, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x12b, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x134, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x137, 0xb, 0x5, 0x5, 0x5, 0x139, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x141, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x144, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x148, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x14c, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x154, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x15a, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x15f, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x162, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x166, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x16a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x174, 0xa, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x177, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x17b, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x17e, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x184, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x187, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x18b, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x19a, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x1a0, 0xa, 
    0x5, 0x5, 0x5, 0x1a2, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x1a8, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x1ae, 0xa, 0x5, 0x5, 0x5, 0x1b0, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x1b6, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x1dd, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x1e0, 0xb, 0x5, 0x5, 0x5, 
    0x1e2, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x1e6, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x1ea, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x1fa, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x1fd, 0xb, 0x5, 0x5, 0x5, 0x1ff, 0xa, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x20a, 0xa, 0x5, 0x3, 0x6, 0x5, 0x6, 0x20d, 0xa, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x213, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x218, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x21b, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x21f, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x225, 0xa, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x229, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x5, 0xa, 0x22f, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0x235, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x238, 0xb, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x246, 0xa, 
    0xd, 0xc, 0xd, 0xe, 0xd, 0x249, 0xb, 0xd, 0x5, 0xd, 0x24b, 0xa, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x24f, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x257, 0xa, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x25d, 0xa, 0xe, 0x3, 0xe, 0x7, 
    0xe, 0x260, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x263, 0xb, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 
    0x26c, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x26f, 0xb, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x275, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0x279, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x27d, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x281, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x286, 0xa, 0x11, 0xc, 0x11, 
    0xe, 0x11, 0x289, 0xb, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x7, 0x11, 0x28f, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0x292, 0xb, 0x11, 
    0x5, 0x11, 0x294, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x298, 
    0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x29d, 0xa, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x2a1, 0xa, 0x11, 0x3, 0x12, 0x5, 0x12, 
    0x2a4, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x2a9, 
    0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x2ac, 0xb, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x2b4, 0xa, 0x13, 
    0xc, 0x13, 0xe, 0x13, 0x2b7, 0xb, 0x13, 0x5, 0x13, 0x2b9, 0xa, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 
    0x13, 0x2c1, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x2c4, 0xb, 0x13, 0x5, 
    0x13, 0x2c6, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x2cf, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0x2d2, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x2d6, 
    0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x2dc, 
    0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x2df, 0xb, 0x14, 0x5, 0x14, 0x2e1, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x2e5, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x2e9, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x5, 
    0x17, 0x2f4, 0xa, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2f7, 0xa, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x2fe, 
    0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x311, 
    0xa, 0x18, 0x7, 0x18, 0x313, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x316, 
    0xb, 0x18, 0x3, 0x19, 0x5, 0x19, 0x319, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0x31d, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x321, 
    0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x325, 0xa, 0x19, 0x5, 0x19, 
    0x327, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x330, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 
    0x333, 0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x337, 0xa, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x5, 0x1b, 0x340, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 
    0x3, 0x1d, 0x5, 0x1d, 0x346, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
    0x34a, 0xa, 0x1d, 0x5, 0x1d, 0x34c, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x352, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 
    0x355, 0xb, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x7, 0x1f, 0x363, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x366, 0xb, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x36b, 0xa, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x376, 0xa, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x37d, 0xa, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x381, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x389, 0xa, 0x21, 
    0xc, 0x21, 0xe, 0x21, 0x38c, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x5, 0x22, 0x398, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x3a0, 0xa, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x3a7, 0xa, 0x22, 
    0xc, 0x22, 0xe, 0x22, 0x3aa, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x3af, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x3b7, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x3bd, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x3c1, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
    0x3c6, 0xa, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x3cb, 
    0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x3d1, 
    0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x7, 0x23, 0x3df, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x3e2, 0xb, 0x23, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x6, 0x24, 0x3fc, 
    0xa, 0x24, 0xd, 0x24, 0xe, 0x24, 0x3fd, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x407, 0xa, 0x24, 
    0xc, 0x24, 0xe, 0x24, 0x40a, 0xb, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x413, 0xa, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x416, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x5, 0x24, 0x41b, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 
    0x420, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x423, 0xb, 0x24, 0x5, 0x24, 
    0x425, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x7, 0x24, 0x42c, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x42f, 0xb, 0x24, 
    0x5, 0x24, 0x431, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x435, 
    0xa, 0x24, 0x3, 0x24, 0x5, 0x24, 0x438, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 
    0x24, 0x442, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x445, 0xb, 0x24, 0x5, 
    0x24, 0x447, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x6, 0x24, 0x458, 
    0xa, 0x24, 0xd, 0x24, 0xe, 0x24, 0x459, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 
    0x45e, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x6, 0x24, 
    0x464, 0xa, 0x24, 0xd, 0x24, 0xe, 0x24, 0x465, 0x3, 0x24, 0x3, 0x24, 
    0x5, 0x24, 0x46a, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x481, 0xa, 0x24, 
    0xc, 0x24, 0xe, 0x24, 0x484, 0xb, 0x24, 0x5, 0x24, 0x486, 0xa, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x5, 0x24, 0x48f, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x495, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x49b, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x4a1, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 
    0x24, 0x4ac, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x4b5, 0xa, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x4c9, 0xa, 0x24, 
    0xc, 0x24, 0xe, 0x24, 0x4cc, 0xb, 0x24, 0x5, 0x24, 0x4ce, 0xa, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x4d1, 0xa, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x7, 0x24, 0x4db, 
    0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x4de, 0xb, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x4e4, 0xa, 0x25, 0x5, 0x25, 0x4e6, 
    0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 
    0x26, 0x5, 0x26, 0x4ee, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x4f8, 
    0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x4fe, 
    0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x7, 0x2d, 0x519, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x51c, 0xb, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x7, 0x2d, 0x525, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x528, 0xb, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x52c, 0xa, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x533, 0xa, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x537, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x53a, 0xb, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x53e, 0xa, 0x2e, 
    0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x544, 0xa, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 0x32, 0x558, 
    0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x55b, 0xb, 0x32, 0x5, 0x32, 0x55d, 
    0xa, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x7, 
    0x32, 0x564, 0xa, 0x32, 0xc, 0x32, 0xe, 0x32, 0x567, 0xb, 0x32, 0x5, 
    0x32, 0x569, 0xa, 0x32, 0x3, 0x32, 0x5, 0x32, 0x56c, 0xa, 0x32, 0x3, 
    0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 
    0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 
    0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x580, 
    0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 
    0x34, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x58b, 0xa, 0x34, 
    0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x591, 0xa, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x5, 0x36, 0x598, 
    0xa, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x5, 0x37, 0x5a1, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 
    0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x5a8, 0xa, 0x38, 0x3, 0x39, 
    0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x5af, 0xa, 0x39, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x5b4, 0xa, 0x3a, 0xc, 0x3a, 
    0xe, 0x3a, 0x5b7, 0xb, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x5, 0x3b, 0x5bd, 0xa, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x7, 0x3c, 
    0x5c2, 0xa, 0x3c, 0xc, 0x3c, 0xe, 0x3c, 0x5c5, 0xb, 0x3c, 0x3, 0x3d, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x5, 0x3d, 0x5cc, 0xa, 0x3d, 
    0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x5d1, 0xa, 0x3e, 0x3, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x2, 0x8, 0x1a, 0x2e, 0x40, 0x44, 0x46, 0x58, 
    0x40, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
    0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 
    0x7a, 0x7c, 0x2, 0x18, 0x4, 0x2, 0x1a, 0x1a, 0x8e, 0x8e, 0x4, 0x2, 0x46, 
    0x46, 0x51, 0x51, 0x4, 0x2, 0x44, 0x44, 0x75, 0x75, 0x4, 0x2, 0x3b, 
    0x3b, 0x52, 0x52, 0x4, 0x2, 0xd, 0xd, 0xd0, 0xd0, 0x4, 0x2, 0x3a, 0x3a, 
    0xb2, 0xb2, 0x4, 0x2, 0x14, 0x14, 0x32, 0x32, 0x4, 0x2, 0x42, 0x42, 
    0x5e, 0x5e, 0x4, 0x2, 0xd, 0xd, 0x34, 0x34, 0x4, 0x2, 0x16, 0x16, 0xa2, 
    0xa2, 0x3, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0xc9, 0xcb, 0x3, 0x2, 0xc1, 0xc6, 
    0x5, 0x2, 0xd, 0xd, 0x11, 0x11, 0x9e, 0x9e, 0x4, 0x2, 0x40, 0x40, 0xac, 
    0xac, 0x7, 0x2, 0x2f, 0x2f, 0x4f, 0x4f, 0x68, 0x69, 0x97, 0x97, 0xbf, 
    0xbf, 0x3, 0x2, 0x6b, 0x6e, 0x4, 0x2, 0x43, 0x43, 0x82, 0x82, 0x5, 0x2, 
    0x4b, 0x4b, 0x5c, 0x5c, 0xa6, 0xa6, 0x6, 0x2, 0x35, 0x35, 0x59, 0x59, 
    0x66, 0x66, 0xb6, 0xb6, 0x4, 0x2, 0x76, 0x76, 0xbe, 0xbe, 0x2d, 0x2, 
    0xc, 0xd, 0xf, 0xf, 0x11, 0x12, 0x14, 0x16, 0x19, 0x1a, 0x1d, 0x22, 
    0x27, 0x27, 0x2d, 0x2f, 0x32, 0x32, 0x35, 0x35, 0x3b, 0x3b, 0x3e, 0x3e, 
    0x41, 0x43, 0x45, 0x45, 0x48, 0x4b, 0x4f, 0x50, 0x52, 0x52, 0x54, 0x54, 
    0x57, 0x57, 0x59, 0x59, 0x5b, 0x5c, 0x5e, 0x5f, 0x61, 0x61, 0x63, 0x63, 
    0x66, 0x69, 0x6b, 0x6f, 0x73, 0x74, 0x76, 0x77, 0x7a, 0x7a, 0x7c, 0x82, 
    0x84, 0x88, 0x8a, 0x8f, 0x91, 0x91, 0x93, 0x97, 0x99, 0xa2, 0xa4, 0xa6, 
    0xa8, 0xab, 0xad, 0xae, 0xb0, 0xb1, 0xb4, 0xb4, 0xb6, 0xb6, 0xb8, 0xb9, 
    0xbd, 0xc0, 0x2, 0x6be, 0x2, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x81, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8, 0x209, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x20c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x210, 0x3, 0x2, 0x2, 
    0x2, 0xe, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x12, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x14, 0x230, 0x3, 0x2, 0x2, 0x2, 0x16, 
    0x23b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x250, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x274, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x276, 0x3, 
    0x2, 0x2, 0x2, 0x20, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x22, 0x2a3, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2e4, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2ef, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2fd, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2ff, 0x3, 0x2, 0x2, 0x2, 0x30, 
    0x326, 0x3, 0x2, 0x2, 0x2, 0x32, 0x336, 0x3, 0x2, 0x2, 0x2, 0x34, 0x338, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x341, 0x3, 0x2, 0x2, 0x2, 0x38, 0x343, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x375, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x377, 0x3, 0x2, 0x2, 0x2, 0x40, 0x380, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x3ca, 0x3, 0x2, 0x2, 0x2, 0x44, 0x3d0, 0x3, 0x2, 0x2, 0x2, 
    0x46, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4e5, 0x3, 0x2, 0x2, 0x2, 0x4a, 
    0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4ef, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f1, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x4f3, 0x3, 0x2, 0x2, 0x2, 0x52, 0x4f5, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x4ff, 0x3, 0x2, 0x2, 0x2, 0x56, 0x501, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x532, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x53d, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x543, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x545, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x54a, 0x3, 0x2, 0x2, 0x2, 0x62, 0x550, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x57f, 0x3, 0x2, 0x2, 0x2, 0x66, 0x58a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x590, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x597, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x5a0, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x5a7, 0x3, 0x2, 0x2, 0x2, 0x70, 0x5ae, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x74, 0x5bc, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x78, 0x5cb, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x5d0, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x5d2, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x7f, 0x5, 0x8, 0x5, 0x2, 0x7f, 0x80, 0x7, 0x2, 0x2, 0x3, 0x80, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x5, 0x3e, 0x20, 0x2, 0x82, 0x83, 0x7, 
    0x2, 0x2, 0x3, 0x83, 0x5, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x5, 0x72, 
    0x3a, 0x2, 0x85, 0x86, 0x7, 0x2, 0x2, 0x3, 0x86, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x20a, 0x5, 0xa, 0x6, 0x2, 0x88, 0x89, 0x7, 0xb4, 0x2, 0x2, 
    0x89, 0x20a, 0x5, 0x78, 0x3d, 0x2, 0x8a, 0x8b, 0x7, 0xb4, 0x2, 0x2, 
    0x8b, 0x8c, 0x5, 0x78, 0x3d, 0x2, 0x8c, 0x8d, 0x7, 0x3, 0x2, 0x2, 0x8d, 
    0x8e, 0x5, 0x78, 0x3d, 0x2, 0x8e, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 
    0x7, 0x24, 0x2, 0x2, 0x90, 0x94, 0x7, 0x95, 0x2, 0x2, 0x91, 0x92, 0x7, 
    0x50, 0x2, 0x2, 0x92, 0x93, 0x7, 0x71, 0x2, 0x2, 0x93, 0x95, 0x7, 0x3d, 
    0x2, 0x2, 0x94, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x99, 0x5, 0x76, 0x3c, 0x2, 
    0x97, 0x98, 0x7, 0xbc, 0x2, 0x2, 0x98, 0x9a, 0x5, 0x14, 0xb, 0x2, 0x99, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x20a, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x7, 0x36, 0x2, 0x2, 0x9c, 0x9f, 0x7, 
    0x95, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x50, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x3d, 
    0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0x76, 0x3c, 0x2, 
    0xa2, 0xa4, 0x9, 0x2, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa3, 
    0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x20a, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 
    0x7, 0xe, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0x95, 0x2, 0x2, 0xa7, 0xa8, 0x5, 
    0x76, 0x3c, 0x2, 0xa8, 0xa9, 0x7, 0x8a, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0xaa, 
    0x2, 0x2, 0xaa, 0xab, 0x5, 0x78, 0x3d, 0x2, 0xab, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xad, 0x7, 0x24, 0x2, 0x2, 0xad, 0xb1, 0x7, 0xa3, 0x2, 0x2, 
    0xae, 0xaf, 0x7, 0x50, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x71, 0x2, 0x2, 0xb0, 
    0xb2, 0x7, 0x3d, 0x2, 0x2, 0xb1, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb5, 0x5, 
    0x76, 0x3c, 0x2, 0xb4, 0xb6, 0x5, 0x3a, 0x1e, 0x2, 0xb5, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xb7, 0xb8, 0x7, 0x20, 0x2, 0x2, 0xb8, 0xba, 0x5, 0x48, 0x25, 
    0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xba, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0xbc, 0x2, 0x2, 0xbc, 
    0xbe, 0x5, 0x14, 0xb, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc5, 0x7, 
    0x13, 0x2, 0x2, 0xc0, 0xc6, 0x5, 0xa, 0x6, 0x2, 0xc1, 0xc2, 0x7, 0x4, 
    0x2, 0x2, 0xc2, 0xc3, 0x5, 0xa, 0x6, 0x2, 0xc3, 0xc4, 0x7, 0x5, 0x2, 
    0x2, 0xc4, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc9, 0x7, 0xbc, 0x2, 0x2, 0xc8, 0xca, 0x7, 0x6f, 0x2, 0x2, 0xc9, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xcd, 0x7, 0x2d, 0x2, 0x2, 0xcc, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xcf, 0x7, 0x24, 0x2, 0x2, 0xcf, 0xd3, 0x7, 0xa3, 0x2, 0x2, 
    0xd0, 0xd1, 0x7, 0x50, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x71, 0x2, 0x2, 0xd2, 
    0xd4, 0x7, 0x3d, 0x2, 0x2, 0xd3, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x5, 
    0x76, 0x3c, 0x2, 0xd6, 0xd7, 0x7, 0x4, 0x2, 0x2, 0xd7, 0xdc, 0x5, 0xe, 
    0x8, 0x2, 0xd8, 0xd9, 0x7, 0x6, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0xe, 0x8, 
    0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe2, 
    0x7, 0x5, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x20, 0x2, 0x2, 0xe1, 0xe3, 0x5, 
    0x48, 0x25, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0xbc, 0x2, 
    0x2, 0xe5, 0xe7, 0x5, 0x14, 0xb, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x20a, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x7, 0x36, 0x2, 0x2, 0xe9, 0xec, 0x7, 0xa3, 0x2, 0x2, 0xea, 0xeb, 
    0x7, 0x50, 0x2, 0x2, 0xeb, 0xed, 0x7, 0x3d, 0x2, 0x2, 0xec, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 
    0x2, 0x2, 0xee, 0x20a, 0x5, 0x76, 0x3c, 0x2, 0xef, 0xf0, 0x7, 0x55, 
    0x2, 0x2, 0xf0, 0xf1, 0x7, 0x58, 0x2, 0x2, 0xf1, 0xf3, 0x5, 0x76, 0x3c, 
    0x2, 0xf2, 0xf4, 0x5, 0x3a, 0x1e, 0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf5, 
    0xf6, 0x5, 0xa, 0x6, 0x2, 0xf6, 0x20a, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 
    0x7, 0x31, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x46, 0x2, 0x2, 0xf9, 0xfc, 0x5, 
    0x76, 0x3c, 0x2, 0xfa, 0xfb, 0x7, 0xbb, 0x2, 0x2, 0xfb, 0xfd, 0x5, 0x40, 
    0x21, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0x20a, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0xe, 0x2, 0x2, 
    0xff, 0x100, 0x7, 0xa3, 0x2, 0x2, 0x100, 0x101, 0x5, 0x76, 0x3c, 0x2, 
    0x101, 0x102, 0x7, 0x8a, 0x2, 0x2, 0x102, 0x103, 0x7, 0xaa, 0x2, 0x2, 
    0x103, 0x104, 0x5, 0x76, 0x3c, 0x2, 0x104, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0x106, 0x7, 0xe, 0x2, 0x2, 0x106, 0x107, 0x7, 0xa3, 0x2, 0x2, 
    0x107, 0x108, 0x5, 0x76, 0x3c, 0x2, 0x108, 0x109, 0x7, 0x8a, 0x2, 0x2, 
    0x109, 0x10a, 0x7, 0x1e, 0x2, 0x2, 0x10a, 0x10b, 0x5, 0x78, 0x3d, 0x2, 
    0x10b, 0x10c, 0x7, 0xaa, 0x2, 0x2, 0x10c, 0x10d, 0x5, 0x78, 0x3d, 0x2, 
    0x10d, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0xe, 0x2, 0x2, 
    0x10f, 0x110, 0x7, 0xa3, 0x2, 0x2, 0x110, 0x111, 0x5, 0x76, 0x3c, 0x2, 
    0x111, 0x112, 0x7, 0x36, 0x2, 0x2, 0x112, 0x113, 0x7, 0x1e, 0x2, 0x2, 
    0x113, 0x114, 0x5, 0x76, 0x3c, 0x2, 0x114, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x115, 0x116, 0x7, 0xe, 0x2, 0x2, 0x116, 0x117, 0x7, 0xa3, 0x2, 0x2, 
    0x117, 0x118, 0x5, 0x76, 0x3c, 0x2, 0x118, 0x119, 0x7, 0xc, 0x2, 0x2, 
    0x119, 0x11a, 0x7, 0x1e, 0x2, 0x2, 0x11a, 0x11b, 0x5, 0x10, 0x9, 0x2, 
    0x11b, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11f, 0x7, 0x24, 0x2, 0x2, 
    0x11d, 0x11e, 0x7, 0x78, 0x2, 0x2, 0x11e, 0x120, 0x7, 0x8c, 0x2, 0x2, 
    0x11f, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x121, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0xb9, 0x2, 0x2, 
    0x122, 0x123, 0x5, 0x76, 0x3c, 0x2, 0x123, 0x124, 0x7, 0x13, 0x2, 0x2, 
    0x124, 0x125, 0x5, 0xa, 0x6, 0x2, 0x125, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x126, 0x127, 0x7, 0x36, 0x2, 0x2, 0x127, 0x12a, 0x7, 0xb9, 0x2, 0x2, 
    0x128, 0x129, 0x7, 0x50, 0x2, 0x2, 0x129, 0x12b, 0x7, 0x3d, 0x2, 0x2, 
    0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x20a, 0x5, 0x76, 0x3c, 0x2, 
    0x12d, 0x12e, 0x7, 0x19, 0x2, 0x2, 0x12e, 0x12f, 0x5, 0x76, 0x3c, 0x2, 
    0x12f, 0x138, 0x7, 0x4, 0x2, 0x2, 0x130, 0x135, 0x5, 0x6e, 0x38, 0x2, 
    0x131, 0x132, 0x7, 0x6, 0x2, 0x2, 0x132, 0x134, 0x5, 0x6e, 0x38, 0x2, 
    0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x137, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 
    0x136, 0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x130, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0x5, 0x2, 0x2, 
    0x13b, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x147, 0x7, 0x49, 0x2, 0x2, 
    0x13d, 0x142, 0x5, 0x74, 0x3b, 0x2, 0x13e, 0x13f, 0x7, 0x6, 0x2, 0x2, 
    0x13f, 0x141, 0x5, 0x74, 0x3b, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x144, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x7, 0xd, 0x2, 0x2, 
    0x146, 0x148, 0x7, 0x84, 0x2, 0x2, 0x147, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x145, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x14b, 0x7, 0x75, 0x2, 0x2, 0x14a, 0x14c, 0x7, 0xa3, 0x2, 0x2, 
    0x14b, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x5, 0x76, 0x3c, 0x2, 
    0x14e, 0x14f, 0x7, 0xaa, 0x2, 0x2, 0x14f, 0x153, 0x5, 0x78, 0x3d, 0x2, 
    0x150, 0x151, 0x7, 0xbc, 0x2, 0x2, 0x151, 0x152, 0x7, 0x49, 0x2, 0x2, 
    0x152, 0x154, 0x7, 0x77, 0x2, 0x2, 0x153, 0x150, 0x3, 0x2, 0x2, 0x2, 
    0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x159, 0x7, 0x8f, 0x2, 0x2, 0x156, 0x157, 0x7, 0x49, 0x2, 0x2, 
    0x157, 0x158, 0x7, 0x77, 0x2, 0x2, 0x158, 0x15a, 0x7, 0x44, 0x2, 0x2, 
    0x159, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x165, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x160, 0x5, 0x74, 0x3b, 0x2, 
    0x15c, 0x15d, 0x7, 0x6, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x74, 0x3b, 0x2, 
    0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x166, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x164, 0x7, 0xd, 0x2, 0x2, 0x164, 0x166, 0x7, 0x84, 0x2, 0x2, 
    0x165, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 
    0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x169, 0x7, 0x75, 0x2, 0x2, 
    0x168, 0x16a, 0x7, 0xa3, 0x2, 0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 
    0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 0x2, 
    0x16b, 0x16c, 0x5, 0x76, 0x3c, 0x2, 0x16c, 0x16d, 0x7, 0x46, 0x2, 0x2, 
    0x16d, 0x16e, 0x5, 0x78, 0x3d, 0x2, 0x16e, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x16f, 0x170, 0x7, 0x9d, 0x2, 0x2, 0x170, 0x176, 0x7, 0x4a, 0x2, 0x2, 
    0x171, 0x173, 0x7, 0x75, 0x2, 0x2, 0x172, 0x174, 0x7, 0xa3, 0x2, 0x2, 
    0x173, 0x172, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 
    0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x177, 0x5, 0x76, 0x3c, 0x2, 
    0x176, 0x171, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 
    0x177, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 0x7, 0x3e, 0x2, 0x2, 
    0x179, 0x17b, 0x7, 0xf, 0x2, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 
    0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17d, 0x3, 0x2, 0x2, 0x2, 
    0x17c, 0x17e, 0x7, 0xb8, 0x2, 0x2, 0x17d, 0x17c, 0x3, 0x2, 0x2, 0x2, 
    0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x18a, 0x3, 0x2, 0x2, 0x2, 
    0x17f, 0x180, 0x7, 0x4, 0x2, 0x2, 0x180, 0x185, 0x5, 0x68, 0x35, 0x2, 
    0x181, 0x182, 0x7, 0x6, 0x2, 0x2, 0x182, 0x184, 0x5, 0x68, 0x35, 0x2, 
    0x183, 0x181, 0x3, 0x2, 0x2, 0x2, 0x184, 0x187, 0x3, 0x2, 0x2, 0x2, 
    0x185, 0x183, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x3, 0x2, 0x2, 0x2, 
    0x186, 0x188, 0x3, 0x2, 0x2, 0x2, 0x187, 0x185, 0x3, 0x2, 0x2, 0x2, 
    0x188, 0x189, 0x7, 0x5, 0x2, 0x2, 0x189, 0x18b, 0x3, 0x2, 0x2, 0x2, 
    0x18a, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x20a, 0x5, 0x8, 0x5, 0x2, 
    0x18d, 0x18e, 0x7, 0x9d, 0x2, 0x2, 0x18e, 0x18f, 0x7, 0x24, 0x2, 0x2, 
    0x18f, 0x190, 0x7, 0xa3, 0x2, 0x2, 0x190, 0x20a, 0x5, 0x76, 0x3c, 0x2, 
    0x191, 0x192, 0x7, 0x9d, 0x2, 0x2, 0x192, 0x193, 0x7, 0x24, 0x2, 0x2, 
    0x193, 0x194, 0x7, 0xb9, 0x2, 0x2, 0x194, 0x20a, 0x5, 0x76, 0x3c, 0x2, 
    0x195, 0x196, 0x7, 0x9d, 0x2, 0x2, 0x196, 0x199, 0x7, 0xa4, 0x2, 0x2, 
    0x197, 0x198, 0x9, 0x3, 0x2, 0x2, 0x198, 0x19a, 0x5, 0x76, 0x3c, 0x2, 
    0x199, 0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x7, 0x62, 0x2, 0x2, 
    0x19c, 0x19f, 0x5, 0x48, 0x25, 0x2, 0x19d, 0x19e, 0x7, 0x39, 0x2, 0x2, 
    0x19e, 0x1a0, 0x5, 0x48, 0x25, 0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 
    0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a2, 0x3, 0x2, 0x2, 0x2, 
    0x1a1, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a2, 0x3, 0x2, 0x2, 0x2, 
    0x1a2, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x9d, 0x2, 0x2, 
    0x1a4, 0x1a7, 0x7, 0x96, 0x2, 0x2, 0x1a5, 0x1a6, 0x9, 0x3, 0x2, 0x2, 
    0x1a6, 0x1a8, 0x5, 0x78, 0x3d, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1af, 0x3, 0x2, 0x2, 0x2, 
    0x1a9, 0x1aa, 0x7, 0x62, 0x2, 0x2, 0x1aa, 0x1ad, 0x5, 0x48, 0x25, 0x2, 
    0x1ab, 0x1ac, 0x7, 0x39, 0x2, 0x2, 0x1ac, 0x1ae, 0x5, 0x48, 0x25, 0x2, 
    0x1ad, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1a9, 0x3, 0x2, 0x2, 0x2, 
    0x1af, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x1b1, 0x1b2, 0x7, 0x9d, 0x2, 0x2, 0x1b2, 0x1b5, 0x7, 0x1d, 0x2, 0x2, 
    0x1b3, 0x1b4, 0x7, 0x62, 0x2, 0x2, 0x1b4, 0x1b6, 0x5, 0x48, 0x25, 0x2, 
    0x1b5, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x3, 0x2, 0x2, 0x2, 
    0x1b6, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x1b7, 0x1b8, 0x7, 0x9d, 0x2, 0x2, 
    0x1b8, 0x1b9, 0x7, 0x1f, 0x2, 0x2, 0x1b9, 0x1ba, 0x9, 0x3, 0x2, 0x2, 
    0x1ba, 0x20a, 0x5, 0x76, 0x3c, 0x2, 0x1bb, 0x1bc, 0x7, 0x9d, 0x2, 0x2, 
    0x1bc, 0x1bd, 0x7, 0xa0, 0x2, 0x2, 0x1bd, 0x1be, 0x9, 0x4, 0x2, 0x2, 
    0x1be, 0x20a, 0x5, 0x76, 0x3c, 0x2, 0x1bf, 0x1c0, 0x7, 0x9d, 0x2, 0x2, 
    0x1c0, 0x1c1, 0x7, 0xa0, 0x2, 0x2, 0x1c1, 0x1c2, 0x7, 0x44, 0x2, 0x2, 
    0x1c2, 0x1c3, 0x7, 0x4, 0x2, 0x2, 0x1c3, 0x1c4, 0x5, 0x20, 0x11, 0x2, 
    0x1c4, 0x1c5, 0x7, 0x5, 0x2, 0x2, 0x1c5, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x1c6, 0x1c7, 0x7, 0x33, 0x2, 0x2, 0x1c7, 0x20a, 0x5, 0x76, 0x3c, 0x2, 
    0x1c8, 0x1c9, 0x7, 0x32, 0x2, 0x2, 0x1c9, 0x20a, 0x5, 0x76, 0x3c, 0x2, 
    0x1ca, 0x1cb, 0x7, 0x9d, 0x2, 0x2, 0x1cb, 0x20a, 0x7, 0x48, 0x2, 0x2, 
    0x1cc, 0x1cd, 0x7, 0x9d, 0x2, 0x2, 0x1cd, 0x20a, 0x7, 0x9a, 0x2, 0x2, 
    0x1ce, 0x1cf, 0x7, 0x9b, 0x2, 0x2, 0x1cf, 0x1d0, 0x7, 0x9a, 0x2, 0x2, 
    0x1d0, 0x1d1, 0x5, 0x76, 0x3c, 0x2, 0x1d1, 0x1d2, 0x7, 0xc1, 0x2, 0x2, 
    0x1d2, 0x1d3, 0x5, 0x3e, 0x20, 0x2, 0x1d3, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x1d5, 0x7, 0x8d, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x9a, 0x2, 0x2, 
    0x1d6, 0x20a, 0x5, 0x76, 0x3c, 0x2, 0x1d7, 0x1d8, 0x7, 0x9f, 0x2, 0x2, 
    0x1d8, 0x1e1, 0x7, 0xab, 0x2, 0x2, 0x1d9, 0x1de, 0x5, 0x6a, 0x36, 0x2, 
    0x1da, 0x1db, 0x7, 0x6, 0x2, 0x2, 0x1db, 0x1dd, 0x5, 0x6a, 0x36, 0x2, 
    0x1dc, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e0, 0x3, 0x2, 0x2, 0x2, 
    0x1de, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 
    0x1df, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 
    0x1e1, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e2, 0x3, 0x2, 0x2, 0x2, 
    0x1e2, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e5, 0x7, 0x21, 0x2, 0x2, 
    0x1e4, 0x1e6, 0x7, 0xbd, 0x2, 0x2, 0x1e5, 0x1e4, 0x3, 0x2, 0x2, 0x2, 
    0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x1e7, 0x1e9, 0x7, 0x91, 0x2, 0x2, 0x1e8, 0x1ea, 0x7, 0xbd, 0x2, 0x2, 
    0x1e9, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1ea, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ec, 0x7, 0x83, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x5, 0x78, 0x3d, 0x2, 0x1ed, 0x1ee, 0x7, 0x46, 0x2, 0x2, 
    0x1ee, 0x1ef, 0x5, 0x8, 0x5, 0x2, 0x1ef, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1f1, 0x7, 0x30, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x83, 0x2, 0x2, 
    0x1f2, 0x20a, 0x5, 0x78, 0x3d, 0x2, 0x1f3, 0x1f4, 0x7, 0x3c, 0x2, 0x2, 
    0x1f4, 0x1fe, 0x5, 0x78, 0x3d, 0x2, 0x1f5, 0x1f6, 0x7, 0xb5, 0x2, 0x2, 
    0x1f6, 0x1fb, 0x5, 0x3e, 0x20, 0x2, 0x1f7, 0x1f8, 0x7, 0x6, 0x2, 0x2, 
    0x1f8, 0x1fa, 0x5, 0x3e, 0x20, 0x2, 0x1f9, 0x1f7, 0x3, 0x2, 0x2, 0x2, 
    0x1fa, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x1fb, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ff, 0x3, 0x2, 0x2, 0x2, 
    0x1fd, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1f5, 0x3, 0x2, 0x2, 0x2, 
    0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x200, 0x201, 0x7, 0x33, 0x2, 0x2, 0x201, 0x202, 0x7, 0x54, 0x2, 0x2, 
    0x202, 0x20a, 0x5, 0x78, 0x3d, 0x2, 0x203, 0x204, 0x7, 0x33, 0x2, 0x2, 
    0x204, 0x205, 0x7, 0x7c, 0x2, 0x2, 0x205, 0x20a, 0x5, 0x78, 0x3d, 0x2, 
    0x206, 0x207, 0x7, 0x9b, 0x2, 0x2, 0x207, 0x208, 0x7, 0x80, 0x2, 0x2, 
    0x208, 0x20a, 0x5, 0x72, 0x3a, 0x2, 0x209, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x209, 0x88, 0x3, 0x2, 0x2, 0x2, 0x209, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x209, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x209, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x209, 0xa5, 
    0x3, 0x2, 0x2, 0x2, 0x209, 0xac, 0x3, 0x2, 0x2, 0x2, 0x209, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0x209, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x209, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0x209, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x209, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x105, 0x3, 0x2, 0x2, 0x2, 0x209, 0x10e, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x115, 0x3, 0x2, 0x2, 0x2, 0x209, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x126, 0x3, 0x2, 0x2, 0x2, 0x209, 0x12d, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x209, 0x155, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x209, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x209, 0x191, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x195, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1b7, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1bf, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1c8, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1cc, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1d4, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1e3, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1eb, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x209, 0x1f3, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x200, 0x3, 0x2, 0x2, 0x2, 0x209, 0x203, 0x3, 0x2, 0x2, 
    0x2, 0x209, 0x206, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x20b, 0x20d, 0x5, 0xc, 0x7, 0x2, 0x20c, 0x20b, 0x3, 0x2, 0x2, 0x2, 
    0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20e, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x20f, 0x5, 0x18, 0xd, 0x2, 0x20f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x210, 
    0x212, 0x7, 0xbc, 0x2, 0x2, 0x211, 0x213, 0x7, 0x89, 0x2, 0x2, 0x212, 
    0x211, 0x3, 0x2, 0x2, 0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 
    0x214, 0x3, 0x2, 0x2, 0x2, 0x214, 0x219, 0x5, 0x28, 0x15, 0x2, 0x215, 
    0x216, 0x7, 0x6, 0x2, 0x2, 0x216, 0x218, 0x5, 0x28, 0x15, 0x2, 0x217, 
    0x215, 0x3, 0x2, 0x2, 0x2, 0x218, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x219, 
    0x217, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21a, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x21f, 
    0x5, 0x10, 0x9, 0x2, 0x21d, 0x21f, 0x5, 0x12, 0xa, 0x2, 0x21e, 0x21c, 
    0x3, 0x2, 0x2, 0x2, 0x21e, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x21f, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x220, 0x221, 0x5, 0x78, 0x3d, 0x2, 0x221, 0x224, 0x5, 
    0x58, 0x2d, 0x2, 0x222, 0x223, 0x7, 0x20, 0x2, 0x2, 0x223, 0x225, 0x5, 
    0x48, 0x25, 0x2, 0x224, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x3, 
    0x2, 0x2, 0x2, 0x225, 0x228, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x7, 
    0xbc, 0x2, 0x2, 0x227, 0x229, 0x5, 0x14, 0xb, 0x2, 0x228, 0x226, 0x3, 
    0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 0x2, 0x229, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x22a, 0x22b, 0x7, 0x62, 0x2, 0x2, 0x22b, 0x22e, 0x5, 0x76, 
    0x3c, 0x2, 0x22c, 0x22d, 0x9, 0x5, 0x2, 0x2, 0x22d, 0x22f, 0x7, 0x85, 
    0x2, 0x2, 0x22e, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x3, 0x2, 
    0x2, 0x2, 0x22f, 0x13, 0x3, 0x2, 0x2, 0x2, 0x230, 0x231, 0x7, 0x4, 0x2, 
    0x2, 0x231, 0x236, 0x5, 0x16, 0xc, 0x2, 0x232, 0x233, 0x7, 0x6, 0x2, 
    0x2, 0x233, 0x235, 0x5, 0x16, 0xc, 0x2, 0x234, 0x232, 0x3, 0x2, 0x2, 
    0x2, 0x235, 0x238, 0x3, 0x2, 0x2, 0x2, 0x236, 0x234, 0x3, 0x2, 0x2, 
    0x2, 0x236, 0x237, 0x3, 0x2, 0x2, 0x2, 0x237, 0x239, 0x3, 0x2, 0x2, 
    0x2, 0x238, 0x236, 0x3, 0x2, 0x2, 0x2, 0x239, 0x23a, 0x7, 0x5, 0x2, 
    0x2, 0x23a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23c, 0x5, 0x78, 0x3d, 
    0x2, 0x23c, 0x23d, 0x7, 0xc1, 0x2, 0x2, 0x23d, 0x23e, 0x5, 0x3e, 0x20, 
    0x2, 0x23e, 0x17, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x24a, 0x5, 0x1a, 0xe, 
    0x2, 0x240, 0x241, 0x7, 0x79, 0x2, 0x2, 0x241, 0x242, 0x7, 0x18, 0x2, 
    0x2, 0x242, 0x247, 0x5, 0x1e, 0x10, 0x2, 0x243, 0x244, 0x7, 0x6, 0x2, 
    0x2, 0x244, 0x246, 0x5, 0x1e, 0x10, 0x2, 0x245, 0x243, 0x3, 0x2, 0x2, 
    0x2, 0x246, 0x249, 0x3, 0x2, 0x2, 0x2, 0x247, 0x245, 0x3, 0x2, 0x2, 
    0x2, 0x247, 0x248, 0x3, 0x2, 0x2, 0x2, 0x248, 0x24b, 0x3, 0x2, 0x2, 
    0x2, 0x249, 0x247, 0x3, 0x2, 0x2, 0x2, 0x24a, 0x240, 0x3, 0x2, 0x2, 
    0x2, 0x24a, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24e, 0x3, 0x2, 0x2, 
    0x2, 0x24c, 0x24d, 0x7, 0x63, 0x2, 0x2, 0x24d, 0x24f, 0x9, 0x6, 0x2, 
    0x2, 0x24e, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x3, 0x2, 0x2, 
    0x2, 0x24f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x250, 0x251, 0x8, 0xe, 0x1, 0x2, 
    0x251, 0x252, 0x5, 0x1c, 0xf, 0x2, 0x252, 0x261, 0x3, 0x2, 0x2, 0x2, 
    0x253, 0x254, 0xc, 0x4, 0x2, 0x2, 0x254, 0x256, 0x7, 0x56, 0x2, 0x2, 
    0x255, 0x257, 0x5, 0x2a, 0x16, 0x2, 0x256, 0x255, 0x3, 0x2, 0x2, 0x2, 
    0x256, 0x257, 0x3, 0x2, 0x2, 0x2, 0x257, 0x258, 0x3, 0x2, 0x2, 0x2, 
    0x258, 0x260, 0x5, 0x1a, 0xe, 0x5, 0x259, 0x25a, 0xc, 0x3, 0x2, 0x2, 
    0x25a, 0x25c, 0x9, 0x7, 0x2, 0x2, 0x25b, 0x25d, 0x5, 0x2a, 0x16, 0x2, 
    0x25c, 0x25b, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 0x3, 0x2, 0x2, 0x2, 
    0x25d, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x260, 0x5, 0x1a, 0xe, 0x4, 
    0x25f, 0x253, 0x3, 0x2, 0x2, 0x2, 0x25f, 0x259, 0x3, 0x2, 0x2, 0x2, 
    0x260, 0x263, 0x3, 0x2, 0x2, 0x2, 0x261, 0x25f, 0x3, 0x2, 0x2, 0x2, 
    0x261, 0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x263, 
    0x261, 0x3, 0x2, 0x2, 0x2, 0x264, 0x275, 0x5, 0x20, 0x11, 0x2, 0x265, 
    0x266, 0x7, 0xa3, 0x2, 0x2, 0x266, 0x275, 0x5, 0x76, 0x3c, 0x2, 0x267, 
    0x268, 0x7, 0xb7, 0x2, 0x2, 0x268, 0x26d, 0x5, 0x3e, 0x20, 0x2, 0x269, 
    0x26a, 0x7, 0x6, 0x2, 0x2, 0x26a, 0x26c, 0x5, 0x3e, 0x20, 0x2, 0x26b, 
    0x269, 0x3, 0x2, 0x2, 0x2, 0x26c, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x26d, 
    0x26b, 0x3, 0x2, 0x2, 0x2, 0x26d, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x26e, 
    0x275, 0x3, 0x2, 0x2, 0x2, 0x26f, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x270, 
    0x271, 0x7, 0x4, 0x2, 0x2, 0x271, 0x272, 0x5, 0x18, 0xd, 0x2, 0x272, 
    0x273, 0x7, 0x5, 0x2, 0x2, 0x273, 0x275, 0x3, 0x2, 0x2, 0x2, 0x274, 
    0x264, 0x3, 0x2, 0x2, 0x2, 0x274, 0x265, 0x3, 0x2, 0x2, 0x2, 0x274, 
    0x267, 0x3, 0x2, 0x2, 0x2, 0x274, 0x270, 0x3, 0x2, 0x2, 0x2, 0x275, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x276, 0x278, 0x5, 0x3e, 0x20, 0x2, 0x277, 
    0x279, 0x9, 0x8, 0x2, 0x2, 0x278, 0x277, 0x3, 0x2, 0x2, 0x2, 0x278, 
    0x279, 0x3, 0x2, 0x2, 0x2, 0x279, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x27a, 
    0x27b, 0x7, 0x74, 0x2, 0x2, 0x27b, 0x27d, 0x9, 0x9, 0x2, 0x2, 0x27c, 
    0x27a, 0x3, 0x2, 0x2, 0x2, 0x27c, 0x27d, 0x3, 0x2, 0x2, 0x2, 0x27d, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0x27e, 0x280, 0x7, 0x98, 0x2, 0x2, 0x27f, 
    0x281, 0x5, 0x2a, 0x16, 0x2, 0x280, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x280, 
    0x281, 0x3, 0x2, 0x2, 0x2, 0x281, 0x282, 0x3, 0x2, 0x2, 0x2, 0x282, 
    0x287, 0x5, 0x2c, 0x17, 0x2, 0x283, 0x284, 0x7, 0x6, 0x2, 0x2, 0x284, 
    0x286, 0x5, 0x2c, 0x17, 0x2, 0x285, 0x283, 0x3, 0x2, 0x2, 0x2, 0x286, 
    0x289, 0x3, 0x2, 0x2, 0x2, 0x287, 0x285, 0x3, 0x2, 0x2, 0x2, 0x287, 
    0x288, 0x3, 0x2, 0x2, 0x2, 0x288, 0x293, 0x3, 0x2, 0x2, 0x2, 0x289, 
    0x287, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x28b, 0x7, 0x46, 0x2, 0x2, 0x28b, 
    0x290, 0x5, 0x2e, 0x18, 0x2, 0x28c, 0x28d, 0x7, 0x6, 0x2, 0x2, 0x28d, 
    0x28f, 0x5, 0x2e, 0x18, 0x2, 0x28e, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x28f, 
    0x292, 0x3, 0x2, 0x2, 0x2, 0x290, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x290, 
    0x291, 0x3, 0x2, 0x2, 0x2, 0x291, 0x294, 0x3, 0x2, 0x2, 0x2, 0x292, 
    0x290, 0x3, 0x2, 0x2, 0x2, 0x293, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x293, 
    0x294, 0x3, 0x2, 0x2, 0x2, 0x294, 0x297, 0x3, 0x2, 0x2, 0x2, 0x295, 
    0x296, 0x7, 0xbb, 0x2, 0x2, 0x296, 0x298, 0x5, 0x40, 0x21, 0x2, 0x297, 
    0x295, 0x3, 0x2, 0x2, 0x2, 0x297, 0x298, 0x3, 0x2, 0x2, 0x2, 0x298, 
    0x29c, 0x3, 0x2, 0x2, 0x2, 0x299, 0x29a, 0x7, 0x4c, 0x2, 0x2, 0x29a, 
    0x29b, 0x7, 0x18, 0x2, 0x2, 0x29b, 0x29d, 0x5, 0x22, 0x12, 0x2, 0x29c, 
    0x299, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x29d, 
    0x2a0, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x29f, 0x7, 0x4e, 0x2, 0x2, 0x29f, 
    0x2a1, 0x5, 0x40, 0x21, 0x2, 0x2a0, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
    0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2a2, 0x2a4, 
    0x5, 0x2a, 0x16, 0x2, 0x2a3, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x2a4, 
    0x3, 0x2, 0x2, 0x2, 0x2a4, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2aa, 
    0x5, 0x24, 0x13, 0x2, 0x2a6, 0x2a7, 0x7, 0x6, 0x2, 0x2, 0x2a7, 0x2a9, 
    0x5, 0x24, 0x13, 0x2, 0x2a8, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a9, 0x2ac, 
    0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 
    0x3, 0x2, 0x2, 0x2, 0x2ab, 0x23, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2aa, 0x3, 
    0x2, 0x2, 0x2, 0x2ad, 0x2d6, 0x5, 0x26, 0x14, 0x2, 0x2ae, 0x2af, 0x7, 
    0x92, 0x2, 0x2, 0x2af, 0x2b8, 0x7, 0x4, 0x2, 0x2, 0x2b0, 0x2b5, 0x5, 
    0x3e, 0x20, 0x2, 0x2b1, 0x2b2, 0x7, 0x6, 0x2, 0x2, 0x2b2, 0x2b4, 0x5, 
    0x3e, 0x20, 0x2, 0x2b3, 0x2b1, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2b7, 0x3, 
    0x2, 0x2, 0x2, 0x2b5, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b6, 0x3, 
    0x2, 0x2, 0x2, 0x2b6, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x2b5, 0x3, 
    0x2, 0x2, 0x2, 0x2b8, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x2b8, 0x2b9, 0x3, 
    0x2, 0x2, 0x2, 0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2d6, 0x7, 
    0x5, 0x2, 0x2, 0x2bb, 0x2bc, 0x7, 0x26, 0x2, 0x2, 0x2bc, 0x2c5, 0x7, 
    0x4, 0x2, 0x2, 0x2bd, 0x2c2, 0x5, 0x3e, 0x20, 0x2, 0x2be, 0x2bf, 0x7, 
    0x6, 0x2, 0x2, 0x2bf, 0x2c1, 0x5, 0x3e, 0x20, 0x2, 0x2c0, 0x2be, 0x3, 
    0x2, 0x2, 0x2, 0x2c1, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c2, 0x2c0, 0x3, 
    0x2, 0x2, 0x2, 0x2c2, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c6, 0x3, 
    0x2, 0x2, 0x2, 0x2c4, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2bd, 0x3, 
    0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c7, 0x3, 
    0x2, 0x2, 0x2, 0x2c7, 0x2d6, 0x7, 0x5, 0x2, 0x2, 0x2c8, 0x2c9, 0x7, 
    0x4d, 0x2, 0x2, 0x2c9, 0x2ca, 0x7, 0x9c, 0x2, 0x2, 0x2ca, 0x2cb, 0x7, 
    0x4, 0x2, 0x2, 0x2cb, 0x2d0, 0x5, 0x26, 0x14, 0x2, 0x2cc, 0x2cd, 0x7, 
    0x6, 0x2, 0x2, 0x2cd, 0x2cf, 0x5, 0x26, 0x14, 0x2, 0x2ce, 0x2cc, 0x3, 
    0x2, 0x2, 0x2, 0x2cf, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2ce, 0x3, 
    0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2d3, 0x3, 
    0x2, 0x2, 0x2, 0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d4, 0x7, 
    0x5, 0x2, 0x2, 0x2d4, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2ad, 0x3, 
    0x2, 0x2, 0x2, 0x2d5, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2bb, 0x3, 
    0x2, 0x2, 0x2, 0x2d5, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x2d7, 0x2e0, 0x7, 0x4, 0x2, 0x2, 0x2d8, 0x2dd, 0x5, 0x3e, 
    0x20, 0x2, 0x2d9, 0x2da, 0x7, 0x6, 0x2, 0x2, 0x2da, 0x2dc, 0x5, 0x3e, 
    0x20, 0x2, 0x2db, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2df, 0x3, 0x2, 
    0x2, 0x2, 0x2dd, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2de, 0x3, 0x2, 
    0x2, 0x2, 0x2de, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x2df, 0x2dd, 0x3, 0x2, 
    0x2, 0x2, 0x2e0, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 0x3, 0x2, 
    0x2, 0x2, 0x2e1, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e5, 0x7, 0x5, 
    0x2, 0x2, 0x2e3, 0x2e5, 0x5, 0x3e, 0x20, 0x2, 0x2e4, 0x2d7, 0x3, 0x2, 
    0x2, 0x2, 0x2e4, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x2e6, 0x2e8, 0x5, 0x78, 0x3d, 0x2, 0x2e7, 0x2e9, 0x5, 0x3a, 0x1e, 
    0x2, 0x2e8, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 0x3, 0x2, 0x2, 
    0x2, 0x2e9, 0x2ea, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 0x7, 0x13, 0x2, 
    0x2, 0x2eb, 0x2ec, 0x7, 0x4, 0x2, 0x2, 0x2ec, 0x2ed, 0x5, 0xa, 0x6, 
    0x2, 0x2ed, 0x2ee, 0x7, 0x5, 0x2, 0x2, 0x2ee, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x2ef, 0x2f0, 0x9, 0xa, 0x2, 0x2, 0x2f0, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2f1, 
    0x2f6, 0x5, 0x3e, 0x20, 0x2, 0x2f2, 0x2f4, 0x7, 0x13, 0x2, 0x2, 0x2f3, 
    0x2f2, 0x3, 0x2, 0x2, 0x2, 0x2f3, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x2f4, 
    0x2f5, 0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f7, 0x5, 0x78, 0x3d, 0x2, 0x2f6, 
    0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2f6, 0x2f7, 0x3, 0x2, 0x2, 0x2, 0x2f7, 
    0x2fe, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x5, 0x76, 0x3c, 0x2, 0x2f9, 
    0x2fa, 0x7, 0x3, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0xc9, 0x2, 0x2, 0x2fb, 
    0x2fe, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fe, 0x7, 0xc9, 0x2, 0x2, 0x2fd, 
    0x2f1, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2fd, 
    0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x300, 
    0x8, 0x18, 0x1, 0x2, 0x300, 0x301, 0x5, 0x34, 0x1b, 0x2, 0x301, 0x314, 
    0x3, 0x2, 0x2, 0x2, 0x302, 0x310, 0xc, 0x4, 0x2, 0x2, 0x303, 0x304, 
    0x7, 0x25, 0x2, 0x2, 0x304, 0x305, 0x7, 0x5d, 0x2, 0x2, 0x305, 0x311, 
    0x5, 0x34, 0x1b, 0x2, 0x306, 0x307, 0x5, 0x30, 0x19, 0x2, 0x307, 0x308, 
    0x7, 0x5d, 0x2, 0x2, 0x308, 0x309, 0x5, 0x2e, 0x18, 0x2, 0x309, 0x30a, 
    0x5, 0x32, 0x1a, 0x2, 0x30a, 0x311, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30c, 
    0x7, 0x6a, 0x2, 0x2, 0x30c, 0x30d, 0x5, 0x30, 0x19, 0x2, 0x30d, 0x30e, 
    0x7, 0x5d, 0x2, 0x2, 0x30e, 0x30f, 0x5, 0x34, 0x1b, 0x2, 0x30f, 0x311, 
    0x3, 0x2, 0x2, 0x2, 0x310, 0x303, 0x3, 0x2, 0x2, 0x2, 0x310, 0x306, 
    0x3, 0x2, 0x2, 0x2, 0x310, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x311, 0x313, 
    0x3, 0x2, 0x2, 0x2, 0x312, 0x302, 0x3, 0x2, 0x2, 0x2, 0x313, 0x316, 
    0x3, 0x2, 0x2, 0x2, 0x314, 0x312, 0x3, 0x2, 0x2, 0x2, 0x314, 0x315, 
    0x3, 0x2, 0x2, 0x2, 0x315, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x316, 0x314, 0x3, 
    0x2, 0x2, 0x2, 0x317, 0x319, 0x7, 0x53, 0x2, 0x2, 0x318, 0x317, 0x3, 
    0x2, 0x2, 0x2, 0x318, 0x319, 0x3, 0x2, 0x2, 0x2, 0x319, 0x327, 0x3, 
    0x2, 0x2, 0x2, 0x31a, 0x31c, 0x7, 0x60, 0x2, 0x2, 0x31b, 0x31d, 0x7, 
    0x7b, 0x2, 0x2, 0x31c, 0x31b, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x3, 
    0x2, 0x2, 0x2, 0x31d, 0x327, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x320, 0x7, 
    0x90, 0x2, 0x2, 0x31f, 0x321, 0x7, 0x7b, 0x2, 0x2, 0x320, 0x31f, 0x3, 
    0x2, 0x2, 0x2, 0x320, 0x321, 0x3, 0x2, 0x2, 0x2, 0x321, 0x327, 0x3, 
    0x2, 0x2, 0x2, 0x322, 0x324, 0x7, 0x47, 0x2, 0x2, 0x323, 0x325, 0x7, 
    0x7b, 0x2, 0x2, 0x324, 0x323, 0x3, 0x2, 0x2, 0x2, 0x324, 0x325, 0x3, 
    0x2, 0x2, 0x2, 0x325, 0x327, 0x3, 0x2, 0x2, 0x2, 0x326, 0x318, 0x3, 
    0x2, 0x2, 0x2, 0x326, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x326, 0x31e, 0x3, 
    0x2, 0x2, 0x2, 0x326, 0x322, 0x3, 0x2, 0x2, 0x2, 0x327, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x328, 0x329, 0x7, 0x75, 0x2, 0x2, 0x329, 0x337, 0x5, 0x40, 
    0x21, 0x2, 0x32a, 0x32b, 0x7, 0xb5, 0x2, 0x2, 0x32b, 0x32c, 0x7, 0x4, 
    0x2, 0x2, 0x32c, 0x331, 0x5, 0x78, 0x3d, 0x2, 0x32d, 0x32e, 0x7, 0x6, 
    0x2, 0x2, 0x32e, 0x330, 0x5, 0x78, 0x3d, 0x2, 0x32f, 0x32d, 0x3, 0x2, 
    0x2, 0x2, 0x330, 0x333, 0x3, 0x2, 0x2, 0x2, 0x331, 0x32f, 0x3, 0x2, 
    0x2, 0x2, 0x331, 0x332, 0x3, 0x2, 0x2, 0x2, 0x332, 0x334, 0x3, 0x2, 
    0x2, 0x2, 0x333, 0x331, 0x3, 0x2, 0x2, 0x2, 0x334, 0x335, 0x7, 0x5, 
    0x2, 0x2, 0x335, 0x337, 0x3, 0x2, 0x2, 0x2, 0x336, 0x328, 0x3, 0x2, 
    0x2, 0x2, 0x336, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x337, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x338, 0x33f, 0x5, 0x38, 0x1d, 0x2, 0x339, 0x33a, 0x7, 0xa5, 0x2, 
    0x2, 0x33a, 0x33b, 0x5, 0x36, 0x1c, 0x2, 0x33b, 0x33c, 0x7, 0x4, 0x2, 
    0x2, 0x33c, 0x33d, 0x5, 0x3e, 0x20, 0x2, 0x33d, 0x33e, 0x7, 0x5, 0x2, 
    0x2, 0x33e, 0x340, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x339, 0x3, 0x2, 0x2, 
    0x2, 0x33f, 0x340, 0x3, 0x2, 0x2, 0x2, 0x340, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x341, 0x342, 0x9, 0xb, 0x2, 0x2, 0x342, 0x37, 0x3, 0x2, 0x2, 0x2, 0x343, 
    0x34b, 0x5, 0x3c, 0x1f, 0x2, 0x344, 0x346, 0x7, 0x13, 0x2, 0x2, 0x345, 
    0x344, 0x3, 0x2, 0x2, 0x2, 0x345, 0x346, 0x3, 0x2, 0x2, 0x2, 0x346, 
    0x347, 0x3, 0x2, 0x2, 0x2, 0x347, 0x349, 0x5, 0x78, 0x3d, 0x2, 0x348, 
    0x34a, 0x5, 0x3a, 0x1e, 0x2, 0x349, 0x348, 0x3, 0x2, 0x2, 0x2, 0x349, 
    0x34a, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34b, 
    0x345, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x34c, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34e, 0x7, 0x4, 0x2, 0x2, 0x34e, 0x353, 
    0x5, 0x78, 0x3d, 0x2, 0x34f, 0x350, 0x7, 0x6, 0x2, 0x2, 0x350, 0x352, 
    0x5, 0x78, 0x3d, 0x2, 0x351, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x352, 0x355, 
    0x3, 0x2, 0x2, 0x2, 0x353, 0x351, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 
    0x3, 0x2, 0x2, 0x2, 0x354, 0x356, 0x3, 0x2, 0x2, 0x2, 0x355, 0x353, 
    0x3, 0x2, 0x2, 0x2, 0x356, 0x357, 0x7, 0x5, 0x2, 0x2, 0x357, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x358, 0x376, 0x5, 0x76, 0x3c, 0x2, 0x359, 0x35a, 0x7, 
    0x4, 0x2, 0x2, 0x35a, 0x35b, 0x5, 0xa, 0x6, 0x2, 0x35b, 0x35c, 0x7, 
    0x5, 0x2, 0x2, 0x35c, 0x376, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x35e, 0x7, 
    0xb3, 0x2, 0x2, 0x35e, 0x35f, 0x7, 0x4, 0x2, 0x2, 0x35f, 0x364, 0x5, 
    0x3e, 0x20, 0x2, 0x360, 0x361, 0x7, 0x6, 0x2, 0x2, 0x361, 0x363, 0x5, 
    0x3e, 0x20, 0x2, 0x362, 0x360, 0x3, 0x2, 0x2, 0x2, 0x363, 0x366, 0x3, 
    0x2, 0x2, 0x2, 0x364, 0x362, 0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 
    0x2, 0x2, 0x2, 0x365, 0x367, 0x3, 0x2, 0x2, 0x2, 0x366, 0x364, 0x3, 
    0x2, 0x2, 0x2, 0x367, 0x36a, 0x7, 0x5, 0x2, 0x2, 0x368, 0x369, 0x7, 
    0xbc, 0x2, 0x2, 0x369, 0x36b, 0x7, 0x7a, 0x2, 0x2, 0x36a, 0x368, 0x3, 
    0x2, 0x2, 0x2, 0x36a, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x36b, 0x376, 0x3, 
    0x2, 0x2, 0x2, 0x36c, 0x36d, 0x7, 0x5f, 0x2, 0x2, 0x36d, 0x36e, 0x7, 
    0x4, 0x2, 0x2, 0x36e, 0x36f, 0x5, 0xa, 0x6, 0x2, 0x36f, 0x370, 0x7, 
    0x5, 0x2, 0x2, 0x370, 0x376, 0x3, 0x2, 0x2, 0x2, 0x371, 0x372, 0x7, 
    0x4, 0x2, 0x2, 0x372, 0x373, 0x5, 0x2e, 0x18, 0x2, 0x373, 0x374, 0x7, 
    0x5, 0x2, 0x2, 0x374, 0x376, 0x3, 0x2, 0x2, 0x2, 0x375, 0x358, 0x3, 
    0x2, 0x2, 0x2, 0x375, 0x359, 0x3, 0x2, 0x2, 0x2, 0x375, 0x35d, 0x3, 
    0x2, 0x2, 0x2, 0x375, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x375, 0x371, 0x3, 
    0x2, 0x2, 0x2, 0x376, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x5, 0x40, 
    0x21, 0x2, 0x378, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37a, 0x8, 0x21, 
    0x1, 0x2, 0x37a, 0x37c, 0x5, 0x44, 0x23, 0x2, 0x37b, 0x37d, 0x5, 0x42, 
    0x22, 0x2, 0x37c, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37d, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x381, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x37f, 0x7, 0x71, 
    0x2, 0x2, 0x37f, 0x381, 0x5, 0x40, 0x21, 0x5, 0x380, 0x379, 0x3, 0x2, 
    0x2, 0x2, 0x380, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x381, 0x38a, 0x3, 0x2, 
    0x2, 0x2, 0x382, 0x383, 0xc, 0x4, 0x2, 0x2, 0x383, 0x384, 0x7, 0x10, 
    0x2, 0x2, 0x384, 0x389, 0x5, 0x40, 0x21, 0x5, 0x385, 0x386, 0xc, 0x3, 
    0x2, 0x2, 0x386, 0x387, 0x7, 0x78, 0x2, 0x2, 0x387, 0x389, 0x5, 0x40, 
    0x21, 0x4, 0x388, 0x382, 0x3, 0x2, 0x2, 0x2, 0x388, 0x385, 0x3, 0x2, 
    0x2, 0x2, 0x389, 0x38c, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x388, 0x3, 0x2, 
    0x2, 0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 0x38b, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x38c, 0x38a, 0x3, 0x2, 0x2, 0x2, 0x38d, 0x38e, 0x5, 0x4c, 0x27, 
    0x2, 0x38e, 0x38f, 0x5, 0x44, 0x23, 0x2, 0x38f, 0x3cb, 0x3, 0x2, 0x2, 
    0x2, 0x390, 0x391, 0x5, 0x4c, 0x27, 0x2, 0x391, 0x392, 0x5, 0x4e, 0x28, 
    0x2, 0x392, 0x393, 0x7, 0x4, 0x2, 0x2, 0x393, 0x394, 0x5, 0xa, 0x6, 
    0x2, 0x394, 0x395, 0x7, 0x5, 0x2, 0x2, 0x395, 0x3cb, 0x3, 0x2, 0x2, 
    0x2, 0x396, 0x398, 0x7, 0x71, 0x2, 0x2, 0x397, 0x396, 0x3, 0x2, 0x2, 
    0x2, 0x397, 0x398, 0x3, 0x2, 0x2, 0x2, 0x398, 0x399, 0x3, 0x2, 0x2, 
    0x2, 0x399, 0x39a, 0x7, 0x17, 0x2, 0x2, 0x39a, 0x39b, 0x5, 0x44, 0x23, 
    0x2, 0x39b, 0x39c, 0x7, 0x10, 0x2, 0x2, 0x39c, 0x39d, 0x5, 0x44, 0x23, 
    0x2, 0x39d, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x39e, 0x3a0, 0x7, 0x71, 0x2, 
    0x2, 0x39f, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 0x3, 0x2, 0x2, 
    0x2, 0x3a0, 0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a2, 0x7, 0x51, 0x2, 
    0x2, 0x3a2, 0x3a3, 0x7, 0x4, 0x2, 0x2, 0x3a3, 0x3a8, 0x5, 0x3e, 0x20, 
    0x2, 0x3a4, 0x3a5, 0x7, 0x6, 0x2, 0x2, 0x3a5, 0x3a7, 0x5, 0x3e, 0x20, 
    0x2, 0x3a6, 0x3a4, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3aa, 0x3, 0x2, 0x2, 
    0x2, 0x3a8, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 0x3, 0x2, 0x2, 
    0x2, 0x3a9, 0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3a8, 0x3, 0x2, 0x2, 
    0x2, 0x3ab, 0x3ac, 0x7, 0x5, 0x2, 0x2, 0x3ac, 0x3cb, 0x3, 0x2, 0x2, 
    0x2, 0x3ad, 0x3af, 0x7, 0x71, 0x2, 0x2, 0x3ae, 0x3ad, 0x3, 0x2, 0x2, 
    0x2, 0x3ae, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3b0, 0x3, 0x2, 0x2, 
    0x2, 0x3b0, 0x3b1, 0x7, 0x51, 0x2, 0x2, 0x3b1, 0x3b2, 0x7, 0x4, 0x2, 
    0x2, 0x3b2, 0x3b3, 0x5, 0xa, 0x6, 0x2, 0x3b3, 0x3b4, 0x7, 0x5, 0x2, 
    0x2, 0x3b4, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b7, 0x7, 0x71, 0x2, 
    0x2, 0x3b6, 0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b7, 0x3, 0x2, 0x2, 
    0x2, 0x3b7, 0x3b8, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x7, 0x62, 0x2, 
    0x2, 0x3b9, 0x3bc, 0x5, 0x44, 0x23, 0x2, 0x3ba, 0x3bb, 0x7, 0x39, 0x2, 
    0x2, 0x3bb, 0x3bd, 0x5, 0x44, 0x23, 0x2, 0x3bc, 0x3ba, 0x3, 0x2, 0x2, 
    0x2, 0x3bc, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3cb, 0x3, 0x2, 0x2, 
    0x2, 0x3be, 0x3c0, 0x7, 0x5a, 0x2, 0x2, 0x3bf, 0x3c1, 0x7, 0x71, 0x2, 
    0x2, 0x3c0, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3c1, 0x3, 0x2, 0x2, 
    0x2, 0x3c1, 0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c2, 0x3cb, 0x7, 0x72, 0x2, 
    0x2, 0x3c3, 0x3c5, 0x7, 0x5a, 0x2, 0x2, 0x3c4, 0x3c6, 0x7, 0x71, 0x2, 
    0x2, 0x3c5, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c5, 0x3c6, 0x3, 0x2, 0x2, 
    0x2, 0x3c6, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3c7, 0x3c8, 0x7, 0x34, 0x2, 
    0x2, 0x3c8, 0x3c9, 0x7, 0x46, 0x2, 0x2, 0x3c9, 0x3cb, 0x5, 0x44, 0x23, 
    0x2, 0x3ca, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x390, 0x3, 0x2, 0x2, 
    0x2, 0x3ca, 0x397, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x39f, 0x3, 0x2, 0x2, 
    0x2, 0x3ca, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3b6, 0x3, 0x2, 0x2, 
    0x2, 0x3ca, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3c3, 0x3, 0x2, 0x2, 
    0x2, 0x3cb, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3cc, 0x3cd, 0x8, 0x23, 0x1, 
    0x2, 0x3cd, 0x3d1, 0x5, 0x46, 0x24, 0x2, 0x3ce, 0x3cf, 0x9, 0xc, 0x2, 
    0x2, 0x3cf, 0x3d1, 0x5, 0x44, 0x23, 0x6, 0x3d0, 0x3cc, 0x3, 0x2, 0x2, 
    0x2, 0x3d0, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3e0, 0x3, 0x2, 0x2, 
    0x2, 0x3d2, 0x3d3, 0xc, 0x5, 0x2, 0x2, 0x3d3, 0x3d4, 0x9, 0xd, 0x2, 
    0x2, 0x3d4, 0x3df, 0x5, 0x44, 0x23, 0x6, 0x3d5, 0x3d6, 0xc, 0x4, 0x2, 
    0x2, 0x3d6, 0x3d7, 0x9, 0xc, 0x2, 0x2, 0x3d7, 0x3df, 0x5, 0x44, 0x23, 
    0x5, 0x3d8, 0x3d9, 0xc, 0x3, 0x2, 0x2, 0x3d9, 0x3da, 0x7, 0xcc, 0x2, 
    0x2, 0x3da, 0x3df, 0x5, 0x44, 0x23, 0x4, 0x3db, 0x3dc, 0xc, 0x7, 0x2, 
    0x2, 0x3dc, 0x3dd, 0x7, 0x15, 0x2, 0x2, 0x3dd, 0x3df, 0x5, 0x4a, 0x26, 
    0x2, 0x3de, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3d5, 0x3, 0x2, 0x2, 
    0x2, 0x3de, 0x3d8, 0x3, 0x2, 0x2, 0x2, 0x3de, 0x3db, 0x3, 0x2, 0x2, 
    0x2, 0x3df, 0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3de, 0x3, 0x2, 0x2, 
    0x2, 0x3e0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x3e2, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x3e4, 0x8, 0x24, 0x1, 0x2, 
    0x3e4, 0x4d1, 0x7, 0x72, 0x2, 0x2, 0x3e5, 0x4d1, 0x5, 0x52, 0x2a, 0x2, 
    0x3e6, 0x3e7, 0x5, 0x78, 0x3d, 0x2, 0x3e7, 0x3e8, 0x5, 0x48, 0x25, 0x2, 
    0x3e8, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 0x7, 0xd9, 0x2, 0x2, 
    0x3ea, 0x4d1, 0x5, 0x48, 0x25, 0x2, 0x3eb, 0x4d1, 0x5, 0x7a, 0x3e, 0x2, 
    0x3ec, 0x4d1, 0x5, 0x50, 0x29, 0x2, 0x3ed, 0x4d1, 0x5, 0x48, 0x25, 0x2, 
    0x3ee, 0x4d1, 0x7, 0xcf, 0x2, 0x2, 0x3ef, 0x4d1, 0x7, 0x7, 0x2, 0x2, 
    0x3f0, 0x3f1, 0x7, 0x81, 0x2, 0x2, 0x3f1, 0x3f2, 0x7, 0x4, 0x2, 0x2, 
    0x3f2, 0x3f3, 0x5, 0x44, 0x23, 0x2, 0x3f3, 0x3f4, 0x7, 0x51, 0x2, 0x2, 
    0x3f4, 0x3f5, 0x5, 0x44, 0x23, 0x2, 0x3f5, 0x3f6, 0x7, 0x5, 0x2, 0x2, 
    0x3f6, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f8, 0x7, 0x4, 0x2, 0x2, 
    0x3f8, 0x3fb, 0x5, 0x3e, 0x20, 0x2, 0x3f9, 0x3fa, 0x7, 0x6, 0x2, 0x2, 
    0x3fa, 0x3fc, 0x5, 0x3e, 0x20, 0x2, 0x3fb, 0x3f9, 0x3, 0x2, 0x2, 0x2, 
    0x3fc, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fd, 0x3fb, 0x3, 0x2, 0x2, 0x2, 
    0x3fd, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3ff, 0x3, 0x2, 0x2, 0x2, 
    0x3ff, 0x400, 0x7, 0x5, 0x2, 0x2, 0x400, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x401, 0x402, 0x7, 0x93, 0x2, 0x2, 0x402, 0x403, 0x7, 0x4, 0x2, 0x2, 
    0x403, 0x408, 0x5, 0x3e, 0x20, 0x2, 0x404, 0x405, 0x7, 0x6, 0x2, 0x2, 
    0x405, 0x407, 0x5, 0x3e, 0x20, 0x2, 0x406, 0x404, 0x3, 0x2, 0x2, 0x2, 
    0x407, 0x40a, 0x3, 0x2, 0x2, 0x2, 0x408, 0x406, 0x3, 0x2, 0x2, 0x2, 
    0x408, 0x409, 0x3, 0x2, 0x2, 0x2, 0x409, 0x40b, 0x3, 0x2, 0x2, 0x2, 
    0x40a, 0x408, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x40c, 0x7, 0x5, 0x2, 0x2, 
    0x40c, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x40d, 0x40e, 0x5, 0x76, 0x3c, 0x2, 
    0x40e, 0x40f, 0x7, 0x4, 0x2, 0x2, 0x40f, 0x410, 0x7, 0xc9, 0x2, 0x2, 
    0x410, 0x412, 0x7, 0x5, 0x2, 0x2, 0x411, 0x413, 0x5, 0x60, 0x31, 0x2, 
    0x412, 0x411, 0x3, 0x2, 0x2, 0x2, 0x412, 0x413, 0x3, 0x2, 0x2, 0x2, 
    0x413, 0x415, 0x3, 0x2, 0x2, 0x2, 0x414, 0x416, 0x5, 0x62, 0x32, 0x2, 
    0x415, 0x414, 0x3, 0x2, 0x2, 0x2, 0x415, 0x416, 0x3, 0x2, 0x2, 0x2, 
    0x416, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x417, 0x418, 0x5, 0x76, 0x3c, 0x2, 
    0x418, 0x424, 0x7, 0x4, 0x2, 0x2, 0x419, 0x41b, 0x5, 0x2a, 0x16, 0x2, 
    0x41a, 0x419, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x41b, 0x3, 0x2, 0x2, 0x2, 
    0x41b, 0x41c, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x421, 0x5, 0x3e, 0x20, 0x2, 
    0x41d, 0x41e, 0x7, 0x6, 0x2, 0x2, 0x41e, 0x420, 0x5, 0x3e, 0x20, 0x2, 
    0x41f, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x420, 0x423, 0x3, 0x2, 0x2, 0x2, 
    0x421, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x421, 0x422, 0x3, 0x2, 0x2, 0x2, 
    0x422, 0x425, 0x3, 0x2, 0x2, 0x2, 0x423, 0x421, 0x3, 0x2, 0x2, 0x2, 
    0x424, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x424, 0x425, 0x3, 0x2, 0x2, 0x2, 
    0x425, 0x430, 0x3, 0x2, 0x2, 0x2, 0x426, 0x427, 0x7, 0x79, 0x2, 0x2, 
    0x427, 0x428, 0x7, 0x18, 0x2, 0x2, 0x428, 0x42d, 0x5, 0x1e, 0x10, 0x2, 
    0x429, 0x42a, 0x7, 0x6, 0x2, 0x2, 0x42a, 0x42c, 0x5, 0x1e, 0x10, 0x2, 
    0x42b, 0x429, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x42f, 0x3, 0x2, 0x2, 0x2, 
    0x42d, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x42d, 0x42e, 0x3, 0x2, 0x2, 0x2, 
    0x42e, 0x431, 0x3, 0x2, 0x2, 0x2, 0x42f, 0x42d, 0x3, 0x2, 0x2, 0x2, 
    0x430, 0x426, 0x3, 0x2, 0x2, 0x2, 0x430, 0x431, 0x3, 0x2, 0x2, 0x2, 
    0x431, 0x432, 0x3, 0x2, 0x2, 0x2, 0x432, 0x434, 0x7, 0x5, 0x2, 0x2, 
    0x433, 0x435, 0x5, 0x60, 0x31, 0x2, 0x434, 0x433, 0x3, 0x2, 0x2, 0x2, 
    0x434, 0x435, 0x3, 0x2, 0x2, 0x2, 0x435, 0x437, 0x3, 0x2, 0x2, 0x2, 
    0x436, 0x438, 0x5, 0x62, 0x32, 0x2, 0x437, 0x436, 0x3, 0x2, 0x2, 0x2, 
    0x437, 0x438, 0x3, 0x2, 0x2, 0x2, 0x438, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x439, 0x43a, 0x5, 0x78, 0x3d, 0x2, 0x43a, 0x43b, 0x7, 0x8, 0x2, 0x2, 
    0x43b, 0x43c, 0x5, 0x3e, 0x20, 0x2, 0x43c, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x43d, 0x446, 0x7, 0x4, 0x2, 0x2, 0x43e, 0x443, 0x5, 0x78, 0x3d, 0x2, 
    0x43f, 0x440, 0x7, 0x6, 0x2, 0x2, 0x440, 0x442, 0x5, 0x78, 0x3d, 0x2, 
    0x441, 0x43f, 0x3, 0x2, 0x2, 0x2, 0x442, 0x445, 0x3, 0x2, 0x2, 0x2, 
    0x443, 0x441, 0x3, 0x2, 0x2, 0x2, 0x443, 0x444, 0x3, 0x2, 0x2, 0x2, 
    0x444, 0x447, 0x3, 0x2, 0x2, 0x2, 0x445, 0x443, 0x3, 0x2, 0x2, 0x2, 
    0x446, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x446, 0x447, 0x3, 0x2, 0x2, 0x2, 
    0x447, 0x448, 0x3, 0x2, 0x2, 0x2, 0x448, 0x449, 0x7, 0x5, 0x2, 0x2, 
    0x449, 0x44a, 0x7, 0x8, 0x2, 0x2, 0x44a, 0x4d1, 0x5, 0x3e, 0x20, 0x2, 
    0x44b, 0x44c, 0x7, 0x4, 0x2, 0x2, 0x44c, 0x44d, 0x5, 0xa, 0x6, 0x2, 
    0x44d, 0x44e, 0x7, 0x5, 0x2, 0x2, 0x44e, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x44f, 0x450, 0x7, 0x3d, 0x2, 0x2, 0x450, 0x451, 0x7, 0x4, 0x2, 0x2, 
    0x451, 0x452, 0x5, 0xa, 0x6, 0x2, 0x452, 0x453, 0x7, 0x5, 0x2, 0x2, 
    0x453, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x454, 0x455, 0x7, 0x1b, 0x2, 0x2, 
    0x455, 0x457, 0x5, 0x44, 0x23, 0x2, 0x456, 0x458, 0x5, 0x5e, 0x30, 0x2, 
    0x457, 0x456, 0x3, 0x2, 0x2, 0x2, 0x458, 0x459, 0x3, 0x2, 0x2, 0x2, 
    0x459, 0x457, 0x3, 0x2, 0x2, 0x2, 0x459, 0x45a, 0x3, 0x2, 0x2, 0x2, 
    0x45a, 0x45d, 0x3, 0x2, 0x2, 0x2, 0x45b, 0x45c, 0x7, 0x37, 0x2, 0x2, 
    0x45c, 0x45e, 0x5, 0x3e, 0x20, 0x2, 0x45d, 0x45b, 0x3, 0x2, 0x2, 0x2, 
    0x45d, 0x45e, 0x3, 0x2, 0x2, 0x2, 0x45e, 0x45f, 0x3, 0x2, 0x2, 0x2, 
    0x45f, 0x460, 0x7, 0x38, 0x2, 0x2, 0x460, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x461, 0x463, 0x7, 0x1b, 0x2, 0x2, 0x462, 0x464, 0x5, 0x5e, 0x30, 0x2, 
    0x463, 0x462, 0x3, 0x2, 0x2, 0x2, 0x464, 0x465, 0x3, 0x2, 0x2, 0x2, 
    0x465, 0x463, 0x3, 0x2, 0x2, 0x2, 0x465, 0x466, 0x3, 0x2, 0x2, 0x2, 
    0x466, 0x469, 0x3, 0x2, 0x2, 0x2, 0x467, 0x468, 0x7, 0x37, 0x2, 0x2, 
    0x468, 0x46a, 0x5, 0x3e, 0x20, 0x2, 0x469, 0x467, 0x3, 0x2, 0x2, 0x2, 
    0x469, 0x46a, 0x3, 0x2, 0x2, 0x2, 0x46a, 0x46b, 0x3, 0x2, 0x2, 0x2, 
    0x46b, 0x46c, 0x7, 0x38, 0x2, 0x2, 0x46c, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x46d, 0x46e, 0x7, 0x1c, 0x2, 0x2, 0x46e, 0x46f, 0x7, 0x4, 0x2, 0x2, 
    0x46f, 0x470, 0x5, 0x3e, 0x20, 0x2, 0x470, 0x471, 0x7, 0x13, 0x2, 0x2, 
    0x471, 0x472, 0x5, 0x58, 0x2d, 0x2, 0x472, 0x473, 0x7, 0x5, 0x2, 0x2, 
    0x473, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x474, 0x475, 0x7, 0xad, 0x2, 0x2, 
    0x475, 0x476, 0x7, 0x4, 0x2, 0x2, 0x476, 0x477, 0x5, 0x3e, 0x20, 0x2, 
    0x477, 0x478, 0x7, 0x13, 0x2, 0x2, 0x478, 0x479, 0x5, 0x58, 0x2d, 0x2, 
    0x479, 0x47a, 0x7, 0x5, 0x2, 0x2, 0x47a, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x47b, 0x47c, 0x7, 0x12, 0x2, 0x2, 0x47c, 0x485, 0x7, 0x9, 0x2, 0x2, 
    0x47d, 0x482, 0x5, 0x3e, 0x20, 0x2, 0x47e, 0x47f, 0x7, 0x6, 0x2, 0x2, 
    0x47f, 0x481, 0x5, 0x3e, 0x20, 0x2, 0x480, 0x47e, 0x3, 0x2, 0x2, 0x2, 
    0x481, 0x484, 0x3, 0x2, 0x2, 0x2, 0x482, 0x480, 0x3, 0x2, 0x2, 0x2, 
    0x482, 0x483, 0x3, 0x2, 0x2, 0x2, 0x483, 0x486, 0x3, 0x2, 0x2, 0x2, 
    0x484, 0x482, 0x3, 0x2, 0x2, 0x2, 0x485, 0x47d, 0x3, 0x2, 0x2, 0x2, 
    0x485, 0x486, 0x3, 0x2, 0x2, 0x2, 0x486, 0x487, 0x3, 0x2, 0x2, 0x2, 
    0x487, 0x4d1, 0x7, 0xa, 0x2, 0x2, 0x488, 0x4d1, 0x5, 0x78, 0x3d, 0x2, 
    0x489, 0x4d1, 0x7, 0x28, 0x2, 0x2, 0x48a, 0x48e, 0x7, 0x2a, 0x2, 0x2, 
    0x48b, 0x48c, 0x7, 0x4, 0x2, 0x2, 0x48c, 0x48d, 0x7, 0xd0, 0x2, 0x2, 
    0x48d, 0x48f, 0x7, 0x5, 0x2, 0x2, 0x48e, 0x48b, 0x3, 0x2, 0x2, 0x2, 
    0x48e, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x490, 0x494, 0x7, 0x2b, 0x2, 0x2, 0x491, 0x492, 0x7, 0x4, 0x2, 0x2, 
    0x492, 0x493, 0x7, 0xd0, 0x2, 0x2, 0x493, 0x495, 0x7, 0x5, 0x2, 0x2, 
    0x494, 0x491, 0x3, 0x2, 0x2, 0x2, 0x494, 0x495, 0x3, 0x2, 0x2, 0x2, 
    0x495, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x496, 0x49a, 0x7, 0x64, 0x2, 0x2, 
    0x497, 0x498, 0x7, 0x4, 0x2, 0x2, 0x498, 0x499, 0x7, 0xd0, 0x2, 0x2, 
    0x499, 0x49b, 0x7, 0x5, 0x2, 0x2, 0x49a, 0x497, 0x3, 0x2, 0x2, 0x2, 
    0x49a, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x49b, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x49c, 0x4a0, 0x7, 0x65, 0x2, 0x2, 0x49d, 0x49e, 0x7, 0x4, 0x2, 0x2, 
    0x49e, 0x49f, 0x7, 0xd0, 0x2, 0x2, 0x49f, 0x4a1, 0x7, 0x5, 0x2, 0x2, 
    0x4a0, 0x49d, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x4a1, 0x3, 0x2, 0x2, 0x2, 
    0x4a1, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4a2, 0x4d1, 0x7, 0x2c, 0x2, 0x2, 
    0x4a3, 0x4d1, 0x7, 0x29, 0x2, 0x2, 0x4a4, 0x4a5, 0x7, 0xa1, 0x2, 0x2, 
    0x4a5, 0x4a6, 0x7, 0x4, 0x2, 0x2, 0x4a6, 0x4a7, 0x5, 0x44, 0x23, 0x2, 
    0x4a7, 0x4a8, 0x7, 0x46, 0x2, 0x2, 0x4a8, 0x4ab, 0x5, 0x44, 0x23, 0x2, 
    0x4a9, 0x4aa, 0x7, 0x44, 0x2, 0x2, 0x4aa, 0x4ac, 0x5, 0x44, 0x23, 0x2, 
    0x4ab, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4ab, 0x4ac, 0x3, 0x2, 0x2, 0x2, 
    0x4ac, 0x4ad, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 0x7, 0x5, 0x2, 0x2, 
    0x4ae, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4af, 0x4b0, 0x7, 0x70, 0x2, 0x2, 
    0x4b0, 0x4b1, 0x7, 0x4, 0x2, 0x2, 0x4b1, 0x4b4, 0x5, 0x44, 0x23, 0x2, 
    0x4b2, 0x4b3, 0x7, 0x6, 0x2, 0x2, 0x4b3, 0x4b5, 0x5, 0x56, 0x2c, 0x2, 
    0x4b4, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b4, 0x4b5, 0x3, 0x2, 0x2, 0x2, 
    0x4b5, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b7, 0x7, 0x5, 0x2, 0x2, 
    0x4b7, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4b8, 0x4b9, 0x7, 0x3f, 0x2, 0x2, 
    0x4b9, 0x4ba, 0x7, 0x4, 0x2, 0x2, 0x4ba, 0x4bb, 0x5, 0x78, 0x3d, 0x2, 
    0x4bb, 0x4bc, 0x7, 0x46, 0x2, 0x2, 0x4bc, 0x4bd, 0x5, 0x44, 0x23, 0x2, 
    0x4bd, 0x4be, 0x7, 0x5, 0x2, 0x2, 0x4be, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x4bf, 0x4c0, 0x7, 0x4, 0x2, 0x2, 0x4c0, 0x4c1, 0x5, 0x3e, 0x20, 0x2, 
    0x4c1, 0x4c2, 0x7, 0x5, 0x2, 0x2, 0x4c2, 0x4d1, 0x3, 0x2, 0x2, 0x2, 
    0x4c3, 0x4c4, 0x7, 0x4d, 0x2, 0x2, 0x4c4, 0x4cd, 0x7, 0x4, 0x2, 0x2, 
    0x4c5, 0x4ca, 0x5, 0x76, 0x3c, 0x2, 0x4c6, 0x4c7, 0x7, 0x6, 0x2, 0x2, 
    0x4c7, 0x4c9, 0x5, 0x76, 0x3c, 0x2, 0x4c8, 0x4c6, 0x3, 0x2, 0x2, 0x2, 
    0x4c9, 0x4cc, 0x3, 0x2, 0x2, 0x2, 0x4ca, 0x4c8, 0x3, 0x2, 0x2, 0x2, 
    0x4ca, 0x4cb, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4ce, 0x3, 0x2, 0x2, 0x2, 
    0x4cc, 0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4cd, 0x4c5, 0x3, 0x2, 0x2, 0x2, 
    0x4cd, 0x4ce, 0x3, 0x2, 0x2, 0x2, 0x4ce, 0x4cf, 0x3, 0x2, 0x2, 0x2, 
    0x4cf, 0x4d1, 0x7, 0x5, 0x2, 0x2, 0x4d0, 0x3e3, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x3e5, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x3e6, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x3eb, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x3ed, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x3ee, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x3ef, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x3f7, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x401, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x40d, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x417, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x439, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x44b, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x454, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x461, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x46d, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x474, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x47b, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x488, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x489, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x48a, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x490, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x496, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x49c, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x4a2, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4a3, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4af, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4bf, 0x3, 0x2, 0x2, 0x2, 
    0x4d0, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4d1, 0x4dc, 0x3, 0x2, 0x2, 0x2, 
    0x4d2, 0x4d3, 0xc, 0x11, 0x2, 0x2, 0x4d3, 0x4d4, 0x7, 0x9, 0x2, 0x2, 
    0x4d4, 0x4d5, 0x5, 0x44, 0x23, 0x2, 0x4d5, 0x4d6, 0x7, 0xa, 0x2, 0x2, 
    0x4d6, 0x4db, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d8, 0xc, 0xf, 0x2, 0x2, 
    0x4d8, 0x4d9, 0x7, 0x3, 0x2, 0x2, 0x4d9, 0x4db, 0x5, 0x78, 0x3d, 0x2, 
    0x4da, 0x4d2, 0x3, 0x2, 0x2, 0x2, 0x4da, 0x4d7, 0x3, 0x2, 0x2, 0x2, 
    0x4db, 0x4de, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4da, 0x3, 0x2, 0x2, 0x2, 
    0x4dc, 0x4dd, 0x3, 0x2, 0x2, 0x2, 0x4dd, 0x47, 0x3, 0x2, 0x2, 0x2, 0x4de, 
    0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4e6, 0x7, 0xcd, 0x2, 0x2, 0x4e0, 
    0x4e3, 0x7, 0xce, 0x2, 0x2, 0x4e1, 0x4e2, 0x7, 0xaf, 0x2, 0x2, 0x4e2, 
    0x4e4, 0x7, 0xcd, 0x2, 0x2, 0x4e3, 0x4e1, 0x3, 0x2, 0x2, 0x2, 0x4e3, 
    0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e5, 
    0x4df, 0x3, 0x2, 0x2, 0x2, 0x4e5, 0x4e0, 0x3, 0x2, 0x2, 0x2, 0x4e6, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x4e7, 0x4e8, 0x7, 0xa8, 0x2, 0x2, 0x4e8, 
    0x4e9, 0x7, 0xc0, 0x2, 0x2, 0x4e9, 0x4ee, 0x5, 0x52, 0x2a, 0x2, 0x4ea, 
    0x4eb, 0x7, 0xa8, 0x2, 0x2, 0x4eb, 0x4ec, 0x7, 0xc0, 0x2, 0x2, 0x4ec, 
    0x4ee, 0x5, 0x48, 0x25, 0x2, 0x4ed, 0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4ed, 
    0x4ea, 0x3, 0x2, 0x2, 0x2, 0x4ee, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 
    0x9, 0xe, 0x2, 0x2, 0x4f0, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f1, 0x4f2, 0x9, 
    0xf, 0x2, 0x2, 0x4f2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f3, 0x4f4, 0x9, 0x10, 
    0x2, 0x2, 0x4f4, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f5, 0x4f7, 0x7, 0x57, 
    0x2, 0x2, 0x4f6, 0x4f8, 0x9, 0xc, 0x2, 0x2, 0x4f7, 0x4f6, 0x3, 0x2, 
    0x2, 0x2, 0x4f7, 0x4f8, 0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4f9, 0x3, 0x2, 
    0x2, 0x2, 0x4f9, 0x4fa, 0x5, 0x48, 0x25, 0x2, 0x4fa, 0x4fd, 0x5, 0x54, 
    0x2b, 0x2, 0x4fb, 0x4fc, 0x7, 0xaa, 0x2, 0x2, 0x4fc, 0x4fe, 0x5, 0x54, 
    0x2b, 0x2, 0x4fd, 0x4fb, 0x3, 0x2, 0x2, 0x2, 0x4fd, 0x4fe, 0x3, 0x2, 
    0x2, 0x2, 0x4fe, 0x53, 0x3, 0x2, 0x2, 0x2, 0x4ff, 0x500, 0x9, 0x11, 
    0x2, 0x2, 0x500, 0x55, 0x3, 0x2, 0x2, 0x2, 0x501, 0x502, 0x9, 0x12, 
    0x2, 0x2, 0x502, 0x57, 0x3, 0x2, 0x2, 0x2, 0x503, 0x504, 0x8, 0x2d, 
    0x1, 0x2, 0x504, 0x505, 0x7, 0x12, 0x2, 0x2, 0x505, 0x506, 0x7, 0xc3, 
    0x2, 0x2, 0x506, 0x507, 0x5, 0x58, 0x2d, 0x2, 0x507, 0x508, 0x7, 0xc5, 
    0x2, 0x2, 0x508, 0x533, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50a, 0x7, 0x67, 
    0x2, 0x2, 0x50a, 0x50b, 0x7, 0xc3, 0x2, 0x2, 0x50b, 0x50c, 0x5, 0x58, 
    0x2d, 0x2, 0x50c, 0x50d, 0x7, 0x6, 0x2, 0x2, 0x50d, 0x50e, 0x5, 0x58, 
    0x2d, 0x2, 0x50e, 0x50f, 0x7, 0xc5, 0x2, 0x2, 0x50f, 0x533, 0x3, 0x2, 
    0x2, 0x2, 0x510, 0x511, 0x7, 0x93, 0x2, 0x2, 0x511, 0x512, 0x7, 0x4, 
    0x2, 0x2, 0x512, 0x513, 0x5, 0x78, 0x3d, 0x2, 0x513, 0x51a, 0x5, 0x58, 
    0x2d, 0x2, 0x514, 0x515, 0x7, 0x6, 0x2, 0x2, 0x515, 0x516, 0x5, 0x78, 
    0x3d, 0x2, 0x516, 0x517, 0x5, 0x58, 0x2d, 0x2, 0x517, 0x519, 0x3, 0x2, 
    0x2, 0x2, 0x518, 0x514, 0x3, 0x2, 0x2, 0x2, 0x519, 0x51c, 0x3, 0x2, 
    0x2, 0x2, 0x51a, 0x518, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x51b, 0x3, 0x2, 
    0x2, 0x2, 0x51b, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x51c, 0x51a, 0x3, 0x2, 
    0x2, 0x2, 0x51d, 0x51e, 0x7, 0x5, 0x2, 0x2, 0x51e, 0x533, 0x3, 0x2, 
    0x2, 0x2, 0x51f, 0x52b, 0x5, 0x5c, 0x2f, 0x2, 0x520, 0x521, 0x7, 0x4, 
    0x2, 0x2, 0x521, 0x526, 0x5, 0x5a, 0x2e, 0x2, 0x522, 0x523, 0x7, 0x6, 
    0x2, 0x2, 0x523, 0x525, 0x5, 0x5a, 0x2e, 0x2, 0x524, 0x522, 0x3, 0x2, 
    0x2, 0x2, 0x525, 0x528, 0x3, 0x2, 0x2, 0x2, 0x526, 0x524, 0x3, 0x2, 
    0x2, 0x2, 0x526, 0x527, 0x3, 0x2, 0x2, 0x2, 0x527, 0x529, 0x3, 0x2, 
    0x2, 0x2, 0x528, 0x526, 0x3, 0x2, 0x2, 0x2, 0x529, 0x52a, 0x7, 0x5, 
    0x2, 0x2, 0x52a, 0x52c, 0x3, 0x2, 0x2, 0x2, 0x52b, 0x520, 0x3, 0x2, 
    0x2, 0x2, 0x52b, 0x52c, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x533, 0x3, 0x2, 
    0x2, 0x2, 0x52d, 0x52e, 0x7, 0x57, 0x2, 0x2, 0x52e, 0x52f, 0x5, 0x54, 
    0x2b, 0x2, 0x52f, 0x530, 0x7, 0xaa, 0x2, 0x2, 0x530, 0x531, 0x5, 0x54, 
    0x2b, 0x2, 0x531, 0x533, 0x3, 0x2, 0x2, 0x2, 0x532, 0x503, 0x3, 0x2, 
    0x2, 0x2, 0x532, 0x509, 0x3, 0x2, 0x2, 0x2, 0x532, 0x510, 0x3, 0x2, 
    0x2, 0x2, 0x532, 0x51f, 0x3, 0x2, 0x2, 0x2, 0x532, 0x52d, 0x3, 0x2, 
    0x2, 0x2, 0x533, 0x538, 0x3, 0x2, 0x2, 0x2, 0x534, 0x535, 0xc, 0x8, 
    0x2, 0x2, 0x535, 0x537, 0x7, 0x12, 0x2, 0x2, 0x536, 0x534, 0x3, 0x2, 
    0x2, 0x2, 0x537, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x538, 0x536, 0x3, 0x2, 
    0x2, 0x2, 0x538, 0x539, 0x3, 0x2, 0x2, 0x2, 0x539, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x53a, 0x538, 0x3, 0x2, 0x2, 0x2, 0x53b, 0x53e, 0x7, 0xd0, 0x2, 
    0x2, 0x53c, 0x53e, 0x5, 0x58, 0x2d, 0x2, 0x53d, 0x53b, 0x3, 0x2, 0x2, 
    0x2, 0x53d, 0x53c, 0x3, 0x2, 0x2, 0x2, 0x53e, 0x5b, 0x3, 0x2, 0x2, 0x2, 
    0x53f, 0x544, 0x7, 0xd7, 0x2, 0x2, 0x540, 0x544, 0x7, 0xd8, 0x2, 0x2, 
    0x541, 0x544, 0x7, 0xd9, 0x2, 0x2, 0x542, 0x544, 0x5, 0x78, 0x3d, 0x2, 
    0x543, 0x53f, 0x3, 0x2, 0x2, 0x2, 0x543, 0x540, 0x3, 0x2, 0x2, 0x2, 
    0x543, 0x541, 0x3, 0x2, 0x2, 0x2, 0x543, 0x542, 0x3, 0x2, 0x2, 0x2, 
    0x544, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x545, 0x546, 0x7, 0xba, 0x2, 0x2, 
    0x546, 0x547, 0x5, 0x3e, 0x20, 0x2, 0x547, 0x548, 0x7, 0xa7, 0x2, 0x2, 
    0x548, 0x549, 0x5, 0x3e, 0x20, 0x2, 0x549, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x54a, 0x54b, 0x7, 0x41, 0x2, 0x2, 0x54b, 0x54c, 0x7, 0x4, 0x2, 0x2, 
    0x54c, 0x54d, 0x7, 0xbb, 0x2, 0x2, 0x54d, 0x54e, 0x5, 0x40, 0x21, 0x2, 
    0x54e, 0x54f, 0x7, 0x5, 0x2, 0x2, 0x54f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x550, 
    0x551, 0x7, 0x7d, 0x2, 0x2, 0x551, 0x55c, 0x7, 0x4, 0x2, 0x2, 0x552, 
    0x553, 0x7, 0x7e, 0x2, 0x2, 0x553, 0x554, 0x7, 0x18, 0x2, 0x2, 0x554, 
    0x559, 0x5, 0x3e, 0x20, 0x2, 0x555, 0x556, 0x7, 0x6, 0x2, 0x2, 0x556, 
    0x558, 0x5, 0x3e, 0x20, 0x2, 0x557, 0x555, 0x3, 0x2, 0x2, 0x2, 0x558, 
    0x55b, 0x3, 0x2, 0x2, 0x2, 0x559, 0x557, 0x3, 0x2, 0x2, 0x2, 0x559, 
    0x55a, 0x3, 0x2, 0x2, 0x2, 0x55a, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55b, 
    0x559, 0x3, 0x2, 0x2, 0x2, 0x55c, 0x552, 0x3, 0x2, 0x2, 0x2, 0x55c, 
    0x55d, 0x3, 0x2, 0x2, 0x2, 0x55d, 0x568, 0x3, 0x2, 0x2, 0x2, 0x55e, 
    0x55f, 0x7, 0x79, 0x2, 0x2, 0x55f, 0x560, 0x7, 0x18, 0x2, 0x2, 0x560, 
    0x565, 0x5, 0x1e, 0x10, 0x2, 0x561, 0x562, 0x7, 0x6, 0x2, 0x2, 0x562, 
    0x564, 0x5, 0x1e, 0x10, 0x2, 0x563, 0x561, 0x3, 0x2, 0x2, 0x2, 0x564, 
    0x567, 0x3, 0x2, 0x2, 0x2, 0x565, 0x563, 0x3, 0x2, 0x2, 0x2, 0x565, 
    0x566, 0x3, 0x2, 0x2, 0x2, 0x566, 0x569, 0x3, 0x2, 0x2, 0x2, 0x567, 
    0x565, 0x3, 0x2, 0x2, 0x2, 0x568, 0x55e, 0x3, 0x2, 0x2, 0x2, 0x568, 
    0x569, 0x3, 0x2, 0x2, 0x2, 0x569, 0x56b, 0x3, 0x2, 0x2, 0x2, 0x56a, 
    0x56c, 0x5, 0x64, 0x33, 0x2, 0x56b, 0x56a, 0x3, 0x2, 0x2, 0x2, 0x56b, 
    0x56c, 0x3, 0x2, 0x2, 0x2, 0x56c, 0x56d, 0x3, 0x2, 0x2, 0x2, 0x56d, 
    0x56e, 0x7, 0x5, 0x2, 0x2, 0x56e, 0x63, 0x3, 0x2, 0x2, 0x2, 0x56f, 0x570, 
    0x7, 0x87, 0x2, 0x2, 0x570, 0x580, 0x5, 0x66, 0x34, 0x2, 0x571, 0x572, 
    0x7, 0x94, 0x2, 0x2, 0x572, 0x580, 0x5, 0x66, 0x34, 0x2, 0x573, 0x574, 
    0x7, 0x87, 0x2, 0x2, 0x574, 0x575, 0x7, 0x17, 0x2, 0x2, 0x575, 0x576, 
    0x5, 0x66, 0x34, 0x2, 0x576, 0x577, 0x7, 0x10, 0x2, 0x2, 0x577, 0x578, 
    0x5, 0x66, 0x34, 0x2, 0x578, 0x580, 0x3, 0x2, 0x2, 0x2, 0x579, 0x57a, 
    0x7, 0x94, 0x2, 0x2, 0x57a, 0x57b, 0x7, 0x17, 0x2, 0x2, 0x57b, 0x57c, 
    0x5, 0x66, 0x34, 0x2, 0x57c, 0x57d, 0x7, 0x10, 0x2, 0x2, 0x57d, 0x57e, 
    0x5, 0x66, 0x34, 0x2, 0x57e, 0x580, 0x3, 0x2, 0x2, 0x2, 0x57f, 0x56f, 
    0x3, 0x2, 0x2, 0x2, 0x57f, 0x571, 0x3, 0x2, 0x2, 0x2, 0x57f, 0x573, 
    0x3, 0x2, 0x2, 0x2, 0x57f, 0x579, 0x3, 0x2, 0x2, 0x2, 0x580, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x581, 0x582, 0x7, 0xb0, 0x2, 0x2, 0x582, 0x58b, 0x7, 
    0x82, 0x2, 0x2, 0x583, 0x584, 0x7, 0xb0, 0x2, 0x2, 0x584, 0x58b, 0x7, 
    0x43, 0x2, 0x2, 0x585, 0x586, 0x7, 0x27, 0x2, 0x2, 0x586, 0x58b, 0x7, 
    0x93, 0x2, 0x2, 0x587, 0x588, 0x5, 0x3e, 0x20, 0x2, 0x588, 0x589, 0x9, 
    0x13, 0x2, 0x2, 0x589, 0x58b, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x581, 0x3, 
    0x2, 0x2, 0x2, 0x58a, 0x583, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x585, 0x3, 
    0x2, 0x2, 0x2, 0x58a, 0x587, 0x3, 0x2, 0x2, 0x2, 0x58b, 0x67, 0x3, 0x2, 
    0x2, 0x2, 0x58c, 0x58d, 0x7, 0x45, 0x2, 0x2, 0x58d, 0x591, 0x9, 0x14, 
    0x2, 0x2, 0x58e, 0x58f, 0x7, 0xae, 0x2, 0x2, 0x58f, 0x591, 0x9, 0x15, 
    0x2, 0x2, 0x590, 0x58c, 0x3, 0x2, 0x2, 0x2, 0x590, 0x58e, 0x3, 0x2, 
    0x2, 0x2, 0x591, 0x69, 0x3, 0x2, 0x2, 0x2, 0x592, 0x593, 0x7, 0x5b, 
    0x2, 0x2, 0x593, 0x594, 0x7, 0x61, 0x2, 0x2, 0x594, 0x598, 0x5, 0x6c, 
    0x37, 0x2, 0x595, 0x596, 0x7, 0x88, 0x2, 0x2, 0x596, 0x598, 0x9, 0x16, 
    0x2, 0x2, 0x597, 0x592, 0x3, 0x2, 0x2, 0x2, 0x597, 0x595, 0x3, 0x2, 
    0x2, 0x2, 0x598, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x599, 0x59a, 0x7, 0x88, 
    0x2, 0x2, 0x59a, 0x5a1, 0x7, 0xb1, 0x2, 0x2, 0x59b, 0x59c, 0x7, 0x88, 
    0x2, 0x2, 0x59c, 0x5a1, 0x7, 0x22, 0x2, 0x2, 0x59d, 0x59e, 0x7, 0x8b, 
    0x2, 0x2, 0x59e, 0x5a1, 0x7, 0x88, 0x2, 0x2, 0x59f, 0x5a1, 0x7, 0x99, 
    0x2, 0x2, 0x5a0, 0x599, 0x3, 0x2, 0x2, 0x2, 0x5a0, 0x59b, 0x3, 0x2, 
    0x2, 0x2, 0x5a0, 0x59d, 0x3, 0x2, 0x2, 0x2, 0x5a0, 0x59f, 0x3, 0x2, 
    0x2, 0x2, 0x5a1, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x5a2, 0x5a8, 0x5, 0x3e, 
    0x20, 0x2, 0x5a3, 0x5a4, 0x5, 0x78, 0x3d, 0x2, 0x5a4, 0x5a5, 0x7, 0xb, 
    0x2, 0x2, 0x5a5, 0x5a6, 0x5, 0x3e, 0x20, 0x2, 0x5a6, 0x5a8, 0x3, 0x2, 
    0x2, 0x2, 0x5a7, 0x5a2, 0x3, 0x2, 0x2, 0x2, 0x5a7, 0x5a3, 0x3, 0x2, 
    0x2, 0x2, 0x5a8, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x5a9, 0x5aa, 0x5, 0x78, 
    0x3d, 0x2, 0x5aa, 0x5ab, 0x7, 0x3, 0x2, 0x2, 0x5ab, 0x5ac, 0x5, 0x78, 
    0x3d, 0x2, 0x5ac, 0x5af, 0x3, 0x2, 0x2, 0x2, 0x5ad, 0x5af, 0x5, 0x78, 
    0x3d, 0x2, 0x5ae, 0x5a9, 0x3, 0x2, 0x2, 0x2, 0x5ae, 0x5ad, 0x3, 0x2, 
    0x2, 0x2, 0x5af, 0x71, 0x3, 0x2, 0x2, 0x2, 0x5b0, 0x5b5, 0x5, 0x70, 
    0x39, 0x2, 0x5b1, 0x5b2, 0x7, 0x6, 0x2, 0x2, 0x5b2, 0x5b4, 0x5, 0x70, 
    0x39, 0x2, 0x5b3, 0x5b1, 0x3, 0x2, 0x2, 0x2, 0x5b4, 0x5b7, 0x3, 0x2, 
    0x2, 0x2, 0x5b5, 0x5b3, 0x3, 0x2, 0x2, 0x2, 0x5b5, 0x5b6, 0x3, 0x2, 
    0x2, 0x2, 0x5b6, 0x73, 0x3, 0x2, 0x2, 0x2, 0x5b7, 0x5b5, 0x3, 0x2, 0x2, 
    0x2, 0x5b8, 0x5bd, 0x7, 0x98, 0x2, 0x2, 0x5b9, 0x5bd, 0x7, 0x31, 0x2, 
    0x2, 0x5ba, 0x5bd, 0x7, 0x55, 0x2, 0x2, 0x5bb, 0x5bd, 0x5, 0x78, 0x3d, 
    0x2, 0x5bc, 0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x5b9, 0x3, 0x2, 0x2, 
    0x2, 0x5bc, 0x5ba, 0x3, 0x2, 0x2, 0x2, 0x5bc, 0x5bb, 0x3, 0x2, 0x2, 
    0x2, 0x5bd, 0x75, 0x3, 0x2, 0x2, 0x2, 0x5be, 0x5c3, 0x5, 0x78, 0x3d, 
    0x2, 0x5bf, 0x5c0, 0x7, 0x3, 0x2, 0x2, 0x5c0, 0x5c2, 0x5, 0x78, 0x3d, 
    0x2, 0x5c1, 0x5bf, 0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c5, 0x3, 0x2, 0x2, 
    0x2, 0x5c3, 0x5c1, 0x3, 0x2, 0x2, 0x2, 0x5c3, 0x5c4, 0x3, 0x2, 0x2, 
    0x2, 0x5c4, 0x77, 0x3, 0x2, 0x2, 0x2, 0x5c5, 0x5c3, 0x3, 0x2, 0x2, 0x2, 
    0x5c6, 0x5cc, 0x7, 0xd3, 0x2, 0x2, 0x5c7, 0x5cc, 0x7, 0xd5, 0x2, 0x2, 
    0x5c8, 0x5cc, 0x5, 0x7c, 0x3f, 0x2, 0x5c9, 0x5cc, 0x7, 0xd6, 0x2, 0x2, 
    0x5ca, 0x5cc, 0x7, 0xd4, 0x2, 0x2, 0x5cb, 0x5c6, 0x3, 0x2, 0x2, 0x2, 
    0x5cb, 0x5c7, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5c8, 0x3, 0x2, 0x2, 0x2, 
    0x5cb, 0x5c9, 0x3, 0x2, 0x2, 0x2, 0x5cb, 0x5ca, 0x3, 0x2, 0x2, 0x2, 
    0x5cc, 0x79, 0x3, 0x2, 0x2, 0x2, 0x5cd, 0x5d1, 0x7, 0xd1, 0x2, 0x2, 
    0x5ce, 0x5d1, 0x7, 0xd2, 0x2, 0x2, 0x5cf, 0x5d1, 0x7, 0xd0, 0x2, 0x2, 
    0x5d0, 0x5cd, 0x3, 0x2, 0x2, 0x2, 0x5d0, 0x5ce, 0x3, 0x2, 0x2, 0x2, 
    0x5d0, 0x5cf, 0x3, 0x2, 0x2, 0x2, 0x5d1, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x5d2, 
    0x5d3, 0x9, 0x17, 0x2, 0x2, 0x5d3, 0x7d, 0x3, 0x2, 0x2, 0x2, 0xb9, 0x94, 
    0x99, 0x9f, 0xa3, 0xb1, 0xb5, 0xb9, 0xbd, 0xc5, 0xc9, 0xcc, 0xd3, 0xdc, 
    0xe2, 0xe6, 0xec, 0xf3, 0xfc, 0x11f, 0x12a, 0x135, 0x138, 0x142, 0x147, 
    0x14b, 0x153, 0x159, 0x160, 0x165, 0x169, 0x173, 0x176, 0x17a, 0x17d, 
    0x185, 0x18a, 0x199, 0x19f, 0x1a1, 0x1a7, 0x1ad, 0x1af, 0x1b5, 0x1de, 
    0x1e1, 0x1e5, 0x1e9, 0x1fb, 0x1fe, 0x209, 0x20c, 0x212, 0x219, 0x21e, 
    0x224, 0x228, 0x22e, 0x236, 0x247, 0x24a, 0x24e, 0x256, 0x25c, 0x25f, 
    0x261, 0x26d, 0x274, 0x278, 0x27c, 0x280, 0x287, 0x290, 0x293, 0x297, 
    0x29c, 0x2a0, 0x2a3, 0x2aa, 0x2b5, 0x2b8, 0x2c2, 0x2c5, 0x2d0, 0x2d5, 
    0x2dd, 0x2e0, 0x2e4, 0x2e8, 0x2f3, 0x2f6, 0x2fd, 0x310, 0x314, 0x318, 
    0x31c, 0x320, 0x324, 0x326, 0x331, 0x336, 0x33f, 0x345, 0x349, 0x34b, 
    0x353, 0x364, 0x36a, 0x375, 0x37c, 0x380, 0x388, 0x38a, 0x397, 0x39f, 
    0x3a8, 0x3ae, 0x3b6, 0x3bc, 0x3c0, 0x3c5, 0x3ca, 0x3d0, 0x3de, 0x3e0, 
    0x3fd, 0x408, 0x412, 0x415, 0x41a, 0x421, 0x424, 0x42d, 0x430, 0x434, 
    0x437, 0x443, 0x446, 0x459, 0x45d, 0x465, 0x469, 0x482, 0x485, 0x48e, 
    0x494, 0x49a, 0x4a0, 0x4ab, 0x4b4, 0x4ca, 0x4cd, 0x4d0, 0x4da, 0x4dc, 
    0x4e3, 0x4e5, 0x4ed, 0x4f7, 0x4fd, 0x51a, 0x526, 0x52b, 0x532, 0x538, 
    0x53d, 0x543, 0x559, 0x55c, 0x565, 0x568, 0x56b, 0x57f, 0x58a, 0x590, 
    0x597, 0x5a0, 0x5a7, 0x5ae, 0x5b5, 0x5bc, 0x5c3, 0x5cb, 0x5d0, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CentSqlParser::Initializer CentSqlParser::_init;
