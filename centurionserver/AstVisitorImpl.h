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
		//	return process(node->getExpression().get(), context);
		//}

		//antlrcpp::Any visitCast(Cast* node, antlr4::ParserRuleContext* context) override
		//{
		//	return process(node->getExpression().get(), context);
		//}


		antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft().get(), context);
			process(node->getRight().get(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitBetweenPredicate(BetweenPredicate* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getValue().get(), context);
			process(node->getMin().get(), context);
			process(node->getMax().get(), context);

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
		//	process(node->getValue().get(), context);
		//	process(node->getTimeZone().get(), context);

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
		//	process(node->getBase().get(), context);
		//	process(node->getIndex().get(), context);

		//	return antlrcpp::Any();
		//}


		antlrcpp::Any visitComparisonExpression(ComparisonExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft().get(), context);
			process(node->getRight().get(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitQuery(Query* node, antlr4::ParserRuleContext* context) override
		{
			if (node->getWith().has_value()) {
				process(node->getWith().value().get(), context);
			}
			process(node->getQueryBody().get(), context);
			if (node->getOrderBy().has_value()) {
				process(node->getOrderBy().value().get(), context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitWith(With* node, antlr4::ParserRuleContext* context) override
		{
			for (auto query : node->getQueries()) {
				process(query.get(), context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery().get(), context);
		}


		antlrcpp::Any visitSelect(Select* node, antlr4::ParserRuleContext* context) override
		{
			for (auto item : node->getSelectItems()) {
				process(item.get(), context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getExpression().get(), context);

			return antlrcpp::Any();
		}


		//antlrcpp::Any visitWhenClause(WhenClause* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getOperand().get(), context);
		//	process(node->getResult().get(), context);

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
		//		process(node->getOrderBy().value().get(), context);
		//	}

		//	if (node->getWindow().has_value()) {
		//		process(node->getWindow().value().get(), context);
		//	}

		//	if (node->getFilter().has_value()) {
		//		process(node->getFilter().value().get(), context);
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
				process(node->getOrderBy().value().get(), context);
			}

			if (node->getFrame().has_value()) {
				process(node->getFrame().value().get(), context);
			}

			return antlrcpp::Any();
		}


		public antlrcpp::Any visitWindowFrame(WindowFrame* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getStart().get(), context);
			if (node->getEnd().has_value()) {
				process(node->getEnd().value().get(), context);
			}

			return antlrcpp::Any();
		}


		public antlrcpp::Any visitFrameBound(FrameBound* node, antlr4::ParserRuleContext* context) override
		{
			if (node->getValue().has_value()) {
				process(node->getValue().value().get(), context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitSimpleCaseExpression(SimpleCaseExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getOperand().get(), context);
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
			process(node->getFirst().get(), context);
			process(node->getSecond().get(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitIfExpression(IfExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getCondition().get(), context);
			process(node->getTrueValue().get(), context);
			if (node->getFalseValue().has_value()) {
				process(node->getFalseValue().value().get(), context);
			}

			return antlrcpp::Any();
		}


		antlrcpp::Any visitTryExpression(TryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getInnerExpression().get(), context);
			return antlrcpp::Any();
		}


		antlrcpp::Any visitBindExpression(BindExpression* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* value : node->getValues()) {
				process(value, context);
			}
			process(node->getFunction().get(), context);

			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue().get(), context);
		}


		antlrcpp::Any visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue().get(), context);
		}


		/*antlrcpp::Any visitSearchedCaseExpression(SearchedCaseExpression* node, antlr4::ParserRuleContext* context) override
		{
			for (WhenClause* clause : node->getWhenClauses()) {
				process(clause, context);
			}
			if (node->getDefaultValue().has_value()) {
				process(node->getDefaultValue().value().get(), context);
			}
			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitLikePredicate(LikePredicate* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getValue().get(), context);
			process(node->getPattern().get(), context);
			if (node->getEscape().has_value()) {
				process(node->getEscape().value().get(), context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue().get(), context);
		}


		antlrcpp::Any visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue().get(), context);
		}


		antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft().get(), context);
			process(node->getRight().get(), context);

			return antlrcpp::Any();
		}


		antlrcpp::Any visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery().get(), context);
		}


		antlrcpp::Any visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context) override
		{
			for (auto sortItem : node->getSortItems()) {
				process(sortItem.get(), context);
			}
			return antlrcpp::Any();
		}


		antlrcpp::Any visitSortItem(SortItem* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getSortKey().get(), context);
		}


		antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getSelect().value().get(), context);
			if (node->getFrom().has_value()) {
				process(node->getFrom().value().get(), context);
			}
			if (node->getWhere().has_value()) {
				process(node->getWhere().value().get(), context);
			}
			if (node->getGroupBy().has_value()) {
				process(node->getGroupBy().value().get(), context);
			}
			if (node->getHaving().has_value()) {
				process(node->getHaving().value().get(), context);
			}
			if (node->getOrderBy().has_value()) {
				process(node->getOrderBy().value().get(), context);
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
			return process(node->getQuery().get(), context);
		}*/


		antlrcpp::Any visitAliasedRelation(AliasedRelation* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getRelation().get(), context);
		}


		/*antlrcpp::Any visitSampledRelation(SampledRelation* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getRelation().get(), context);
			process(node->getSamplePercentage().get(), context);
			return antlrcpp::Any();
		}*/


		antlrcpp::Any visitJoin(Join* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft().get(), context);
			process(node->getRight().get(), context);

			if (node->getCriteria().has_value()) {
				auto criteria = std::dynamic_pointer_cast<JoinOn>(node->getCriteria().value());
				if (criteria) {
					process(criteria->getExpression().get(), context);
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
			for (auto groupingElement : node->getGroupingElements()) {
				process(groupingElement.get(), context);
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
			for (auto expression : node->getExpressions()) {
				process(expression.get(), context);
			}

			return antlrcpp::Any();
		}


		//antlrcpp::Any visitGroupingSets(GroupingSets* node, antlr4::ParserRuleContext* context) override
		//{
		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitInsert(Insert* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery().get(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitDelete(Delete* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getTable().get(), context);
		//	if (node->getWhere().has_value()) {
		//		process(node->getWhere().value().get(), context);
		//	}
		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitCreateTableAsSelect(CreateTableAsSelect* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery().get(), context);
		//	for (Property* property : node->getProperties()) {
		//		process(property, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitProperty(Property* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getName().get(), context);
		//	process(node->getValue().get(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitCreateView(CreateView* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery().get(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitSetSession(SetSession* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getValue().get(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitAddColumn(AddColumn* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getColumn().get(), context);

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
		//	process(node->getStatement().get(), context);

		//	for (ExplainOption* option : node->getOptions()) {
		//		process(option, context);
		//	}

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitQuantifiedComparisonExpression(QuantifiedComparisonExpression* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getValue().get(), context);
		//	process(node->getSubquery().get(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitExists(ExistsPredicate* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getSubquery().get(), context);

		//	return antlrcpp::Any();
		//}


		//antlrcpp::Any visitLateral(Lateral* node, antlr4::ParserRuleContext* context) override
		//{
		//	process(node->getQuery().get(), context);

		//	return AstVisitor::visitLateral(node, context);
		//}


	private:
		std::shared_ptr<spdlog::logger> _logger;
	};
}
