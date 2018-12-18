#pragma once

#include "AstVisitor.h"
#include <deque>

namespace centurion {
	class StackableAstVisitor : public AstVisitor {
	public:
		class StackableAstVisitorContext : public antlr4::ParserRuleContext
		{
		public:
			StackableAstVisitorContext() { }
			void pop() { nodeStack_.pop_back(); }
			void push(Node* node) { nodeStack_.push_back(node); }
			std::optional<Node*> getPreviousNode()
			{
				if (nodeStack_.size() > 1)
				{
					return std::make_optional(nodeStack_[1]);
				}
				return std::optional<Node*>();
			}

		private:
			std::deque<Node*> nodeStack_;

		};

		virtual antlrcpp::Any process(Node* node, antlr4::ParserRuleContext* context) override
		{
			dynamic_cast<StackableAstVisitorContext*>(context)->push(node);
			antlrcpp::Any result = node->accept(this, context);
			dynamic_cast<StackableAstVisitorContext*>(context)->pop();
			return result;
		}
	};
}
