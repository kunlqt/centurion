#pragma once

namespace centurion {
	
	class NodeLocation {
	public:
		NodeLocation(size_t line, size_t charPositionInLine) 
		: line_(line)
		, charPositionInLine_(charPositionInLine)  { }

		NodeLocation(const NodeLocation& other) {
			line_ = other.line_;
			charPositionInLine_ = other.charPositionInLine_;
		}

		size_t getLineNumber() const { return line_; }
		size_t getColumnNumber() const { return charPositionInLine_ + 1; }

	private:
		size_t line_;
		size_t charPositionInLine_;		
	};

}
