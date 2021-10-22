#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void sort(char* btf1, char* btf2, int width)
{
	while (width--)
	{
		char tmp = *btf1;
		*btf1 = *btf2;
		*btf2 = tmp;
		btf1++;
		btf2++;
	}
}

void bubble_sort(void* base, size_t num, size_t width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + (j * width), (char*)base + (j + 1) * width))
			{
				sort((char*)base + (j * width), (char*)base + (j + 1) * width, width);
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int main()
{
	int arr[] = { 0,1,2,3,5,4,6,7,8,9 };
	bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), cmp_int);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}