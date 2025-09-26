#include "BankAccount.hpp"

BankAccount::BankAccount()
{
}

BankAccount::BankAccount(const int balance) : balance{balance}
{
}

void BankAccount::deposit(int amount)
{
    this->balance += amount;
}

bool BankAccount::withdraw(int amount)
{
    if(amount <= balance)
    {
        balance -= amount;
        return true;
    }
    return false;
}

// bool BankAccount::withdraw(int amount)
// {
//     auto newValue = this->balance - amount;
//     if(newValue > 0)
//         return false;

//     this->balance -= amount;
//     return true;
// }

int BankAccount::getBalance()
{
    return this->balance;
}

void BankAccount::setBalance(int value)
{
    this->balance = value;
}
