#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int begin = 1;
	int end = 1;
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		begin *= 10;
	}
	for (int i = 0; i < n; i++)
	{
		end *= 10;
	}
	int i = 0;
	for (i = begin; i < end; i++)
	{
		int tmp = i;
		int sum = 0;
		int ret = i;
		while (ret)
		{
			sum += pow(ret % 10, n);
			ret /= 10;
		}
		if (tmp == sum)
		{
			printf("%d\n", sum);
		}
	}

	return 0;
}