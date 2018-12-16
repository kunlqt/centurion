#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include <antlr4-runtime.h>
#include <optional>
#include <vector>

namespace centurion {
	class GroupingElement : public Node {
	public:
		GroupingElement(std::optional<NodeLocation> location) : Node(location) { }
		virtual std::vector<Expression*> getExpressions() const =0;
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitGroupingElement(this, context);
		}
	
	};
	   
}
