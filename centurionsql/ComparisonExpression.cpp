#include "ComparisonExpression.h"

namespace centurion {

	ComparisonExpression::Operator ComparisonExpression::Operator::EQUAL("=");
	ComparisonExpression::Operator ComparisonExpression::Operator::NOT_EQUAL("<>");
	ComparisonExpression::Operator ComparisonExpression::Operator::LESS_THAN("<");
	ComparisonExpression::Operator ComparisonExpression::Operator::LESS_THAN_OR_EQUAL("<=");
	ComparisonExpression::Operator ComparisonExpression::Operator::GREATER_THAN(">");
	ComparisonExpression::Operator ComparisonExpression::Operator::GREATER_THAN_OR_EQUAL(">=");
	ComparisonExpression::Operator ComparisonExpression::Operator::IS_DISTINCT_FROM("IS DISTINCT FROM");

};
