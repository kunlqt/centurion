cmake_minimum_required(VERSION 3.10)
project(centurionserver)

add_executable(centurionserver  
	HttpSession.cpp
	Listener.cpp
	Main.cpp
	QueryDocumentHandler.cpp
	SearchIteratorBuilder.cpp
	SharedState.cpp
	WebsocketSession.cpp
	)

if(MSVC)
	target_link_libraries(centurionserver 
		centurionsql 
		centuriondb
		antlr4-runtime.lib 
		boost_program_options-vc140-mt.lib 
		boost_filesystem-vc140-mt.lib 
		boost_system-vc140-mt.lib 		
		lz4.lib 
		zlib.lib 
		snappy.lib 
		rocksdb.lib
		fmt.lib
		Shlwapi.lib Rpcrt4.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib)
endif()
if(UNIX)
	target_link_libraries(centurionserver 
		PRIVATE centurionsql 
		centuriondb
		antlr4-runtime.a 
		rocksdb.a
		lz4.a 
		z.a
	        zstd.a	
		snappy.a 
		bz2.a
		pthread
		${Boost_LIBRARIES}
		)
endif()
if(Boost_FOUND)
	target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
endif(Boost_FOUND)

install(TARGETS centurionserver DESTINATION bin)
#install(FILES test.h DESTINATION include)
