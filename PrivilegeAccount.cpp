#include <iostream>
#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const MyString& username, const MyString& password, const MyString& iban, size_t Id, double overdraft)
	: Account(username, password, iban, Id)
{
	if (overdraft > 0)
	{
		this->overdraft = overdraft;
	}
	else
	{
		this->overdraft = 0;
	}
}
void PrivilegeAccount::deposit(double sum)
{
	if (sum > 0)
	{
		setAmount(getBalance() + sum);
	}
}
bool PrivilegeAccount::withdraw(double sum)
{
	if (getBalance() + overdraft < sum)
	{
		return false;
	}
	else
	{
		setAmount(getBalance() - sum);
		return true;
	}
}
void PrivilegeAccount::display() const
{
	std::cout << "Type account: Privilege account" << std::endl;
	printData();
	std::cout << "Overdraft: " << overdraft;
	std::cout << std::endl;
}
Account* PrivilegeAccount::clone() const
{
	Account* copy = new PrivilegeAccount(*this);
	return copy;
}