#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
	double overdraft;
public:
	PrivilegeAccount(const MyString& username, const MyString& password, const MyString& iban, size_t Id, double overdraft);

	void deposit(double sum) override;
	bool withdraw(double sum) override;
	void display() const override;

	Account* clone() const override;

};