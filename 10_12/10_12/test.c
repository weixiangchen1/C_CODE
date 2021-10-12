#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

int main()
{
	char arr1[20] = "abcd";
	char arr2[] = "abcd";
	//printf("%s\n", my_strcat(arr1, arr2));

	int ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	return 0;
}

