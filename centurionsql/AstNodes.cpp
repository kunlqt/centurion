#include "AstNodes.h"
#include "AstVisitor.h"

namespace centurion {
	
	antlrcpp::Any Node::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context)
	{
		return visitor->visitNode(this, context);
	}

	antlrcpp::Any Expression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitExpression(this, context);
	}

	antlrcpp::Any Identifier::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitIdentifier(this, context);
	}

	antlrcpp::Any DereferenceExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitDereferenceExpression(this, context);
	}

	antlrcpp::Any Literal::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitLiteral(this, context);
	}

	antlrcpp::Any StringLiteral::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitStringLiteral(this, context);
	}

	antlrcpp::Any DecimalLiteral::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitDecimalLiteral(this, context);
	}

	antlrcpp::Any DoubleLiteral::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitDoubleLiteral(this, context);
	}

	antlrcpp::Any LongLiteral::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitLongLiteral(this, context);
	}

	antlrcpp::Any BooleanLiteral::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitBooleanLiteral(this, context);
	}

	antlrcpp::Any ArithmeticBinaryExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitArithmeticBinary(this, context);
	}

	antlrcpp::Any ArithmeticUnaryExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitArithmeticUnary(this, context);
	}

	antlrcpp::Any ComparisonExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitComparisonExpression(this, context);
	}

	antlrcpp::Any InListExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitInListExpression(this, context);
	}

	antlrcpp::Any LogicalBinaryExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitLogicalBinaryExpression(this, context);
	}

	antlrcpp::Any NotExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitNotExpression(this, context);
	}

	antlrcpp::Any Statement::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitStatement(this, context);
	}

	antlrcpp::Any Relation::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitRelation(this, context);
	}

	antlrcpp::Any QueryBody::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitQueryBody(this, context);
	}

	antlrcpp::Any SortItem::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitSortItem(this, context);
	}

	antlrcpp::Any OrderBy::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitOrderBy(this, context);
	}

	antlrcpp::Any Query::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitQuery(this, context);
	}

	Query::~Query()
	{
		if (with_.has_value()) {
			With* with = with_.value();
			delete with;
		}
		delete queryBody_;
		if (orderBy_.has_value()) {
			delete orderBy_.value();
		}
	}

	antlrcpp::Any WithQuery::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitWithQuery(this, context);
	}

	antlrcpp::Any With::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitWith(this, context);
	}

	antlrcpp::Any SubqueryExpression::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitSubqueryExpression(this, context);
	}

	antlrcpp::Any SingleColumn::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitSingleColumn(this, context);
	}

	antlrcpp::Any AliasedRelation::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitAliasedRelation(this, context);
	}

	antlrcpp::Any AllColumns::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitAllColumns(this, context);
	}

	antlrcpp::Any GroupingElement::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitGroupingElement(this, context);
	}
	   
	antlrcpp::Any GroupBy::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitGroupBy(this, context);
	}

	antlrcpp::Any GroupingOperation::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitGroupingOperation(this, context);
	}

	antlrcpp::Any InPredicate::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitInPredicate(this, context);
	}

	antlrcpp::Any Select::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitSelect(this, context);
	}

	antlrcpp::Any IsNotNullPredicate::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitIsNotNullPredicate(this, context);
	}

	antlrcpp::Any IsNullPredicate::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitIsNullPredicate(this, context);
	}

	antlrcpp::Any Table::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitTable(this, context);
	}

	antlrcpp::Any Join::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitJoin(this, context);
	}

	antlrcpp::Any QuerySpecification::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitQuerySpecification(this, context);
	}

	antlrcpp::Any ShowStats::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitShowStats(this, context);
	}

	antlrcpp::Any SimpleGroupBy::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitSimpleGroupBy(this, context);
	}

	antlrcpp::Any LikePredicate::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitLikePredicate(this, context);
	}

	antlrcpp::Any BetweenPredicate::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitBetweenPredicate(this, context);
	}

	LogicalBinaryExpression::Operator LogicalBinaryExpression::Operator::AND(And, "AND");
	LogicalBinaryExpression::Operator LogicalBinaryExpression::Operator::OR(Or, "OR");

	ArithmeticBinaryExpression::Operator ArithmeticBinaryExpression::Operator::ADD(Add, "+");
	ArithmeticBinaryExpression::Operator ArithmeticBinaryExpression::Operator::SUBTRACT(Subtract, "-");
	ArithmeticBinaryExpression::Operator ArithmeticBinaryExpression::Operator::MULTIPLY(Multiply, "*");
	ArithmeticBinaryExpression::Operator ArithmeticBinaryExpression::Operator::DIVIDE(Divide, "/");
	ArithmeticBinaryExpression::Operator ArithmeticBinaryExpression::Operator::MODULUS(Modulus, "%");

	ComparisonExpression::Operator ComparisonExpression::Operator::EQUAL(Equal, "=");
	ComparisonExpression::Operator ComparisonExpression::Operator::NOT_EQUAL(NotEqual, "<>");
	ComparisonExpression::Operator ComparisonExpression::Operator::LESS_THAN(LessThan, "<");
	ComparisonExpression::Operator ComparisonExpression::Operator::LESS_THAN_OR_EQUAL(LessThanOrEqual, "<=");
	ComparisonExpression::Operator ComparisonExpression::Operator::GREATER_THAN(GreaterThan, ">");
	ComparisonExpression::Operator ComparisonExpression::Operator::GREATER_THAN_OR_EQUAL(GreaterThanOrEqual, ">=");
	ComparisonExpression::Operator ComparisonExpression::Operator::IS_DISTINCT_FROM(IsDistinctFrom, "IS DISTINCT FROM");
}
