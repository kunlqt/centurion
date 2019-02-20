#pragma once
#include <boost/filesystem/path.hpp>

// Return a reasonable mime type based on the extension of a file.
beast::string_view mime_type(boost::filesystem::path path)
{
	using beast::iequals;
	if (!path.has_extension())
	{
		return "application/text";
	}
	auto const ext = path.extension().string();
	if (iequals(ext, ".html")) return "text/html";
	if (iequals(ext, ".css"))  return "text/css";
	if (iequals(ext, ".txt"))  return "text/plain";
	if (iequals(ext, ".js"))   return "application/javascript";
	if (iequals(ext, ".json")) return "application/json";
	if (iequals(ext, ".xml"))  return "application/xml";
	if (iequals(ext, ".png"))  return "image/png";
	if (iequals(ext, ".jpeg")) return "image/jpeg";
	if (iequals(ext, ".jpg"))  return "image/jpeg";
	if (iequals(ext, ".gif"))  return "image/gif";
	if (iequals(ext, ".ico"))  return "image/vnd.microsoft.icon";
	if (iequals(ext, ".svg"))  return "image/svg+xml";
	return "application/text";
}
