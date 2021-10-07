#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void left_move(char* str, int k)
//{
//	assert(str);
//	int i = 0;
//	int len = strlen(str);
//	for (i = 0; i < k; i++)
//	{
//		int j = 0;
//		char tmp = *str;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		* (str + len - 1) = tmp;
//	}
//}

//void reverse(char* l, char* r)
//{
//	assert(r && l);
//	while (l < r)
//	{
//		char tmp = *l;
//		*l = *r;
//		*r = tmp;
//
//		l++;
//		r--;
//	}
//}
//
//void left_move(char* str, int k)
//{
//	assert(str);
//	int len = strlen(str);
//	reverse(str, str + k - 1);
//	reverse(str + k, str + len - 1);
//	reverse(str, str + len - 1);
//}
//
//int is_left_move(char* arr1, char* arr2)
//{
//	assert(arr1 && arr2);
//	int i = 0;
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//		return 0;
//	for (i = 0; i < len1; i++)
//	{
//		left_move(arr1, 1);
//		if (strcmp(arr1, arr2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}

//
//int is_left_move(char* arr1, char* arr2)
//{
//	assert(arr1 && arr2);
//
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if (len1 != len2)
//		return 0;
//	strncat(arr1, arr1, len1);
//	if (NULL == strstr(arr1, arr2))
//		return 0;
//	else
//		return 1;
//}
//
//int main()
//{
//	char arr1[20] = "AABCD";
//	char arr2[] = "BCDAA";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("Yes\n");
//	else
//		printf("No\n");
//	//printf("%s\n", str);
//	return 0;
//}

void find_key(int arr[3][3], int key, int r, int c)
{
	int x = 0;
	int y = c - 1;
	while (x < r && y >= 0)
	{
		if (key < arr[x][y])
		{
			y--;
		}
		else if (key > arr[x][y])
		{
			x++;
		}
		else
		{
			printf("找到了：%d %d\n", x, y);
			return;
		}
	}
	printf("找不到\n");
}

int main()
{
	int x = 3;
	int y = 3;
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int key = 5;
	find_key(arr, key, x, y);
	return 0;
}