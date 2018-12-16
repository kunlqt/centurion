#pragma once

#include "Node.h"
#include <string>
#include <vector>

namespace centurion {
	class JoinCriteria {
	public:
		virtual bool equals(const JoinCriteria& obj) = 0;
		virtual int hashCode() = 0;
		virtual std::string toString() = 0;
		virtual std::vector<Node*> getNodes() const = 0;
	};

}
