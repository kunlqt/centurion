#pragma once
#include "Utils.h"
#include <vector>
#include <string>
#include <sstream>

namespace centurion {

	class QualifiedName {
	public:
		QualifiedName() { }
		QualifiedName(QualifiedName&& other)
		{
			parts_ = std::move(other.parts_);
			originalParts_ = std::move(other.originalParts_);
		}

		QualifiedName(const std::vector<std::string>& parts, const std::vector<std::string>& originalParts) {
			for (const auto& s : parts) parts_.push_back(s);
			for (const auto& s : originalParts) originalParts_.push_back(s);
		}

		QualifiedName(const std::vector<std::string>& originalParts) {
			for (auto& s : originalParts) {
				parts_.emplace_back(toLowerCopy(s));
				originalParts_.emplace_back(s);
			}
		}

		QualifiedName(std::string originalPart) {
			parts_.emplace_back(toLowerCopy(originalPart));
			originalParts_.emplace_back(originalPart);
		}

		QualifiedName(const QualifiedName& other) {
			for (const auto& s : other.getParts()) parts_.push_back(s);
			for (const auto& s : other.getOriginalParts()) originalParts_.push_back(s);
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
