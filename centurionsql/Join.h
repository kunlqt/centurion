//
//  QueryBody.h
//  
//
//  Created by Vasko Mitanov on 11/10/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#pragma once

#include "NodeLocation.h"
#include "Relation.h"
#include "JoinCriteria.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {
	class Join : public Relation {
	public:
		enum JoinType
		{
			CROSS, INNER, LEFT, RIGHT, FULL, IMPLICIT
		};

		Join(JoinType type, Relation* left, Relation* right, std::optional<JoinCriteria*> criteria)
			: Join(std::nullopt, type, left, right, criteria)
		{

		}

		Join(NodeLocation location, JoinType type, Relation* left, Relation* right, std::optional<JoinCriteria*> criteria)
			: Join(std::make_optional(location), type, left, right, criteria)
		{

		}

		Join(std::optional<NodeLocation> location, JoinType type, Relation* left, Relation* right, std::optional<JoinCriteria*> criteria)
			: Relation(location), type_(type), left_(left), right_(right), criteria_(criteria)
		{

		}
		 

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitJoin(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			std::vector<Node*> result { left_, right_ };
			if (criteria_.has_value()) {
				const auto& nodes = criteria_.value()->getNodes();
				for (auto& node : nodes) {
					result.push_back(node);
				}
			}
			return result;
		}

		virtual int hashCode() override  {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "Join";
		}

		JoinType getType() const { return type_;  }
		Relation* getLeft() const { return left_;  }
		Relation* getRight() const { return right_; }
		std::optional<JoinCriteria*> getCriteria() const { return criteria_; }

	private:
		JoinType type_;
		Relation* left_;
		Relation* right_;
		std::optional<JoinCriteria*> criteria_;
	};

}
