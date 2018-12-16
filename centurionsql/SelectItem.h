#pragma once

#include "NodeLocation.h"
#include "Node.h"
#include <antlr4-runtime.h>
#include <optional>

namespace centurion {
	class SelectItem : public Node {
	public:		
		SelectItem(std::optional<NodeLocation> location) : Node(location) { }

	};

}
