#include <gtest/gtest.h>
#include <string>

// Declaração da função que está em src/
std::string hello(const std::string& name);

TEST(HelloTest, RetornaMensagemCorreta) 
{
    EXPECT_EQ(hello("World"), "Hello, World!");
    EXPECT_EQ(hello("GTest"), "Hello, GTest!");
    EXPECT_NE(hello("World"), "Hello, world!"); // case-sensitive
}