#include <ctime>
#include <iostream>
#include "Bank.h"
#include "ProgramMenu.h"
using namespace std;
#pragma warning (disable:4996)

const int MAX_CAPACITY = 1024;


int main()
{
	Bank bank;
	bank.setBankName("Bank of America Corp");
	bank.setBankAddress("100 North Tryon Street, Charlotte, NC 28255");
	menu(bank);

	return 0;
}