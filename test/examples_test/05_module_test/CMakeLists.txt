add_executable(ex_05_tests "05_module_tests.cpp")
target_link_libraries(ex_05_tests ex_05_01_library)
add_test(NAME ex_05_tests COMMAND ex_05_tests -s)