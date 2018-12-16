#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include <vector>
#include <optional>

namespace centurion
{
	class InListExpression : public Expression
	{
	public:
		InListExpression(std::vector<Expression*> values)
			: InListExpression(std::optional<NodeLocation>(), values) {}

		InListExpression(NodeLocation location, std::vector<Expression*> values)
			: InListExpression(std::make_optional(location), values) {}

		InListExpression(std::optional<NodeLocation> location, std::vector<Expression*> values) 
		: Expression(location), values_(std::move(values)) {}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitInListExpression(this, context);
		}

		virtual std::vector<Node*> getChildren() override
		{
			std::vector<Node*> result;
			for (Expression* value : values_)
			{
				result.push_back(value);
			}
			return result;
		}
		virtual int hashCode()  override
		{
			return 0;
		}
		virtual bool equals(const Node& node)  override
		{
			return false;
		}
		virtual std::string toString()  override
		{
			return "InListExpression";
		}

		std::vector<Expression*> getValues() const { return values_; }

	private:
		std::vector<Expression*> values_;
	};
}