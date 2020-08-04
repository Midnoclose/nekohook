
# TODO: add function to test a library for wanted functions and apply conditionals as nessesary

file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE headers "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

add_custom_target(nekohook)

macro(ApplyCommon in_target)
    add_dependencies(nekohook ${in_target})
    set_property(TARGET ${in_target} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET ${in_target} PROPERTY CXX_STANDARD 17)

    target_include_directories(${in_target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/")
    target_include_directories(${in_target} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../")
    if (UNIX AND NOT APPLE)
        target_link_libraries(${in_target} PUBLIC rt pthread)
    endif ()

    install(TARGETS ${in_target} DESTINATION lib)
endmacro()

if(NEKOHOOK_BUILD_SHARED)
    add_library(nekohook_shared SHARED ${sources})
    ApplyCommon(nekohook_shared)
endif(NEKOHOOK_BUILD_SHARED)
if(NEKOHOOK_BUILD_STATIC)
    add_library(nekohook_static STATIC ${sources})
    ApplyCommon(nekohook_static)
endif(NEKOHOOK_BUILD_STATIC)


install(FILES ${headers} DESTINATION include/nekohook)
