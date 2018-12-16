//
//  Expression.h
//  deleteme
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Expression_h
#define Expression_h

#include "NodeLocation.h"
#include "Node.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {
	
class Expression : public Node {
public:
	Expression(std::optional<NodeLocation> location) : Node(location) {
	}
	
	virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override { 
		return visitor->visitExpression(this, context); 
	}

	virtual std::string toString() override {
		return "Expression";
	}
};
    
}

    

#endif /* Expression_h */
