//
//  AstBuilder.cpp
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#include "AstBuilder.h"
#include "CentSqlLexer.h"
#include "ParsingException.h"
#include "AstNodes.h"
#include "Utils.h"

namespace centurion {
	static LogicalBinaryExpression::Operator getLogicalBinaryOperator(antlr4::Token* token);
	static ComparisonExpression::Operator getComparisonOperator(antlr4::Token* symbol);
	static ArithmeticBinaryExpression::Operator getArithmeticBinaryOperator(antlr4::Token* symbol);
	static SortItem::Ordering getOrderingType(antlr4::Token* token);
	static SortItem::NullOrdering getNullOrderingType(antlr4::Token* token);
	
	AstBuilder::AstBuilder(ParsingOptions parsingOptions) 
		: 
		parameterPosition_(0),
		parsingOptions_(parsingOptions) {}

	antlrcpp::Any AstBuilder::visitSingleStatement(CentSqlParser::SingleStatementContext *ctx) {
		return CentSqlBaseVisitor::visit(ctx->statement());
	}

	antlrcpp::Any AstBuilder::visitStandaloneExpression(CentSqlParser::StandaloneExpressionContext *ctx) {
		return CentSqlBaseVisitor::visit(ctx->expression());
	}

	antlrcpp::Any AstBuilder::visitStandalonePathSpecification(CentSqlParser::StandalonePathSpecificationContext *ctx) {
		return CentSqlBaseVisitor::visit(ctx->pathSpecification());
	}

