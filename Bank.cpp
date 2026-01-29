#include "Bank.h"
#include <iostream>
#pragma warning (disable:4996)

const int MAX_CAPACITY = 1024;
const int DEFAULT_ALLOCATED_CELLS = 4;

void swap(Customer& cust1, Customer& cust2)
{
	Customer temp = cust1;
	cust1 = cust2;
	cust2 = temp;
}
void Bank::free()
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		delete accounts[i];
	}
	delete[] accounts;
	delete[] customers;
}
void Bank::copyFrom(const Bank& other)
{
	bankName = other.bankName;
	bankAddress = other.bankAddress;

	accountsCount = other.accountsCount;
	accountsCapacity = other.accountsCapacity;
	accounts = new Account * [accountsCapacity];
	for (size_t i = 0; i < accountsCount; i++)
	{
		accounts[i] = other.accounts[i]->clone();
	}

	customersCount = other.customersCount;
	customersCapacity = other.customersCapacity;
	customers = new Customer[customersCapacity];
	for (size_t i = 0; i < customersCount; i++)
	{
		customers[i] = other.customers[i];
	}
}
void Bank::resizeAccounts()
{
	Account** newCollection = new Account * [accountsCapacity *= 2];
	for (size_t i = 0; i < accountsCount; i++)
	{
		newCollection[i] = accounts[i];
	}
	delete[] accounts;
	accounts = newCollection;
}
void Bank::resizeCustomers()
{
	Customer* newCollection = new Customer[customersCapacity *= 2];
	for (size_t i = 0; i < customersCount; i++)
	{
		newCollection[i] = customers[i];
	}
	delete[] customers;
	customers = newCollection;
}
bool Bank::existsCustomer(size_t id) const
{
	for (size_t i = 0; i < customersCount; i++)
	{
		if (customers[i].getId() == id)
			return true;
	}
	return false;
}
int Bank::getIndexOfAccountByIBAN(const MyString& IBAN) const
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i] != nullptr && (accounts[i]->getIBAN() == IBAN))
		{
			return i;
		}
	}
	return -1;
}
int Bank::getIndexOfCustometById(unsigned int id) const
{
	for (size_t i = 0; i < customersCount; i++)
	{
		if (customers[i].getId() == id)
			return i;
	}
	return -1;
}
Bank::Bank()
{
	bankName = "Unknown";
	bankAddress = "Unknown";

	accountsCapacity = DEFAULT_ALLOCATED_CELLS;
	accountsCount = 0;
	accounts = new Account * [accountsCapacity];

	customersCapacity = DEFAULT_ALLOCATED_CELLS;
	customersCount = 0;
	customers = new Customer[customersCapacity];
}
Bank::~Bank()
{
	free();
}
Bank::Bank(const Bank& other)
{
	copyFrom(other);
}
Bank& Bank::operator=(const Bank& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
void Bank::setBankName(const MyString& bankName)
{
	this->bankName = bankName;
}
void Bank::setBankAddress(const MyString& bankAddress)
{
	this->bankAddress = bankAddress;
}
bool Bank::addCustomer()
{
	std::cout << "Enter customer's id: ";
	size_t id;
	std::cin >> id;
	std::cin.ignore();

	std::cout << "Enter customer's name: ";
	char buff[MAX_CAPACITY];
	std::cin.getline(buff, MAX_CAPACITY);
	MyString name = buff;

	std::cout << "Enter customer's address: ";
	char buff1[MAX_CAPACITY];
	std::cin.getline(buff1, MAX_CAPACITY);
	MyString address = buff1;

	Customer newCustomer(id, name, address);

	if (existsCustomer(id))
		return false;

	if (customersCount >= customersCapacity)
		resizeCustomers();
	
	customers[customersCount++] = newCustomer;
	return true;
}
void Bank::addAccount_(Account* account)
{
	if (accountsCount >= accountsCapacity)
		resizeAccounts();

	accounts[accountsCount++] = account;
}
bool Bank::addAccount()
{
	std::cout << "Enter type account (Normal account, Savings account or Privilege account): ";
	char type[MAX_CAPACITY];
	std::cin.ignore();
	std::cin.getline(type, MAX_CAPACITY );

	std::cout << "Enter ID: ";
	unsigned int ID;
	std::cin >> ID;

	std::cout << "Enter username: ";
	MyString username;
	std::cin >> username;

	std::cout << "Enter password: ";
	MyString password;
	std::cin >> password;
	
	std::cout << "Enter IBAN: ";
	MyString IBAN;
	std::cin >> IBAN;

	if (strcmp(type, "Savings account") == 0)
	{
		std::cout << "Enter interest rate: ";
		double rate;
		std::cin >> rate;

		SavingsAccount* sa = new SavingsAccount(username, password, IBAN, ID, rate);
		addAccount_(sa);
		return true;
	}
	else if (strcmp(type, "Privilege account") == 0)
	{
		std::cout << "Enter overdraft: ";
		double overdraft;
		std::cin >> overdraft;

		PrivilegeAccount* pa = new PrivilegeAccount(username, password, IBAN, ID, overdraft);
		addAccount_(pa);
		return true;
	}
	else if (strcmp(type, "Normal account") == 0)
	{
		NormalAccount* na = new NormalAccount(username, password, IBAN, ID);
		addAccount_(na);
		return true;
	}
	return false;
}
void Bank::listCustomers() const
{
	for (size_t i = 0; i < customersCount; i++)
	{
		std::cout << "Customer's name: " << customers[i].getName().c_str() << std::endl;
		std::cout << "Customer's address: " << customers[i].getAddress().c_str() << std::endl;
		std::cout << "Customer's id: " << customers[i].getId() << std::endl;
		std::cout << std::endl;
	}
}
void Bank::listAccounts() const
{
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i] != nullptr)
		{
			accounts[i]->display();
			std::cout << std::endl;
		}
	}
}
bool Bank::listCustomerAccount(size_t id)const
{
	size_t accountsNeeded = 0;
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i] != nullptr && (accounts[i]->getId() == id))
		{
			accounts[i]->display();
			std::cout << std::endl;
			accountsNeeded++;
		}
	}
	if (accountsNeeded == 0)
	{
		return false;
	}
	return true;
}
bool Bank::transfer(double sum, const MyString& fromIBAN, const MyString& toIBAN)
{
	int searchedFromIndex = getIndexOfAccountByIBAN(fromIBAN);
	int searchedToIndex = getIndexOfAccountByIBAN(toIBAN);

	if (searchedFromIndex == -1 || searchedToIndex == -1 || searchedFromIndex == searchedToIndex)
		return false;

	if (accounts[searchedFromIndex]->withdraw(sum))
	{
		accounts[searchedToIndex]->deposit(sum);
		return true;
	}
	return false;
}
bool Bank::withdraw(const MyString& IBAN, double sum)
{
	size_t searchedIndex = getIndexOfAccountByIBAN(IBAN);
	if (searchedIndex == -1)
	{
		return false;
	}
	if (!accounts[searchedIndex]->withdraw(sum))
	{
		return false;
	}
	return true;
}
bool Bank::deposit(const MyString& IBAN, double sum)
{
	size_t searchedIndex = getIndexOfAccountByIBAN(IBAN);
	if (searchedIndex == -1)
	{
		return false;
	}
	accounts[searchedIndex]->deposit(sum);
	return true;
}
bool Bank::deleteAccount(const MyString& IBAN)
{
	size_t searchedIndex = getIndexOfAccountByIBAN(IBAN);
	if (searchedIndex == -1)
		return false;

	delete accounts[searchedIndex];
	accounts[searchedIndex] = nullptr;
	return true;
}
bool Bank::deleteCustomer(unsigned int id)
{
	size_t indexToRemove = getIndexOfCustometById(id);
	if (indexToRemove == -1)
		return false;

	swap(customers[indexToRemove], customers[customersCount - 1]);
	customersCount--;
	
	for (size_t i = 0; i < accountsCount; i++)
	{
		if (accounts[i]->getId() == id)
		{
			delete accounts[i];
			accounts[i] = nullptr;
		}
	}
	return true;
}
void Bank::display() const
{
	std::cout << "Bank name: " << bankName.c_str() << std::endl;
	std::cout << "Bank address: " << bankAddress.c_str() << std::endl;
	std::cout << "Number customers: " << customersCount << std::endl;
	std::cout << "Number accounts: " << accountsCount << std::endl;
}
