#pragma once
#include <string>
#include <vector>
#include <boost/beast.hpp>

struct UriExtractor 
{
	void Parse(const boost::beast::string_view & queryURL, std::vector<std::string>& pathComponents, std::vector<std::pair<std::string, std::string>>& queryParams);
};
