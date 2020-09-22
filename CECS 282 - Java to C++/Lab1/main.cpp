/**************************************************************************
 * AUTHOR	    :Chaz Del Prato
 * STUDENT ID   :017844266
 * LAB 1        :Odd Digits, Factors, Rainfall
 * CLASS	    :CECS 282
 * SECTION	    :T/Th 8:00 AM
 *************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

//Functions declared so main can see them
 void inputRainFall(int[]);
 int calculateAverageRainFall(int[] , int);
 void classifyAndDisplayRainfall(int[] , int);

int main(){
	const int NUM_MONTHS = 12;
	
/**************************************************************************
 * Problem 1
 * ________________________________________________________________________
 * 	Write a program that displays the sum of all odd digits of an input.
 * ex - 43256  3+5=8
 *************************************************************************/
 	int oddInput = 0;	//User input
 	int sum = 0;		//Accumlator for the sum
 	int intArray[20];	//Creates an array with 20 values
 	
 	//Outputs the prompt to console and reads in user input
	cout << "Problem 1: Odd Digits\n" 
         << "---------------------\n"
	 	 << "Enter a number: ";
 	cin >> oddInput;
 	
 	//The for loop will load each digit of the users input into an array.
 	//And then it will check to see if the digit is odd and will add it to 
	//the sum if the digit is odd.
 	for(int i = 20-1; i>0; i--){
 		intArray[i] = oddInput % 10;
 		oddInput = oddInput / 10;
 		
 		if((intArray[i] % 2) != 0){
 			sum = sum + intArray[i];
		 }
	 }
	 //Outputs the sum to the console
	 cout << "The sum of the odd digits is: " << sum << endl << endl;
	 
/**************************************************************************
 * Problem 2
 * ________________________________________________________________________
 * 	Write a program that displays the factors of a specified integer.
 * 20 - 10*2, 20*1, 5*4
 *************************************************************************/
	int factorInput = 0;	//User input for the number to be factored
	int count = 0;			//Used to keep cout of factors
	int factors[15];		//Used to store the factors of the number
	 
	//Outputs the prompt and reads in user input
	cout << "Problem 2: Factors\n" 
	     << "------------------\n"
		 << "Enter a number: ";
	cin >> factorInput;
	
	//Outputs the number to the console
	cout <<  "The factors of " << factorInput << " are: " << endl;
	
	//This will determine if a number is a factor of the user inputted number.
	//If it is a factor of the number it will be saved into the array and 
	//the count will increment.
	for(int i = 1; i <= factorInput; i++){
		
		if((factorInput % i) == 0){
			factors[count] = i;			
			count++;
		 }	
	}
	
	//This will output the factors to the console. The factors will be in pairs 
	//and seperated by newlines
	for(int i = 0; i < 15; i++){
		if(i < count){
			cout << factors[i] << ", " << factors[count - 1] << endl;
		}
		count--;
	}
 	 
 /**************************************************************************
 * Problem 3
 * ________________________________________________________________________
 * 	The Weather Service Bureau department has data representing  monthly 
 * rainfall for a year and we would like to create a table categorizing 
 * each month as rainy (rainfall 20% higher than average) dry (rainfall 
 * 25% lower than average). or average. The data file for monthly rain fall 
 * is called rainfall.txt.
 *
 *************************************************************************/
 	int rainFall[NUM_MONTHS];	//An array to hold in the rainfall from file
 	
 	//Outptus the prompt to the console
 	cout << "\nProblem 3: Monthly Rainfall" << endl
 		 << "---------------------------\n";
 		 
 	//Call the funstion that will input all the data from a file
 	inputRainFall(rainFall);
 	
 	//Will output all the months, rainfall for that month and if the month 
	//was dry, average, or rainy
 	classifyAndDisplayRainfall(rainFall, NUM_MONTHS);

	return 0;
}//End MAIN
 
 /**************************************************************************
 * inputRainFall
 * ________________________________________________________________________
 * 	This function will read in a file called rainfall.txt and save each
 *	number to an array. There is no return type. The array is the only
 * parameter being passed in.
 *
 *************************************************************************/ 
 void inputRainFall(int rainFall[]){
	//Open the file
	ifstream inputFile;
	inputFile.open("rainfall.txt");
	
	//Initialize month counter
	int month = 0; //first month
	
	while(inputFile){
		//Read the monthly rainfall in the file
		inputFile >> rainFall[month];		
		
		month++;	//Increments the number of months	
	}

	//closes the input file
	inputFile.close();
 }
 
  /**************************************************************************
 * calculateAverageRainFall
 * ________________________________________________________________________
 * 	This funtion will take in the current array and the current size of the
 * array and will calculate the average rainfall for the year. Once it
 * determines the rainfall, it will return the average.
 *
 *************************************************************************/ 
