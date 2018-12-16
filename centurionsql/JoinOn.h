#pragma once

#include "JoinCriteria.h"
#include "Expression.h"

namespace centurion
{
	class JoinOn : public JoinCriteria
	{
	public:
		JoinOn(Expression* expression): expression_(expression) { }

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
}
