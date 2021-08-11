#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}

int my_strlen(const char* arr)
{
	int count = 0;
	assert(arr);
	while (*arr++ != '\0')
	{
		count++;
	}
	return count;
}

int main()
{

	char arr1[] = "abcdef";
	char arr2[10] = { 0 };
	//my_strcpy(arr2, arr1);
	printf("%d\n", my_strlen(arr1));
	printf("%s\n", arr2);

	return 0;
}