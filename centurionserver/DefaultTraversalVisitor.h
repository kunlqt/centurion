#pragma once

#include "TraversalVisitorResult.h"
#include "StackableAstVisitor.h"
#include "StringValueSearchIterator.h"
#include "SearchIteratorAnd.h"
#include "SearchIteratorOr.h"
#include <fmt/ostream.h>

namespace centurion {
	
	class DefaultTraversalVisitor : public StackableAstVisitor {
		const DatabaseManager& dbm_;			
		std::shared_ptr<spdlog::logger> log_;

	public:
		DefaultTraversalVisitor(const DatabaseManager& dbm)
		:
		dbm_(dbm) 
		{
			log_ = spdlog::get("root")->clone("defaultastvisitor");
		}

		 bool CastToDouble(antlrcpp::Any val, double& target) const
		{
			if (val.is<DoubleLiteral*>()) {
				target = val.as<DoubleLiteral*>()->getValue(); 
				return true;
			}
			if (val.is<DecimalLiteral*>()) {
				std::stod(val.as<DecimalLiteral*>()->getValue()); 
				return true;
			}
			if (val.is<LongLiteral*>()) {
				target = val.as<LongLiteral*>()->getValue();
				return true;
			}
			return false;
		}
		virtual antlrcpp::Any visitArithmeticBinary(ArithmeticBinaryExpression* expr, antlr4::ParserRuleContext* context) override
		{	
			log_->trace("visitArithmeticBinary operation: {}", expr->getOperator());
			antlrcpp::Any left = process(expr->getLeft(), context);
			antlrcpp::Any right = process(expr->getRight(), context);
			double leftVal;
			double rightVal;
			if (CastToDouble(left, leftVal) && CastToDouble(right, rightVal)) {
				if (expr->getOperator() == ArithmeticBinaryExpression::Operator::ADD) {
					return new DoubleLiteral(expr->getLeft()->getLocation(), leftVal + rightVal);
				} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::SUBTRACT) {
					return new DoubleLiteral(expr->getLeft()->getLocation(), leftVal - rightVal);
				} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::MULTIPLY) {
					return new DoubleLiteral(expr->getLeft()->getLocation(), leftVal * rightVal);
				} else if (expr->getOperator() == ArithmeticBinaryExpression::Operator::DIVIDE) {
					return new DoubleLiteral(expr->getLeft()->getLocation(), leftVal / rightVal);
				}
			} else if (left.is<StringLiteral*>() && right.is<StringLiteral*>()) {
				return new StringLiteral(expr->getLeft()->getLocation(), left.as<StringLiteral*>()->getValue() + right.as<StringLiteral*>()->getValue());
			}			
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitComparisonExpression(ComparisonExpression* comparisonExpr, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitComparisonExpression operation: {}", comparisonExpr->getOperator());
			antlrcpp::Any leftResult = process(comparisonExpr->getLeft(), context);
			antlrcpp::Any rightResult = process(comparisonExpr->getRight(), context);			
			if (leftResult.is<FieldIdentifier*>(false) && rightResult.is<Literal*>(true)) {				
				return visitFieldComparisonExpression(comparisonExpr->getOperator(), dbm_.indexNameStore().getIndexId(leftResult.as<FieldIdentifier*>()->toString()), rightResult);
			} else if (leftResult.is<Literal*>(true) && rightResult.is<FieldIdentifier*>(false)) {
				return visitFieldComparisonExpression(comparisonExpr->getOperator(), dbm_.indexNameStore().getIndexId(rightResult.as<FieldIdentifier*>()->toString()), leftResult);
			} else {
				throw std::runtime_error("Unsupported Comparison, only supported comparison is comparison between field and literal");
			}
		}

