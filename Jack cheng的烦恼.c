#include <stdio.h>
#include <math.h>
int main()
{
	int a[100];
	int n, m, i;
	int len = 0;
	scanf("%d%d", &n, &m);
	if(m == 2)
	{
		while(n)
		{
			a[len++] = n % 2;
			n /= 2;
		}
		for(i = len - 1; i >= 0; i--)
		    printf("%d", a[i]);
	}
	
	if(m == 10)
	{
		int sum = 0;
		int cnt = 0;
		while(n)
		{
			sum += (n % 10) * pow(2, cnt++);
			n /= 10;
		}
		printf("%d", sum);
	}
	return 0;
}
