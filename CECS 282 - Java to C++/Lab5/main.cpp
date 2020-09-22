//Chaz Del Prato
//CECS - 282 Lab5
#include "Person.h"

void bsort(Person **, int, bool);
void orderName(Person**, Person**);
void orderSalary(Person**, Person**);
void bsortPartTwo(Person **, int, bool);
int main() {
	string name;				//saves the name
	float salary = 0.0;			//saves the salary
	char another;				//saves the choice
	int numPerson = 0;			//saves the number of preople
	Person* personPtr[100];		//creates pointer array
	
	cout << " - PROBLEM 1 - \n\n";
	do{
		//reads user input
		cout << "Enter in the person's name: " << endl;
		getline(cin, name);
		cout << "Enter in the person's salary: " << endl;
		cin >> salary;
		cin.ignore(1000, '\n');
		
		//creates new person and saves the data
		personPtr[numPerson] = new Person();
		personPtr[numPerson]->setPerson(name, salary);
		numPerson++;
		
		//prompts for another person
		cout << "\nWould you like to add another person? (y/n)\n";
		cin >> another;
		cin.ignore(1000, '\n');
		
	}while(another == 'y');
	
	//outputs the unsorted list
	cout << "\nUnsorted List: \n"
		 << "-------------- \n";
	for(int i = 0; i < numPerson; i++){
		cout << "Name: " << personPtr[i]->getName() << endl
			 << "Salary: " << personPtr[i]->getSalary() << endl << endl;
	}
	
	//calls bsort that will sort by name
	bsort(personPtr, numPerson, true);
	
	//prints the sorted list
	cout << "\nSorted by Name List: \n"
		 << "-------------- \n";
	for(int i = 0; i < numPerson; i++){
		cout << "Name: " << personPtr[i]->getName() << endl
			 << "Salary: " << personPtr[i]->getSalary() << endl << endl;
	}	
	
	//calls bsort that will sort by salary
	bsort(personPtr, numPerson, false);
	
	//prints sorted list
	cout << "\nSorted by Salary List: \n"
		 << "-------------- \n";
	for(int i = 0; i < numPerson; i++){
		cout << "Name: " << personPtr[i]->getName() << endl
			 << "Salary: " << personPtr[i]->getSalary() << endl << endl;
	}	
	
	//delete[] personPtr;
	
	
	string name2;				//saves the name
	float salary2 = 0.0;			//saves the salary
	char another2;				//saves the choice
	int numPerson2 = 0;			//saves the number of preople
	Person* personPtr2[100];		//creates pointer array
	
	cout << " - PROBLEM 2 - \n\n";
	do{
		//reads user input
		cout << "Enter in the person's name: " << endl;
		getline(cin, name2);
		cout << "Enter in the person's salary: " << endl;
		cin >> salary2;
		cin.ignore(1000, '\n');
		
		//creates new person and saves the data
		personPtr2[numPerson2] = new Person();
		personPtr2[numPerson2]->setPerson(name2, salary2);
		numPerson2++;
		
		//prompts for another person
		cout << "\nWould you like to add another person? (y/n)\n";
		cin >> another2;
		cin.ignore(1000, '\n');
		
	}while(another2 == 'y');
	
	//outputs the unsorted list
	cout << "\nUnsorted List: \n"
		 << "-------------- \n";
	for(int i = 0; i < numPerson2; i++){
		cout << "Name: " << personPtr2[i]->getName() << endl
			 << "Salary: " << personPtr2[i]->getSalary() << endl << endl;
	}
	
	//calls bsort that will sort by name
	bsortPartTwo(personPtr2, numPerson2, true);
	
	//prints the sorted list
	cout << "\nSorted by Name List: \n"
		 << "-------------- \n";
	for(int i = 0; i < numPerson2; i++){
		cout << "Name: " << personPtr2[i]->getName() << endl
			 << "Salary: " << personPtr2[i]->getSalary() << endl << endl;
	}	
	
	//calls bsort that will sort by salary
	bsortPartTwo(personPtr2, numPerson2, false);
	
	//prints sorted list
	cout << "\nSorted by Salary List: \n"
		 << "-------------- \n";
	for(int i = 0; i < numPerson2; i++){
		cout << "Name: " << personPtr2[i]->getName() << endl
			 << "Salary: " << personPtr2[i]->getSalary() << endl << endl;
	}	
	
//	delete[] personPtr2;
	
	return 0;
}

//sorts the person array and determines to sort by name or salary
void bsort(Person ** pp, int n, bool s){
	int j, k;                      
	for(j=0; j<n-1; j++){
		for(k=j+1; k<n; k++){
			if(s){
				//checks name	
				orderName(pp+j, pp+k);
				
			}else{
				//checks salary
				orderSalary(pp+j, pp+k);
				
			}
		}    
	}         
		       
}

//sorts the person object by name or salary
void bsortPartTwo(Person ** pp, int n, bool s){
	int j, k;                      
	for(j=0; j<n-1; j++){
		for(k=j+1; k<n; k++){
			//checks if the name without the order function
			if(s){
				if((*(pp+j))->getName() > (*(pp+k))->getName() ){
					Person* tempptr = *(pp+j);
					*(pp+j) = *(pp+k);  
					*(pp+k) = tempptr; 					
				}
			//checks if the salary without order function
			}else{
				if((*(pp+j))->getSalary() > (*(pp+k))->getSalary() ){
					Person* tempptr = *(pp+j);
					*(pp+j) = *(pp+k);  
					*(pp+k) = tempptr; 					
				}
			}
		}    
	}         
		       
}

//sorts the person pointers
void orderName(Person** pp1, Person** pp2){
	if((*pp1)->getName() > (*pp2)->getName() ){
	
		Person* tempptr = *pp1;
		*pp1 = *pp2;  
		*pp2 = tempptr;  
	}
	
}
//sorts the person pointers
void orderSalary(Person** pp1, Person** pp2){
	if((*pp1)->getSalary() > (*pp2)->getSalary() ){
		Person* tempptr = *pp1;
		*pp1 = *pp2;  
		*pp2 = tempptr;  
	}
	
}

