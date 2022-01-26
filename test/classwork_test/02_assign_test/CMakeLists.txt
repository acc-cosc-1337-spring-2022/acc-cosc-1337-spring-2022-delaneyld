add_executable(cw_02_tests "expressions_tests.cpp")
target_link_libraries(cw_02_tests cw_02_library)
add_test(NAME cw_02_tests COMMAND cw_02_tests -s)