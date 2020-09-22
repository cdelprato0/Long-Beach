//Chaz Del Prato
//Assignment 2
//Dynamic Heap
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//creates a Block
struct Block{
	//the # of bytes in the data section
	int block_size;
	//pointer to the next block
	struct Block *next_block;
};

//size of the block
const int OVERHEAD_SIZE = sizeof(struct Block);
//size of the void pointer
const int VOIDPTR_SIZE = sizeof(void*);
//will always point to the first free block in the free heap.
struct Block *free_head;

//initializes my heap
void my_initialize_heap(int size){
	
	//initializes a buffer of the given size
	free_head = malloc(size);
	
	//sets the size of the block by using the given size minus the overhead 
	//size of the block
	free_head->block_size = size - OVERHEAD_SIZE;
	
	//Since the heap is being initialized, the head will be loocking at null.
	free_head->next_block = NULL;
}

//Calculates the multiple value of the void pointer
int sizeMultiple(int size){
	
	//call the math ceil function, which rounds up to the nearest whole number
	//inside ceil it will calculate the size that is passed in and divide it by
	//the void pointer.
	double doubleSize = ceil((double)size / (double)VOIDPTR_SIZE);
	
	//returns the multiple of the void pointer
	return (int)(doubleSize * VOIDPTR_SIZE);
	
}

//My memory allocation method
void* my_malloc(int size){
	//Calculates the multiple of the given size
	int newSize = sizeMultiple(size);
	//creates a new pointer to the current block, its free head because we have
	//to start from the head of the free heap
	struct Block *currentPtr = free_head;
	//keeps track of the previous block
  	struct Block *prevBlk = NULL;
	
	//while there is free space
	while(currentPtr){
		//if the new multiple size of the void ptr is less than or equal to the
		//current free block
		if(newSize <= currentPtr->block_size){
			//calculates the overflow to see if the extra space could support 
			//another block
			int overflow = currentPtr->block_size - newSize;
			
			//if the overflow is big enough, then we can split the block and get 
			//another free block out of it
			if(overflow >= (OVERHEAD_SIZE + VOIDPTR_SIZE)){
				//splits the current free block into the size that is needed
        		currentPtr->block_size = newSize;
        		//creates a new block that splits and is initialized based on
        		//the overflow and the remaining space of the current free block
        		//basically creates a new free block with the left over space
				struct Block *splitBlk = (struct Block *)((char*)currentPtr + newSize + OVERHEAD_SIZE);
				//sets the new free block to the size that is left over
				splitBlk->block_size = overflow;
				
				//if the current block happens to be the head
		    	if(currentPtr == free_head){
		    		//then the new split block will become the free head
		          	free_head = splitBlk;
		        }else{
		        	//else the new split block will insert itself into the location
		        	//of the current free block
		        	//the split block is now pointing to the block after the 
		        	//current free block
		          	splitBlk->next_block = currentPtr->next_block;
		          	//the block before the current freed block is now pointing
		          	//to the new split blk
		          	prevBlk->next_block = splitBlk;
		        }
			//else splitting cannot happen
			}else{
				//if the current free block is equal to the head
		        if(currentPtr == free_head){
		        	//then it will set the current block to the head of the list
		          	free_head = currentPtr->next_block;
		        }else{
		        	//else it will remove the current block and set its previous
		        	//block to the block after it
		          	prevBlk->next_block = currentPtr->next_block;
		        }
		        //sets the null to the current blocks next block
				currentPtr->next_block = NULL;
				
			}
			//returns the currentb block pointing to the next block
      		return currentPtr + 1;
		}else{ //if the data does not fit in the current block, then it will look for the next free block
      		//the current block is now set to the back
			prevBlk = currentPtr;
			//and the new current block is the next block
      		currentPtr = currentPtr->next_block;
    	}
	}
	//returns null if there is no space available
  	return NULL;
}

//deallocates a value that was allocated on the data heap
void my_free(void *data){
	//creates a temp pointer that has the data portion of a block that is pointing
	//to the offset
	struct Block *tempPtr = ((struct Block *)data - 1);
	//the head is now connected to the temp pointers next block
	tempPtr->next_block = free_head;
	//and the temp pointer is the head
	free_head = tempPtr;
}


