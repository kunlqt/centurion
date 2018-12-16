//
//  Expression.h
//  deleteme
//
//  Created by Vasko Mitanov on 11/8/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef DereferenceExpression_h
#define DereferenceExpression_h

#include "QualifiedName.h"
#include "Expression.h"
#include "Identifier.h"
#include "Node.h"
#include "AstVisitor.h"
#include <optional>

namespace centurion {

	class DereferenceExpression : public Expression {
	private:
		Expression* base_;
		Identifier* field_;

	public:
		DereferenceExpression(Expression* base, Identifier* field)
			: DereferenceExpression(std::nullopt, base, field)
		{

		}

		DereferenceExpression(NodeLocation location, Expression* base, Identifier* field)
			: DereferenceExpression(std::optional<NodeLocation>(location), base, field)
		{

		}

		DereferenceExpression(std::optional<NodeLocation> location, Expression* base, Identifier* field) 
			: Expression(location), base_(base), field_(field)
		{
		}
		
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitDereferenceExpression(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ base_ };
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "DereferenceExpression";
		}

		static Expression* from(const QualifiedName& name) {
			Expression* result = nullptr;
			for (const auto& part : name.getParts()) {
				if (result == nullptr) {
					result = new Identifier(part);
				}
				else {
					result = new DereferenceExpression(result, new Identifier(part));
				}
			}
			return result;
		}

		Expression* getBase() const {
			return base_;
		}

		Identifier* getField() const {
			return field_;
		}

	};

}



#endif /* DereferenceExpression_h */
