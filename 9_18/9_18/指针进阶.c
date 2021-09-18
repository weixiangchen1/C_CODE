#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void test(int(*p)[3])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[2][3] = { {1,2,3},{4,5,6 } };
//	test(&arr);
//
//	return 0;
//}


//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*p)(int, int) = Add;
//	int ret = p(2, 3);
//	printf("%p\n", p);
//	printf("%p\n", Add);
//	printf("%p\n", &Add);
//	printf("%d\n", ret);
//	ret = (*p)(3, 4);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	(*(void (*)()) 0)();
//	return 0;
//}

//typedef void(*pfun_t)(int);
//int main()
//{
//	void (*signal(int, void(*)(int)))(int);
//	pfun_t signal(int, pfun_t);
//	return 0;
//}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int input = 0;
	do
	{
		scanf("%d", &input);
		int (*pArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
		if (input == 0)
		{
			printf("退出计算器\n");
		}
		else if (input >= 1 && input <= 4)
		{
			int x = 0;
			int y = 0;
			printf("请输入两个操作数:>\n");
			scanf("%d%d", &x, &y);
			int ret = pArr[input](x, y);
			printf("%d\n", ret);
		}
	} while (input);

	return 0;
}