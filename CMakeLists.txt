cmake_minimum_required(VERSION 3.10)
project(centurion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOLUTION_DIR ${PROJECT_SOURCE_DIR})

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WIN32_WINNT=0x0A00 -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS -DANTLR4CPP_STATIC -DNDEBUG -D_CONSOLE)
	include_directories($ENV{VCPKG_ROOT}/installed/x64-windows-static/include ${SOLUTION_DIR}/centuriondb ${SOLUTION_DIR}/centurionsql)
	link_directories($ENV{VCPKG_ROOT}/installed/x64-windows-static/lib lib)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
endif()

add_subdirectory(centuriondb)
add_subdirectory(centurionsql)
add_subdirectory(centurionserver)
