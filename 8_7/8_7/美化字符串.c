#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char arr[10000];
	char s[10000];
	gets(arr);
	int count = 0;
	int len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z')||arr[i] == ' ')
		{
			s[count++] = arr[i];
		}
	}
	s[count] = '\0';
	printf("%s", s);

	return 0;
}