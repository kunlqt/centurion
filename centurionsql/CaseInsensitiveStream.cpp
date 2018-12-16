//
//  CaseInsensitiveStream.cpp
//  SqlParser
//
//  Created by Vasko Mitanov on 11/2/18.
//  Copyright © 2018 vasko. All rights reserved.
//

#include "CaseInsensitiveStream.h"
#include "Exceptions.h"
#include "misc/Interval.h"
#include "IntStream.h"

#include "support/StringUtils.h"
#include "support/CPPUtils.h"

#include <cwctype>


using namespace antlr4;
using namespace antlrcpp;

using misc::Interval;

CaseInsensitiveStream::CaseInsensitiveStream(const std::string &input) : p(0) {
    load(input);
}

CaseInsensitiveStream::CaseInsensitiveStream(const char data_[], size_t numberOfActualCharsInArray)
: CaseInsensitiveStream(std::string(data_, numberOfActualCharsInArray)) {
}

CaseInsensitiveStream::CaseInsensitiveStream(std::istream &stream) : p(0) {
    load(stream);
}

void CaseInsensitiveStream::load(const std::string &input) {
    // Remove the UTF-8 BOM if present.
    const char bom[4] = "\xef\xbb\xbf";
    if (input.compare(0, 3, bom, 3) == 0)
        _data = antlrcpp::utf8_to_utf32(input.data() + 3, input.data() + input.size());
    else
        _data = antlrcpp::utf8_to_utf32(input.data(), input.data() + input.size());
    p = 0;
}

void CaseInsensitiveStream::load(std::istream &stream) {
    if (!stream.good() || stream.eof()) // No fail, bad or EOF.
        return;
    
    _data.clear();
    
    std::string s((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
    load(s);
}

void CaseInsensitiveStream::reset() {
    p = 0;
}

void CaseInsensitiveStream::consume() {
    if (p >= _data.size()) {
        assert(LA(1) == IntStream::EOF);
        throw IllegalStateException("cannot consume EOF");
    }
    
    if (p < _data.size()) {
        p++;
    }
}

size_t CaseInsensitiveStream::LA(ssize_t i) {
    if (i == 0) {
        return 0; // undefined
    }
    
    auto position = static_cast<ssize_t>(p);
    if (i < 0) {
        i++; // e.g., translate LA(-1) to use offset i=0; then _data[p+0-1]
        if ((position + i - 1) < 0) {
            return IntStream::EOF; // invalid; no char before first char
        }
    }
    
    if ((position + i - 1) >= static_cast<ssize_t>(_data.size())) {
        return IntStream::EOF;
    }
    return std::towupper(_data[static_cast<size_t>((position + i - 1))]);
}

size_t CaseInsensitiveStream::LT(ssize_t i) {
    return LA(i);
}

size_t CaseInsensitiveStream::index() {
    return p;
}

size_t CaseInsensitiveStream::size() {
    return _data.size();
}

// Mark/release do nothing. We have entire buffer.
ssize_t CaseInsensitiveStream::mark() {
    return -1;
}

void CaseInsensitiveStream::release(ssize_t /* marker */) {
}

void CaseInsensitiveStream::seek(size_t index) {
    if (index <= p) {
        p = index; // just jump; don't update stream state (line, ...)
        return;
    }
    // seek forward, consume until p hits index or n (whichever comes first)
    index = std::min(index, _data.size());
    while (p < index) {
        consume();
    }
}

std::string CaseInsensitiveStream::getText(const Interval &interval) {
    if (interval.a < 0 || interval.b < 0) {
        return "";
    }
    
    size_t start = static_cast<size_t>(interval.a);
    size_t stop = static_cast<size_t>(interval.b);
    
    
    if (stop >= _data.size()) {
        stop = _data.size() - 1;
    }
    
    size_t count = stop - start + 1;
    if (start >= _data.size()) {
        return "";
    }
    
    return antlrcpp::utf32_to_utf8(_data.substr(start, count));
}

std::string CaseInsensitiveStream::getSourceName() const {
    if (name.empty()) {
        return IntStream::UNKNOWN_SOURCE_NAME;
    }
    return name;
}

std::string CaseInsensitiveStream::toString() const {
    return antlrcpp::utf32_to_utf8(_data);
}
