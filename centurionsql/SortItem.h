//
//  SortItem.h
//  
//
//  Created by Vasko Mitanov on 11/8/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef SortItem_h
#define SortItem_h

#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <vector>
#include <string>

namespace centurion {

	class SortItem : public Node {
	public:
		enum Ordering { Ascending, Descending };
		enum NullOrdering { First, Last, Undefined };

		SortItem(std::optional<NodeLocation> location, Expression* sortKey, Ordering ordering, NullOrdering nullOrdering) 
			: 
			Node(location), sortKey_(sortKey), ordering_(ordering), nullOrdering_(nullOrdering)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitSortItem(this, context);
		}
			
		virtual std::vector<Node*> getChildren() {
			std::vector<Node*> result{ sortKey_ };
			return result;
		}

		virtual int hashCode() {
			return 0;
		}

		virtual bool equals(const Node& node) {
			return false;
		}

		virtual std::string toString() {
			return "SortItem";
		}

		Expression* getSortKey() const {
			return sortKey_;
		}

		Ordering getOrdering() const {
			return ordering_;
		}

		NullOrdering getNullOrdering() const {
			return nullOrdering_;
		}


	private:
		Expression* sortKey_;
		SortItem::Ordering ordering_;
		SortItem::NullOrdering nullOrdering_;
	
	};

}



#endif /* SortItem_h */
