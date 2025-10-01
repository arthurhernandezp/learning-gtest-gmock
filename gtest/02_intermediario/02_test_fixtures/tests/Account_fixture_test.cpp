#include "Account.hpp"
#include <gtest/gtest.h>

class AccountTestFixture : public testing::Test
{
    public:
        void SetUp() override;
    protected:
        Account account;
};

//Agora todos os testes que usarem esse test fixture começaram com uma account com 10.5 no balance
void AccountTestFixture::SetUp()
{
    std::cout << "SetUp Called" << '\n';
    account.deposit(10.5);
}

TEST_F(AccountTestFixture, TestEmptyAccount)
{
    ASSERT_EQ(10.5,account.getBalance());
}

TEST_F(AccountTestFixture,TestDeposit)
{
    account.deposit(100);
    ASSERT_EQ(110.5,account.getBalance());
}

TEST_F(AccountTestFixture,TestWithdrawOK)
{
    account.withdraw(5);
    ASSERT_EQ(5.5,account.getBalance());
}

TEST_F(AccountTestFixture,TestWithdrawInsufficientFunds)
{
    ASSERT_THROW(account.withdraw(300);,std::runtime_error);
}

TEST_F(AccountTestFixture,TestTransferTo)
{
    //Arrange
    Account dest;

    //Act
    account.transfer(dest,2);

    //Assert
    ASSERT_EQ(8.5,account.getBalance());
    ASSERT_EQ(2,dest.getBalance());
}

TEST_F(AccountTestFixture,TestTransferInsufficientFundsTo)
{
    Account dest;
    ASSERT_THROW(account.transfer(dest,200),std::runtime_error);
}


