#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\Administrator\\Desktop\\data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//	fputc('h', pf);//将字符写入文件
//	fputc('e', pf);
//	fputc('l', pf);
//	fputc('l', pf);
//	fputc('o', pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	fputc('h', stdout);//将字符打印在屏幕上
//	fputc('e', stdout);
//	fputc('l', stdout);
//	fputc('l', stdout);
//	fputc('o', stdout);
//
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("C:\\Users\\Administrator\\Desktop\\data.txt", "r");
//	if (NULL == pf)
//	{
//		printf("fopen");
//		return -1;
//	}
//	int ch = fgetc(pf);//读文件
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	int ch = fgetc(stdin);
//	printf("%c\n", ch);
//	ch = fgetc(stdin);
//	printf("%c\n", ch);
//	ch = fgetc(stdin);
//	printf("%c\n", ch);
//
//	return 0;
//}
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\Administrator\\Desktop\\data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return -1;
//	}
//
//	fputs("hello world\n", pf);
//	fputs("hello\n", pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

int main()
{
	FILE* pf = fopen("C:\\Users\\Administrator\\Desktop\\data.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		return -1;
	}
	char arr[20] = { 0 };
	fgets(arr, 20, pf);
	printf("%s\n", arr);
	fgets(arr, 20, pf);
	printf("%s\n", arr);

	fclose(pf);
	pf = NULL;
	return 0;
}