//
//  AstVisitor.h
//  CenturionSQL
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#pragma once

#include "AstNodes.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <antlr4-runtime.h>

namespace centurion {
	class AstVisitor {
	private:
		std::shared_ptr<spdlog::logger> log_;

	public:
		AstVisitor();

		virtual ~AstVisitor();


		virtual antlrcpp::Any process(Node* node);
		virtual antlrcpp::Any process(Node* node, antlr4::ParserRuleContext* context);
			
		virtual antlrcpp::Any visitExpression(Expression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitSelect(Select* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitSelectItem(SelectItem* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitAllColumns(AllColumns* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitTable(Table* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitQueryBody(QueryBody* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitRelation(Relation* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitNode(Node* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitStatement(Statement* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitQuery(Query* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitWith(With* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitSortItem(SortItem* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitGroupingElement(GroupingElement* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitGroupBy(GroupBy* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitJoin(Join* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitComparisonExpression(ComparisonExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitLiteral(Literal* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitDoubleLiteral(DoubleLiteral* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitBooleanLiteral(BooleanLiteral* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitAliasedRelation(AliasedRelation* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitShowStats(ShowStats* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitLikePredicate(LikePredicate* node, antlr4::ParserRuleContext* context);

		virtual antlrcpp::Any visitBetweenPredicate(BetweenPredicate* node, antlr4::ParserRuleContext* context);

		/*
		virtual antlrcpp::Any visitCurrentTime(CurrentTime* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitExtract(Extract* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}


		virtual antlrcpp::Any visitCoalesceExpression(CoalesceExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitPrepare(Prepare* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDeallocate(Deallocate* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitExecute(Execute* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDescribeOutput(DescribeOutput* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDescribeInput(DescribeInput* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitExplain(Explain* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowTables(ShowTables* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowSchemas(ShowSchemas* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowCatalogs(ShowCatalogs* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowColumns(ShowColumns* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowCreate(ShowCreate* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowFunctions(ShowFunctions* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitUse(Use* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowSession(ShowSession* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitSetSession(SetSession* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitResetSession(ResetSession* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitGenericLiteral(GenericLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}

		virtual antlrcpp::Any visitTimeLiteral(TimeLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}

		virtual antlrcpp::Any visitExplainOption(ExplainOption* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitSetOperation(SetOperation* node, antlr4::ParserRuleContext* context)
		{
			return visitQueryBody(node, context);
		}

		virtual antlrcpp::Any visitUnion(Union* node, antlr4::ParserRuleContext* context)
		{
			return visitSetOperation(node, context);
		}

		virtual antlrcpp::Any visitIntersect(Intersect* node, antlr4::ParserRuleContext* context)
		{
			return visitSetOperation(node, context);
		}

		virtual antlrcpp::Any visitExcept(Except* node, antlr4::ParserRuleContext* context)
		{
			return visitSetOperation(node, context);
		}

		virtual antlrcpp::Any visitTimestampLiteral(TimestampLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}

		virtual antlrcpp::Any visitWhenClause(WhenClause* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitIntervalLiteral(IntervalLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}

		virtual antlrcpp::Any visitFunctionCall(FunctionCall* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitLambdaExpression(LambdaExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitSimpleCaseExpression(SimpleCaseExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitCharLiteral(CharLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}

		virtual antlrcpp::Any visitBinaryLiteral(BinaryLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}		

		virtual antlrcpp::Any visitNullIfExpression(NullIfExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitIfExpression(IfExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitNullLiteral(NullLiteral* node, antlr4::ParserRuleContext* context)
		{
			return visitLiteral(node, context);
		}

		virtual antlrcpp::Any visitSearchedCaseExpression(SearchedCaseExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitArrayConstructor(ArrayConstructor* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitSubscriptExpression(SubscriptExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitParameter(Parameter* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitUnnest(Unnest* node, antlr4::ParserRuleContext* context)
		{
			return visitRelation(node, context);
		}

		virtual antlrcpp::Any visitLateral(Lateral* node, antlr4::ParserRuleContext* context)
		{
			return visitRelation(node, context);
		}

		virtual antlrcpp::Any visitValues(Values* node, antlr4::ParserRuleContext* context)
		{
			return visitQueryBody(node, context);
		}

		virtual antlrcpp::Any visitRow(Row* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitTableSubquery(TableSubquery* node, antlr4::ParserRuleContext* context)
		{
			return visitQueryBody(node, context);
		}

		virtual antlrcpp::Any visitSampledRelation(SampledRelation* node, antlr4::ParserRuleContext* context)
		{
			return visitRelation(node, context);
		}

		virtual antlrcpp::Any visitExists(ExistsPredicate* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitTryExpression(TryExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitCast(Cast* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitFieldReference(FieldReference* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitWindow(Window* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitWindowFrame(WindowFrame* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitFrameBound(FrameBound* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitCallArgument(CallArgument* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitTableElement(TableElement* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitColumnDefinition(ColumnDefinition* node, antlr4::ParserRuleContext* context)
		{
			return visitTableElement(node, context);
		}

		virtual antlrcpp::Any visitLikeClause(LikeClause* node, antlr4::ParserRuleContext* context)
		{
			return visitTableElement(node, context);
		}

		virtual antlrcpp::Any visitCreateSchema(CreateSchema* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDropSchema(DropSchema* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitRenameSchema(RenameSchema* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitCreateTable(CreateTable* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitCreateTableAsSelect(CreateTableAsSelect* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitProperty(Property* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitDropTable(DropTable* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitRenameTable(RenameTable* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitRenameColumn(RenameColumn* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDropColumn(DropColumn* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitAddColumn(AddColumn* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitCreateView(CreateView* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDropView(DropView* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitInsert(Insert* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitCall(Call* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitDelete(Delete* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitStartTransaction(StartTransaction* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitGrant(Grant* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitRevoke(Revoke* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitShowGrants(ShowGrants* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitSetPath(SetPath* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitPathSpecification(PathSpecification* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitPathElement(PathElement* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitTransactionMode(TransactionMode* node, antlr4::ParserRuleContext* context)
		{
			return visitNode(node, context);
		}

		virtual antlrcpp::Any visitIsolationLevel(Isolation* node, antlr4::ParserRuleContext* context)
		{
			return visitTransactionMode(node, context);
		}

		virtual antlrcpp::Any visitTransactionAccessMode(TransactionAccessMode* node, antlr4::ParserRuleContext* context)
		{
			return visitTransactionMode(node, context);
		}

		virtual antlrcpp::Any visitCommit(Commit* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitRollback(Rollback* node, antlr4::ParserRuleContext* context)
		{
			return visitStatement(node, context);
		}

		virtual antlrcpp::Any visitAtTimeZone(AtTimeZone* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}


		virtual antlrcpp::Any visitCube(Cube* node, antlr4::ParserRuleContext* context)
		{
			return visitGroupingElement(node, context);
		}

		virtual antlrcpp::Any visitGroupingSets(GroupingSets* node, antlr4::ParserRuleContext* context)
		{
			return visitGroupingElement(node, context);
		}

		virtual antlrcpp::Any visitRollup(Rollup* node, antlr4::ParserRuleContext* context)
		{
			return visitGroupingElement(node, context);
		}

		virtual antlrcpp::Any visitSymbolReference(SymbolReference* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitQuantifiedComparisonExpression(QuantifiedComparisonExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitLambdaArgumentDeclaration(LambdaArgumentDeclaration* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitBindExpression(BindExpression* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitCurrentUser(CurrentUser* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}

		virtual antlrcpp::Any visitCurrentPath(CurrentPath* node, antlr4::ParserRuleContext* context)
		{
			return visitExpression(node, context);
		}
		*/

	};

}

