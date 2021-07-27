#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//
//int main()
//{
//	int num = 12345;
//	print(num);
//}

//int Fac1(int x)
//{
//	if (x == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return x * Fac1(x - 1);
//	}
//}
//
//int Fac2(int x)
//{
//	int sum = 1;
//	while (x >= 1)
//	{
//		sum = sum * x;
//		x--;
//	}
//	return sum;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int ret1 = Fac1(num);
//	printf("%d\n", ret1);
//	int ret2 = Fac2(num);
//	printf("%d\n", ret2);
//	return 0;
//}


//int my_strlen(char* p)
//{
//	if (*p != '\0')
//	{
//		return 1 + my_strlen(p + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char* arr = "hello";
//	int count = my_strlen(arr);
//
//	printf("%d\n", count);
//}

//int DigitSum(int x)
//{
//	if (x != 0)
//	{
//		return x % 10 + DigitSum(x / 10);
//	}
//	else {
//		return 0;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = DigitSum(n);
//	printf("%d\n", ret);
//
//	return 0;
//}