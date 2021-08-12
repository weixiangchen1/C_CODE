#include <stdio.h>
int main()
{
	int i, n;
	double sum=0, item;
	int a=2, b=1, t;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		item=(double)a/b;
		sum=sum+item;
		t=b;
		b=a;
		a=a+t;
	}
	printf("%.2f", sum);
}
