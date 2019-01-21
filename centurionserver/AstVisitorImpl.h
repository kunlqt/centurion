#pragma once
#include <spdlog/spdlog.h>
#include "AstVisitor.h"

namespace centurion {
	class AstVisitorImpl : public AstVisitor {
	public:
		AstVisitorImpl() : _logger(spdlog::get("root")->clone("AstVisitorImpl"))
		{

		}

		//antlrcpp::Any visitExtract(Extract* node, antlr4::ParserRuleContext* context) override
		//{
		//	return process(node->getExpression(), context);
		//}

		//antlrcpp::Any visitCast(Cast* node, antlr4::ParserRuleContext* context) override
		//{
		//	return process(node->getExpression(), context);
		//}


		antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft(), context);
			process(node->getRight(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitBetweenPredicate(BetweenPredicate* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getValue(), context);
			process(node->getMin(), context);
			process(node->getMax(), context);

			return antlrcpp::Any();
		}


		//antlrcpp::Any visitCoalesceExpression(CoalesceExpression* node, antlr4::ParserRuleContext* context) override
		//{
		//	for (Expression* operand : node->getOperands()) {
		//		process(operand, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitAtTimeZone(AtTimeZone* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getValue(), context);
		//	process(node->getTimeZone(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitArrayConstructor(ArrayConstructor* node, antlr4::ParserRuleContext* context) override
		//{
		//	for (Expression* expression : node->getValues()) {
		//		process(expression, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitSubscriptExpression(SubscriptExpression* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getBase(), context);
		//	process(node->getIndex(), context);

		//	return antlrcpp::Any();
		//}


		antlrcpp::Any visitComparisonExpression(ComparisonExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft(), context);
			process(node->getRight(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitQuery(Query* node, antlr4::ParserRuleContext* context) override
		{
			if (node->getWith().has_value()) {
				process(node->getWith().value(), context);
			}
			process(node->getQueryBody(), context);
			if (node->getOrderBy().has_value()) {
				process(node->getOrderBy().value(), context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitWith(With* node, antlr4::ParserRuleContext* context) override
		{
			for (WithQuery* query : node->getQueries()) {
				process(query, context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery(), context);
		}


		antlrcpp::Any visitSelect(Select* node, antlr4::ParserRuleContext* context) override
		{
			for (SelectItem* item : node->getSelectItems()) {
				process(item, context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getExpression(), context);

			return antlrcpp::Any();
		}


		//antlrcpp::Any visitWhenClause(WhenClause* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getOperand(), context);
		//	process(node->getResult(), context);

		//	return antlrcpp::Any();
		//}


		antlrcpp::Any visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getValue().get(), context);
			process(node->getValueList().get(), context);

			return antlrcpp::Any();
		}


		//antlrcpp::Any visitFunctionCall(FunctionCall* node, antlr4::ParserRuleContext* context) override
		//{
		//	for (Expression* argument : node->getArguments()) {
		//		process(argument, context);
		//	}

		//	if (node->getOrderBy().has_value()) {
		//		process(node->getOrderBy().value(), context);
		//	}

		//	if (node->getWindow().has_value()) {
		//		process(node->getWindow().value(), context);
		//	}

		//	if (node->getFilter().has_value()) {
		//		process(node->getFilter().value(), context);
		//	}

		//	return antlrcpp::Any();
		//}


		antlrcpp::Any visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context) override
		{
			for (auto columnArgument : node->getGroupingColumns()) {
				process(columnArgument.get(), context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getBase().get(), context);
			return antlrcpp::Any();
		}


	/*	public antlrcpp::Any visitWindow(Window* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* expression : node->getPartitionBy()) {
				process(expression, context);
			}

			if (node->getOrderBy().has_value()) {
				process(node->getOrderBy().value(), context);
			}

			if (node->getFrame().has_value()) {
				process(node->getFrame().value(), context);
			}

			return antlrcpp::Any();
		}


		public antlrcpp::Any visitWindowFrame(WindowFrame* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getStart(), context);
			if (node->getEnd().has_value()) {
				process(node->getEnd().value(), context);
			}

			return antlrcpp::Any();
		}


		public antlrcpp::Any visitFrameBound(FrameBound* node, antlr4::ParserRuleContext* context) override
		{
			if (node->getValue().has_value()) {
				process(node->getValue().value(), context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitSimpleCaseExpression(SimpleCaseExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getOperand(), context);
			for (WhenClause* clause : node->getWhenClauses()) {
				process(clause, context);
			}

			node->getDefaultValue()
				.ifPresent(value->process(value, context));

			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context) override
		{
			for (auto value : node->getValues()) {
				process(value.get(), context);
			}
			return antlrcpp::Any();
		}


		/*antlrcpp::Any visitNullIfExpression(NullIfExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getFirst(), context);
			process(node->getSecond(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitIfExpression(IfExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getCondition(), context);
			process(node->getTrueValue(), context);
			if (node->getFalseValue().has_value()) {
				process(node->getFalseValue().value(), context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitTryExpression(TryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getInnerExpression(), context);
			return antlrcpp::Any();
		}


		antlrcpp::Any visitBindExpression(BindExpression* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* value : node->getValues()) {
				process(value, context);
			}
			process(node->getFunction(), context);

			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}


		antlrcpp::Any visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}


		/*antlrcpp::Any visitSearchedCaseExpression(SearchedCaseExpression* node, antlr4::ParserRuleContext* context) override
		{
			for (WhenClause* clause : node->getWhenClauses()) {
				process(clause, context);
			}
			if (node->getDefaultValue().has_value()) {
				process(node->getDefaultValue().value(), context);
			}
			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitLikePredicate(LikePredicate* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getValue(), context);
			process(node->getPattern(), context);
			if (node->getEscape().has_value()) {
				process(node->getEscape().value(), context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}


		antlrcpp::Any visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}


		antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft(), context);
			process(node->getRight(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery(), context);
		}


		antlrcpp::Any visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context) override
		{
			for (SortItem* sortItem : node->getSortItems()) {
				process(sortItem, context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitSortItem(SortItem* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getSortKey(), context);
		}


		antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getSelect().value(), context);
			if (node->getFrom().has_value()) {
				process(node->getFrom().value(), context);
			}
			if (node->getWhere().has_value()) {
				process(node->getWhere().value(), context);
			}
			if (node->getGroupBy().has_value()) {
				process(node->getGroupBy().value(), context);
			}
			if (node->getHaving().has_value()) {
				process(node->getHaving().value(), context);
			}
			if (node->getOrderBy().has_value()) {
				process(node->getOrderBy().value(), context);
			}
			return antlrcpp::Any();
		}


		/*antlrcpp::Any visitSetOperation(SetOperation* node, antlr4::ParserRuleContext* context) override
		{
			for (Relation* relation : node->getRelations()) {
				process(relation, context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitValues(Values* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* row : node->getRows()) {
				process(row, context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitRow(Row* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* expression : node->getItems()) {
				process(expression, context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitTableSubquery(TableSubquery* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery(), context);
		}*/


		antlrcpp::Any visitAliasedRelation(AliasedRelation* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getRelation(), context);
		}


		/*antlrcpp::Any visitSampledRelation(SampledRelation* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getRelation(), context);
			process(node->getSamplePercentage(), context);
			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitJoin(Join* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft(), context);
			process(node->getRight(), context);

			if (node->getCriteria().has_value()) {
				auto criteria = dynamic_cast<JoinOn*>(node->getCriteria().value());
				if (criteria) {
					process(criteria->getExpression(), context);
				}
			}
			return antlrcpp::Any();
		}

/*
		antlrcpp::Any visitUnnest(Unnest* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* expression : node->getExpressions()) {
				process(expression, context);
			}

			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitGroupBy(GroupBy* node, antlr4::ParserRuleContext* context) override
		{
			for (GroupingElement* groupingElement : node->getGroupingElements()) {
				process(groupingElement, context);
			}

			return antlrcpp::Any();
		}
/*

		antlrcpp::Any visitCube(Cube* node, antlr4::ParserRuleContext* context) override
		{
			return antlrcpp::Any();
		}


		antlrcpp::Any visitRollup(Rollup* node, antlr4::ParserRuleContext* context) override
		{
			return antlrcpp::Any();
		}
*/

		antlrcpp::Any visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* expression : node->getExpressions()) {
				process(expression, context);
			}

			return antlrcpp::Any();
		}


		//antlrcpp::Any visitGroupingSets(GroupingSets* node, antlr4::ParserRuleContext* context) override
		//{
		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitInsert(Insert* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitDelete(Delete* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getTable(), context);
		//	if (node->getWhere().has_value()) {
		//		process(node->getWhere().value(), context);
		//	}
		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitCreateTableAsSelect(CreateTableAsSelect* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery(), context);
		//	for (Property* property : node->getProperties()) {
		//		process(property, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitProperty(Property* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getName(), context);
		//	process(node->getValue(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitCreateView(CreateView* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitSetSession(SetSession* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getValue(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitAddColumn(AddColumn* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getColumn(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitCreateTable(CreateTable* node, antlr4::ParserRuleContext* context) override
		//{
		//	for (TableElement* tableElement : node->getElements()) {
		//		process(tableElement, context);
		//	}
		//	for (Property property : node->getProperties()) {
		//		process(property, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitStartTransaction(StartTransaction* node, antlr4::ParserRuleContext* context) override
		//{
		//	for (TransactionMode* transactionMode : node->getTransactionModes()) {
		//		process(transactionMode, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitExplain(Explain* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getStatement(), context);

		//	for (ExplainOption* option : node->getOptions()) {
		//		process(option, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitQuantifiedComparisonExpression(QuantifiedComparisonExpression* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getValue(), context);
		//	process(node->getSubquery(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitExists(ExistsPredicate* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getSubquery(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitLateral(Lateral* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery(), context);

		//	return AstVisitor::visitLateral(node, context);
		//}


	private:
		std::shared_ptr<spdlog::logger> _logger;
	};
}
