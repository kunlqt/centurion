cmake_minimum_required(VERSION 3.10)
project(uriparser)

add_library(uriparser STATIC 
	UriCommon.c  
	UriCompare.c  
	UriEscape.c  UriFile.c  UriIp4.c  UriIp4Base.c  UriMemory.c  UriNormalize.c  UriNormalizeBase.c  UriParse.c  UriParseBase.c  UriQuery.c  UriRecompose.c  UriResolve.c  UriShorten.c	
	)
target_include_directories(uriparser PRIVATE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include)
install(TARGETS uriparser DESTINATION lib)
#install(FILES test.h DESTINATION include)
