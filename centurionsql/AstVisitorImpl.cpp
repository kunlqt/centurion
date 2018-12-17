#include "AstVisitorImpl.h"

namespace centurion {
	antlrcpp::Any AstVisitorImpl::process(Node* node)
	{
		return process(node, nullptr);
	}

	antlrcpp::Any AstVisitorImpl::process(Node* node, antlr4::ParserRuleContext* context)
	{
		return node->accept(this, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExpression(Expression* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSelect(Select* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSelectItem(SelectItem* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitSelectItem((SelectItem*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitAllColumns(AllColumns* node, antlr4::ParserRuleContext* context)
	{
		return visitSelectItem((SelectItem*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTable(Table* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody((QueryBody*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitQueryBody(QueryBody* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation((Relation*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRelation(Relation* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitNode(Node* node, antlr4::ParserRuleContext* context)
	{
		return nullptr;
	}

	antlrcpp::Any AstVisitorImpl::visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitStatement(Statement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitQuery(Query* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement((Statement*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitWith(With* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSortItem(SortItem* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody((QueryBody*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitGroupingElement(GroupingElement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitGroupBy(GroupBy* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitJoin(Join* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation((Relation*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitComparisonExpression(ComparisonExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLiteral(Literal* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDoubleLiteral(DoubleLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLogicalBinaryExpression(LogicalBinaryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitAliasedRelation(AliasedRelation* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation((Relation*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitArithmeticBinary(ArithmeticBinaryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowStats(ShowStats* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement((Statement*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement((GroupingElement*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	/*
	antlrcpp::Any AstVisitorImpl::visitCurrentTime(CurrentTime* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExtract(Extract* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitBetweenPredicate(BetweenPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCoalesceExpression(CoalesceExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitPrepare(Prepare* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDeallocate(Deallocate* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExecute(Execute* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDescribeOutput(DescribeOutput* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDescribeInput(DescribeInput* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExplain(Explain* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowTables(ShowTables* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowSchemas(ShowSchemas* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowCatalogs(ShowCatalogs* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowColumns(ShowColumns* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowCreate(ShowCreate* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowFunctions(ShowFunctions* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitUse(Use* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowSession(ShowSession* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSetSession(SetSession* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitResetSession(ResetSession* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitGenericLiteral(GenericLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTimeLiteral(TimeLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExplainOption(ExplainOption* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSetOperation(SetOperation* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitUnion(Union* node, antlr4::ParserRuleContext* context)
	{
		return visitSetOperation(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIntersect(Intersect* node, antlr4::ParserRuleContext* context)
	{
		return visitSetOperation(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExcept(Except* node, antlr4::ParserRuleContext* context)
	{
		return visitSetOperation(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTimestampLiteral(TimestampLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitWhenClause(WhenClause* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIntervalLiteral(IntervalLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitFunctionCall(FunctionCall* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLambdaExpression(LambdaExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSimpleCaseExpression(SimpleCaseExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCharLiteral(CharLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitBinaryLiteral(BinaryLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitBooleanLiteral(BooleanLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}


	antlrcpp::Any AstVisitorImpl::visitNullIfExpression(NullIfExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIfExpression(IfExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitNullLiteral(NullLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSearchedCaseExpression(SearchedCaseExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLikePredicate(LikePredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitArrayConstructor(ArrayConstructor* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSubscriptExpression(SubscriptExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitParameter(Parameter* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitUnnest(Unnest* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLateral(Lateral* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitValues(Values* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRow(Row* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTableSubquery(TableSubquery* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSampledRelation(SampledRelation* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitExists(ExistsPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTryExpression(TryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCast(Cast* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitFieldReference(FieldReference* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitWindow(Window* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitWindowFrame(WindowFrame* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitFrameBound(FrameBound* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCallArgument(CallArgument* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTableElement(TableElement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitColumnDefinition(ColumnDefinition* node, antlr4::ParserRuleContext* context)
	{
		return visitTableElement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLikeClause(LikeClause* node, antlr4::ParserRuleContext* context)
	{
		return visitTableElement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCreateSchema(CreateSchema* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDropSchema(DropSchema* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRenameSchema(RenameSchema* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCreateTable(CreateTable* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCreateTableAsSelect(CreateTableAsSelect* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitProperty(Property* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDropTable(DropTable* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRenameTable(RenameTable* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRenameColumn(RenameColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDropColumn(DropColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitAddColumn(AddColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCreateView(CreateView* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDropView(DropView* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitInsert(Insert* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCall(Call* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitDelete(Delete* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitStartTransaction(StartTransaction* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitGrant(Grant* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRevoke(Revoke* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitShowGrants(ShowGrants* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSetPath(SetPath* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitPathSpecification(PathSpecification* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitPathElement(PathElement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTransactionMode(TransactionMode* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitIsolationLevel(Isolation* node, antlr4::ParserRuleContext* context)
	{
		return visitTransactionMode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitTransactionAccessMode(TransactionAccessMode* node, antlr4::ParserRuleContext* context)
	{
		return visitTransactionMode(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCommit(Commit* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRollback(Rollback* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitAtTimeZone(AtTimeZone* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}


	antlrcpp::Any AstVisitorImpl::visitCube(Cube* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitGroupingSets(GroupingSets* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitRollup(Rollup* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitSymbolReference(SymbolReference* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitQuantifiedComparisonExpression(QuantifiedComparisonExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitLambdaArgumentDeclaration(LambdaArgumentDeclaration* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitBindExpression(BindExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCurrentUser(CurrentUser* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitorImpl::visitCurrentPath(CurrentPath* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}
	*/
}
