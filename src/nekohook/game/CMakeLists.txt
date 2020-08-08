file(GLOB tmp_sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
set(sources ${sources} ${tmp_sources} PARENT_SCOPE)
install(FILES ${headers} DESTINATION include/nekohook/game)
