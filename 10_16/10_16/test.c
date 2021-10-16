#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//void move(char* str, int length, int count)
//{
//	int i = 0;
//	for (i = length - 1; i > count; i--)
//	{
//		*(str + i + 3) = *(str + i);
//	}
//	*(str + count) = '%';
//	*(str + count + 1) = '2';
//	*(str + count + 2) = '0';
//}
//
//void stringreplace(char* str, int length)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		if (*str == ' ')
//		{
//			move(str, length, count);
//		}
//		str++;
//	}
//}
//
//int main()
//{
//	char s[] = "we are happy";
//	int length = strlen(s);
//	stringreplace(s, length);
//
//	printf("%s\n", s);
//	return 0;
//}
//
//void* my_memcpy(void* dest, void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//	my_memcpy(arr2, arr1, 10 * sizeof(int));
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* s1;
//	char* s2;
//	char* cp = str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 && *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char str1[] = "student";
//	char str2[] = "student";
//	int tmp = my_strcmp(str1, str2);
//	printf("%d\n", tmp);
//	char* ret = my_strstr(str1, str2);
//	printf("%s\n", ret);
//
//	return 0;
//}


int main()
{
	char str1[] = "1422306169@qq.com";
	char str2[100] = { 0 };
	char arr[] = "@.";
	char* ret = NULL;
	strcpy(str2, str1);
	for (ret = strtok(str2, arr); ret != NULL; ret = (NULL, arr))
	{
		printf("%s\n", ret);
	}

	return 0;
}