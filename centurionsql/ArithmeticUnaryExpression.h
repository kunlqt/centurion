#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {
	class ArithmeticUnaryExpression : public Expression {
	public:
		enum Sign {
			PLUS, MINUS
		};

		ArithmeticUnaryExpression(Sign sign, Expression* left)
			:
			ArithmeticUnaryExpression(std::optional<NodeLocation>(), sign, left) {
		}

		ArithmeticUnaryExpression(NodeLocation location, Sign sign, Expression* value)
			:
			ArithmeticUnaryExpression(std::make_optional(location), sign, value) {
		}

		ArithmeticUnaryExpression(std::optional<NodeLocation> location, Sign sign, Expression* value)
			:
			Expression(location), sign_(sign), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitArithmeticUnary(this, context);
		}

		virtual std::string toString() override {
			return "ArithmeticUnaryExpression";
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ value_};
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		Sign getSign() { return sign_; }
		Expression* getValue() { return value_; }
		

	private:
		Sign sign_;
		Expression* value_;
		
	};

}
