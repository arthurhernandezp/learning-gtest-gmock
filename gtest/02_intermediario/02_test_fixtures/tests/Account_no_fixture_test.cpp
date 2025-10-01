#include "Account.hpp"
#include <gtest/gtest.h>

TEST(AccountTest,TestEmptyAccount)
{
    //Arrange
    Account ac;

    //Act
    double balance = ac.getBalance();

    //Assert
    ASSERT_EQ(0,balance);
}

TEST(AccountTest,TestDeposit)
{
    //Arrange
    Account ac;

    //Act
    ac.deposit(100);

    //Assert
    ASSERT_EQ(100,ac.getBalance());
}

TEST(AccountTest,TestWithdrawOK)
{
    //Arrange
    Account ac;

    //Act
    ac.deposit(100);
    ac.withdraw(40);
    //Assert
    ASSERT_EQ(60,ac.getBalance());
}

TEST(AccountTest,TestWithdrawInsufficientFunds)
{
    //Arrange
    Account ac;

    //Act
    ac.deposit(100);
    
    //Assert
    ASSERT_THROW(ac.withdraw(300);,std::runtime_error);
}

TEST(AccountTest,TestTransferTo)
{
    //Arrange
    Account source;
    Account dest;
    source.deposit(200);
    dest.deposit(120);

    double transferValue = 50;

    //Act
    source.transfer(dest,transferValue);

    //Assert
    ASSERT_EQ(150,source.getBalance());
    ASSERT_EQ(170,dest.getBalance());
}

TEST(AccountTest,TestTransferInsufficientFundsTo)
{
    //Arrange
    Account source;
    Account dest;
    source.deposit(200);
    dest.deposit(120);

    double transferValue = 400;

    //Assert
    ASSERT_THROW(source.transfer(dest,transferValue),std::runtime_error);
}