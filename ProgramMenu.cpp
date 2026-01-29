#include "ProgramMenu.h"
#include <iostream>
using namespace std;

void menu(Bank& bank)
{
	cout << "1. Edit" << endl;
	cout << " a. Customer" << endl;
	cout << "  i. Add new customer" << endl;
	cout << "  ii. Delete customer" << endl;
	cout << " b. Account" << endl;
	cout << "  i. Add new account" << endl;
	cout << "  ii. Delete account" << endl;
	cout << "2. List" << endl;
	cout << " a. List all customers" << endl;
	cout << " b. List all accounts" << endl;
	cout << " c. List customer account" << endl;
	cout << " d. List log" << endl;
	cout << "3. Action" << endl;
	cout << " a. Withdraw from account" << endl;
	cout << " b. Deposit to account" << endl;
	cout << " c. Transfer" << endl;
	cout << "4. Display info for the bank" << endl;
	cout << "5. Quit" << endl << endl;

	cout << "Follow the menu above!!!!" << endl;

	bool toLoop = true;
	while (toLoop)
	{
		cout << "Please, enter a number between 1 and 5: ";
		size_t number;
		cin >> number;

		switch (number)
		{
		case 1:
			cout << "Edit" << endl;
			cout << "Enter a letter 'a' to edit a customer or 'b' to edit an account: ";
			char letter;
			cin >> letter;
			if (letter == 'a')
			{
				cout << "Customer" << endl;
				cout << "Enter '1' to Add new customer or enter '2' to  Delete customer: ";
				size_t num;
				cin >> num;
				if (num == 1)
				{
					if (bank.addCustomer())
					{
						cout << "Successfully added customer!" << endl << endl;
					}
					else
					{
						cout << "Failed to add customer!" << endl << endl;
					}
				}
				else if (num == 2)
				{
					cout << "Enter id to delete customer: ";
					size_t id;
					cin >> id;
					if (bank.deleteCustomer(id))
					{
						cout << "Successfully deleted customer!" << endl << endl;
					}
					else
					{
						cout << "Failed to delete customer!" << endl << endl;
					}
				}
				else
				{
					cout << "Invalid number!" << endl << endl;
				}
			}
			else if (letter == 'b')
			{
				cout << "Account" << endl;
				cout << "Enter '1' to Add new account or enter '2' to  Delete account: ";
				size_t num;
				cin >> num;
				if (num == 1)
				{
					if (bank.addAccount())
					{
						cout << "Successfully added account!" << endl << endl;
					}
				}
				else if (num == 2)
				{
					cout << "Please, enter IBAN to delete account!";
					MyString IBAN;
					cin >> IBAN;
					if (bank.deleteAccount(IBAN))
					{
						cout << "Successfully deleted account" << endl << endl;
					}
				}
				else
				{
					cout << "Invalid number!" << endl << endl;
				}
			}
			else
			{
				cout << "Invalid letter(follow the menu above)" << endl;
			}
			break;
		case 2:
			cout << "List" << endl;
			cout << "Enter a letter between 'a', 'b' , 'c' or 'd': ";
			char letter_;
			cin >> letter_;
			if (letter_ == 'a')
			{
				bank.listCustomers();
			}
			else if (letter_ == 'b')
			{
				bank.listAccounts();
			}
			else if (letter_ == 'c')
			{
				cout << "Please, enter customer's id: ";
				size_t id;
				cin >> id;
				if (!bank.listCustomerAccount(id))
				{
					cout << "There is not a customer with such an id or there is not such an account!!" << endl << endl;
				}
			}
			else if (letter_ == 'd')
			{

			}
			else
			{
				cout << "Invalid letter(follow the menu above)" << endl;
			}
			break;
		case 3:
			cout << "Action" << endl;
			cout << "Enter a letter 'a' to withdraw from account, 'b' to deposit to account or 'c' to transfer: ";
			char _letter_;
			cin >> _letter_;
			if (_letter_ == 'a')
			{
				cout << "Please, enter IBAN: ";
				MyString _iban;
				cin >> _iban;
				cout << "Please, enter the amount of money to withdraw: ";
				double _sum;
				cin >> _sum;
				if (bank.withdraw(_iban, _sum))
				{
					cout << "Successfully withdrawn money!" << endl << endl;
				}
				else
				{
					cout << "You cannot withdraw money from this account!" << endl << endl;
				}
			}
			else if (_letter_ == 'b')
			{
				cout << "Please, enter IBAN: ";
				MyString _Iban;
				cin >> _Iban;
				cout << "Please, enter the amount of money to deposit: ";
				double _Sum;
				cin >> _Sum;
				if (bank.deposit(_Iban, _Sum))
				{
					cout << "Successfully deposited money!" << endl << endl;
				}
				else
				{
					cout << "Trere is not such an account!" << endl << endl;
				}
			}
			else if (_letter_ == 'c')
			{
				cout << "Please, enter the sum you want to transfer: ";
				double _amount;
				cin >> _amount;
				cout << "Please, enter from which IBAN to transfer the sum: ";
				MyString fromIban;
				cin >> fromIban;
				cout << "Please, enter to which IBAN to transfer the sum: ";
				MyString toIban;
				cin >> toIban;
				if (bank.transfer(_amount, fromIban, toIban))
				{
					cout << "Successfully transfered money!" << endl << endl;
				}
				else
				{
					cout << "Money failed to transfer!" << endl << endl;
				}
			}
			else
			{
				cout << "Invalid letter (please, follow the menu above)!!" << endl << endl;
			}
			break;
		case 4:
			cout << endl;
			cout << "Here is the bank information:" << endl;
			bank.display();
			cout << endl;
			break;
		case 5:
			cout << "Qiut!";
			toLoop = false;
			break;
		default: cout << "Invalid number(follow the menu above)" << endl;
		}
	}
}
