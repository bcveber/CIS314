

#include<stdio.h>

// define IntArray
struct IntArray
{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length);
//void freeIntArray(struct IntArray **arrayPtr);
void readIntArray(struct IntArray *array);
void swap(int *xp, int *yp);
void sortIntArray(struct IntArray *array);
void printIntArray(struct IntArray *array);

//initialize the pointer
struct IntArray* mallocIntArray(int length)
{
	// make the pointer
	struct IntArray* newIntArray;

	// give memory to IntArray
	newIntArray = (struct IntArray *)(malloc(sizeof(struct IntArray)));

	// give memory to dataPtr
	newIntArray->dataPtr = (int *)(malloc(sizeof(int) * length));

	// set the length variable of IntArray to given length val
	newIntArray->length = length;

	// return pointer
	return newIntArray;
}

// sets the values into the dataPtr of struct IntArray
void readIntArray(struct IntArray *array)
{
	int i = 0;
	
	// loop from 0 to array's length(dataPtr length)
	for(i = 0; i < array->length; i++)
	{
		printf("Enter int: ");

		scanf("%d", &array->dataPtr[i]);
	}
}

// swap function to swap xp and yp
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// sort array vals in ascending order w/ bubble sort
void sortIntArray(struct IntArray *array)
{

	int i = 0;
	int j = 0;

	// loop through 0-last but one value
	for(i = 0; i < array->length - 1; i++)
	{
		// loop through 0 to length - i - 1 value
		for(j = 0; j < array->length - i - 1; j++)
		{
			// check whether the j val is greater than j+1 val. if so swap the elements
			if(array->dataPtr[j] > array->dataPtr[j + 1])
			{
				swap(&array->dataPtr[j], &array->dataPtr[j + 1]);				
			}
		}
	}
}

// print vals in array
void printIntArray(struct IntArray *array)
{

	int i = 0;

	// loop through each val in the dataPtr
	for(i = 0; i < array->length; i++)
	{

		// print the first element
		if(i == 0)
			printf("[%d, ", array->dataPtr[i]);

		// condition to print the elements till last but one element
		else if(i < array->length - 1)
			printf("%d, ", array->dataPtr[i]);
		// condition to print the last element
		else
			printf("%d]", array->dataPtr[i]);
	}
	printf("\n");
}

//free the memory given to the array called dataPtr and memory given to the structure pointer
void freeIntArray(struct IntArray **arrayPtr)
{
	free((*arrayPtr)->dataPtr);
	(*arrayPtr)->length = 0;
	free(arrayPtr);
}

int main()
{
	// define a pointer to the struct IntArray
	struct IntArray* newArray;

	int length;

	printf("Enter length: ");

	scanf("%d", &length);

	newArray = mallocIntArray(length);
	
	readIntArray(newArray);
	
	sortIntArray(newArray);

	printIntArray(newArray);

	//freeIntArray(newArray);
	getchar();
	getchar();
	return 0;
}

