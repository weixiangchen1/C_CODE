#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int Fib(int n)
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

int Fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib1(n - 1) + Fib1(n - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d", Fib(n));
	return 0;
}

//int Fac(int n)
//{
//	if (n == 1)
//		return 1;
//	else
//		return n * Fac(n - 1);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = Fac(n);
//	printf("%d", ret);
//
//	return 0;
//}


#/*include "add.h"

#pragma comment(lib, "add.lib")
int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("%d", c);

	return 0;
}*/

//void print(int n)
//{
//	printf("%d ", n % 10);
//	if (n > 9)
//	{
//		print(n / 10);
//		
//	}
//}
//
//int main()
//{
//	int x = 1234;
//	print(x);
//
//	return 0;
//}

//int my_strlen(char* s)
//{
//	if (*s != '\0')
//	{
//		return 1 + my_strlen(s + 1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[10] = "abcdfg";
//	printf("%d", my_strlen(arr));
//}
