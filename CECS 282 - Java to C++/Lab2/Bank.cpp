#include "Bank.h"

//Constructor
Bank::Bank(){
	
}

//This function will take in the amount and the 
//string of the account the user wants to use. It will determine 
//which account to deposit into and will deposit. it will display 
//an error if the account doesnt exist.
void Bank::deposit(double amount, string account){
	//Checks the string to see which account
	if(account == "S"){
		savings.deposit(amount);
	}
	else if(account == "C"){
		checkings.deposit(amount);
	}
	else{
		cout << "That account does NOT exist";
	}
}

//This function will take in the amount and the string of the 
//account the user wants to use. It will determine which account 
//the user wants to withdraw money from and will do so. It will 
//display an error if the account doesnt exist.
void Bank::withdraw(double amount, string account){
	//Checks to see which account the user wants access to
	if(account == "S"){
		savings.withdraw(amount);
	}
	else if(account == "C"){
		checkings.withdraw(amount);
	}
	else{
		cout << "That account does NOT exist";
	}
}

//This function will take in the amount and the string of the 
//account the user wants to use. It will determine which account 
//the user wants to transfer money from. With the given account, 
//it will take out of the given account and attemp to transfer 
//the money in to the other account. If the amount is higher 
//than the account balance, it will not transfer and display an 
//error. If the account doesnt exist it wil display an error.
void Bank::transfer(double amount, string account){
	//Checks to see what account the user wants to access
	if(account == "S"){
		//Checks to see if the balance of the account is higher than the amount
		if(savings.getBalance() > amount){
			checkings.deposit(amount);
			savings.withdraw(amount);
		}
		else{
			cout << "There is not enough money in the Savings account to transfer...\n";
		}
	}
	else if(account == "C"){
		//Checks to see if the balance of the account is higher than the amount
		if(checkings.getBalance() > amount){
			savings.deposit(amount);
			checkings.withdraw(amount);
		}
		else{
			cout << "There is not enough money in the Checkings account to transfer...\n";
		}
		
	}
	else{
		cout << "That account does NOT exist";
	}
}

//This function will display to the console both the checkings and saving balances.
void Bank::print_balances(){
	cout << "\nCheckings Account\n"
		 << "-----------------\n"
		 << "   $" << checkings.getBalance() << endl;
	cout << "Savings Account\n"
		 << "-----------------\n"
		 << "   $" << savings.getBalance() << endl << endl;
}
