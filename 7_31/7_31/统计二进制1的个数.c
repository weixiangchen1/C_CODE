#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int count = 0;
	int num = 0;
	scanf("%d", &num);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		int ret = 0;
		ret = num & 1;
		if (ret == 1)
		{
			count++;
		}
		num = num >> 1;
	}
	printf("count = %d\n", count);
	return 0;
}