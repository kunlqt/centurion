#pragma once

#include "JoinCriteria.h"
#include "Identifier.h"
#include <vector>

namespace centurion
{
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
}
