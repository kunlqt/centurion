#include "Node.h"
#include "AstVisitor.h"

namespace centurion {

	Node::Node(std::optional<NodeLocation> location) : location_(location) { }
	std::optional<NodeLocation> Node::getLocation() const { return location_; }
	antlrcpp::Any Node::accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) {
		return visitor->visitNode(this, context);
	}

	Node::~Node()
	{
	}

}
