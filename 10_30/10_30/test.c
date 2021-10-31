#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_type
{
	int i;
	int a[];//柔性数组成员
};

int main()
{
	int i = 0;
	struct st_type* pc;
	printf("%d\n", sizeof(struct st_type));//4
	struct st_type* ptr = (struct st_type*)malloc(sizeof(struct st_type) + 10 * sizeof(int));
	if (ptr == NULL)
	{
		return -1;
	}
	pc = ptr;
	for (i = 0; i < 10; i++)
	{
		*(pc->a + i) = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", * (pc->a + i));
	}
	free(pc);
	pc = NULL;
	return 0;
}

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
////1.GetMemory函数为传值调用，函数中形参p改变不影响str，函数结束后str仍为NULL指针
////对str进行strcpy函数调用会导致程序崩溃
////2.GetMemory函数中p动态申请内存后未释放，会导致内存泄露
//int main()
//{
//	Test();
//	return 0;
//}

//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
////GetMemory函数中p数组的生命周期是在GetMemory中的，出了函数p数组就销毁了
////函数调用结束后Test函数使用p的地址属于非法访问内存空间
////返回栈空间地址问题
//int main()
//{
//	Test();
//	return 0;
//}

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
////p申请的空间没有被释放，存在内存泄露问题
//int main()
//{
//	Test();
//	return 0;
//}

//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
////str申请的内存虽然被释放，但是它仍然会记住原本申请的那一块空间不为NULL，只是使用权限交还给操作系统
////str是一个野指针，对其进行strcpy操作是非法的
//int main()
//{
//	Test();
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;
//	free(p);
//}

//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}

//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//重复释放
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}

//int GlobalVar = 1;
//static int staticGlobalVar = 1;
// 
//void test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num[] = { 0 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 8);
//
//	free(ptr1);
//	free(ptr3);
//}

