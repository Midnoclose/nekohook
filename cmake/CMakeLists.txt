
include(CMakePackageConfigHelpers)
configure_package_config_file(
    NekohookConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/NekohookConfig.cmake 
    INSTALL_DESTINATION lib/cmake/Nekohook 
    PATH_VARS CMAKE_INSTALL_PREFIX)

install(FILES Nekohook.cmake ${CMAKE_CURRENT_BINARY_DIR}/NekohookConfig.cmake 
    DESTINATION lib/cmake/Nekohook)




