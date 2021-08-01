#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			printf("* ");
		}
		printf("\n");
		printf("\n");
		for (i = 0; i < n - 2; i++)
		{
			printf("* ");
			for (j = 0; j < n - 2; j++)
			{
				printf("  ");
			}
			printf("* ");
			printf("\n");
			printf("\n");
		}
		for (i = 0; i < n; i++)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	return 0;
}