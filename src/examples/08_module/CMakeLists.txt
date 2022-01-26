add_library(ex_08_library "temperature.cpp" "temperature.h"
								"temperature_data.cpp" "temperature_data.h")
add_executable(ex_08_exe "main.cpp" "temperature.cpp" "temperature_data.cpp")