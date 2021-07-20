#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int fun(int n)
{
	int sum = 1;
	while (n >= 1)
	{
		sum = sum * n;
		n--;
	}
	return sum;
}
int main()
{
	int x = 1;
	int ret = 0;
	while (x <= 10)
	{
		ret += fun(x);
		x++;
	}
	printf("%d", ret);
	return 0;
}