#Day 6 - man function arguments and char**

Command line arguments are often used. eg `ls -a` - `-a` is an argument.

We can specify arguments in main, like the argument count and the strings passed in. 

```c
int main(int argc, char** argv)
{

}
```

- `argc` : The total number of space sparated arguments when our program is invoked. 
- `argv` : A vector of strings, including the filename of the program being run as the first argument. The last element argv[argc] is a NULL pointer.

## Array of strings (char**)

- A char pointer to char*'s (A pointer to pointers of char type)
