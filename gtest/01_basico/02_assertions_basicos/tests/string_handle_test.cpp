#include <cstring>
#include <cctype>
#include <gtest/gtest.h>
#include "string_handle.hpp"

TEST(ToUpperTest, BasicTest)
{
    //Arrange
    char inputString[] = "Hello World";

    //Act
    toUpper(inputString);

    //Assert
    EXPECT_STREQ("HELLO WORLD",inputString);
}