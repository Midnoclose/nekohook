
function(AddNekohook name)
    set(target "nekohook-${name}")

    add_library("${target}" SHARED ${NEKOHOOK_SOURCES} ${ARGN})
    set_property(TARGET "${target}" PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET "${target}" PROPERTY CXX_STANDARD 20)
    
    target_include_directories("${target}" PRIVATE "${NEKOHOOK_SRC_DIR}")
    target_include_directories("${target}" PRIVATE "${NEKOHOOK_SRC_DIR}/nekohook")
    if (UNIX AND NOT APPLE)
        target_link_libraries("${target}" PRIVATE rt pthread)
    endif ()
endfunction(AddNekohook)
