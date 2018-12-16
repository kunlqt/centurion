
// Generated from C:/Users/vasko/source/repos/presto/presto-parser/src/main/antlr4/com/facebook/presto/sql/parser\CentSql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace centurion {


class  CentSqlParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, ADD = 10, ALL = 11, ALTER = 12, ANALYZE = 13, AND = 14, 
    ANY = 15, ARRAY = 16, AS = 17, ASC = 18, AT = 19, BERNOULLI = 20, BETWEEN = 21, 
    BY = 22, CALL = 23, CASCADE = 24, CASE = 25, CAST = 26, CATALOGS = 27, 
    COLUMN = 28, COLUMNS = 29, COMMENT = 30, COMMIT = 31, COMMITTED = 32, 
    CONSTRAINT = 33, CREATE = 34, CROSS = 35, CUBE = 36, CURRENT = 37, CURRENT_DATE = 38, 
    CURRENT_PATH = 39, CURRENT_TIME = 40, CURRENT_TIMESTAMP = 41, CURRENT_USER = 42, 
    DATA = 43, DATE = 44, DAY = 45, DEALLOCATE = 46, DELETE = 47, DESC = 48, 
    DESCRIBE = 49, DISTINCT = 50, DISTRIBUTED = 51, DROP = 52, ELSE = 53, 
    END = 54, ESCAPE = 55, EXCEPT = 56, EXCLUDING = 57, EXECUTE = 58, EXISTS = 59, 
    EXPLAIN = 60, EXTRACT = 61, FALSE_VALUE = 62, FILTER = 63, FIRST = 64, 
    FOLLOWING = 65, FOR = 66, FORMAT = 67, FROM = 68, FULL = 69, FUNCTIONS = 70, 
    GRANT = 71, GRANTS = 72, GRAPHVIZ = 73, GROUP = 74, GROUPING = 75, HAVING = 76, 
    HOUR = 77, IF = 78, IN = 79, INCLUDING = 80, INNER = 81, INPUT = 82, 
    INSERT = 83, INTERSECT = 84, INTERVAL = 85, INTO = 86, IO = 87, IS = 88, 
    ISOLATION = 89, JSON = 90, JOIN = 91, LAST = 92, LATERAL = 93, LEFT = 94, 
    LEVEL = 95, LIKE = 96, LIMIT = 97, LOCALTIME = 98, LOCALTIMESTAMP = 99, 
    LOGICAL = 100, MAP = 101, MINUTE = 102, MONTH = 103, NATURAL = 104, 
    NFC = 105, NFD = 106, NFKC = 107, NFKD = 108, NO = 109, NORMALIZE = 110, 
    NOT = 111, NULL_VALUE = 112, NULLIF = 113, NULLS = 114, ON = 115, ONLY = 116, 
    OPTION = 117, OR = 118, ORDER = 119, ORDINALITY = 120, OUTER = 121, 
    OUTPUT = 122, OVER = 123, PARTITION = 124, PARTITIONS = 125, PATH = 126, 
    POSITION = 127, PRECEDING = 128, PREPARE = 129, PRIVILEGES = 130, PROPERTIES = 131, 
    PUBLIC = 132, RANGE = 133, READ = 134, RECURSIVE = 135, RENAME = 136, 
    REPEATABLE = 137, REPLACE = 138, RESET = 139, RESTRICT = 140, REVOKE = 141, 
    RIGHT = 142, ROLLBACK = 143, ROLLUP = 144, ROW = 145, ROWS = 146, SCHEMA = 147, 
    SCHEMAS = 148, SECOND = 149, SELECT = 150, SERIALIZABLE = 151, SESSION = 152, 
    SET = 153, SETS = 154, SHOW = 155, SOME = 156, START = 157, STATS = 158, 
    SUBSTRING = 159, SYSTEM = 160, TABLE = 161, TABLES = 162, TABLESAMPLE = 163, 
    TEXT = 164, THEN = 165, TIME = 166, TIMESTAMP = 167, TO = 168, TRANSACTION = 169, 
    TRUE_VALUE = 170, TRY_CAST = 171, TYPE = 172, UESCAPE = 173, UNBOUNDED = 174, 
    UNCOMMITTED = 175, UNION = 176, UNNEST = 177, USE = 178, USING = 179, 
    VALIDATE = 180, VALUES = 181, VERBOSE = 182, VIEW = 183, WHEN = 184, 
    WHERE = 185, WITH = 186, WORK = 187, WRITE = 188, YEAR = 189, ZONE = 190, 
    EQ = 191, NEQ = 192, LT = 193, LTE = 194, GT = 195, GTE = 196, PLUS = 197, 
    MINUS = 198, ASTERISK = 199, SLASH = 200, PERCENT = 201, CONCAT = 202, 
    STRING = 203, UNICODE_STRING = 204, BINARY_LITERAL = 205, INTEGER_VALUE = 206, 
    DECIMAL_VALUE = 207, DOUBLE_VALUE = 208, IDENTIFIER = 209, DIGIT_IDENTIFIER = 210, 
    QUOTED_IDENTIFIER = 211, BACKQUOTED_IDENTIFIER = 212, TIME_WITH_TIME_ZONE = 213, 
    TIMESTAMP_WITH_TIME_ZONE = 214, DOUBLE_PRECISION = 215, SIMPLE_COMMENT = 216, 
    BRACKETED_COMMENT = 217, WS = 218, UNRECOGNIZED = 219, DELIMITER = 220
  };

  enum {
    RuleSingleStatement = 0, RuleStandaloneExpression = 1, RuleStandalonePathSpecification = 2, 
    RuleStatement = 3, RuleQuery = 4, RuleWith = 5, RuleTableElement = 6, 
    RuleColumnDefinition = 7, RuleLikeClause = 8, RuleProperties = 9, RuleProperty = 10, 
    RuleQueryNoWith = 11, RuleQueryTerm = 12, RuleQueryPrimary = 13, RuleSortItem = 14, 
    RuleQuerySpecification = 15, RuleGroupBy = 16, RuleGroupingElement = 17, 
    RuleGroupingSet = 18, RuleNamedQuery = 19, RuleSetQuantifier = 20, RuleSelectItem = 21, 
    RuleRelation = 22, RuleJoinType = 23, RuleJoinCriteria = 24, RuleSampledRelation = 25, 
    RuleSampleType = 26, RuleAliasedRelation = 27, RuleColumnAliases = 28, 
    RuleRelationPrimary = 29, RuleExpression = 30, RuleBooleanExpression = 31, 
    RulePredicate = 32, RuleValueExpression = 33, RulePrimaryExpression = 34, 
    RuleString = 35, RuleTimeZoneSpecifier = 36, RuleComparisonOperator = 37, 
    RuleComparisonQuantifier = 38, RuleBooleanValue = 39, RuleInterval = 40, 
    RuleIntervalField = 41, RuleNormalForm = 42, RuleType = 43, RuleTypeParameter = 44, 
    RuleBaseType = 45, RuleWhenClause = 46, RuleFilter = 47, RuleOver = 48, 
    RuleWindowFrame = 49, RuleFrameBound = 50, RuleExplainOption = 51, RuleTransactionMode = 52, 
    RuleLevelOfIsolation = 53, RuleCallArgument = 54, RulePathElement = 55, 
    RulePathSpecification = 56, RulePrivilege = 57, RuleQualifiedName = 58, 
    RuleIdentifier = 59, RuleNumber = 60, RuleNonReserved = 61
  };

  CentSqlParser(antlr4::TokenStream *input);
  ~CentSqlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class SingleStatementContext;
  class StandaloneExpressionContext;
  class StandalonePathSpecificationContext;
  class StatementContext;
  class QueryContext;
  class WithContext;
  class TableElementContext;
  class ColumnDefinitionContext;
  class LikeClauseContext;
  class PropertiesContext;
  class PropertyContext;
  class QueryNoWithContext;
  class QueryTermContext;
  class QueryPrimaryContext;
  class SortItemContext;
  class QuerySpecificationContext;
  class GroupByContext;
  class GroupingElementContext;
  class GroupingSetContext;
  class NamedQueryContext;
  class SetQuantifierContext;
  class SelectItemContext;
  class RelationContext;
  class JoinTypeContext;
  class JoinCriteriaContext;
  class SampledRelationContext;
  class SampleTypeContext;
  class AliasedRelationContext;
  class ColumnAliasesContext;
  class RelationPrimaryContext;
  class ExpressionContext;
  class BooleanExpressionContext;
  class PredicateContext;
  class ValueExpressionContext;
  class PrimaryExpressionContext;
  class StringContext;
  class TimeZoneSpecifierContext;
  class ComparisonOperatorContext;
  class ComparisonQuantifierContext;
  class BooleanValueContext;
  class IntervalContext;
  class IntervalFieldContext;
  class NormalFormContext;
  class TypeContext;
  class TypeParameterContext;
  class BaseTypeContext;
  class WhenClauseContext;
  class FilterContext;
  class OverContext;
  class WindowFrameContext;
  class FrameBoundContext;
  class ExplainOptionContext;
  class TransactionModeContext;
  class LevelOfIsolationContext;
  class CallArgumentContext;
  class PathElementContext;
  class PathSpecificationContext;
  class PrivilegeContext;
  class QualifiedNameContext;
  class IdentifierContext;
  class NumberContext;
  class NonReservedContext; 

  class  SingleStatementContext : public antlr4::ParserRuleContext {
  public:
    SingleStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleStatementContext* singleStatement();

  class  StandaloneExpressionContext : public antlr4::ParserRuleContext {
  public:
    StandaloneExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StandaloneExpressionContext* standaloneExpression();

  class  StandalonePathSpecificationContext : public antlr4::ParserRuleContext {
  public:
    StandalonePathSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathSpecificationContext *pathSpecification();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StandalonePathSpecificationContext* standalonePathSpecification();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExplainContext : public StatementContext {
  public:
    ExplainContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *EXPLAIN();
    StatementContext *statement();
    antlr4::tree::TerminalNode *ANALYZE();
    antlr4::tree::TerminalNode *VERBOSE();
    std::vector<ExplainOptionContext *> explainOption();
    ExplainOptionContext* explainOption(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PrepareContext : public StatementContext {
  public:
    PrepareContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PREPARE();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *FROM();
    StatementContext *statement();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CreateTableContext : public StatementContext {
  public:
    CreateTableContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *TABLE();
    QualifiedNameContext *qualifiedName();
    std::vector<TableElementContext *> tableElement();
    TableElementContext* tableElement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *COMMENT();
    StringContext *string();
    antlr4::tree::TerminalNode *WITH();
    PropertiesContext *properties();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StartTransactionContext : public StatementContext {
  public:
    StartTransactionContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *TRANSACTION();
    std::vector<TransactionModeContext *> transactionMode();
    TransactionModeContext* transactionMode(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CreateTableAsSelectContext : public StatementContext {
  public:
    CreateTableAsSelectContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *TABLE();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *AS();
    QueryContext *query();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    ColumnAliasesContext *columnAliases();
    antlr4::tree::TerminalNode *COMMENT();
    StringContext *string();
    std::vector<antlr4::tree::TerminalNode *> WITH();
    antlr4::tree::TerminalNode* WITH(size_t i);
    PropertiesContext *properties();
    antlr4::tree::TerminalNode *DATA();
    antlr4::tree::TerminalNode *NO();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UseContext : public StatementContext {
  public:
    UseContext(StatementContext *ctx);

    CentSqlParser::IdentifierContext *schema = nullptr;
    CentSqlParser::IdentifierContext *catalog = nullptr;
    antlr4::tree::TerminalNode *USE();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowStatsContext : public StatementContext {
  public:
    ShowStatsContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *STATS();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *ON();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeallocateContext : public StatementContext {
  public:
    DeallocateContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DEALLOCATE();
    antlr4::tree::TerminalNode *PREPARE();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RenameTableContext : public StatementContext {
  public:
    RenameTableContext(StatementContext *ctx);

    CentSqlParser::QualifiedNameContext *from = nullptr;
    CentSqlParser::QualifiedNameContext *to = nullptr;
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *TO();
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CommitContext : public StatementContext {
  public:
    CommitContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *COMMIT();
    antlr4::tree::TerminalNode *WORK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RevokeContext : public StatementContext {
  public:
    RevokeContext(StatementContext *ctx);

    CentSqlParser::IdentifierContext *grantee = nullptr;
    antlr4::tree::TerminalNode *REVOKE();
    antlr4::tree::TerminalNode *ON();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *FROM();
    IdentifierContext *identifier();
    std::vector<PrivilegeContext *> privilege();
    PrivilegeContext* privilege(size_t i);
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *PRIVILEGES();
    antlr4::tree::TerminalNode *GRANT();
    antlr4::tree::TerminalNode *OPTION();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *TABLE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DropColumnContext : public StatementContext {
  public:
    DropColumnContext(StatementContext *ctx);

    CentSqlParser::QualifiedNameContext *tableName = nullptr;
    CentSqlParser::QualifiedNameContext *column = nullptr;
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *COLUMN();
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DropViewContext : public StatementContext {
  public:
    DropViewContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *VIEW();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *EXISTS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeleteContext : public StatementContext {
  public:
    DeleteContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *FROM();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *WHERE();
    BooleanExpressionContext *booleanExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowTablesContext : public StatementContext {
  public:
    ShowTablesContext(StatementContext *ctx);

    CentSqlParser::StringContext *pattern = nullptr;
    CentSqlParser::StringContext *escape = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *TABLES();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *LIKE();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *IN();
    std::vector<StringContext *> string();
    StringContext* string(size_t i);
    antlr4::tree::TerminalNode *ESCAPE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DescribeInputContext : public StatementContext {
  public:
    DescribeInputContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DESCRIBE();
    antlr4::tree::TerminalNode *INPUT();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowStatsForQueryContext : public StatementContext {
  public:
    ShowStatsForQueryContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *STATS();
    antlr4::tree::TerminalNode *FOR();
    QuerySpecificationContext *querySpecification();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowCatalogsContext : public StatementContext {
  public:
    ShowCatalogsContext(StatementContext *ctx);

    CentSqlParser::StringContext *pattern = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *CATALOGS();
    antlr4::tree::TerminalNode *LIKE();
    StringContext *string();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StatementDefaultContext : public StatementContext {
  public:
    StatementDefaultContext(StatementContext *ctx);

    QueryContext *query();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RenameColumnContext : public StatementContext {
  public:
    RenameColumnContext(StatementContext *ctx);

    CentSqlParser::QualifiedNameContext *tableName = nullptr;
    CentSqlParser::IdentifierContext *from = nullptr;
    CentSqlParser::IdentifierContext *to = nullptr;
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *COLUMN();
    antlr4::tree::TerminalNode *TO();
    QualifiedNameContext *qualifiedName();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SetSessionContext : public StatementContext {
  public:
    SetSessionContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *SESSION();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *EQ();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CreateViewContext : public StatementContext {
  public:
    CreateViewContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *VIEW();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *AS();
    QueryContext *query();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *REPLACE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowCreateTableContext : public StatementContext {
  public:
    ShowCreateTableContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *TABLE();
    QualifiedNameContext *qualifiedName();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowSchemasContext : public StatementContext {
  public:
    ShowSchemasContext(StatementContext *ctx);

    CentSqlParser::StringContext *pattern = nullptr;
    CentSqlParser::StringContext *escape = nullptr;
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *SCHEMAS();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *LIKE();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *IN();
    std::vector<StringContext *> string();
    StringContext* string(size_t i);
    antlr4::tree::TerminalNode *ESCAPE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DropTableContext : public StatementContext {
  public:
    DropTableContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *TABLE();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *EXISTS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowColumnsContext : public StatementContext {
  public:
    ShowColumnsContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *COLUMNS();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *DESCRIBE();
    antlr4::tree::TerminalNode *DESC();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RollbackContext : public StatementContext {
  public:
    RollbackContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *WORK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddColumnContext : public StatementContext {
  public:
    AddColumnContext(StatementContext *ctx);

    CentSqlParser::QualifiedNameContext *tableName = nullptr;
    CentSqlParser::ColumnDefinitionContext *column = nullptr;
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *COLUMN();
    QualifiedNameContext *qualifiedName();
    ColumnDefinitionContext *columnDefinition();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ResetSessionContext : public StatementContext {
  public:
    ResetSessionContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RESET();
    antlr4::tree::TerminalNode *SESSION();
    QualifiedNameContext *qualifiedName();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InsertIntoContext : public StatementContext {
  public:
    InsertIntoContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *INSERT();
    antlr4::tree::TerminalNode *INTO();
    QualifiedNameContext *qualifiedName();
    QueryContext *query();
    ColumnAliasesContext *columnAliases();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SetPathContext : public StatementContext {
  public:
    SetPathContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *PATH();
    PathSpecificationContext *pathSpecification();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowSessionContext : public StatementContext {
  public:
    ShowSessionContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *SESSION();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CreateSchemaContext : public StatementContext {
  public:
    CreateSchemaContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *SCHEMA();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *WITH();
    PropertiesContext *properties();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExecuteContext : public StatementContext {
  public:
    ExecuteContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *EXECUTE();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *USING();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallContext : public StatementContext {
  public:
    CallContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CALL();
    QualifiedNameContext *qualifiedName();
    std::vector<CallArgumentContext *> callArgument();
    CallArgumentContext* callArgument(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RenameSchemaContext : public StatementContext {
  public:
    RenameSchemaContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *SCHEMA();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *TO();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowGrantsContext : public StatementContext {
  public:
    ShowGrantsContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *GRANTS();
    antlr4::tree::TerminalNode *ON();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *TABLE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowFunctionsContext : public StatementContext {
  public:
    ShowFunctionsContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *FUNCTIONS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DescribeOutputContext : public StatementContext {
  public:
    DescribeOutputContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DESCRIBE();
    antlr4::tree::TerminalNode *OUTPUT();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DropSchemaContext : public StatementContext {
  public:
    DropSchemaContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *SCHEMA();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *CASCADE();
    antlr4::tree::TerminalNode *RESTRICT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GrantContext : public StatementContext {
  public:
    GrantContext(StatementContext *ctx);

    CentSqlParser::IdentifierContext *grantee = nullptr;
    std::vector<antlr4::tree::TerminalNode *> GRANT();
    antlr4::tree::TerminalNode* GRANT(size_t i);
    antlr4::tree::TerminalNode *ON();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *TO();
    IdentifierContext *identifier();
    std::vector<PrivilegeContext *> privilege();
    PrivilegeContext* privilege(size_t i);
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *PRIVILEGES();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *OPTION();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShowCreateViewContext : public StatementContext {
  public:
    ShowCreateViewContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *VIEW();
    QualifiedNameContext *qualifiedName();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  QueryContext : public antlr4::ParserRuleContext {
  public:
    QueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QueryNoWithContext *queryNoWith();
    WithContext *with();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QueryContext* query();

  class  WithContext : public antlr4::ParserRuleContext {
  public:
    WithContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    std::vector<NamedQueryContext *> namedQuery();
    NamedQueryContext* namedQuery(size_t i);
    antlr4::tree::TerminalNode *RECURSIVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WithContext* with();

  class  TableElementContext : public antlr4::ParserRuleContext {
  public:
    TableElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ColumnDefinitionContext *columnDefinition();
    LikeClauseContext *likeClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableElementContext* tableElement();

  class  ColumnDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ColumnDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    TypeContext *type();
    antlr4::tree::TerminalNode *COMMENT();
    StringContext *string();
    antlr4::tree::TerminalNode *WITH();
    PropertiesContext *properties();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColumnDefinitionContext* columnDefinition();

  class  LikeClauseContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *optionType = nullptr;;
    LikeClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIKE();
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *PROPERTIES();
    antlr4::tree::TerminalNode *INCLUDING();
    antlr4::tree::TerminalNode *EXCLUDING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LikeClauseContext* likeClause();

  class  PropertiesContext : public antlr4::ParserRuleContext {
  public:
    PropertiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PropertyContext *> property();
    PropertyContext* property(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertiesContext* properties();

  class  PropertyContext : public antlr4::ParserRuleContext {
  public:
    PropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *EQ();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PropertyContext* property();

  class  QueryNoWithContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *limit = nullptr;;
    QueryNoWithContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QueryTermContext *queryTerm();
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    std::vector<SortItemContext *> sortItem();
    SortItemContext* sortItem(size_t i);
    antlr4::tree::TerminalNode *LIMIT();
    antlr4::tree::TerminalNode *INTEGER_VALUE();
    antlr4::tree::TerminalNode *ALL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QueryNoWithContext* queryNoWith();

  class  QueryTermContext : public antlr4::ParserRuleContext {
  public:
    QueryTermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    QueryTermContext() : antlr4::ParserRuleContext() { }
    void copyFrom(QueryTermContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  QueryTermDefaultContext : public QueryTermContext {
  public:
    QueryTermDefaultContext(QueryTermContext *ctx);

    QueryPrimaryContext *queryPrimary();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SetOperationContext : public QueryTermContext {
  public:
    SetOperationContext(QueryTermContext *ctx);

    CentSqlParser::QueryTermContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    CentSqlParser::QueryTermContext *right = nullptr;
    std::vector<QueryTermContext *> queryTerm();
    QueryTermContext* queryTerm(size_t i);
    antlr4::tree::TerminalNode *INTERSECT();
    SetQuantifierContext *setQuantifier();
    antlr4::tree::TerminalNode *UNION();
    antlr4::tree::TerminalNode *EXCEPT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  QueryTermContext* queryTerm();
  QueryTermContext* queryTerm(int precedence);
  class  QueryPrimaryContext : public antlr4::ParserRuleContext {
  public:
    QueryPrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    QueryPrimaryContext() : antlr4::ParserRuleContext() { }
    void copyFrom(QueryPrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SubqueryContext : public QueryPrimaryContext {
  public:
    SubqueryContext(QueryPrimaryContext *ctx);

    QueryNoWithContext *queryNoWith();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  QueryPrimaryDefaultContext : public QueryPrimaryContext {
  public:
    QueryPrimaryDefaultContext(QueryPrimaryContext *ctx);

    QuerySpecificationContext *querySpecification();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TableContext : public QueryPrimaryContext {
  public:
    TableContext(QueryPrimaryContext *ctx);

    antlr4::tree::TerminalNode *TABLE();
    QualifiedNameContext *qualifiedName();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InlineTableContext : public QueryPrimaryContext {
  public:
    InlineTableContext(QueryPrimaryContext *ctx);

    antlr4::tree::TerminalNode *VALUES();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  QueryPrimaryContext* queryPrimary();

  class  SortItemContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *ordering = nullptr;;
    antlr4::Token *nullOrdering = nullptr;;
    SortItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NULLS();
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *DESC();
    antlr4::tree::TerminalNode *FIRST();
    antlr4::tree::TerminalNode *LAST();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SortItemContext* sortItem();

  class  QuerySpecificationContext : public antlr4::ParserRuleContext {
  public:
    CentSqlParser::BooleanExpressionContext *where = nullptr;;
    CentSqlParser::BooleanExpressionContext *having = nullptr;;
    QuerySpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    std::vector<SelectItemContext *> selectItem();
    SelectItemContext* selectItem(size_t i);
    SetQuantifierContext *setQuantifier();
    antlr4::tree::TerminalNode *FROM();
    std::vector<RelationContext *> relation();
    RelationContext* relation(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    antlr4::tree::TerminalNode *GROUP();
    antlr4::tree::TerminalNode *BY();
    GroupByContext *groupBy();
    antlr4::tree::TerminalNode *HAVING();
    std::vector<BooleanExpressionContext *> booleanExpression();
    BooleanExpressionContext* booleanExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuerySpecificationContext* querySpecification();

  class  GroupByContext : public antlr4::ParserRuleContext {
  public:
    GroupByContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<GroupingElementContext *> groupingElement();
    GroupingElementContext* groupingElement(size_t i);
    SetQuantifierContext *setQuantifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupByContext* groupBy();

  class  GroupingElementContext : public antlr4::ParserRuleContext {
  public:
    GroupingElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    GroupingElementContext() : antlr4::ParserRuleContext() { }
    void copyFrom(GroupingElementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MultipleGroupingSetsContext : public GroupingElementContext {
  public:
    MultipleGroupingSetsContext(GroupingElementContext *ctx);

    antlr4::tree::TerminalNode *GROUPING();
    antlr4::tree::TerminalNode *SETS();
    std::vector<GroupingSetContext *> groupingSet();
    GroupingSetContext* groupingSet(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SingleGroupingSetContext : public GroupingElementContext {
  public:
    SingleGroupingSetContext(GroupingElementContext *ctx);

    GroupingSetContext *groupingSet();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CubeContext : public GroupingElementContext {
  public:
    CubeContext(GroupingElementContext *ctx);

    antlr4::tree::TerminalNode *CUBE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RollupContext : public GroupingElementContext {
  public:
    RollupContext(GroupingElementContext *ctx);

    antlr4::tree::TerminalNode *ROLLUP();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  GroupingElementContext* groupingElement();

  class  GroupingSetContext : public antlr4::ParserRuleContext {
  public:
    GroupingSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GroupingSetContext* groupingSet();

  class  NamedQueryContext : public antlr4::ParserRuleContext {
  public:
    CentSqlParser::IdentifierContext *name = nullptr;;
    NamedQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AS();
    QueryContext *query();
    IdentifierContext *identifier();
    ColumnAliasesContext *columnAliases();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedQueryContext* namedQuery();

  class  SetQuantifierContext : public antlr4::ParserRuleContext {
  public:
    SetQuantifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DISTINCT();
    antlr4::tree::TerminalNode *ALL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetQuantifierContext* setQuantifier();

  class  SelectItemContext : public antlr4::ParserRuleContext {
  public:
    SelectItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    SelectItemContext() : antlr4::ParserRuleContext() { }
    void copyFrom(SelectItemContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SelectAllContext : public SelectItemContext {
  public:
    SelectAllContext(SelectItemContext *ctx);

    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *ASTERISK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelectSingleContext : public SelectItemContext {
  public:
    SelectSingleContext(SelectItemContext *ctx);

    ExpressionContext *expression();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *AS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  SelectItemContext* selectItem();

  class  RelationContext : public antlr4::ParserRuleContext {
  public:
    RelationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelationContext() : antlr4::ParserRuleContext() { }
    void copyFrom(RelationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RelationDefaultContext : public RelationContext {
  public:
    RelationDefaultContext(RelationContext *ctx);

    SampledRelationContext *sampledRelation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  JoinRelationContext : public RelationContext {
  public:
    JoinRelationContext(RelationContext *ctx);

    CentSqlParser::RelationContext *left = nullptr;
    CentSqlParser::SampledRelationContext *right = nullptr;
    CentSqlParser::RelationContext *rightRelation = nullptr;
    std::vector<RelationContext *> relation();
    RelationContext* relation(size_t i);
    antlr4::tree::TerminalNode *CROSS();
    antlr4::tree::TerminalNode *JOIN();
    JoinTypeContext *joinType();
    JoinCriteriaContext *joinCriteria();
    antlr4::tree::TerminalNode *NATURAL();
    SampledRelationContext *sampledRelation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RelationContext* relation();
  RelationContext* relation(int precedence);
  class  JoinTypeContext : public antlr4::ParserRuleContext {
  public:
    JoinTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INNER();
    antlr4::tree::TerminalNode *LEFT();
    antlr4::tree::TerminalNode *OUTER();
    antlr4::tree::TerminalNode *RIGHT();
    antlr4::tree::TerminalNode *FULL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JoinTypeContext* joinType();

  class  JoinCriteriaContext : public antlr4::ParserRuleContext {
  public:
    JoinCriteriaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON();
    BooleanExpressionContext *booleanExpression();
    antlr4::tree::TerminalNode *USING();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JoinCriteriaContext* joinCriteria();

  class  SampledRelationContext : public antlr4::ParserRuleContext {
  public:
    CentSqlParser::ExpressionContext *percentage = nullptr;;
    SampledRelationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AliasedRelationContext *aliasedRelation();
    antlr4::tree::TerminalNode *TABLESAMPLE();
    SampleTypeContext *sampleType();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SampledRelationContext* sampledRelation();

  class  SampleTypeContext : public antlr4::ParserRuleContext {
  public:
    SampleTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BERNOULLI();
    antlr4::tree::TerminalNode *SYSTEM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SampleTypeContext* sampleType();

  class  AliasedRelationContext : public antlr4::ParserRuleContext {
  public:
    AliasedRelationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationPrimaryContext *relationPrimary();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *AS();
    ColumnAliasesContext *columnAliases();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AliasedRelationContext* aliasedRelation();

  class  ColumnAliasesContext : public antlr4::ParserRuleContext {
  public:
    ColumnAliasesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColumnAliasesContext* columnAliases();

  class  RelationPrimaryContext : public antlr4::ParserRuleContext {
  public:
    RelationPrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    RelationPrimaryContext() : antlr4::ParserRuleContext() { }
    void copyFrom(RelationPrimaryContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SubqueryRelationContext : public RelationPrimaryContext {
  public:
    SubqueryRelationContext(RelationPrimaryContext *ctx);

    QueryContext *query();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedRelationContext : public RelationPrimaryContext {
  public:
    ParenthesizedRelationContext(RelationPrimaryContext *ctx);

    RelationContext *relation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnnestContext : public RelationPrimaryContext {
  public:
    UnnestContext(RelationPrimaryContext *ctx);

    antlr4::tree::TerminalNode *UNNEST();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *ORDINALITY();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LateralContext : public RelationPrimaryContext {
  public:
    LateralContext(RelationPrimaryContext *ctx);

    antlr4::tree::TerminalNode *LATERAL();
    QueryContext *query();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TableNameContext : public RelationPrimaryContext {
  public:
    TableNameContext(RelationPrimaryContext *ctx);

    QualifiedNameContext *qualifiedName();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  RelationPrimaryContext* relationPrimary();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExpressionContext *booleanExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  BooleanExpressionContext : public antlr4::ParserRuleContext {
  public:
    BooleanExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BooleanExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(BooleanExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LogicalNotContext : public BooleanExpressionContext {
  public:
    LogicalNotContext(BooleanExpressionContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    BooleanExpressionContext *booleanExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PredicatedContext : public BooleanExpressionContext {
  public:
    PredicatedContext(BooleanExpressionContext *ctx);

    CentSqlParser::ValueExpressionContext *valueExpressionContext = nullptr;
    ValueExpressionContext *valueExpression();
    PredicateContext *predicate();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalBinaryContext : public BooleanExpressionContext {
  public:
    LogicalBinaryContext(BooleanExpressionContext *ctx);

    CentSqlParser::BooleanExpressionContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    CentSqlParser::BooleanExpressionContext *right = nullptr;
    std::vector<BooleanExpressionContext *> booleanExpression();
    BooleanExpressionContext* booleanExpression(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BooleanExpressionContext* booleanExpression();
  BooleanExpressionContext* booleanExpression(int precedence);
  class  PredicateContext : public antlr4::ParserRuleContext {
  public:
    antlr4::ParserRuleContext* value;
    PredicateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    PredicateContext(antlr4::ParserRuleContext *parent, size_t invokingState, antlr4::ParserRuleContext* value);
   
    PredicateContext() : antlr4::ParserRuleContext(), value(nullptr) { }
    void copyFrom(PredicateContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ComparisonContext : public PredicateContext {
  public:
    ComparisonContext(PredicateContext *ctx);

    CentSqlParser::ValueExpressionContext *right = nullptr;
    ComparisonOperatorContext *comparisonOperator();
    ValueExpressionContext *valueExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LikeContext : public PredicateContext {
  public:
    LikeContext(PredicateContext *ctx);

    CentSqlParser::ValueExpressionContext *pattern = nullptr;
    CentSqlParser::ValueExpressionContext *escape = nullptr;
    antlr4::tree::TerminalNode *LIKE();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *ESCAPE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InSubqueryContext : public PredicateContext {
  public:
    InSubqueryContext(PredicateContext *ctx);

    antlr4::tree::TerminalNode *IN();
    QueryContext *query();
    antlr4::tree::TerminalNode *NOT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DistinctFromContext : public PredicateContext {
  public:
    DistinctFromContext(PredicateContext *ctx);

    CentSqlParser::ValueExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *DISTINCT();
    antlr4::tree::TerminalNode *FROM();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *NOT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InListContext : public PredicateContext {
  public:
    InListContext(PredicateContext *ctx);

    antlr4::tree::TerminalNode *IN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *NOT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullPredicateContext : public PredicateContext {
  public:
    NullPredicateContext(PredicateContext *ctx);

    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NULL_VALUE();
    antlr4::tree::TerminalNode *NOT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BetweenContext : public PredicateContext {
  public:
    BetweenContext(PredicateContext *ctx);

    CentSqlParser::ValueExpressionContext *lower = nullptr;
    CentSqlParser::ValueExpressionContext *upper = nullptr;
    antlr4::tree::TerminalNode *BETWEEN();
    antlr4::tree::TerminalNode *AND();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *NOT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  QuantifiedComparisonContext : public PredicateContext {
  public:
    QuantifiedComparisonContext(PredicateContext *ctx);

    ComparisonOperatorContext *comparisonOperator();
    ComparisonQuantifierContext *comparisonQuantifier();
    QueryContext *query();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PredicateContext* predicate(antlr4::ParserRuleContext* value);

  class  ValueExpressionContext : public antlr4::ParserRuleContext {
  public:
    ValueExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ValueExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ValueExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ValueExpressionDefaultContext : public ValueExpressionContext {
  public:
    ValueExpressionDefaultContext(ValueExpressionContext *ctx);

    PrimaryExpressionContext *primaryExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConcatenationContext : public ValueExpressionContext {
  public:
    ConcatenationContext(ValueExpressionContext *ctx);

    CentSqlParser::ValueExpressionContext *left = nullptr;
    CentSqlParser::ValueExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *CONCAT();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArithmeticBinaryContext : public ValueExpressionContext {
  public:
    ArithmeticBinaryContext(ValueExpressionContext *ctx);

    CentSqlParser::ValueExpressionContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    CentSqlParser::ValueExpressionContext *right = nullptr;
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *ASTERISK();
    antlr4::tree::TerminalNode *SLASH();
    antlr4::tree::TerminalNode *PERCENT();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArithmeticUnaryContext : public ValueExpressionContext {
  public:
    ArithmeticUnaryContext(ValueExpressionContext *ctx);

    antlr4::Token *oper = nullptr;
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *PLUS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtTimeZoneContext : public ValueExpressionContext {
  public:
    AtTimeZoneContext(ValueExpressionContext *ctx);

    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *AT();
    TimeZoneSpecifierContext *timeZoneSpecifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ValueExpressionContext* valueExpression();
  ValueExpressionContext* valueExpression(int precedence);
  class  PrimaryExpressionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExpressionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(PrimaryExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DereferenceContext : public PrimaryExpressionContext {
  public:
    DereferenceContext(PrimaryExpressionContext *ctx);

    CentSqlParser::PrimaryExpressionContext *base = nullptr;
    CentSqlParser::IdentifierContext *fieldName = nullptr;
    PrimaryExpressionContext *primaryExpression();
    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeConstructorContext : public PrimaryExpressionContext {
  public:
    TypeConstructorContext(PrimaryExpressionContext *ctx);

    IdentifierContext *identifier();
    StringContext *string();
    antlr4::tree::TerminalNode *DOUBLE_PRECISION();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SpecialDateTimeFunctionContext : public PrimaryExpressionContext {
  public:
    SpecialDateTimeFunctionContext(PrimaryExpressionContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::Token *precision = nullptr;
    antlr4::tree::TerminalNode *CURRENT_DATE();
    antlr4::tree::TerminalNode *CURRENT_TIME();
    antlr4::tree::TerminalNode *INTEGER_VALUE();
    antlr4::tree::TerminalNode *CURRENT_TIMESTAMP();
    antlr4::tree::TerminalNode *LOCALTIME();
    antlr4::tree::TerminalNode *LOCALTIMESTAMP();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubstringContext : public PrimaryExpressionContext {
  public:
    SubstringContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *SUBSTRING();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *FOR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CastContext : public PrimaryExpressionContext {
  public:
    CastContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *CAST();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *AS();
    TypeContext *type();
    antlr4::tree::TerminalNode *TRY_CAST();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LambdaContext : public PrimaryExpressionContext {
  public:
    LambdaContext(PrimaryExpressionContext *ctx);

    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedExpressionContext : public PrimaryExpressionContext {
  public:
    ParenthesizedExpressionContext(PrimaryExpressionContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParameterContext : public PrimaryExpressionContext {
  public:
    ParameterContext(PrimaryExpressionContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NormalizeContext : public PrimaryExpressionContext {
  public:
    NormalizeContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *NORMALIZE();
    ValueExpressionContext *valueExpression();
    NormalFormContext *normalForm();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntervalLiteralContext : public PrimaryExpressionContext {
  public:
    IntervalLiteralContext(PrimaryExpressionContext *ctx);

    IntervalContext *interval();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumericLiteralContext : public PrimaryExpressionContext {
  public:
    NumericLiteralContext(PrimaryExpressionContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanLiteralContext : public PrimaryExpressionContext {
  public:
    BooleanLiteralContext(PrimaryExpressionContext *ctx);

    BooleanValueContext *booleanValue();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SimpleCaseContext : public PrimaryExpressionContext {
  public:
    SimpleCaseContext(PrimaryExpressionContext *ctx);

    CentSqlParser::ExpressionContext *elseExpression = nullptr;
    antlr4::tree::TerminalNode *CASE();
    ValueExpressionContext *valueExpression();
    antlr4::tree::TerminalNode *END();
    std::vector<WhenClauseContext *> whenClause();
    WhenClauseContext* whenClause(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ColumnReferenceContext : public PrimaryExpressionContext {
  public:
    ColumnReferenceContext(PrimaryExpressionContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullLiteralContext : public PrimaryExpressionContext {
  public:
    NullLiteralContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *NULL_VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RowConstructorContext : public PrimaryExpressionContext {
  public:
    RowConstructorContext(PrimaryExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ROW();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubscriptContext : public PrimaryExpressionContext {
  public:
    SubscriptContext(PrimaryExpressionContext *ctx);

    CentSqlParser::PrimaryExpressionContext *value = nullptr;
    CentSqlParser::ValueExpressionContext *index = nullptr;
    PrimaryExpressionContext *primaryExpression();
    ValueExpressionContext *valueExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CurrentPathContext : public PrimaryExpressionContext {
  public:
    CurrentPathContext(PrimaryExpressionContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::tree::TerminalNode *CURRENT_PATH();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubqueryExpressionContext : public PrimaryExpressionContext {
  public:
    SubqueryExpressionContext(PrimaryExpressionContext *ctx);

    QueryContext *query();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryLiteralContext : public PrimaryExpressionContext {
  public:
    BinaryLiteralContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *BINARY_LITERAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CurrentUserContext : public PrimaryExpressionContext {
  public:
    CurrentUserContext(PrimaryExpressionContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::tree::TerminalNode *CURRENT_USER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExtractContext : public PrimaryExpressionContext {
  public:
    ExtractContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *EXTRACT();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *FROM();
    ValueExpressionContext *valueExpression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringLiteralContext : public PrimaryExpressionContext {
  public:
    StringLiteralContext(PrimaryExpressionContext *ctx);

    StringContext *string();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayConstructorContext : public PrimaryExpressionContext {
  public:
    ArrayConstructorContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *ARRAY();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallContext : public PrimaryExpressionContext {
  public:
    FunctionCallContext(PrimaryExpressionContext *ctx);

    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *ASTERISK();
    FilterContext *filter();
    OverContext *over();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *ORDER();
    antlr4::tree::TerminalNode *BY();
    std::vector<SortItemContext *> sortItem();
    SortItemContext* sortItem(size_t i);
    SetQuantifierContext *setQuantifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExistsContext : public PrimaryExpressionContext {
  public:
    ExistsContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *EXISTS();
    QueryContext *query();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositionContext : public PrimaryExpressionContext {
  public:
    PositionContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *POSITION();
    std::vector<ValueExpressionContext *> valueExpression();
    ValueExpressionContext* valueExpression(size_t i);
    antlr4::tree::TerminalNode *IN();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SearchedCaseContext : public PrimaryExpressionContext {
  public:
    SearchedCaseContext(PrimaryExpressionContext *ctx);

    CentSqlParser::ExpressionContext *elseExpression = nullptr;
    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *END();
    std::vector<WhenClauseContext *> whenClause();
    WhenClauseContext* whenClause(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GroupingOperationContext : public PrimaryExpressionContext {
  public:
    GroupingOperationContext(PrimaryExpressionContext *ctx);

    antlr4::tree::TerminalNode *GROUPING();
    std::vector<QualifiedNameContext *> qualifiedName();
    QualifiedNameContext* qualifiedName(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimaryExpressionContext* primaryExpression();
  PrimaryExpressionContext* primaryExpression(int precedence);
  class  StringContext : public antlr4::ParserRuleContext {
  public:
    StringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StringContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StringContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnicodeStringLiteralContext : public StringContext {
  public:
    UnicodeStringLiteralContext(StringContext *ctx);

    antlr4::tree::TerminalNode *UNICODE_STRING();
    antlr4::tree::TerminalNode *UESCAPE();
    antlr4::tree::TerminalNode *STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BasicStringLiteralContext : public StringContext {
  public:
    BasicStringLiteralContext(StringContext *ctx);

    antlr4::tree::TerminalNode *STRING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StringContext* string();

  class  TimeZoneSpecifierContext : public antlr4::ParserRuleContext {
  public:
    TimeZoneSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TimeZoneSpecifierContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TimeZoneSpecifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TimeZoneIntervalContext : public TimeZoneSpecifierContext {
  public:
    TimeZoneIntervalContext(TimeZoneSpecifierContext *ctx);

    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *ZONE();
    IntervalContext *interval();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TimeZoneStringContext : public TimeZoneSpecifierContext {
  public:
    TimeZoneStringContext(TimeZoneSpecifierContext *ctx);

    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *ZONE();
    StringContext *string();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TimeZoneSpecifierContext* timeZoneSpecifier();

  class  ComparisonOperatorContext : public antlr4::ParserRuleContext {
  public:
    ComparisonOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LTE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GTE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonOperatorContext* comparisonOperator();

  class  ComparisonQuantifierContext : public antlr4::ParserRuleContext {
  public:
    ComparisonQuantifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *SOME();
    antlr4::tree::TerminalNode *ANY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonQuantifierContext* comparisonQuantifier();

  class  BooleanValueContext : public antlr4::ParserRuleContext {
  public:
    BooleanValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE_VALUE();
    antlr4::tree::TerminalNode *FALSE_VALUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanValueContext* booleanValue();

  class  IntervalContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *sign = nullptr;;
    CentSqlParser::IntervalFieldContext *from = nullptr;;
    CentSqlParser::IntervalFieldContext *to = nullptr;;
    IntervalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTERVAL();
    StringContext *string();
    std::vector<IntervalFieldContext *> intervalField();
    IntervalFieldContext* intervalField(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntervalContext* interval();

  class  IntervalFieldContext : public antlr4::ParserRuleContext {
  public:
    IntervalFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *YEAR();
    antlr4::tree::TerminalNode *MONTH();
    antlr4::tree::TerminalNode *DAY();
    antlr4::tree::TerminalNode *HOUR();
    antlr4::tree::TerminalNode *MINUTE();
    antlr4::tree::TerminalNode *SECOND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IntervalFieldContext* intervalField();

  class  NormalFormContext : public antlr4::ParserRuleContext {
  public:
    NormalFormContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NFD();
    antlr4::tree::TerminalNode *NFC();
    antlr4::tree::TerminalNode *NFKD();
    antlr4::tree::TerminalNode *NFKC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NormalFormContext* normalForm();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    CentSqlParser::IntervalFieldContext *from = nullptr;;
    CentSqlParser::IntervalFieldContext *to = nullptr;;
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *ROW();
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    BaseTypeContext *baseType();
    std::vector<TypeParameterContext *> typeParameter();
    TypeParameterContext* typeParameter(size_t i);
    antlr4::tree::TerminalNode *INTERVAL();
    antlr4::tree::TerminalNode *TO();
    std::vector<IntervalFieldContext *> intervalField();
    IntervalFieldContext* intervalField(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();
  TypeContext* type(int precedence);
  class  TypeParameterContext : public antlr4::ParserRuleContext {
  public:
    TypeParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_VALUE();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeParameterContext* typeParameter();

  class  BaseTypeContext : public antlr4::ParserRuleContext {
  public:
    BaseTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TIME_WITH_TIME_ZONE();
    antlr4::tree::TerminalNode *TIMESTAMP_WITH_TIME_ZONE();
    antlr4::tree::TerminalNode *DOUBLE_PRECISION();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BaseTypeContext* baseType();

  class  WhenClauseContext : public antlr4::ParserRuleContext {
  public:
    CentSqlParser::ExpressionContext *condition = nullptr;;
    CentSqlParser::ExpressionContext *result = nullptr;;
    WhenClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    antlr4::tree::TerminalNode *THEN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhenClauseContext* whenClause();

  class  FilterContext : public antlr4::ParserRuleContext {
  public:
    FilterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FILTER();
    antlr4::tree::TerminalNode *WHERE();
    BooleanExpressionContext *booleanExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FilterContext* filter();

  class  OverContext : public antlr4::ParserRuleContext {
  public:
    CentSqlParser::ExpressionContext *expressionContext = nullptr;;
    std::vector<ExpressionContext *> partition;;
    OverContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OVER();
    antlr4::tree::TerminalNode *PARTITION();
    std::vector<antlr4::tree::TerminalNode *> BY();
    antlr4::tree::TerminalNode* BY(size_t i);
    antlr4::tree::TerminalNode *ORDER();
    std::vector<SortItemContext *> sortItem();
    SortItemContext* sortItem(size_t i);
    WindowFrameContext *windowFrame();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OverContext* over();

  class  WindowFrameContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *frameType = nullptr;;
    CentSqlParser::FrameBoundContext *start = nullptr;;
    CentSqlParser::FrameBoundContext *end = nullptr;;
    WindowFrameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RANGE();
    std::vector<FrameBoundContext *> frameBound();
    FrameBoundContext* frameBound(size_t i);
    antlr4::tree::TerminalNode *ROWS();
    antlr4::tree::TerminalNode *BETWEEN();
    antlr4::tree::TerminalNode *AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WindowFrameContext* windowFrame();

  class  FrameBoundContext : public antlr4::ParserRuleContext {
  public:
    FrameBoundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FrameBoundContext() : antlr4::ParserRuleContext() { }
    void copyFrom(FrameBoundContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BoundedFrameContext : public FrameBoundContext {
  public:
    BoundedFrameContext(FrameBoundContext *ctx);

    antlr4::Token *boundType = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *FOLLOWING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnboundedFrameContext : public FrameBoundContext {
  public:
    UnboundedFrameContext(FrameBoundContext *ctx);

    antlr4::Token *boundType = nullptr;
    antlr4::tree::TerminalNode *UNBOUNDED();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *FOLLOWING();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CurrentRowBoundContext : public FrameBoundContext {
  public:
    CurrentRowBoundContext(FrameBoundContext *ctx);

    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *ROW();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FrameBoundContext* frameBound();

  class  ExplainOptionContext : public antlr4::ParserRuleContext {
  public:
    ExplainOptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExplainOptionContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExplainOptionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExplainFormatContext : public ExplainOptionContext {
  public:
    ExplainFormatContext(ExplainOptionContext *ctx);

    antlr4::Token *value = nullptr;
    antlr4::tree::TerminalNode *FORMAT();
    antlr4::tree::TerminalNode *TEXT();
    antlr4::tree::TerminalNode *GRAPHVIZ();
    antlr4::tree::TerminalNode *JSON();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExplainTypeContext : public ExplainOptionContext {
  public:
    ExplainTypeContext(ExplainOptionContext *ctx);

    antlr4::Token *value = nullptr;
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *LOGICAL();
    antlr4::tree::TerminalNode *DISTRIBUTED();
    antlr4::tree::TerminalNode *VALIDATE();
    antlr4::tree::TerminalNode *IO();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExplainOptionContext* explainOption();

  class  TransactionModeContext : public antlr4::ParserRuleContext {
  public:
    TransactionModeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TransactionModeContext() : antlr4::ParserRuleContext() { }
    void copyFrom(TransactionModeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TransactionAccessModeContext : public TransactionModeContext {
  public:
    TransactionAccessModeContext(TransactionModeContext *ctx);

    antlr4::Token *accessMode = nullptr;
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *ONLY();
    antlr4::tree::TerminalNode *WRITE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IsolationLevelContext : public TransactionModeContext {
  public:
    IsolationLevelContext(TransactionModeContext *ctx);

    antlr4::tree::TerminalNode *ISOLATION();
    antlr4::tree::TerminalNode *LEVEL();
    LevelOfIsolationContext *levelOfIsolation();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TransactionModeContext* transactionMode();

  class  LevelOfIsolationContext : public antlr4::ParserRuleContext {
  public:
    LevelOfIsolationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LevelOfIsolationContext() : antlr4::ParserRuleContext() { }
    void copyFrom(LevelOfIsolationContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ReadUncommittedContext : public LevelOfIsolationContext {
  public:
    ReadUncommittedContext(LevelOfIsolationContext *ctx);

    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *UNCOMMITTED();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SerializableContext : public LevelOfIsolationContext {
  public:
    SerializableContext(LevelOfIsolationContext *ctx);

    antlr4::tree::TerminalNode *SERIALIZABLE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReadCommittedContext : public LevelOfIsolationContext {
  public:
    ReadCommittedContext(LevelOfIsolationContext *ctx);

    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *COMMITTED();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RepeatableReadContext : public LevelOfIsolationContext {
  public:
    RepeatableReadContext(LevelOfIsolationContext *ctx);

    antlr4::tree::TerminalNode *REPEATABLE();
    antlr4::tree::TerminalNode *READ();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LevelOfIsolationContext* levelOfIsolation();

  class  CallArgumentContext : public antlr4::ParserRuleContext {
  public:
    CallArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CallArgumentContext() : antlr4::ParserRuleContext() { }
    void copyFrom(CallArgumentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PositionalArgumentContext : public CallArgumentContext {
  public:
    PositionalArgumentContext(CallArgumentContext *ctx);

    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NamedArgumentContext : public CallArgumentContext {
  public:
    NamedArgumentContext(CallArgumentContext *ctx);

    IdentifierContext *identifier();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CallArgumentContext* callArgument();

  class  PathElementContext : public antlr4::ParserRuleContext {
  public:
    PathElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PathElementContext() : antlr4::ParserRuleContext() { }
    void copyFrom(PathElementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  QualifiedArgumentContext : public PathElementContext {
  public:
    QualifiedArgumentContext(PathElementContext *ctx);

    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnqualifiedArgumentContext : public PathElementContext {
  public:
    UnqualifiedArgumentContext(PathElementContext *ctx);

    IdentifierContext *identifier();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PathElementContext* pathElement();

  class  PathSpecificationContext : public antlr4::ParserRuleContext {
  public:
    PathSpecificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PathElementContext *> pathElement();
    PathElementContext* pathElement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PathSpecificationContext* pathSpecification();

  class  PrivilegeContext : public antlr4::ParserRuleContext {
  public:
    PrivilegeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *INSERT();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrivilegeContext* privilege();

  class  QualifiedNameContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedNameContext* qualifiedName();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IdentifierContext() : antlr4::ParserRuleContext() { }
    void copyFrom(IdentifierContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BackQuotedIdentifierContext : public IdentifierContext {
  public:
    BackQuotedIdentifierContext(IdentifierContext *ctx);

    antlr4::tree::TerminalNode *BACKQUOTED_IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  QuotedIdentifierContext : public IdentifierContext {
  public:
    QuotedIdentifierContext(IdentifierContext *ctx);

    antlr4::tree::TerminalNode *QUOTED_IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DigitIdentifierContext : public IdentifierContext {
  public:
    DigitIdentifierContext(IdentifierContext *ctx);

    antlr4::tree::TerminalNode *DIGIT_IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnquotedIdentifierContext : public IdentifierContext {
  public:
    UnquotedIdentifierContext(IdentifierContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    NonReservedContext *nonReserved();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IdentifierContext* identifier();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumberContext() : antlr4::ParserRuleContext() { }
    void copyFrom(NumberContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DecimalLiteralContext : public NumberContext {
  public:
    DecimalLiteralContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *DECIMAL_VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DoubleLiteralContext : public NumberContext {
  public:
    DoubleLiteralContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *DOUBLE_VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntegerLiteralContext : public NumberContext {
  public:
    IntegerLiteralContext(NumberContext *ctx);

    antlr4::tree::TerminalNode *INTEGER_VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NumberContext* number();

  class  NonReservedContext : public antlr4::ParserRuleContext {
  public:
    NonReservedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *ALL();
    antlr4::tree::TerminalNode *ANALYZE();
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *BERNOULLI();
    antlr4::tree::TerminalNode *CALL();
    antlr4::tree::TerminalNode *CASCADE();
    antlr4::tree::TerminalNode *CATALOGS();
    antlr4::tree::TerminalNode *COLUMN();
    antlr4::tree::TerminalNode *COLUMNS();
    antlr4::tree::TerminalNode *COMMENT();
    antlr4::tree::TerminalNode *COMMIT();
    antlr4::tree::TerminalNode *COMMITTED();
    antlr4::tree::TerminalNode *CURRENT();
    antlr4::tree::TerminalNode *DATA();
    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *DAY();
    antlr4::tree::TerminalNode *DESC();
    antlr4::tree::TerminalNode *DISTRIBUTED();
    antlr4::tree::TerminalNode *EXCLUDING();
    antlr4::tree::TerminalNode *EXPLAIN();
    antlr4::tree::TerminalNode *FILTER();
    antlr4::tree::TerminalNode *FIRST();
    antlr4::tree::TerminalNode *FOLLOWING();
    antlr4::tree::TerminalNode *FORMAT();
    antlr4::tree::TerminalNode *FUNCTIONS();
    antlr4::tree::TerminalNode *GRANT();
    antlr4::tree::TerminalNode *GRANTS();
    antlr4::tree::TerminalNode *GRAPHVIZ();
    antlr4::tree::TerminalNode *HOUR();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *INCLUDING();
    antlr4::tree::TerminalNode *INPUT();
    antlr4::tree::TerminalNode *INTERVAL();
    antlr4::tree::TerminalNode *IO();
    antlr4::tree::TerminalNode *ISOLATION();
    antlr4::tree::TerminalNode *JSON();
    antlr4::tree::TerminalNode *LAST();
    antlr4::tree::TerminalNode *LATERAL();
    antlr4::tree::TerminalNode *LEVEL();
    antlr4::tree::TerminalNode *LIMIT();
    antlr4::tree::TerminalNode *LOGICAL();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *MINUTE();
    antlr4::tree::TerminalNode *MONTH();
    antlr4::tree::TerminalNode *NFC();
    antlr4::tree::TerminalNode *NFD();
    antlr4::tree::TerminalNode *NFKC();
    antlr4::tree::TerminalNode *NFKD();
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *NULLIF();
    antlr4::tree::TerminalNode *NULLS();
    antlr4::tree::TerminalNode *ONLY();
    antlr4::tree::TerminalNode *OPTION();
    antlr4::tree::TerminalNode *ORDINALITY();
    antlr4::tree::TerminalNode *OUTPUT();
    antlr4::tree::TerminalNode *OVER();
    antlr4::tree::TerminalNode *PARTITION();
    antlr4::tree::TerminalNode *PARTITIONS();
    antlr4::tree::TerminalNode *PATH();
    antlr4::tree::TerminalNode *POSITION();
    antlr4::tree::TerminalNode *PRECEDING();
    antlr4::tree::TerminalNode *PRIVILEGES();
    antlr4::tree::TerminalNode *PROPERTIES();
    antlr4::tree::TerminalNode *PUBLIC();
    antlr4::tree::TerminalNode *RANGE();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *REPEATABLE();
    antlr4::tree::TerminalNode *REPLACE();
    antlr4::tree::TerminalNode *RESET();
    antlr4::tree::TerminalNode *RESTRICT();
    antlr4::tree::TerminalNode *REVOKE();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ROW();
    antlr4::tree::TerminalNode *ROWS();
    antlr4::tree::TerminalNode *SCHEMA();
    antlr4::tree::TerminalNode *SCHEMAS();
    antlr4::tree::TerminalNode *SECOND();
    antlr4::tree::TerminalNode *SERIALIZABLE();
    antlr4::tree::TerminalNode *SESSION();
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *SETS();
    antlr4::tree::TerminalNode *SHOW();
    antlr4::tree::TerminalNode *SOME();
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *STATS();
    antlr4::tree::TerminalNode *SUBSTRING();
    antlr4::tree::TerminalNode *SYSTEM();
    antlr4::tree::TerminalNode *TABLES();
    antlr4::tree::TerminalNode *TABLESAMPLE();
    antlr4::tree::TerminalNode *TEXT();
    antlr4::tree::TerminalNode *TIME();
    antlr4::tree::TerminalNode *TIMESTAMP();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *TRY_CAST();
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *UNBOUNDED();
    antlr4::tree::TerminalNode *UNCOMMITTED();
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *VALIDATE();
    antlr4::tree::TerminalNode *VERBOSE();
    antlr4::tree::TerminalNode *VIEW();
    antlr4::tree::TerminalNode *WORK();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *YEAR();
    antlr4::tree::TerminalNode *ZONE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NonReservedContext* nonReserved();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool queryTermSempred(QueryTermContext *_localctx, size_t predicateIndex);
  bool relationSempred(RelationContext *_localctx, size_t predicateIndex);
  bool booleanExpressionSempred(BooleanExpressionContext *_localctx, size_t predicateIndex);
  bool valueExpressionSempred(ValueExpressionContext *_localctx, size_t predicateIndex);
  bool primaryExpressionSempred(PrimaryExpressionContext *_localctx, size_t predicateIndex);
  bool typeSempred(TypeContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace centurion
