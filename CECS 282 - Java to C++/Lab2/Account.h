#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
public:
	//Constructors
	Account();
	Account(double b);
	
	//Deposits money into the account balance
	void deposit(double a);
	
	//Withdraws money from the account balance
	void withdraw(double w);
	
	//Calculates how many months it will take to double investment
	int calculateInterest(double interest, double initial);
	
	//Displays the balance of the account
	double getBalance();
	

private:
	double balance;	//holds the amount of money for the account
	
};

#endif /* ACCOUNT_H_ */

