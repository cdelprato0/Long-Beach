//Chaz Del Prato
//Quick Sort and Merge Sort in C
#include <stdio.h>

//-----------------------------
//QUICK Sort
//-----------------------------

//swaps the integer elements 
void swapVals(int *valueA, int *valueB){
  //creates temp variable to hold value of a
  int t = *valueA;
  //sets b equal to a
  *valueA = *valueB;
  //stores a inside of b
  *valueB = t;
}

void qsort2(int *a, int n){

  //if the size of the array is one, then it will return because
  //an array with one element is already sorted.
  if(n < 2){
    return;
  }
  //calculates the pivot point by taking value at half the index in the list
  int pivot = a[n/2];

  //sets a reference pointer to the front of the list, looks at first value
  int *first = a;

  //sets a reference pointer to the end of the list, looks at last value
  int *last = a + n - 1;

  //while the first element is less than or equal to the right element. increasing order
  while (first <= last){
    //if the first element is less than the pivot
    if(*first < pivot){
      //it then increments the pointer to the next element
      first++;
    }
    //if the last element is greater than the pivot
    else if (*last > pivot){
      //moves the last element pointer to the next element to the left
      last--;
    }
    //when the either of the pointers are not true to the above statements, it will swap the elements that the two pointers are looking at and continue onto the next one
    else{
      swapVals(first, last);
      first++;
      last--;
    }
  }
  
  //recursivly calls qsort on the list until it is sorted completely
  qsort2(a, last - a + 1);  //takes in the initial list, and the new size of the list after it has sorted some of its values
  qsort2(first, a + n - first);
}

//prints the list
void printSort(int *a, int n){
  //outputs to console the entire list
  for(int i = 0; i < n; i++){
    //prints out the number of each index in the list
    printf("%d", a[i]);
    //adds a comma
    printf(", ");
  }
}

//-----------------------------
//MERGE Sort
//-----------------------------

void merge(int *a, int left, int pivot, int right){

  //calculates the size of the left side of the pivot
  int size1 = pivot - left + 1;
  //calculates the size of the right side of the pivot
  int size2 = right - pivot;

  //need temp lists to copy into
  int leftList[size1];
  int rightList[size2];

  //sets the elements in the left side of the list to the first temp list
  for(int index = 0; index < size1; index++){
    leftList[index] = a[left + index];
  }
  //sets the elements in the right side of the list to the second temp list
  for(int index = 0; index < size2; index++){
    rightList[index] = a[pivot + 1 + index];
  }

  //sets the left lists index to zero
  int leftIndex = 0;
   //sets the right lists index to zero
  int rightIndex = 0;
   //sets the merged lists index to one
  int mergedIndex = left;

  //while the left index is less than the size of the left list and the right index is less than the size of the right list
  while(leftIndex < size1 && rightIndex < size2){
    //if the left element is less than or equal to the right element
    if(leftList[leftIndex] <= rightList[rightIndex]){
      //the left element gets saved into the merged list, (the smallest value for this index)
      a[mergedIndex] = leftList[leftIndex];
      //increments the left and merged index
      leftIndex++;
      
    }else{
      //if the right element is smaller, then it will save the right element at the merged index
      a[mergedIndex] = rightList[rightIndex];
      rightIndex++;
      
    }
    mergedIndex++;
  }

  //fills the rest of the merged list with the left list
  while(leftIndex < size1){
    a[mergedIndex] = leftList[leftIndex];
    leftIndex++;
    mergedIndex++;
  }
  //fills the rest of the merged list with the right list so that this function can be called again
  while(rightIndex < size2){
    a[mergedIndex] = rightList[rightIndex];
    rightIndex++;
    mergedIndex++;
  }
}

//merge sort with an array being passed in, the first index, and last index
void msort(int *a, int firstIndex, int lastIndex){
  // if the first index of the array is less then the last index of the array
  if (firstIndex < lastIndex)
	{
    //finds the pivot point by adding the first index
    //plus the last index -1 since we are looking at indexes that start at zero. then half it
		int pivot = (firstIndex + (lastIndex - 1)) / 2;

    //recursivly calls the first half of the orginial list
    //goes from the first index to the pivot
		msort(a, firstIndex, pivot);
    //calls the second half of the orginial list from the pivot plus one to the last index
		msort(a, pivot + 1, lastIndex);

    //calls my merge method that merges the two smaller list into one
		merge(a, firstIndex, pivot, lastIndex);
	}

  //my attempt at using the parameters provided for this assignment. was not able to get working
  // void msort(int *a, int n){
  
  // if(n < 2){
  //   return;
  // }
  // int *leftIndex = a;
  // int *rightIndex = a + n - 1;
  // int size1 = n / 2;
  // int size2 = n - size1;

  //  //need temp lists to copy into
  // int leftList[size1];
  // int rightList[size2];

  // for(int i = 0; i < size1; i++){
  //   leftList[i] = a[i];
  // }
  // for(int i = 0; i < size2; i++){
  //   rightList[i] = a[i];
  // }

  // if (leftIndex < rightIndex)
	// {
  //   int *pivot = leftIndex+(rightIndex-leftIndex)/2;

	// 	msort(leftList, *pivot);
	// 	msort(rightList, *rightIndex);

	// 	merge(a, 0, n/2, leftIndex - a + 1);
	// }
}

int main(void) {
  
  int n = 10;
  int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};

  qsort2(a, n);
  printSort(a, n);
  printf("\n");
  
  int b[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  msort(b, 0, n-1);
  printSort(b, n);


  return 0;
}