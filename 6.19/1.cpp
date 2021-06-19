#include <stdio.h>
void transform (int a[], int n);
int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	int a[10000];
	for(i=0;i<n;i++)
	   scanf("%d", &a[i]);
	for(i=0;i<m;i++)
	   transform(a, n);
	for(i=0;i<n-1;i++)
	   printf("%d ", a[i]);
	printf("%d", a[i]); 
 } 
void transform(int a[], int n)
{
	int i;
	int x = a[n-1];
	for(i=n-1;i>=0;i--){
	a[i] = a[i-1];	
	}	a[0]= x;
}
 
