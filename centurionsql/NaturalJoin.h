#pragma once

#include "JoinCriteria.h"

namespace centurion
{
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
}