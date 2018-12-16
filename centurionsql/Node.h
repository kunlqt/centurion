//
//  Node.h
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "NodeLocation.h"
#include <antlr4-runtime.h>
#include <string>
#include <vector>
#include <optional>

namespace centurion {
	class AstVisitor;
	class Node  {
	public:
		virtual std::optional<NodeLocation> getLocation() const;
		virtual std::vector<Node*> getChildren() = 0;
		virtual int hashCode() = 0;
		virtual bool equals(const Node& node) = 0;
		virtual std::string toString() = 0;

	protected:
		// protected:
		Node(std::optional<NodeLocation> location);
		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context);
		virtual ~Node();
	private:
		std::optional<NodeLocation> location_;

		friend AstVisitor;
	};

}

#endif /* Node_h */
