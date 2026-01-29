#pragma once
#include "String.h"

class Account
{
	MyString username;
	MyString password;
	MyString iban;
	MyString dateOfCreation;
	size_t Id;
	double amount;
	bool isValid;
	
public:
	Account(const MyString& username, const MyString& password, const MyString& iban, size_t Id);

	void setUsername(const MyString& username);
	void setPassword(const MyString& password);
	void setIban(const MyString& iban);
	void setId(size_t Id);
	void setAmount(double amount);
	void setDateOfCreation();

	virtual ~Account() {};
	virtual void deposit(double sum) = 0;
	virtual bool withdraw(double sum) = 0;
	virtual void display() const = 0;
	virtual Account* clone() const = 0;

	void printData() const;
	size_t getId() const;
	const MyString& getIBAN() const;
	bool getValidity() const;
	double getBalance() const;
};