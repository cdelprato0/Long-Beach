/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :017844266
 * LAB 2        :Account, Account with interest, Bank and Account
 * CLASS	    :CECS 282
 * SECTION	    :T/Th 8:00 AM
 *************************************************************************/
#include "Account.h"
#include "Bank.h"



int main(){
/********************************************************************************************
*	Problem 1
*	---------
*	Implement a class Account. An account has a balance, functions to add and withdraw money,
* 	and a function to query the current balance. Charge $20 penalty if an attempt is made to 
*	withdraw more money than available in the account.
*********************************************************************************************/
	cout << "Problem 1: Deposit/Withdraw\n" 
         << "---------------------------\n";
         
   Account my_account(100);     // Set up my account with $100
   my_account.deposit(50);		//Deposits monet into the account
   my_account.withdraw(175);   // Penalty of $20 will apply
   my_account.withdraw(25);

	//Calls the getBalance function in account
   cout << "Account balance: " << my_account.getBalance() << "\n";
  
   my_account.withdraw(my_account.getBalance());  // withdraw all
   cout << "Account balance: " << my_account.getBalance() << "\n";
   
   
/********************************************************************************************
*	Problem 2
*	---------
*	Enhance the Account class to compute the interest on the current balance. An account 
*	has initial balance of $10,000.00, and 6% percent annual interest is compounded monthly 
*	until  the investement is double.
*	Write a main function to determine the number of months to double the initial investment. 
*	Create a menu to allow the user to enter the initial investement and the annual interest rate.
*********************************************************************************************/
	cout << "\nProblem 2: Investment/Annual Interest\n" 
         << "-------------------------------------\n";
         
	Account myAccount(0);	//Initializes an account
	double investment = 0;	//used to save value of user inputs
	double interest = 0;
	int months = 0;			//Will be used to show how many months it takes
	
	//Prompts user for their initial investment and reads in from the keyboard
	cout << "\nEnter your initial investment: $";
	cin >> investment;
	cin.ignore(1000, '\n');
	
	//Prompts user to enter the annual interest rate
	cout << "Enter the annual interest: %";
	cin >> interest;
	
	//Calculates how many months it will take to double the investment
	months = myAccount.calculateInterest(interest, investment);
	
	//Displays how many months it took
	cout << fixed << setprecision(2) 
		 << "\nIt would take " << months << " months to double the intital investment of $" << investment << endl; 
		 
		 
/********************************************************************************************
*	Problem 3
*	---------
*	Implement a class Bank. This bank has two objects, checking and savings of type Account that was 
*	developed in the problem 2. Implement four member functions:
*     deposit(double amount, string account)
*     withdraw(double amount, string account)
*     transfer(double amount, string account)
*     print_balance()	
*********************************************************************************************/
	cout << "\nProblem 3: Deposit/Withdraw/Transfer with Bank\n" 
         << "----------------------------------------------\n";	 
	Bank my_bank;	//Creates a new bank object
	
	cout << "Inital bank balances: \n";
	my_bank.print_balances(); /* set up empty accounts */
	
	cout << "Adding some money to accounts: \n";
	my_bank.deposit(1000, "S"); /* deposit $1000 to savings */
	my_bank.deposit(2000, "C"); /* deposit $2000 to checking */
	my_bank.print_balances();
	
	cout << "Taking out $1500 from checking,and moving $200 from";
	cout << " savings to checking.\n";
	my_bank.withdraw(1500, "C"); /* withdraw $1500 from checking */
	my_bank.transfer(200, "S"); /* transfer $200 from savings */
	my_bank.print_balances();
	
	cout << "Trying to transfer $900 from Checking.\n";
	my_bank.transfer(900,"C");
	my_bank.print_balances();
	
	cout << "trying to transfer $900 from Savings.\n";
	my_bank.transfer(900,"S");
	my_bank.print_balances();
   
   return 0;   
}
