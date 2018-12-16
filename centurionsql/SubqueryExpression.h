#pragma once
#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "Query.h"
#include <optional>

namespace centurion {

	class SubqueryExpression : public Expression
	{
	public:
		SubqueryExpression(Query* query) : SubqueryExpression(std::optional<NodeLocation>(), query) { }
		SubqueryExpression(NodeLocation location, Query* query) :  SubqueryExpression(std::make_optional(location), query) { }
		SubqueryExpression(std::optional<NodeLocation> location, Query* query) 
		: Expression(location), query_(query) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitSubqueryExpression(this, context);
		}

		virtual std::string toString() override {
			return "SubqueryExpression";
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ query_ };
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		Query* getQuery() const { return query_; }

	private:
		Query* query_;
	};

}
