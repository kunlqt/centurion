//
//  Relation.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Relation_h
#define Relation_h

#include "NodeLocation.h"
#include "Node.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {

	class Relation : public Node {
	public:
		Relation(std::optional<NodeLocation> location) : Node(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitRelation(this, context);
		}

	};

}



#endif /* Relation_h */
