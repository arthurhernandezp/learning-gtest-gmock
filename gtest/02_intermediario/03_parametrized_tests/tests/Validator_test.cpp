#include "Validator.hpp"
#include <gtest/gtest.h>

//Validator(5,10)
//  4,5,6,7,8,9,10,11

struct TestCase
{
    int value;
    bool expectedValue;
};

class ValidatorTestFixture : public testing::TestWithParam<std::pair<int,bool>>
{
    public:
    protected:
        Validator mValidator{5,10};
    private:
};

class ValidatorTestFixture2 : public testing::TestWithParam<std::pair<int,bool>>
{
    public:
    protected:
        Validator mValidator{5,10};
    private:
};
TEST_P(ValidatorTestFixture, TestInRange)
{
    std::pair<int,bool> param = GetParam();
    bool isInside = mValidator.inRange(param.first);
    bool expectedValue = param.second;

    ASSERT_EQ(expectedValue,isInside);
}

INSTANTIATE_TEST_SUITE_P(InRange,ValidatorTestFixture,
    testing::Values(
        std::make_pair(5,true),
        std::make_pair(6,true),
        std::make_pair(7,true),
        std::make_pair(8,true),
        std::make_pair(9,true),
        std::make_pair(10,true),
        std::make_pair(1,false),
        std::make_pair(22,false),
        std::make_pair(3,false),
        std::make_pair(0,false),
        std::make_pair(13,false),
        std::make_pair(-10,false)
    ));
