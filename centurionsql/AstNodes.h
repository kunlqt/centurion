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
		virtual std::vector<std::shared_ptr<Node>> getChildren()  const = 0;
		virtual size_t hashCode() const = 0;
		virtual bool equals(std::shared_ptr<Node> node) const = 0;
		virtual std::string toString() const = 0;
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context);
		std::optional<NodeLocation> location() const { return location_; }
	protected:		
		Node(std::optional<NodeLocation> location) : location_(std::move(location)) { }
		virtual ~Node() = default;
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
			delimited_(delimited) { }

		Identifier(NodeLocation location, std::string value, bool delimited)
			: Identifier(std::optional<NodeLocation>(location), value, delimited) { }

		Identifier(std::string value, bool delimited)
			: Identifier(std::optional<NodeLocation>(), value, delimited) { }

		Identifier(std::string value)
			: Identifier(std::optional<NodeLocation>(), value, false) 
		{
			delimited_ = std::regex_match(value, namePattern_);
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>();
		}

		virtual size_t hashCode() const override {
			return std::hash<std::string>{}(value_);
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto identifier = std::dynamic_pointer_cast<Identifier>(node);
			if (identifier == nullptr) return false;
			return getValue() == identifier->getValue();
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
	public:
		DereferenceExpression(std::shared_ptr<Expression> base, std::shared_ptr<Identifier> field)
			: DereferenceExpression(std::optional<NodeLocation>(), base, field) { }

		DereferenceExpression(NodeLocation location, std::shared_ptr<Expression> base, std::shared_ptr<Identifier> field)
			: DereferenceExpression(std::make_optional(location), base, field) { }

		DereferenceExpression(std::optional<NodeLocation> location, std::shared_ptr<Expression> base, std::shared_ptr<Identifier> field)
			: Expression(location), base_(std::move(base)), field_(std::move(field)) { }

		virtual ~DereferenceExpression()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ base_ };
		}

		virtual size_t hashCode() const override {
			return hashCombine(base_->hashCode(), field_->hashCode());
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto expr  = std::dynamic_pointer_cast<DereferenceExpression>(node);
			if (expr == nullptr) return false;
			if (!expr->getField()->equals(getField())) return false;
			return expr->getBase()->equals(getBase());
		}

		virtual std::string toString() const override {
			return "DereferenceExpression";
		}

		
		static std::shared_ptr<QualifiedName> GetQualifiedName(DereferenceExpression* expression)
		{
			std::vector<std::string> parts;
			DereferenceExpression* current = expression;
			while (current)
			{				
				parts.push_back(current->getField()->getValue());
				if (current->getBase())
				{
					auto ident = dynamic_cast<Identifier*>(current->getBase().get());
					if (ident)
					{
						parts.push_back(ident->getValue());
						break;
					}
					auto deref = dynamic_cast<DereferenceExpression*>(current->getBase().get());
					if (deref)
					{
						current = deref;
					} else
					{
						throw std::runtime_error("err");
					}
				}
			}
			return std::make_shared<QualifiedName>(parts, true);
		}
		
		/*
		static std::shared_ptr<QualifiedName> GetQualifiedName_(std::shared_ptr<DereferenceExpression> expression)
		{
			std::vector<std::string> parts = 
				TryParseParts(expression->getBase(), toLowerCopy(expression->getField()->getValue()));
			if (parts.empty())
				return nullptr;
			return std::make_shared<QualifiedName>(parts);
		}

		static std::vector<std::string> TryParseParts(std::shared_ptr<Expression> base, std::string fieldName)
		{
			const auto identifier = std::dynamic_pointer_cast<Identifier>(base);
			if (identifier) {
				return std::vector<std::string> { identifier->getValue(), fieldName };
			} 
			const auto dereferenceExpression = std::dynamic_pointer_cast<DereferenceExpression>(base);
			if (dereferenceExpression) {
				const auto baseQualifiedName = GetQualifiedName_(dereferenceExpression);
				if (baseQualifiedName != nullptr) {
					auto newList = baseQualifiedName->getParts();
					newList.emplace_back(fieldName);
					return newList;
				}
			}
			return std::vector<std::string>();
		}
		*/

		static std::shared_ptr<Expression> From(std::shared_ptr<QualifiedName> name) {
			std::shared_ptr<Expression> result;
			for (const auto& part : name->getParts()) {
				if (result == nullptr) {
					result = std::make_shared<Identifier>(part);
				} else {
					result = std::make_shared<DereferenceExpression>(result, std::make_shared<Identifier>(part));
				}
			}
			return result;
		}

		std::shared_ptr<Expression> getBase() const {
			return base_;
		}

		std::shared_ptr<Identifier> getField() const {
			return field_;
		}

	private:
		std::shared_ptr<Expression> base_;
		std::shared_ptr<Identifier> field_;

	};

	class Literal : public Expression {
	public:
		Literal(std::optional<NodeLocation> location) 
			: Expression(location) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "Literal";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>();
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

		virtual size_t hashCode() const override {
			return std::hash<std::string>{}(value_);
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto identifier = std::dynamic_pointer_cast<StringLiteral>(node);
			if (identifier == nullptr) return false;
			return getValue() == identifier->getValue();
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

		virtual size_t hashCode() const override {
			return std::hash<std::string>{}(value_);
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto identifier = std::dynamic_pointer_cast<DecimalLiteral>(node);
			if (identifier == nullptr) return false;
			return getValue() == identifier->getValue();
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

		virtual size_t hashCode() const override {
			return ((size_t)value_);
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto identifier = std::dynamic_pointer_cast<DoubleLiteral>(node);
			if (identifier == nullptr) return false;
			return getValue() == identifier->getValue();
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
		
		virtual size_t hashCode() const override {
			return ((size_t)value_);
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto identifier = std::dynamic_pointer_cast<LongLiteral>(node);
			if (identifier == nullptr) return false;
			return getValue() == identifier->getValue();
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

		virtual size_t hashCode() const override {
			return value_ ? 1 : 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			if (node == nullptr) return false;
			const auto identifier = std::dynamic_pointer_cast<BooleanLiteral>(node);
			if (identifier == nullptr) return false;
			return getValue() == identifier->getValue();
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

		ArithmeticBinaryExpression(Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			:
			ArithmeticBinaryExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		ArithmeticBinaryExpression(NodeLocation location, Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			:
			ArithmeticBinaryExpression(std::make_optional(location), oper, left, right) {
		}

		ArithmeticBinaryExpression(std::optional<NodeLocation> location, Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			:
			Expression(location), operator_(std::move(oper)), left_(left), right_(right) {
		}

		virtual ~ArithmeticBinaryExpression()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "ArithmeticBinaryExpression";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ left_, right_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		Operator getOperator() const { return operator_; }
		std::shared_ptr<Expression> getLeft() const { return left_; }
		std::shared_ptr<Expression> getRight() const { return right_; }

	private:
		Operator operator_;
		std::shared_ptr<Expression> left_;
		std::shared_ptr<Expression> right_;
	};

	class ArithmeticUnaryExpression : public Expression {
	public:
		enum Sign {
			PLUS, MINUS
		};

		ArithmeticUnaryExpression(Sign sign, std::shared_ptr<Expression> left)
			:
			ArithmeticUnaryExpression(std::optional<NodeLocation>(), sign, left) {
		}

		ArithmeticUnaryExpression(NodeLocation location, Sign sign, std::shared_ptr<Expression> value)
			:
			ArithmeticUnaryExpression(std::make_optional(location), sign, value) {
		}

		ArithmeticUnaryExpression(std::optional<NodeLocation> location, Sign sign, std::shared_ptr<Expression> value)
			:
			Expression(location), sign_(sign), value_(value) {
		}

		virtual ~ArithmeticUnaryExpression()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "ArithmeticUnaryExpression";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ value_};
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		Sign getSign() const { return sign_; }
		std::shared_ptr<Expression> getValue() const { return value_; }


	private:
		Sign sign_;
		std::shared_ptr<Expression> value_;

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
			enum openum {Equal, NotEqual, LessThan, LessThanOrEqual, GreaterThan, GreaterThanOrEqual, IsDistinctFrom};
			Operator(openum op, std::string name) : name_(std::move(name)), op_(op) { }
			std::string name_;
			openum op_;
		};

		ComparisonExpression(Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			:
			ComparisonExpression(std::optional<NodeLocation>(), oper, left, right) {
		}

		ComparisonExpression(NodeLocation location, Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			:
			ComparisonExpression(std::make_optional(location), oper, left, right) {
		}

		ComparisonExpression(std::optional<NodeLocation> location, Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			:
			Expression(location), operator_(oper), left_(std::move(left)), right_(std::move(right)) {
		}

		virtual ~ComparisonExpression()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "ComparisonExpression";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			result.push_back(left_);
			result.push_back(right_);
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		Operator getOperator() const { return operator_; }
		std::shared_ptr<Expression> getLeft() const { return left_; }
		std::shared_ptr<Expression> getRight() const { return right_; }
			   
	private:
		Operator operator_;
		std::shared_ptr<Expression> left_;
		std::shared_ptr<Expression> right_;
	};

	class InListExpression : public Expression
	{
	public:
		InListExpression(std::vector<std::shared_ptr<Expression>> values)
			: InListExpression(std::optional<NodeLocation>(), values) {}

		InListExpression(NodeLocation location, std::vector<std::shared_ptr<Expression>> values)
			: InListExpression(std::make_optional(location), values) {}

		InListExpression(std::optional<NodeLocation> location, std::vector<std::shared_ptr<Expression>> values)
			: Expression(location), values_(std::move(values)) {}

		virtual ~InListExpression()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override
		{
			std::vector<std::shared_ptr<Node>> result;
			for (auto value : values_)
			{
				result.push_back(value);
			}
			return result;
		}
		virtual size_t hashCode() const  override
		{
			return 0;
		}
		virtual bool equals(std::shared_ptr<Node> node) const override
		{
			return false;
		}
		virtual std::string toString() const override
		{
			return "InListExpression";
		}

		std::vector<std::shared_ptr<Expression>> getValues() const { return values_; }

	private:
		std::vector<std::shared_ptr<Expression>> values_;
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
			Operator(openum op, std::string name) : name_(std::move(name)), op_(op) { }
			std::string name_;
			openum op_;
		};

		LogicalBinaryExpression(Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			: LogicalBinaryExpression(std::optional<NodeLocation>(), oper, left, right) { }

		LogicalBinaryExpression(NodeLocation location, Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			: LogicalBinaryExpression(std::make_optional(location), oper, left, right) { }

		LogicalBinaryExpression(std::optional<NodeLocation> location, Operator oper, std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
			: Expression(location), operator_(oper), left_(left), right_(right) { }

		virtual ~LogicalBinaryExpression()
		{

		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "LogicalBinaryExpression";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			result.push_back(left_);
			result.push_back(right_);
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		Operator getOperator() const { return operator_; }
		std::shared_ptr<Expression> getLeft() const { return left_; }
		std::shared_ptr<Expression> getRight() const { return right_; }

	private:
		Operator operator_;
		std::shared_ptr<Expression> left_;
		std::shared_ptr<Expression> right_;
	};

	class NotExpression : public Expression {
	public:
		NotExpression(std::shared_ptr<Expression> value)
			:
			NotExpression(std::optional<NodeLocation>(), value) {
		}

		NotExpression(NodeLocation location, std::shared_ptr<Expression> value)
			:
			NotExpression(std::make_optional(location), value) {
		}

		NotExpression(std::optional<NodeLocation> location, std::shared_ptr<Expression> value)
			:
			Expression(location), value_(value) {
		}

		virtual ~NotExpression()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "NotExpression";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			result.push_back(value_);
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		std::shared_ptr<Expression> getValue() const { return value_; }

	private:
		std::shared_ptr<Expression> value_;
	};

	class Statement : public Node {
	public:
		Statement(std::optional<NodeLocation> location) : Node(location) { }
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;
	};

	class Relation : public Node {
	public:
		Relation(std::optional<NodeLocation> location) : Node(location) { }
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;
	};

	class QueryBody : public Relation {
	public:
		QueryBody(std::optional<NodeLocation> location) : Relation(location) { }
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;
	};

	class SortItem : public Node {
	public:
		enum Ordering { Ascending, Descending };
		enum NullOrdering { First, Last, Undefined };

		SortItem(std::optional<NodeLocation> location, std::shared_ptr<Expression> sortKey, Ordering ordering, NullOrdering nullOrdering)
			: Node(location), sortKey_(sortKey), ordering_(ordering), nullOrdering_(nullOrdering) { }

		virtual ~SortItem()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result{ sortKey_ };
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "SortItem";
		}

		std::shared_ptr<Expression> getSortKey() const {
			return sortKey_;
		}

		Ordering getOrdering() const {
			return ordering_;
		}

		NullOrdering getNullOrdering() const {
			return nullOrdering_;
		}


	private:
		std::shared_ptr<Expression> sortKey_;
		SortItem::Ordering ordering_;
		SortItem::NullOrdering nullOrdering_;

	};

	class OrderBy : public Node {
	public:
		OrderBy(std::vector<std::shared_ptr<SortItem>> sortItems)
			: OrderBy(std::optional<NodeLocation>(), sortItems) { }

		OrderBy(const NodeLocation& location, std::vector<std::shared_ptr<SortItem>> sortItems)
			: OrderBy(std::make_optional(location), sortItems) { }

		OrderBy(std::optional<NodeLocation> location, std::vector<std::shared_ptr<SortItem>> sortItems)
			: Node(location), sortItems_(std::move(sortItems)) { }

		virtual ~OrderBy()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			for (auto sortItem : sortItems_) {
				result.push_back(sortItem);
			}
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "OrderBy";
		}

		std::vector<std::shared_ptr<SortItem>> getSortItems() const {
			return sortItems_;
		}

	private:
		std::vector<std::shared_ptr<SortItem>> sortItems_;
	};

	class With;

	class Query : public Statement {
	public:
		Query(std::optional<std::shared_ptr<With>> with,
			std::shared_ptr<QueryBody> queryBody,
			std::optional<std::shared_ptr<OrderBy>> orderBy,
			std::optional<std::string> limit)
			: Query(std::optional<NodeLocation>(), with, queryBody, orderBy, limit) { }

		Query(const NodeLocation& location,
			std::optional<std::shared_ptr<With>> with,
			std::shared_ptr<QueryBody> queryBody,
			std::optional<std::shared_ptr<OrderBy>> orderBy,
			std::optional<std::string> limit)
			: Query(std::optional<NodeLocation>(location), with, queryBody, orderBy, limit) { }

		Query(std::optional<NodeLocation> location,
			std::optional<std::shared_ptr<With>> with,
			std::shared_ptr<QueryBody> queryBody,
			std::optional<std::shared_ptr<OrderBy>> orderBy,
			std::optional<std::string> limit)
			: Statement(location)
			, with_(std::move(with))
			, queryBody_(std::move(queryBody))
			, orderBy_(std::move(orderBy))
			, limit_(std::move(limit)) { }

		virtual ~Query();
		
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			if (with_.has_value()) {
				std::shared_ptr<With> with = with_.value();
				//result.push_back(with); // todo: fix this
			}
			if (orderBy_.has_value()) {
				result.push_back(orderBy_.value());
			}
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Query";
		}

		std::optional<std::shared_ptr<With>> getWith() const
		{
			return with_;
		}

		std::shared_ptr<QueryBody> getQueryBody() const
		{
			return queryBody_;
		}

		std::optional<std::shared_ptr<OrderBy>> getOrderBy() const
		{
			return orderBy_;
		}

		std::optional<std::string> getLimit() const
		{
			return limit_;
		}


	private:
		std::optional<std::shared_ptr<With>> with_;
		std::shared_ptr<QueryBody> queryBody_;
		std::optional<std::shared_ptr<OrderBy>> orderBy_;
		std::optional<std::string> limit_;
	};

	class WithQuery : public Node {
	public:
		WithQuery(std::shared_ptr<Identifier> name, std::shared_ptr<Query> query, std::optional<std::vector<std::shared_ptr<Identifier>>> columnNames)
			: WithQuery(std::optional<NodeLocation>(), name, query, columnNames) { }

		WithQuery(const NodeLocation& location, std::shared_ptr<Identifier> name, std::shared_ptr<Query> query, std::optional<std::vector<std::shared_ptr<Identifier>>> columnNames)
			: WithQuery(std::optional<NodeLocation>(location), name, query, columnNames) { }

		WithQuery(std::optional<NodeLocation> location, std::shared_ptr<Identifier> name, std::shared_ptr<Query> query, std::optional<std::vector<std::shared_ptr<Identifier>>> columnNames)
			: Node(location)
			, name_(name)
			, query_(query)
			, columnNames_(std::move(columnNames)) { }

		virtual ~WithQuery()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ query_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "WithQuery";
		}

		std::shared_ptr<Identifier> getName() const {
			return name_;
		}

		std::shared_ptr<Query> getQuery() const {
			return query_;
		}

		std::optional<std::vector<std::shared_ptr<Identifier>>> getColumnNames() const {
			return columnNames_;
		}

	private:
		std::shared_ptr<Identifier> name_;
		std::shared_ptr<Query> query_;
		std::optional<std::vector<std::shared_ptr<Identifier>>> columnNames_;
	};

	class With : public Node {
	public:
		With(bool recursive, std::vector<std::shared_ptr<WithQuery>> queries)
			: With(std::optional<NodeLocation>(), recursive, std::move(queries)) { }

		With(const NodeLocation& location, bool recursive, std::vector<std::shared_ptr<WithQuery>> queries)
			: With(std::optional<NodeLocation>(location), recursive, std::move(queries)) { }

		With(std::optional<NodeLocation> location, bool recursive, std::vector<std::shared_ptr<WithQuery>> queries)
			: Node(location), recursive_(recursive), queries_(std::move(queries)) { }

		virtual ~With()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			for (auto& item : queries_) {
				result.push_back(item);
			}
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "With";
		}

		bool isRecursive() const {
			return recursive_;
		}

		std::vector<std::shared_ptr<WithQuery>> getQueries() const {
			return queries_;
		};


	private:
		bool recursive_;
		std::vector<std::shared_ptr<WithQuery>> queries_;
	};

	class SubqueryExpression : public Expression
	{
	public:
		SubqueryExpression(std::shared_ptr<Query> query) : SubqueryExpression(std::optional<NodeLocation>(), query) { }
		SubqueryExpression(NodeLocation location, std::shared_ptr<Query> query) : SubqueryExpression(std::make_optional(location), query) { }
		SubqueryExpression(std::optional<NodeLocation> location, std::shared_ptr<Query> query)
			: Expression(location), query_(query) { }

		virtual ~SubqueryExpression()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::string toString() const override {
			return "SubqueryExpression";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ query_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		std::shared_ptr<Query> getQuery() const { return query_; }

	private:
		std::shared_ptr<Query> query_;
	};

	class SelectItem : public Node {
	public:
		SelectItem(std::optional<NodeLocation> location) : Node(location) { }
	};

	class SingleColumn : public SelectItem {
	public:
		SingleColumn(std::shared_ptr < Expression> expression)
			: SingleColumn(std::optional<NodeLocation>(), expression, std::optional< std::shared_ptr<Identifier>>()) { }

		SingleColumn(
			std::shared_ptr < Expression> expression,
			std::optional< std::shared_ptr<Identifier>> alias)
			: SingleColumn(std::optional<NodeLocation>(), expression, std::optional< std::shared_ptr<Identifier>>(alias)) { }

		SingleColumn(
			const NodeLocation& location,
			std::shared_ptr < Expression> expression,
			std::optional< std::shared_ptr<Identifier>> alias)
			: SingleColumn(std::optional<NodeLocation>(location), expression, std::optional< std::shared_ptr<Identifier>>(alias)) { }

		SingleColumn(
			std::optional<NodeLocation> location,
			std::shared_ptr < Expression> expression,
			std::optional< std::shared_ptr<Identifier>> alias)
			: SelectItem(location)
			, expression_(std::move(expression))
			, alias_(std::move(alias)) { }

		virtual ~SingleColumn()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ expression_};
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "SingleColumn";
		}

		std::optional< std::shared_ptr<Identifier>> getAlias() const { return alias_; }
		std::shared_ptr < Expression> getExpression() const { return expression_; }

	private:
		std::shared_ptr<Expression> expression_;
		std::optional<std::shared_ptr<Identifier>> alias_;
	};

	class AliasedRelation : public Relation {
	public:
		AliasedRelation(std::optional<NodeLocation> location, std::shared_ptr<Relation> relation, std::shared_ptr<Identifier> alias, std::vector<std::shared_ptr<Identifier>> columnNames)
			: Relation(location), relation_(relation), alias_(alias), columnNames_(std::move(columnNames)) { }

		virtual ~AliasedRelation()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>> { relation_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "AliasedRelation";
		}

		std::shared_ptr<Relation> getRelation() const { return relation_; }
		std::shared_ptr<Identifier> getAlias() const { return alias_; }
		std::vector<std::shared_ptr<Identifier>> getColumnNames() const { return columnNames_; }

	private:
		std::optional<NodeLocation> location_;
		std::shared_ptr<Relation> relation_;
		std::shared_ptr<Identifier> alias_;
		std::vector<std::shared_ptr<Identifier>> columnNames_;
	};

	class AllColumns : public SelectItem {
	public:
		AllColumns()
			: SelectItem(std::optional<NodeLocation>())
			, prefix_(std::optional<std::shared_ptr<QualifiedName>>()) { }

		AllColumns(const NodeLocation& location)
			: SelectItem(std::optional<NodeLocation>(location))
			, prefix_(std::optional<std::shared_ptr<QualifiedName>>()) { }

		AllColumns(std::shared_ptr<QualifiedName> prefix)
			: AllColumns(std::optional<NodeLocation>(), prefix)  { }

		AllColumns(const NodeLocation& location, std::shared_ptr<QualifiedName> prefix)
			: AllColumns(std::optional<NodeLocation>(location), prefix)  { }

		AllColumns(std::optional<NodeLocation> location, std::shared_ptr<QualifiedName> prefix)
			: SelectItem(location), prefix_(prefix) { }

		virtual ~AllColumns()
		{
			
		}

		antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>();
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "AllColumns";
		}

		std::optional<std::shared_ptr<QualifiedName>> getPrefix() const {
			return prefix_;
		}

	private:
		std::optional<std::shared_ptr<QualifiedName>> prefix_;
	};

	class GroupingElement : public Node {
	public:
		GroupingElement(std::optional<NodeLocation> location) : Node(location) { }
		virtual std::vector<std::shared_ptr<Expression>> getExpressions() const = 0;
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;
	};

	class GroupBy : public Node {
	public:
		GroupBy(bool distinct, const std::vector<std::shared_ptr<GroupingElement>> groupingElements)
			: GroupBy(std::nullopt, distinct, groupingElements) { }

		GroupBy(const NodeLocation& location, bool distinct, const std::vector<std::shared_ptr<GroupingElement>> groupingElements)
			: GroupBy(std::optional<NodeLocation>(location), distinct, groupingElements) { }

		GroupBy(const std::optional<NodeLocation>& location, bool distinct, const std::vector<std::shared_ptr<GroupingElement>> groupingElements)
			: Node(location), distinct_(distinct), groupingElements_(groupingElements) { }

		virtual ~GroupBy()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			for (const auto& selectItem : groupingElements_) {
				result.push_back(selectItem);
			}
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "GroupBy";
		}

		bool isDistinct() const { return distinct_; }

		std::vector<std::shared_ptr<GroupingElement>> getGroupingElements() const { return groupingElements_; };


	private:
		bool distinct_;
		std::vector<std::shared_ptr<GroupingElement>> groupingElements_;
	};

	class GroupingOperation : public Expression {
	public:
		GroupingOperation(
			const std::optional<NodeLocation>& location, 
			std::vector<std::shared_ptr<QualifiedName>> groupingColumns) 
		: Expression(location)
		{
			for (std::shared_ptr<QualifiedName> groupingColumn : groupingColumns)
			{
				groupingColumns_.emplace_back(DereferenceExpression::From(groupingColumn));
			}
		}

		virtual ~GroupingOperation()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>();
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "GroupingOperation";
		}

		std::vector<std::shared_ptr<Expression>> getGroupingColumns() const {
			return groupingColumns_;
		}

	private:
		std::vector<std::shared_ptr<Expression>> groupingColumns_;
	};

	class InPredicate : public Expression
	{
	public:
		InPredicate(std::shared_ptr < Expression> value, std::shared_ptr < Expression> valueList)
			: InPredicate(std::optional<NodeLocation>(), value, valueList) {}

		InPredicate(NodeLocation location, std::shared_ptr < Expression> value, std::shared_ptr < Expression> valueList)
			: InPredicate(std::make_optional(location), value, valueList) {}

		InPredicate(std::optional<NodeLocation> location, std::shared_ptr < Expression> value, std::shared_ptr < Expression> valueList)
			: Expression(location), value_(std::move(value)), valueList_(std::move(valueList)) {}

		virtual ~InPredicate()
		{
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override
		{
			return std::vector<std::shared_ptr<Node>>{ value_, valueList_ };
		}

		virtual size_t hashCode() const override
		{
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override
		{
			return false;
		}

		virtual std::string toString() const override
		{
			return "InPredicate";
		}

		std::shared_ptr<Expression> getValue() const { return value_; }
		std::shared_ptr<Expression> getValueList() const { return valueList_; }

	private:
		std::shared_ptr<Expression> value_;
		std::shared_ptr<Expression> valueList_;
	};

	class Select : public Node {
	public:
		Select(bool distinct, std::vector<std::shared_ptr<SelectItem>> selectItems)
			: Select(std::nullopt, distinct, selectItems) { }

		Select(const NodeLocation& location, bool distinct, std::vector<std::shared_ptr<SelectItem>> selectItems)
			: Select(std::optional<NodeLocation>(location), distinct, selectItems) { }

		Select(const std::optional<NodeLocation>& location, bool distinct, std::vector<std::shared_ptr<SelectItem>> selectItems)
			: Node(location), distinct_(distinct), selectItems_(std::move(selectItems)) { }

		virtual ~Select()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			for (const auto& selectItem : selectItems_) {
				result.push_back(selectItem);
			}
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Select";
		}

		bool isDistinct() const { return distinct_; }
		std::vector<std::shared_ptr<SelectItem>> getSelectItems() const { return selectItems_; };

	private:
		bool distinct_;
		std::vector<std::shared_ptr<SelectItem>> selectItems_;
	};

	class IsNotNullPredicate : public Expression {
	public:
		IsNotNullPredicate(std::shared_ptr<Expression> value)
			: IsNotNullPredicate(std::optional<NodeLocation>(), value) { }

		IsNotNullPredicate(NodeLocation location, std::shared_ptr<Expression> value)
			: IsNotNullPredicate(std::make_optional(location), value) { }

		IsNotNullPredicate(std::optional<NodeLocation> location, std::shared_ptr<Expression> value)
			: Expression(location), value_(value) { }

		virtual ~IsNotNullPredicate()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ value_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "IsNotNullPredicate";
		}

		std::shared_ptr<Expression> getValue() const {
			return value_;
		}


	private:
		std::shared_ptr<Expression> value_;
	};

	class IsNullPredicate : public Expression {
	public:
		IsNullPredicate(std::shared_ptr<Expression> value)
			: IsNullPredicate(std::optional<NodeLocation>(), value) { }

		IsNullPredicate(NodeLocation location, std::shared_ptr<Expression> value)
			: IsNullPredicate(std::make_optional(location), value) { }

		IsNullPredicate(std::optional<NodeLocation> location, std::shared_ptr<Expression> value)
			: Expression(location), value_(value) { }

		virtual ~IsNullPredicate()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ value_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "IsNullPredicate";
		}

		std::shared_ptr<Expression> getValue() const {
			return value_;
		}

	private:
		std::shared_ptr<Expression> value_;
	};

	class LikePredicate : public Expression {
	public:
		LikePredicate(std::shared_ptr<Expression> value, std::shared_ptr<Expression> pattern, std::shared_ptr<Expression> escape)
			: LikePredicate(std::optional<NodeLocation>(), value, pattern, std::make_optional(escape)) {
		}

		LikePredicate(NodeLocation location, std::shared_ptr<Expression> value, std::shared_ptr<Expression> pattern, std::optional<std::shared_ptr<Expression>> escape)
			: LikePredicate(std::make_optional(location), value, pattern, escape) {
		}

		LikePredicate(std::optional<NodeLocation> location, std::shared_ptr<Expression> value, std::shared_ptr<Expression> pattern, std::optional<std::shared_ptr<Expression>> escape)
			: Expression(location)
			, value_(value)
			, pattern_(pattern)
			, escape_(escape) {
		}

		virtual ~LikePredicate()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ value_, pattern_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "LikePredicate";
		}

		std::shared_ptr<Expression> getValue() const {
			return value_;
		}

		std::shared_ptr<Expression> getPattern() const {
			return pattern_;
		}

		std::optional<std::shared_ptr<Expression>> getEscape() const {
			return escape_;
		}

	private:
		std::shared_ptr<Expression> value_;
		std::shared_ptr<Expression> pattern_;
		std::optional<std::shared_ptr<Expression>> escape_;
	};

	class BetweenPredicate: public Expression {
	public:
		BetweenPredicate(std::shared_ptr<Expression> value, std::shared_ptr<Expression> min, std::shared_ptr<Expression> max)
			: BetweenPredicate(std::optional<NodeLocation>(), value, min, max) {
		}

		BetweenPredicate(NodeLocation location, std::shared_ptr<Expression> value, std::shared_ptr<Expression> min, std::shared_ptr<Expression> max)
			: BetweenPredicate(std::make_optional(location), value, min, max) {
		}

		BetweenPredicate(std::optional<NodeLocation> location, std::shared_ptr<Expression> value, std::shared_ptr<Expression> min, std::shared_ptr<Expression> max)
			: Expression(location)
			, value_(value)
			, min_(min)
			, max_(max) {
		}

		virtual ~BetweenPredicate()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>{ value_, min_, max_ };
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "BetweenPredicate";
		}

		std::shared_ptr<Expression> getValue() const {
			return value_;
		}

		std::shared_ptr<Expression> getMin() const {
			return min_;
		}

		std::shared_ptr<Expression> getMax() const {
			return max_;
		}

	private:
		std::shared_ptr<Expression> value_;
		std::shared_ptr<Expression> min_;
		std::shared_ptr<Expression> max_;
	};

	class Table : public QueryBody {
	public:
		Table(std::optional<NodeLocation> location, std::shared_ptr<QualifiedName> name) : QueryBody(location), name_(name) { }
		Table(std::shared_ptr<QualifiedName> name) : QueryBody(std::nullopt), name_(name) { }
		Table(NodeLocation location, std::shared_ptr<QualifiedName> name) : QueryBody(location), name_(name) { }

		virtual ~Table()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			return std::vector<std::shared_ptr<Node>>();
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Table";
		}

		std::shared_ptr<QualifiedName> getName() const { return name_; }

	private:
		std::shared_ptr<QualifiedName> name_;

	};

	class JoinCriteria {
	public:
		virtual bool equals(const JoinCriteria& obj) = 0;
		virtual size_t hashCode() = 0;
		virtual std::string toString() = 0;
		virtual std::vector<std::shared_ptr<Node>> getNodes() const = 0;
		virtual ~JoinCriteria() = default;
	};

	class Join : public Relation {
	public:
		enum JoinType
		{
			CROSS, INNER, LEFT, RIGHT, FULL, IMPLICIT
		};

		Join(JoinType type, std::shared_ptr < Relation> left, std::shared_ptr < Relation> right, std::optional< std::shared_ptr<JoinCriteria>> criteria)
			: Join(std::optional<NodeLocation>(), type, left, right, criteria) { }

		Join(NodeLocation location, JoinType type, std::shared_ptr < Relation> left, std::shared_ptr < Relation> right, std::optional< std::shared_ptr<JoinCriteria>> criteria)
			: Join(std::make_optional(location), type, left, right, criteria) { }

		Join(std::optional<NodeLocation> location, JoinType type, 
			std::shared_ptr<Relation> left, 
			std::shared_ptr<Relation> right, 
			std::optional<std::shared_ptr<JoinCriteria>> criteria)
			: Relation(location), 
		type_(type), 
		left_(std::move(left)), 
		right_(std::move(right)),
		criteria_(std::move(criteria)) { }

		virtual ~Join()
		{
		
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result{ left_, right_ };
			if (criteria_.has_value()) {
				const auto& nodes = criteria_.value()->getNodes();
				for (auto& node : nodes) {
					result.push_back(node);
				}
			}
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "Join";
		}

		JoinType getType() const { return type_; }
		std::shared_ptr < Relation> getLeft() const { return left_; }
		std::shared_ptr < Relation> getRight() const { return right_; }
		std::optional< std::shared_ptr<JoinCriteria>> getCriteria() const { return criteria_; }

	private:
		JoinType type_;
		std::shared_ptr<Relation> left_;
		std::shared_ptr<Relation> right_;
		std::optional<std::shared_ptr<JoinCriteria>> criteria_;
	};

	class JoinOn : public JoinCriteria
	{
	public:
		JoinOn(std::shared_ptr<Expression> expression) : expression_(std::move(expression)) { }
		virtual ~JoinOn()
		{
		}

		virtual bool equals(const JoinCriteria& obj) override
		{
			return false;
		}

		virtual size_t hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "JoinOn";
		}

		virtual std::vector<std::shared_ptr<Node>> getNodes() const override
		{
			return std::vector<std::shared_ptr<Node>>{ expression_ };
		}

		std::shared_ptr<Expression> getExpression() const { return expression_; }

	private:
		std::shared_ptr<Expression> expression_;

	};

	class JoinUsing : public JoinCriteria
	{
	public:
		JoinUsing(std::vector<std::shared_ptr<Identifier>> columns) : columns_(std::move(columns)) { }
		virtual ~JoinUsing()
		{
			
		}

		virtual bool equals(const JoinCriteria& obj) override
		{
			return false;
		}

		virtual size_t hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "JoinUsing";
		}

		virtual std::vector<std::shared_ptr<Node>> getNodes() const override
		{
			return std::vector<std::shared_ptr<Node>>();
		}

		std::vector<std::shared_ptr<Identifier>> getColumns() const { return columns_; }

	private:
		std::vector<std::shared_ptr<Identifier>> columns_;

	};

	class NaturalJoin : public JoinCriteria
	{
	public:
		virtual ~NaturalJoin() {}

		virtual bool equals(const JoinCriteria& obj) override
		{
			return false;
		}

		virtual size_t hashCode() override
		{
			return 0;
		}

		virtual std::string toString() override
		{
			return "NaturalJoin";
		}

		virtual std::vector<std::shared_ptr<Node>> getNodes() const override
		{
			return std::vector<std::shared_ptr<Node>>();
		}
	};

	class QuerySpecification : public QueryBody {
	public:
		QuerySpecification(
			std::optional<std::shared_ptr<Select>> select,
			std::optional<std::shared_ptr<Relation>> from,
			std::optional<std::shared_ptr<Expression>> where,
			std::optional<std::shared_ptr<GroupBy>> groupBy,
			std::optional<std::shared_ptr<Expression>> having,
			std::optional<std::shared_ptr<OrderBy>> orderBy,
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
			std::optional<std::shared_ptr<Select>> select,
			std::optional<std::shared_ptr<Relation>> from,
			std::optional<std::shared_ptr<Expression>> where,
			std::optional<std::shared_ptr<GroupBy>> groupBy,
			std::optional<std::shared_ptr<Expression>> having,
			std::optional<std::shared_ptr<OrderBy>> orderBy,
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
			std::optional<std::shared_ptr<Select>> select,
			std::optional<std::shared_ptr<Relation>> from,
			std::optional<std::shared_ptr<Expression>> where,
			std::optional<std::shared_ptr<GroupBy>> groupBy,
			std::optional<std::shared_ptr<Expression>> having,
			std::optional<std::shared_ptr<OrderBy>> orderBy,
			std::optional<std::string> limit)
			:
			QueryBody(location),
			select_(select),
			from_(from),
			where_(where),
			groupBy_(groupBy),
			having_(having),
			orderBy_(orderBy),
			limit_(std::move(limit))
		{
		}

		virtual ~QuerySpecification()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			if (select_.has_value()) result.push_back(select_.value());
			if (from_.has_value()) result.push_back(from_.value());
			if (where_.has_value()) result.push_back(where_.value());
			if (groupBy_.has_value()) result.push_back(groupBy_.value());
			if (having_.has_value()) result.push_back(having_.value());
			if (orderBy_.has_value()) result.push_back(orderBy_.value());
			return result;
		}

		virtual size_t hashCode() const override {
			return 0;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "QuerySpecification";
		}

		std::optional<std::shared_ptr<Select>> getSelect() const { return select_; }
		std::optional<std::shared_ptr<Relation>> getFrom() const { return from_; }
		std::optional<std::shared_ptr<Expression>> getWhere() const { return where_; }
		std::optional<std::shared_ptr<GroupBy>> getGroupBy() const { return groupBy_; }
		std::optional<std::shared_ptr<Expression>> getHaving() const { return having_; }
		std::optional<std::shared_ptr<OrderBy>> getOrderBy() const { return orderBy_; }
		std::optional<std::string> getLimit() const { return limit_; }

	private:
		std::optional<std::shared_ptr<Select>> select_;
		std::optional<std::shared_ptr<Relation>> from_;
		std::optional<std::shared_ptr<Expression>> where_;
		std::optional<std::shared_ptr<GroupBy>> groupBy_;
		std::optional<std::shared_ptr<Expression>> having_;
		std::optional<std::shared_ptr<OrderBy>> orderBy_;
		std::optional<std::string> limit_;
	};

	class ShowStats : public Statement
	{
	public:
		ShowStats(std::shared_ptr<Relation> relation) : ShowStats(std::optional<NodeLocation>(), relation) {}
		ShowStats(NodeLocation location, std::shared_ptr<Relation> relation) : ShowStats(std::make_optional(location), relation) {}
		ShowStats(std::optional<NodeLocation> location, std::shared_ptr<Relation> relation) : Statement(location), relation_(relation) {}

		virtual  ~ShowStats()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual bool equals(std::shared_ptr<Node> node) const override
		{
			return false;
		}

		virtual size_t hashCode() const override
		{
			return 0;
		}

		virtual std::string toString() const override
		{
			return "ShowStats";
		}

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override
		{
			return std::vector<std::shared_ptr<Node>>{ relation_ };
		}


	private:
		std::shared_ptr<Relation> relation_;
	};

	class SimpleGroupBy : public GroupingElement {
	public:
		SimpleGroupBy(std::vector<std::shared_ptr<Expression>> columns)
			: SimpleGroupBy(std::optional<NodeLocation>(), std::move(columns)) { }

		SimpleGroupBy(NodeLocation location, std::vector<std::shared_ptr<Expression>> columns)
			: SimpleGroupBy(std::make_optional(location), std::move(columns)) { }

		SimpleGroupBy(std::optional<NodeLocation> location, std::vector<std::shared_ptr<Expression>> columns)
			: GroupingElement(location), columns_(std::move(columns)) { }

		virtual  ~SimpleGroupBy()
		{
			
		}

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override;

		virtual std::vector<std::shared_ptr<Node>> getChildren() const override {
			std::vector<std::shared_ptr<Node>> result;
			for (auto value : columns_)
			{
				result.push_back(value);
			}
			return result;
		};

		virtual size_t hashCode() const override {
			int result = 0;
			//for (const auto& column : columns_) (column-> result.push_back(column);
			return result;
		}

		virtual bool equals(std::shared_ptr<Node> node) const override {
			return false;
		}

		virtual std::string toString() const override {
			return "SimpleGroupBy";
		}

		virtual std::vector<std::shared_ptr<Expression>> getExpressions() const override {
			return columns_;
		}

	private:
		std::vector<std::shared_ptr<Expression>> columns_;
	};
	

}
