//
//  LongLiteral.h
//  Created by Vasko Mitanov on 11/12/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#include "NodeLocation.h"
#include "Node.h"
#include "Literal.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {

	class DoubleLiteral : public Literal {
	public:
		DoubleLiteral(const std::string& value)
			: DoubleLiteral(std::optional<NodeLocation>(), value) {
		}

		DoubleLiteral(const NodeLocation& location, const std::string& value)
			: DoubleLiteral(std::make_optional(location), value) {
		}

		DoubleLiteral(std::optional<NodeLocation> location, const std::string& value) : Literal(location) {
			value_ = std::atof(value.c_str());
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitDoubleLiteral(this, context);
		}

		virtual std::string toString() override {
			return "DoubleLiteral";
		}

		double getValue() const {
			return value_;
		}

		virtual int hashCode() override {
			return ((int)value_);
		}

		virtual bool equals(const Node& node) override {
			return false;
		}


	private:
		double value_;
	};

}

