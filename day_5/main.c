#include <stdio.h>
#include <stdlib.h>

/// Calculates the length of a C-string
size_t StringLength(const char* input)
{
	int length=0;
	while(input[length]!='\0')
	{
		length++;
	}
	return length;
}

char* StringAppend(char* destination, const char* source)
{
	// Compute lengths of input and source
	size_t dstLength = StringLength(destination);
	size_t srcLength = StringLength(source);

	// New buffer for combined string
	char* newString = (char*)malloc(sizeof(char)*(dstLength+srcLength+1));

	int i=0;
	while (i < dstLength)
	{
		newString[i] = destination[i];
		i++;
	}

	int j=0;
	while (j < srcLength)
	{
		newString[dstLength+j] = source[j];
		j++;
	}
	newString[dstLength+srcLength] = '\0';
	
	return newString;
}


int main()
{
	// char hello[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char name[6];
	name[0] = 'S';
	name[1] = 'h';
	name[2] = 'a';
	name[3] = 'u';
	name[4] = 'n';
	name[5] = '\0';

	printf("String: %s\n", name);
	printf("String length: %ld\n\n", StringLength(name));

	char* name_2 = (char*)malloc(sizeof(char)*6);
	name_2[0] = 'S';
	name_2[1] = 'h';
	name_2[2] = 'a';
	name_2[3] = 'u';
	name_2[4] = 'n';
	name_2[5] = '\0';

	printf("String: %s\n", name_2);
	printf("String length: %ld\n\n", StringLength(name_2));
	free(name_2);

	const char* string_literal="hello world";
	printf("String: %s\n", string_literal);
	printf("String length: %ld\n\n", StringLength(string_literal));

	char first[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
	char second[7] = {' ', 'w', 'o', 'r', 'l', 'd', '\0'};
	char* combined = StringAppend(first, second);
	printf("%s\n", combined);
	free(combined);
	return 0;
}
