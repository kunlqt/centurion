cmake_minimum_required(VERSION 3.10)
project(centurionsql)


add_library(centurionsql STATIC 
	AstBuilder.cpp
	AstNodes.cpp
	AstVisitor.cpp
	CaseInsensitiveStream.cpp
	CentSqlBaseListener.cpp
	CentSqlBaseVisitor.cpp
	CentSqlLexer.cpp
	CentSqlListener.cpp
	CentSqlParser.cpp
	CentSqlVisitor.cpp
	)
install(TARGETS centurionsql DESTINATION lib)
#install(FILES test.h DESTINATION include)
