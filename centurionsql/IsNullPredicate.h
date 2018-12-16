#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <vector>
#include <optional>

namespace centurion {
	class IsNullPredicate : public Expression {
	public:
		IsNullPredicate(Expression* value)
			:
			IsNullPredicate(std::optional<NodeLocation>(), value) {
		}

		IsNullPredicate(NodeLocation location, Expression* value)
			:
			IsNullPredicate(std::make_optional(location), value) {
		}

		IsNullPredicate(std::optional<NodeLocation> location, Expression* value) 
			: 
			Expression(location), value_(value) {
		}
		
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitIsNullPredicate(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ value_ } ;
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "IsNullPredicate";
		}

		Expression* getValue() const {
			return value_;
		}

	private:
		Expression* value_;
	};
}
