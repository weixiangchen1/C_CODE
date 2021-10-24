#include <stdio.h>
int fun(int x, int n)
{
	if(x == 0)
	{
		return 0;
	}
	else
	{
		return x%n+fun(x/n, n);
	}
}
int main()
{
	int i = 0;
	int n = 0;
	int x = 0;
	int count = 0;
	while(~scanf("%d", &n))
	{
		count = 0;
		for(i=0; i<=n; i++)
		{
			if(fun(i,10) == fun(i,2))
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
