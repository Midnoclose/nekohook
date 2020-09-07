
# NOTE: Split nekohook into a sdk and the "features" could potentially bride gaps based on perspectives. currently its a fps cheat, but what about a sdk but used to make cheats easily???

# TODO: test if exporting a interface keeps sources when installed, which can be used in target_sources afterwards

cmake_minimum_required(VERSION 3.14)
project(nekohook CXX)

include("${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/cmake")
include(cmake/Nekohook.cmake)

enable_testing()
include(tests/CMakeLists.txt)

