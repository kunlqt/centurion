//
//  OrderBy.h
//  
//
//  Created by Vasko Mitanov on 11/8/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef OrderBy_h
#define OrderBy_h

#include "Node.h"
#include "SortItem.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <vector>

namespace centurion {

	class OrderBy : public Node {
	public:
		OrderBy(const std::vector<SortItem*>& sortItems)
			: OrderBy(std::optional<NodeLocation>(), sortItems)
		{

		}

		OrderBy(const NodeLocation& location, const std::vector<SortItem*>& sortItems)
			: OrderBy(std::make_optional(location), sortItems)
		{

		}

		OrderBy(std::optional<NodeLocation> location, const std::vector<SortItem*>& sortItems) 
			: 
			Node(location), sortItems_(sortItems)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitOrderBy(this, context);
		}
				
		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			for (const auto& sortItem : sortItems_) {
				sortItems_.push_back(sortItem);
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
			return "OrderBy";
		}

		std::vector<SortItem*> getSortItems() const {
			return sortItems_;
		}

	private:
		std::vector<SortItem*> sortItems_;
	};

}



#endif /* OrderBy_h */
