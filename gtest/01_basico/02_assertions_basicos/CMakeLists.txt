cmake_minimum_required(VERSION 3.14)

set(TEST_NAME gtest_02_assertions_basicos)

include_directories(include)

add_executable(${TEST_NAME}
    src/assertion.cpp
    src/string_handle.cpp
    tests/assertion_test.cpp
    tests/string_handle_test.cpp
)

# Linka com GoogleTest via FetchContent
target_link_libraries(${TEST_NAME}
    GTest::gtest
    GTest::gtest_main
    pthread
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
