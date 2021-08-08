#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[] = { &a,&b,&c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", *arr[i]);
//	}
//
//	return 0;
//}

//struct T
//{
//	int sex;
//	char name[10];
//};
//
//struct stu
//{
//	struct T t;
//	double high;
//};
//
//void Print1(struct stu s)
//{
//	printf("%d %s %lf\n", s.t.sex, s.t.name, s.high);
//}
//
//void Print2(struct stu* s)
//{
//	printf("%d %s %lf\n", s->t.sex, s->t.name, s->high);
//}
//#include <stdio.h>
//int main()
//{
//	struct stu student = { {1,"zhangsan"},1.75 };
//	Print1(student);
//	Print2(&student);
//	return 0;
//}

//void Print(int* arr)
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	Print(arr);
//
//	return 0;
//}

#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int sum = 0;
	int count = 0;
	for (i = 1; i <= 100000; i++)
	{
		sum = 0;
		count = 0;
		int ret = i;
		int tmp = i;
		while (ret)
		{
			count++;
			ret = ret / 10;
		}
		ret = i;
		while (ret)
		{
			sum += pow(ret % 10, count);
			ret = ret / 10;
		}
		if (sum == tmp)
		{
			printf("%d ", sum);
		}
	}

	return 0;
}