		antlrcpp::Any visitFieldComparisonExpression(const ComparisonExpression::Operator oper, const IndexId idx, const antlrcpp::Any& value) const
		{
			if (oper == ComparisonExpression::Operator::EQUAL)
			{
				if (value.is<StringLiteral*>())
				{
					return (SearchIterator*)(StringValueSearchIterator::eq(dbm_.isvs(), idx, value.as<StringLiteral*>()->getValue()));
				} else if (value.is<DecimalLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::eq(dbm_.idvs(), idx, std::stod(value.as<DecimalLiteral*>()->getValue())));
				} else if (value.is<DoubleLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::eq(dbm_.idvs(), idx, value.as<DoubleLiteral*>()->getValue()));
				} else if (value.is<LongLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::eq(dbm_.idvs(), idx, value.as<LongLiteral*>()->getValue()));
				} else if (value.is<BooleanLiteral*>())
				{
					return (SearchIterator*)(BooleanValueSearchIterator::eq(dbm_.ibvs(), idx, value.as<BooleanLiteral*>()->getValue()));
				}
			} else if (oper == ComparisonExpression::Operator::GREATER_THAN)
			{
				if (value.is<DecimalLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::gt(dbm_.idvs(), idx, std::stod(value.as<DecimalLiteral*>()->getValue())));
				} else if (value.is<DoubleLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::gt(dbm_.idvs(), idx, value.as<DoubleLiteral*>()->getValue()));
				} else if (value.is<LongLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::gt(dbm_.idvs(), idx, value.as<LongLiteral*>()->getValue()));
				}
			} else if (oper == ComparisonExpression::Operator::LESS_THAN)
			{
				if (value.is<DecimalLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::lt(dbm_.idvs(), idx, std::stod(value.as<DecimalLiteral*>()->getValue())));
				} else if (value.is<DoubleLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::lt(dbm_.idvs(), idx, value.as<DoubleLiteral*>()->getValue()));
				} else if (value.is<LongLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::lt(dbm_.idvs(), idx, value.as<LongLiteral*>()->getValue()));
				}
			} else if (oper == ComparisonExpression::Operator::GREATER_THAN_OR_EQUAL)
			{
				if (value.is<DecimalLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::gte(dbm_.idvs(), idx, std::stod(value.as<DecimalLiteral*>()->getValue())));
				} else if (value.is<DoubleLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::gte(dbm_.idvs(), idx, value.as<DoubleLiteral*>()->getValue()));
				} else if (value.is<LongLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::gte(dbm_.idvs(), idx, value.as<LongLiteral*>()->getValue()));
				}
			} else if (oper == ComparisonExpression::Operator::LESS_THAN_OR_EQUAL)
			{
				if (value.is<DecimalLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::lte(dbm_.idvs(), idx, std::stod(value.as<DecimalLiteral*>()->getValue())));
				} else if (value.is<DoubleLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::lte(dbm_.idvs(), idx, value.as<DoubleLiteral*>()->getValue()));
				} else if (value.is<LongLiteral*>())
				{
					return (SearchIterator*)(DoubleValueSearchIterator::lte(dbm_.idvs(), idx, value.as<LongLiteral*>()->getValue()));
				}
			}
			throw std::runtime_error("Unsupported Comparison, only supported comparison is comparison between field and literal where literal is string or number");
		}

		virtual antlrcpp::Any visitLogicalBinaryExpression(LogicalBinaryExpression* logicalExpr, antlr4::ParserRuleContext* context) override
		{
			
			log_->trace("visitLogicalBinaryExpression operator: {}", logicalExpr->getOperator());

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

		virtual antlrcpp::Any visitQuery(Query* query, antlr4::ParserRuleContext* context) override 
		{			
			log_->trace("visitQuery");
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
			log_->trace("visitWith");
			for (const auto& query : with->getQueries()) {
				process(query, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitWithQuery(WithQuery* node, antlr4::ParserRuleContext* context) override
		{
			
			log_->trace("visitWithQuery");
			return process(node->getQuery(), context);
		}

		virtual antlrcpp::Any visitAllColumns(AllColumns* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitAllColumns");			
			return std::string("/");
		}

		virtual antlrcpp::Any visitSelect(Select* select, antlr4::ParserRuleContext* context) override 
		{	
			log_->trace("visitSelect");
			auto result = new SelectedFields;
			for (SelectItem* selectItem : select->getSelectItems()) {
				auto processResult = process(selectItem, context);
				if (processResult.is<FieldIdentifier*>()) {					
					result->emplace_back(processResult.as<FieldIdentifier*>()->toString());
				}
			}
			return result;
		}

		virtual antlrcpp::Any visitStringLiteral(StringLiteral* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitStringLiteral: {}", node->getValue());
			return node;
		}

		virtual antlrcpp::Any visitDoubleLiteral(DoubleLiteral* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitDoubleLiteral: {}", node->getValue());
			return node;
		}

		virtual antlrcpp::Any visitDecimalLiteral(DecimalLiteral* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitDecimalLiteral: {}", node->getValue());
			return node;
		}

		virtual antlrcpp::Any visitLongLiteral(LongLiteral* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitLongLiteral: {}", node->getValue());
			return node;
		}

		virtual antlrcpp::Any visitBooleanLiteral(BooleanLiteral* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitBooleanLiteral: {}", node->getValue());
			return node;
		}

		virtual antlrcpp::Any visitSingleColumn(SingleColumn* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitSingleColumn");
			return process(node->getExpression(), context);
		}

		virtual antlrcpp::Any visitGroupingOperation(GroupingOperation* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitGroupingOperation");
			for (Expression* columnArgument : node->getGroupingColumns()) {
				process(columnArgument, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitIdentifier(Identifier* identifier, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitIdentifier: {}", identifier->getValue());
			return identifier->getValue();
		}

		
		virtual antlrcpp::Any visitDereferenceExpression(DereferenceExpression* expr, antlr4::ParserRuleContext* context) override
		{						
			log_->trace("visitDereferenceExpression: {}", expr->getField()->getValue());
			if (expr->getBase() != nullptr)
			{
				antlrcpp::Any b = process(expr->getBase(), context);
				if (b.is<FieldIdentifier*>())
				{
					return b.as<FieldIdentifier*>()->AddComponent(expr->getField());
				} else if (b.is<std::string>()) {
					return new FieldIdentifier(
						expr->getBase()->getLocation(), 
						new Identifier(expr->getBase()->getLocation(), b.as<std::string>(), false), 
						expr->getField()
					);
				}				
			} 
			throw std::runtime_error("missing base");
		}

		virtual antlrcpp::Any visitInPredicate(InPredicate* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitInPredicate");
			antlrcpp::Any identifier = process(node->getValue(), context);
			antlrcpp::Any values = process(node->getValueList(), context);
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitInListExpression(InListExpression* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitInListExpression");
			std::vector<Literal*> result;
			for (Expression* value : node->getValues()) {
				antlrcpp::Any listExpression = process(value, context);
				if (listExpression.is<Literal*>(true)) {
					result.push_back(listExpression.as<Literal*>());
				}
			}
			return result;
		}

		virtual antlrcpp::Any visitArithmeticUnary(ArithmeticUnaryExpression* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitArithmeticUnary");
			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitNotExpression(NotExpression* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitNotExpression");
			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitIsNotNullPredicate(IsNotNullPredicate* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitIsNotNullPredicate");
			return process(node->getValue(), context);
		}

		virtual antlrcpp::Any visitIsNullPredicate(IsNullPredicate* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitIsNullPredicate");
			return process(node->getValue(), context);
		}


		virtual antlrcpp::Any visitSubqueryExpression(SubqueryExpression* node, antlr4::ParserRuleContext* context) override
		{
			log_->trace("visitSubqueryExpression");
			return process(node->getQuery(), context);
		}

		virtual antlrcpp::Any visitOrderBy(OrderBy* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitOrderBy");
			for (SortItem* sortItem : node->getSortItems()) {
				process(sortItem, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitSortItem(SortItem* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitSortItem");
			return process(node->getSortKey(), context);
		}

		virtual antlrcpp::Any visitQuerySpecification(QuerySpecification* node, antlr4::ParserRuleContext* context) override
		{
			auto result = std::make_shared<TraversalVisitorResult>();
			log_->trace("visitQuerySpecification");			
			result->selectFields = process(node->getSelect().value(), context);
			if (node->getFrom().has_value()) {
				process(node->getFrom().value(), context);
			}			
			if (node->getWhere().has_value()) {
				result->searchRootIterator = process(node->getWhere().value(), context);
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
			log_->trace("visitAliasedRelation");
			return process(node->getRelation(), context);
		}

		virtual antlrcpp::Any visitJoin(Join* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitJoin");
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
			log_->trace("visitGroupBy");
			for (const auto& groupingElement : node->getGroupingElements()) {
				process(groupingElement, context);
			}
			return antlrcpp::Any();
		}

		virtual antlrcpp::Any visitSimpleGroupBy(SimpleGroupBy* node, antlr4::ParserRuleContext* context) override
		{			
			log_->trace("visitSimpleGroupBy");
			for (const auto& expression : node->getExpressions()) {
				process(expression, context);
			}
			return antlrcpp::Any();
		}
		
	};
}
