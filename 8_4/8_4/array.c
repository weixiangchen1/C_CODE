#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[3] = { 'a','b','c' };
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		printf("&arr[%d] = %p\n", i, &arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			arr[i][j] = i * 4 + j;
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[3][4];
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//		}
//	}
//	return 0;
//}

//方法1：
//#include <stdio.h>
//void bubble_sort(int arr[])
//{
//    int sz = sizeof(arr) / sizeof(arr[0]);//这样对吗？
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        for (j = 0; j < sz - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
//int main()
//{
//    int i = 0;
//    int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
//    bubble_sort(arr);//是否可以正常排序？
//    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 1,2,3,4,5 };
//    printf("%p\n", arr);
//    printf("%p\n", &arr[0]);
//    printf("%p\n", &arr);
//    输出结果
//    return 0;
//}

#include <stdio.h>
//方法2
void bubble_sort(int arr[], int sz)//参数接收数组元素个数
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
int main()
{
    int i = 0;
    int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz);//是否可以正常排序？
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}