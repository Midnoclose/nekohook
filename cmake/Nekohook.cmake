
function(NekohookApplyCommon target)
    set_property(TARGET "${target}" PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET "${target}" PROPERTY CXX_STANDARD 20)
    
    #target_compile_options("${target}" PRIVATE "-wambiguous-reversed-operator")
    target_include_directories("${target}" PRIVATE "${NEKOHOOK_SRC_DIR}")
    target_link_libraries("${target}" PRIVATE nanovg)
    if(UNIX AND NOT APPLE)
        target_link_libraries("${target}" PRIVATE rt pthread)
    endif()
endfunction(NekohookApplyCommon)

function(NekohookConstructSources)
    set(RET ${NEKOHOOK_SOURCES} ${ARGN} PARENT_SCOPE)
endfunction(NekohookConstructSources)

function(NekohookAddPsudocrt)
    set(RET ${psudocrt_start} ${ARGN} ${psudocrt_end} PARENT_SCOPE)
endfunction(NekohookAddPsudocrt)

function(AddNekohook name type)
    NekohookConstructSources(${ARGN})
    set(sources ${RET})

    set(target "nekohook-${name}")
    if(${type} STREQUAL "EXTERNAL")
        add_executable(${target} ${sources})
        target_compile_definitions(${target} PRIVATE -DNEKOHOOK_EXTERNAL=1)
    elseif(${type} STREQUAL "INTERNAL")
        NekohookAddPsudocrt(${sources})
        set(sources ${RET})
        add_library(${target} SHARED ${sources})
    else()
        message(FATAL "Unable to determine nekohook type: \"${type}\"")
    endif()

    list(POP_BACK ARGN i)
    if(NOT i STREQUAL "NO_DUMMY")
        target_link_libraries(${target} PUBLIC nekohook-dummy)
    endif()

    NekohookApplyCommon(${target})
endfunction(AddNekohook)


