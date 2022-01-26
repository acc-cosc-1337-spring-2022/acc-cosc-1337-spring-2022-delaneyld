add_executable(cw_05_tests "sequence_tests.cpp")
target_link_libraries(cw_05_tests cw_05_library)
add_test(NAME cw_05_tests COMMAND cw_05_tests -s)