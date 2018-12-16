#pragma once
#include "NodeLocation.h"
#include "Node.h"
#include "Statement.h"
#include "Relation.h"
#include <optional>

namespace centurion
{
	class ShowStats : public Statement
	{
	public:
		ShowStats(Relation* relation) : ShowStats(std::optional<NodeLocation>(), relation) {}
		ShowStats(NodeLocation location, Relation* relation): ShowStats(std::make_optional(location), relation) {}
		ShowStats(std::optional<NodeLocation> location, Relation* relation): Statement(location), relation_(relation) {}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitShowStats(this, context);
		}

		virtual bool equals(const Node& obj) override
		{
			return false;
		}

		virtual int hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "ShowStats";
		}

		virtual std::vector<Node*> getChildren() override
		{
			return std::vector<Node*>{ relation_ };
		}


	private:
		Relation* relation_;
	};
}
