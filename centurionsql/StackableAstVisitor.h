#pragma once

#include "AstVisitor.h"
#include <stack>

namespace centurion {
	class StackableAstVisitor : public AstVisitor {
		class StackableAstVisitorContext : public antlr4::ParserRuleContext
		{
		public:
			StackableAstVisitorContext() : nodeStack_(dequeue_) { }
			void pop() { nodeStack_.pop(); }
			void push(Node* node) { nodeStack_.push(node); }
			std::optional<Node*> getPreviousNode()
			{
				if (nodeStack_.size() > 1)
				{
					return std::make_optional(dequeue_[1]);
				}
				return std::optional<Node*>();
			}

		private:
			std::deque<Node*> dequeue_;
			std::stack<Node*> nodeStack_;

		};

	public:
		virtual antlrcpp::Any process(Node* node, antlr4::ParserRuleContext* context) override
		{
			((StackableAstVisitorContext*)context)->push(node);
			antlrcpp::Any result = node->accept(this, context);
			((StackableAstVisitorContext*)context)->pop();
			return result;
		}
	};
}
