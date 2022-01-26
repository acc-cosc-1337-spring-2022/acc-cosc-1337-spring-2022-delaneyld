add_executable(cw_03_tests "decisions_tests.cpp")
target_link_libraries(cw_03_tests cw_03_library)
add_test(NAME cw_03_tests COMMAND cw_03_tests -s)