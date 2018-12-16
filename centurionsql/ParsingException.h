#pragma once

#include <stdexcept>
#include <exception>

namespace centurion {
	class ParsingException : public std::runtime_error {
	public:
		ParsingException(const std::string& msg) : std::runtime_error(msg) {

		}
	};
}
