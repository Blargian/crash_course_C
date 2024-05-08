Macros can be identified from the `#`. There are several different kinds but two of the most common are:
- `#include` : copies some other files contents into this file.
- `#define` : lets you define symbols which will be replaced by the define value on compile

## Text replacement and conditionals with define

For example

```c
#include <stdio.h>
#define PI 3.1415926

int main()
{
	printf('%f', PI);
}
```

You can see what is actually getting compiled if you run `gcc -E main.cpp | nl`. 

Notice how PI was replaced with the value we defined:

```
int main()
{
 printf('%f', 3.1415926);
}

```

This can be useful for conditional compiling, making use of the `-D` compile flag. 

```c
#include <stdio.h>

int main()
{
	#if DEBUG
		printf("DEBUGGING");
	#else
		printf("ORDINARY EXECUTION");
	#endif
	return 0;	
}

```

We can then compile with `gcc conditional_compile.c -DDEBUG=1` if we want to debug or `-DDEBUG=0` if not. You'll see this quite a bit when working with CMake.

Other macros we might commonly encounter are:

```
#ifndef
    #define PI 3.14159
#endif
```

## Function like macro

```
#include <stdio.h>
#define LOG(param) printf("LOG: %d", param);
   
int add(int a, int b)
{
    return a+b;
}

int main()
{
    LOG(add(7,2))
    return 0;
}	
```

## `__FILE__` and `__LINE__`

These print out the line we are at and file we are in. Useful for debugging.
