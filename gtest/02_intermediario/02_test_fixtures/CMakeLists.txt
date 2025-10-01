cmake_minimum_required(VERSION 3.14)

set(TEST_NAME gtest_intermediario_02_test_fixtures)

include_directories(include)

add_executable(${TEST_NAME}
    src/Account.cpp
    tests/Account_no_fixture_test.cpp
    tests/Account_fixture_test.cpp
)

# Linka com GoogleTest via FetchContent
target_link_libraries(${TEST_NAME}
    GTest::gtest
    GTest::gtest_main
    pthread
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
