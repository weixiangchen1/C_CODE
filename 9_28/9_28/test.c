#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int my_strlen(char* arr)
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(arr + 1);
//
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	return 0;
//}

//typedef struct LNode
//{
//	int data;
//	struct LNode* next;
//}LNode;
//
//LNode* max(LNode* node)
//{
//	if (node->next == NULL)
//		return node;
//	else
//	{
//		if (node->data > max(node->next)->data)
//			return node;
//		else
//			return max(node->next);
//	}
//}
//int main()
//{
//	LNode a = { 1, NULL };
//	LNode b = { 55, NULL };
//	LNode c = { 2, NULL };
//	a.next = &b;
//	b.next = &c;
//	LNode* p = max(&a);
//	printf("%d", p->data);
//
//	return 0;
//}


//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//
//void BubbleSort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2))
//{
//	size_t i = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width))
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	BubbleSort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

int main()
{
	char str[100] = { 0 };
	int k = 0;
	int i = 0;
	scanf("%d", &k);
	scanf("%s", str);
	int len = strlen(str);
	while (k--)
	{
		char tmp = str[0];
		for (i = 1; i < len; i++)
		{
			str[i - 1] = str[i];
		}
		str[len - 1] = tmp;
		str[len] = '\0';
	}
	printf("%s\n", str);
	return 0;
}