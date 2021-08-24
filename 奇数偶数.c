#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int str[20] = { 0 };
	int i = 0;
	int count = 0;
	for (i = 0; i <= 10; i++)
	{
		if (arr[i] % 2!=0)
		{
			str[count++] = arr[i];
		}
	}
	for (i = 0; i <= 10; i++)
	{
		if (arr[i] % 2==0)
		{
			str[count++] = arr[i];
		}
	}
	for (i = 0; i < count - 1; i++)
	{
		printf("%d ", str[i]);
	}
	return 0;
}