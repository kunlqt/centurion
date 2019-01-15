#pragma once

#include "QualifiedNameBuilder.h"
#include "SearchIterator.h"
#include "StringValueSearchIterator.h"
#include "DoubleValueSearchIterator.h"
#include "BooleanValueSearchIterator.h"
#include "DoubleValueRangeSearchIterator.h"
#include "SearchIteratorOr.h"
#include "SearchIteratorIn.h"
#include "SearchIteratorAnd.h"
#include "AstVisitorImpl.h"

namespace centurion {
	class QualifiedNameBuilderVisitor : public AstVisitorImpl {
	public:
		QualifiedNameBuilderVisitor()
		{
			log_ = spdlog::get("root")->clone("QualifiedNameBuilderVisitor");
		}

		antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			process(node->getSelect().value(), context);
			if (node->getFrom().has_value()) {
				process(node->getFrom().value(), context);
			}
			if (node->getWhere().has_value()) {
				auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
				builder->setRootSearchIterator(process(node->getWhere().value(), context));
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

		antlrcpp::Any visitSingleColumn(SingleColumn* singleColumn, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitSingleColumn");
			auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
			builder->add(process(singleColumn->getExpression(), context));
			return antlrcpp::Any();
		}

		antlrcpp::Any visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context) override
		{
			auto result = std::shared_ptr<QualifiedName>(DereferenceExpression::getQualifiedName(node));
			log_->trace("visitDereferenceExpression: {}", result->toString());
			return result;
		}

		antlrcpp::Any visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitIdentifier: {}", node->getValue());
			return std::make_shared<QualifiedName>(node->getValue());
		}

		antlrcpp::Any visitAllColumns(AllColumns* allColumns, antlr4::ParserRuleContext* context) override
		{
			auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
			if (allColumns->getPrefix().has_value()) {
				builder->add(allColumns->getPrefix().value());
			} 
			else
			{
				builder->add(std::make_shared<QualifiedName>());
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
			antlrcpp::Any left = process(expr->getLeft(), context);
			antlrcpp::Any right = process(expr->getRight(), context);
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
			antlrcpp::Any leftResult = process(comparisonExpr->getLeft(), context);
			antlrcpp::Any rightResult = process(comparisonExpr->getRight(), context);
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

		SearchIterator* visitFieldComparisonExpression(const ComparisonExpression::Operator oper, std::string fieldName, const antlrcpp::Any& value) const
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
			antlrcpp::Any identifier = process(node->getValue(), context);
			std::string fieldName;
			if (identifier.is<std::shared_ptr<QualifiedName>>()) {
				fieldName = (identifier.as<std::shared_ptr<QualifiedName>>()->toString());
			} else {
				throw std::runtime_error("Unsupported identifier for IN predicate");
			}
			antlrcpp::Any values = process(node->getValueList(), context);
			std::vector<SearchIterator*> iterators;
			std::vector<antlrcpp::Any> literals = values.as<std::vector<antlrcpp::Any>>();
			for (auto literal : literals)
			{
				SearchIterator* searchIterator = nullptr;
				if (literal.is<std::string>())
				{
					iterators.emplace_back(StringValueSearchIterator::eq(fieldName, literal.as<std::string>()));
				} else if (literal.is<double>())
				{
					iterators.emplace_back(DoubleValueSearchIterator::eq(fieldName, literal.as<double>()));
				} else if (literal.is<bool>())
				{
					iterators.emplace_back(BooleanValueSearchIterator::eq(fieldName, literal.as<bool>()));
				} else
				{
					throw std::runtime_error("Unsupported literal for IN operation");
				}
			}
			if (iterators.size() == 1)
			{
				return iterators.front();
			} else if (iterators.size() == 2) {
				return new SearchIteratorOr(iterators.front(), iterators.back());
			}
			return new SearchIteratorIn(iterators);
		}

		virtual antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitInListExpression");
			std::vector<antlrcpp::Any> result;
			for (Expression* value : node->getValues()) {				
				result.emplace_back(std::move(process(value, context)));
			}
			return result;
		}
		
		antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* logicalExpr, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitLogicalBinaryExpression operator");
			antlrcpp::Any left = process(logicalExpr->getLeft(), context);
			antlrcpp::Any right = process(logicalExpr->getRight(), context);
			if (logicalExpr->getOperator() == LogicalBinaryExpression::Operator::AND)
			{
				log_->trace("visitLogicalBinaryExpression operator AND");
				return new SearchIteratorAnd(left, right);
			} else if (logicalExpr->getOperator() == LogicalBinaryExpression::Operator::OR)
			{
				log_->trace("visitLogicalBinaryExpression operator OR");
				return new SearchIteratorOr(left, right);
			}
			throw std::runtime_error("Unsupported logical binary operator");
		}

	private:
		std::shared_ptr<spdlog::logger> log_;

	};
}
