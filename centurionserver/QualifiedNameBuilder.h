#pragma once
#include "ParserRuleContext.h"
#include "QualifiedName.h"
#include "SearchIterator.h"

namespace centurion {
	class QualifiedNameBuilder : public antlr4::ParserRuleContext {
	public:
		QualifiedNameBuilder() { }
		QualifiedNameBuilder(QualifiedNameBuilder&& other)
			: qualifiedNames_(std::move(other.qualifiedNames_))
			, rootSearchIterator_(other.rootSearchIterator_)
		{
			
		}
		void add(std::shared_ptr<QualifiedName> qualifiedName) {
			qualifiedNames_.emplace_back(qualifiedName);
		}

		void setRootSearchIterator(SearchIterator* rootSearchIterator)
		{
			rootSearchIterator_.reset(rootSearchIterator);
		}

		std::string toString() const
		{
			std::stringstream ss;
			for (const auto& qualifiedName : qualifiedNames_)
			{
				ss << qualifiedName->toString() << ";";
			}
			return ss.str();
		}

		std::vector<std::string> qualifiedNames() const
		{
			std::vector<std::string> result;
			for (const auto& qualifiedName : qualifiedNames_)
			{
				result.emplace_back(qualifiedName->toString());
			}
			return result;
		}

		std::shared_ptr<SearchIterator> rootSearchIterator() const
		{
			return rootSearchIterator_;
		}

	private:
		std::vector<std::shared_ptr<QualifiedName>> qualifiedNames_;
		std::shared_ptr<SearchIterator> rootSearchIterator_;
	};

}
