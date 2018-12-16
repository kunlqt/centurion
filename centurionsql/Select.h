#pragma once

#include "SelectItem.h"
#include "NodeLocation.h"
#include "Node.h"
#include <vector>
#include <optional>

namespace centurion {

	class Select : public Node {
	public:
		Select(bool distinct, const std::vector<SelectItem*> selectItems)
			: Select(std::nullopt, distinct, selectItems) {

		}

		Select(const NodeLocation& location, bool distinct, const std::vector<SelectItem*> selectItems)
			: Select(std::optional<NodeLocation>(location), distinct, selectItems) {

		}

		Select(const std::optional<NodeLocation>& location, bool distinct, const std::vector<SelectItem*> selectItems)
			: Node(location), distinct_(distinct), selectItems_(selectItems) {

		}
				
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitSelect(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			for (const auto& selectItem : selectItems_) {
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
			return "Select";
		}

		bool isDistinct() const { return distinct_; }
		std::vector<SelectItem*> getSelectItems() const { return selectItems_; };

	private:
		bool distinct_;
		std::vector<SelectItem*> selectItems_;
	};

}
