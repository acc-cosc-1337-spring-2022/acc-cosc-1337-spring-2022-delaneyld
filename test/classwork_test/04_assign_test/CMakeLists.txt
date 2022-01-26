add_executable(cw_04_tests "loops_tests.cpp")
target_link_libraries(cw_04_tests cw_04_library)
add_test(NAME cw_04_tests COMMAND cw_04_tests -s)