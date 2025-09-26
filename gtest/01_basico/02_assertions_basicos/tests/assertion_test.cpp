#include <gtest/gtest.h>
#include <vector>

int countPositives(std::vector<int> const & inputVector);

TEST(TestCountPositives, Basictest)
{
    // Arrange
    std::vector<int> inputVector{1,-2,3,-4,5,-6,-7};

    // Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(3,count);
}

TEST(TestCountPositives, EmptyVectorTest)
{
    // Arrange
    std::vector<int> inputVector{};

    // Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(0,count);
}

TEST(TestCountPositives, AllNegativesVectorTest)
{
    // Arrange
    std::vector<int> inputVector{-1,-4,-2,-7,-3,-10};

    // Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(0,count);
}