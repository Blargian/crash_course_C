#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array
{
    // Pointer to 'self' - called 'this' in other languages
    struct array* self;

    // "member variables"
    int* data;
    size_t size;

    // "Member functions" or "methods" that we implement from scratch
    void (*pfnSet)(struct array*, size_t, int);
    int (*pfnGet)(struct array*, size_t);
} array_t;

// Retrieve data
int Get_array_t(array_t* self, size_t index)
{
    return self->data[index];
}

// Set data
void Set_array_t(array_t* self, size_t index, int value)
{
    if (NULL == self)
    {
        return;
    }
    if (index >=0 && index < self->size)
    {
        self->data[index] = value;
    }
}

// Array Constructor
array_t* make_array(size_t capacity)
{
    array_t* newArray = (array_t*)malloc(sizeof(array_t));

    // Store the pointer back to the memory that holds our actual object
    newArray->self = newArray;
    newArray->data = (int*)malloc(sizeof(int)*capacity);
    newArray->size = capacity;

    //Set up the function pointers
    newArray->pfnSet = Set_array_t;
    newArray->pfnGet = Get_array_t;

    return newArray;
}

// Array destructor
void destroy_array(array_t* self)
{
    free(self->data);
    free(self);
}

int main()
{
    array_t* test = make_array(10);

    // Set all of the values
    for (int i=0; i<10; i++)
    {
        test->pfnSet(test->self,i,i);
    }

    // Retrieve all of the values

    for (int i=0; i<10; i++)
    {
        printf("%d\n", test->pfnGet(test->self,i));
    }
    destroy_array(test);
    return 0;
}
