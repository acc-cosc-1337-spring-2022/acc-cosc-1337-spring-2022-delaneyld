add_executable(cw_01_tests "types_tests.cpp")
target_link_libraries(cw_01_tests cw_01_library)
add_test(NAME cw_01_tests COMMAND cw_01_tests -s)