//Chaz Del Prato
// CECS 282 LAB 3 - Problem 1+2

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Function declarations
int readData( int *);
void bsort(int *, int);
void writeToConsole(int *, int);
void bSortD(int *, int);
void bubble_sort(int *, int, void (*)(int *, int));

int main() {
	
	/**************
	*  PROBLEM 1  *
	**************/
	//Write a program for sorting a list of integers in ascending order using the 
	//bubble sort algorithm.
	cout << "*****************\n"
		 << "*   Problem 1   *\n"
		 << "*****************\n";
	ifstream inFirstLine;	//used to read in file
	int arrySize = 0;		//used to determine size
	
	//opens input file and reads the first data inside and then closes
	inFirstLine.open("data.txt");	
	inFirstLine >> arrySize;
	inFirstLine.close();
	
	int *numbers = new int[arrySize];	//creates a new array pointer
	
	//Dynamic input array of n integer elements
	readData(numbers);
	
	//Calls the bubble sort function and sorts the data in ascending order
	//passes in array pointer and size
	bsort(numbers, arrySize);
	
	//Prints out the array
	writeToConsole(numbers, arrySize);
	
	//deletes the point array in memory
	delete[] numbers;
	
	/**************
	*  PROBLEM 2  *
	**************/
	//Reimpelment a function called bubble_sort that has the following prototype.
	//bubble_sort(int *array, int size,  pointer to a function)
	//Pre condition
	//array - a pointer to a an array of size element.
	//pointer to function - a pointer to a function that compares two values (depending on sorting in ascending order or descending order)
	//Post condition
	//Sort the array in ascending or descending based on the the pointer to a function.	
	cout << "\n*****************\n"
	 	 << "*   Problem 2   *\n"
	 	 << "*****************\n";
	ifstream inFirst;	//used to read in file
	int arraySize = 0;	//used to determine size
	
	//opens input file and reads the first data inside and then closes
	inFirst.open("data.txt");
	inFirst >> arraySize;
	inFirst.close();
	
	int *number = new int[arraySize];	//creates a new array pointer
	
	//Dynamic input array of n integer elements
	readData(number);	
	
	//Call the function bubble_sort to sort the array in ascending
	//Display the sorting array.
	cout << "Ascending Order:\n";
	bubble_sort(number, arraySize, bsort);	
	writeToConsole(number, arraySize);
	
	//Call the function bubble_sort to sort the array in descending
	//Display the sorting array.
	cout << "Decending Order:\n";
	bubble_sort(number, arraySize, bSortD);
	writeToConsole(number, arraySize);
	
	return 0;
}

//arr is a pointer for storing the integers. The function returns the number of integers.
//The function readData reads the list of integers from a file call data.txt into the 
//array arr. The first integer number in the file is the number of intergers. After the 
//first number, the file lists the integers line by line.
int readData( int *arr){
	ifstream inFile;	//used to use the file
	int count = 0;		//used to skip first val
	int arrySize = 0;	//fetertmines the size of input
	
	inFile.open("data.txt");	//opens file
	
	//Checks to see if the file and data and will read in all the data except the first data
	while(inFile){
		if(count == 0){
			inFile >> arrySize;
		}
		else{
			inFile >> *(arr + (count - 1));	
					
		}
		count++;
	}
	
	inFile.close();		//closes file
	return arrySize;	

}

//arr is a pointer to an array of integers to be sorted. last is the number of 
//elements in the array. The function bsort sorts the list of integers in ascending order.
void bsort(int * arr, int last){
	bool swapped = true;
	int j = 0;
	int tmp;
	while (swapped) {
        swapped = false;
        j++;

        for (int i = 0; i < last - j; i++) {
            if (arr[i] > arr[i + 1]) {	//makes it ascending

                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;

                swapped = true;
            }
        } 
    }	
}

//arr is a pointer to an array of integers to be sorted. last is the number of 
//elements in the array. The function bsort sorts the list of integers in Decending order.
void bSortD(int * arr, int last){
	bool swapped = true;
	int j = 0;
	int tmp;
	while (swapped) {
        swapped = false;
        j++;

        for (int i = 0; i < last - j; i++) {
            if (arr[i] < arr[i + 1]) {	//makes it desending

                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;

                swapped = true;
            }
        } 
    }	
}

//arr is a pointer to an array of integers. last is the number of elements in the array.
//The function writeToConsole displays the sorted list.
void writeToConsole(int *arr, int last){
	for(int i = 0; i < last; i++){
		cout << *(arr + i) << endl;
	}
}

//bubble_sort(int *array, int size,  pointer to a function)
//Pre condition
//array - a pointer to a an array of size element.
//pointer to function - a pointer to a function that compares two values (depending on sorting in ascending order or descending order)
void bubble_sort(int *arr, int last, void (*op)(int *arr, int last)){
	(*op)(arr, last);
}
