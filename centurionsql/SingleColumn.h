#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include "SelectItem.h"
#include "Identifier.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {
	class SingleColumn : public SelectItem {
	public:
		SingleColumn(Expression* expression) 
			: SingleColumn(std::nullopt, expression, std::nullopt)
		{  
		}
		
		SingleColumn(
			Expression* expression,
			std::optional<Identifier*> alias)
			:
			SingleColumn(std::nullopt, expression, std::optional<Identifier*>(alias))
		{
		}

		SingleColumn(
			const NodeLocation& location,
			Expression* expression,
			std::optional<Identifier*> alias)
			:
			SingleColumn(std::optional<NodeLocation>(location), expression, std::optional<Identifier*>(alias))
		{
		}

		SingleColumn(
			std::optional<NodeLocation> location, 
			Expression* expression, 
			std::optional<Identifier*> alias)
			: 
			SelectItem(location), 
			expression_(expression), 
			alias_(alias)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitSingleColumn(this, context); 
		}
	
		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>{ expression_ };
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "SingleColumn";
		}

		std::optional<Identifier*> getAlias() const { return alias_; }
		Expression* getExpression() const { return expression_; }
	
	private:
		std::optional<Identifier*> alias_;
		Expression* expression_;
	};
}
