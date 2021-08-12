#include<stdio.h>
#include<math.h>
int main()
{
	double eps,pi;
	int denominator,flag;
	double item;
	scanf("%lf",&eps);
	flag=1;
	denominator=1;
	item=1.0;
	pi=0;
	while(fabs(item)>eps){
		item=flag*1.0/denominator;
		pi=pi+item;
		flag=-flag;
		denominator=denominator+2;
	}
	pi=4*pi;
	printf("Pi = %.4f",pi);
 } 
