//
//  Statement.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Statement_h
#define Statement_h

#include "Node.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {

	class Statement : public Node {
	public:
		Statement(std::optional<NodeLocation> location) : Node(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitStatement(this, context);
		}

	};

}



#endif /* Statement_h */
