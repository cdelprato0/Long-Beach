//Assignment 3 c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//creates a struct
struct Person{
  string name;
  int age;
};
//sets a type definition to structs, trying to keep it generic
typedef Person structs;

//create a template class of T
template<class T>
class GenericArray{

  //the content of a generic type of the array
  T *content;
  //size of array
  int size;
  
  public:
    //constructor takes in an array and size
    GenericArray(T contents[], int s){
      //sets the size and the contents of the array
      size = s;
      content = new T[size];
      for(int i = 0; i < size; i++){
        content[i] = contents[i];
      }
    }
    
    //this can print any type except the struct
    void printArray(){
      for(int i = 0; i < size; i++){
        cout << content[i] << "\n";
      }
    }
    //prints out the values for a struct
    void printStruct(){
      for(int i = 0; i < size; i++){
        //points to reference of a person's content at the current index
        cout << (*((Person*)content + i)).name << "\t" << (*((Person*)content + i)).age << "\n";
      }
    }
    //sorts and outp[uts the sorted array
    void sortArray(){
      cout << "Numbers:\n";
      printArray();
      //calls std sort
      sort(content, content+size);
      cout << "\nNumbers Sorted: \n";
      printArray();
    }
    //used for comparing the data in the struct
    //will get the sorted names
    static int compareName(structs const& a, structs const& b){
      if(a.name == b.name){
        return a.age < b.age;
      }
      return a.name < b.name;
    }
    //used for comparing the data in the struct
    //will get the sorted ages in decending order
    static int compareAge(structs const& a, structs const& b){
      if(a.age == b.age){
        return a.name < b.name;
      }
      return a.age > b.age;
    }
    
    //sorts and outputs the structs
    void sortStruct(){
      cout << "\nPeople:\n";
      printStruct();
      //uses the std sort and gives the compare function
      sort(content, content+size, compareName);
      cout << "\nSorted by People's Name:\n";
      printStruct();
      sort(content, content+size, compareAge);
      cout << "\nSorted by People's Age:\n";
      printStruct();
    }
    
};

int main() {
  float fContent[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
  int size = sizeof(fContent) / sizeof(fContent[0]);
  GenericArray<float> numbers(fContent, size);

  numbers.sortArray();

  Person pContent[] = {{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25} };
  int peopleSize = sizeof(pContent)/ sizeof(pContent[0]);
  GenericArray<Person> people(pContent, peopleSize);

  people.sortStruct();

  return 0;

}