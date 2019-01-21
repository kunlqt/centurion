#pragma once
#include "ParserRuleContext.h"
#include "SearchIterator.h"

namespace centurion {
	class DefaultVisitorResult : public antlr4::ParserRuleContext {
	public:
		DefaultVisitorResult() : rootSearchIterator_(nullptr) { }

		DefaultVisitorResult(const DefaultVisitorResult& other) = delete;

		DefaultVisitorResult(DefaultVisitorResult&& other) noexcept
			: selectedColumns_(std::move(other.selectedColumns_))
			, rootSearchIterator_(other.rootSearchIterator_)
		{
			other.rootSearchIterator_ = nullptr;
		}

		virtual ~DefaultVisitorResult()
		{
			delete rootSearchIterator_;
		}

		void add(std::string selectedColumn) {
			selectedColumns_.emplace_back(selectedColumn);
		}

		void setRootSearchIterator(SearchIterator* rootSearchIterator)
		{
			rootSearchIterator_ = rootSearchIterator;
		}

		std::string toString() const 
		{
			std::stringstream ss;
			for (const auto& selectedColumn : selectedColumns_)
			{
				ss << selectedColumn << ";";
			}
			return ss.str();
		}

		std::vector<std::string> selectedColumns() const
		{
			return selectedColumns_;
		}

		SearchIterator* rootSearchIterator() const
		{
			return rootSearchIterator_;
		}

	private:
		std::vector<std::string> selectedColumns_;
		SearchIterator* rootSearchIterator_;
	};

}
