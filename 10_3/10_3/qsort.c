//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//struct student
//{
//	char name[20];
//	int age;
//};
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int cmp_double(const void* e1, const void* e2)
//{
//	double a = *(double*)e1;
//	double b = *(double*)e2;
//	return (a > b) ? 1 : -1;
//}
//
//int cmp_char(const void* e1, const void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//
//int cmp_by_name(const void* e1, const void* e2)
//{
//	return ((struct student*)e1)->name - ((struct student*)e2)->name;
//}
//
//int cmp_by_age(const void* e1, const void* e2)
//{
//	return ((struct student*)e1)->age - ((struct student*)e1)->age;
//}
//
//int main()
//{
//	int arr[] = { 3,2,4,5,1,6,8,7,9,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, size, sizeof(arr[0]), cmp_int);
//
//	double arr1[] = { 1.2,1.6,1.4,1.0,2.6 };
//	int size1 = sizeof(arr1) / sizeof(arr1[0]);
//	qsort(arr1, size1, sizeof(arr1[0]), cmp_double);
//
//	struct student s[] = { {"zhangsan", 15}, {"lisi", 34}, {"wangwu", 56} };
//	int size2 = sizeof(s) / sizeof(s[0]);
//	qsort(s, size2, sizeof(s[0]), cmp_by_name);
//	qsort(s, size2, sizeof(s[0]), cmp_by_age);
//
//	char arr2[] = { 'a', 'e', 'c', 'b', 'd' ,'\0'};
//	int size3 = sizeof(arr2) / sizeof(arr2[0]);
//	qsort(arr2, size3, sizeof(arr2[0]), cmp_char);
//
//	return 0;
//}