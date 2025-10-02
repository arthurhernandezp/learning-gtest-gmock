cmake_minimum_required(VERSION 3.14)

set(TEST_NAME gmock_example-cases_employeeManager)

include_directories(include)

add_executable(${TEST_NAME}
    src/EmployeeManager.cpp
    src/IDatabaseConnection.cpp
    tests/testRunner.cpp
)

# Linka com GoogleTest via FetchContent
target_link_libraries(${TEST_NAME}
    GTest::gmock
    GTest::gmock_main
    pthread
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
