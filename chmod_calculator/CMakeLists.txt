cmake_minimum_required(VERSION 3.24.1 FATAL_ERROR)
set(CMAKE_CXX_COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++")
set(CMAKE_C_COMPILER "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang")
set(CMAKE_BUILD_TYPE Debug)

set(USE_BOOST true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

#the build:
project(chmod_calc)

add_subdirectory(wxWidgets-3.2.1)
add_subdirectory(chmod_calc)
add_subdirectory(unit_tests)