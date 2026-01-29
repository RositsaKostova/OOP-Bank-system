#pragma once
#include "String.h"
#include "Customer.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount .h"
#include "Account.h"

class Bank
{
	MyString bankName;
	MyString bankAddress;

	Customer* customers;
	size_t customersCount;
	size_t customersCapacity;

	Account** accounts;
	size_t accountsCount;
	size_t accountsCapacity;

	void copyFrom(const Bank& other);
	void free();
	void resizeCustomers();
	void resizeAccounts();

	bool existsCustomer(size_t id) const;
	int getIndexOfAccountByIBAN(const MyString& IBAN) const;
	int getIndexOfCustometById(unsigned int id) const;

public:
	Bank();
	~Bank();
	Bank(const Bank& other);
	Bank& operator=(const Bank& other);

	void setBankName(const MyString& bankName);
	void setBankAddress(const MyString& bankAddress);

	bool addCustomer();
	bool addAccount();
	void addAccount_(Account* account);
	void listCustomers() const;
	void listAccounts() const;
	bool listCustomerAccount(size_t id) const;
	bool transfer(double sum, const MyString& fromIBAN, const MyString& toIBAN);
	bool withdraw(const MyString& IBAN, double sum);
	bool deposit(const MyString& IBAN, double sum);
	bool deleteAccount(const MyString& IBAN);
	bool deleteCustomer(unsigned int id);
	void display() const;
};