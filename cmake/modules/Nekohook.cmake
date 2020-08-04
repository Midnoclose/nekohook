
check_ipo_supported()

function(internal_nekohook_link_libraries)

    if(NEKOHOOK_BUILD_SHARED=true shared_library)
    set_property(TARGET nekohook-static PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET nekohook-shared PROPERTY CXX_STANDARD 17)

endfunction(internal_nekohook_link_libraries)
