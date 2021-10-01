#include <stdio.h>
int a[100][100];
void func(int n)
{
    int x = 0, y = -1;        //x,y表示当前数组要赋值的位置
    int x_add = 0, y_add = 1; //每次赋值时,x和y的增量
    int num = n, num_add = n; //num:移动方向发生变化的转变点,num_add:每次转变时num的增量
    for (int i = 1; i <= n * n; ++i)
    {
        x += x_add;
        y += y_add;
        a[x][y] = i;
        if (i == num) //每次移动方向发生改变的判断条件
        {
            if (y_add == 1 || y_add == -1) //横向变纵向
            {
                x_add = y_add;
                y_add = 0;
                num_add--;      //为下一次变向做准备，因为这列的最后一个元素也是变换成行的第一个元素，为了不重复计算，所以减去一
                num += num_add; //下一次变向的终点
            }
            else //纵向变横向
            {
                y_add = -x_add;
                x_add = 0;
                num += num_add; //因为一定会先进行横向变纵向，所以此时的num_add早已不是初始化定义的num_add，显然就不用了减一操作了
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
