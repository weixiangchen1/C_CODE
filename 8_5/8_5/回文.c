#define _CRT_SECURE_NO_WARNINGS 1
#include <string.h>
#include <stdio.h>
int main()
{
	int flag = 1;
	int left = 0;
	int right = 0;
	int i = 0;
	char s[10000];
	char arr[100000];
	int count = 0;
	gets(s);
	int len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			arr[count] = s[i];
			count++;
		}
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			arr[count] = s[i] + 32;
			count++;

		}
	}
	arr[count] = '\0';
	right = count - 1;
	while (left < right)
	{
		if (arr[left] != arr[right])
		{
			flag = 0;
			break;
		}
		left++;
		right--;
	}
	if (flag)
		printf("YES\n");
	else
		printf("NO\n");
}