#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//size_t NumberOf1(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}

//size_t NumberOf1(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	return count;
//}

size_t NumberOf1(unsigned int n)
{
	int count = 0;
	while (n)
	{
		if (n % 2 == 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = NumberOf1(num);

	printf("%d\n", ret);
	return 0;
}