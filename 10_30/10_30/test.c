#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_type
{
	int i;
	int a[];//���������Ա
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
////1.GetMemory����Ϊ��ֵ���ã��������β�p�ı䲻Ӱ��str������������str��ΪNULLָ��
////��str����strcpy�������ûᵼ�³������
////2.GetMemory������p��̬�����ڴ��δ�ͷţ��ᵼ���ڴ�й¶
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
////GetMemory������p�����������������GetMemory�еģ����˺���p�����������
////�������ý�����Test����ʹ��p�ĵ�ַ���ڷǷ������ڴ�ռ�
////����ջ�ռ��ַ����
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
////p����Ŀռ�û�б��ͷţ������ڴ�й¶����
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
////str������ڴ���Ȼ���ͷţ���������Ȼ���סԭ���������һ��ռ䲻ΪNULL��ֻ��ʹ��Ȩ�޽���������ϵͳ
////str��һ��Ұָ�룬�������strcpy�����ǷǷ���
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
//		//ʹ�ÿռ�
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
//		*(p + i) = i;//��i��10��ʱ��Խ�����
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
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}
//
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//�ظ��ͷ�
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

