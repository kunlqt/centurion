#pragma once

#include "SearchIterator.h"
#include "StringValueSearchIterator.h"
#include "DoubleValueSearchIterator.h"
#include "BooleanValueSearchIterator.h"
#include "DoubleValueRangeSearchIterator.h"
#include "SearchIteratorOr.h"
#include "SearchIteratorIn.h"
#include "SearchIteratorAnd.h"
#include "AstVisitorImpl.h"
#include "DefaultVisitorResult.h"

namespace centurion {
	class DefaultVisitor : public AstVisitorImpl {
	public:
		DefaultVisitor()
		{
			log_ = spdlog::get("root")->clone("DefaultVisitor");
		}

		antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getSelect().value().get(), context);
			if (node->getFrom().has_value()) {
				process(node->getFrom().value().get(), context);
			}
			if (node->getWhere().has_value()) {
				auto visitorResult = dynamic_cast<DefaultVisitorResult*>(context);
				SearchIterator* searchIterator = process(node->getWhere().value().get(), context);
				visitorResult->setRootSearchIterator(searchIterator);
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

		antlrcpp::Any visitSingleColumn(SingleColumn* singleColumn, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitSingleColumn");
			auto visitorResult = dynamic_cast<DefaultVisitorResult*>(context);
			std::shared_ptr<QualifiedName> column = process(singleColumn->getExpression().get(), context);
			visitorResult->add(column->toString());
			return antlrcpp::Any();
		}

		antlrcpp::Any visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context) override
		{
			//auto deref = std::shared_ptr<DereferenceExpression>(node);
			auto result = DereferenceExpression::GetQualifiedName(node);
			log_->trace("visitDereferenceExpression: {}", result->toString());
			return result;
		}

