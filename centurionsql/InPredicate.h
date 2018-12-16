#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include <vector>
#include <optional>

namespace centurion
{
	class InPredicate : public Expression
	{
	public:
		InPredicate(Expression* value, Expression* valueList)
			: InPredicate(std::optional<NodeLocation>(), value, valueList) {}

		InPredicate(NodeLocation location, Expression* value, Expression* valueList)
			: InPredicate(std::make_optional(location), value, valueList) {}

		InPredicate(std::optional<NodeLocation> location, Expression* value, Expression* valueList)
			: Expression(location), value_(value), valueList_(valueList) {}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitInPredicate(this, context);
		}

		virtual std::vector<Node*> getChildren() override
		{
			return std::vector<Node*>{ value_, valueList_};
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
			return "InPredicate";
		}

		Expression* getValue() const { return value_; }
		Expression* getValueList() const { return valueList_; }
		
	private:
		Expression* value_;
		Expression* valueList_;
	};
}
