#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {
	class ArithmeticBinaryExpression : public Expression {
	public:
		struct Operator {
			static Operator ADD;
			static Operator SUBTRACT;
			static Operator MULTIPLY;
			static Operator DIVIDE;
			static Operator MODULUS;
			
			bool operator==(const ArithmeticBinaryExpression::Operator& other) const {
				return value_ == other.value_;
			}

		private:
			Operator(std::string value) : value_(std::move(value)) { }
			std::string value_;
		};

		ArithmeticBinaryExpression(Operator oper, Expression* left, Expression* right)
			:
			ArithmeticBinaryExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		ArithmeticBinaryExpression(NodeLocation location, Operator oper, Expression* left, Expression* right)
			:
			ArithmeticBinaryExpression(std::make_optional(location), oper, left, right) {
		}

		ArithmeticBinaryExpression(std::optional<NodeLocation> location, Operator oper, Expression* left, Expression* right)
			:
			Expression(location), operator_(oper), left_(left), right_(right) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitArithmeticBinary(this, context);
		}

		virtual std::string toString() override {
			return "ArithmeticBinaryExpression";
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ left_, right_ };
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
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
