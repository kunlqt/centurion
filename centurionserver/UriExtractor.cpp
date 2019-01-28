#include "UriExtractor.h"
#include <uriparser/Uri.h>

bool validURI(UriUriA & uri) {
	if (uri.scheme.first == NULL || uri.scheme.first == uri.scheme.afterLast) {
		return false;
	}
	if (uri.hostText.first == NULL || uri.hostText.first == uri.hostText.afterLast) {
		return false;
	}
	return true;
}

void UriExtractor::Parse(const boost::beast::string_view & queryURLa, std::vector<std::string>& pathComponents, std::vector<std::pair<std::string, std::string>> & queryParams) {
	pathComponents.clear();
	queryParams.clear();

	if (queryURLa.empty()) {
		return;
	}

	std::string queryURL = "http://0.0.0.0";
	queryURL.append(queryURLa.to_string());

	const char * bptr = queryURL.data();
	const char * eptr = bptr + queryURL.length();

	UriParserStateA uriParserState;
	UriUriA uri;
	uriParserState.uri = &uri;

	//parse the uri by calling the function in the uriparser lib
	if (uriParseUriExA(&uriParserState, bptr, eptr) != URI_SUCCESS || !validURI(uri)) {
		uriFreeUriMembersA(&uri);
		return;
	}

	bptr = uri.scheme.first;
	eptr = uri.scheme.afterLast;
	//check if the uri is http uri
	if (bptr == NULL || bptr == eptr) {
		uriFreeUriMembersA(&uri);
		return;
	}

	std::string schema(bptr, eptr - bptr);
	if ((schema != "http") && (schema != "https")) {
		uriFreeUriMembersA(&uri);
		return;
	}

	UriPathSegmentA* currentPathSegment = uri.pathHead;
	while (currentPathSegment != nullptr)
	{
		if (currentPathSegment->text.afterLast > currentPathSegment->text.first) {
			pathComponents.emplace_back(std::string(currentPathSegment->text.first, currentPathSegment->text.afterLast - currentPathSegment->text.first));
		}
		currentPathSegment = currentPathSegment->next;
	}
	//parse the query uri
	UriQueryListA * queryList = NULL;
	int itemCount;

	bptr = uri.query.first;
	eptr = uri.query.afterLast;
	//calling the function in the uriparser lib
	if (bptr != NULL && bptr != eptr &&
		uriDissectQueryMallocA(&queryList, &itemCount, bptr, eptr) == URI_SUCCESS) {
		queryParams.reserve(itemCount);
		UriQueryListA * itemPtr = queryList;
		for (int i = 0; i < itemCount && itemPtr != NULL; i++, itemPtr = itemPtr->next) {
			queryParams.emplace_back(itemPtr->key ? itemPtr->key : "", itemPtr->value ? itemPtr->value : "");
		}
	}
	if (queryList) {
		uriFreeQueryListA(queryList);
	}
	uriFreeUriMembersA(&uri);

}

