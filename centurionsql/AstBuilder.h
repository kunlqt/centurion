//
//  AstBuilder.h
//  deleteme
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef AstBuilder_h
#define AstBuilder_h

#include "NodeLocation.h"
#include "ParsingOptions.h"
#include "QualifiedName.h"
#include "CentSqlBaseVisitor.h"
#include "CentSqlParser.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {
    class AstBuilder : public CentSqlBaseVisitor  {
        int parameterPosition_;
        ParsingOptions parsingOptions_;

		static NodeLocation getLocation(antlr4::ParserRuleContext* ctx) {
			return getLocation(ctx->getStart());
		}

		static NodeLocation getLocation(antlr4::Token* token) {
			return NodeLocation(token->getLine(), token->getCharPositionInLine());
		}

		static NodeLocation getLocation(antlr4::tree::TerminalNode* terminalNode) {
			return getLocation(terminalNode->getSymbol());
		}

		static bool isDistinct(CentSqlParser::SetQuantifierContext* setQuantifier)
		{
			if (setQuantifier == nullptr) return false;
			return setQuantifier->DISTINCT() != nullptr;
		}
				
		template<typename F, typename T>
		static std::vector<T> castVector(const std::vector<F>& from)
		{
			std::vector<T> to(from.size());
			for (size_t idx = 0; idx < from.size(); idx++) {
				F a = from[idx];
				to[idx] = (T)a;
			}
			return to;
		}
			   
		template<class T>
		std::optional<T*> visitIfPresent(antlr4::ParserRuleContext* context)
		{
			if (context != nullptr) {
				auto visitResult = CentSqlBaseVisitor::visit(context);
				if (visitResult.isNotNull()) {
					T* tmp = visitResult;
					return std::make_optional(tmp);
				}
			}
			return std::optional<T*>();
		}

		std::vector<antlrcpp::Any> visit(std::vector<antlr4::ParserRuleContext*> contexts)
		{
			std::vector<antlrcpp::Any> result;
			for (auto& contextItem : contexts) {
				result.emplace_back(CentSqlBaseVisitor::visit(contextItem));
			}
			return result;
		}

		QualifiedName getQualifiedName(CentSqlParser::QualifiedNameContext* ctx);


    public:
        AstBuilder(ParsingOptions parsingOptions);

		std::optional<std::string> getTextIfPresent(antlr4::ParserRuleContext* ctx);
		std::optional<std::string> getTextIfPresent(antlr4::Token* token);


        /**
         * Visit parse trees produced by CentSqlParser.
         */
        virtual antlrcpp::Any visitSingleStatement(CentSqlParser::SingleStatementContext *context);
        
        virtual antlrcpp::Any visitStandaloneExpression(CentSqlParser::StandaloneExpressionContext *context);
        
        virtual antlrcpp::Any visitStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext *context);
        
        virtual antlrcpp::Any visitStatementDefault(CentSqlParser::StatementDefaultContext *context);
        
        virtual antlrcpp::Any visitUse(CentSqlParser::UseContext *context);
        
        virtual antlrcpp::Any visitCreateSchema(CentSqlParser::CreateSchemaContext *context);
        
        virtual antlrcpp::Any visitDropSchema(CentSqlParser::DropSchemaContext *context);
        
        virtual antlrcpp::Any visitRenameSchema(CentSqlParser::RenameSchemaContext *context);
        
        virtual antlrcpp::Any visitCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext *context);
        
        virtual antlrcpp::Any visitCreateTable(CentSqlParser::CreateTableContext *context);
        
        virtual antlrcpp::Any visitDropTable(CentSqlParser::DropTableContext *context);
        
        virtual antlrcpp::Any visitInsertInto(CentSqlParser::InsertIntoContext *context);
        
        virtual antlrcpp::Any visitDelete(CentSqlParser::DeleteContext *context);
        
        virtual antlrcpp::Any visitRenameTable(CentSqlParser::RenameTableContext *context);
        
        virtual antlrcpp::Any visitRenameColumn(CentSqlParser::RenameColumnContext *context);
        
        virtual antlrcpp::Any visitDropColumn(CentSqlParser::DropColumnContext *context);
        
        virtual antlrcpp::Any visitAddColumn(CentSqlParser::AddColumnContext *context);
        
        virtual antlrcpp::Any visitCreateView(CentSqlParser::CreateViewContext *context);
        
        virtual antlrcpp::Any visitDropView(CentSqlParser::DropViewContext *context);
        
        virtual antlrcpp::Any visitCall(CentSqlParser::CallContext *context);
        
        virtual antlrcpp::Any visitGrant(CentSqlParser::GrantContext *context);
        
        virtual antlrcpp::Any visitRevoke(CentSqlParser::RevokeContext *context);
        
        virtual antlrcpp::Any visitShowGrants(CentSqlParser::ShowGrantsContext *context);
        
        virtual antlrcpp::Any visitExplain(CentSqlParser::ExplainContext *context);
        
        virtual antlrcpp::Any visitShowCreateTable(CentSqlParser::ShowCreateTableContext *context);
        
        virtual antlrcpp::Any visitShowCreateView(CentSqlParser::ShowCreateViewContext *context);
        
        virtual antlrcpp::Any visitShowTables(CentSqlParser::ShowTablesContext *context);
        
        virtual antlrcpp::Any visitShowSchemas(CentSqlParser::ShowSchemasContext *context);
        
        virtual antlrcpp::Any visitShowCatalogs(CentSqlParser::ShowCatalogsContext *context);
        
        virtual antlrcpp::Any visitShowColumns(CentSqlParser::ShowColumnsContext *context);
        
        virtual antlrcpp::Any visitShowStats(CentSqlParser::ShowStatsContext *context);
        
        virtual antlrcpp::Any visitShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext *context);
        
        virtual antlrcpp::Any visitShowFunctions(CentSqlParser::ShowFunctionsContext *context);
        
        virtual antlrcpp::Any visitShowSession(CentSqlParser::ShowSessionContext *context);
        
        virtual antlrcpp::Any visitSetSession(CentSqlParser::SetSessionContext *context);
        
        virtual antlrcpp::Any visitResetSession(CentSqlParser::ResetSessionContext *context);
        
        virtual antlrcpp::Any visitStartTransaction(CentSqlParser::StartTransactionContext *context);
        
        virtual antlrcpp::Any visitCommit(CentSqlParser::CommitContext *context);
        
        virtual antlrcpp::Any visitRollback(CentSqlParser::RollbackContext *context);
        
        virtual antlrcpp::Any visitPrepare(CentSqlParser::PrepareContext *context);
        
        virtual antlrcpp::Any visitDeallocate(CentSqlParser::DeallocateContext *context);
        
        virtual antlrcpp::Any visitExecute(CentSqlParser::ExecuteContext *context);
        
        virtual antlrcpp::Any visitDescribeInput(CentSqlParser::DescribeInputContext *context);
        
        virtual antlrcpp::Any visitDescribeOutput(CentSqlParser::DescribeOutputContext *context);
        
        virtual antlrcpp::Any visitSetPath(CentSqlParser::SetPathContext *context);
        
        virtual antlrcpp::Any visitQuery(CentSqlParser::QueryContext *context);
        
        virtual antlrcpp::Any visitWith(CentSqlParser::WithContext *context);
        
        virtual antlrcpp::Any visitTableElement(CentSqlParser::TableElementContext *context);
        
        virtual antlrcpp::Any visitColumnDefinition(CentSqlParser::ColumnDefinitionContext *context);
        
        virtual antlrcpp::Any visitLikeClause(CentSqlParser::LikeClauseContext *context);
        
        virtual antlrcpp::Any visitProperties(CentSqlParser::PropertiesContext *context);
        
        virtual antlrcpp::Any visitProperty(CentSqlParser::PropertyContext *context);
        
        virtual antlrcpp::Any visitQueryNoWith(CentSqlParser::QueryNoWithContext *context);
        
        virtual antlrcpp::Any visitQueryTermDefault(CentSqlParser::QueryTermDefaultContext *context);
        
        virtual antlrcpp::Any visitSetOperation(CentSqlParser::SetOperationContext *context);
        
        virtual antlrcpp::Any visitQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext *context);
        
        virtual antlrcpp::Any visitTable(CentSqlParser::TableContext *context);
        
        virtual antlrcpp::Any visitInlineTable(CentSqlParser::InlineTableContext *context);
        
        virtual antlrcpp::Any visitSubquery(CentSqlParser::SubqueryContext *context);
        
        virtual antlrcpp::Any visitSortItem(CentSqlParser::SortItemContext *context);
        
        virtual antlrcpp::Any visitQuerySpecification(CentSqlParser::QuerySpecificationContext *context);
        
        virtual antlrcpp::Any visitGroupBy(CentSqlParser::GroupByContext *context);
        
        virtual antlrcpp::Any visitSingleGroupingSet(CentSqlParser::SingleGroupingSetContext *context);
        
        virtual antlrcpp::Any visitRollup(CentSqlParser::RollupContext *context);
        
        virtual antlrcpp::Any visitCube(CentSqlParser::CubeContext *context);
        
        virtual antlrcpp::Any visitMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext *context);
        
        virtual antlrcpp::Any visitGroupingSet(CentSqlParser::GroupingSetContext *context);
        
        virtual antlrcpp::Any visitNamedQuery(CentSqlParser::NamedQueryContext *context);
        
        virtual antlrcpp::Any visitSetQuantifier(CentSqlParser::SetQuantifierContext *context);
        
        virtual antlrcpp::Any visitSelectSingle(CentSqlParser::SelectSingleContext *context);
        
        virtual antlrcpp::Any visitSelectAll(CentSqlParser::SelectAllContext *context);
        
        virtual antlrcpp::Any visitRelationDefault(CentSqlParser::RelationDefaultContext *context);
        
        virtual antlrcpp::Any visitJoinRelation(CentSqlParser::JoinRelationContext *context);
        
        virtual antlrcpp::Any visitJoinType(CentSqlParser::JoinTypeContext *context);
        
        virtual antlrcpp::Any visitJoinCriteria(CentSqlParser::JoinCriteriaContext *context);
        
        virtual antlrcpp::Any visitSampledRelation(CentSqlParser::SampledRelationContext *context);
        
        virtual antlrcpp::Any visitSampleType(CentSqlParser::SampleTypeContext *context);
        
        virtual antlrcpp::Any visitAliasedRelation(CentSqlParser::AliasedRelationContext *context);
        
        virtual antlrcpp::Any visitColumnAliases(CentSqlParser::ColumnAliasesContext *context);
        
        virtual antlrcpp::Any visitTableName(CentSqlParser::TableNameContext *context);
        
        virtual antlrcpp::Any visitSubqueryRelation(CentSqlParser::SubqueryRelationContext *context);
        
        virtual antlrcpp::Any visitUnnest(CentSqlParser::UnnestContext *context);
        
        virtual antlrcpp::Any visitLateral(CentSqlParser::LateralContext *context);
        
        virtual antlrcpp::Any visitParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext *context);
        
        virtual antlrcpp::Any visitExpression(CentSqlParser::ExpressionContext *context);
        
        virtual antlrcpp::Any visitLogicalNot(CentSqlParser::LogicalNotContext *context);
        
        virtual antlrcpp::Any visitPredicated(CentSqlParser::PredicatedContext *context);
        
        virtual antlrcpp::Any visitLogicalBinary(CentSqlParser::LogicalBinaryContext *context);
        
        virtual antlrcpp::Any visitComparison(CentSqlParser::ComparisonContext *context);
        
        virtual antlrcpp::Any visitQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext *context);
        
        virtual antlrcpp::Any visitBetween(CentSqlParser::BetweenContext *context);
        
        virtual antlrcpp::Any visitInList(CentSqlParser::InListContext *context);
        
        virtual antlrcpp::Any visitInSubquery(CentSqlParser::InSubqueryContext *context);
        
        virtual antlrcpp::Any visitLike(CentSqlParser::LikeContext *context);
        
        virtual antlrcpp::Any visitNullPredicate(CentSqlParser::NullPredicateContext *context);
        
        virtual antlrcpp::Any visitDistinctFrom(CentSqlParser::DistinctFromContext *context);
        
        virtual antlrcpp::Any visitValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext *context);
        
        virtual antlrcpp::Any visitConcatenation(CentSqlParser::ConcatenationContext *context);
        
        virtual antlrcpp::Any visitArithmeticBinary(CentSqlParser::ArithmeticBinaryContext *context);
        
        virtual antlrcpp::Any visitArithmeticUnary(CentSqlParser::ArithmeticUnaryContext *context);
        
        virtual antlrcpp::Any visitAtTimeZone(CentSqlParser::AtTimeZoneContext *context);
        
        virtual antlrcpp::Any visitDereference(CentSqlParser::DereferenceContext *context);
        
        virtual antlrcpp::Any visitTypeConstructor(CentSqlParser::TypeConstructorContext *context);
        
        virtual antlrcpp::Any visitSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext *context);
        
        virtual antlrcpp::Any visitSubstring(CentSqlParser::SubstringContext *context);
        
        virtual antlrcpp::Any visitCast(CentSqlParser::CastContext *context);
        
        virtual antlrcpp::Any visitLambda(CentSqlParser::LambdaContext *context);
        
        virtual antlrcpp::Any visitParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext *context);
        
        virtual antlrcpp::Any visitParameter(CentSqlParser::ParameterContext *context);
        
        virtual antlrcpp::Any visitNormalize(CentSqlParser::NormalizeContext *context);
        
        virtual antlrcpp::Any visitIntervalLiteral(CentSqlParser::IntervalLiteralContext *context);
        
        virtual antlrcpp::Any visitNumericLiteral(CentSqlParser::NumericLiteralContext *context);
        
        virtual antlrcpp::Any visitBooleanLiteral(CentSqlParser::BooleanLiteralContext *context);
        
        virtual antlrcpp::Any visitSimpleCase(CentSqlParser::SimpleCaseContext *context);
        
        virtual antlrcpp::Any visitColumnReference(CentSqlParser::ColumnReferenceContext *context);
        
        virtual antlrcpp::Any visitNullLiteral(CentSqlParser::NullLiteralContext *context);
        
        virtual antlrcpp::Any visitRowConstructor(CentSqlParser::RowConstructorContext *context);
        
        virtual antlrcpp::Any visitSubscript(CentSqlParser::SubscriptContext *context);
        
        virtual antlrcpp::Any visitCurrentPath(CentSqlParser::CurrentPathContext *context);
        
        virtual antlrcpp::Any visitSubqueryExpression(CentSqlParser::SubqueryExpressionContext *context);
        
        virtual antlrcpp::Any visitBinaryLiteral(CentSqlParser::BinaryLiteralContext *context);
        
        virtual antlrcpp::Any visitCurrentUser(CentSqlParser::CurrentUserContext *context);
        
        virtual antlrcpp::Any visitExtract(CentSqlParser::ExtractContext *context);
        
        virtual antlrcpp::Any visitStringLiteral(CentSqlParser::StringLiteralContext *context);
        
        virtual antlrcpp::Any visitArrayConstructor(CentSqlParser::ArrayConstructorContext *context);
        
        virtual antlrcpp::Any visitFunctionCall(CentSqlParser::FunctionCallContext *context);
        
        virtual antlrcpp::Any visitExists(CentSqlParser::ExistsContext *context);
        
        virtual antlrcpp::Any visitPosition(CentSqlParser::PositionContext *context);
        
        virtual antlrcpp::Any visitSearchedCase(CentSqlParser::SearchedCaseContext *context);
        
        virtual antlrcpp::Any visitGroupingOperation(CentSqlParser::GroupingOperationContext *context);
        
        virtual antlrcpp::Any visitBasicStringLiteral(CentSqlParser::BasicStringLiteralContext *context);
        
        virtual antlrcpp::Any visitUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext *context);
        
        virtual antlrcpp::Any visitTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext *context);
        
        virtual antlrcpp::Any visitTimeZoneString(CentSqlParser::TimeZoneStringContext *context);
        
        virtual antlrcpp::Any visitComparisonOperator(CentSqlParser::ComparisonOperatorContext *context);
        
        virtual antlrcpp::Any visitComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext *context);
        
        virtual antlrcpp::Any visitBooleanValue(CentSqlParser::BooleanValueContext *context);
        
        virtual antlrcpp::Any visitInterval(CentSqlParser::IntervalContext *context);
        
        virtual antlrcpp::Any visitIntervalField(CentSqlParser::IntervalFieldContext *context);
        
        virtual antlrcpp::Any visitNormalForm(CentSqlParser::NormalFormContext *context);
        
        virtual antlrcpp::Any visitType(CentSqlParser::TypeContext *context);
        
        virtual antlrcpp::Any visitTypeParameter(CentSqlParser::TypeParameterContext *context);
        
        virtual antlrcpp::Any visitBaseType(CentSqlParser::BaseTypeContext *context);
        
        virtual antlrcpp::Any visitWhenClause(CentSqlParser::WhenClauseContext *context);
        
        virtual antlrcpp::Any visitFilter(CentSqlParser::FilterContext *context);
        
        virtual antlrcpp::Any visitOver(CentSqlParser::OverContext *context);
        
        virtual antlrcpp::Any visitWindowFrame(CentSqlParser::WindowFrameContext *context);
        
        virtual antlrcpp::Any visitUnboundedFrame(CentSqlParser::UnboundedFrameContext *context);
        
        virtual antlrcpp::Any visitCurrentRowBound(CentSqlParser::CurrentRowBoundContext *context);
        
        virtual antlrcpp::Any visitBoundedFrame(CentSqlParser::BoundedFrameContext *context);
        
        virtual antlrcpp::Any visitExplainFormat(CentSqlParser::ExplainFormatContext *context);
        
        virtual antlrcpp::Any visitExplainType(CentSqlParser::ExplainTypeContext *context);
        
        virtual antlrcpp::Any visitIsolationLevel(CentSqlParser::IsolationLevelContext *context);
        
        virtual antlrcpp::Any visitTransactionAccessMode(CentSqlParser::TransactionAccessModeContext *context);
        
        virtual antlrcpp::Any visitReadUncommitted(CentSqlParser::ReadUncommittedContext *context);
        
        virtual antlrcpp::Any visitReadCommitted(CentSqlParser::ReadCommittedContext *context);
        
        virtual antlrcpp::Any visitRepeatableRead(CentSqlParser::RepeatableReadContext *context);
        
        virtual antlrcpp::Any visitSerializable(CentSqlParser::SerializableContext *context);
        
        virtual antlrcpp::Any visitPositionalArgument(CentSqlParser::PositionalArgumentContext *context);
        
        virtual antlrcpp::Any visitNamedArgument(CentSqlParser::NamedArgumentContext *context);
        
        virtual antlrcpp::Any visitQualifiedArgument(CentSqlParser::QualifiedArgumentContext *context);
        
        virtual antlrcpp::Any visitUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext *context);
        
        virtual antlrcpp::Any visitPathSpecification(CentSqlParser::PathSpecificationContext *context);
        
        virtual antlrcpp::Any visitPrivilege(CentSqlParser::PrivilegeContext *context);
        
        virtual antlrcpp::Any visitQualifiedName(CentSqlParser::QualifiedNameContext *context);
        
        virtual antlrcpp::Any visitUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext *context);
        
        virtual antlrcpp::Any visitQuotedIdentifier(CentSqlParser::QuotedIdentifierContext *context);
        
        virtual antlrcpp::Any visitBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext *context);
        
        virtual antlrcpp::Any visitDigitIdentifier(CentSqlParser::DigitIdentifierContext *context);
        
        virtual antlrcpp::Any visitDecimalLiteral(CentSqlParser::DecimalLiteralContext *context);
        
        virtual antlrcpp::Any visitDoubleLiteral(CentSqlParser::DoubleLiteralContext *context);
        
        virtual antlrcpp::Any visitIntegerLiteral(CentSqlParser::IntegerLiteralContext *context);
        
        virtual antlrcpp::Any visitNonReserved(CentSqlParser::NonReservedContext *context);
        
        
    };
    
}  // namespace centurion


#endif /* AstBuilder_h */
