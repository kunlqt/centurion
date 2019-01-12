#pragma once

#include "QualifiedName.h"
#include "NodeLocation.h"
#include "Utils.h"
#include <antlr4-runtime.h>
#include <optional>
#include <vector>
#include <regex>

namespace centurion {
	class AstVisitor;

	class Node {

public:
		virtual std::optional<NodeLocation> getLocation() const { return location_; }
		virtual std::vector<Node*> getChildren()  const = 0;
		virtual int hashCode() const = 0;
		virtual bool equals(const Node& node) const = 0;
		virtual std::string toString() const = 0;

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context);

	protected:
		// protected:
		Node(std::optional<NodeLocation> location) : location_(location) { }
		virtual ~Node() {};
	private:
		std::optional<NodeLocation> location_;
	};

	class Expression : public Node {
	public:
		Expression(std::optional<NodeLocation> location) : Node(location) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "Expression";
		}
	};

	class Identifier : public Expression {
	public:
		Identifier(std::optional<NodeLocation> location, std::string value, bool delimited)
			:
			Expression(location),
			namePattern_("[a-zA-Z_]([a-zA-Z0-9_:@])*"),
			location_(location),
			value_(std::move(value)),
			delimited_(delimited)
		{

		}

		Identifier(NodeLocation location, std::string value, bool delimited)
			: Identifier(std::optional<NodeLocation>(location), value, delimited)
		{

		}

		Identifier(std::string value, bool delimited)
			:
			Identifier(std::optional<NodeLocation>(), value, delimited)
		{

		}

		Identifier(std::string value)
			:
			Identifier(std::optional<NodeLocation>(), value, false)
		{
			delimited_ = std::regex_match(value, namePattern_);
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>();
		}

		virtual int hashCode() const override {
			return (int)std::hash_value(value_);
		}

		virtual bool equals(const Node& node) const override {
			//return getValue() == node.getValue();
			return true;
		}

		virtual std::string toString() const override {
			return "Identifier";
		}

		virtual std::string getValue() const {
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

	class DereferenceExpression : public Expression {
	private:
		Expression* base_;
		Identifier* field_;

	public:
		DereferenceExpression(Expression* base, Identifier* field)
			: DereferenceExpression(std::optional<NodeLocation>(), base, field)
		{

		}

		DereferenceExpression(NodeLocation location, Expression* base, Identifier* field)
			: DereferenceExpression(std::make_optional(location), base, field)
		{

		}

		DereferenceExpression(std::optional<NodeLocation> location, Expression* base, Identifier* field)
			: Expression(location), base_(base), field_(field)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ base_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "DereferenceExpression";
		}

		static QualifiedName* getQualifiedName(DereferenceExpression* expression)
		{
			std::vector<std::string> parts = tryParseParts(expression->getBase(), toLowerCopy(expression->getField()->getValue()));
			if (parts.empty())
				return nullptr;
			return new QualifiedName(parts);
		}

		static std::vector<std::string> tryParseParts(Expression* base, std::string fieldName)
		{
			Identifier* identifier = dynamic_cast<Identifier*>(base);
			if (identifier) {
				return std::vector<std::string> { identifier->getValue() };
			} 
			DereferenceExpression* dereferenceExpression = dynamic_cast<DereferenceExpression*>(base);
			if (dereferenceExpression) {
				QualifiedName* baseQualifiedName = getQualifiedName(dereferenceExpression);
				if (baseQualifiedName != nullptr) {
					auto newList = baseQualifiedName->getParts();
					newList.push_back(fieldName);
					return newList;
				}
			}
			return std::vector<std::string>();
		}

		static Expression* from(const QualifiedName& name) {
			Expression* result = nullptr;
			for (const auto& part : name.getParts()) {
				if (result == nullptr) {
					result = new Identifier(part);
				} else {
					result = new DereferenceExpression(result, new Identifier(part));
				}
			}
			return result;
		}

		Expression* getBase() const {
			return base_;
		}

		Identifier* getField() const {
			return field_;
		}

	};

	class Literal : public Expression {
	public:
		Literal(std::optional<NodeLocation> location) : Expression(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "Literal";
		}

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>();
		}
	};

	class StringLiteral : public Literal {
	public:
		StringLiteral(std::string value)
			: StringLiteral(std::optional<NodeLocation>(), value) { }

		StringLiteral(const NodeLocation& location, std::string value)
			: StringLiteral(std::make_optional(location), value) { }

		StringLiteral(std::optional<NodeLocation> location, std::string value) 
		: Literal(location)
		, value_(std::move(value)) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "StringLiteral";
		}

		virtual int hashCode() const override {
			std::hash<std::string> h;
			return (int)h(value_);
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		std::string getValue() const {
			return value_;
		}


	private:
		std::string value_;
	};

	class DecimalLiteral : public Literal {
	public:
		DecimalLiteral(std::string value)
			: DecimalLiteral(std::optional<NodeLocation>(), value) { }

		DecimalLiteral(const NodeLocation& location, std::string value)
			: DecimalLiteral(std::make_optional(location), value) { }

		DecimalLiteral(std::optional<NodeLocation> location, std::string value) : Literal(location), value_(std::move(value)) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "DecimalLiteral";
		}

		virtual int hashCode() const override {
			std::hash<std::string> h;
			return (int)h(value_);
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		std::string getValue() const {
			return value_;
		}

	private:
		std::string value_;
	};

	class DoubleLiteral : public Literal {
	public:
		DoubleLiteral(const std::string& value)
			: DoubleLiteral(std::optional<NodeLocation>(), value) { }

		DoubleLiteral(const NodeLocation& location, const std::string& value)
			: DoubleLiteral(std::make_optional(location), value) { }

		DoubleLiteral(std::optional<NodeLocation> location, const std::string& value) 
		: Literal(location)
		, value_(std::stod(value)) { }

		DoubleLiteral(std::optional<NodeLocation> location, double value) 
		: Literal(location)
		, value_(value) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "DoubleLiteral";
		}

		double getValue() const {
			return value_;
		}

		virtual int hashCode() const override {
			return ((int)value_);
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

	private:
		double value_;
	};

	class LongLiteral : public Literal {
	public:
		LongLiteral(const std::string& value)
			: LongLiteral(std::optional<NodeLocation>(), value) {
		}

		LongLiteral(const NodeLocation& location, const std::string& value)
			: LongLiteral(std::make_optional(location), value) {
		}

		LongLiteral(std::optional<NodeLocation> location, const std::string& value) 
		: Literal(location)
		, value_(std::atol(value.c_str())) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "LongLiteral";
		}

		long getValue() const {
			return value_;
		}

		virtual int hashCode() const override {
			return (value_);
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}


	private:
		long value_;
	};


	class BooleanLiteral : public Literal {
	public:
		BooleanLiteral(const std::string& value)
			: BooleanLiteral(std::optional<NodeLocation>(), value) {
		}

		BooleanLiteral(const NodeLocation& location, const std::string& value)
			: BooleanLiteral(std::make_optional(location), value) {
		}

		BooleanLiteral(std::optional<NodeLocation> location, const std::string& value) 
		: Literal(location)
		, value_(toLowerCopy(value) == "true") { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "BooleanLiteral";
		}

		bool getValue() const {
			return value_;
		}

		virtual int hashCode() const override {
			return (value_);
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}


	private:
		bool value_;
	};

	class ArithmeticBinaryExpression : public Expression {
	public:
		struct Operator {
			static Operator ADD;
			static Operator SUBTRACT;
			static Operator MULTIPLY;
			static Operator DIVIDE;
			static Operator MODULUS;

			bool operator==(const ArithmeticBinaryExpression::Operator& other) const {
				return op_ == other.op_;
			}

			friend std::ostream& operator<< (std::ostream& stream, const Operator& oper) {
				stream << oper.value_;
				return stream;
			}

		private:
			enum openum { Add, Subtract, Multiply, Divide, Modulus };
			Operator(openum op, std::string value) : value_(std::move(value)), op_(op) { }
			std::string value_;
			openum op_;
		};

		ArithmeticBinaryExpression(Operator oper, Expression* left, Expression* right)
			:
			ArithmeticBinaryExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		ArithmeticBinaryExpression(NodeLocation location, Operator oper, Expression* left, Expression* right)
			:
			ArithmeticBinaryExpression(std::make_optional(location), oper, left, right) {
		}

		ArithmeticBinaryExpression(std::optional<NodeLocation> location, Operator oper, Expression* left, Expression* right)
			:
			Expression(location), operator_(oper), left_(left), right_(right) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "ArithmeticBinaryExpression";
		}

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ left_, right_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		Operator getOperator() { return operator_; }
		Expression* getLeft() { return left_; }
		Expression* getRight() { return right_; }

	private:
		Operator operator_;
		Expression* left_;
		Expression* right_;
	};

	class ArithmeticUnaryExpression : public Expression {
	public:
		enum Sign {
			PLUS, MINUS
		};

		ArithmeticUnaryExpression(Sign sign, Expression* left)
			:
			ArithmeticUnaryExpression(std::optional<NodeLocation>(), sign, left) {
		}

		ArithmeticUnaryExpression(NodeLocation location, Sign sign, Expression* value)
			:
			ArithmeticUnaryExpression(std::make_optional(location), sign, value) {
		}

		ArithmeticUnaryExpression(std::optional<NodeLocation> location, Sign sign, Expression* value)
			:
			Expression(location), sign_(sign), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "ArithmeticUnaryExpression";
		}

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ value_};
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		Sign getSign() { return sign_; }
		Expression* getValue() { return value_; }


	private:
		Sign sign_;
		Expression* value_;

	};

	class ComparisonExpression : public Expression {
	public:
		struct Operator {
			static Operator EQUAL;
			static Operator NOT_EQUAL;
			static Operator LESS_THAN;
			static Operator LESS_THAN_OR_EQUAL;
			static Operator GREATER_THAN;
			static Operator GREATER_THAN_OR_EQUAL;
			static Operator IS_DISTINCT_FROM;

			bool operator==(const ComparisonExpression::Operator& other) const {
				return op_ == other.op_;
			}

			friend std::ostream& operator<< (std::ostream& stream, const Operator& oper) {
				stream << oper.name_;
				return stream;
			}

		private:
			enum openum { Equal , NotEqual
			, LessThan
			, LessThanOrEqual
			, GreaterThan
			, GreaterThanOrEqual
			, IsDistinctFrom
			};
			Operator(openum op, const std::string& name) : name_(name), op_(op) { }
			std::string name_;
			openum op_;
		};

		ComparisonExpression(const Operator& oper, Expression* left, Expression* right)
			:
			ComparisonExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		ComparisonExpression(NodeLocation location, const Operator& oper, Expression* left, Expression* right)
			:
			ComparisonExpression(std::make_optional(location), oper, left, right) {
		}

		ComparisonExpression(std::optional<NodeLocation> location, const Operator& oper, Expression* left, Expression* right)
			:
			Expression(location), operator_(oper), left_(left), right_(right) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "ComparisonExpression";
		}

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			result.push_back(left_);
			result.push_back(right_);
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		Operator getOperator() const { return operator_; }
		Expression* getLeft() const { return left_; }
		Expression* getRight() const { return right_; }



	private:
		Operator operator_;
		Expression* left_;
		Expression* right_;
	};

	class InListExpression : public Expression
	{
	public:
		InListExpression(std::vector<Expression*> values)
			: InListExpression(std::optional<NodeLocation>(), values) {}

		InListExpression(NodeLocation location, std::vector<Expression*> values)
			: InListExpression(std::make_optional(location), values) {}

		InListExpression(std::optional<NodeLocation> location, std::vector<Expression*> values)
			: Expression(location), values_(std::move(values)) {}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override
		{
			std::vector<Node*> result;
			for (Expression* value : values_)
			{
				result.push_back(value);
			}
			return result;
		}
		virtual int hashCode() const  override
		{
			return 0;
		}
		virtual bool equals(const Node& node) const override
		{
			return false;
		}
		virtual std::string toString() const override
		{
			return "InListExpression";
		}

		std::vector<Expression*> getValues() const { return values_; }

	private:
		std::vector<Expression*> values_;
	};

	class LogicalBinaryExpression : public Expression {
	public:		
		struct Operator {
			static Operator AND;
			static Operator OR;

			bool operator==(const LogicalBinaryExpression::Operator& other) const {
				return op_ == other.op_;
			}

			friend std::ostream& operator<< (std::ostream& stream, const Operator& oper) {
				stream << oper.name_;
				return stream;
			}

		private:
			enum openum { And, Or };
			Operator(openum op, const std::string& name) : name_(name), op_(op) { }
			std::string name_;
			openum op_;
		};

		LogicalBinaryExpression(Operator oper, Expression* left, Expression* right)
			:
			LogicalBinaryExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		LogicalBinaryExpression(NodeLocation location, Operator oper, Expression* left, Expression* right)
			:
			LogicalBinaryExpression(std::make_optional(location), oper, left, right) {
		}

		LogicalBinaryExpression(std::optional<NodeLocation> location, Operator oper, Expression* left, Expression* right)
			:
			Expression(location), operator_(oper), left_(left), right_(right) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "LogicalBinaryExpression";
		}

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			result.push_back(left_);
			result.push_back(right_);
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		Operator getOperator() { return operator_; }
		Expression* getLeft() { return left_; }
		Expression* getRight() { return right_; }

	private:
		Operator operator_;
		Expression* left_;
		Expression* right_;
	};

	class NotExpression : public Expression {
	public:
		NotExpression(Expression* value)
			:
			NotExpression(std::optional<NodeLocation>(), value) {
		}

		NotExpression(NodeLocation location, Expression* value)
			:
			NotExpression(std::make_optional(location), value) {
		}

		NotExpression(std::optional<NodeLocation> location, Expression* value)
			:
			Expression(location), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "NotExpression";
		}

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			result.push_back(value_);
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		Expression* getValue() const { return value_; }

	private:
		Expression* value_;
	};

	class Statement : public Node {
	public:
		Statement(std::optional<NodeLocation> location) : Node(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

	};

	class Relation : public Node {
	public:
		Relation(std::optional<NodeLocation> location) : Node(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

	};

	class QueryBody : public Relation {
	public:
		QueryBody(std::optional<NodeLocation> location) : Relation(location) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

	};

	class SortItem : public Node {
	public:
		enum Ordering { Ascending, Descending };
		enum NullOrdering { First, Last, Undefined };

		SortItem(std::optional<NodeLocation> location, Expression* sortKey, Ordering ordering, NullOrdering nullOrdering)
			:
			Node(location), sortKey_(sortKey), ordering_(ordering), nullOrdering_(nullOrdering)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result{ sortKey_ };
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "SortItem";
		}

		Expression* getSortKey() const {
			return sortKey_;
		}

		Ordering getOrdering() const {
			return ordering_;
		}

		NullOrdering getNullOrdering() const {
			return nullOrdering_;
		}


	private:
		Expression* sortKey_;
		SortItem::Ordering ordering_;
		SortItem::NullOrdering nullOrdering_;

	};

	class OrderBy : public Node {
	public:
		OrderBy(const std::vector<SortItem*>& sortItems)
			: OrderBy(std::optional<NodeLocation>(), sortItems)
		{

		}

		OrderBy(const NodeLocation& location, const std::vector<SortItem*>& sortItems)
			: OrderBy(std::make_optional(location), sortItems)
		{

		}

		OrderBy(std::optional<NodeLocation> location, const std::vector<SortItem*>& sortItems)
			:
			Node(location), sortItems_(sortItems)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			for (const auto& sortItem : sortItems_) {
				result.push_back(sortItem);
			}
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "OrderBy";
		}

		std::vector<SortItem*> getSortItems() const {
			return sortItems_;
		}

	private:
		std::vector<SortItem*> sortItems_;
	};

	class With;

	class Query : public Statement {
	public:
		Query(std::optional<With*> with,
			QueryBody* queryBody,
			std::optional<OrderBy*> orderBy,
			const std::optional<std::string>& limit)
			:
			Query(std::optional<NodeLocation>(), with, queryBody, orderBy, limit) {
		}

		Query(const NodeLocation& location,
			std::optional<With*> with,
			QueryBody* queryBody,
			std::optional<OrderBy*> orderBy,
			const std::optional<std::string>& limit)
			:
			Query(std::optional<NodeLocation>(location), with, queryBody, orderBy, limit) {
		}

		Query(std::optional<NodeLocation> location,
			std::optional<With*> with,
			QueryBody* queryBody,
			std::optional<OrderBy*> orderBy,
			const std::optional<std::string>& limit)
			:
			Statement(location), with_(with), queryBody_(queryBody), orderBy_(orderBy), limit_(limit) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			if (with_.has_value()) {
				result.push_back((Node*)with_.value());
			}
			if (orderBy_.has_value()) {
				result.push_back((Node*)orderBy_.value());
			}
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Query";
		}

		std::optional<With*> getWith() const
		{
			return with_;
		}

		QueryBody* getQueryBody() const
		{
			return queryBody_;
		}

		std::optional<OrderBy*> getOrderBy() const
		{
			return orderBy_;
		}

		std::optional<std::string> getLimit() const
		{
			return limit_;
		}


	private:
		std::optional<With*> with_;
		QueryBody* queryBody_;
		std::optional<OrderBy*> orderBy_;
		std::optional<std::string> limit_;
	};

	class WithQuery : public Node {
	public:
		WithQuery(Identifier* name, Query* query, const std::optional<std::vector<Identifier*>>& columnNames)
			:
			WithQuery(std::optional<NodeLocation>(), name, query, columnNames)
		{ }

		WithQuery(const NodeLocation& location, Identifier* name, Query* query, const std::optional<std::vector<Identifier*>>& columnNames)
			:
			WithQuery(std::optional<NodeLocation>(location), name, query, columnNames)
		{ }

		WithQuery(std::optional<NodeLocation> location, Identifier* name, Query* query, const std::optional<std::vector<Identifier*>>& columnNames)
			:
			Node(location),
			name_(name),
			query_(query),
			columnNames_(columnNames)
		{ }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ query_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "WithQuery";
		}

		Identifier* getName() const {
			return name_;
		}

		Query* getQuery() const {
			return query_;
		}

		std::optional<std::vector<Identifier*>> getColumnNames() const {
			return columnNames_;
		}

	private:
		Identifier* name_;
		centurion::Query* query_;
		std::optional<std::vector<Identifier*>> columnNames_;
	};

	class With : public Node {
	public:
		With(bool recursive, std::vector<WithQuery*>& queries)
			: With(std::optional<NodeLocation>(), recursive, queries) {

		}

		With(const NodeLocation& location, bool recursive, std::vector<WithQuery*>& queries)
			: With(std::optional<NodeLocation>(location), recursive, queries) {

		}

		With(std::optional<NodeLocation> location, bool recursive, std::vector<WithQuery*>& queries)
			: Node(location), recursive_(recursive) {
			for (auto item : queries) {
				queries_.push_back(item);
			}
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			for (auto& item : queries_) {
				result.push_back(item);
			}
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "With";
		}

		bool isRecursive() const {
			return recursive_;
		}

		std::vector<WithQuery*> getQueries() const {
			return queries_;
		};


	private:
		bool recursive_;
		std::vector<WithQuery*> queries_;
	};

	class SubqueryExpression : public Expression
	{
	public:
		SubqueryExpression(Query* query) : SubqueryExpression(std::optional<NodeLocation>(), query) { }
		SubqueryExpression(NodeLocation location, Query* query) : SubqueryExpression(std::make_optional(location), query) { }
		SubqueryExpression(std::optional<NodeLocation> location, Query* query)
			: Expression(location), query_(query) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "SubqueryExpression";
		}

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ query_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		Query* getQuery() const { return query_; }

	private:
		Query* query_;
	};

	class SelectItem : public Node {
	public:
		SelectItem(std::optional<NodeLocation> location) : Node(location) { }

	};

	class SingleColumn : public SelectItem {
	public:
		SingleColumn(Expression* expression)
			: SingleColumn(std::optional<NodeLocation>(), expression, std::optional<Identifier*>())
		{
		}

		SingleColumn(
			Expression* expression,
			std::optional<Identifier*> alias)
			:
			SingleColumn(std::optional<NodeLocation>(), expression, std::optional<Identifier*>(alias))
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

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ expression_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "SingleColumn";
		}

		std::optional<Identifier*> getAlias() const { return alias_; }
		Expression* getExpression() const { return expression_; }

	private:
		Expression* expression_;
		std::optional<Identifier*> alias_;		
	};

	class AliasedRelation : public Relation {
	public:
		AliasedRelation(std::optional<NodeLocation> location, Relation* relation, Identifier* alias, const std::vector<Identifier*>& columnNames)
			: Relation(location), relation_(relation), alias_(alias)
		{
			for (const auto& col : columnNames_) {
				columnNames_.push_back(col);
			}
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			result.push_back(relation_);
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "AliasedRelation";
		}

		Relation* getRelation() const { return relation_; }
		Identifier* getAlias() const { return alias_; }
		std::vector<Identifier*> getColumnNames() const { return columnNames_; }

	private:
		std::optional<NodeLocation> location_;
		Relation* relation_;
		Identifier* alias_;
		std::vector<Identifier*> columnNames_;
	};

	class AllColumns : public SelectItem {
	public:
		AllColumns()
			: SelectItem(std::optional<NodeLocation>())
			, prefix_(std::optional<QualifiedName>())
		{
		}

		AllColumns(const NodeLocation& location)
			: SelectItem(std::optional<NodeLocation>(location))
			, prefix_(std::optional<QualifiedName>())
		{
		}

		AllColumns(const QualifiedName& prefix)
			: AllColumns(std::optional<NodeLocation>() , prefix) 
		{
		}

		AllColumns(const NodeLocation& location, const QualifiedName& prefix)
			: AllColumns(std::optional<NodeLocation>(location), prefix) 
		{
		}

		AllColumns(std::optional<NodeLocation> location, const QualifiedName& prefix)
			: SelectItem(location), prefix_(prefix) {
		}

		antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>();
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "AllColumns";
		}

		std::optional<QualifiedName> getPrefix() const {
			return prefix_;
		}

	private:
		std::optional<QualifiedName> prefix_;
	};

	class GroupingElement : public Node {
	public:
		GroupingElement(std::optional<NodeLocation> location) : Node(location) { }
		virtual std::vector<Expression*> getExpressions() const = 0;
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;
	};

	class GroupBy : public Node {
	public:
		GroupBy(bool distinct, const std::vector<GroupingElement*> groupingElements)
			: GroupBy(std::nullopt, distinct, groupingElements) {

		}

		GroupBy(const NodeLocation& location, bool distinct, const std::vector<GroupingElement*> groupingElements)
			: GroupBy(std::optional<NodeLocation>(location), distinct, groupingElements) {

		}

		GroupBy(const std::optional<NodeLocation>& location, bool distinct, const std::vector<GroupingElement*> groupingElements)
			: Node(location), distinct_(distinct), groupingElements_(groupingElements) {

		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			for (const auto& selectItem : groupingElements_) {
				result.push_back(selectItem);
			}
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "GroupBy";
		}

		bool isDistinct() const { return distinct_; }

		std::vector<GroupingElement*> getGroupingElements() const { return groupingElements_; };


	private:
		bool distinct_;
		std::vector<GroupingElement*> groupingElements_;
	};

	class GroupingOperation : public Expression {
	public:
		GroupingOperation(const std::optional<NodeLocation>& location, const std::vector<QualifiedName>& groupingColumns) : Expression(location) {
			for (const auto& groupingColumn : groupingColumns) {
				groupingColumns_.push_back(DereferenceExpression::from(groupingColumn));
			}
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>();
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "GroupingOperation";
		}

		std::vector<Expression*> getGroupingColumns() const {
			return groupingColumns_;
		}

	private:
		std::vector<Expression*> groupingColumns_;
	};

	class InPredicate : public Expression
	{
	public:
		InPredicate(Expression* value, Expression* valueList)
			: InPredicate(std::optional<NodeLocation>(), value, valueList) {}

		InPredicate(NodeLocation location, Expression* value, Expression* valueList)
			: InPredicate(std::make_optional(location), value, valueList) {}

		InPredicate(std::optional<NodeLocation> location, Expression* value, Expression* valueList)
			: Expression(location), value_(value), valueList_(valueList) {}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override
		{
			return std::vector<Node*>{ value_, valueList_};
		}

		virtual int hashCode() const override
		{
			return 0;
		}

		virtual bool equals(const Node& node) const override
		{
			return false;
		}

		virtual std::string toString() const override
		{
			return "InPredicate";
		}

		Expression* getValue() const { return value_; }
		Expression* getValueList() const { return valueList_; }

	private:
		Expression* value_;
		Expression* valueList_;
	};

	class Select : public Node {
	public:
		Select(bool distinct, const std::vector<SelectItem*> selectItems)
			: Select(std::nullopt, distinct, selectItems) {

		}

		Select(const NodeLocation& location, bool distinct, const std::vector<SelectItem*> selectItems)
			: Select(std::optional<NodeLocation>(location), distinct, selectItems) {

		}

		Select(const std::optional<NodeLocation>& location, bool distinct, const std::vector<SelectItem*> selectItems)
			: Node(location), distinct_(distinct), selectItems_(selectItems) {

		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			for (const auto& selectItem : selectItems_) {
				result.push_back(selectItem);
			}
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Select";
		}

		bool isDistinct() const { return distinct_; }
		std::vector<SelectItem*> getSelectItems() const { return selectItems_; };

	private:
		bool distinct_;
		std::vector<SelectItem*> selectItems_;
	};

	class IsNotNullPredicate : public Expression {
	public:
		IsNotNullPredicate(Expression* value)
			:
			IsNotNullPredicate(std::optional<NodeLocation>(), value) {
		}

		IsNotNullPredicate(NodeLocation location, Expression* value)
			:
			IsNotNullPredicate(std::make_optional(location), value) {
		}

		IsNotNullPredicate(std::optional<NodeLocation> location, Expression* value)
			:
			Expression(location), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ value_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "IsNotNullPredicate";
		}

		Expression* getValue() const {
			return value_;
		}


	private:
		Expression* value_;
	};

	class IsNullPredicate : public Expression {
	public:
		IsNullPredicate(Expression* value)
			:
			IsNullPredicate(std::optional<NodeLocation>(), value) {
		}

		IsNullPredicate(NodeLocation location, Expression* value)
			:
			IsNullPredicate(std::make_optional(location), value) {
		}

		IsNullPredicate(std::optional<NodeLocation> location, Expression* value)
			:
			Expression(location), value_(value) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ value_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "IsNullPredicate";
		}

		Expression* getValue() const {
			return value_;
		}

	private:
		Expression* value_;
	};

	class LikePredicate : public Expression {
	public:
		LikePredicate(Expression* value, Expression* pattern, Expression* escape)
			: LikePredicate(std::optional<NodeLocation>(), value, pattern, std::make_optional(escape)) {
		}

		LikePredicate(NodeLocation location, Expression* value, Expression* pattern, std::optional<Expression*> escape)
			: LikePredicate(std::make_optional(location), value, pattern, escape) {
		}

		LikePredicate(std::optional<NodeLocation> location, Expression* value, Expression* pattern, std::optional<Expression*> escape)
			: Expression(location)
			, value_(value)
			, pattern_(pattern)
			, escape_(escape) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ value_, pattern_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "LikePredicate";
		}

		Expression* getValue() const {
			return value_;
		}

		Expression* getPattern() const {
			return pattern_;
		}

		std::optional<Expression*> getEscape() const {
			return escape_;
		}

	private:
		Expression* value_;
		Expression* pattern_;
		std::optional<Expression*> escape_;
	};

	class BetweenPredicate: public Expression {
	public:
		BetweenPredicate(Expression* value, Expression* min, Expression* max)
			: BetweenPredicate(std::optional<NodeLocation>(), value, min, max) {
		}

		BetweenPredicate(NodeLocation location, Expression* value, Expression* min, Expression* max)
			: BetweenPredicate(std::make_optional(location), value, min, max) {
		}

		BetweenPredicate(std::optional<NodeLocation> location, Expression* value, Expression* min, Expression* max)
			: Expression(location)
			, value_(value)
			, min_(min)
			, max_(max) {
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>{ value_, min_, max_ };
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "BetweenPredicate";
		}

		Expression* getValue() const {
			return value_;
		}

		Expression* getMin() const {
			return min_;
		}

		Expression* getMax() const {
			return max_;
		}

	private:
		Expression* value_;
		Expression* min_;
		Expression* max_;
	};

	class Table : public QueryBody {

	public:
		Table(std::optional<NodeLocation> location, const QualifiedName& name) : QueryBody(location), name_(name) { }
		Table(const QualifiedName& name) : QueryBody(std::nullopt), name_(name) { }
		Table(NodeLocation location, const QualifiedName& name) : QueryBody(location), name_(name) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			return std::vector<Node*>();
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Table";
		}

		const QualifiedName& getName() const { return name_; }

	private:
		QualifiedName name_;

	};

	class JoinCriteria {
	public:
		virtual bool equals(const JoinCriteria& obj) = 0;
		virtual int hashCode() = 0;
		virtual std::string toString() = 0;
		virtual std::vector<Node*> getNodes() const = 0;
	};

	class Join : public Relation {
	public:
		enum JoinType
		{
			CROSS, INNER, LEFT, RIGHT, FULL, IMPLICIT
		};

		Join(JoinType type, Relation* left, Relation* right, std::optional<JoinCriteria*> criteria)
			: Join(std::nullopt, type, left, right, criteria)
		{

		}

		Join(NodeLocation location, JoinType type, Relation* left, Relation* right, std::optional<JoinCriteria*> criteria)
			: Join(std::make_optional(location), type, left, right, criteria)
		{

		}

		Join(std::optional<NodeLocation> location, JoinType type, Relation* left, Relation* right, std::optional<JoinCriteria*> criteria)
			: Relation(location), type_(type), left_(left), right_(right), criteria_(criteria)
		{

		}


		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result{ left_, right_ };
			if (criteria_.has_value()) {
				const auto& nodes = criteria_.value()->getNodes();
				for (auto& node : nodes) {
					result.push_back(node);
				}
			}
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Join";
		}

		JoinType getType() const { return type_; }
		Relation* getLeft() const { return left_; }
		Relation* getRight() const { return right_; }
		std::optional<JoinCriteria*> getCriteria() const { return criteria_; }

	private:
		JoinType type_;
		Relation* left_;
		Relation* right_;
		std::optional<JoinCriteria*> criteria_;
	};

	class JoinOn : public JoinCriteria
	{
	public:
		JoinOn(Expression* expression) : expression_(expression) { }

		virtual bool equals(const JoinCriteria& obj) override
		{
			return false;
		}

		virtual int hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "JoinOn";
		}

		virtual std::vector<Node*> getNodes() const override
		{
			return std::vector<Node*>{ expression_ };
		}

		Expression* getExpression() const { return expression_; }

	private:
		Expression* expression_;

	};

	class JoinUsing : public JoinCriteria
	{
	public:
		JoinUsing(std::vector<Identifier*> columns) : columns_(std::move(columns)) { }

		virtual bool equals(const JoinCriteria& obj) override
		{
			return false;
		}

		virtual int hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "JoinUsing";
		}

		virtual std::vector<Node*> getNodes() const override
		{
			return std::vector<Node*>();
		}

		std::vector<Identifier*> getColumns() const { return columns_; }

	private:
		std::vector<Identifier*> columns_;

	};

	class NaturalJoin : public JoinCriteria
	{
	public:
		virtual bool equals(const JoinCriteria& obj) override
		{
			return false;
		}

		virtual int hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "NaturalJoin";
		}

		virtual std::vector<Node*> getNodes() const override
		{
			return std::vector<Node*>();
		}
	};

	class QuerySpecification : public QueryBody {
	public:
		QuerySpecification(
			std::optional<Select*> select,
			std::optional<Relation*> from,
			std::optional<Expression*> where,
			std::optional<GroupBy*> groupBy,
			std::optional<Expression*> having,
			std::optional<OrderBy*> orderBy,
			std::optional<std::string> limit)
			: QuerySpecification(
				std::nullopt,
				select,
				from,
				where,
				groupBy,
				having,
				orderBy,
				limit)
		{}

		QuerySpecification(
			const NodeLocation& location,
			std::optional<Select*> select,
			std::optional<Relation*> from,
			std::optional<Expression*> where,
			std::optional<GroupBy*> groupBy,
			std::optional<Expression*> having,
			std::optional<OrderBy*> orderBy,
			std::optional<std::string> limit)
			: QuerySpecification(
				std::optional<NodeLocation>(location),
				select,
				from,
				where,
				groupBy,
				having,
				orderBy,
				limit)
		{}

		QuerySpecification(
			const std::optional<NodeLocation>& location,
			std::optional<Select*> select,
			std::optional<Relation*> from,
			std::optional<Expression*> where,
			std::optional<GroupBy*> groupBy,
			std::optional<Expression*> having,
			std::optional<OrderBy*> orderBy,
			std::optional<std::string> limit)
			:
			QueryBody(location),
			select_(select),
			from_(from),
			where_(where),
			groupBy_(groupBy),
			having_(having),
			orderBy_(orderBy),
			limit_(limit)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			result.push_back(select_.value());
			if (from_.has_value()) result.push_back(from_.value());
			if (where_.has_value()) result.push_back(where_.value());
			if (groupBy_.has_value()) result.push_back(groupBy_.value());
			if (having_.has_value()) result.push_back(having_.value());
			if (orderBy_.has_value()) result.push_back(orderBy_.value());
			return result;
		}

		virtual int hashCode() const override {
			return 0;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "QuerySpecification";
		}

		std::optional<Select*> getSelect() const { return select_; }
		std::optional<Relation*> getFrom() const { return from_; }
		std::optional<Expression*> getWhere() const { return where_; }
		std::optional<GroupBy*> getGroupBy() const { return groupBy_; }
		std::optional<Expression*> getHaving() const { return having_; }
		std::optional<OrderBy*> getOrderBy() const { return orderBy_; }
		std::optional<std::string> getLimit() const { return limit_; }

	private:
		std::optional<Select*> select_;
		std::optional<Relation*> from_;
		std::optional<Expression*> where_;
		std::optional<GroupBy*> groupBy_;
		std::optional<Expression*> having_;
		std::optional<OrderBy*> orderBy_;
		std::optional<std::string> limit_;
	};

	class ShowStats : public Statement
	{
	public:
		ShowStats(Relation* relation) : ShowStats(std::optional<NodeLocation>(), relation) {}
		ShowStats(NodeLocation location, Relation* relation) : ShowStats(std::make_optional(location), relation) {}
		ShowStats(std::optional<NodeLocation> location, Relation* relation) : Statement(location), relation_(relation) {}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual bool equals(const Node& obj) const override
		{
			return false;
		}

		virtual int hashCode() const override
		{
			return 0;
		}

		virtual std::string toString() const override
		{
			return "ShowStats";
		}

		virtual std::vector<Node*> getChildren() const override
		{
			return std::vector<Node*>{ relation_ };
		}


	private:
		Relation* relation_;
	};

	class SimpleGroupBy : public GroupingElement {
	public:
		SimpleGroupBy(const std::vector<Expression*>& columns)
			:
			SimpleGroupBy(std::optional<NodeLocation>(), columns)
		{
		}

		SimpleGroupBy(NodeLocation location, const std::vector<Expression*>& columns)
			:
			SimpleGroupBy(std::make_optional(location), columns)
		{
		}

		SimpleGroupBy(std::optional<NodeLocation> location, const std::vector<Expression*>& columns)
			:
			GroupingElement(location), columns_(columns)
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			for (const auto& column : columns_) result.push_back(column);
			return result;
		};

		virtual int hashCode() const override {
			int result = 0;
			//for (const auto& column : columns_) (column-> result.push_back(column);
			return result;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "SimpleGroupBy";
		}

		virtual std::vector<Expression*> getExpressions() const {
			return columns_;
		}

	private:
		std::vector<Expression*> columns_;
	};

	struct FieldIdentifier : public Identifier
	{
		FieldIdentifier(std::optional<NodeLocation> location, Identifier* base, Identifier* comp) : FieldIdentifier(location, base)
		{			
			components_.push_back(comp);
		}

		FieldIdentifier(std::optional<NodeLocation> location, Identifier* comp) : Identifier(location, "", true)
		{			
			components_.push_back(comp);
		}

		FieldIdentifier* AddComponent(Identifier* comp)
		{
			components_.push_back(comp);
			return this;
		}

		virtual std::string getValue() const override {
			std::stringstream result;			
			for (const auto& comp : components_)
			{
				if (components_.size() > 1 && comp->getValue() == "*") {
					// ignore field.* components
				} else {
					result << "/" << comp->getValue();
				}
			}
			return result.str();
		}

		std::string toString() const override
		{
			return "FieldIdentifier";
		}

		virtual std::vector<Node*> getChildren() const override {
			std::vector<Node*> result;
			for (const auto& column : components_) result.push_back(column);
			return result;
		};

		virtual int hashCode() const override {
			int result = 0;
			//for (const auto& column : columns_) (column-> result.push_back(column);
			return result;
		}

		virtual bool equals(const Node& node) const override {
			return false;
		}


	private:
		std::vector<Identifier*> components_;
	};

}
