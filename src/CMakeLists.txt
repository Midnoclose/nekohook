
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/psudocrt/")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/nekohook/")
set(NEKOHOOK_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/dummy/")


file(GLOB_RECURSE nanocanvas_src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE nanocanvas_headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h*")
add_library(nekohook-nanocanvas STATIC ${nanocanvas_src})

install(TARGETS nekohook-nanocanvas EXPORT nekohook-nanocanvas DESTINATION lib/nekohook)
install(EXPORT nekohook-nanocanvas DESTINATION lib/nekohook)
install(FILES ${nanocanvas_headers} DESTINATION include/NanoCanvas)
