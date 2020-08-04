#!/bin/bash

cur_dir=$PWD
build_dir=bin/lin

# build cmake
mkdir -p $build_dir
cd $build_dir

if [ -f "./MakeFile" ]; then
  echo Cleaning up old-style build
  ./clean.sh
fi

if [ $# != 0 ] || [ ! -f CMakeCache.txt ]; then
  echo Generating CMake Files
  if [ -x "$(command -v clang++)" ]; then
    echo Enforcing use of clang for saftey
    CC=$(command -v clang)
    CXX=$(command -v clang++)
  fi
  cmake $cur_dir $@ # pass the args to cmake
fi

# make  with all threads
make -j$(nproc)

cd $cur_dir

ln -sf "$build_dir/libnekohook.so" ./
