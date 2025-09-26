#pragma once

class BankAccount
{
    public:
        BankAccount();
        explicit BankAccount(const int balance);
        void deposit(int amount);
        bool withdraw(int amount);

        int getBalance();
        void setBalance(int value);
    private:
        int balance = 0;
};