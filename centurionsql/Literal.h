//
//  Literal.h
//  Created by Vasko Mitanov on 11/11/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Literal_h
#define Literal_h

#include "NodeLocation.h"
#include "Node.h"
#include "Expression.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {

	class Literal : public Expression {
	public:
		Literal(std::optional<NodeLocation> location) : Expression(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitLiteral(this, context);
		}

		virtual std::string toString() override {
			return "Literal";
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>();
		}
	};

}



#endif /* Literal_h */
