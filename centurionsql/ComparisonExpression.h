#pragma once

#ifndef ComparisonExpression_h
#define ComparisonExpression_h

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {
	class ComparisonExpression : public Expression {
	public:
		struct Operator { 
			static Operator EQUAL;
			static Operator NOT_EQUAL;
			static Operator LESS_THAN;
			static Operator LESS_THAN_OR_EQUAL;
			static Operator GREATER_THAN;
			static Operator GREATER_THAN_OR_EQUAL;
			static Operator IS_DISTINCT_FROM;

			bool operator==(const ComparisonExpression::Operator& other) const {
				return name_ == other.name_;
			}

		private:
			Operator(const std::string& name) : name_(name) { }
			std::string name_;
		};

		ComparisonExpression(const Operator& oper, Expression* left, Expression* right)
			:
			ComparisonExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		ComparisonExpression(NodeLocation location, const Operator& oper, Expression* left, Expression* right)
			:
			ComparisonExpression(std::make_optional(location), oper, left, right) {
		}

		ComparisonExpression(std::optional<NodeLocation> location, const Operator& oper, Expression* left, Expression* right)
			:
			Expression(location), operator_(oper), left_(left), right_(right) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitComparisonExpression(this, context);
		}

		virtual std::string toString() override {
			return "ComparisonExpression";
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

		Operator getOperator() const { return operator_; }
		Expression* getLeft() const { return left_; }
		Expression* getRight() const { return right_; }

		

	private:
		Operator operator_;
		Expression* left_;
		Expression* right_;
	};

	
	
}



#endif /* ComparisonExpression_h */
