add_executable(ex_04_tests "04_module_tests.cpp")
target_link_libraries(ex_04_tests ex_04_01_library ex_04_02_library ex_04_03_library ex_04_04_library
                      ex_04_05_library ex_04_06_library ex_04_07_library)
add_test(NAME ex_04_tests COMMAND ex_04_tests -s)