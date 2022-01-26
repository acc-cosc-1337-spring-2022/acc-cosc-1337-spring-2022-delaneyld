cmake_minimum_required (VERSION 3.8)
project(cw_02_library)

add_library(cw_02_library "expressions.cpp" "expressions.h")
add_executable(cw_02_exe "main.cpp" "expressions.cpp")




