# Day 5 - Understanding C Strings

In C, strings are really just arrays of characters with one caveat - there is an extra character at the end of a C-string which is the character `\0` (a null string).

## Standard functions

Included in the `<stdio.h>` library:

```
size_t strlen(const char *s)
```

- `const`: means that a variable is read-only (not assignable after assignment).
- `size_t`: a data type for long unsigned int. Use it to signal that the quantity you are returning, is a 'size'.

```
char* strcat(char *dest, const char *src)
```
 
## String Literals

Also known as a 'string constant', it is created by enclosing a sequence of characters within " "'s.

```c
char* string_lit="I am a string literal";
``` 

Note: the null character `\0` is automatically included, we didn't have to put it in ourselves. 

What happens if we try to change one of the characters? eg) `string_lit[0] = H;`

```response
Segmentation fault (core dumped)
```

**String literals cannot be modified - they are read only (const)**

The reason for this is that the C compiler generates assembly code and a binary from this assembly code. The string literal is stored in a read-only region of the executable binary.


## realloc

```
realloc
```

Differs from `malloc` in that it changes the size of the memory block pointed to by `ptr` to `size` bytes.

## memcopy

Existing in `<string.h>` copies n bytes from memory area `src` to memory area `dest`.

```
void *memcopy(void *dest, const void *src, size_t n)
```

## What happens without the null character?

Take the example:

```c
int main()
{
	/// new scope
	{
		char name[6];
		name[0] = 'h';
		name[1] = 'e';
		name[2] = 'l';
		name[3] = 'l';
		name[4] = 'o';
		name[5] = '!';

		printf("%s\n", name);
	}

	/// new scope
	char name2[2];
	name2[0] = 'i'
	name2[1] = 'i';
	printf("%s\n", name2);

	return 0;
}
```

What gets printed is:

```
hello!
iillo!
```

This is because C does not automatically 'zero out' memory. Whatever is left in memory is what is left there. All of the rpevious data is left in the stack, data will print until it reaches a null byte in the stack.
