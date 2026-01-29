#include "SavingsAccount .h"
#include <iostream>

SavingsAccount::SavingsAccount(const MyString& username, const MyString& password, const MyString& iban, size_t Id, double interestRate)
	: Account(username, password, iban, Id)
{
	if (interestRate > 0)
	{
		this->interestRate = interestRate;
	}
	else
	{
		this->interestRate = 0;
	}
}
void SavingsAccount::deposit(double sum)
{
	if (sum > 0)
	{
		setAmount(getBalance() + sum);
	}
}
bool SavingsAccount::withdraw(double sum)
{
	return false;
}
void SavingsAccount::display() const
{
	std::cout << "Type account: Savings account" << std::endl;
	printData();
	std::cout << "Interest Rate: " << interestRate;
	std::cout << std::endl;
}
Account* SavingsAccount::clone() const
{
	Account* copy = new SavingsAccount(*this);
	return copy;
}