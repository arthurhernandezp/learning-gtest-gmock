#include "BankAccount.hpp"
#include <gtest/gtest.h>

struct account_state
{
    int initial_balance;
    int withdraw_amount;
    int final_balance;
    bool sucess;
    
    // void PrintTo(const account_state& obj, std::ostream* os)
    // {
    //     *os << "initial_balance: " << obj.initial_balance
    //         << " withdraw_amount: " << obj.withdraw_amount
    //         << " final_balance: " << obj.final_balance
    //         << " sucess: " << obj.sucess;
    // }
    friend std::ostream& operator<<(std::ostream& os, const account_state& obj)
    {
        return os
            <<  "initial_balance: " << obj.initial_balance
            <<  " withdraw_amount: " << obj.withdraw_amount
            <<  " final_balance: " << obj.final_balance
            <<  " sucess: " << obj.sucess;
    }
};

class BankAccountTest : public testing::Test
{
    protected:
        BankAccount* account;
	    BankAccountTest()
        {
            account = new BankAccount();
        };

        ~BankAccountTest()
        {
            delete account;
        };
};

// Fixture class
class WithdrawAccountTest : public BankAccountTest, public testing::WithParamInterface<account_state>
{
    public:
        WithdrawAccountTest()
        {
            account->setBalance(GetParam().initial_balance);
        };
};

TEST_F(BankAccountTest, BankAccountStartsEmpty)
{
    EXPECT_EQ(account->getBalance(),0);
}

TEST_F(BankAccountTest, CanDepositMoney)
{
    account->deposit(100);
    EXPECT_EQ(100,account->getBalance());
}

TEST_P(WithdrawAccountTest,FinalBalance)
{
    auto as = GetParam();
    auto sucess = account->withdraw(as.withdraw_amount);
    EXPECT_EQ(as.final_balance,account->getBalance());
    EXPECT_EQ(as.sucess,sucess);
}

INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest, 
    testing::Values(
        account_state{100,50,50,true},                  // initial_balance: 100, withdraw_amount: 50 , final_balance: 50 , will be sucessed
        account_state{100,200,100,false}                // initial_balance: 100, withdraw_amount: 200, final_balance: 100, will failed
    ));