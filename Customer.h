#pragma once
#include "String.h"

class Customer
{
	unsigned int id;
	MyString name;
	MyString address;
public:
	Customer();
	Customer(int id, const MyString& name, const MyString& address);

	void setId(size_t id);
	void setName(const MyString& name);
	void setAddress(const MyString& address);

	unsigned int getId() const;
	const MyString& getName() const;
	const MyString& getAddress() const;
};