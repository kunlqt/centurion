#ifndef StringLiteral_h
#define StringLiteral_h

#include "NodeLocation.h"
#include "Node.h"
#include "Literal.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>
#include <string>

namespace centurion {

	class StringLiteral : public Literal {
	public:
		StringLiteral(const std::string& value)
			: StringLiteral(std::optional<NodeLocation>(), value) {
		}

		StringLiteral(const NodeLocation& location, const std::string& value)
			: StringLiteral(std::make_optional(location), value) {
		}

		StringLiteral(std::optional<NodeLocation> location, const std::string& value) : Literal(location) {
			value_ = value;
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitStringLiteral(this, context);
		}

		virtual std::string toString() override {
			return "StringLiteral";
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

#endif /* StringLiteral */
