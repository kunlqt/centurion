#pragma once

#ifndef NotExpression_h
#define NotExpression_h

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {
	class NotExpression : public Expression {
	public:
		NotExpression(Expression* value)
			:
			NotExpression(std::optional<NodeLocation>(), value) {
		}

		NotExpression(NodeLocation location, Expression* value)
			:
			NotExpression(std::make_optional(location), value) {
		}

		NotExpression(std::optional<NodeLocation> location, Expression* value)
			:
			Expression(location), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitNotExpression(this, context);
		}

		virtual std::string toString() override {
			return "NotExpression";
		}

		virtual std::vector<Node*> getChildren() {
			std::vector<Node*> result;
			result.push_back(value_);
			return result;
		}

		virtual int hashCode() {
			return 0;
		}

		virtual bool equals(const Node& node) {
			return false;
		}

		Expression* getValue() { return value_; }

	private:
		Expression* value_;
	};

}



#endif /* NotExpression_h */
