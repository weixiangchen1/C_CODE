#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = 10;//���ڴ��п���һ��ռ�
//	int* p = &a;//�������ǶԱ���a��ȡ�����ĵ�ַ������ʹ��&��������
//	  //��a�ĵ�ַ�����p�����У�p����һ��ָ֮�������
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;
//	int* pi = &n;
//
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return  0;
//}

//#include <stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)&n;
//	int* pi = &n;
//	*pc = 0;  
//	*pi = 0;  
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int* p;//�ֲ�����ָ��δ��ʼ����Ĭ��Ϊ���ֵ
//    *p = 20;
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int* p = arr;
//    int i = 0;
//    for (i = 0; i <= 11; i++)
//    {
//        //��ָ��ָ��ķ�Χ��������arr�ķ�Χʱ��p����Ұָ��
//        *(p++) = i;
//    }
//    return 0;
//}

#include <stdio.h>
int main()
{
    int* p = NULL;
    //....
    int a = 10;
    p = &a;
    if (p != NULL)
    {
        *p = 20;
    }
    return 0;
}
