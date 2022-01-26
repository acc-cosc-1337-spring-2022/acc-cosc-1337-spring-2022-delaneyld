cmake_minimum_required (VERSION 3.8)
project(cw_03_library)

add_library(cw_03_library "decision.cpp" "decision.h")
add_executable(cw_03_exe "main.cpp" "decision.cpp")




