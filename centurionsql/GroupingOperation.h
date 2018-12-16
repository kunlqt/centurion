#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "QualifiedName.h"
#include "DereferenceExpression.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <vector>
#include <optional>

namespace centurion {
	class GroupingOperation : public Expression {
	public:
		GroupingOperation(const std::optional<NodeLocation>& location, const std::vector<QualifiedName>& groupingColumns) : Expression(location) {
			for (const auto& groupingColumn : groupingColumns) {
				groupingColumns_.push_back(DereferenceExpression::from(groupingColumn));
			}
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitGroupingOperation(this, context);
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
			return "GroupingOperation";
		}

		std::vector<Expression*> getGroupingColumns() const {
			return groupingColumns_;
		}

	private:
		std::vector<Expression*> groupingColumns_;
	};
}