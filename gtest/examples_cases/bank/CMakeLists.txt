cmake_minimum_required(VERSION 3.14)

set(BANK_Example gtest_example-cases_bank)

add_executable(${BANK_Example}
    main.cpp
    src/BankAccount.cpp
    tests/bank_test.cpp
)

# Inclui headers locais
target_include_directories(${BANK_Example}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Linka com GoogleTest via FetchContent
target_link_libraries(${BANK_Example}
    GTest::gtest
    pthread
)

add_test(NAME ${BANK_Example} COMMAND ${BANK_Example})
