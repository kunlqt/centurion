
// Generated from C:/Users/vasko/source/repos/presto/presto-parser/src/main/antlr4/com/facebook/presto/sql/parser\CentSql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "CentSqlParser.h"


namespace centurion {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by CentSqlParser.
 */
class  CentSqlVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CentSqlParser.
   */
    virtual antlrcpp::Any visitSingleStatement(CentSqlParser::SingleStatementContext *context) = 0;

    virtual antlrcpp::Any visitStandaloneExpression(CentSqlParser::StandaloneExpressionContext *context) = 0;

    virtual antlrcpp::Any visitStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext *context) = 0;

    virtual antlrcpp::Any visitStatementDefault(CentSqlParser::StatementDefaultContext *context) = 0;

    virtual antlrcpp::Any visitUse(CentSqlParser::UseContext *context) = 0;

    virtual antlrcpp::Any visitCreateSchema(CentSqlParser::CreateSchemaContext *context) = 0;

    virtual antlrcpp::Any visitDropSchema(CentSqlParser::DropSchemaContext *context) = 0;

    virtual antlrcpp::Any visitRenameSchema(CentSqlParser::RenameSchemaContext *context) = 0;

    virtual antlrcpp::Any visitCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext *context) = 0;

    virtual antlrcpp::Any visitCreateTable(CentSqlParser::CreateTableContext *context) = 0;

    virtual antlrcpp::Any visitDropTable(CentSqlParser::DropTableContext *context) = 0;

    virtual antlrcpp::Any visitInsertInto(CentSqlParser::InsertIntoContext *context) = 0;

    virtual antlrcpp::Any visitDelete(CentSqlParser::DeleteContext *context) = 0;

    virtual antlrcpp::Any visitRenameTable(CentSqlParser::RenameTableContext *context) = 0;

    virtual antlrcpp::Any visitRenameColumn(CentSqlParser::RenameColumnContext *context) = 0;

    virtual antlrcpp::Any visitDropColumn(CentSqlParser::DropColumnContext *context) = 0;

    virtual antlrcpp::Any visitAddColumn(CentSqlParser::AddColumnContext *context) = 0;

    virtual antlrcpp::Any visitCreateView(CentSqlParser::CreateViewContext *context) = 0;

    virtual antlrcpp::Any visitDropView(CentSqlParser::DropViewContext *context) = 0;

    virtual antlrcpp::Any visitCall(CentSqlParser::CallContext *context) = 0;

    virtual antlrcpp::Any visitGrant(CentSqlParser::GrantContext *context) = 0;

    virtual antlrcpp::Any visitRevoke(CentSqlParser::RevokeContext *context) = 0;

    virtual antlrcpp::Any visitShowGrants(CentSqlParser::ShowGrantsContext *context) = 0;

    virtual antlrcpp::Any visitExplain(CentSqlParser::ExplainContext *context) = 0;

    virtual antlrcpp::Any visitShowCreateTable(CentSqlParser::ShowCreateTableContext *context) = 0;

    virtual antlrcpp::Any visitShowCreateView(CentSqlParser::ShowCreateViewContext *context) = 0;

    virtual antlrcpp::Any visitShowTables(CentSqlParser::ShowTablesContext *context) = 0;

    virtual antlrcpp::Any visitShowSchemas(CentSqlParser::ShowSchemasContext *context) = 0;

    virtual antlrcpp::Any visitShowCatalogs(CentSqlParser::ShowCatalogsContext *context) = 0;

    virtual antlrcpp::Any visitShowColumns(CentSqlParser::ShowColumnsContext *context) = 0;

    virtual antlrcpp::Any visitShowStats(CentSqlParser::ShowStatsContext *context) = 0;

    virtual antlrcpp::Any visitShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext *context) = 0;

    virtual antlrcpp::Any visitShowFunctions(CentSqlParser::ShowFunctionsContext *context) = 0;

    virtual antlrcpp::Any visitShowSession(CentSqlParser::ShowSessionContext *context) = 0;

    virtual antlrcpp::Any visitSetSession(CentSqlParser::SetSessionContext *context) = 0;

    virtual antlrcpp::Any visitResetSession(CentSqlParser::ResetSessionContext *context) = 0;

    virtual antlrcpp::Any visitStartTransaction(CentSqlParser::StartTransactionContext *context) = 0;

    virtual antlrcpp::Any visitCommit(CentSqlParser::CommitContext *context) = 0;

    virtual antlrcpp::Any visitRollback(CentSqlParser::RollbackContext *context) = 0;

    virtual antlrcpp::Any visitPrepare(CentSqlParser::PrepareContext *context) = 0;

    virtual antlrcpp::Any visitDeallocate(CentSqlParser::DeallocateContext *context) = 0;

    virtual antlrcpp::Any visitExecute(CentSqlParser::ExecuteContext *context) = 0;

    virtual antlrcpp::Any visitDescribeInput(CentSqlParser::DescribeInputContext *context) = 0;

    virtual antlrcpp::Any visitDescribeOutput(CentSqlParser::DescribeOutputContext *context) = 0;

    virtual antlrcpp::Any visitSetPath(CentSqlParser::SetPathContext *context) = 0;

    virtual antlrcpp::Any visitQuery(CentSqlParser::QueryContext *context) = 0;

    virtual antlrcpp::Any visitWith(CentSqlParser::WithContext *context) = 0;

    virtual antlrcpp::Any visitTableElement(CentSqlParser::TableElementContext *context) = 0;

    virtual antlrcpp::Any visitColumnDefinition(CentSqlParser::ColumnDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitLikeClause(CentSqlParser::LikeClauseContext *context) = 0;

    virtual antlrcpp::Any visitProperties(CentSqlParser::PropertiesContext *context) = 0;

    virtual antlrcpp::Any visitProperty(CentSqlParser::PropertyContext *context) = 0;

    virtual antlrcpp::Any visitQueryNoWith(CentSqlParser::QueryNoWithContext *context) = 0;

    virtual antlrcpp::Any visitQueryTermDefault(CentSqlParser::QueryTermDefaultContext *context) = 0;

    virtual antlrcpp::Any visitSetOperation(CentSqlParser::SetOperationContext *context) = 0;

    virtual antlrcpp::Any visitQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext *context) = 0;

    virtual antlrcpp::Any visitTable(CentSqlParser::TableContext *context) = 0;

    virtual antlrcpp::Any visitInlineTable(CentSqlParser::InlineTableContext *context) = 0;

    virtual antlrcpp::Any visitSubquery(CentSqlParser::SubqueryContext *context) = 0;

    virtual antlrcpp::Any visitSortItem(CentSqlParser::SortItemContext *context) = 0;

    virtual antlrcpp::Any visitQuerySpecification(CentSqlParser::QuerySpecificationContext *context) = 0;

    virtual antlrcpp::Any visitGroupBy(CentSqlParser::GroupByContext *context) = 0;

    virtual antlrcpp::Any visitSingleGroupingSet(CentSqlParser::SingleGroupingSetContext *context) = 0;

    virtual antlrcpp::Any visitRollup(CentSqlParser::RollupContext *context) = 0;

    virtual antlrcpp::Any visitCube(CentSqlParser::CubeContext *context) = 0;

    virtual antlrcpp::Any visitMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext *context) = 0;

    virtual antlrcpp::Any visitGroupingSet(CentSqlParser::GroupingSetContext *context) = 0;

    virtual antlrcpp::Any visitNamedQuery(CentSqlParser::NamedQueryContext *context) = 0;

    virtual antlrcpp::Any visitSetQuantifier(CentSqlParser::SetQuantifierContext *context) = 0;

    virtual antlrcpp::Any visitSelectSingle(CentSqlParser::SelectSingleContext *context) = 0;

    virtual antlrcpp::Any visitSelectAll(CentSqlParser::SelectAllContext *context) = 0;

    virtual antlrcpp::Any visitRelationDefault(CentSqlParser::RelationDefaultContext *context) = 0;

    virtual antlrcpp::Any visitJoinRelation(CentSqlParser::JoinRelationContext *context) = 0;

    virtual antlrcpp::Any visitJoinType(CentSqlParser::JoinTypeContext *context) = 0;

    virtual antlrcpp::Any visitJoinCriteria(CentSqlParser::JoinCriteriaContext *context) = 0;

    virtual antlrcpp::Any visitSampledRelation(CentSqlParser::SampledRelationContext *context) = 0;

    virtual antlrcpp::Any visitSampleType(CentSqlParser::SampleTypeContext *context) = 0;

    virtual antlrcpp::Any visitAliasedRelation(CentSqlParser::AliasedRelationContext *context) = 0;

    virtual antlrcpp::Any visitColumnAliases(CentSqlParser::ColumnAliasesContext *context) = 0;

    virtual antlrcpp::Any visitTableName(CentSqlParser::TableNameContext *context) = 0;

    virtual antlrcpp::Any visitSubqueryRelation(CentSqlParser::SubqueryRelationContext *context) = 0;

    virtual antlrcpp::Any visitUnnest(CentSqlParser::UnnestContext *context) = 0;

    virtual antlrcpp::Any visitLateral(CentSqlParser::LateralContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext *context) = 0;

    virtual antlrcpp::Any visitExpression(CentSqlParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalNot(CentSqlParser::LogicalNotContext *context) = 0;

    virtual antlrcpp::Any visitPredicated(CentSqlParser::PredicatedContext *context) = 0;

    virtual antlrcpp::Any visitLogicalBinary(CentSqlParser::LogicalBinaryContext *context) = 0;

    virtual antlrcpp::Any visitComparison(CentSqlParser::ComparisonContext *context) = 0;

    virtual antlrcpp::Any visitQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext *context) = 0;

    virtual antlrcpp::Any visitBetween(CentSqlParser::BetweenContext *context) = 0;

    virtual antlrcpp::Any visitInList(CentSqlParser::InListContext *context) = 0;

    virtual antlrcpp::Any visitInSubquery(CentSqlParser::InSubqueryContext *context) = 0;

    virtual antlrcpp::Any visitLike(CentSqlParser::LikeContext *context) = 0;

    virtual antlrcpp::Any visitNullPredicate(CentSqlParser::NullPredicateContext *context) = 0;

    virtual antlrcpp::Any visitDistinctFrom(CentSqlParser::DistinctFromContext *context) = 0;

    virtual antlrcpp::Any visitValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext *context) = 0;

    virtual antlrcpp::Any visitConcatenation(CentSqlParser::ConcatenationContext *context) = 0;

    virtual antlrcpp::Any visitArithmeticBinary(CentSqlParser::ArithmeticBinaryContext *context) = 0;

    virtual antlrcpp::Any visitArithmeticUnary(CentSqlParser::ArithmeticUnaryContext *context) = 0;

    virtual antlrcpp::Any visitAtTimeZone(CentSqlParser::AtTimeZoneContext *context) = 0;

    virtual antlrcpp::Any visitDereference(CentSqlParser::DereferenceContext *context) = 0;

    virtual antlrcpp::Any visitTypeConstructor(CentSqlParser::TypeConstructorContext *context) = 0;

    virtual antlrcpp::Any visitSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext *context) = 0;

    virtual antlrcpp::Any visitSubstring(CentSqlParser::SubstringContext *context) = 0;

    virtual antlrcpp::Any visitCast(CentSqlParser::CastContext *context) = 0;

    virtual antlrcpp::Any visitLambda(CentSqlParser::LambdaContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext *context) = 0;

    virtual antlrcpp::Any visitParameter(CentSqlParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitNormalize(CentSqlParser::NormalizeContext *context) = 0;

    virtual antlrcpp::Any visitIntervalLiteral(CentSqlParser::IntervalLiteralContext *context) = 0;

    virtual antlrcpp::Any visitNumericLiteral(CentSqlParser::NumericLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBooleanLiteral(CentSqlParser::BooleanLiteralContext *context) = 0;

    virtual antlrcpp::Any visitSimpleCase(CentSqlParser::SimpleCaseContext *context) = 0;

    virtual antlrcpp::Any visitColumnReference(CentSqlParser::ColumnReferenceContext *context) = 0;

    virtual antlrcpp::Any visitNullLiteral(CentSqlParser::NullLiteralContext *context) = 0;

    virtual antlrcpp::Any visitRowConstructor(CentSqlParser::RowConstructorContext *context) = 0;

    virtual antlrcpp::Any visitSubscript(CentSqlParser::SubscriptContext *context) = 0;

    virtual antlrcpp::Any visitCurrentPath(CentSqlParser::CurrentPathContext *context) = 0;

    virtual antlrcpp::Any visitSubqueryExpression(CentSqlParser::SubqueryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBinaryLiteral(CentSqlParser::BinaryLiteralContext *context) = 0;

    virtual antlrcpp::Any visitCurrentUser(CentSqlParser::CurrentUserContext *context) = 0;

    virtual antlrcpp::Any visitExtract(CentSqlParser::ExtractContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteral(CentSqlParser::StringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitArrayConstructor(CentSqlParser::ArrayConstructorContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(CentSqlParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitExists(CentSqlParser::ExistsContext *context) = 0;

    virtual antlrcpp::Any visitPosition(CentSqlParser::PositionContext *context) = 0;

    virtual antlrcpp::Any visitSearchedCase(CentSqlParser::SearchedCaseContext *context) = 0;

    virtual antlrcpp::Any visitGroupingOperation(CentSqlParser::GroupingOperationContext *context) = 0;

    virtual antlrcpp::Any visitBasicStringLiteral(CentSqlParser::BasicStringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext *context) = 0;

    virtual antlrcpp::Any visitTimeZoneString(CentSqlParser::TimeZoneStringContext *context) = 0;

    virtual antlrcpp::Any visitComparisonOperator(CentSqlParser::ComparisonOperatorContext *context) = 0;

    virtual antlrcpp::Any visitComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext *context) = 0;

    virtual antlrcpp::Any visitBooleanValue(CentSqlParser::BooleanValueContext *context) = 0;

    virtual antlrcpp::Any visitInterval(CentSqlParser::IntervalContext *context) = 0;

    virtual antlrcpp::Any visitIntervalField(CentSqlParser::IntervalFieldContext *context) = 0;

    virtual antlrcpp::Any visitNormalForm(CentSqlParser::NormalFormContext *context) = 0;

    virtual antlrcpp::Any visitType(CentSqlParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitTypeParameter(CentSqlParser::TypeParameterContext *context) = 0;

    virtual antlrcpp::Any visitBaseType(CentSqlParser::BaseTypeContext *context) = 0;

    virtual antlrcpp::Any visitWhenClause(CentSqlParser::WhenClauseContext *context) = 0;

    virtual antlrcpp::Any visitFilter(CentSqlParser::FilterContext *context) = 0;

    virtual antlrcpp::Any visitOver(CentSqlParser::OverContext *context) = 0;

    virtual antlrcpp::Any visitWindowFrame(CentSqlParser::WindowFrameContext *context) = 0;

    virtual antlrcpp::Any visitUnboundedFrame(CentSqlParser::UnboundedFrameContext *context) = 0;

    virtual antlrcpp::Any visitCurrentRowBound(CentSqlParser::CurrentRowBoundContext *context) = 0;

    virtual antlrcpp::Any visitBoundedFrame(CentSqlParser::BoundedFrameContext *context) = 0;

    virtual antlrcpp::Any visitExplainFormat(CentSqlParser::ExplainFormatContext *context) = 0;

    virtual antlrcpp::Any visitExplainType(CentSqlParser::ExplainTypeContext *context) = 0;

    virtual antlrcpp::Any visitIsolationLevel(CentSqlParser::IsolationLevelContext *context) = 0;

    virtual antlrcpp::Any visitTransactionAccessMode(CentSqlParser::TransactionAccessModeContext *context) = 0;

    virtual antlrcpp::Any visitReadUncommitted(CentSqlParser::ReadUncommittedContext *context) = 0;

    virtual antlrcpp::Any visitReadCommitted(CentSqlParser::ReadCommittedContext *context) = 0;

    virtual antlrcpp::Any visitRepeatableRead(CentSqlParser::RepeatableReadContext *context) = 0;

    virtual antlrcpp::Any visitSerializable(CentSqlParser::SerializableContext *context) = 0;

    virtual antlrcpp::Any visitPositionalArgument(CentSqlParser::PositionalArgumentContext *context) = 0;

    virtual antlrcpp::Any visitNamedArgument(CentSqlParser::NamedArgumentContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedArgument(CentSqlParser::QualifiedArgumentContext *context) = 0;

    virtual antlrcpp::Any visitUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext *context) = 0;

    virtual antlrcpp::Any visitPathSpecification(CentSqlParser::PathSpecificationContext *context) = 0;

    virtual antlrcpp::Any visitPrivilege(CentSqlParser::PrivilegeContext *context) = 0;

    virtual antlrcpp::Any visitQualifiedName(CentSqlParser::QualifiedNameContext *context) = 0;

    virtual antlrcpp::Any visitUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitQuotedIdentifier(CentSqlParser::QuotedIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitDigitIdentifier(CentSqlParser::DigitIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitDecimalLiteral(CentSqlParser::DecimalLiteralContext *context) = 0;

    virtual antlrcpp::Any visitDoubleLiteral(CentSqlParser::DoubleLiteralContext *context) = 0;

    virtual antlrcpp::Any visitIntegerLiteral(CentSqlParser::IntegerLiteralContext *context) = 0;

    virtual antlrcpp::Any visitNonReserved(CentSqlParser::NonReservedContext *context) = 0;


};

}  // namespace centurion
