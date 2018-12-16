
// Generated from C:/Users/vasko/source/repos/presto/presto-parser/src/main/antlr4/com/facebook/presto/sql/parser\CentSql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "CentSqlParser.h"


namespace centurion {

/**
 * This interface defines an abstract listener for a parse tree produced by CentSqlParser.
 */
class  CentSqlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSingleStatement(CentSqlParser::SingleStatementContext *ctx) = 0;
  virtual void exitSingleStatement(CentSqlParser::SingleStatementContext *ctx) = 0;

  virtual void enterStandaloneExpression(CentSqlParser::StandaloneExpressionContext *ctx) = 0;
  virtual void exitStandaloneExpression(CentSqlParser::StandaloneExpressionContext *ctx) = 0;

  virtual void enterStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext *ctx) = 0;
  virtual void exitStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext *ctx) = 0;

  virtual void enterStatementDefault(CentSqlParser::StatementDefaultContext *ctx) = 0;
  virtual void exitStatementDefault(CentSqlParser::StatementDefaultContext *ctx) = 0;

  virtual void enterUse(CentSqlParser::UseContext *ctx) = 0;
  virtual void exitUse(CentSqlParser::UseContext *ctx) = 0;

  virtual void enterCreateSchema(CentSqlParser::CreateSchemaContext *ctx) = 0;
  virtual void exitCreateSchema(CentSqlParser::CreateSchemaContext *ctx) = 0;

  virtual void enterDropSchema(CentSqlParser::DropSchemaContext *ctx) = 0;
  virtual void exitDropSchema(CentSqlParser::DropSchemaContext *ctx) = 0;

  virtual void enterRenameSchema(CentSqlParser::RenameSchemaContext *ctx) = 0;
  virtual void exitRenameSchema(CentSqlParser::RenameSchemaContext *ctx) = 0;

  virtual void enterCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext *ctx) = 0;
  virtual void exitCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext *ctx) = 0;

  virtual void enterCreateTable(CentSqlParser::CreateTableContext *ctx) = 0;
  virtual void exitCreateTable(CentSqlParser::CreateTableContext *ctx) = 0;

  virtual void enterDropTable(CentSqlParser::DropTableContext *ctx) = 0;
  virtual void exitDropTable(CentSqlParser::DropTableContext *ctx) = 0;

  virtual void enterInsertInto(CentSqlParser::InsertIntoContext *ctx) = 0;
  virtual void exitInsertInto(CentSqlParser::InsertIntoContext *ctx) = 0;

  virtual void enterDelete(CentSqlParser::DeleteContext *ctx) = 0;
  virtual void exitDelete(CentSqlParser::DeleteContext *ctx) = 0;

  virtual void enterRenameTable(CentSqlParser::RenameTableContext *ctx) = 0;
  virtual void exitRenameTable(CentSqlParser::RenameTableContext *ctx) = 0;

  virtual void enterRenameColumn(CentSqlParser::RenameColumnContext *ctx) = 0;
  virtual void exitRenameColumn(CentSqlParser::RenameColumnContext *ctx) = 0;

  virtual void enterDropColumn(CentSqlParser::DropColumnContext *ctx) = 0;
  virtual void exitDropColumn(CentSqlParser::DropColumnContext *ctx) = 0;

  virtual void enterAddColumn(CentSqlParser::AddColumnContext *ctx) = 0;
  virtual void exitAddColumn(CentSqlParser::AddColumnContext *ctx) = 0;

  virtual void enterCreateView(CentSqlParser::CreateViewContext *ctx) = 0;
  virtual void exitCreateView(CentSqlParser::CreateViewContext *ctx) = 0;

  virtual void enterDropView(CentSqlParser::DropViewContext *ctx) = 0;
  virtual void exitDropView(CentSqlParser::DropViewContext *ctx) = 0;

  virtual void enterCall(CentSqlParser::CallContext *ctx) = 0;
  virtual void exitCall(CentSqlParser::CallContext *ctx) = 0;

  virtual void enterGrant(CentSqlParser::GrantContext *ctx) = 0;
  virtual void exitGrant(CentSqlParser::GrantContext *ctx) = 0;

  virtual void enterRevoke(CentSqlParser::RevokeContext *ctx) = 0;
  virtual void exitRevoke(CentSqlParser::RevokeContext *ctx) = 0;

  virtual void enterShowGrants(CentSqlParser::ShowGrantsContext *ctx) = 0;
  virtual void exitShowGrants(CentSqlParser::ShowGrantsContext *ctx) = 0;

  virtual void enterExplain(CentSqlParser::ExplainContext *ctx) = 0;
  virtual void exitExplain(CentSqlParser::ExplainContext *ctx) = 0;

  virtual void enterShowCreateTable(CentSqlParser::ShowCreateTableContext *ctx) = 0;
  virtual void exitShowCreateTable(CentSqlParser::ShowCreateTableContext *ctx) = 0;

  virtual void enterShowCreateView(CentSqlParser::ShowCreateViewContext *ctx) = 0;
  virtual void exitShowCreateView(CentSqlParser::ShowCreateViewContext *ctx) = 0;

  virtual void enterShowTables(CentSqlParser::ShowTablesContext *ctx) = 0;
  virtual void exitShowTables(CentSqlParser::ShowTablesContext *ctx) = 0;

  virtual void enterShowSchemas(CentSqlParser::ShowSchemasContext *ctx) = 0;
  virtual void exitShowSchemas(CentSqlParser::ShowSchemasContext *ctx) = 0;

  virtual void enterShowCatalogs(CentSqlParser::ShowCatalogsContext *ctx) = 0;
  virtual void exitShowCatalogs(CentSqlParser::ShowCatalogsContext *ctx) = 0;

  virtual void enterShowColumns(CentSqlParser::ShowColumnsContext *ctx) = 0;
  virtual void exitShowColumns(CentSqlParser::ShowColumnsContext *ctx) = 0;

  virtual void enterShowStats(CentSqlParser::ShowStatsContext *ctx) = 0;
  virtual void exitShowStats(CentSqlParser::ShowStatsContext *ctx) = 0;

  virtual void enterShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext *ctx) = 0;
  virtual void exitShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext *ctx) = 0;

  virtual void enterShowFunctions(CentSqlParser::ShowFunctionsContext *ctx) = 0;
  virtual void exitShowFunctions(CentSqlParser::ShowFunctionsContext *ctx) = 0;

  virtual void enterShowSession(CentSqlParser::ShowSessionContext *ctx) = 0;
  virtual void exitShowSession(CentSqlParser::ShowSessionContext *ctx) = 0;

  virtual void enterSetSession(CentSqlParser::SetSessionContext *ctx) = 0;
  virtual void exitSetSession(CentSqlParser::SetSessionContext *ctx) = 0;

  virtual void enterResetSession(CentSqlParser::ResetSessionContext *ctx) = 0;
  virtual void exitResetSession(CentSqlParser::ResetSessionContext *ctx) = 0;

  virtual void enterStartTransaction(CentSqlParser::StartTransactionContext *ctx) = 0;
  virtual void exitStartTransaction(CentSqlParser::StartTransactionContext *ctx) = 0;

  virtual void enterCommit(CentSqlParser::CommitContext *ctx) = 0;
  virtual void exitCommit(CentSqlParser::CommitContext *ctx) = 0;

  virtual void enterRollback(CentSqlParser::RollbackContext *ctx) = 0;
  virtual void exitRollback(CentSqlParser::RollbackContext *ctx) = 0;

  virtual void enterPrepare(CentSqlParser::PrepareContext *ctx) = 0;
  virtual void exitPrepare(CentSqlParser::PrepareContext *ctx) = 0;

  virtual void enterDeallocate(CentSqlParser::DeallocateContext *ctx) = 0;
  virtual void exitDeallocate(CentSqlParser::DeallocateContext *ctx) = 0;

  virtual void enterExecute(CentSqlParser::ExecuteContext *ctx) = 0;
  virtual void exitExecute(CentSqlParser::ExecuteContext *ctx) = 0;

  virtual void enterDescribeInput(CentSqlParser::DescribeInputContext *ctx) = 0;
  virtual void exitDescribeInput(CentSqlParser::DescribeInputContext *ctx) = 0;

  virtual void enterDescribeOutput(CentSqlParser::DescribeOutputContext *ctx) = 0;
  virtual void exitDescribeOutput(CentSqlParser::DescribeOutputContext *ctx) = 0;

  virtual void enterSetPath(CentSqlParser::SetPathContext *ctx) = 0;
  virtual void exitSetPath(CentSqlParser::SetPathContext *ctx) = 0;

  virtual void enterQuery(CentSqlParser::QueryContext *ctx) = 0;
  virtual void exitQuery(CentSqlParser::QueryContext *ctx) = 0;

  virtual void enterWith(CentSqlParser::WithContext *ctx) = 0;
  virtual void exitWith(CentSqlParser::WithContext *ctx) = 0;

  virtual void enterTableElement(CentSqlParser::TableElementContext *ctx) = 0;
  virtual void exitTableElement(CentSqlParser::TableElementContext *ctx) = 0;

  virtual void enterColumnDefinition(CentSqlParser::ColumnDefinitionContext *ctx) = 0;
  virtual void exitColumnDefinition(CentSqlParser::ColumnDefinitionContext *ctx) = 0;

  virtual void enterLikeClause(CentSqlParser::LikeClauseContext *ctx) = 0;
  virtual void exitLikeClause(CentSqlParser::LikeClauseContext *ctx) = 0;

  virtual void enterProperties(CentSqlParser::PropertiesContext *ctx) = 0;
  virtual void exitProperties(CentSqlParser::PropertiesContext *ctx) = 0;

  virtual void enterProperty(CentSqlParser::PropertyContext *ctx) = 0;
  virtual void exitProperty(CentSqlParser::PropertyContext *ctx) = 0;

  virtual void enterQueryNoWith(CentSqlParser::QueryNoWithContext *ctx) = 0;
  virtual void exitQueryNoWith(CentSqlParser::QueryNoWithContext *ctx) = 0;

  virtual void enterQueryTermDefault(CentSqlParser::QueryTermDefaultContext *ctx) = 0;
  virtual void exitQueryTermDefault(CentSqlParser::QueryTermDefaultContext *ctx) = 0;

  virtual void enterSetOperation(CentSqlParser::SetOperationContext *ctx) = 0;
  virtual void exitSetOperation(CentSqlParser::SetOperationContext *ctx) = 0;

  virtual void enterQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext *ctx) = 0;
  virtual void exitQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext *ctx) = 0;

  virtual void enterTable(CentSqlParser::TableContext *ctx) = 0;
  virtual void exitTable(CentSqlParser::TableContext *ctx) = 0;

  virtual void enterInlineTable(CentSqlParser::InlineTableContext *ctx) = 0;
  virtual void exitInlineTable(CentSqlParser::InlineTableContext *ctx) = 0;

  virtual void enterSubquery(CentSqlParser::SubqueryContext *ctx) = 0;
  virtual void exitSubquery(CentSqlParser::SubqueryContext *ctx) = 0;

  virtual void enterSortItem(CentSqlParser::SortItemContext *ctx) = 0;
  virtual void exitSortItem(CentSqlParser::SortItemContext *ctx) = 0;

  virtual void enterQuerySpecification(CentSqlParser::QuerySpecificationContext *ctx) = 0;
  virtual void exitQuerySpecification(CentSqlParser::QuerySpecificationContext *ctx) = 0;

  virtual void enterGroupBy(CentSqlParser::GroupByContext *ctx) = 0;
  virtual void exitGroupBy(CentSqlParser::GroupByContext *ctx) = 0;

  virtual void enterSingleGroupingSet(CentSqlParser::SingleGroupingSetContext *ctx) = 0;
  virtual void exitSingleGroupingSet(CentSqlParser::SingleGroupingSetContext *ctx) = 0;

  virtual void enterRollup(CentSqlParser::RollupContext *ctx) = 0;
  virtual void exitRollup(CentSqlParser::RollupContext *ctx) = 0;

  virtual void enterCube(CentSqlParser::CubeContext *ctx) = 0;
  virtual void exitCube(CentSqlParser::CubeContext *ctx) = 0;

  virtual void enterMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext *ctx) = 0;
  virtual void exitMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext *ctx) = 0;

  virtual void enterGroupingSet(CentSqlParser::GroupingSetContext *ctx) = 0;
  virtual void exitGroupingSet(CentSqlParser::GroupingSetContext *ctx) = 0;

  virtual void enterNamedQuery(CentSqlParser::NamedQueryContext *ctx) = 0;
  virtual void exitNamedQuery(CentSqlParser::NamedQueryContext *ctx) = 0;

  virtual void enterSetQuantifier(CentSqlParser::SetQuantifierContext *ctx) = 0;
  virtual void exitSetQuantifier(CentSqlParser::SetQuantifierContext *ctx) = 0;

  virtual void enterSelectSingle(CentSqlParser::SelectSingleContext *ctx) = 0;
  virtual void exitSelectSingle(CentSqlParser::SelectSingleContext *ctx) = 0;

  virtual void enterSelectAll(CentSqlParser::SelectAllContext *ctx) = 0;
  virtual void exitSelectAll(CentSqlParser::SelectAllContext *ctx) = 0;

  virtual void enterRelationDefault(CentSqlParser::RelationDefaultContext *ctx) = 0;
  virtual void exitRelationDefault(CentSqlParser::RelationDefaultContext *ctx) = 0;

  virtual void enterJoinRelation(CentSqlParser::JoinRelationContext *ctx) = 0;
  virtual void exitJoinRelation(CentSqlParser::JoinRelationContext *ctx) = 0;

  virtual void enterJoinType(CentSqlParser::JoinTypeContext *ctx) = 0;
  virtual void exitJoinType(CentSqlParser::JoinTypeContext *ctx) = 0;

  virtual void enterJoinCriteria(CentSqlParser::JoinCriteriaContext *ctx) = 0;
  virtual void exitJoinCriteria(CentSqlParser::JoinCriteriaContext *ctx) = 0;

  virtual void enterSampledRelation(CentSqlParser::SampledRelationContext *ctx) = 0;
  virtual void exitSampledRelation(CentSqlParser::SampledRelationContext *ctx) = 0;

  virtual void enterSampleType(CentSqlParser::SampleTypeContext *ctx) = 0;
  virtual void exitSampleType(CentSqlParser::SampleTypeContext *ctx) = 0;

  virtual void enterAliasedRelation(CentSqlParser::AliasedRelationContext *ctx) = 0;
  virtual void exitAliasedRelation(CentSqlParser::AliasedRelationContext *ctx) = 0;

  virtual void enterColumnAliases(CentSqlParser::ColumnAliasesContext *ctx) = 0;
  virtual void exitColumnAliases(CentSqlParser::ColumnAliasesContext *ctx) = 0;

  virtual void enterTableName(CentSqlParser::TableNameContext *ctx) = 0;
  virtual void exitTableName(CentSqlParser::TableNameContext *ctx) = 0;

  virtual void enterSubqueryRelation(CentSqlParser::SubqueryRelationContext *ctx) = 0;
  virtual void exitSubqueryRelation(CentSqlParser::SubqueryRelationContext *ctx) = 0;

  virtual void enterUnnest(CentSqlParser::UnnestContext *ctx) = 0;
  virtual void exitUnnest(CentSqlParser::UnnestContext *ctx) = 0;

  virtual void enterLateral(CentSqlParser::LateralContext *ctx) = 0;
  virtual void exitLateral(CentSqlParser::LateralContext *ctx) = 0;

  virtual void enterParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext *ctx) = 0;
  virtual void exitParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext *ctx) = 0;

  virtual void enterExpression(CentSqlParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(CentSqlParser::ExpressionContext *ctx) = 0;

  virtual void enterLogicalNot(CentSqlParser::LogicalNotContext *ctx) = 0;
  virtual void exitLogicalNot(CentSqlParser::LogicalNotContext *ctx) = 0;

  virtual void enterPredicated(CentSqlParser::PredicatedContext *ctx) = 0;
  virtual void exitPredicated(CentSqlParser::PredicatedContext *ctx) = 0;

  virtual void enterLogicalBinary(CentSqlParser::LogicalBinaryContext *ctx) = 0;
  virtual void exitLogicalBinary(CentSqlParser::LogicalBinaryContext *ctx) = 0;

  virtual void enterComparison(CentSqlParser::ComparisonContext *ctx) = 0;
  virtual void exitComparison(CentSqlParser::ComparisonContext *ctx) = 0;

  virtual void enterQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext *ctx) = 0;
  virtual void exitQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext *ctx) = 0;

  virtual void enterBetween(CentSqlParser::BetweenContext *ctx) = 0;
  virtual void exitBetween(CentSqlParser::BetweenContext *ctx) = 0;

  virtual void enterInList(CentSqlParser::InListContext *ctx) = 0;
  virtual void exitInList(CentSqlParser::InListContext *ctx) = 0;

  virtual void enterInSubquery(CentSqlParser::InSubqueryContext *ctx) = 0;
  virtual void exitInSubquery(CentSqlParser::InSubqueryContext *ctx) = 0;

  virtual void enterLike(CentSqlParser::LikeContext *ctx) = 0;
  virtual void exitLike(CentSqlParser::LikeContext *ctx) = 0;

  virtual void enterNullPredicate(CentSqlParser::NullPredicateContext *ctx) = 0;
  virtual void exitNullPredicate(CentSqlParser::NullPredicateContext *ctx) = 0;

  virtual void enterDistinctFrom(CentSqlParser::DistinctFromContext *ctx) = 0;
  virtual void exitDistinctFrom(CentSqlParser::DistinctFromContext *ctx) = 0;

  virtual void enterValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext *ctx) = 0;
  virtual void exitValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext *ctx) = 0;

  virtual void enterConcatenation(CentSqlParser::ConcatenationContext *ctx) = 0;
  virtual void exitConcatenation(CentSqlParser::ConcatenationContext *ctx) = 0;

  virtual void enterArithmeticBinary(CentSqlParser::ArithmeticBinaryContext *ctx) = 0;
  virtual void exitArithmeticBinary(CentSqlParser::ArithmeticBinaryContext *ctx) = 0;

  virtual void enterArithmeticUnary(CentSqlParser::ArithmeticUnaryContext *ctx) = 0;
  virtual void exitArithmeticUnary(CentSqlParser::ArithmeticUnaryContext *ctx) = 0;

  virtual void enterAtTimeZone(CentSqlParser::AtTimeZoneContext *ctx) = 0;
  virtual void exitAtTimeZone(CentSqlParser::AtTimeZoneContext *ctx) = 0;

  virtual void enterDereference(CentSqlParser::DereferenceContext *ctx) = 0;
  virtual void exitDereference(CentSqlParser::DereferenceContext *ctx) = 0;

  virtual void enterTypeConstructor(CentSqlParser::TypeConstructorContext *ctx) = 0;
  virtual void exitTypeConstructor(CentSqlParser::TypeConstructorContext *ctx) = 0;

  virtual void enterSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext *ctx) = 0;
  virtual void exitSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext *ctx) = 0;

  virtual void enterSubstring(CentSqlParser::SubstringContext *ctx) = 0;
  virtual void exitSubstring(CentSqlParser::SubstringContext *ctx) = 0;

  virtual void enterCast(CentSqlParser::CastContext *ctx) = 0;
  virtual void exitCast(CentSqlParser::CastContext *ctx) = 0;

  virtual void enterLambda(CentSqlParser::LambdaContext *ctx) = 0;
  virtual void exitLambda(CentSqlParser::LambdaContext *ctx) = 0;

  virtual void enterParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext *ctx) = 0;
  virtual void exitParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext *ctx) = 0;

  virtual void enterParameter(CentSqlParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(CentSqlParser::ParameterContext *ctx) = 0;

  virtual void enterNormalize(CentSqlParser::NormalizeContext *ctx) = 0;
  virtual void exitNormalize(CentSqlParser::NormalizeContext *ctx) = 0;

  virtual void enterIntervalLiteral(CentSqlParser::IntervalLiteralContext *ctx) = 0;
  virtual void exitIntervalLiteral(CentSqlParser::IntervalLiteralContext *ctx) = 0;

  virtual void enterNumericLiteral(CentSqlParser::NumericLiteralContext *ctx) = 0;
  virtual void exitNumericLiteral(CentSqlParser::NumericLiteralContext *ctx) = 0;

  virtual void enterBooleanLiteral(CentSqlParser::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(CentSqlParser::BooleanLiteralContext *ctx) = 0;

  virtual void enterSimpleCase(CentSqlParser::SimpleCaseContext *ctx) = 0;
  virtual void exitSimpleCase(CentSqlParser::SimpleCaseContext *ctx) = 0;

  virtual void enterColumnReference(CentSqlParser::ColumnReferenceContext *ctx) = 0;
  virtual void exitColumnReference(CentSqlParser::ColumnReferenceContext *ctx) = 0;

  virtual void enterNullLiteral(CentSqlParser::NullLiteralContext *ctx) = 0;
  virtual void exitNullLiteral(CentSqlParser::NullLiteralContext *ctx) = 0;

  virtual void enterRowConstructor(CentSqlParser::RowConstructorContext *ctx) = 0;
  virtual void exitRowConstructor(CentSqlParser::RowConstructorContext *ctx) = 0;

  virtual void enterSubscript(CentSqlParser::SubscriptContext *ctx) = 0;
  virtual void exitSubscript(CentSqlParser::SubscriptContext *ctx) = 0;

  virtual void enterCurrentPath(CentSqlParser::CurrentPathContext *ctx) = 0;
  virtual void exitCurrentPath(CentSqlParser::CurrentPathContext *ctx) = 0;

  virtual void enterSubqueryExpression(CentSqlParser::SubqueryExpressionContext *ctx) = 0;
  virtual void exitSubqueryExpression(CentSqlParser::SubqueryExpressionContext *ctx) = 0;

  virtual void enterBinaryLiteral(CentSqlParser::BinaryLiteralContext *ctx) = 0;
  virtual void exitBinaryLiteral(CentSqlParser::BinaryLiteralContext *ctx) = 0;

  virtual void enterCurrentUser(CentSqlParser::CurrentUserContext *ctx) = 0;
  virtual void exitCurrentUser(CentSqlParser::CurrentUserContext *ctx) = 0;

  virtual void enterExtract(CentSqlParser::ExtractContext *ctx) = 0;
  virtual void exitExtract(CentSqlParser::ExtractContext *ctx) = 0;

  virtual void enterStringLiteral(CentSqlParser::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(CentSqlParser::StringLiteralContext *ctx) = 0;

  virtual void enterArrayConstructor(CentSqlParser::ArrayConstructorContext *ctx) = 0;
  virtual void exitArrayConstructor(CentSqlParser::ArrayConstructorContext *ctx) = 0;

  virtual void enterFunctionCall(CentSqlParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(CentSqlParser::FunctionCallContext *ctx) = 0;

  virtual void enterExists(CentSqlParser::ExistsContext *ctx) = 0;
  virtual void exitExists(CentSqlParser::ExistsContext *ctx) = 0;

  virtual void enterPosition(CentSqlParser::PositionContext *ctx) = 0;
  virtual void exitPosition(CentSqlParser::PositionContext *ctx) = 0;

  virtual void enterSearchedCase(CentSqlParser::SearchedCaseContext *ctx) = 0;
  virtual void exitSearchedCase(CentSqlParser::SearchedCaseContext *ctx) = 0;

  virtual void enterGroupingOperation(CentSqlParser::GroupingOperationContext *ctx) = 0;
  virtual void exitGroupingOperation(CentSqlParser::GroupingOperationContext *ctx) = 0;

  virtual void enterBasicStringLiteral(CentSqlParser::BasicStringLiteralContext *ctx) = 0;
  virtual void exitBasicStringLiteral(CentSqlParser::BasicStringLiteralContext *ctx) = 0;

  virtual void enterUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext *ctx) = 0;
  virtual void exitUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext *ctx) = 0;

  virtual void enterTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext *ctx) = 0;
  virtual void exitTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext *ctx) = 0;

  virtual void enterTimeZoneString(CentSqlParser::TimeZoneStringContext *ctx) = 0;
  virtual void exitTimeZoneString(CentSqlParser::TimeZoneStringContext *ctx) = 0;

  virtual void enterComparisonOperator(CentSqlParser::ComparisonOperatorContext *ctx) = 0;
  virtual void exitComparisonOperator(CentSqlParser::ComparisonOperatorContext *ctx) = 0;

  virtual void enterComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext *ctx) = 0;
  virtual void exitComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext *ctx) = 0;

  virtual void enterBooleanValue(CentSqlParser::BooleanValueContext *ctx) = 0;
  virtual void exitBooleanValue(CentSqlParser::BooleanValueContext *ctx) = 0;

  virtual void enterInterval(CentSqlParser::IntervalContext *ctx) = 0;
  virtual void exitInterval(CentSqlParser::IntervalContext *ctx) = 0;

  virtual void enterIntervalField(CentSqlParser::IntervalFieldContext *ctx) = 0;
  virtual void exitIntervalField(CentSqlParser::IntervalFieldContext *ctx) = 0;

  virtual void enterNormalForm(CentSqlParser::NormalFormContext *ctx) = 0;
  virtual void exitNormalForm(CentSqlParser::NormalFormContext *ctx) = 0;

  virtual void enterType(CentSqlParser::TypeContext *ctx) = 0;
  virtual void exitType(CentSqlParser::TypeContext *ctx) = 0;

  virtual void enterTypeParameter(CentSqlParser::TypeParameterContext *ctx) = 0;
  virtual void exitTypeParameter(CentSqlParser::TypeParameterContext *ctx) = 0;

  virtual void enterBaseType(CentSqlParser::BaseTypeContext *ctx) = 0;
  virtual void exitBaseType(CentSqlParser::BaseTypeContext *ctx) = 0;

  virtual void enterWhenClause(CentSqlParser::WhenClauseContext *ctx) = 0;
  virtual void exitWhenClause(CentSqlParser::WhenClauseContext *ctx) = 0;

  virtual void enterFilter(CentSqlParser::FilterContext *ctx) = 0;
  virtual void exitFilter(CentSqlParser::FilterContext *ctx) = 0;

  virtual void enterOver(CentSqlParser::OverContext *ctx) = 0;
  virtual void exitOver(CentSqlParser::OverContext *ctx) = 0;

  virtual void enterWindowFrame(CentSqlParser::WindowFrameContext *ctx) = 0;
  virtual void exitWindowFrame(CentSqlParser::WindowFrameContext *ctx) = 0;

  virtual void enterUnboundedFrame(CentSqlParser::UnboundedFrameContext *ctx) = 0;
  virtual void exitUnboundedFrame(CentSqlParser::UnboundedFrameContext *ctx) = 0;

  virtual void enterCurrentRowBound(CentSqlParser::CurrentRowBoundContext *ctx) = 0;
  virtual void exitCurrentRowBound(CentSqlParser::CurrentRowBoundContext *ctx) = 0;

  virtual void enterBoundedFrame(CentSqlParser::BoundedFrameContext *ctx) = 0;
  virtual void exitBoundedFrame(CentSqlParser::BoundedFrameContext *ctx) = 0;

  virtual void enterExplainFormat(CentSqlParser::ExplainFormatContext *ctx) = 0;
  virtual void exitExplainFormat(CentSqlParser::ExplainFormatContext *ctx) = 0;

  virtual void enterExplainType(CentSqlParser::ExplainTypeContext *ctx) = 0;
  virtual void exitExplainType(CentSqlParser::ExplainTypeContext *ctx) = 0;

  virtual void enterIsolationLevel(CentSqlParser::IsolationLevelContext *ctx) = 0;
  virtual void exitIsolationLevel(CentSqlParser::IsolationLevelContext *ctx) = 0;

  virtual void enterTransactionAccessMode(CentSqlParser::TransactionAccessModeContext *ctx) = 0;
  virtual void exitTransactionAccessMode(CentSqlParser::TransactionAccessModeContext *ctx) = 0;

  virtual void enterReadUncommitted(CentSqlParser::ReadUncommittedContext *ctx) = 0;
  virtual void exitReadUncommitted(CentSqlParser::ReadUncommittedContext *ctx) = 0;

  virtual void enterReadCommitted(CentSqlParser::ReadCommittedContext *ctx) = 0;
  virtual void exitReadCommitted(CentSqlParser::ReadCommittedContext *ctx) = 0;

  virtual void enterRepeatableRead(CentSqlParser::RepeatableReadContext *ctx) = 0;
  virtual void exitRepeatableRead(CentSqlParser::RepeatableReadContext *ctx) = 0;

  virtual void enterSerializable(CentSqlParser::SerializableContext *ctx) = 0;
  virtual void exitSerializable(CentSqlParser::SerializableContext *ctx) = 0;

  virtual void enterPositionalArgument(CentSqlParser::PositionalArgumentContext *ctx) = 0;
  virtual void exitPositionalArgument(CentSqlParser::PositionalArgumentContext *ctx) = 0;

  virtual void enterNamedArgument(CentSqlParser::NamedArgumentContext *ctx) = 0;
  virtual void exitNamedArgument(CentSqlParser::NamedArgumentContext *ctx) = 0;

  virtual void enterQualifiedArgument(CentSqlParser::QualifiedArgumentContext *ctx) = 0;
  virtual void exitQualifiedArgument(CentSqlParser::QualifiedArgumentContext *ctx) = 0;

  virtual void enterUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext *ctx) = 0;
  virtual void exitUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext *ctx) = 0;

  virtual void enterPathSpecification(CentSqlParser::PathSpecificationContext *ctx) = 0;
  virtual void exitPathSpecification(CentSqlParser::PathSpecificationContext *ctx) = 0;

  virtual void enterPrivilege(CentSqlParser::PrivilegeContext *ctx) = 0;
  virtual void exitPrivilege(CentSqlParser::PrivilegeContext *ctx) = 0;

  virtual void enterQualifiedName(CentSqlParser::QualifiedNameContext *ctx) = 0;
  virtual void exitQualifiedName(CentSqlParser::QualifiedNameContext *ctx) = 0;

  virtual void enterUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext *ctx) = 0;
  virtual void exitUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext *ctx) = 0;

  virtual void enterQuotedIdentifier(CentSqlParser::QuotedIdentifierContext *ctx) = 0;
  virtual void exitQuotedIdentifier(CentSqlParser::QuotedIdentifierContext *ctx) = 0;

  virtual void enterBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext *ctx) = 0;
  virtual void exitBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext *ctx) = 0;

  virtual void enterDigitIdentifier(CentSqlParser::DigitIdentifierContext *ctx) = 0;
  virtual void exitDigitIdentifier(CentSqlParser::DigitIdentifierContext *ctx) = 0;

  virtual void enterDecimalLiteral(CentSqlParser::DecimalLiteralContext *ctx) = 0;
  virtual void exitDecimalLiteral(CentSqlParser::DecimalLiteralContext *ctx) = 0;

  virtual void enterDoubleLiteral(CentSqlParser::DoubleLiteralContext *ctx) = 0;
  virtual void exitDoubleLiteral(CentSqlParser::DoubleLiteralContext *ctx) = 0;

  virtual void enterIntegerLiteral(CentSqlParser::IntegerLiteralContext *ctx) = 0;
  virtual void exitIntegerLiteral(CentSqlParser::IntegerLiteralContext *ctx) = 0;

  virtual void enterNonReserved(CentSqlParser::NonReservedContext *ctx) = 0;
  virtual void exitNonReserved(CentSqlParser::NonReservedContext *ctx) = 0;


};

}  // namespace centurion
