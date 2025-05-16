
add_executable(test_long_number
    test_long_number.cpp
)


target_link_libraries(test_long_number
    PRIVATE
        long_number_lib
        gtest_main
)


add_test(
    NAME LongNumberTests
    COMMAND test_long_number
)


set_target_properties(test_long_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)