	antlrcpp::Any AstBuilder::visitStatementDefault(CentSqlParser::StatementDefaultContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitUse(CentSqlParser::UseContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCreateSchema(CentSqlParser::CreateSchemaContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDropSchema(CentSqlParser::DropSchemaContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRenameSchema(CentSqlParser::RenameSchemaContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCreateTableAsSelect(CentSqlParser::CreateTableAsSelectContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCreateTable(CentSqlParser::CreateTableContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDropTable(CentSqlParser::DropTableContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitInsertInto(CentSqlParser::InsertIntoContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDelete(CentSqlParser::DeleteContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRenameTable(CentSqlParser::RenameTableContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRenameColumn(CentSqlParser::RenameColumnContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDropColumn(CentSqlParser::DropColumnContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitAddColumn(CentSqlParser::AddColumnContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCreateView(CentSqlParser::CreateViewContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDropView(CentSqlParser::DropViewContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCall(CentSqlParser::CallContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitGrant(CentSqlParser::GrantContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRevoke(CentSqlParser::RevokeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowGrants(CentSqlParser::ShowGrantsContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExplain(CentSqlParser::ExplainContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowCreateTable(CentSqlParser::ShowCreateTableContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowCreateView(CentSqlParser::ShowCreateViewContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowTables(CentSqlParser::ShowTablesContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowSchemas(CentSqlParser::ShowSchemasContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowCatalogs(CentSqlParser::ShowCatalogsContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowColumns(CentSqlParser::ShowColumnsContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowStats(CentSqlParser::ShowStatsContext *ctx) {
		return implicitCast<Statement*>(new ShowStats(std::make_optional(getLocation(ctx)), new Table(getQualifiedName(ctx->qualifiedName()))));
	}

	antlrcpp::Any AstBuilder::visitShowStatsForQuery(CentSqlParser::ShowStatsForQueryContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowFunctions(CentSqlParser::ShowFunctionsContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitShowSession(CentSqlParser::ShowSessionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSetSession(CentSqlParser::SetSessionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitResetSession(CentSqlParser::ResetSessionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitStartTransaction(CentSqlParser::StartTransactionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCommit(CentSqlParser::CommitContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRollback(CentSqlParser::RollbackContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitPrepare(CentSqlParser::PrepareContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDeallocate(CentSqlParser::DeallocateContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExecute(CentSqlParser::ExecuteContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDescribeInput(CentSqlParser::DescribeInputContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDescribeOutput(CentSqlParser::DescribeOutputContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSetPath(CentSqlParser::SetPathContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitQuery(CentSqlParser::QueryContext *ctx) {
		Statement* queryStatement = CentSqlBaseVisitor::visit(ctx->queryNoWith());
		const auto body = dynamic_cast<Query*>(queryStatement);
		return implicitCast<Statement*>(new Query(
			getLocation(ctx),
			visitIfPresent<With*>(ctx->with()),
			body->getQueryBody(),
			body->getOrderBy(),
			body->getLimit())
		);
	}

	antlrcpp::Any AstBuilder::visitWith(CentSqlParser::WithContext *ctx) {		
		return new With(
			getLocation(ctx), 
			ctx->RECURSIVE() != nullptr, 
			castVector<WithQuery*>(visit(castVector<antlr4::ParserRuleContext*>(ctx->namedQuery())))
		);
	}

	antlrcpp::Any AstBuilder::visitTableElement(CentSqlParser::TableElementContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitColumnDefinition(CentSqlParser::ColumnDefinitionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitLikeClause(CentSqlParser::LikeClauseContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitProperties(CentSqlParser::PropertiesContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitProperty(CentSqlParser::PropertyContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitQueryNoWith(CentSqlParser::QueryNoWithContext *ctx) {
		Relation* queryTerm = CentSqlBaseVisitor::visit(ctx->queryTerm());
		std::optional<OrderBy*> orderBy;
		if (ctx->ORDER() != nullptr) {
			auto sortItems = castVector<SortItem*>(visit(castVector<antlr4::ParserRuleContext*>(ctx->sortItem())));
			orderBy.emplace(new OrderBy(getLocation(ctx->ORDER()), sortItems));
		}
		const auto query = dynamic_cast<QuerySpecification*>(queryTerm);
		if (query != nullptr) {
			return implicitCast<Statement*>(new Query(
				getLocation(ctx),
				std::optional<With*>(),
				new QuerySpecification(
					getLocation(ctx),
					query->getSelect(),
					query->getFrom(),
					query->getWhere(),
					query->getGroupBy(),
					query->getHaving(),
					orderBy,
					getTextIfPresent(ctx->limit)),
				std::optional<OrderBy*>(),
				std::optional<std::string>()
			));
		}
		const auto queryBody = dynamic_cast<QueryBody*>(queryTerm);
		if (queryBody != nullptr) {
			return implicitCast<Statement*>(
				new Query(
					getLocation(ctx),
					std::optional<With*>(),
					queryBody,
					orderBy,
					getTextIfPresent(ctx->limit))
				);
		}
		throw std::runtime_error("Missing query body");
	}

	antlrcpp::Any AstBuilder::visitQueryTermDefault(CentSqlParser::QueryTermDefaultContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSetOperation(CentSqlParser::SetOperationContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitQueryPrimaryDefault(CentSqlParser::QueryPrimaryDefaultContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitTable(CentSqlParser::TableContext *ctx) {
		return implicitCast<Relation*>(new Table(getLocation(ctx), getQualifiedName(ctx->qualifiedName())));
	}

	antlrcpp::Any AstBuilder::visitInlineTable(CentSqlParser::InlineTableContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSubquery(CentSqlParser::SubqueryContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSortItem(CentSqlParser::SortItemContext *ctx) {
		const auto ordering = getOrderingType(ctx->ordering);
		const auto nullOrdering = getNullOrderingType(ctx->nullOrdering);
		return new SortItem(getLocation(ctx),
			CentSqlBaseVisitor::visit(ctx->expression()),
			ordering,
			nullOrdering);
	}

	antlrcpp::Any AstBuilder::visitQuerySpecification(CentSqlParser::QuerySpecificationContext *ctx) {
		auto selectedItems = visit(castVector<antlr4::ParserRuleContext*>(ctx->selectItem()));
		auto relations = castVector<Relation*>(visit(castVector<antlr4::ParserRuleContext*>(ctx->relation())));
		std::optional<Relation*> from;
		if (!relations.empty()) {
			auto iterator = relations.cbegin();
			auto relation = *(iterator++);
			while (iterator != relations.cend()) {
				relation = implicitCast<Relation*>(
					new Join(
						getLocation(ctx), 
						Join::JoinType::IMPLICIT, 
						relation, 
						*iterator, 
						std::optional<JoinCriteria*>()
					)
				);
				++iterator;
			}
			from = std::make_optional(relation);
		}		
		return implicitCast<Relation*>(new QuerySpecification(
			getLocation(ctx),
			new Select(getLocation(ctx->SELECT()), isDistinct(ctx->setQuantifier()), castVector<SelectItem*>(selectedItems)),
			from,
			visitIfPresent<Expression*>(ctx->where),
			visitIfPresent<GroupBy*>(ctx->groupBy()),
			visitIfPresent<Expression*>(ctx->having),
			std::optional<OrderBy*>(),
			std::optional<std::string>()
		));		
	}

	antlrcpp::Any AstBuilder::visitGroupBy(CentSqlParser::GroupByContext *ctx) {
		auto visitResult = visit(castVector<antlr4::ParserRuleContext*>(ctx->groupingElement()));
		return new GroupBy(getLocation(ctx), isDistinct(ctx->setQuantifier()), castVector<GroupingElement*>(visitResult));
	}

	antlrcpp::Any AstBuilder::visitSingleGroupingSet(CentSqlParser::SingleGroupingSetContext *ctx) {		
		return implicitCast<GroupingElement*>(
			new SimpleGroupBy(
				getLocation(ctx), 
				castVector<Expression*>(visit(castVector<antlr4::ParserRuleContext*>(ctx->groupingSet()->expression())))
			)
		);
	}

	antlrcpp::Any AstBuilder::visitRollup(CentSqlParser::RollupContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCube(CentSqlParser::CubeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitMultipleGroupingSets(CentSqlParser::MultipleGroupingSetsContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitGroupingSet(CentSqlParser::GroupingSetContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitNamedQuery(CentSqlParser::NamedQueryContext *ctx) {
		std::optional<std::vector<Identifier*>> aliases;
		if (ctx->columnAliases() != nullptr) {
			aliases.emplace(castVector<Identifier*>(visit(castVector<antlr4::ParserRuleContext*>(ctx->columnAliases()->identifier()))));
		}
		return new WithQuery(
			getLocation(ctx),
			CentSqlBaseVisitor::visit(ctx->name),
			CentSqlBaseVisitor::visit(ctx->query()),
			aliases
		);
	}

	antlrcpp::Any AstBuilder::visitSetQuantifier(CentSqlParser::SetQuantifierContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSelectSingle(CentSqlParser::SelectSingleContext *ctx) {
		Expression* expr = CentSqlBaseVisitor::visit(ctx->expression());
		auto identifier = visitIfPresent<Expression*>(ctx->identifier());
		std::optional<Identifier*> alias;
		if (identifier.has_value()) {
			alias.emplace(dynamic_cast<Identifier*>(identifier.value()));
		}
		return implicitCast<SelectItem*>(
			new SingleColumn(
				getLocation(ctx), 
				expr,
				alias
			)
		);
	}

	antlrcpp::Any AstBuilder::visitSelectAll(CentSqlParser::SelectAllContext *ctx) {
		if (ctx->qualifiedName() != nullptr) {
			return implicitCast<SelectItem*>(new AllColumns(getLocation(ctx), getQualifiedName(ctx->qualifiedName())));
		}
		return implicitCast<SelectItem*>(new AllColumns(getLocation(ctx)));
	}
	
	antlrcpp::Any AstBuilder::visitRelationDefault(CentSqlParser::RelationDefaultContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitJoinRelation(CentSqlParser::JoinRelationContext *ctx) {
		Relation* left = CentSqlBaseVisitor::visit(ctx->left);		
		if (ctx->CROSS() != nullptr) {
			Relation* right = CentSqlBaseVisitor::visit(ctx->right);
			return implicitCast<Relation*>(
				new Join(getLocation(ctx), Join::CROSS, left, right, std::optional<JoinCriteria*>())
			);
		}
		Relation* right;
		JoinCriteria* criteria;
		if (ctx->NATURAL() != nullptr) {
			right = CentSqlBaseVisitor::visit(ctx->right);
			criteria = new NaturalJoin();
		} else {
			right = CentSqlBaseVisitor::visit(ctx->rightRelation);
			if (ctx->joinCriteria()->ON() != nullptr) {
				Expression* joinOnExpr = CentSqlBaseVisitor::visit(ctx->joinCriteria()->booleanExpression());
				criteria = new JoinOn(joinOnExpr);
			} else if (ctx->joinCriteria()->USING() != nullptr) {
				auto visitResult = visit(castVector<antlr4::ParserRuleContext*>(ctx->joinCriteria()->identifier()));
				std::vector<Identifier*> columns;
				for (auto& visitResultItem : visitResult) {
					columns.emplace_back(visitResultItem);
				}
				criteria = new JoinUsing(columns);
			} else {
				throw antlr4::IllegalArgumentException("Unsupported join criteria");
			}
		}
		Join::JoinType joinType;
		if (ctx->joinType()->LEFT() != nullptr) {
			joinType = Join::LEFT;
		} else if (ctx->joinType()->RIGHT() != nullptr) {
			joinType = Join::RIGHT;
		} else if (ctx->joinType()->FULL() != nullptr) {
			joinType = Join::FULL;
		} else {
			joinType = Join::INNER;
		}
		return implicitCast<Relation*>(new Join(getLocation(ctx), joinType, left, right, std::make_optional(criteria)));
	}

	antlrcpp::Any AstBuilder::visitJoinType(CentSqlParser::JoinTypeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitJoinCriteria(CentSqlParser::JoinCriteriaContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSampledRelation(CentSqlParser::SampledRelationContext *ctx) {
		Relation* child = CentSqlBaseVisitor::visit(ctx->aliasedRelation());
		if (ctx->TABLESAMPLE() == nullptr) {
			return child;
		}
		throw std::invalid_argument("IMPLEMENT SampledRelation");
	}

	antlrcpp::Any AstBuilder::visitSampleType(CentSqlParser::SampleTypeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitAliasedRelation(CentSqlParser::AliasedRelationContext *ctx) {
		Relation* child = CentSqlBaseVisitor::visit(ctx->relationPrimary());
		if (ctx->identifier() == nullptr) {
			return child;
		}
		auto aliases =
			(ctx->columnAliases() != nullptr)
			? castVector<Identifier*>(visit(castVector<antlr4::ParserRuleContext*>(ctx->columnAliases()->identifier())))
			: std::vector<Identifier*>();		
		Expression* expr = CentSqlBaseVisitor::visit(ctx->identifier());
		return implicitCast<Relation*>(
			new AliasedRelation(
				getLocation(ctx), child, dynamic_cast<Identifier*>(expr), aliases
			)
		);
	}

	antlrcpp::Any AstBuilder::visitColumnAliases(CentSqlParser::ColumnAliasesContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitTableName(CentSqlParser::TableNameContext *ctx) {
		return implicitCast<Relation*>(new Table(getLocation(ctx), getQualifiedName(ctx->qualifiedName())));
	}

	antlrcpp::Any AstBuilder::visitSubqueryRelation(CentSqlParser::SubqueryRelationContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitUnnest(CentSqlParser::UnnestContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitLateral(CentSqlParser::LateralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitParenthesizedRelation(CentSqlParser::ParenthesizedRelationContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExpression(CentSqlParser::ExpressionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitLogicalNot(CentSqlParser::LogicalNotContext *ctx) {
		return implicitCast<Expression*>(
			new NotExpression(getLocation(ctx), (Expression*)CentSqlBaseVisitor::visit(ctx->booleanExpression()))
			);
	}

	antlrcpp::Any AstBuilder::visitPredicated(CentSqlParser::PredicatedContext *ctx) {
		if (ctx->predicate() != nullptr) {
			return CentSqlBaseVisitor::visit(ctx->predicate());
		}
		return CentSqlBaseVisitor::visit(ctx->valueExpression());
	}

	antlrcpp::Any AstBuilder::visitLogicalBinary(CentSqlParser::LogicalBinaryContext *ctx) {
		return implicitCast<Expression*>(new LogicalBinaryExpression(
			getLocation(ctx->oper),
			getLogicalBinaryOperator(ctx->oper),
			CentSqlBaseVisitor::visit(ctx->left),
			CentSqlBaseVisitor::visit(ctx->right)
		));
	}

	antlrcpp::Any AstBuilder::visitComparison(CentSqlParser::ComparisonContext *ctx) {
		auto children = ctx->comparisonOperator()->children;
		if (children.empty()) {
			throw ParsingException("No children in comparison");
		}
		auto comparisonOp = (antlr4::tree::TerminalNode*)children.at(0);
		auto token = comparisonOp->getSymbol();
		antlrcpp::Any left = CentSqlBaseVisitor::visit(ctx->value);
		antlrcpp::Any right = CentSqlBaseVisitor::visit(ctx->right);
		return implicitCast<Expression*>(
			new ComparisonExpression(getLocation(ctx->comparisonOperator()),
				getComparisonOperator(token),
				left,
				right
			)
		);
	}

	antlrcpp::Any AstBuilder::visitQuantifiedComparison(CentSqlParser::QuantifiedComparisonContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitBetween(CentSqlParser::BetweenContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitInList(CentSqlParser::InListContext *ctx) {
		std::shared_ptr<Expression> fieldName = CentSqlBaseVisitor::visit(ctx->value);
		const auto fieldValues = visit(castVector<antlr4::ParserRuleContext*>(ctx->expression()));
		//auto res = castSharedPtrVector<std::shared_ptr<Expression>>(fieldValues);
		Expression* result = nullptr; /* new InPredicate(
			getLocation(ctx),
			fieldName,
			std::make_shared<InListExpression>(getLocation(ctx), castSharedPtrVector<std::shared_ptr<Expression>>(fieldValues)));
			*/
		if (ctx->NOT() != nullptr) {
			result = new NotExpression(getLocation(ctx), result);
		}
		return result;
	}

	antlrcpp::Any AstBuilder::visitInSubquery(CentSqlParser::InSubqueryContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitLike(CentSqlParser::LikeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitNullPredicate(CentSqlParser::NullPredicateContext *ctx) {
		Expression* child = CentSqlBaseVisitor::visit(ctx->value);
		if (ctx->NOT() == nullptr) {
			return new IsNullPredicate(getLocation(ctx), child);
		}
		return new IsNotNullPredicate(getLocation(ctx), child);
	}

	antlrcpp::Any AstBuilder::visitDistinctFrom(CentSqlParser::DistinctFromContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitValueExpressionDefault(CentSqlParser::ValueExpressionDefaultContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitConcatenation(CentSqlParser::ConcatenationContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitArithmeticBinary(CentSqlParser::ArithmeticBinaryContext *ctx) {
		return implicitCast<Expression*>(new ArithmeticBinaryExpression(
			getLocation(ctx->oper),
			getArithmeticBinaryOperator(ctx->oper),
			(Expression*)CentSqlBaseVisitor::visit(ctx->left),
			(Expression*)CentSqlBaseVisitor::visit(ctx->right))
		);
	}

	antlrcpp::Any AstBuilder::visitArithmeticUnary(CentSqlParser::ArithmeticUnaryContext *ctx) {
		auto child = (Expression*)CentSqlBaseVisitor::visit(ctx->valueExpression());
		switch (ctx->oper->getType())
		{
			case CentSqlLexer::MINUS:
				return new ArithmeticUnaryExpression(getLocation(ctx), ArithmeticUnaryExpression::MINUS, child);
			case CentSqlLexer::PLUS:
				return new ArithmeticUnaryExpression(getLocation(ctx), ArithmeticUnaryExpression::PLUS, child);
			default:
				throw ParsingException("Unsupported sign: " + ctx->oper->getText());
		}
	}

	antlrcpp::Any AstBuilder::visitAtTimeZone(CentSqlParser::AtTimeZoneContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDereference(CentSqlParser::DereferenceContext *ctx) {
		std::shared_ptr<Expression> expr = CentSqlBaseVisitor::visit(ctx->base);
		std::shared_ptr<Expression> ident = CentSqlBaseVisitor::visit(ctx->fieldName);
		return std::dynamic_pointer_cast<Expression>(
			std::make_shared<DereferenceExpression>(
				getLocation(ctx),  expr, std::dynamic_pointer_cast<Identifier>(ident)
				)
			);
	}

	antlrcpp::Any AstBuilder::visitTypeConstructor(CentSqlParser::TypeConstructorContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSpecialDateTimeFunction(CentSqlParser::SpecialDateTimeFunctionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSubstring(CentSqlParser::SubstringContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCast(CentSqlParser::CastContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitLambda(CentSqlParser::LambdaContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitParenthesizedExpression(CentSqlParser::ParenthesizedExpressionContext *ctx) {
		return CentSqlBaseVisitor::visit(ctx->expression());
	}

	antlrcpp::Any AstBuilder::visitParameter(CentSqlParser::ParameterContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitNormalize(CentSqlParser::NormalizeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitIntervalLiteral(CentSqlParser::IntervalLiteralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitNumericLiteral(CentSqlParser::NumericLiteralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitBooleanLiteral(CentSqlParser::BooleanLiteralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSimpleCase(CentSqlParser::SimpleCaseContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitColumnReference(CentSqlParser::ColumnReferenceContext *ctx) {
		return CentSqlBaseVisitor::visit(ctx->identifier());
	}

	antlrcpp::Any AstBuilder::visitNullLiteral(CentSqlParser::NullLiteralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRowConstructor(CentSqlParser::RowConstructorContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSubscript(CentSqlParser::SubscriptContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCurrentPath(CentSqlParser::CurrentPathContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSubqueryExpression(CentSqlParser::SubqueryExpressionContext *ctx) {
		return new SubqueryExpression(getLocation(ctx), (Query*)CentSqlBaseVisitor::visit(ctx->query()));
	}

	antlrcpp::Any AstBuilder::visitBinaryLiteral(CentSqlParser::BinaryLiteralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCurrentUser(CentSqlParser::CurrentUserContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExtract(CentSqlParser::ExtractContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitStringLiteral(CentSqlParser::StringLiteralContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitArrayConstructor(CentSqlParser::ArrayConstructorContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitFunctionCall(CentSqlParser::FunctionCallContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExists(CentSqlParser::ExistsContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitPosition(CentSqlParser::PositionContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSearchedCase(CentSqlParser::SearchedCaseContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitGroupingOperation(CentSqlParser::GroupingOperationContext *ctx) {
		
		const auto& qualifiedNames = ctx->qualifiedName();
		std::vector<QualifiedName*> arguments;
		for (const auto& qualifiedName : qualifiedNames) {
			arguments.emplace_back(getQualifiedName(qualifiedName));
		}
		return new GroupingOperation(std::make_optional(getLocation(ctx)), arguments);
	}

	antlrcpp::Any AstBuilder::visitBasicStringLiteral(CentSqlParser::BasicStringLiteralContext *ctx) {
		std::string value = ctx->getText();
		removeQuotes(value);
		return std::dynamic_pointer_cast<Expression>(std::make_shared<StringLiteral>(getLocation(ctx), value));
	}

	antlrcpp::Any AstBuilder::visitUnicodeStringLiteral(CentSqlParser::UnicodeStringLiteralContext *ctx) {
		std::string value = ctx->getText();
		removeQuotes(value);
		return std::dynamic_pointer_cast<Expression>(std::make_shared<StringLiteral>(getLocation(ctx), value));  // todo: convert to unicode
	}

	antlrcpp::Any AstBuilder::visitTimeZoneInterval(CentSqlParser::TimeZoneIntervalContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitTimeZoneString(CentSqlParser::TimeZoneStringContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitComparisonOperator(CentSqlParser::ComparisonOperatorContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitComparisonQuantifier(CentSqlParser::ComparisonQuantifierContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitBooleanValue(CentSqlParser::BooleanValueContext *ctx) {
		return implicitCast<Expression*>(new BooleanLiteral(getLocation(ctx), ctx->getText()));
	}

	antlrcpp::Any AstBuilder::visitInterval(CentSqlParser::IntervalContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitIntervalField(CentSqlParser::IntervalFieldContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitNormalForm(CentSqlParser::NormalFormContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitType(CentSqlParser::TypeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitTypeParameter(CentSqlParser::TypeParameterContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitBaseType(CentSqlParser::BaseTypeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitWhenClause(CentSqlParser::WhenClauseContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitFilter(CentSqlParser::FilterContext *ctx) {
		return CentSqlBaseVisitor::visit(ctx->booleanExpression());
	}

	antlrcpp::Any AstBuilder::visitOver(CentSqlParser::OverContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitWindowFrame(CentSqlParser::WindowFrameContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitUnboundedFrame(CentSqlParser::UnboundedFrameContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitCurrentRowBound(CentSqlParser::CurrentRowBoundContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitBoundedFrame(CentSqlParser::BoundedFrameContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExplainFormat(CentSqlParser::ExplainFormatContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitExplainType(CentSqlParser::ExplainTypeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitIsolationLevel(CentSqlParser::IsolationLevelContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitTransactionAccessMode(CentSqlParser::TransactionAccessModeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitReadUncommitted(CentSqlParser::ReadUncommittedContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitReadCommitted(CentSqlParser::ReadCommittedContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitRepeatableRead(CentSqlParser::RepeatableReadContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitSerializable(CentSqlParser::SerializableContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitPositionalArgument(CentSqlParser::PositionalArgumentContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitNamedArgument(CentSqlParser::NamedArgumentContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitQualifiedArgument(CentSqlParser::QualifiedArgumentContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitUnqualifiedArgument(CentSqlParser::UnqualifiedArgumentContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitPathSpecification(CentSqlParser::PathSpecificationContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitPrivilege(CentSqlParser::PrivilegeContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitQualifiedName(CentSqlParser::QualifiedNameContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitUnquotedIdentifier(CentSqlParser::UnquotedIdentifierContext *ctx) {
		return std::dynamic_pointer_cast<Expression>(std::make_shared<Identifier>(getLocation(ctx), ctx->getText(), false));
	}

	antlrcpp::Any AstBuilder::visitQuotedIdentifier(CentSqlParser::QuotedIdentifierContext *ctx) {
		const auto& token = ctx->getText(); 
		auto identifier = token.substr(1, token.length() - 1); 
		replace(identifier, "\"\"", "\"");
		return implicitCast<Expression*>(new Identifier(getLocation(ctx), identifier, true));
	}

	antlrcpp::Any AstBuilder::visitBackQuotedIdentifier(CentSqlParser::BackQuotedIdentifierContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDigitIdentifier(CentSqlParser::DigitIdentifierContext *ctx) {
		return visitChildren(ctx);
	}

	antlrcpp::Any AstBuilder::visitDecimalLiteral(CentSqlParser::DecimalLiteralContext *ctx) {
		switch (parsingOptions_.getDecimalLiteralTreatment()) {
			case ParsingOptions::AS_DOUBLE:
				return implicitCast<Expression*>(new DoubleLiteral(getLocation(ctx), ctx->getText()));
			case ParsingOptions::AS_DECIMAL:
				return implicitCast<Expression*>(new DecimalLiteral(getLocation(ctx), ctx->getText()));
			case ParsingOptions::REJECT:
				throw ParsingException("Unexpected decimal literal");
			default:
				throw std::invalid_argument(ctx->getText());
		}
	}

	antlrcpp::Any AstBuilder::visitDoubleLiteral(CentSqlParser::DoubleLiteralContext *ctx) {
		return std::dynamic_pointer_cast<Expression>(std::make_shared <DoubleLiteral>(getLocation(ctx), ctx->getText()));
	}

	antlrcpp::Any AstBuilder::visitIntegerLiteral(CentSqlParser::IntegerLiteralContext *ctx) {
		return std::dynamic_pointer_cast<Expression>(std::make_shared<LongLiteral>(getLocation(ctx), ctx->getText()));
	}

	antlrcpp::Any AstBuilder::visitNonReserved(CentSqlParser::NonReservedContext *ctx) {
		return visitChildren(ctx);
	}
		
	QualifiedName* AstBuilder::getQualifiedName(CentSqlParser::QualifiedNameContext* ctx) {		
		auto visitResults = visit(castVector<antlr4::ParserRuleContext*>(ctx->identifier()));
		std::vector<std::string> parts;
		for (auto& visitResult : visitResults) {
			std::shared_ptr<Expression> item = visitResult;
			parts.emplace_back(std::dynamic_pointer_cast<Identifier>(item)->getValue());
		}
		return new QualifiedName(parts);
	}

	std::optional<std::string> AstBuilder::getTextIfPresent(antlr4::ParserRuleContext* ctx)
	{
		if (ctx != nullptr) {
			return ctx->getText();
		}
		return std::optional<std::string>();
	}

	std::optional<std::string> AstBuilder::getTextIfPresent(antlr4::Token* token)
	{
		if (token != nullptr) {
			return token->getText();
		}
		return std::optional<std::string>();
	}

	LogicalBinaryExpression::Operator getLogicalBinaryOperator(antlr4::Token* token)
	{
		switch (token->getType()) {
			case CentSqlLexer::AND:
				return LogicalBinaryExpression::Operator::AND;
			case CentSqlLexer::OR:
				return LogicalBinaryExpression::Operator::OR;
			default:
				throw std::invalid_argument(token->getText());
		}
	}

	static ComparisonExpression::Operator getComparisonOperator(antlr4::Token* symbol)
	{
		switch (symbol->getType()) {
			case CentSqlLexer::EQ:
				return ComparisonExpression::Operator::EQUAL;
			case CentSqlLexer::NEQ:
				return ComparisonExpression::Operator::NOT_EQUAL;
			case CentSqlLexer::LT:
				return ComparisonExpression::Operator::LESS_THAN;
			case CentSqlLexer::LTE:
				return ComparisonExpression::Operator::LESS_THAN_OR_EQUAL;
			case CentSqlLexer::GT:
				return ComparisonExpression::Operator::GREATER_THAN;
			case CentSqlLexer::GTE:
				return ComparisonExpression::Operator::GREATER_THAN_OR_EQUAL;
			default:
				throw std::invalid_argument(symbol->getText());

		}
	}

	static ArithmeticBinaryExpression::Operator getArithmeticBinaryOperator(antlr4::Token* symbol)
	{
		switch (symbol->getType()) {
			case CentSqlLexer::PLUS:
				return ArithmeticBinaryExpression::Operator::ADD;
			case CentSqlLexer::MINUS:
				return ArithmeticBinaryExpression::Operator::SUBTRACT;
			case CentSqlLexer::ASTERISK:
				return ArithmeticBinaryExpression::Operator::MULTIPLY;
			case CentSqlLexer::SLASH:
				return ArithmeticBinaryExpression::Operator::DIVIDE;
			case CentSqlLexer::PERCENT:
				return ArithmeticBinaryExpression::Operator::MODULUS;
			default:
				throw std::invalid_argument(symbol->getText());
		}
	}

	static SortItem::Ordering getOrderingType(antlr4::Token* token)
	{
		if (token == nullptr) {
			return SortItem::Ordering::Ascending;
		}
		switch (token->getType()) {
		case CentSqlLexer::ASC:
			return SortItem::Ordering::Ascending;
		case CentSqlLexer::DESC:
			return SortItem::Ordering::Descending;
		default:
			throw std::invalid_argument("Unsupported ordering type");
		}
	}
		
	static SortItem::NullOrdering getNullOrderingType(antlr4::Token* token)
	{
		if (token == nullptr) {
			return SortItem::NullOrdering::Undefined;
		}
		switch (token->getType()) {
			case CentSqlLexer::FIRST:
				return SortItem::NullOrdering::First;
			case CentSqlLexer::LAST:
				return SortItem::NullOrdering::Last;
			default:
				throw std::invalid_argument("Unsupported null ordering type");
		}
	}

	template<typename T>
	inline std::optional<T> AstBuilder::visitIfPresent(antlr4::ParserRuleContext* context)
	{
		if (context != nullptr) {
			auto visitResult = CentSqlBaseVisitor::visit(context);
			if (visitResult.isNotNull()) {
				T tmp = visitResult;
				return std::make_optional(tmp);
			}
		}
		return std::optional<T>();
	}
}
