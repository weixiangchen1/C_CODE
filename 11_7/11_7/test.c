#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	
//	return 0;
//}
//
//#define MAX 100
//#define reg register
//#define STR "hello world"
//int main()
//{
//	int a = MAX;
//	reg int b = 100;
//	printf("%d\n", a);
//	printf("%d\n", b);
//	printf("%s\n", STR);
//
//	return 0;
//}
//#define SQUARE(X) ((X)*(X))
//#define DOUBLE(X) ((X)+(X))
//#define ADD(X,Y) ((X)+(Y))
//
//#include <math.h>
//int main()
//{
//	float a = 5.5;
//	int b = 4;
//	float ret = SQUARE(a);
//	float tmp = DOUBLE(a);
//	float val = ADD(ADD(a,b), b);
//	printf("%lf\n", ret);
//	printf("%lf\n", tmp);
//	printf("%lf\n", val);
//
//	return 0;
//}
//
//#define PRINT(n) printf("the value of "#n" is %d\n", n)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	PRINT(a);
//	PRINT(b);
//	printf("hello ""world");
//
//	return 0;
//}
//
//#define CAT(X,Y) X##Y
//
//int main()
//{
//	int val_t = 100;
//	printf("%d\n", CAT(val, _t));
//	printf("%d\n", CAT(1, 2));
//
//	return 0;
//}
//
//#define MAX(X,Y) ((X>Y)?(X):(Y))
//
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//int ret = MAX(10, 20);
//	//int ret = MAX(a++, b++);
//
//	//int ret = ((a++>b++)?(a++):(b++))
//	//printf("%d\n", ret);//21
//	//printf("%d\n", a);//11
//	//printf("%d\n", b);//22
//
//	int val = Max(a++, b++);
//	printf("%d\n", val);//20
//	printf("%d\n", a);//11
//	printf("%d\n", b);//21
//	return 0;
//}
//
//#define MALLOC(num, type) (type*)malloc(num*sizeof(type))
//
//int main()
//{
//	int* arr = MALLOC(10, int);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(arr + i) = i;
//		printf("%d ", *(arr + i));
//	}
//	free(arr);
//	arr = NULL;
//
//	return 0;
//}
//
//#define MAX 100
//#if 1
//int main()
//{
//	int m = MAX;
//	printf("hello world");
//
//	return 0;
//}
//#endif
//#define M 2
//int main()
//{
//#if M == 2
//	printf("hello\n");
//#endif
//
//	return 0;
//}
#define MAX 100
int main()
{
#if MAX==100
	printf("1\n");
#elif MAX = 200
	printf("2\n");
#else
	printf("3\n");
#endif
	return 0;
}