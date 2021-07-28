#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fib1(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fib1(n - 1) + fib1(n - 2);
	}
}

int fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret1 = fib1(n);
	int ret2 = fib2(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);

	return 0;
}