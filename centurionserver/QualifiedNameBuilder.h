#pragma once
#include "ParserRuleContext.h"
#include "QualifiedName.h"
#include "SearchIterator.h"

namespace centurion {
	class QualifiedNameBuilder : public antlr4::ParserRuleContext {
	public:
		QualifiedNameBuilder() { }

		QualifiedNameBuilder(const QualifiedNameBuilder& other) = delete;

		QualifiedNameBuilder(QualifiedNameBuilder&& other) noexcept
			: qualifiedNames_(std::move(other.qualifiedNames_))
			, rootSearchIterator_(other.rootSearchIterator_)
		{
			other.rootSearchIterator_ = nullptr;
		}

		virtual ~QualifiedNameBuilder()
		{
			delete rootSearchIterator_;
		}

		void add(std::string qualifiedName) {
			qualifiedNames_.emplace_back(qualifiedName);
		}

		void setRootSearchIterator(SearchIterator* rootSearchIterator)
		{
			rootSearchIterator_ = rootSearchIterator;
		}

		std::string toString() const 
		{
			std::stringstream ss;
			for (const auto& qualifiedName : qualifiedNames_)
			{
				ss << qualifiedName << ";";
			}
			return ss.str();
		}

		std::vector<std::string> qualifiedNames() const
		{
			return qualifiedNames_;
		}

		SearchIterator* rootSearchIterator() const
		{
			return rootSearchIterator_;
		}

	private:
		std::vector<std::string> qualifiedNames_;
		SearchIterator* rootSearchIterator_;
	};

}
