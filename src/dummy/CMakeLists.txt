
file(GLOB_RECURSE dummy_src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_library(nekohook-dummy STATIC ${dummy_src})
install(TARGETS nekohook-dummy DESTINATION lib/)

