//
//  LongLiteral.h
//  Created by Vasko Mitanov on 11/11/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef LongLiteral_h
#define LongLiteral_h

#include "NodeLocation.h"
#include "Node.h"
#include "Literal.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {

	class LongLiteral : public Literal {
	public:
		LongLiteral(const std::string& value)
			: LongLiteral(std::optional<NodeLocation>(), value) {
		}

		LongLiteral(const NodeLocation& location, const std::string& value) 
			: LongLiteral(std::make_optional(location), value) {
		}

		LongLiteral(std::optional<NodeLocation> location, const std::string& value) : Literal(location) {
			value_ = std::atol(value.c_str());
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitLongLiteral(this, context);
		}

		virtual std::string toString() override {
			return "LongLiteral";
		}

		long getValue() const {
			return value_;
		}

		virtual int hashCode() override {
			return (value_);
		}

		virtual bool equals(const Node& node) override {
			return false;
		}


	private:
		long value_;
	};

}



#endif /* LongLiteral_h */
