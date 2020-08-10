
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/psudocrt/")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/nekohook/")
set(NEKOHOOK_SRC_ROOT "${CMAKE_CURRENT_LIST_DIR}" PARENT_SCOPE)
#set(NEKOHOOK_SOURCES "${sources}" PARENT_SCOPE)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/dummy/")