int calculateAverageRainFall(int rainFall [], int size){
 	double average = 0;	//creates and initalizes a variable for the average
 	double sum = 0;		//creates and initalizes a varable for the sum
 	
 	//Will add up all the rainfaill in the given year
 	for(int i = 0; i < size; i++){
 		sum += rainFall[i];
	}
	
	//will calculate the average by using the sum divided by the number of months.
	//The ceil function will round up to the nearest mm.
 	average = ceil(sum/size);
 	
 	return average;
 }
 /**************************************************************************
 * classifyAndDisplayRainfall
 * ________________________________________________________________________
 * 	This function will take in the array with the rainfall and how many
 * months the display chart is for. It will call the average function
 * and output all the nesscesay components for the assigment. It will
 * also classify the month with it being dry, average, or rainy
 *
 *************************************************************************/  
void classifyAndDisplayRainfall(int rainFall[], int months){
 	//list of months
 	string monthName[months] = {"January", "February", "March", "April", "May", "June", "July", 
	 "August", "September", "October", "November", "December"};
	 
	 //calls the average function and saves it to a variable
	int yearAvg = calculateAverageRainFall(rainFall, months); 	
	int highestRain = 0;		//used to store the highest rain from input
	int lowestRain;				//used to store the loswest rain from input
	string highestRainMonth;	//used to store the month for the most rainfall
	string lowestRainMonth;		//used to store the moth for the lowest
	
	//Will determine the highest and the lowest rain in the year and save.
	//It will run throught the array that has the rainfall for each month and 
	//determine which month is the highest and the lowest
	for(int i = 0; i < months; i++){
		
		if(highestRain < rainFall[i]){
			highestRain = rainFall[i];
			highestRainMonth = monthName[i];
		}
		
		if(rainFall[i] < lowestRain){
			lowestRain = rainFall[i];
			lowestRainMonth = monthName[i];
		}	
	}
	
	//Outputs the year average fro rain, the highest and lowest months with rain
	cout << "The year's average monthly rainfall was " << yearAvg << " mm." << endl
		 << highestRainMonth << " has the highest rainfall (" << highestRain << " mm)." << endl
		 << lowestRainMonth  << " has the lowest rainfall (" << lowestRain << " mm)." << endl << endl;
	
	//Outptus the title for the rainfall table
	cout << left << setw(12) << "Month" << setw(15) << "Rainfall(mm)" << "Classification" << endl
		 << setw(11) << "------" << setw(16) << "--------------" << "--------------" << endl;
		 
	//Will determine which month can be considered dry, rainy, or average.
	//Dry is 20% below average and rainy is 20% higher than average.
	for(int i = 0; i < months; i++){
		
		cout << right << setw(3) << (i + 1) << setw(16) << rainFall[i];
		
		if((yearAvg - (yearAvg * .2)) > rainFall[i] ){
			cout << setw(18) << "Dry" << endl;
		}
		else if((yearAvg + (yearAvg * .2)) < rainFall[i]){
			cout << setw(18) << "Rainy" << endl;
		}
		else{
			cout << setw(18) << "Average" << endl;
		}
	}
 }
