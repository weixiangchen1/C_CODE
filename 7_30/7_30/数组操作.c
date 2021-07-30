#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 10
#include <stdio.h>

void Init(int arr[])
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		arr[i] = 0;
	}
}

void Print(int arr[])
{
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[])
{
	int left = 0;
	int right = MAX - 1;
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

int main()
{
	int arr[MAX] = { 0,1,2,3,4,5,6,7,8,9 };
	//Init(arr);
	Print(arr);
	reverse(arr);
	Print(arr);

}