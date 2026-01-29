#pragma once
#include "Account.h"

class NormalAccount : public Account
{
public:
	NormalAccount(const MyString& username, const MyString& password, const MyString& iban, size_t Id);
	
	void deposit(double sum) override;
	bool withdraw(double sum) override;
	void display() const override;

	virtual Account* clone() const override;
};