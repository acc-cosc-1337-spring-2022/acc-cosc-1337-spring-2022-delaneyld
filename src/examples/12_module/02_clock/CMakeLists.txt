cmake_minimum_required(VERSION 3.8)
project(grahics_clock)

set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR C:/Users/Public/cpp/wxWidgets-3.1.2)
set(wxWidgets_LIB_DIR C:/Users/Public/cpp/wxWidgets-3.1.2/lib/vc_x64_lib)
set(wxWidgets_CONFIGURATION msw)

find_package(wxWidgets REQUIRED net gl core base)

if(wxWidgets_FOUND)
	include(${wxWidgets_USE_FILE})

	set(SOURCE_FILES main.cpp app.h app.cpp frame.h frame.cpp 
	                 panel.h panel.cpp clock.h clock.cpp
					 clock_graphic.h clock_graphic.cpp)
	
	add_executable(ex_12_02_exe WIN32 ${SOURCE_FILES})
	target_link_libraries(ex_12_02_exe ${wxWidgets_LIBRARIES})
endif()

