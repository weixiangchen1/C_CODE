#include <stdio.h>
#include <math.h>
int main()
{
	int i, count=0;
	double x;
	scanf("%lf", &x);
	for(i=1;i<=pow(x, 1.0/3);i++)
	   count++;
	printf("%d", count);
}
