
##
# Welcome to the cmake lists file, this controls how nekohook will build for your system
##

cmake_minimum_required(VERSION 3.14)
project(nekohook CXX)

# Settings
set(NEKOHOOK_BUILD_SHARED OFF CACHE BOOL "Build the shared library")
set(NEKOHOOK_BUILD_STATIC ON CACHE BOOL "Build the static library")
set(NEKOHOOK_GFX opengl CACHE STRING "Graphics api to use: none;opengl")
set(NEKOHOOK_X86 OFF CACHE BOOL "Build x86 libraries for x86_64")
# Lib itself
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")
