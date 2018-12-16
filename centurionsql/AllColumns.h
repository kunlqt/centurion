#pragma once

#include "SelectItem.h"
#include "QualifiedName.h"
#include <optional>

namespace centurion {
	class AllColumns : public SelectItem {
	public:
		AllColumns() 
			: 
			SelectItem(std::nullopt),
			prefix_(std::nullopt) 
		{
		}

		AllColumns(const NodeLocation& location) 
			: 
			SelectItem(std::optional<NodeLocation>(location)), 
			prefix_(std::nullopt) 
		{
		}

		AllColumns(const QualifiedName& prefix) 
			: AllColumns(std::nullopt, prefix) {
		}

		AllColumns(const NodeLocation& location, const QualifiedName& prefix) 
			: AllColumns(std::optional<NodeLocation>(location), prefix) {
		}

		AllColumns(std::optional<NodeLocation> location, const QualifiedName& prefix) 
			: SelectItem(location), prefix_(prefix) {
		}

		antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitAllColumns(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>();
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "AllColumns";
		}

		std::optional<QualifiedName> getPrefix() const {
			return prefix_;
		}

	private:
		std::optional<QualifiedName> prefix_;
	};
}
