#include "Account.h"
//Constructor
Account::Account(){
	balance = 0;
}

//Constructor that passes in a variable
Account::Account(double b){
	balance = b;
}

//This function will take in an amount of money and add it to the balance on the account.
void Account::deposit(double a){
	balance = balance + a;
}

//This function will withdraw the amount given out of the balance. There will
//display an error message if the user tries to withdraw more than what is in 
//tha account.
void Account::withdraw(double w){
	//Checks to see if the balance is less than the amount
	if(balance < w){
		balance = balance - 20;
		cout << "A $20 overdraft fee has been charged!\n";
	}else{
		balance = balance - w;
	}
}

//This function will calculate the time it takes for an investment to double given the annual interest percent.
//The interest and investment are user inputs.
//It will return the number of months
int Account::calculateInterest(double interest, double initial){
	//Doubles the initial investment
	double doubleInvestment = initial * 2;
	//Determines the monthly interest rate
	double monthlyInterest = (interest/100) / 12;
	//sets the number of months to 0
	int months = 0;
	
	//Will check until the initial investment is less than double the investment.
	//It will also add the monthly interest to the investment
	while(initial < doubleInvestment){
		initial += initial * monthlyInterest;
		months++;
	}
	return months;
}

//Will return the balance on the account
double Account::getBalance(){
	return balance;
}