		antlrcpp::Any visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitIdentifier: {}", node->getValue());
			return new QualifiedName(node->getValue());
		}

		antlrcpp::Any visitAllColumns(AllColumns* allColumns, antlr4::ParserRuleContext* context) override
		{
			auto visitorResult = dynamic_cast<DefaultVisitorResult*>(context);
			if (allColumns->getPrefix().has_value()) {
				visitorResult->add(allColumns->getPrefix().value()->toString());
			} 
			else
			{
				visitorResult->add("");
			}
			return antlrcpp::Any();
		}

		antlrcpp::Any visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitStringLiteral: {}", node->getValue());
			return node->getValue();
		}

		antlrcpp::Any visitDoubleLiteral(DoubleLiteral* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitDoubleLiteral: {}", node->getValue());
			return node->getValue();
		}

		antlrcpp::Any visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitDecimalLiteral: {}", node->getValue());
			return std::stod(node->getValue());
		}

		antlrcpp::Any visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitLongLiteral: {}", node->getValue());
			double result = node->getValue();
			return result;
		}

		antlrcpp::Any visitBooleanLiteral(BooleanLiteral* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitBooleanLiteral: {}", node->getValue());
			return node->getValue();
		}

		virtual antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* expr, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitArithmeticBinary operation");
			antlrcpp::Any left = process(expr->getLeft().get(), context);
			antlrcpp::Any right = process(expr->getRight().get(), context);
			if (left.is<double>() && right.is<double>()) {
				log_->trace("visitArithmeticBinary operation, operands of type Double");
				double l = left.as<double>();
				double r = right.as<double>();
				if (expr->getOperator() == ArithmeticBinaryExpression::Operator::ADD) {
					log_->trace("visitArithmeticBinary operation: {}(Double) + {}(Double)", l, r);
					return l + r;
				} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::SUBTRACT) {
					log_->trace("visitArithmeticBinary operation: {}(Double) - {}(Double)", l, r);
					return l - r;
				} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::MULTIPLY) {
					log_->trace("visitArithmeticBinary operation: {}(Double) * {}(Double)", l, r);
					return l * r;
				} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::DIVIDE) {
					log_->trace("visitArithmeticBinary operation: {}(Double) / {}(Double)", l, r);
					return l / r;
				}
			} else if (left.is<std::string>() && right.is<std::string>()) {
				log_->trace("visitArithmeticBinary operation: {}(String) + {}(String)", left.as<std::string>(), right.as<std::string>());
				return left.as<std::string>() + right.as<std::string>();
			}
			throw std::runtime_error("Unsupported operators for arithmetic binary");
		}

		antlrcpp::Any visitComparisonExpression(ComparisonExpression* comparisonExpr, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitComparisonExpression");
			antlrcpp::Any leftResult = process(comparisonExpr->getLeft().get(), context);
			antlrcpp::Any rightResult = process(comparisonExpr->getRight().get(), context);
			if (leftResult.is<std::shared_ptr<QualifiedName>>())
			{
				return visitFieldComparisonExpression(comparisonExpr->getOperator(), leftResult.as<std::shared_ptr<QualifiedName>>()->toString(), rightResult);
			}
			else if (rightResult.is<std::shared_ptr<QualifiedName>>())
			{
				return visitFieldComparisonExpression(comparisonExpr->getOperator(), rightResult.as<std::shared_ptr<QualifiedName>>()->toString(), leftResult);
			}
			throw std::runtime_error("Unsupported operands for comparison");

		}

		SearchIterator* visitFieldComparisonExpression(const ComparisonExpression::Operator& oper, const std::string& fieldName, const antlrcpp::Any& value) const
		{
			if (oper == ComparisonExpression::Operator::EQUAL)
			{
				if (value.is<std::string>())
				{
					return StringValueSearchIterator::eq(fieldName, value.as<std::string>());
				} else if (value.is<double>())
				{
					return DoubleValueSearchIterator::eq(fieldName, value.as<double>());
				} else if (value.is<bool>())
				{
					return BooleanValueSearchIterator::eq(fieldName, value.as<bool>());
				}
			} else if (oper == ComparisonExpression::Operator::GREATER_THAN)
			{
				if (value.is<double>())
				{
					return DoubleValueRangeSearchIterator::gt(fieldName, value.as<double>());
				} 
			} else if (oper == ComparisonExpression::Operator::LESS_THAN)
			{
				if (value.is<double>())
				{
					return DoubleValueRangeSearchIterator::lt(fieldName, value.as<double>());
				}
			} else if (oper == ComparisonExpression::Operator::GREATER_THAN_OR_EQUAL)
			{
				if (value.is<double>())
				{
					return DoubleValueRangeSearchIterator::gte(fieldName, value.as<double>());
				}
			} else if (oper == ComparisonExpression::Operator::LESS_THAN_OR_EQUAL)
			{
				if (value.is<double>())
				{
					return DoubleValueRangeSearchIterator::lte(fieldName, value.as<double>());
				}
			}
			throw std::runtime_error("Unsupported Comparison, only supported comparison is comparison between field and literal where literal is string or number");
		}

		virtual antlrcpp::Any visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitInPredicate");
			antlrcpp::Any identifier = process(node->getValue().get(), context);
			std::string fieldName;
			if (identifier.is<std::shared_ptr<QualifiedName>>()) {
				fieldName = (identifier.as<std::shared_ptr<QualifiedName>>()->toString());
			} else {
				throw std::runtime_error("Unsupported identifier for IN predicate");
			}
			std::vector<std::shared_ptr<antlrcpp::Any>> literals = process(node->getValueList().get(), context);
			std::vector<SearchIterator*> iterators;
			for (const auto& literal : literals)
			{
				if (literal->is<std::string>())
				{
					iterators.emplace_back(StringValueSearchIterator::eq(fieldName, literal->as<std::string>()));
				} else if (literal->is<double>())
				{
					iterators.emplace_back(DoubleValueSearchIterator::eq(fieldName, literal->as<double>()));
				} else if (literal->is<bool>())
				{
					iterators.emplace_back(BooleanValueSearchIterator::eq(fieldName, literal->as<bool>()));
				} else
				{
					throw std::runtime_error("Unsupported literal for IN operation");
				}
			}
			if (iterators.size() == 1)
			{
				return iterators.front();
			} else if (iterators.size() == 2) {
				return (SearchIterator*)(new SearchIteratorOr(iterators.front(), iterators.back()));
			}
			return (SearchIterator*)(new SearchIteratorIn(iterators));
		}

		virtual antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitInListExpression");
			std::vector<std::shared_ptr<antlrcpp::Any>> result;
			for (auto value : node->getValues()) {				
				result.emplace_back(std::make_shared<antlrcpp::Any>(process(value.get(), context)));
			}
			return result;
		}
		
		antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* logicalExpr, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitLogicalBinaryExpression operator");
			antlrcpp::Any left = process(logicalExpr->getLeft().get(), context);
			antlrcpp::Any right = process(logicalExpr->getRight().get(), context);
			if (logicalExpr->getOperator() == LogicalBinaryExpression::Operator::AND)
			{
				log_->trace("visitLogicalBinaryExpression operator AND");
				return (SearchIterator*)(new SearchIteratorAnd(left, right));
			} else if (logicalExpr->getOperator() == LogicalBinaryExpression::Operator::OR)
			{
				log_->trace("visitLogicalBinaryExpression operator OR");
				return (SearchIterator*)(new SearchIteratorOr(left, right));
			}
			throw std::runtime_error("Unsupported logical binary operator");
		}

	private:
		std::shared_ptr<spdlog::logger> log_;

	};
}
