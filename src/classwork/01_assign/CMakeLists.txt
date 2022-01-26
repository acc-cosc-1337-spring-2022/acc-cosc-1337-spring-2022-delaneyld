cmake_minimum_required (VERSION 3.8)
project(cw_01_library)

add_library(cw_01_library "types.cpp" "types.h")
add_executable(cw_01_exe "main.cpp" "types.cpp")




