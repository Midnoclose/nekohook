
##
# Welcome to the cmake lists file, this controls how nekohook will build for your system
##

cmake_minimum_required(VERSION 2.6)
project(nekohook)

# Settings
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif()
set(N_GAME NONE CACHE STRING "Game to build with")
add_definitions(-DNEKO_GAME="${N_GAME}")
set(N_USERNAME UNREGISTERED CACHE STRING "Register a username")
set(N_USERID 0 CACHE STRING "Register a id")
add_definitions(-DNEKO_USERNAME="${N_USERNAME}" -DNEKO_USERID=${N_USERID})
set(N_EXTERNAL false CACHE BOOL "Whether to build nekohook as an external program")
if(N_EXTERNAL)
  add_definitions(-DNEKO_EXTERNAL=1)
endif()

# Compile options
set(CMAKE_CXX_STANDARD 17)
# TODO: make warnings return errors
add_definitions(-D_USE_MATH_DEFINES=1) # Precompiled headers mess with this so we define it project wide
include(${CMAKE_CURRENT_SOURCE_DIR}/utils/ucm/cmake/ucm.cmake)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    ucm_add_flags(-fno-operator-names)
    ucm_add_flags(-g3 -ggdb -fasynchronous-unwind-tables -Og CONFIG Debug)
    # Potential increase in polymorphic functions -fstrict-vtable-pointers
    # Big maybe, needs some testing: -fno-gnu-unique
    # This one too, might break hooks... -freg-struct-return
    # maybe -flto,
    ucm_add_flags(-s -mtune=generic -Ofast -DNDEBUG -fno-rtti -fshort-enums -fno-plt -fvisibility=hidden CONFIG Release)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_definitions(/D_CRT_SECURE_NO_WARNINGS=1) # So we can use our normal libc functions
    ucm_add_flags(/RTC /W2 /Z7 CONFIG Debug)
    ucm_add_flags(/w /GR- CONFIG Release)
endif()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Project
ucm_add_dirs("src" TO sources RECURSIVE)
if(NOT N_EXTERNAL)
  add_library(nekohook SHARED ${sources})
else()
  add_executable(nekohook ${sources})
endif()
target_include_directories(nekohook PRIVATE include)
cotire(nekohook)

# Dependancies
add_definitions(-DBOOST_DATE_TIME_NO_LIB=1)
find_package(Boost REQUIRED)
target_include_directories(nekohook PRIVATE ${Boost_INCLUDE_DIRS})

add_subdirectory(external/nekolib)
target_link_libraries(nekohook ${NEKOLIB_LIBRARIES})
target_include_directories(nekohook PRIVATE ${NEKOLIB_INCLUDE_DIRS})
