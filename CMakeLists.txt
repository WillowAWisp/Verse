cmake_minimum_required(VERSION 3.25)
project(Verse)

include(${CMAKE_SOURCE_DIR}/CMake/build.cmake)

add_subdirectory(Code/Applications)
add_subdirectory(Code/Libraries)
