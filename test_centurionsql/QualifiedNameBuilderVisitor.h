#pragma once

#include "AstVisitorImpl.h"

namespace centurion {
	class QualifiedNameBuilder : public antlr4::ParserRuleContext {
	public:
		void add(std::shared_ptr<QualifiedName> qualifiedName) {
			qualifiedNames_.emplace_back(qualifiedName);
		}

	private:
		std::vector<std::shared_ptr<QualifiedName>> qualifiedNames_;
	};

	class QualifiedNameBuilderVisitor : public AstVisitorImpl {
	public:
		antlrcpp::Any visitDereferenceExpression(DereferenceExpression* node, antlr4::ParserRuleContext* context) override
		{
			return std::shared_ptr<QualifiedName>(DereferenceExpression::getQualifiedName(node));
		}

		antlrcpp::Any visitIdentifier(Identifier* node, antlr4::ParserRuleContext* context) override
		{
			return std::make_shared<QualifiedName>(node->getValue());
		}

		antlrcpp::Any visitSingleColumn(SingleColumn* singleColumn, antlr4::ParserRuleContext* context) override
		{
			auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
			builder->add(process(singleColumn->getExpression(), context));
			return antlrcpp::Any();
		}

		antlrcpp::Any visitAllColumns(AllColumns* allColumns, antlr4::ParserRuleContext* context) override
		{
			auto builder = dynamic_cast<QualifiedNameBuilder*>(context);
			if (allColumns->getPrefix().has_value()) {
				builder->add(allColumns->getPrefix().value());
			} 
			else
			{
				builder->add(std::make_shared<QualifiedName>());
			}
			return antlrcpp::Any();
		}

	};
}
