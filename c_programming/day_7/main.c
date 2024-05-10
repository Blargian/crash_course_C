#include <stdio.h>

void printArray(int param[], size_t size)
{
	for (int i=0; i<size; i++)
	{
		printf("%d\n", param[i]);
	}
}

int main(int argc, char** argv)
{

	// setting up an array
    int array[7];
    for (int i=0; i<7; i++)
    {
        array[i] = i;
    }
	
	// looping through an array with [] syntax
    for (int i=0; i<7; i++)
    {
        printf("%d\n", array[i]);
    }
	
	printf("%ld\n", sizeof(array)); //24 bytes

	// create a pointer that points to the start of an array (two ways)
	int* p_array = array;
	// int* p_array = &array[0];
	
	// Loop through a pointer
	for (int i=0; i<7; i++)
	{
		printf("%d\n", p_array[i]);
	}

	// Printing the size of our p_array
	printf("p_array: %ld\n", sizeof(p_array)); //8 bytes

	// something unexpected using the function above which takes parameter (int array[])
	printArray(p_array, size_of(array)); //N.B arrays passed to functions decay to pointers

	return 0;
}

