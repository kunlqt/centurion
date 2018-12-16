#pragma once

#include "NodeLocation.h"
#include "Relation.h"
#include "Identifier.h"
#include <vector>
#include <optional>

namespace centurion {
	class AliasedRelation : public Relation {
	public:
		AliasedRelation(std::optional<NodeLocation> location, Relation* relation, Identifier* alias, const std::vector<Identifier*>& columnNames)
			: Relation(location), relation_(relation), alias_(alias)
		{
			for (const auto& col : columnNames_) {
				columnNames_.push_back(col);
			}
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitAliasedRelation(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result;
			result.push_back(relation_);
			return result;
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "AliasedRelation";
		}

		Relation* getRelation() const { return relation_; }
		Identifier* getAlias() const { return alias_; }
		std::vector<Identifier*> getColumnNames() const { return columnNames_; }

	private:
		std::optional<NodeLocation> location_;
		Relation* relation_;
		Identifier* alias_;
		std::vector<Identifier*> columnNames_;


	};
}