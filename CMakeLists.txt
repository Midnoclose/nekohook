
cmake_minimum_required(VERSION 3.14)
project(nekohook CXX)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/cmake")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src")

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/AddNekohook.cmake")
