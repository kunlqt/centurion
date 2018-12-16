#pragma once

#include "GroupingElement.h"
#include "SelectItem.h"
#include "NodeLocation.h"
#include "Node.h"
#include <vector>
#include <optional>

namespace centurion {

	class GroupBy : public Node {
	public:
		GroupBy(bool distinct, const std::vector<GroupingElement*> groupingElements)
			: GroupBy(std::nullopt, distinct, groupingElements) {

		}

		GroupBy(const NodeLocation& location, bool distinct, const std::vector<GroupingElement*> groupingElements)
			: GroupBy(std::optional<NodeLocation>(location), distinct, groupingElements) {

		}

		GroupBy(const std::optional<NodeLocation>& location, bool distinct, const std::vector<GroupingElement*> groupingElements)
			: Node(location), distinct_(distinct), groupingElements_(groupingElements) {

		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitGroupBy(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			for (const auto& selectItem : groupingElements_) {
				result.push_back(selectItem);
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
			return "GroupBy";
		}

		bool isDistinct() const { return distinct_; }

		std::vector<GroupingElement*> getGroupingElements() const { return groupingElements_; };


	private:
		bool distinct_;
		std::vector<GroupingElement*> groupingElements_;
	};

}
