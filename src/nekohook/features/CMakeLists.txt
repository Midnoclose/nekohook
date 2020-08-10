
file(GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(nekohook-dummy STATIC ${sources})
install(TARGETS nekohook-dummy DESTINATION lib)
install(FILES ${headers} DESTINATION include/nekohook/features)