//calculates the standard deviation
double calcSTDDev(int *intArray, int size){
	//calc the mean of the array
	double mean = 0;
	//accumulating sum of the array contents
	double sum = 0;
	//standard deviation value
	double stdDev = 0;
	//summation
	double sigma = 0;
	
	int i;
	//adds the sum of each element in the array
	for(i = 0; i < size; i++){
		sum += intArray[i];
	}
	
	//divide the total sum over the size of the array
	mean = sum / (double)size;
	
	int j;
	//the summation of the value in the array minus the mean
	//times itself to make it squared
	for(j = 0; j < size; j++){
		sigma += (intArray[j] - mean)*(intArray[j] - mean);
	}
	
	//calculates the square root of the summation over n
	stdDev = sqrt(sigma / (double)size);
	
	return stdDev;
}


//Test cases and standard devation
int main() {
	
/*	//initializes my heap with the size of 7777
	my_initialize_heap(7777);

//TEST 1
	printf( "TEST CASE 1:\n" );
	int *test11 = my_malloc(sizeof(int));
	printf( "The address in hex: 0x%X and in decimal: %d \n", test11, test11);
	my_free(test11);
	
	int *test12 = my_malloc(sizeof(int));
	printf( "The address in hex: 0x%X and in decimal: %d AFTER free \n", test12, test12);

//TEST 2
	printf( "\nTEST CASE 2:\n" );
	int *test21 = my_malloc(sizeof(int));
	int *test22 = my_malloc(sizeof(int));
	printf("The address in hex: 0x%X and in decimal: %d \n", test21, test21);
	printf("The address in hex: 0x%X and in decimal: %d \n", test22, test22);
	printf("The SUM of the overhead and void pointer in decimal: %d \n", OVERHEAD_SIZE + VOIDPTR_SIZE);

//TEST 3
	printf( "\nTEST CASE 3:\n" );
	int *test31= my_malloc(sizeof(int));
	int *test32 = my_malloc(sizeof(int));
	int *test33 = my_malloc(sizeof(int));
	printf("The address in hex: 0x%X and in decimal: %d \n", test31, test31);
	printf("The address in hex: 0x%X and in decimal: %d \n", test32, test32);
	printf("The address in hex: 0x%X and in decimal: %d \n", test33, test33);
	
	my_free(test32);
	
	double *test34 = my_malloc(sizeof(double));
	printf("The address of the double in hex: 0x%X and in decimal: %d AFTER free \n", test34, test34);

//TEST 4
	printf( "\nTEST CASE 4:\n" );
	char *test41 = my_malloc(sizeof(char));
	int *test42 = my_malloc(sizeof(int));
	
	printf("The address of the char in hex: 0x%X and in decimal: %d \n", test41, test41);
	printf("The address of the int in hex: 0x%X and in decimal: %d \n", test42, test42);

//TEST 5
	printf( "\nTEST CASE 5:\n" );
	int *intArray = my_malloc(100*sizeof(int));
	int *intValue = my_malloc(sizeof(int));
	*intValue = 75;
	printf("The address of the array in hex: 0x%X and in decimal: %d \n", intArray, intArray);
	printf("The address of the int value in hex: 0x%X and in decimal: %d and the actual value: %d\n", intValue, intValue, *intValue);
	my_free(intArray);
	
	printf("The address of the int value in hex: 0x%X and in decimal: %d and the actual value AFTER free: %d\n", intValue, intValue, *intValue);
	*/
//Standard Deviation Problem

	//initializes my heap with the size of 7777
	my_initialize_heap(7777);
	
	//user input of size of the array
	int size = 0;
	//standard deviation
	double sd = 0.0;
	//user input of values in array
	int valueInput = 0;
	
	//prompts user to enter in the size of the array and reads input
	printf("Enter a positive number: ");
	scanf("%d", &size);
	
	//initializes and allocates the space needed for the array in our heap
	int *stdDev = my_malloc(size * sizeof(int));
	
	//fills in all the values of the array
	int i;
	for(i = 0; i < size; i++){
		printf("Enter in a value: ");
		scanf("%d", &valueInput);
		stdDev[i] = valueInput;
	}
	
	//calls the standard deviation calculation
	sd = calcSTDDev(stdDev, size);
	
	//prints the standard deviation
	printf("Standard Deivation: %f", sd);

	return 0;
}
