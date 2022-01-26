add_library(ex_06_02_library "shape.cpp" "shape.h"
                                "circle.cpp" "circle.h"
								"line.cpp" "line.h")
add_executable(ex_06_02_exe "main.cpp" "shape.cpp" "circle.cpp" "line.cpp")