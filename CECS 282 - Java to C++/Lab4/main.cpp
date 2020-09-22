//CECS 282 - Chaz Del Prato
//Lab 4
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//function declarations
void transform(char *, char *);
bool testPalindrome(char *);

int main() {
	string input;	//saves user inptu
	
	//Prompts the user for input
	cout << "Enter a string (Enter 0 to exit): \n";
	getline(cin, input);
	
	//Checks to see if the user wants to quit
	while(input != "0"){
		int size = input.length() + 1;	//sets the size of the input
		char *raw = new char[size];		//dynamically creates char array
		char *testStr = new char[size];	//dynamically creates char array for clean string
		
		//copies the contents of the input into the char array
		strcpy(raw, input.c_str());		
		
		//Calls the transform function that will take in the raw data and clean it
		transform(raw, testStr);
		
		//Calls the testPalindrome function to see if it is a palidrome and outputs
		if(testPalindrome(testStr)){
			cout << input << " is a Palindrome!\n\n";
		}
		else{
			cout << input << " is not a Palindrome!\n\n";
		}
		
		//deallocates the memory
		delete[] raw;
		delete[] testStr;
		
		//reprompts the user
		cout << "Enter a string (Enter 0 to exit): \n";
		getline(cin, input);
	}
	return 0;
}

//The function transform converts the given string raw into a standard form by 
//coverting lowercase letters into uppercase letter and removing all characters 
//other than letters and numerals from the string. The converted string will stored 
//in C string testStr.
void transform(char *raw, char *testStr){
	int length = strlen(raw);
	int countTest = 0;
	
	//checks to see if the char is a space or any special char and saves only the letters
	for(int i = 0; i < length; i++){
		if(raw[i] != ' ' && !ispunct(raw[i])){
			testStr[countTest] = raw[i];
			countTest++;
		}
	}
	
	//sets all chars to uppercase
	for(int i = 0; i < countTest; i++){
		testStr[i] = toupper(testStr[i]);
	}
	
	//adds a null terminator at the end of the c string
	testStr[countTest] = '\0';
}


//The function test checks whether the C string str is a palindrome. If the C string 
//str is palindrome, then the function returns true; otherwise, the function returns false.
bool testPalindrome(char *str){
	bool testPalin = true;
	int length = strlen(str) - 1;
	int count = strlen(str) / 2;
	
	//Checks to see if the middle has been reached yet
	if(count > 0){
		//Checks each char element starting from the front and back and making its way to the middle
		for(int i = 0; i < count; i++, length--){
			if(str[i] != str[length]){
				
				testPalin = false;				
			}
		}	
	}
	return testPalin;
}

