cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Test)

enable_testing()
add_subdirectory(third-party)
add_executable(test_app tests/test.cpp)
target_link_libraries(test_app gtest_main gmock_main)
add_test(NAME test_app COMMAND test_app)