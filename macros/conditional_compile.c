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
