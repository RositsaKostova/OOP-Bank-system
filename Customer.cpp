#include "Customer.h"

Customer::Customer()
{
	setId(0);
	setName("Unknown");
	setAddress("Unknown");
}
Customer::Customer(int id, const MyString& name, const MyString& address)
{
	setId(id);
	setName(name);
	setAddress(address);
}
void Customer::setId(size_t id)
{
	this->id = id;
}
bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}
bool isNameValid(const char* name)
{
	return isUpper(*name);
}
void Customer::setName(const MyString& name)
{
	if (isNameValid(name.c_str()))
	{
		this->name = name;
	}
}
void Customer::setAddress(const MyString& address)
{
	this->address = address;
}
unsigned int Customer::getId() const
{
	return id;
}
const MyString& Customer::getName() const
{
	return name;
}
const MyString& Customer::getAddress() const
{
	return address;
}
