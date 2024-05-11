#include <stdio.h>

int add (int a, int b)
{
    return a+b;
}

int multiply (int a, int b)
{
    return a*b;
}

int main(int argc, char** argv)
{
    printf("&add = %p\n", &add); // Prints the address of the add function

    // Create a function pointer
    int (* pfn)(int, int) = &add;
    printf("2+7=%d\n", pfn(2, 7));

    // Change what pfn points auto
    pfn = &multiply;
    printf("2*7=%d\n", pfn(2, 7));
    
    return 0;
}
