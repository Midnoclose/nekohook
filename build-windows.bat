@ECHO OFF

:: NOTE: This file isnt final, it is for development for now. production will come later

SET CUR_DIR=%CD%
SET BUILD_DIR=bin\win

MKDIR %BUILD_DIR%
CD %BUILD_DIR%


:: Call CMake only if there are some args to pass along or cmake hasn't been run yet
set RESULT=false
if NOT "%*" == "" SET RESULT=true
IF NOT EXIST CMakeCache.txt SET RESULT=true

if "%RESULT%" == "true" (
  ECHO Generating CMake Files
  :: These are temporary just for getting cmake to work as this script is finaky
  :: The boost dir is default for most boost installs
  cmake "%CUR_DIR%" -DBOOST_ROOT=C:\local\boost_1_65_1x32 -Wno-dev
  set EXITCODE=%ERRORLEVEL%
  if ERRORLEVEL 1 goto failure
)

ECHO Calling MSBuild
"C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\MSBuild\\15.0\\Bin\\msbuild" /t:build libnekohook.sln /p:Configuration=Release /verbosity:minimal /m
set EXITCODE=%ERRORLEVEL%

if ERRORLEVEL 0 copy /B /Y Release\nekohook.dll %CUR_DIR%

:failure
CD %CUR_DIR%
pause
EXIT /B %EXITCODE%
