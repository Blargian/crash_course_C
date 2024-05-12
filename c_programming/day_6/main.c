#include <stdio.h>
#include <stdlib.h>

// This program will add two numbers and return the result to us
int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Program terminated. Expected two arguments but received %d arguments instead \n",argc-1);
		return 0;
	}

	int firstArgument = atoi(argv[1]);
	int secondArgument = atoi(argv[2]);
	int result = firstArgument + secondArgument;

	printf("%d + %d = %d\n", firstArgument, secondArgument, result);
	return 0;
}
