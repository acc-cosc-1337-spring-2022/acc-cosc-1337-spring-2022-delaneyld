add_executable(cw_06_tests "rectangle_tests.cpp")
target_link_libraries(cw_06_tests cw_06_library)
add_test(NAME cw_06_tests COMMAND cw_06_tests -s)