#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person {
public:

	Person();
	Person(string n, float s);
	
    void setPerson(string n, float s);
    
    string getName();
    float getSalary();


private:
	string name;
	float salary;
	
};

#endif /* PERSON_H_ */

