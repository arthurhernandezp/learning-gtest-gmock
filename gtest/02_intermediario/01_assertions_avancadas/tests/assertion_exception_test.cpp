#include <gtest/gtest.h>
#include <stdexcept>
#include <assertion_exception.hpp>

TEST(SquareRootTest, NegativeArgumentTest)
{
    double inputValue = -9;
    ASSERT_THROW(mySqrt(inputValue),std::runtime_error);
}

TEST(SquareRootTest, PositiveArgumentTest)
{
    double inputValue = 9;
    ASSERT_NO_THROW(mySqrt(inputValue));
}