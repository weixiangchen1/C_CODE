#include <stdio.h>
#include <math.h>
bool isint(double x){
	if(x==(int)x) return true;
	else return false;
}
int main()
{
	int count=0;
	double a, b;
	double i;
	scanf("%lf%lf", &a, &b);
	while(a!=0){
		count=0;
	for(i=a;i<=b;i++)
	   if(isint(i)&&isint(sqrt(i)))
	   count++;
	printf("%d\n", count);
	scanf("%lf%lf", &a, &b);
	}
	
 }
