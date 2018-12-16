//
//  DecimalLiteral.h
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

	class DecimalLiteral : public Literal {
	public:
		DecimalLiteral(const std::string& value)
			: DecimalLiteral(std::optional<NodeLocation>(), value) {
		}

		DecimalLiteral(const NodeLocation& location, const std::string& value)
			: DecimalLiteral(std::make_optional(location), value) {
		}

		DecimalLiteral(std::optional<NodeLocation> location, const std::string& value) : Literal(location) {
			value_ = value;
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitDecimalLiteral(this, context);
		}

		virtual std::string toString() override {
			return "DecimalLiteral";
		}

		virtual int hashCode() override {
			std::hash<std::string> h;
			return (int)h(value_);
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		std::string getValue() const {
			return value_;
		}

	private:
		std::string value_;
	};

}

