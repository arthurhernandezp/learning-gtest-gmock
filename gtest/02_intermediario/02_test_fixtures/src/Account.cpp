#include "Account.hpp"
#include <stdexcept>

Account::Account()
{

}

void Account::deposit(double sum)
{
    mBalance += sum;
}

void Account::withdraw(double sum)
{
    if(mBalance < sum)
    {
        throw std::runtime_error("Insufficient funds");
    }
    mBalance -= sum;
}

double Account::getBalance() const
{
    return mBalance;
}

void Account::transfer(Account &to, double sum)
{
    withdraw(sum);      // Soltará uma error se nao for suficiente
    to.deposit(sum);
}
