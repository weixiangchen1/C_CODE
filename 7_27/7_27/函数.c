#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//void new_line()
//{
//	printf("hello\n");
//}
//void three_line()
//{
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        new_line();
//    }
//}
//int main()
//{
//    three_line();
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    printf("%d", printf("%d", printf("%d", 43)));
//    //½á¹ûÊÇÉ¶£¿
//    return 0;
//}

//
//#include <stdio.h>
//void print(int n)
//{
//	//if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int num = 1234;
//	print(num);
//	return 0;
//}

#include <stdio.h>
int Strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else return 1 + Strlen(str + 1);
}
int main()
{
	char* p = "abcdef";
	int len = Strlen(p);
	printf("%d\n", len);
	return 0;
}
