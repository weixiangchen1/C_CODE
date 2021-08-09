#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		if (arr[left] % 2 == 1)
		{
			left++;
		}
		else if (arr[right] % 2 == 0)
		{
			right--;
		}
		else
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}