
// Generated from C:/Users/vasko/source/repos/presto/presto-parser/src/main/antlr4/com/facebook/presto/sql/parser\CentSql.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "CentSqlListener.h"


namespace centurion {

/**
 * This class provides an empty implementation of CentSqlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CentSqlBaseListener : public CentSqlListener {
public:

  virtual void enterSingleStatement(CentSqlParser::SingleStatementContext * /*ctx*/) override { }
  virtual void exitSingleStatement(CentSqlParser::SingleStatementContext * /*ctx*/) override { }

  virtual void enterStandaloneExpression(CentSqlParser::StandaloneExpressionContext * /*ctx*/) override { }
  virtual void exitStandaloneExpression(CentSqlParser::StandaloneExpressionContext * /*ctx*/) override { }

  virtual void enterStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext * /*ctx*/) override { }
  virtual void exitStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext * /*ctx*/) override { }

  virtual void enterStatementDefault(CentSqlParser::StatementDefaultContext * /*ctx*/) override { }
  virtual void exitStatementDefault(CentSqlParser::StatementDefaultContext * /*ctx*/) override { }

  virtual void enterUse(CentSqlParser::UseContext * /*ctx*/) override { }
  virtual void exitUse(CentSqlParser::UseContext * /*ctx*/) override { }

  virtual void enterCreateSchema(CentSqlParser::CreateSchemaContext * /*ctx*/) override { }
  virtual void exitCreateSchema(CentSqlParser::CreateSchemaContext * /*ctx*/) override { }

  virtual void enterDropSchema(CentSqlParser::DropSchemaContext * /*ctx*/) override { }
  virtual void exitDropSchema(CentSqlParser::DropSchemaContext * /*ctx*/) override { }

  virtual void enterRenameSchema(CentSqlParser::RenameSchemaContext * /*ctx*/) override { }
  virtual void exitRenameSchema(CentSqlParser::RenameSchemaContext * /*ctx*/) override { }

  virtual void enterCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext * /*ctx*/) override { }
  virtual void exitCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext * /*ctx*/) override { }

  virtual void enterCreateTable(CentSqlParser::CreateTableContext * /*ctx*/) override { }
  virtual void exitCreateTable(CentSqlParser::CreateTableContext * /*ctx*/) override { }

  virtual void enterDropTable(CentSqlParser::DropTableContext * /*ctx*/) override { }
  virtual void exitDropTable(CentSqlParser::DropTableContext * /*ctx*/) override { }

  virtual void enterInsertInto(CentSqlParser::InsertIntoContext * /*ctx*/) override { }
  virtual void exitInsertInto(CentSqlParser::InsertIntoContext * /*ctx*/) override { }

  virtual void enterDelete(CentSqlParser::DeleteContext * /*ctx*/) override { }
  virtual void exitDelete(CentSqlParser::DeleteContext * /*ctx*/) override { }

  virtual void enterRenameTable(CentSqlParser::RenameTableContext * /*ctx*/) override { }
  virtual void exitRenameTable(CentSqlParser::RenameTableContext * /*ctx*/) override { }

  virtual void enterRenameColumn(CentSqlParser::RenameColumnContext * /*ctx*/) override { }
  virtual void exitRenameColumn(CentSqlParser::RenameColumnContext * /*ctx*/) override { }

  virtual void enterDropColumn(CentSqlParser::DropColumnContext * /*ctx*/) override { }
  virtual void exitDropColumn(CentSqlParser::DropColumnContext * /*ctx*/) override { }

  virtual void enterAddColumn(CentSqlParser::AddColumnContext * /*ctx*/) override { }
  virtual void exitAddColumn(CentSqlParser::AddColumnContext * /*ctx*/) override { }

  virtual void enterCreateView(CentSqlParser::CreateViewContext * /*ctx*/) override { }
  virtual void exitCreateView(CentSqlParser::CreateViewContext * /*ctx*/) override { }

  virtual void enterDropView(CentSqlParser::DropViewContext * /*ctx*/) override { }
  virtual void exitDropView(CentSqlParser::DropViewContext * /*ctx*/) override { }

  virtual void enterCall(CentSqlParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(CentSqlParser::CallContext * /*ctx*/) override { }

  virtual void enterGrant(CentSqlParser::GrantContext * /*ctx*/) override { }
  virtual void exitGrant(CentSqlParser::GrantContext * /*ctx*/) override { }

  virtual void enterRevoke(CentSqlParser::RevokeContext * /*ctx*/) override { }
  virtual void exitRevoke(CentSqlParser::RevokeContext * /*ctx*/) override { }

  virtual void enterShowGrants(CentSqlParser::ShowGrantsContext * /*ctx*/) override { }
  virtual void exitShowGrants(CentSqlParser::ShowGrantsContext * /*ctx*/) override { }

  virtual void enterExplain(CentSqlParser::ExplainContext * /*ctx*/) override { }
  virtual void exitExplain(CentSqlParser::ExplainContext * /*ctx*/) override { }

  virtual void enterShowCreateTable(CentSqlParser::ShowCreateTableContext * /*ctx*/) override { }
  virtual void exitShowCreateTable(CentSqlParser::ShowCreateTableContext * /*ctx*/) override { }

  virtual void enterShowCreateView(CentSqlParser::ShowCreateViewContext * /*ctx*/) override { }
  virtual void exitShowCreateView(CentSqlParser::ShowCreateViewContext * /*ctx*/) override { }

  virtual void enterShowTables(CentSqlParser::ShowTablesContext * /*ctx*/) override { }
  virtual void exitShowTables(CentSqlParser::ShowTablesContext * /*ctx*/) override { }

  virtual void enterShowSchemas(CentSqlParser::ShowSchemasContext * /*ctx*/) override { }
  virtual void exitShowSchemas(CentSqlParser::ShowSchemasContext * /*ctx*/) override { }

  virtual void enterShowCatalogs(CentSqlParser::ShowCatalogsContext * /*ctx*/) override { }
  virtual void exitShowCatalogs(CentSqlParser::ShowCatalogsContext * /*ctx*/) override { }

  virtual void enterShowColumns(CentSqlParser::ShowColumnsContext * /*ctx*/) override { }
  virtual void exitShowColumns(CentSqlParser::ShowColumnsContext * /*ctx*/) override { }

  virtual void enterShowStats(CentSqlParser::ShowStatsContext * /*ctx*/) override { }
  virtual void exitShowStats(CentSqlParser::ShowStatsContext * /*ctx*/) override { }

  virtual void enterShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext * /*ctx*/) override { }
  virtual void exitShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext * /*ctx*/) override { }

  virtual void enterShowFunctions(CentSqlParser::ShowFunctionsContext * /*ctx*/) override { }
  virtual void exitShowFunctions(CentSqlParser::ShowFunctionsContext * /*ctx*/) override { }

  virtual void enterShowSession(CentSqlParser::ShowSessionContext * /*ctx*/) override { }
  virtual void exitShowSession(CentSqlParser::ShowSessionContext * /*ctx*/) override { }

  virtual void enterSetSession(CentSqlParser::SetSessionContext * /*ctx*/) override { }
  virtual void exitSetSession(CentSqlParser::SetSessionContext * /*ctx*/) override { }

  virtual void enterResetSession(CentSqlParser::ResetSessionContext * /*ctx*/) override { }
  virtual void exitResetSession(CentSqlParser::ResetSessionContext * /*ctx*/) override { }

  virtual void enterStartTransaction(CentSqlParser::StartTransactionContext * /*ctx*/) override { }
  virtual void exitStartTransaction(CentSqlParser::StartTransactionContext * /*ctx*/) override { }

  virtual void enterCommit(CentSqlParser::CommitContext * /*ctx*/) override { }
  virtual void exitCommit(CentSqlParser::CommitContext * /*ctx*/) override { }

  virtual void enterRollback(CentSqlParser::RollbackContext * /*ctx*/) override { }
  virtual void exitRollback(CentSqlParser::RollbackContext * /*ctx*/) override { }

  virtual void enterPrepare(CentSqlParser::PrepareContext * /*ctx*/) override { }
  virtual void exitPrepare(CentSqlParser::PrepareContext * /*ctx*/) override { }

  virtual void enterDeallocate(CentSqlParser::DeallocateContext * /*ctx*/) override { }
  virtual void exitDeallocate(CentSqlParser::DeallocateContext * /*ctx*/) override { }

  virtual void enterExecute(CentSqlParser::ExecuteContext * /*ctx*/) override { }
  virtual void exitExecute(CentSqlParser::ExecuteContext * /*ctx*/) override { }

  virtual void enterDescribeInput(CentSqlParser::DescribeInputContext * /*ctx*/) override { }
  virtual void exitDescribeInput(CentSqlParser::DescribeInputContext * /*ctx*/) override { }

  virtual void enterDescribeOutput(CentSqlParser::DescribeOutputContext * /*ctx*/) override { }
  virtual void exitDescribeOutput(CentSqlParser::DescribeOutputContext * /*ctx*/) override { }

  virtual void enterSetPath(CentSqlParser::SetPathContext * /*ctx*/) override { }
  virtual void exitSetPath(CentSqlParser::SetPathContext * /*ctx*/) override { }

  virtual void enterQuery(CentSqlParser::QueryContext * /*ctx*/) override { }
  virtual void exitQuery(CentSqlParser::QueryContext * /*ctx*/) override { }

  virtual void enterWith(CentSqlParser::WithContext * /*ctx*/) override { }
  virtual void exitWith(CentSqlParser::WithContext * /*ctx*/) override { }

  virtual void enterTableElement(CentSqlParser::TableElementContext * /*ctx*/) override { }
  virtual void exitTableElement(CentSqlParser::TableElementContext * /*ctx*/) override { }

  virtual void enterColumnDefinition(CentSqlParser::ColumnDefinitionContext * /*ctx*/) override { }
  virtual void exitColumnDefinition(CentSqlParser::ColumnDefinitionContext * /*ctx*/) override { }

  virtual void enterLikeClause(CentSqlParser::LikeClauseContext * /*ctx*/) override { }
  virtual void exitLikeClause(CentSqlParser::LikeClauseContext * /*ctx*/) override { }

  virtual void enterProperties(CentSqlParser::PropertiesContext * /*ctx*/) override { }
  virtual void exitProperties(CentSqlParser::PropertiesContext * /*ctx*/) override { }

  virtual void enterProperty(CentSqlParser::PropertyContext * /*ctx*/) override { }
  virtual void exitProperty(CentSqlParser::PropertyContext * /*ctx*/) override { }

  virtual void enterQueryNoWith(CentSqlParser::QueryNoWithContext * /*ctx*/) override { }
  virtual void exitQueryNoWith(CentSqlParser::QueryNoWithContext * /*ctx*/) override { }

  virtual void enterQueryTermDefault(CentSqlParser::QueryTermDefaultContext * /*ctx*/) override { }
  virtual void exitQueryTermDefault(CentSqlParser::QueryTermDefaultContext * /*ctx*/) override { }

  virtual void enterSetOperation(CentSqlParser::SetOperationContext * /*ctx*/) override { }
  virtual void exitSetOperation(CentSqlParser::SetOperationContext * /*ctx*/) override { }

  virtual void enterQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext * /*ctx*/) override { }
  virtual void exitQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext * /*ctx*/) override { }

  virtual void enterTable(CentSqlParser::TableContext * /*ctx*/) override { }
  virtual void exitTable(CentSqlParser::TableContext * /*ctx*/) override { }

  virtual void enterInlineTable(CentSqlParser::InlineTableContext * /*ctx*/) override { }
  virtual void exitInlineTable(CentSqlParser::InlineTableContext * /*ctx*/) override { }

  virtual void enterSubquery(CentSqlParser::SubqueryContext * /*ctx*/) override { }
  virtual void exitSubquery(CentSqlParser::SubqueryContext * /*ctx*/) override { }

  virtual void enterSortItem(CentSqlParser::SortItemContext * /*ctx*/) override { }
  virtual void exitSortItem(CentSqlParser::SortItemContext * /*ctx*/) override { }

  virtual void enterQuerySpecification(CentSqlParser::QuerySpecificationContext * /*ctx*/) override { }
  virtual void exitQuerySpecification(CentSqlParser::QuerySpecificationContext * /*ctx*/) override { }

  virtual void enterGroupBy(CentSqlParser::GroupByContext * /*ctx*/) override { }
  virtual void exitGroupBy(CentSqlParser::GroupByContext * /*ctx*/) override { }

  virtual void enterSingleGroupingSet(CentSqlParser::SingleGroupingSetContext * /*ctx*/) override { }
  virtual void exitSingleGroupingSet(CentSqlParser::SingleGroupingSetContext * /*ctx*/) override { }

  virtual void enterRollup(CentSqlParser::RollupContext * /*ctx*/) override { }
  virtual void exitRollup(CentSqlParser::RollupContext * /*ctx*/) override { }

  virtual void enterCube(CentSqlParser::CubeContext * /*ctx*/) override { }
  virtual void exitCube(CentSqlParser::CubeContext * /*ctx*/) override { }

  virtual void enterMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext * /*ctx*/) override { }
  virtual void exitMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext * /*ctx*/) override { }

  virtual void enterGroupingSet(CentSqlParser::GroupingSetContext * /*ctx*/) override { }
  virtual void exitGroupingSet(CentSqlParser::GroupingSetContext * /*ctx*/) override { }

  virtual void enterNamedQuery(CentSqlParser::NamedQueryContext * /*ctx*/) override { }
  virtual void exitNamedQuery(CentSqlParser::NamedQueryContext * /*ctx*/) override { }

  virtual void enterSetQuantifier(CentSqlParser::SetQuantifierContext * /*ctx*/) override { }
  virtual void exitSetQuantifier(CentSqlParser::SetQuantifierContext * /*ctx*/) override { }

  virtual void enterSelectSingle(CentSqlParser::SelectSingleContext * /*ctx*/) override { }
  virtual void exitSelectSingle(CentSqlParser::SelectSingleContext * /*ctx*/) override { }

  virtual void enterSelectAll(CentSqlParser::SelectAllContext * /*ctx*/) override { }
  virtual void exitSelectAll(CentSqlParser::SelectAllContext * /*ctx*/) override { }

  virtual void enterRelationDefault(CentSqlParser::RelationDefaultContext * /*ctx*/) override { }
  virtual void exitRelationDefault(CentSqlParser::RelationDefaultContext * /*ctx*/) override { }

  virtual void enterJoinRelation(CentSqlParser::JoinRelationContext * /*ctx*/) override { }
  virtual void exitJoinRelation(CentSqlParser::JoinRelationContext * /*ctx*/) override { }

  virtual void enterJoinType(CentSqlParser::JoinTypeContext * /*ctx*/) override { }
  virtual void exitJoinType(CentSqlParser::JoinTypeContext * /*ctx*/) override { }

  virtual void enterJoinCriteria(CentSqlParser::JoinCriteriaContext * /*ctx*/) override { }
  virtual void exitJoinCriteria(CentSqlParser::JoinCriteriaContext * /*ctx*/) override { }

  virtual void enterSampledRelation(CentSqlParser::SampledRelationContext * /*ctx*/) override { }
  virtual void exitSampledRelation(CentSqlParser::SampledRelationContext * /*ctx*/) override { }

  virtual void enterSampleType(CentSqlParser::SampleTypeContext * /*ctx*/) override { }
  virtual void exitSampleType(CentSqlParser::SampleTypeContext * /*ctx*/) override { }

  virtual void enterAliasedRelation(CentSqlParser::AliasedRelationContext * /*ctx*/) override { }
  virtual void exitAliasedRelation(CentSqlParser::AliasedRelationContext * /*ctx*/) override { }

  virtual void enterColumnAliases(CentSqlParser::ColumnAliasesContext * /*ctx*/) override { }
  virtual void exitColumnAliases(CentSqlParser::ColumnAliasesContext * /*ctx*/) override { }

  virtual void enterTableName(CentSqlParser::TableNameContext * /*ctx*/) override { }
  virtual void exitTableName(CentSqlParser::TableNameContext * /*ctx*/) override { }

  virtual void enterSubqueryRelation(CentSqlParser::SubqueryRelationContext * /*ctx*/) override { }
  virtual void exitSubqueryRelation(CentSqlParser::SubqueryRelationContext * /*ctx*/) override { }

  virtual void enterUnnest(CentSqlParser::UnnestContext * /*ctx*/) override { }
  virtual void exitUnnest(CentSqlParser::UnnestContext * /*ctx*/) override { }

  virtual void enterLateral(CentSqlParser::LateralContext * /*ctx*/) override { }
  virtual void exitLateral(CentSqlParser::LateralContext * /*ctx*/) override { }

  virtual void enterParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext * /*ctx*/) override { }
  virtual void exitParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext * /*ctx*/) override { }

  virtual void enterExpression(CentSqlParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(CentSqlParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalNot(CentSqlParser::LogicalNotContext * /*ctx*/) override { }
  virtual void exitLogicalNot(CentSqlParser::LogicalNotContext * /*ctx*/) override { }

  virtual void enterPredicated(CentSqlParser::PredicatedContext * /*ctx*/) override { }
  virtual void exitPredicated(CentSqlParser::PredicatedContext * /*ctx*/) override { }

  virtual void enterLogicalBinary(CentSqlParser::LogicalBinaryContext * /*ctx*/) override { }
  virtual void exitLogicalBinary(CentSqlParser::LogicalBinaryContext * /*ctx*/) override { }

  virtual void enterComparison(CentSqlParser::ComparisonContext * /*ctx*/) override { }
  virtual void exitComparison(CentSqlParser::ComparisonContext * /*ctx*/) override { }

  virtual void enterQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext * /*ctx*/) override { }
  virtual void exitQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext * /*ctx*/) override { }

  virtual void enterBetween(CentSqlParser::BetweenContext * /*ctx*/) override { }
  virtual void exitBetween(CentSqlParser::BetweenContext * /*ctx*/) override { }

  virtual void enterInList(CentSqlParser::InListContext * /*ctx*/) override { }
  virtual void exitInList(CentSqlParser::InListContext * /*ctx*/) override { }

  virtual void enterInSubquery(CentSqlParser::InSubqueryContext * /*ctx*/) override { }
  virtual void exitInSubquery(CentSqlParser::InSubqueryContext * /*ctx*/) override { }

  virtual void enterLike(CentSqlParser::LikeContext * /*ctx*/) override { }
  virtual void exitLike(CentSqlParser::LikeContext * /*ctx*/) override { }

  virtual void enterNullPredicate(CentSqlParser::NullPredicateContext * /*ctx*/) override { }
  virtual void exitNullPredicate(CentSqlParser::NullPredicateContext * /*ctx*/) override { }

  virtual void enterDistinctFrom(CentSqlParser::DistinctFromContext * /*ctx*/) override { }
  virtual void exitDistinctFrom(CentSqlParser::DistinctFromContext * /*ctx*/) override { }

  virtual void enterValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext * /*ctx*/) override { }
  virtual void exitValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext * /*ctx*/) override { }

  virtual void enterConcatenation(CentSqlParser::ConcatenationContext * /*ctx*/) override { }
  virtual void exitConcatenation(CentSqlParser::ConcatenationContext * /*ctx*/) override { }

  virtual void enterArithmeticBinary(CentSqlParser::ArithmeticBinaryContext * /*ctx*/) override { }
  virtual void exitArithmeticBinary(CentSqlParser::ArithmeticBinaryContext * /*ctx*/) override { }

  virtual void enterArithmeticUnary(CentSqlParser::ArithmeticUnaryContext * /*ctx*/) override { }
  virtual void exitArithmeticUnary(CentSqlParser::ArithmeticUnaryContext * /*ctx*/) override { }

  virtual void enterAtTimeZone(CentSqlParser::AtTimeZoneContext * /*ctx*/) override { }
  virtual void exitAtTimeZone(CentSqlParser::AtTimeZoneContext * /*ctx*/) override { }

  virtual void enterDereference(CentSqlParser::DereferenceContext * /*ctx*/) override { }
  virtual void exitDereference(CentSqlParser::DereferenceContext * /*ctx*/) override { }

  virtual void enterTypeConstructor(CentSqlParser::TypeConstructorContext * /*ctx*/) override { }
  virtual void exitTypeConstructor(CentSqlParser::TypeConstructorContext * /*ctx*/) override { }

  virtual void enterSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext * /*ctx*/) override { }
  virtual void exitSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext * /*ctx*/) override { }

  virtual void enterSubstring(CentSqlParser::SubstringContext * /*ctx*/) override { }
  virtual void exitSubstring(CentSqlParser::SubstringContext * /*ctx*/) override { }

  virtual void enterCast(CentSqlParser::CastContext * /*ctx*/) override { }
  virtual void exitCast(CentSqlParser::CastContext * /*ctx*/) override { }

  virtual void enterLambda(CentSqlParser::LambdaContext * /*ctx*/) override { }
  virtual void exitLambda(CentSqlParser::LambdaContext * /*ctx*/) override { }

  virtual void enterParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext * /*ctx*/) override { }
  virtual void exitParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext * /*ctx*/) override { }

  virtual void enterParameter(CentSqlParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(CentSqlParser::ParameterContext * /*ctx*/) override { }

  virtual void enterNormalize(CentSqlParser::NormalizeContext * /*ctx*/) override { }
  virtual void exitNormalize(CentSqlParser::NormalizeContext * /*ctx*/) override { }

  virtual void enterIntervalLiteral(CentSqlParser::IntervalLiteralContext * /*ctx*/) override { }
  virtual void exitIntervalLiteral(CentSqlParser::IntervalLiteralContext * /*ctx*/) override { }

  virtual void enterNumericLiteral(CentSqlParser::NumericLiteralContext * /*ctx*/) override { }
  virtual void exitNumericLiteral(CentSqlParser::NumericLiteralContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(CentSqlParser::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(CentSqlParser::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterSimpleCase(CentSqlParser::SimpleCaseContext * /*ctx*/) override { }
  virtual void exitSimpleCase(CentSqlParser::SimpleCaseContext * /*ctx*/) override { }

  virtual void enterColumnReference(CentSqlParser::ColumnReferenceContext * /*ctx*/) override { }
  virtual void exitColumnReference(CentSqlParser::ColumnReferenceContext * /*ctx*/) override { }

  virtual void enterNullLiteral(CentSqlParser::NullLiteralContext * /*ctx*/) override { }
  virtual void exitNullLiteral(CentSqlParser::NullLiteralContext * /*ctx*/) override { }

  virtual void enterRowConstructor(CentSqlParser::RowConstructorContext * /*ctx*/) override { }
  virtual void exitRowConstructor(CentSqlParser::RowConstructorContext * /*ctx*/) override { }

  virtual void enterSubscript(CentSqlParser::SubscriptContext * /*ctx*/) override { }
  virtual void exitSubscript(CentSqlParser::SubscriptContext * /*ctx*/) override { }

  virtual void enterCurrentPath(CentSqlParser::CurrentPathContext * /*ctx*/) override { }
  virtual void exitCurrentPath(CentSqlParser::CurrentPathContext * /*ctx*/) override { }

  virtual void enterSubqueryExpression(CentSqlParser::SubqueryExpressionContext * /*ctx*/) override { }
  virtual void exitSubqueryExpression(CentSqlParser::SubqueryExpressionContext * /*ctx*/) override { }

  virtual void enterBinaryLiteral(CentSqlParser::BinaryLiteralContext * /*ctx*/) override { }
  virtual void exitBinaryLiteral(CentSqlParser::BinaryLiteralContext * /*ctx*/) override { }

  virtual void enterCurrentUser(CentSqlParser::CurrentUserContext * /*ctx*/) override { }
  virtual void exitCurrentUser(CentSqlParser::CurrentUserContext * /*ctx*/) override { }

  virtual void enterExtract(CentSqlParser::ExtractContext * /*ctx*/) override { }
  virtual void exitExtract(CentSqlParser::ExtractContext * /*ctx*/) override { }

  virtual void enterStringLiteral(CentSqlParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(CentSqlParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterArrayConstructor(CentSqlParser::ArrayConstructorContext * /*ctx*/) override { }
  virtual void exitArrayConstructor(CentSqlParser::ArrayConstructorContext * /*ctx*/) override { }

  virtual void enterFunctionCall(CentSqlParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(CentSqlParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterExists(CentSqlParser::ExistsContext * /*ctx*/) override { }
  virtual void exitExists(CentSqlParser::ExistsContext * /*ctx*/) override { }

  virtual void enterPosition(CentSqlParser::PositionContext * /*ctx*/) override { }
  virtual void exitPosition(CentSqlParser::PositionContext * /*ctx*/) override { }

  virtual void enterSearchedCase(CentSqlParser::SearchedCaseContext * /*ctx*/) override { }
  virtual void exitSearchedCase(CentSqlParser::SearchedCaseContext * /*ctx*/) override { }

  virtual void enterGroupingOperation(CentSqlParser::GroupingOperationContext * /*ctx*/) override { }
  virtual void exitGroupingOperation(CentSqlParser::GroupingOperationContext * /*ctx*/) override { }

  virtual void enterBasicStringLiteral(CentSqlParser::BasicStringLiteralContext * /*ctx*/) override { }
  virtual void exitBasicStringLiteral(CentSqlParser::BasicStringLiteralContext * /*ctx*/) override { }

  virtual void enterUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext * /*ctx*/) override { }
  virtual void exitUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext * /*ctx*/) override { }

  virtual void enterTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext * /*ctx*/) override { }
  virtual void exitTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext * /*ctx*/) override { }

  virtual void enterTimeZoneString(CentSqlParser::TimeZoneStringContext * /*ctx*/) override { }
  virtual void exitTimeZoneString(CentSqlParser::TimeZoneStringContext * /*ctx*/) override { }

  virtual void enterComparisonOperator(CentSqlParser::ComparisonOperatorContext * /*ctx*/) override { }
  virtual void exitComparisonOperator(CentSqlParser::ComparisonOperatorContext * /*ctx*/) override { }

  virtual void enterComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext * /*ctx*/) override { }
  virtual void exitComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext * /*ctx*/) override { }

  virtual void enterBooleanValue(CentSqlParser::BooleanValueContext * /*ctx*/) override { }
  virtual void exitBooleanValue(CentSqlParser::BooleanValueContext * /*ctx*/) override { }

  virtual void enterInterval(CentSqlParser::IntervalContext * /*ctx*/) override { }
  virtual void exitInterval(CentSqlParser::IntervalContext * /*ctx*/) override { }

  virtual void enterIntervalField(CentSqlParser::IntervalFieldContext * /*ctx*/) override { }
  virtual void exitIntervalField(CentSqlParser::IntervalFieldContext * /*ctx*/) override { }

  virtual void enterNormalForm(CentSqlParser::NormalFormContext * /*ctx*/) override { }
  virtual void exitNormalForm(CentSqlParser::NormalFormContext * /*ctx*/) override { }

  virtual void enterType(CentSqlParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(CentSqlParser::TypeContext * /*ctx*/) override { }

  virtual void enterTypeParameter(CentSqlParser::TypeParameterContext * /*ctx*/) override { }
  virtual void exitTypeParameter(CentSqlParser::TypeParameterContext * /*ctx*/) override { }

  virtual void enterBaseType(CentSqlParser::BaseTypeContext * /*ctx*/) override { }
  virtual void exitBaseType(CentSqlParser::BaseTypeContext * /*ctx*/) override { }

  virtual void enterWhenClause(CentSqlParser::WhenClauseContext * /*ctx*/) override { }
  virtual void exitWhenClause(CentSqlParser::WhenClauseContext * /*ctx*/) override { }

  virtual void enterFilter(CentSqlParser::FilterContext * /*ctx*/) override { }
  virtual void exitFilter(CentSqlParser::FilterContext * /*ctx*/) override { }

  virtual void enterOver(CentSqlParser::OverContext * /*ctx*/) override { }
  virtual void exitOver(CentSqlParser::OverContext * /*ctx*/) override { }

  virtual void enterWindowFrame(CentSqlParser::WindowFrameContext * /*ctx*/) override { }
  virtual void exitWindowFrame(CentSqlParser::WindowFrameContext * /*ctx*/) override { }

  virtual void enterUnboundedFrame(CentSqlParser::UnboundedFrameContext * /*ctx*/) override { }
  virtual void exitUnboundedFrame(CentSqlParser::UnboundedFrameContext * /*ctx*/) override { }

  virtual void enterCurrentRowBound(CentSqlParser::CurrentRowBoundContext * /*ctx*/) override { }
  virtual void exitCurrentRowBound(CentSqlParser::CurrentRowBoundContext * /*ctx*/) override { }

  virtual void enterBoundedFrame(CentSqlParser::BoundedFrameContext * /*ctx*/) override { }
  virtual void exitBoundedFrame(CentSqlParser::BoundedFrameContext * /*ctx*/) override { }

  virtual void enterExplainFormat(CentSqlParser::ExplainFormatContext * /*ctx*/) override { }
  virtual void exitExplainFormat(CentSqlParser::ExplainFormatContext * /*ctx*/) override { }

  virtual void enterExplainType(CentSqlParser::ExplainTypeContext * /*ctx*/) override { }
  virtual void exitExplainType(CentSqlParser::ExplainTypeContext * /*ctx*/) override { }

  virtual void enterIsolationLevel(CentSqlParser::IsolationLevelContext * /*ctx*/) override { }
  virtual void exitIsolationLevel(CentSqlParser::IsolationLevelContext * /*ctx*/) override { }

  virtual void enterTransactionAccessMode(CentSqlParser::TransactionAccessModeContext * /*ctx*/) override { }
  virtual void exitTransactionAccessMode(CentSqlParser::TransactionAccessModeContext * /*ctx*/) override { }

  virtual void enterReadUncommitted(CentSqlParser::ReadUncommittedContext * /*ctx*/) override { }
  virtual void exitReadUncommitted(CentSqlParser::ReadUncommittedContext * /*ctx*/) override { }

  virtual void enterReadCommitted(CentSqlParser::ReadCommittedContext * /*ctx*/) override { }
  virtual void exitReadCommitted(CentSqlParser::ReadCommittedContext * /*ctx*/) override { }

  virtual void enterRepeatableRead(CentSqlParser::RepeatableReadContext * /*ctx*/) override { }
  virtual void exitRepeatableRead(CentSqlParser::RepeatableReadContext * /*ctx*/) override { }

  virtual void enterSerializable(CentSqlParser::SerializableContext * /*ctx*/) override { }
  virtual void exitSerializable(CentSqlParser::SerializableContext * /*ctx*/) override { }

  virtual void enterPositionalArgument(CentSqlParser::PositionalArgumentContext * /*ctx*/) override { }
  virtual void exitPositionalArgument(CentSqlParser::PositionalArgumentContext * /*ctx*/) override { }

  virtual void enterNamedArgument(CentSqlParser::NamedArgumentContext * /*ctx*/) override { }
  virtual void exitNamedArgument(CentSqlParser::NamedArgumentContext * /*ctx*/) override { }

  virtual void enterQualifiedArgument(CentSqlParser::QualifiedArgumentContext * /*ctx*/) override { }
  virtual void exitQualifiedArgument(CentSqlParser::QualifiedArgumentContext * /*ctx*/) override { }

  virtual void enterUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext * /*ctx*/) override { }
  virtual void exitUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext * /*ctx*/) override { }

  virtual void enterPathSpecification(CentSqlParser::PathSpecificationContext * /*ctx*/) override { }
  virtual void exitPathSpecification(CentSqlParser::PathSpecificationContext * /*ctx*/) override { }

  virtual void enterPrivilege(CentSqlParser::PrivilegeContext * /*ctx*/) override { }
  virtual void exitPrivilege(CentSqlParser::PrivilegeContext * /*ctx*/) override { }

  virtual void enterQualifiedName(CentSqlParser::QualifiedNameContext * /*ctx*/) override { }
  virtual void exitQualifiedName(CentSqlParser::QualifiedNameContext * /*ctx*/) override { }

  virtual void enterUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext * /*ctx*/) override { }
  virtual void exitUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext * /*ctx*/) override { }

  virtual void enterQuotedIdentifier(CentSqlParser::QuotedIdentifierContext * /*ctx*/) override { }
  virtual void exitQuotedIdentifier(CentSqlParser::QuotedIdentifierContext * /*ctx*/) override { }

  virtual void enterBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext * /*ctx*/) override { }
  virtual void exitBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext * /*ctx*/) override { }

  virtual void enterDigitIdentifier(CentSqlParser::DigitIdentifierContext * /*ctx*/) override { }
  virtual void exitDigitIdentifier(CentSqlParser::DigitIdentifierContext * /*ctx*/) override { }

  virtual void enterDecimalLiteral(CentSqlParser::DecimalLiteralContext * /*ctx*/) override { }
  virtual void exitDecimalLiteral(CentSqlParser::DecimalLiteralContext * /*ctx*/) override { }

  virtual void enterDoubleLiteral(CentSqlParser::DoubleLiteralContext * /*ctx*/) override { }
  virtual void exitDoubleLiteral(CentSqlParser::DoubleLiteralContext * /*ctx*/) override { }

  virtual void enterIntegerLiteral(CentSqlParser::IntegerLiteralContext * /*ctx*/) override { }
  virtual void exitIntegerLiteral(CentSqlParser::IntegerLiteralContext * /*ctx*/) override { }

  virtual void enterNonReserved(CentSqlParser::NonReservedContext * /*ctx*/) override { }
  virtual void exitNonReserved(CentSqlParser::NonReservedContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace centurion
