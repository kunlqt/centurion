#pragma once

#include "AstVisitorImpl.h"
#include "StringValueSearchIterator.h"
#include "SearchIteratorAnd.h"

namespace centurion {
	class DefaultTraversalVisitor : public AstVisitorImpl {
		const DatabaseManager& dbm_;
	public:
		DefaultTraversalVisitor(const DatabaseManager& dbm)
		: 
			AstVisitorImpl()
		, dbm_(dbm) {}

	
		virtual antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft(), context);
			process(node->getRight(), context);
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitComparisonExpression(ComparisonExpression* comparisonExpr, antlr4::ParserRuleContext* context) override
		{
			antlrcpp::Any left = process(comparisonExpr->getLeft(), context);
			antlrcpp::Any right = process(comparisonExpr->getRight(), context);
			std::string indexName = "/" + left.as<std::string>();
			IndexId idx = dbm_.indexNameStore().getIndexId(indexName);
			if (comparisonExpr->getOperator() == ComparisonExpression::Operator::EQUAL)
			{
				if (right.is<std::string>())
				{
					return (SearchIterator*)StringValueSearchIterator::eq(dbm_.isvs(), idx, right.as<std::string>());
				} else if (right.is<double>())
				{
					return (SearchIterator*)DoubleValueSearchIterator::eq(dbm_.idvs(), idx, right.as<double>());
				} else if (right.is<long>())
				{
					return (SearchIterator*)DoubleValueSearchIterator::eq(dbm_.idvs(), idx, right.as<long>());
				}
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* logicalExpr, antlr4::ParserRuleContext* context) override
		{
			antlrcpp::Any left = process(logicalExpr->getLeft(), context);
			antlrcpp::Any right = process(logicalExpr->getRight(), context);
			if (logicalExpr->getOperator() == LogicalBinaryExpression::AND)
			{
				return new SearchIteratorAnd(left, right);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitQuery(Query* query, antlr4::ParserRuleContext* context) override {
			if (query->getWith().has_value()) {
				process(query->getWith().value(), context);
			}
			antlrcpp::Any result = process(query->getQueryBody(), context);
			if (query->getOrderBy().has_value()) {
				process(query->getOrderBy().value(), context);
			}
			return result;
		}

		virtual antlrcpp::Any visitWith(With* with, antlr4::ParserRuleContext* context) override
		{
			for (const auto& query : with->getQueries()) {
				process(query, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery(), context);
		}

		virtual antlrcpp::Any visitSelect(Select* select, antlr4::ParserRuleContext* context) override {
			for (SelectItem* selectItem : select->getSelectItems()) {
				process(selectItem, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context) override
		{
			auto s = node->getValue();
			if (s.size() >= 2)
			{
				if (s.front() == '\'' && s.back() == '\'')
				{
					return s.substr(1, s.size() - 2);
				}
			}
			return s;
		}

		virtual antlrcpp::Any visitDoubleLiteral(DoubleLiteral* node, antlr4::ParserRuleContext* context) override
		{
			return node->getValue();
		}

		virtual antlrcpp::Any visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context) override
		{
			return node->getValue();
		}

		virtual antlrcpp::Any visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context) override
		{
			return node->getValue();
		}


		virtual antlrcpp::Any visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context) override
		{
			antlrcpp::Any result = process(node->getExpression(), context);
			return result;
		}

		virtual antlrcpp::Any visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* columnArgument : node->getGroupingColumns()) {
				process(columnArgument, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitIdentifier(Identifier* identifier, antlr4::ParserRuleContext* context) override
		{
			return 	identifier->getValue();
		}

		virtual antlrcpp::Any visitDereferenceExpression(DereferenceExpression* dereferenceExpression, antlr4::ParserRuleContext* context) override
		{
			std::string result = "/" + dereferenceExpression->getField()->getValue();
			if (dereferenceExpression->getBase() != nullptr)
			{
				return process(dereferenceExpression->getBase(), context).as<std::string>() + result;
			} 
			return result;
		}

		virtual antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context) override
		{
			for (Expression* value : node->getValues()) {
				process(value, context);
			}
			return antlrcpp::Any();

		}

		virtual antlrcpp::Any visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getValue(), context);
			process(node->getValueList(), context);
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getValue(), context);
		}


		virtual antlrcpp::Any visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getQuery(), context);
		}

		virtual antlrcpp::Any visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context) override
		{
			for (SortItem* sortItem : node->getSortItems()) {
				process(sortItem, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitSortItem(SortItem* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getSortKey(), context);
		}

		virtual antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			antlrcpp::Any result;
			process(node->getSelect().value(), context);
			if (node->getFrom().has_value()) {
				process(node->getFrom().value(), context);
			}
			if (node->getWhere().has_value()) {
				result = process(node->getWhere().value(), context);
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
			return result;
		}

		virtual antlrcpp::Any visitAliasedRelation(AliasedRelation* node, antlr4::ParserRuleContext* context) override
		{
			return process(node->getRelation(), context);
		}

		virtual antlrcpp::Any visitJoin(Join* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getLeft(), context);
			process(node->getRight(), context);

			if (node->getCriteria().has_value()) {
				JoinOn* joinOn = dynamic_cast<JoinOn*>(node->getCriteria().value());
				if (joinOn != nullptr)
				{
					process(joinOn->getExpression(), context);
				}
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitGroupBy(GroupBy* node, antlr4::ParserRuleContext* context) override
		{
			for (const auto& groupingElement : node->getGroupingElements()) {
				process(groupingElement, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context) override
		{
			for (const auto& expression : node->getExpressions()) {
				process(expression, context);
			}
			return antlrcpp::Any();
		}

		
	};
}
