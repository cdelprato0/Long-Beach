#include "Person.h"

	Person::Person(){
		
	}
	Person::Person(string n, float s){
		name = n;
		salary = s;
	}
	
    void Person::setPerson(string n, float s){	
    	name = n;
		salary = s;
	}
    
    string Person::getName(){
    	return name;
	}
    float Person::getSalary(){
    	return salary;
	}
