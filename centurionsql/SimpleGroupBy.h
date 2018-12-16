#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "GroupingElement.h"
#include <antlr4-runtime.h>
#include <optional>
#include <vector>

namespace centurion {
	class SimpleGroupBy : public GroupingElement {
	public:
		SimpleGroupBy(const std::vector<Expression*>& columns)
			:
			SimpleGroupBy(std::optional<NodeLocation>(), columns)
		{
		}

		SimpleGroupBy(NodeLocation location, const std::vector<Expression*>& columns)
			: 
			SimpleGroupBy(std::make_optional(location), columns)
		{ 
		}

		SimpleGroupBy(std::optional<NodeLocation> location, const std::vector<Expression*>& columns)
			:
			GroupingElement(location), columns_(columns)
		{
		}
				
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitSimpleGroupBy(this, context);
		}

		virtual std::vector<Node*> getChildren() {
			std::vector<Node*> result;
			for (const auto& column : columns_) result.push_back(column);
			return result;
		};
		
		virtual int hashCode() {
			int result = 0;
			//for (const auto& column : columns_) (column-> result.push_back(column);
			return result;
		}

		virtual bool equals(const Node& node) {
			return false;
		}

		virtual std::string toString() {
			return "SimpleGroupBy";
		}

		virtual std::vector<Expression*> getExpressions() const {
			return columns_;
		}

	private:
		std::vector<Expression*> columns_;
	};

}
