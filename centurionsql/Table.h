//
//  Table.h
//  
//
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include "QualifiedName.h"
#include "QueryBody.h"
#include "AstVisitor.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {

	class Table : public QueryBody {
	
	public:
		Table(std::optional<NodeLocation> location, const QualifiedName& name) : QueryBody(location), name_(name) { }
		Table(const QualifiedName& name) : QueryBody(std::nullopt), name_(name) { }
		Table(NodeLocation location, const QualifiedName& name) : QueryBody(location), name_(name) { }

		virtual antlrcpp::Any accept(AstVisitor* visitor, antlr4::ParserRuleContext* context) override {
			return visitor->visitTable(this, context);
		}

		virtual std::vector<Node*> getChildren() override {
			return std::vector<Node*>();
		}

		virtual int hashCode() override {
			return 0;
		}

		virtual bool equals(const Node& node) override {
			return false;
		}

		virtual std::string toString() override {
			return "Table";
		}

		const QualifiedName& getName() const { return name_; }

	private:
		QualifiedName name_;

	};

}



#endif /* Table_h */
