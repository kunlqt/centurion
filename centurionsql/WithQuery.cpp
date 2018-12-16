#include "Query.h"
#include "Node.h"
#include "WithQuery.h"
#include <vector>

namespace centurion {
	std::vector<Node*> WithQuery::getChildren() {
		return std::vector<Node*>{ query_ };
	}


}
