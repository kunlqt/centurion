#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <vector>
#include <optional>

namespace centurion {
	class IsNotNullPredicate : public Expression {
	public:
		IsNotNullPredicate(Expression* value)
			:
			IsNotNullPredicate(std::optional<NodeLocation>(), value) {
		}

		IsNotNullPredicate(NodeLocation location, Expression* value)
			:
			IsNotNullPredicate(std::make_optional(location), value) {
		}

		IsNotNullPredicate(std::optional<NodeLocation> location, Expression* value)
			:
			Expression(location), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitIsNotNullPredicate(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ value_ };
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "IsNotNullPredicate";
		}

		Expression* getValue() const {
			return value_;
		}


	private:
		Expression* value_;
	};
}
