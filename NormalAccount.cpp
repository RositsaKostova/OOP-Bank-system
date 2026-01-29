#include "NormalAccount.h"
#include <iostream>

NormalAccount::NormalAccount(const MyString& username, const MyString& password, const MyString& iban, size_t Id)
	: Account(username, password, iban, Id)
{}
void NormalAccount::deposit(double sum)
{
	if (sum > 0)
	{
		setAmount(getBalance() + sum);
	}
}
bool NormalAccount::withdraw(double sum)
{
	if (getBalance() < sum)
	{
		return false;
	}
	else
	{
		setAmount(getBalance() - sum);
		return true;
	}
}
void NormalAccount::display() const
{
	std::cout << "Type account: Normal account" << std::endl;
	printData();
	std::cout << std::endl;
}
Account* NormalAccount::clone()const
{
	Account* copy = new NormalAccount(*this);
	return copy;
}