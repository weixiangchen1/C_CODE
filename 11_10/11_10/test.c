#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//用宏计算出结构体成员的偏移量
//#define OFFSETOF(struct_type, mem_name) \
//	(int)&(((struct_type*)0)->mem_name)
//
//struct Stu
//{
//	int a;
//	char b;
//	double c;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct Stu, a));
//	printf("%d\n", OFFSETOF(struct Stu, b));
//	printf("%d\n", OFFSETOF(struct Stu, c));
//
//	return 0;
//}
//
//int main()
//{
//	int arr[] = { 1,1,2,2,3,3,4,4,5,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int pos = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	for (i = 0; i < 32; i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	int n = 0;
//	int m = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			n ^= arr[i];
//		}
//		else
//		{
//			m ^= arr[i];
//		}
//
//	}
//	printf("%d %d\n", n, m);
//
//	return 0;
//}
//
//#include <stdlib.h>
//#include <assert.h>
//#include <ctype.h>
//
//enum State
//{
//	VALID,
//	INVALID
//};
//
//enum State state = INVALID;
//int my_atoi(const char* str)
//{
//	assert(str);
//	if (*str == '\0')
//	{
//		return 0;
//		//非法返回
//	}
//	//跳过空格
//	if (isspace(*str))
//	{
//		str++;
//	}
//	//识别正负数
//	int flag = 1;
//	if (*str == '+')
//	{
//		str++;
//	}
//	else if (*str == '-')
//	{
//		flag = -1;
//		str++;
//	}
//	long long ret = 0;
//	while (*str)
//	{
//		if (isdigit(*str))
//		{
//			ret = ret * 10 + flag * (*str - '0');
//			if (ret<INT_MIN || ret>INT_MAX)
//			{
//				return 0;
//			}
//			str++;
//		}
//		else
//		{
//			state = VALID;
//			return (int)ret;
//		}
//	}
//
//	state - VALID;
//	return (int)ret;
//
//}
//
//int main()
//{
//	int val = my_atoi("12345");
//	printf("%d\n", val);
//}

#define SWAP_BIT(n) n=((n&0xaaaaaaaa)>>1)+((n&0x55555555)<<1)

int main()
{
	int a = 10;
	SWAP_BIT(a);

	printf("%d\n", a);

	return 0;
}