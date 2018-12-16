//
//  Query.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Query_h
#define Query_h

#include "Statement.h"
#include "With.h"
#include "QueryBody.h"
#include "OrderBy.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {
	class Query : public Statement {
	public:
		Query(std::optional<With*> with,
			QueryBody* queryBody,
			std::optional<OrderBy*> orderBy,
			const std::optional<std::string>& limit)
			:
			Query(std::optional<NodeLocation>(), with, queryBody, orderBy, limit) {
		}

		Query(const NodeLocation& location,
			std::optional<With*> with,
			QueryBody* queryBody,
			std::optional<OrderBy*> orderBy,
			const std::optional<std::string>& limit)
			:
			Query(std::optional<NodeLocation>(location), with, queryBody, orderBy, limit) {
		}

		Query(std::optional<NodeLocation> location, 
			std::optional<With*> with,
			QueryBody* queryBody,
			std::optional<OrderBy*> orderBy,
			const std::optional<std::string>& limit) 
			: 
			Statement(location), with_(with), queryBody_(queryBody), orderBy_(orderBy), limit_(limit) {
		}
				
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitQuery(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			if (with_.has_value()) {
				result.push_back((Node*)with_.value());
			}
			if (orderBy_.has_value()) {
				result.push_back((Node*)orderBy_.value());
			}
			return result;
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "Query";
		}

		std::optional<With*> getWith() const
		{
			return with_;
		}

		QueryBody* getQueryBody() const
		{
			return queryBody_;
		}

		std::optional<OrderBy*> getOrderBy() const
		{
			return orderBy_;
		}

		std::optional<std::string> getLimit() const
		{
			return limit_;
		}


	private:
		std::optional<With*> with_;
		QueryBody* queryBody_;
		std::optional<OrderBy*> orderBy_;
		std::optional<std::string> limit_;
	};

}



#endif /* Query_h */
