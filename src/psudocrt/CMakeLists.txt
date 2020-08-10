
# Do we even need this thing? i mean it helps, but what about organizing sources in cmake
set(psudocrt_start "${CMAKE_CURRENT_SOURCE_DIR}/start.cpp" PARENT_SCOPE)
set(psudocrt_end "${CMAKE_CURRENT_SOURCE_DIR}/end.cpp" PARENT_SCOPE)
install(FILES ${psudocrt_start} ${psudocrt_end} DESTINATION src/psudocrt/)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt" DESTINATION src/psudocrt)

