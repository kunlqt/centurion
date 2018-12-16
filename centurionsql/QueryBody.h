//
//  QueryBody.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#pragma once

#include "NodeLocation.h"
#include "Relation.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {

	class QueryBody: public Relation {
	public:
		QueryBody(std::optional<NodeLocation> location) : Relation(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitQueryBody(this, context);
		}

	};

}
