#include <stdio.h>
int a[100][100];
void func(int n)
{
    int x = 0, y = -1;        //x,y��ʾ��ǰ����Ҫ��ֵ��λ��
    int x_add = 0, y_add = 1; //ÿ�θ�ֵʱ,x��y������
    int num = n, num_add = n; //num:�ƶ��������仯��ת���,num_add:ÿ��ת��ʱnum������
    for (int i = 1; i <= n * n; ++i)
    {
        x += x_add;
        y += y_add;
        a[x][y] = i;
        if (i == num) //ÿ���ƶ��������ı���ж�����
        {
            if (y_add == 1 || y_add == -1) //���������
            {
                x_add = y_add;
                y_add = 0;
                num_add--;      //Ϊ��һ�α�����׼������Ϊ���е����һ��Ԫ��Ҳ�Ǳ任���еĵ�һ��Ԫ�أ�Ϊ�˲��ظ����㣬���Լ�ȥһ
                num += num_add; //��һ�α�����յ�
            }
            else //��������
            {
                y_add = -x_add;
                x_add = 0;
                num += num_add; //��Ϊһ�����Ƚ��к�����������Դ�ʱ��num_add���Ѳ��ǳ�ʼ�������num_add����Ȼ�Ͳ����˼�һ������
            }
        }
    }
}
int main()
{
    int n;
    while (scanf_s("%d", &n)!=EOF)
    {
        func(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                printf("%5d ", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
