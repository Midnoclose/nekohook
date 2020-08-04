
##
# Welcome to the cmake lists file, this controls how nekohook will build for your system
##

cmake_minimum_required(VERSION 3.14)
project(nekohook)

# Settings
set(NEKOHOOK_BUILD_SHARED OFF CACHE BOOL "Build the shared library")
set(NEKOHOOK_BUILD_STATIC ON CACHE BOOL "Build the static library")
set(NEKOHOOK_GFX opengl CACHE STRING "Graphics api to use: none;opengl")

# Lib itself
add_subdirectory(src)
