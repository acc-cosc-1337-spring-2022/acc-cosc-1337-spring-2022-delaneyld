cmake_minimum_required (VERSION 3.8)
project(hw_02_library)

add_library(hw_02_library "expressions.cpp" "expressions.h")
add_executable(hw_02_exe "main.cpp" "expressions.cpp")




