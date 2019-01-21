#pragma once

#include <string>
#include <algorithm> 
#include <cwctype>
#include <locale>
#include <vector>
#include <optional>

namespace centurion {
	static inline std::string& replace(std::string& s, const std::string& from, const std::string& to)
	{
		if (!from.empty())
			for (size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
				s.replace(pos, from.size(), to);
		return s;
	}

	static inline std::string toLowerCopy(const std::string& s) {
		std::string result;
		const auto& loc = std::locale();
		std::for_each(s.begin(), s.end(), [&result, &loc](auto c) { result.push_back(std::tolower(c, loc)); });
		return result;
	}

	template<typename T> struct is_shared_ptr : std::false_type {};
	template<typename T> struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};

	inline void removeQuotes(std::string& value)
	{
		if ((value.size() >= 2) && (value.front() == '\'' && value.back() == '\''))
		{
			value.erase(value.size() - 1);
			value.erase(0, 1);
		}
	}

	template <class T>
	inline std::size_t hashCombine(std::size_t seed, const T& v)
	{
		std::hash<T> hasher;
		return seed ^ (hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
	}

}
