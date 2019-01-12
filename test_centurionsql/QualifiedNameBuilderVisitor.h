#pragma once

#include "AstVisitorImpl.h"

namespace centurion {
	class QualifiedNameBuilder : public antlr4::ParserRuleContext {
	public:
		void add(QualifiedName* qualifiedName) {
			qualifiedNames_.push_back(qualifiedName);
		}

	private:
		std::vector<QualifiedName*> qualifiedNames_;
	};

	class ExpressionRef {
	public:
		ExpressionRef(Expression* node) : node_(node) {}
		const Expression* expr() const { return node_; }
	private:
		Expression* node_;
	};

	struct KeyHash {
		std::size_t operator()(const ExpressionRef& k) const
		{
			return 0;
			//return std::hash<std::string>()(k.expr()->) ^
			//	(std::hash<std::string>()(k.second) << 1);
		}
	};

	struct KeyEqual {
		bool operator()(const ExpressionRef& lhs, const ExpressionRef& rhs) const
		{
			return true; // lhs.first == rhs.first && lhs.second == rhs.second;
		}
	};

	class QualifiedNameBuilderVisitor : public AstVisitorImpl {
	public:
		antlrcpp::Any visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context) override
		{
			if (columnReferences_.count(ExpressionRef(node)) > 0) {
				auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
				builder->add(DereferenceExpression::getQualifiedName(node));
			}
			process(node->getBase(), context);
			return antlrcpp::Any();
		}

		antlrcpp::Any visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context) override
		{
			auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
			builder->add(new QualifiedName(node->getValue()));
			return antlrcpp::Any();
		}

	private:
		std::unordered_set<ExpressionRef, KeyHash, KeyEqual> columnReferences_;
	};
}
