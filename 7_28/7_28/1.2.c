//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int my_strlen(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//void reverse_string(char* str)
//{
//	int len = my_strlen(str);
//	char tmp = str[0];
//	str[0] = str[len - 1];
//	str[len - 1] = '\0';
//	if (my_strlen(str + 1) >= 2)
//	{
//		reverse_string(str + 1);
//	}
//	str[len - 1] = tmp;
//}
//
//int main()
//{
//	char arr[20] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//
//	return 0;
//}