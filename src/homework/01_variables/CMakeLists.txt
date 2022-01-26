cmake_minimum_required (VERSION 3.8)
project(hw_01_library)

add_library(hw_01_library "variables.cpp" "variables.h")
add_executable(hw_01_exe "main.cpp" "variables.cpp")




