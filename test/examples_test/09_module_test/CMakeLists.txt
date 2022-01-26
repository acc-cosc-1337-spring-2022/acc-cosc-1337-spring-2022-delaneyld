add_executable(ex_09_tests "09_module_tests.cpp")
target_link_libraries(ex_09_tests ex_09_01_library ex_09_02_library ex_09_03_library 
                      ex_09_04_library ex_09_05_library ex_09_06_library)
add_test(NAME ex_09_tests COMMAND ex_09_tests -s)