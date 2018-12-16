#pragma once

#include "NodeLocation.h"
#include "Select.h"
#include "Relation.h"
#include "Expression.h"
#include "GroupBy.h"
#include "OrderBy.h"
#include "QueryBody.h"
#include <optional>

namespace centurion {
	class QuerySpecification : public QueryBody {
	public:
		QuerySpecification(
			std::optional<Select*> select,
			std::optional<Relation*> from,
			std::optional<Expression*> where,
			std::optional<GroupBy*> groupBy,
			std::optional<Expression*> having,
			std::optional<OrderBy*> orderBy,
			std::optional<std::string> limit)
			: QuerySpecification(
				std::nullopt,
				select,
				from,
				where,
				groupBy,
				having,
				orderBy,
				limit)
		{}

		QuerySpecification(
			const NodeLocation& location,
			std::optional<Select*> select,
			std::optional<Relation*> from,
			std::optional<Expression*> where,
			std::optional<GroupBy*> groupBy,
			std::optional<Expression*> having,
			std::optional<OrderBy*> orderBy,
			std::optional<std::string> limit)
		: QuerySpecification(
			std::optional<NodeLocation>(location),
			select,
			from,
			where,
			groupBy,
			having,
			orderBy,
			limit) 
		{}

		QuerySpecification(
			const std::optional<NodeLocation>& location,
			std::optional<Select*> select,
			std::optional<Relation*> from,
			std::optional<Expression*> where,
			std::optional<GroupBy*> groupBy,
			std::optional<Expression*> having,
			std::optional<OrderBy*> orderBy,
			std::optional<std::string> limit)
			: 
			QueryBody(location),
			select_(select),
			from_(from),
			where_(where),
			groupBy_(groupBy),
			having_(having),
			orderBy_(orderBy),
			limit_(limit) 
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitQuerySpecification(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			result.push_back(select_.value());
			if (from_.has_value()) result.push_back(from_.value());
			if (where_.has_value()) result.push_back(where_.value());
			if (groupBy_.has_value()) result.push_back(groupBy_.value());
			if (having_.has_value()) result.push_back(having_.value());
			if (orderBy_.has_value()) result.push_back(orderBy_.value());
			return result;
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "QuerySpecification";
		}

		std::optional<Select*> getSelect() const { return select_; }
		std::optional<Relation*> getFrom() const { return from_; }
		std::optional<Expression*> getWhere() const { return where_; }
		std::optional<GroupBy*> getGroupBy() const { return groupBy_; }
		std::optional<Expression*> getHaving() const { return having_; }
		std::optional<OrderBy*> getOrderBy() const { return orderBy_; }
		std::optional<std::string> getLimit() const { return limit_; }

	private:
		std::optional<Select*> select_;
		std::optional<Relation*> from_;
		std::optional<Expression*> where_;
		std::optional<GroupBy*> groupBy_;
		std::optional<Expression*> having_;
		std::optional<OrderBy*> orderBy_;
		std::optional<std::string> limit_;
	};
}


