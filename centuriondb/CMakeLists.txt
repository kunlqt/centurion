cmake_minimum_required(VERSION 3.10)
project(centuriondb)

add_library(centuriondb STATIC CityHash.cpp DatabaseManager.cpp Sha2.cpp)
install(TARGETS centuriondb DESTINATION lib)
#install(FILES test.h DESTINATION include)
