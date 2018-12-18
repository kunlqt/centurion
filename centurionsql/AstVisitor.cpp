#include "AstVisitor.h"

namespace centurion {
	antlrcpp::Any AstVisitor::process(Node* node)
	{
		return process(node, nullptr);
	}

	antlrcpp::Any AstVisitor::process(Node* node, antlr4::ParserRuleContext* context)
	{
		return node->accept(this, context);
	}

	antlrcpp::Any AstVisitor::visitExpression(Expression* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitSelect(Select* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitSelectItem(SelectItem* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitSelectItem((SelectItem*)node, context);
	}

	antlrcpp::Any AstVisitor::visitAllColumns(AllColumns* node, antlr4::ParserRuleContext* context)
	{
		return visitSelectItem((SelectItem*)node, context);
	}

	antlrcpp::Any AstVisitor::visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitTable(Table* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody((QueryBody*)node, context);
	}

	antlrcpp::Any AstVisitor::visitQueryBody(QueryBody* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation((Relation*)node, context);
	}

	antlrcpp::Any AstVisitor::visitRelation(Relation* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitNode(Node* node, antlr4::ParserRuleContext* context)
	{
		return nullptr;
	}

	antlrcpp::Any AstVisitor::visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitStatement(Statement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitQuery(Query* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement((Statement*)node, context);
	}

	antlrcpp::Any AstVisitor::visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitWith(With* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitSortItem(SortItem* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody((QueryBody*)node, context);
	}

	antlrcpp::Any AstVisitor::visitGroupingElement(GroupingElement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitGroupBy(GroupBy* node, antlr4::ParserRuleContext* context)
	{
		return visitNode((Node*)node, context);
	}

	antlrcpp::Any AstVisitor::visitJoin(Join* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation((Relation*)node, context);
	}

	antlrcpp::Any AstVisitor::visitComparisonExpression(ComparisonExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitLiteral(Literal* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitDoubleLiteral(DoubleLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitor::visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitor::visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitor::visitLogicalBinaryExpression(LogicalBinaryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral((Literal*)node, context);
	}

	antlrcpp::Any AstVisitor::visitAliasedRelation(AliasedRelation* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation((Relation*)node, context);
	}

	antlrcpp::Any AstVisitor::visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitArithmeticBinary(ArithmeticBinaryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitShowStats(ShowStats* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement((Statement*)node, context);
	}

	antlrcpp::Any AstVisitor::visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement((GroupingElement*)node, context);
	}

	antlrcpp::Any AstVisitor::visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	antlrcpp::Any AstVisitor::visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression((Expression*)node, context);
	}

	/*
	antlrcpp::Any AstVisitor::visitCurrentTime(CurrentTime* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitExtract(Extract* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitBetweenPredicate(BetweenPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitCoalesceExpression(CoalesceExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitPrepare(Prepare* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDeallocate(Deallocate* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitExecute(Execute* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDescribeOutput(DescribeOutput* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDescribeInput(DescribeInput* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitExplain(Explain* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowTables(ShowTables* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowSchemas(ShowSchemas* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowCatalogs(ShowCatalogs* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowColumns(ShowColumns* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowCreate(ShowCreate* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowFunctions(ShowFunctions* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitUse(Use* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowSession(ShowSession* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitSetSession(SetSession* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitResetSession(ResetSession* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitGenericLiteral(GenericLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitTimeLiteral(TimeLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitExplainOption(ExplainOption* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitSetOperation(SetOperation* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody(node, context);
	}

	antlrcpp::Any AstVisitor::visitUnion(Union* node, antlr4::ParserRuleContext* context)
	{
		return visitSetOperation(node, context);
	}

	antlrcpp::Any AstVisitor::visitIntersect(Intersect* node, antlr4::ParserRuleContext* context)
	{
		return visitSetOperation(node, context);
	}

	antlrcpp::Any AstVisitor::visitExcept(Except* node, antlr4::ParserRuleContext* context)
	{
		return visitSetOperation(node, context);
	}

	antlrcpp::Any AstVisitor::visitTimestampLiteral(TimestampLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitWhenClause(WhenClause* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitIntervalLiteral(IntervalLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitFunctionCall(FunctionCall* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitLambdaExpression(LambdaExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitSimpleCaseExpression(SimpleCaseExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitCharLiteral(CharLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitBinaryLiteral(BinaryLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitBooleanLiteral(BooleanLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}


	antlrcpp::Any AstVisitor::visitNullIfExpression(NullIfExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitIfExpression(IfExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitNullLiteral(NullLiteral* node, antlr4::ParserRuleContext* context)
	{
		return visitLiteral(node, context);
	}

	antlrcpp::Any AstVisitor::visitSearchedCaseExpression(SearchedCaseExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitLikePredicate(LikePredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitArrayConstructor(ArrayConstructor* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitSubscriptExpression(SubscriptExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitParameter(Parameter* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitUnnest(Unnest* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation(node, context);
	}

	antlrcpp::Any AstVisitor::visitLateral(Lateral* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation(node, context);
	}

	antlrcpp::Any AstVisitor::visitValues(Values* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody(node, context);
	}

	antlrcpp::Any AstVisitor::visitRow(Row* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitTableSubquery(TableSubquery* node, antlr4::ParserRuleContext* context)
	{
		return visitQueryBody(node, context);
	}

	antlrcpp::Any AstVisitor::visitSampledRelation(SampledRelation* node, antlr4::ParserRuleContext* context)
	{
		return visitRelation(node, context);
	}

	antlrcpp::Any AstVisitor::visitExists(ExistsPredicate* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitTryExpression(TryExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitCast(Cast* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitFieldReference(FieldReference* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitWindow(Window* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitWindowFrame(WindowFrame* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitFrameBound(FrameBound* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitCallArgument(CallArgument* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitTableElement(TableElement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitColumnDefinition(ColumnDefinition* node, antlr4::ParserRuleContext* context)
	{
		return visitTableElement(node, context);
	}

	antlrcpp::Any AstVisitor::visitLikeClause(LikeClause* node, antlr4::ParserRuleContext* context)
	{
		return visitTableElement(node, context);
	}

	antlrcpp::Any AstVisitor::visitCreateSchema(CreateSchema* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDropSchema(DropSchema* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitRenameSchema(RenameSchema* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitCreateTable(CreateTable* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitCreateTableAsSelect(CreateTableAsSelect* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitProperty(Property* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitDropTable(DropTable* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitRenameTable(RenameTable* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitRenameColumn(RenameColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDropColumn(DropColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitAddColumn(AddColumn* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitCreateView(CreateView* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDropView(DropView* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitInsert(Insert* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitCall(Call* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitDelete(Delete* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitStartTransaction(StartTransaction* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitGrant(Grant* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitRevoke(Revoke* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitShowGrants(ShowGrants* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitSetPath(SetPath* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitPathSpecification(PathSpecification* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitPathElement(PathElement* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitTransactionMode(TransactionMode* node, antlr4::ParserRuleContext* context)
	{
		return visitNode(node, context);
	}

	antlrcpp::Any AstVisitor::visitIsolationLevel(Isolation* node, antlr4::ParserRuleContext* context)
	{
		return visitTransactionMode(node, context);
	}

	antlrcpp::Any AstVisitor::visitTransactionAccessMode(TransactionAccessMode* node, antlr4::ParserRuleContext* context)
	{
		return visitTransactionMode(node, context);
	}

	antlrcpp::Any AstVisitor::visitCommit(Commit* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitRollback(Rollback* node, antlr4::ParserRuleContext* context)
	{
		return visitStatement(node, context);
	}

	antlrcpp::Any AstVisitor::visitAtTimeZone(AtTimeZone* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}


	antlrcpp::Any AstVisitor::visitCube(Cube* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement(node, context);
	}

	antlrcpp::Any AstVisitor::visitGroupingSets(GroupingSets* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement(node, context);
	}

	antlrcpp::Any AstVisitor::visitRollup(Rollup* node, antlr4::ParserRuleContext* context)
	{
		return visitGroupingElement(node, context);
	}

	antlrcpp::Any AstVisitor::visitSymbolReference(SymbolReference* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitQuantifiedComparisonExpression(QuantifiedComparisonExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitLambdaArgumentDeclaration(LambdaArgumentDeclaration* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitBindExpression(BindExpression* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitCurrentUser(CurrentUser* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}

	antlrcpp::Any AstVisitor::visitCurrentPath(CurrentPath* node, antlr4::ParserRuleContext* context)
	{
		return visitExpression(node, context);
	}
	*/
}
