
// Generated from C:/Users/vasko/source/repos/presto/presto-parser/src/main/antlr4/com/facebook/presto/sql/parser\CentSql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "CentSqlVisitor.h"


namespace centurion {

/**
 * This class provides an empty implementation of CentSqlVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CentSqlBaseVisitor : public CentSqlVisitor {
public:

  virtual antlrcpp::Any visitSingleStatement(CentSqlParser::SingleStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStandaloneExpression(CentSqlParser::StandaloneExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementDefault(CentSqlParser::StatementDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUse(CentSqlParser::UseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateSchema(CentSqlParser::CreateSchemaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropSchema(CentSqlParser::DropSchemaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameSchema(CentSqlParser::RenameSchemaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTable(CentSqlParser::CreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropTable(CentSqlParser::DropTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsertInto(CentSqlParser::InsertIntoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelete(CentSqlParser::DeleteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameTable(CentSqlParser::RenameTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRenameColumn(CentSqlParser::RenameColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropColumn(CentSqlParser::DropColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddColumn(CentSqlParser::AddColumnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateView(CentSqlParser::CreateViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropView(CentSqlParser::DropViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(CentSqlParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGrant(CentSqlParser::GrantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRevoke(CentSqlParser::RevokeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowGrants(CentSqlParser::ShowGrantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplain(CentSqlParser::ExplainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCreateTable(CentSqlParser::ShowCreateTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCreateView(CentSqlParser::ShowCreateViewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowTables(CentSqlParser::ShowTablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSchemas(CentSqlParser::ShowSchemasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowCatalogs(CentSqlParser::ShowCatalogsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowColumns(CentSqlParser::ShowColumnsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowStats(CentSqlParser::ShowStatsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowFunctions(CentSqlParser::ShowFunctionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowSession(CentSqlParser::ShowSessionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetSession(CentSqlParser::SetSessionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResetSession(CentSqlParser::ResetSessionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStartTransaction(CentSqlParser::StartTransactionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommit(CentSqlParser::CommitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRollback(CentSqlParser::RollbackContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrepare(CentSqlParser::PrepareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeallocate(CentSqlParser::DeallocateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExecute(CentSqlParser::ExecuteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescribeInput(CentSqlParser::DescribeInputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescribeOutput(CentSqlParser::DescribeOutputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetPath(CentSqlParser::SetPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuery(CentSqlParser::QueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith(CentSqlParser::WithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableElement(CentSqlParser::TableElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnDefinition(CentSqlParser::ColumnDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLikeClause(CentSqlParser::LikeClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperties(CentSqlParser::PropertiesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty(CentSqlParser::PropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryNoWith(CentSqlParser::QueryNoWithContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryTermDefault(CentSqlParser::QueryTermDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetOperation(CentSqlParser::SetOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable(CentSqlParser::TableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInlineTable(CentSqlParser::InlineTableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubquery(CentSqlParser::SubqueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSortItem(CentSqlParser::SortItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuerySpecification(CentSqlParser::QuerySpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupBy(CentSqlParser::GroupByContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleGroupingSet(CentSqlParser::SingleGroupingSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRollup(CentSqlParser::RollupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCube(CentSqlParser::CubeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupingSet(CentSqlParser::GroupingSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedQuery(CentSqlParser::NamedQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetQuantifier(CentSqlParser::SetQuantifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectSingle(CentSqlParser::SelectSingleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectAll(CentSqlParser::SelectAllContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationDefault(CentSqlParser::RelationDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoinRelation(CentSqlParser::JoinRelationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoinType(CentSqlParser::JoinTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoinCriteria(CentSqlParser::JoinCriteriaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSampledRelation(CentSqlParser::SampledRelationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSampleType(CentSqlParser::SampleTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAliasedRelation(CentSqlParser::AliasedRelationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnAliases(CentSqlParser::ColumnAliasesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableName(CentSqlParser::TableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubqueryRelation(CentSqlParser::SubqueryRelationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnnest(CentSqlParser::UnnestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLateral(CentSqlParser::LateralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(CentSqlParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalNot(CentSqlParser::LogicalNotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPredicated(CentSqlParser::PredicatedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalBinary(CentSqlParser::LogicalBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparison(CentSqlParser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBetween(CentSqlParser::BetweenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInList(CentSqlParser::InListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInSubquery(CentSqlParser::InSubqueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLike(CentSqlParser::LikeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullPredicate(CentSqlParser::NullPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDistinctFrom(CentSqlParser::DistinctFromContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcatenation(CentSqlParser::ConcatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmeticBinary(CentSqlParser::ArithmeticBinaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArithmeticUnary(CentSqlParser::ArithmeticUnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtTimeZone(CentSqlParser::AtTimeZoneContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDereference(CentSqlParser::DereferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeConstructor(CentSqlParser::TypeConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubstring(CentSqlParser::SubstringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCast(CentSqlParser::CastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambda(CentSqlParser::LambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(CentSqlParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNormalize(CentSqlParser::NormalizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalLiteral(CentSqlParser::IntervalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumericLiteral(CentSqlParser::NumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanLiteral(CentSqlParser::BooleanLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleCase(CentSqlParser::SimpleCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnReference(CentSqlParser::ColumnReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNullLiteral(CentSqlParser::NullLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRowConstructor(CentSqlParser::RowConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubscript(CentSqlParser::SubscriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrentPath(CentSqlParser::CurrentPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubqueryExpression(CentSqlParser::SubqueryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryLiteral(CentSqlParser::BinaryLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrentUser(CentSqlParser::CurrentUserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtract(CentSqlParser::ExtractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLiteral(CentSqlParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayConstructor(CentSqlParser::ArrayConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(CentSqlParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExists(CentSqlParser::ExistsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPosition(CentSqlParser::PositionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSearchedCase(CentSqlParser::SearchedCaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupingOperation(CentSqlParser::GroupingOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasicStringLiteral(CentSqlParser::BasicStringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeZoneString(CentSqlParser::TimeZoneStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonOperator(CentSqlParser::ComparisonOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanValue(CentSqlParser::BooleanValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterval(CentSqlParser::IntervalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntervalField(CentSqlParser::IntervalFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNormalForm(CentSqlParser::NormalFormContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(CentSqlParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeParameter(CentSqlParser::TypeParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBaseType(CentSqlParser::BaseTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhenClause(CentSqlParser::WhenClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFilter(CentSqlParser::FilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOver(CentSqlParser::OverContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWindowFrame(CentSqlParser::WindowFrameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnboundedFrame(CentSqlParser::UnboundedFrameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrentRowBound(CentSqlParser::CurrentRowBoundContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoundedFrame(CentSqlParser::BoundedFrameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplainFormat(CentSqlParser::ExplainFormatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExplainType(CentSqlParser::ExplainTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsolationLevel(CentSqlParser::IsolationLevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransactionAccessMode(CentSqlParser::TransactionAccessModeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadUncommitted(CentSqlParser::ReadUncommittedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReadCommitted(CentSqlParser::ReadCommittedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeatableRead(CentSqlParser::RepeatableReadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSerializable(CentSqlParser::SerializableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPositionalArgument(CentSqlParser::PositionalArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedArgument(CentSqlParser::NamedArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualifiedArgument(CentSqlParser::QualifiedArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPathSpecification(CentSqlParser::PathSpecificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrivilege(CentSqlParser::PrivilegeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQualifiedName(CentSqlParser::QualifiedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuotedIdentifier(CentSqlParser::QuotedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDigitIdentifier(CentSqlParser::DigitIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecimalLiteral(CentSqlParser::DecimalLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoubleLiteral(CentSqlParser::DoubleLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntegerLiteral(CentSqlParser::IntegerLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonReserved(CentSqlParser::NonReservedContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace centurion
