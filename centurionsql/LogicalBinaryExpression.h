#pragma once

#ifndef LogicalBinaryExpression_h
#define LogicalBinaryExpression_h

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {
	class LogicalBinaryExpression : public Expression {		
	public:
		enum Operator { AND, OR };

		LogicalBinaryExpression(Operator oper, Expression* left, Expression* right)
			:
			LogicalBinaryExpression(std::optional<NodeLocation>(), oper, left, right) {
		}
		
		LogicalBinaryExpression(NodeLocation location, Operator oper, Expression* left, Expression* right)
			:
			LogicalBinaryExpression(std::make_optional(location), oper, left, right) {
		}

		LogicalBinaryExpression(std::optional<NodeLocation> location, Operator oper, Expression* left, Expression* right) 
			: 
			Expression(location), operator_(oper), left_(left), right_(right)  {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitLogicalBinaryExpression(this, context);
		}

		virtual std::string toString() override {
			return "LogicalBinaryExpression";
		}

		virtual std::vector<Node*> getChildren() {
			std::vector<Node*> result;
			result.push_back(left_);
			result.push_back(right_);
			return result;
		}

		virtual int hashCode() {
			return 0;
		}

		virtual bool equals(const Node& node) {
			return false;
		}

		Operator getOperator() { return operator_; }
		Expression* getLeft() { return left_; }
		Expression* getRight() { return right_; }

	private:
		Operator operator_;
		Expression* left_;
		Expression* right_;
	};

}



#endif /* LogicalBinaryExpression_h */
