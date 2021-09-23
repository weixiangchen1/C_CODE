#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char arr1[101] = { 0 };
	char arr2[101] = { 0 };
	int n = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", arr1);
		scanf("%s", arr2);
		int left = 0;
		int right = strlen(arr1) - 1;
		while (left < right)
		{
			char tmp = arr1[left];
			arr1[left] = arr1[right];
			arr1[right] = tmp;
			left++;
			right--;
		}
		if (strcmp(arr1, arr2) == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}