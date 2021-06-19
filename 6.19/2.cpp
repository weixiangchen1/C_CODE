#include <stdio.h>
void bubble(double a[], int n){
	int i, j, t;
	for(i=1;i<n;i++)
	   for(j=0;j<n-i;j++)
	   if(a[j]>a[j+1]){
	   	t=a[j];a[j]=a[j+1];a[j+1]=t;
	   }
}
int main()
{
	int i, n;
	double sum=0;
	scanf("%d", &n);
	double a[100000];
	for(i=0;i<n;i++)
	   scanf("%lf", &a[i]);
	bubble(a, n);
	for(i=0;i<n;i++)
	   sum=sum+a[i]*(i+1);
	printf("%0.f", sum);
}
