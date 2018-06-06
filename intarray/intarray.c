/*
  creates an array, fills via user input, sorts array, and prints and frees memory. 3-1.
  */

#include<stdio.h>

struct IntArray
{
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length);
void readIntArray(struct IntArray *array);
void swap(int *xp, int *yp);
void sortIntArray(struct IntArray *array);
void printIntArray(struct IntArray *array);

struct IntArray* mallocIntArray(int length)
{
	struct IntArray* newIntArray;
	newIntArray = (struct IntArray *)(malloc(sizeof(struct IntArray)));
	newIntArray->dataPtr = (int *)(malloc(sizeof(int) * length));
	newIntArray->length = length;
	return newIntArray;
}

//sets the values into the dataPtr of struct IntArray
void readIntArray(struct IntArray *array)
{
	int i = 0;
	
	//loop from 0 to array's length(dataPtr length)
	for(i = 0; i < array->length; i++)
	{
		printf("Enter int: ");

		scanf("%d", &array->dataPtr[i]);
	}
}

//swap function to swap xp and yp
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//sort array vals in ascending order w/ bubble sort
void sortIntArray(struct IntArray *array)
{

	int i = 0;
	int j = 0;

	for(i = 0; i < array->length - 1; i++)
	{
		for(j = 0; j < array->length - i - 1; j++)
		{
			if(array->dataPtr[j] > array->dataPtr[j + 1])
			{
				swap(&array->dataPtr[j], &array->dataPtr[j + 1]);				
			}
		}
	}
}

void printIntArray(struct IntArray *array)
{

	int i = 0;

	for(i = 0; i < array->length; i++)
	{

		if(i == 0)
			printf("[%d, ", array->dataPtr[i]);
		else if(i < array->length - 1)
			printf("%d, ", array->dataPtr[i]);
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
	struct IntArray* newArray;

	int length;

	printf("Enter length: ");

	scanf("%d", &length);

	newArray = mallocIntArray(length);
	
	readIntArray(newArray);
	
	sortIntArray(newArray);

	printIntArray(newArray);

	getchar();
	getchar();
	return 0;
}

