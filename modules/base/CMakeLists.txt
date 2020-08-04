
cmake_minimum_required (VERSION 2.6)
project (nekohook-base)

set(CMAKE_CXX_STANDARD 17)

ucm_add_dirs("${CMAKE_CURRENT_SOURCE_DIR}/src" TO sources RECURSIVE)

add_library(nekohook-base STATIC ${sources})
target_include_directories(nekohook-base PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(nekohook-base PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../include")
