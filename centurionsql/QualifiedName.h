#pragma once
#include "Utils.h"
#include <vector>
#include <string>
#include <sstream>

namespace centurion {

	class QualifiedName {
	public:

		QualifiedName() { }
		
		QualifiedName(const QualifiedName& other)
		{
			for (auto part : other.parts_)
			{
				parts_.emplace_back(part);
			}
			for (auto part : other.originalParts_)
			{
				originalParts_.emplace_back(part);
			}
		}

		QualifiedName(QualifiedName&& other)
		{
			parts_ = std::move(other.parts_);
			originalParts_ = std::move(other.originalParts_);
		}

		QualifiedName(const std::vector<std::string>& parts, const std::vector<std::string>& originalParts) {
			for (const auto& s : parts) parts_.push_back(s);
			for (const auto& s : originalParts) originalParts_.push_back(s);
		}

		QualifiedName(const std::vector<std::string>& originalParts, bool reverse = false) {
			if (originalParts.empty()) return;
			for (size_t idx = originalParts.size(); idx != 0; idx--) {
				std::string s = originalParts[idx - 1];
				parts_.emplace_back(toLowerCopy(s));
				originalParts_.emplace_back(s);
			}
		}

		QualifiedName(std::string originalPart) {
			parts_.emplace_back(toLowerCopy(originalPart));
			originalParts_.emplace_back(originalPart);
		}


		std::vector<std::string> getParts() const {
			return parts_;
		}

		std::vector<std::string> getOriginalParts() const {
			return originalParts_;
		}

		std::string toString() const
		{
			std::stringstream ss;
			if (parts_.empty())
			{
				ss << "/";
			} else {
				for (const auto& part : parts_)
				{
					ss << "/" << part;
				}
			}
			return ss.str();
		}

	private:
		std::vector<std::string> parts_;
		std::vector<std::string> originalParts_;
	};

}
