#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int isPrime(int x)
{
	int i;
	for (i = 2; i < sqrt(x); i++)
	{
		if (x % i == 0)
			return 1;
	}
	return 0;
}
int main()
{
	int n = 100;
	int m = 200;
	for (int i = n; i <= m; i++)
	{
		if (isPrime(i)==0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}