# Bit shifting and bit fields

Binary representation of `2`: `0000 0010`. Using `<<` we can move everything forward:

## Bitwise operators `<<` and `>>`
```c
x = 2; // '0000 0010'
x << 1;
// gives us '0000 0100' which is 4
```
> This shows us that bit shifting is a way to do multiplication.

In the example below we see that the left shift (`<<`) operation multiplies by 2 for every bit shifted.
```c
#include <stdio.h>

int main()
{
    int x = 1;
    printf("x is %d\n", x);
    x = x << 1;
    printf("x is %d\n", x);
    x = x << 1;
    printf("x is %d\n", x);
    x = x << 1;
    printf("x is %d\n", x);
    x = x << 1;
    printf("x is %d\n", x);
    return 0;
}
```

Response:
```
x is 1
x is 2
x is 4
x is 8
x is 16
```

In the example below we see that the right shift (`>>`) operation divides by 2 for every bit shifted.
```c
#include <stdio.h>

int main()
{
    int x = 64;
    printf("x is %d\n", x);
    x = x >> 1;
    printf("x is %d\n", x);
    x = x >> 1;
    printf("x is %d\n", x);
    x = x >> 1;
    printf("x is %d\n", x);
    x = x >> 1;
    printf("x is %d\n", x);
    return 0;
}
```

Response:
```
x is 64
x is 32
x is 16
x is 8
x is 4
```

An example of where this is useful: An image is made up of pixels which have an R, G, B, (A) component. Most common pixel formats use 1 byte (8 bits) to store a value of 0-255, which represents the intensity of the component.

```c
#include <stdio.h>

int main()
{
    // Hex number representation
    int Pixel = 0xFFAACC11; // FF=red, AA=green, CC=blue, 11=opacity
    unsigned char r = (Pixel >> 24);
    unsigned char g = (Pixel >> 16);
    unsigned char b = (Pixel >> 8);
    unsigned char a = (Pixel >> 0);

    printf("r is: %d\n", r);
    printf("g is: %d\n", g);
    printf("b is: %d\n", b);
    printf("a is: %d\n", a);
    
    return 0;
}
```
Response:
```
r is: 255
g is: 170
b is: 204
a is: 17
```

## Converting hex value to decimal

Decimal and Hexadecimal values all correspond up until 9. Then:

| Decimal  | Hexadecimal |
| ------------- | ------------- |
| 10  | A  |
| 11  | B  |
| 12  | C  |
| 13  | D  |
| 14  | E  |
| 15  | F  |

This can be done quite quickly with python3 just by typing the number: 
```
>>> 0xff
255
```
or from decimal to hex using `hex(255)`

To do it manually:

eg. `0x23E` = `(2*16^2) + (3*16^1) + (14*16^0)` = `0d574`

## Bit fields

We can specify the size in bits using `:` operator.

```c
#include <stdio.h>

typedef struct StagesCompleted
{
    char level1Completed:1; // use only 1 bit
    char level2Completed:1;
    char level3Completed:1;
    char level4Completed:1;
    char level5Completed:1;
    char level6Completed:1;
    char level7Completed:1;
    char level8Completed:1;
} StagesCompleted_t;

int main()
{

    printf("sizeof(StagesCompleted_t) = %ld\n", sizeof(StagesCompleted_t));
    return 0;
}
```

Response:
```
sizeof(StagesCompleted_t) = 1
```






