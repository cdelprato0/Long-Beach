#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"
using namespace std;

class Bank {
	
public:
	//Constructor
	Bank();
	
	//Deposits into the given account
	void deposit(double amount, string account);
	
	//Withdraws from the given account
	void withdraw(double amount, string account);
	
	//Transfers from the given account to the other
	void transfer(double amount, string account);
	
	//Displays the balances of the accounts
	void print_balances();
	

private:
	Account checkings;	//Creates a new account objects
	Account savings;	
	
};

#endif /* BANK_H_ */

