# Day 8 - Function Pointers 

```c
#include <stdio.h>

int add (int a, int b)
{
    return a+b;
}

int main(int argc, char** argv)
{
    return 0;
}
```

We can look at the assembly using `gcc -S main.c`. We see that our function `add` is there.

On linux we can use `objdump` to see that `add` has an address in memory. 

```
objdump -T a
```

Let's look at a more pragmatic example:

```
#include <stdio.h>

int add (int a, int b)
{
    return a+b;
}

int main(int argc, char** argv)
{
    printf("&add = %p\n", &add);
    return 0;
}
```

**Function pointers - ability to store a function address of a specific function signature**

Why would we need this?
- We can encapsulate (hold) the behaviour of a function in a pointer → we build on this to implement object orientation in C.

Function pointer syntax:

```
int (* pfn)(param1, param2) = &somefunction;
↑      ↑          ↑           ↑
return name       arguments   address of function
```
An example:

```c
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
    return 0;
}
```

Response:

```response
&add = 0x401126
2+7=9
```

The power is in being able to change what the function pointer points to:

```
// Change what pfn points auto
pfn = &multiply;
printf("2*7=%d\n", pfn(2, 7));
```
