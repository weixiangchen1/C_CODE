#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int* p = (int*)malloc(40);
//	int i = 0;
//	if (p == NULL)
//	{
//		return -1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int* p = (int*)calloc(10, 4);
//	if (p == NULL)
//	{
//		return -1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

int main()
{
	int* p = (int*)malloc(40);
	int i = 0;
	if (p == NULL)
	{
		return -1;
	}
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}
	int* ptr = (int*)realloc(p, 80);
	if (ptr != NULL)
	{
		p = ptr;
	}
	else
	{
		return;
	}
	for (i = 10; i < 20; i++)
	{
		*(p + i) = i;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);
	p = NULL;

	return 0;
}