//
//  WithQuery.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef WithQuery_h
#define WithQuery_h

#include "Node.h"
#include "Identifier.h"
#include "Query.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <vector>

namespace centurion {
	class WithQuery : public Node {
	public:
		WithQuery(Identifier* name, Query* query, const std::optional<std::vector<Identifier*>>& columnNames)
			:
			WithQuery(std::optional<NodeLocation>(), name, query, columnNames)
		{ }

		WithQuery(const NodeLocation& location, Identifier* name, Query* query, const std::optional<std::vector<Identifier*>>& columnNames)
			:
			WithQuery(std::optional<NodeLocation>(location), name, query, columnNames) 
		{ }

		WithQuery(std::optional<NodeLocation> location, Identifier* name, Query* query, const std::optional<std::vector<Identifier*>>& columnNames)
			:
			Node(location),
			name_(name),
			query_(query),
			columnNames_(columnNames) 
		{ }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitWithQuery(this, context);
		}

		virtual std::vector<Node*> getChildren();

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "WithQuery";
		}

		Identifier* getName() const {
			return name_;
		}

		Query* getQuery() const {
			return query_;
		}

		std::optional<std::vector<Identifier*>> getColumnNames() const {
			return columnNames_;
		}

	private:
		Identifier* name_;
		centurion::Query* query_;
		std::optional<std::vector<Identifier*>> columnNames_;
	};

}



#endif /* WithQuery_h */
