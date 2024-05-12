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

