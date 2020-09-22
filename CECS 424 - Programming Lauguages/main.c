#include <stdio.h>
#include <string.h>

//create a struct and then sets the type definition to structs.
//will call structs instead of person
typedef struct Person{
  char* name;
  int age;
}structs;

//hold the enmu types of data types
enum Types{
  INT,
  DOUBLE,
  STRING,
  STRUCT_VAR1,
  STRUCT_VAR2
};
//global variable to help get correct sorting algor
int type;

//prints out an array of any type
void printArray(void* a, int size){
  if(type == DOUBLE){
    for(int i = 0; i < size; i++){
      printf("%.2f", *((double*)a + i));
      printf("\n");
    }
  }
  if(type == STRUCT_VAR1 || type == STRUCT_VAR2){
    structs* structArray = (structs*)a;
    for(int i = 0; i < size; i++){
      printf("%s\t%d", structArray->name, structArray->age);
      structArray = ((structs*)structArray + 1);
      printf("\n");
    }
  }
}

//compare functions that will be used with the std sort
int compareFunction(const void* a, const void* b){
  //if the type is a number
  if(type == DOUBLE){
    return (*(double*)a) - (*(double*)b);
  }
  //if you are sorting by the first value in a struct
  if(type == STRUCT_VAR1){
    structs* structA = (structs*)a;
    structs* structB = (structs*)b;

    if(strcmp(structA->name, structB->name) == 0){
      return structA->age - structB->age;
    }
    return strcmp(structA->name, structB->name);
  }
  //if you are sorting by the second value in a struct
  if(type == STRUCT_VAR2){
    structs* structA = (structs*)a;
    structs* structB = (structs*)b;

    if((structA->age - structB->age) == 0){
      return strcmp(structA->name, structB->name);
    }
    return (structB->age - structA->age);
  }
}

int main(void){
  double numbers[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
  //gets the size of the array
  int doubleSize = sizeof(numbers) / sizeof(numbers[0]);
  type = DOUBLE;

  printf("Numbers:\n");
  printArray(numbers, doubleSize);
  //calls std qsort with the compare function
  qsort(numbers, doubleSize, sizeof(double), compareFunction);
  printf("\nSorted Numbers:\n");
  printArray(numbers, doubleSize);

  structs people[] = {{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25} };
  int peopleSize = sizeof(people)/ sizeof(people[0]);

  type = STRUCT_VAR1;
  printf("\nPeople:\n");
  printArray(people, peopleSize);
  qsort(people, peopleSize, sizeof(structs), compareFunction);
  printf("\nPeople Sorted by Name:\n");
  printArray(people, peopleSize);

  type = STRUCT_VAR2;
  qsort(people, peopleSize, sizeof(structs), compareFunction);
  printf("\nPeople Sorted by Age:\n");
  printArray(people, peopleSize);
  return 0;
}