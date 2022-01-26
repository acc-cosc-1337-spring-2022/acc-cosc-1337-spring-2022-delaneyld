add_executable(ex_07_tests "07_module_tests.cpp")
target_link_libraries(ex_07_tests ex_07_library )
add_test(NAME ex_07_tests COMMAND ex_07_tests -s)