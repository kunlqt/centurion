#pragma once

#include "StackableAstVisitor.h"
#include "StringValueSearchIterator.h"
#include "SearchIteratorAnd.h"
#include "SearchIteratorOr.h"
#include <fmt/ostream.h>

namespace centurion {
	class DefaultTraversalVisitor : public StackableAstVisitor {
		const DatabaseManager& dbm_;
	public:
		DefaultTraversalVisitor(const DatabaseManager& dbm)
		: StackableAstVisitor()
		, dbm_(dbm) {}

	
		virtual antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* expr, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitArithmeticBinary operation: {}", expr->getOperator());
			antlrcpp::Any left = process(expr->getLeft(), context);
			antlrcpp::Any right = process(expr->getRight(), context);
			if (expr->getOperator() == ArithmeticBinaryExpression::Operator::ADD)
			{
				if (left.is<double>() && right.is<double>()) {
					return left.as<double>() + right.as<double>();
				} else if (left.is<double>() && right.is<long>()) {
					return left.as<double>() + right.as<long>();
				} else if (left.is<long>() && right.is<double>()) {
					return left.as<long>() + right.as<double>();
				} else if (left.is<long>() && right.is<long>()) {
					return left.as<long>() + right.as<long>();
				}
			} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::SUBTRACT)
			{
				if (left.is<double>() && right.is<double>()) {
					return left.as<double>() - right.as<double>();
				} else if (left.is<double>() && right.is<long>()) {
					return left.as<double>() - right.as<long>();
				} else if (left.is<long>() && right.is<double>()) {
					return left.as<long>() - right.as<double>();
				} else if (left.is<long>() && right.is<long>()) {
					return left.as<long>() - right.as<long>();
				}
			} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::MULTIPLY)
			{
				if (left.is<double>() && right.is<double>()) {
					return left.as<double>() * right.as<double>();
				} else if (left.is<double>() && right.is<long>()) {
					return left.as<double>() * right.as<long>();
				} else if (left.is<long>() && right.is<double>()) {
					return left.as<long>() * right.as<double>();
				} else if (left.is<long>() && right.is<long>()) {
					return left.as<long>() * right.as<long>();
				}
			} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::DIVIDE)
			{
				if (left.is<double>() && right.is<double>()) {
					return left.as<double>() / right.as<double>();
				} else if (left.is<double>() && right.is<long>()) {
					return left.as<double>() / right.as<long>();
				} else if (left.is<long>() && right.is<double>()) {
					return left.as<long>() / right.as<double>();
				} else if (left.is<long>() && right.is<long>()) {
					return left.as<long>() / right.as<long>();
				}
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitComparisonExpression(ComparisonExpression* comparisonExpr, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitComparisonExpression operation: {}", comparisonExpr->getOperator());

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
			} else if (comparisonExpr->getOperator() == ComparisonExpression::Operator::GREATER_THAN)
			{
				if (right.is<double>())
				{
					return (SearchIterator*)DoubleValueSearchIterator::gt(dbm_.idvs(), idx, right.as<double>());
				} else if (right.is<long>())
				{
					return (SearchIterator*)DoubleValueSearchIterator::gt(dbm_.idvs(), idx, right.as<long>());
				}
			} else if (comparisonExpr->getOperator() == ComparisonExpression::Operator::LESS_THAN)
			{
				if (right.is<double>())
				{
					return (SearchIterator*)DoubleValueSearchIterator::lt(dbm_.idvs(), idx, right.as<double>());
				} else if (right.is<long>())
				{
					return (SearchIterator*)DoubleValueSearchIterator::lt(dbm_.idvs(), idx, right.as<long>());
				}
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* logicalExpr, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitLogicalBinaryExpression operator: {}", logicalExpr->getOperator());

			antlrcpp::Any left = process(logicalExpr->getLeft(), context);
			antlrcpp::Any right = process(logicalExpr->getRight(), context);
			if (logicalExpr->getOperator() == LogicalBinaryExpression::Operator::AND)
			{
				return new SearchIteratorAnd(left, right);
			} else if (logicalExpr->getOperator() == LogicalBinaryExpression::Operator::OR)
			{
				return new SearchIteratorOr(left, right);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitQuery(Query* query, antlr4::ParserRuleContext* context) override {
			auto console = spdlog::get("console");
			console->trace("visitQuery");

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
			auto console = spdlog::get("console");
			console->trace("visitWith");

			for (const auto& query : with->getQueries()) {
				process(query, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitWithQuery");

			return process(node->getQuery(), context);
		}

		virtual antlrcpp::Any visitSelect(Select* select, antlr4::ParserRuleContext* context) override 
		{
			auto console = spdlog::get("console");
			console->trace("visitSelect");

			for (SelectItem* selectItem : select->getSelectItems()) {
				process(selectItem, context);
			}
			return antlrcpp::Any();
		}



		virtual antlrcpp::Any visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitStringLiteral: {}", node->getValue());

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
			auto console = spdlog::get("console");
			console->trace("visitDoubleLiteral: {}", node->getValue());

			return node->getValue();
		}

		virtual antlrcpp::Any visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitDecimalLiteral: {}", node->getValue());

			return std::stod(node->getValue());
		}

		virtual antlrcpp::Any visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitLongLiteral: {}", node->getValue());

			return node->getValue();
		}


		virtual antlrcpp::Any visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitSingleColumn");

			antlrcpp::Any result = process(node->getExpression(), context);
			return result;
		}

		virtual antlrcpp::Any visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitGroupingOperation");

			for (Expression* columnArgument : node->getGroupingColumns()) {
				process(columnArgument, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitIdentifier(Identifier* identifier, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitIdentifier: {}", identifier->getValue());

			return 	identifier->getValue();
		}

		virtual antlrcpp::Any visitDereferenceExpression(DereferenceExpression* dereferenceExpression, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			std::string result = "/" + dereferenceExpression->getField()->getValue();
			console->trace("visitDereferenceExpression: {}", result);			

			if (dereferenceExpression->getBase() != nullptr)
			{
				return process(dereferenceExpression->getBase(), context).as<std::string>() + result;
			} 
			return result;
		}

		virtual antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitInListExpression");

			for (Expression* value : node->getValues()) {
				process(value, context);
			}
			return antlrcpp::Any();

		}

		virtual antlrcpp::Any visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitInPredicate");

			process(node->getValue(), context);
			process(node->getValueList(), context);
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitArithmeticUnary");

			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitNotExpression");

			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitIsNotNullPredicate");

			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitIsNullPredicate");

			return process(node->getValue(), context);
		}


		virtual antlrcpp::Any visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitSubqueryExpression");

			return process(node->getQuery(), context);
		}

		virtual antlrcpp::Any visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitOrderBy");

			for (SortItem* sortItem : node->getSortItems()) {
				process(sortItem, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitSortItem(SortItem* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitSortItem");

			return process(node->getSortKey(), context);
		}

		virtual antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitQuerySpecification");

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
			auto console = spdlog::get("console");
			console->trace("visitAliasedRelation");

			return process(node->getRelation(), context);
		}

		virtual antlrcpp::Any visitJoin(Join* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitJoin");

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
			auto console = spdlog::get("console");
			console->trace("visitGroupBy");

			for (const auto& groupingElement : node->getGroupingElements()) {
				process(groupingElement, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context) override
		{
			auto console = spdlog::get("console");
			console->trace("visitSimpleGroupBy");

			for (const auto& expression : node->getExpressions()) {
				process(expression, context);
			}
			return antlrcpp::Any();
		}
		
	};
}
