#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	void* ret = dest;
//	assert(dest && src);
//	if (dest > src)
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1 + 3, arr1, 24);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
//
//void my_memcpy(void* dest, void* src, size_t count)
//{
//	assert(dest && src);
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 5,5,5,5,5,5,5,5,5,5 };
//	//memcpy(arr1, arr2, 40);
//	my_memcpy(arr1, arr2, 40);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
//
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
//		if (*str2 == '\0')
//		{
//			return str1;
//		}
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//			if (*s2 == '\0')
//				return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	const char arr[] = "I am a student";
//	const char str[] = "am";
//	char* ret = my_strstr(arr, str);
//	printf("%s\n", ret);
//
//	return 0;
//}
//
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest && src);
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//int main()
//{
//	char str1[20] = "hello ";
//	char str2[] = "world";
//	char* ret = my_strcat(str1, str2);
//
//	printf("%s\n", ret);
//
//	return 0;
//}
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char* str1 = "hello";
//	char* str2 = "hello";
//
//	printf("%d\n", my_strcmp(str1, str2));
//
//	return 0;
//}
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "xxxxx";
//	char* ret = my_strcpy(str1, str2);
//	printf("%s\n", ret);
//
//	return 0;
//}

int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str++)
	{
		count++;
	}

	return count;
}

int main()
{
	char str[] = "hello world";
	int len = my_strlen(str);

	printf("%d\n", len);
	return 0;
}