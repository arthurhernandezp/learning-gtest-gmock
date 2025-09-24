cmake_minimum_required(VERSION 3.14)

set(TEST_NAME gtest_01_basico_configuracao)

add_executable(${TEST_NAME}
    src/hello.cpp
    tests/hello_test.cpp
)

# Linka com GoogleTest via FetchContent
target_link_libraries(${TEST_NAME}
    GTest::gtest
    GTest::gtest_main
    pthread
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
