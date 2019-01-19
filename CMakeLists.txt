cmake_minimum_required(VERSION 3.10)
project(centurion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOLUTION_DIR ${PROJECT_SOURCE_DIR})

include_directories(${SOLUTION_DIR}/centuriondb ${SOLUTION_DIR}/centurionsql)
link_directories(lib)
if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WIN32_WINNT=0x0A00 -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS -DANTLR4CPP_STATIC -DNDEBUG -D_CONSOLE)
	include_directories($ENV{VCPKG_ROOT}/installed/x64-windows-static/include)
	link_directories($ENV{VCPKG_ROOT}/installed/x64-windows-static/lib)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()
if(UNIX)
	link_directories(/usr/local/lib)
	include_directories(
		
		/home/vasko/personal/spdlog/include 
		/home/vasko/personal/rapidjson/include 
		/usr/local/include/antlr4-runtime
		)
endif()

set(BOOST_INCLUDEDIR /home/vasko/personal/boost_1_69_0)
set(BOOST_LIBRARYDIR /home/vasko/personal/boost_1_69_0/stage/lib)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.69.0 COMPONENTS program_options system filesystem REQUIRED)

add_subdirectory(centuriondb)
add_subdirectory(centurionsql)
add_subdirectory(centurionserver)
