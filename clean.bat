@echo off
::!C:\Windows\system32\cmd.exe cuz meme
//
:: cmake
rmdir /S /Q CMakeFiles\ > nul
rmdir /S /Q cotire\ > nul
del /F /Q CMakeCache.txt > nul
del /F /Q cmake_install.cmake > nul
del /F /Q nekohook_CXX_cotire.cmake > nul
del /F /Q nekohook_CXX_cotire.cmake > nul

:: Vs build files
rmdir /S /Q .vs\ > nul
del /F /Q CMakeSettings.json > nul
del /F /Q ALL_BUILD.vcxproj.filters > nul
del /F /Q ALL_BUILD.vcxproj.filters > nul
del /F /Q ZERO_CHECK.vcxproj.filters > nul
del /F /Q all_unity.vcxproj.filters > nul
del /F /Q clean_cotire.vcxproj.filters > nul
del /F /Q nekohook_unity.vcxproj.filters > nul
del /F /Q nekohook.vcxproj.filters > nul
del /F /Q ALL_BUILD.vcxproj > nul
del /F /Q ZERO_CHECK.vcxproj > nul
del /F /Q all_unity.vcxproj > nul
del /F /Q clean_cotire.vcxproj > nul
del /F /Q nekohook_unity.vcxproj > nul
del /F /Q nekohook.vcxproj > nul
del /F /Q libnekohook.sln > nul

:: binaries
rmdir /S /Q bin\ > nul
del /F /Q nekohook.dll > nul
