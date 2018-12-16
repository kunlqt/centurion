//
//  With.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef With_h
#define With_h

#include "Node.h"
#include "Query.h"
#include "WithQuery.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {
	class With : public Node {
	public:
		With(bool recursive, std::vector<WithQuery*>& queries) 
			: With(std::optional<NodeLocation>(), recursive, queries) {

		}

		With(const NodeLocation& location, bool recursive, std::vector<WithQuery*>& queries) 
			: With(std::optional<NodeLocation>(location), recursive, queries) {

		}

		With(std::optional<NodeLocation> location, bool recursive, std::vector<WithQuery*>& queries) 
			: Node(location), recursive_(recursive) {
			for (auto item : queries) {
				queries_.push_back(item);
			}
		}			

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitWith(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			for (auto& item : queries_) {
				result.push_back(item);
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
			return "With";
		}

		bool isRecursive() const { 
			return recursive_; 
		}

		std::vector<WithQuery*> getQueries() const {
			return queries_;
		};


	private:
		bool recursive_;
		std::vector<WithQuery*> queries_;
	};

}



#endif /* With_h */
