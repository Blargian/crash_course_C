# Day 7 - Pointer are not arrays, and 2D arrays

A review of arrays:
- Arrays are contiguous blocks of memory.

```
[][][][][][]
0 1 2 3 4 5
``` 

- `char**` is a multi-dimensional array (an array of strings) 


In the code below `size_of` returns the size (in bytes) of a type or variable. Why do we get 28? We have 7 elements in the array and an int is 4-bytes. For 'stack allocated' arrays, in the current block scope, we can retrieve the size of the array.

```c
int main(int argc, char** argv)
{

    int array[7];
    for (int i=0; i<7; i++)
    {
        array[i] = i;
    }

    for (int i=0; i<7; i++)
    {
        printf("%d\n", array[i]);
    }

    printf("%ld\n", sizeof(array));
    return 0;
}
```

We can take a pointer to an array.

```c
// int* p_array = array;
int* p_array = &array[0]
```

You can walk through a pointer using `[]` syntax:

```c
int array[7];
for (int i=0; i<7; i++)
{
	array[i] = i;
}

int* p_array = array;
for (int i=0; i<7; i++)
{
	printf("%d\n", p_array[i]);
}
```
When using `sizeof` on a pointer, it returns the size of the pointer data type (not of the array) - typically 8 bytes on a 64-bit architecture.

**N.B : Arrays passed to functions decay to pointers (we lose the size information we had with arrays)**

It is for this reason that in the C API you will often see something like this:

```c
void some_function(int an_array[], size_t size)
{
	//...
}
```

In this way when our array decays to a pointer we do not lose the size information.

An alternative is making our own array type which holds the size intrinsically:

```c
typedef struct array
{
	int* data;
	size_t size;
} array_t;
```

> Are pointers arrays?

No. But they are closely linked. Here is an example of why they are not the same:

```c
int array1[4];
int* parray1 = array1;

int* parray2;
int array2[4] = parray2; // throws an invalid initializer compiler error
```

 ## Two dimensional array

2D (multidimensional) arrays are still contiguous blocks of memory. 

```
   pitch
<--------> 
[][][][][] ↑
[][][][][] |
[][][][][] |
[][][][][] ↓

// is the same as:

   pitch
<-------->
[][][][][][][][][][][][][][][][][][][][]
```

- `pitch`: the array width (how many columns)
  
Syntax:

```c
int array2D[0][1]
```

Example:

```c
#include <stdio.h>

int main(int argc, char** argv)
{
    int counter=0;
    int array2D[5][4];
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<4; j++)
        {
            array2D[i][j] = counter++;
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

Accessing 2D with pointers:

```
Select element at [i,j] : [ith_row*number_of_elements_in_a_column + jth_element]
```

**You can pass a 2D (3D, 4D etc) array into a function in C, but the second (and any further dimensions) need to be fixed. Typically, it's more common to pass in a pointer to a 1D array and then do the conversion to 2D or to 3D etc: **

```c
int* array2D = (int*)malloc(sieof(int)*5*4);
```

Example:

```c
#include <stdio.h>
#include <stdlib.h>

void print2DArrayWithPointer(int* array, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d\t", array[i*cols+j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    const int rows = 5;
    const int cols = 4;
    int counter = 0;
    int* array2D = (int*)malloc(sizeof(int)*rows*cols);
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            array2D[cols*i + j] = counter++;
            printf("%d ", array2D[cols*i + j]);
        }
        printf("\n");
    }

    // Print 2D array with function defined above
    print2DArrayWithPointer(array2D, 5, 4);
    free(array2D);
    return 0;
}
```
