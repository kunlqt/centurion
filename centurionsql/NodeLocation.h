//
//  NodeLocation.h
//  Created by Vasko Mitanov on 11/7/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#ifndef NodeLocation_h
#define NodeLocation_h

namespace centurion {
    
class NodeLocation {
public:
    NodeLocation(size_t line, size_t charPositionInLine) {
        line_ = line;
        charPositionInLine_ = charPositionInLine;
    }

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

#endif /* NodeLocation_h */
