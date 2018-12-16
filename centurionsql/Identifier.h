#pragma once

#include "NodeLocation.h"
#include "Expression.h"
#include <antlr4-runtime.h>
#include <string>
#include <optional>
#include <regex>

namespace centurion {
	class Identifier : public Expression {
	public:
		Identifier(std::optional<NodeLocation> location, const std::string& value, bool delimited)
			:
			namePattern_("[a-zA-Z_]([a-zA-Z0-9_:@])*"),
			Expression(location),
			location_(location),
			value_(value),
			delimited_(delimited)
		{

		}

		Identifier(NodeLocation location, const std::string& value, bool delimited) 
			: Identifier(std::optional<NodeLocation>(location), value, delimited)
		{
			
		}

		Identifier(const std::string& value, bool delimited)
			:
			Identifier(std::nullopt, value, delimited)
		{
			
		}

		Identifier(const std::string& value)
			:
			Identifier(std::nullopt, value, false)			
		{
			delimited_ = std::regex_match(value, namePattern_);
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override { 
			return visitor->visitIdentifier(this, context); 
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>();
		}

		virtual int hashCode() override {
			return (int)std::hash_value(value_);
		}

		virtual bool equals(const Node& node) override {
			//return getValue() == node.getValue();
			return true;
		}

		virtual std::string toString() override {
			return "Identifier";
		}

		std::string getValue() const {
			return value_;
		}

		bool isDelimited() const {
			return delimited_;
		}

	private:
		std::regex namePattern_;
		std::optional<NodeLocation> location_;
		std::string value_;
		bool delimited_;
	};
}
