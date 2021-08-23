#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	printf("The size of short is %d bytes.\n", sizeof(short));
//	printf("The size of int is %d bytes.\n", sizeof(int));
//	printf("The size of long is %d bytes.\n", sizeof(long));
//	printf("The size of long long is %d bytes.\n", sizeof(long long));
//
//
//	return 0;
//}

#include <stdio.h>
int main()
{
    int val = printf("Hello World!");
    printf("\n");
    printf("%d\n", val);

    return 0;
}