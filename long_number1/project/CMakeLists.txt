cmake_minimum_required(VERSION 3.16)
project(long_number VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


cmake_policy(SET CMP0077 NEW)


enable_testing()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/CMakeLists.txt")
    add_subdirectory(lib/googletest)
else()
    message(WARNING "GoogleTest not found - tests will be disabled")
endif()

add_subdirectory(source)

if(TARGET gtest_main)
    add_subdirectory(test)
endif()