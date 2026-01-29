#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
	double interestRate;
public:
	SavingsAccount(const MyString& username, const MyString& password, const MyString& iban, size_t Id, double interestRate);
	
	void deposit(double sum) override;
	bool withdraw(double sum) override;
	void display() const override;
	Account* clone() const override;
};