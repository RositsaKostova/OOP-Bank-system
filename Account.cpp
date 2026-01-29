#include "Account.h"
#include <iostream>
#include <ctime>
#pragma warning (disable:4996)
using namespace std;

Account::Account(const MyString& username, const MyString& password, const MyString& iban, size_t Id)
{
	if (strlen(username.c_str()) == 0 || strlen(password.c_str()) == 0 || strlen(iban.c_str()) == 0)
	{
		isValid = false;
	}
	else
	{
		isValid = true;
	}
	setUsername(username);
	setPassword(password);
	setIban(iban);
	setId(Id);
	setDateOfCreation();
}
void Account::setUsername(const MyString& username)
{
	this->username = username;
}
void Account::setPassword(const MyString& password)
{
	this->password = password;
}
void Account::setIban(const MyString& iban)
{
	this->iban = iban;
}
void Account::setId(size_t Id)
{
	this->Id = Id;
}
void Account::setAmount(double amount)
{
	this->amount = amount;
}
void Account::setDateOfCreation()
{
	time_t current_time = time(NULL);
	char* tm = ctime(&current_time);
	dateOfCreation = tm;
}
void Account::printData() const
{
	cout << "Iban: " << iban.c_str() << endl;
	cout << "Id: " << Id << endl;
	cout << "Amount: " << amount << endl;
	cout << "Date of creation: " << dateOfCreation.c_str();
}
size_t Account::getId() const
{
	return Id;
}
const MyString& Account:: getIBAN() const
{
	return iban;
}
bool Account::getValidity() const
{
	return isValid;
}
double Account::getBalance() const
{
	return amount;
}
