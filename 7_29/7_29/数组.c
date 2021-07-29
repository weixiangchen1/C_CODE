#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//int main()
//{
//	char arr[] = "abcdef";
//
//	printf("%d %d", strlen(arr), sizeof(arr));
//	return 0;
//
//}

//int main()
//{
//	int arr[][3] = { 1,2,3,4,5,6,7,8,9 };
//	int arr1[3][5] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[3][5] = { {1,2},{3,4},{5,6} };
//
//	char ch[][5] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	char ch1[3][5] = { {'a', 'b'}, {'c', 'd'} };
//	char ch2[3][5] = { "abc", "def", "gh" };
//
//	return 0;
//}

//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	return 0;
//}

//int main()
//{
//	/*int arr[3][5] = { {1,2,3},{4,5},{6,7,8,9,0} };
//	int* p = arr;
//	int i;
//	for (i = 0; i < 15; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}*/
//	int i = 0;
//	int arr[3][5] = { 1,2,3,4,5,6,7,7,8,9 };
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//}

bubble_sort(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		if (flag)
			break;
	}
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr)/sizeof(arr[0]);

	bubble_sort(arr, sz);

	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}