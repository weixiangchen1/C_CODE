#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	num1& num2;
//	num1 | num2;
//	num1^ num2;
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	//����1
//	int a = 10;
//	int b = 20;
//	printf("a=%d,b=%d\n", a, b);
//	//1.
//	a = a + b;
//	b = a - b;//(a+b)-b = a
//	a = a - b;//(a+b)-a = b
//	printf("a=%d,b=%d\n", a, b);//�����������
//
//	//����2
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a = %d b = %d\n", a, b);//�ɶ��Բֻ����������
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = -10;
//	int* p = NULL;
//	printf("%d\n", !2);
//	printf("%d\n", !0);
//	a = -a;
//	p = &a;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof a);//����д�в��У�
//	printf("%d\n", sizeof int);//����д�в��У�
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int x = 0;
//	if (!x)
//	{
//		printf("YES\n");
//	}
//	else
//	{
//		printf("NO\n");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//(2)
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//(4)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));//(1)
//	printf("%d\n", sizeof(ch));//(3)
//	test1(arr);
//	test2(ch);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int x = ++a;
//	//�ȶ�a����������Ȼ���ʹ��a��Ҳ���Ǳ��ʽ��ֵ��a����֮���ֵ��xΪ11��
//	int y = --a;
//	//�ȶ�a�����Լ���Ȼ���ʹ��a��Ҳ���Ǳ��ʽ��ֵ��a�Լ�֮���ֵ��yΪ10;
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", i[arr]);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//void test1()
//{
//	printf("hehe\n");
//}
//void test2(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	test1();            //ʵ�ã�����Ϊ�������ò�������
//	test2("hello bit.");//ʵ�ã�����Ϊ�������ò�������
//	return 0;
//}


//#include <stdio.h>
//struct Stu
//{
//	char name[10];
//	int age;
//	char sex[5];
//	double score;
//}��
//void set_age1(struct Stu stu)
//{
//	stu.age = 18;
//}
//void set_age2(struct Stu* pStu)
//{
//	pStu->age = 18;//�ṹ��Ա����
//}
//int main()
//{
//	struct Stu stu;
//	struct Stu* pStu = &stu;//�ṹ��Ա����
//
//	stu.age = 20;//�ṹ��Ա����
//	set_age1(stu);
//
//	pStu->age = 20;//�ṹ��Ա����
//	set_age2(pStu);
//	return 0;
//}
