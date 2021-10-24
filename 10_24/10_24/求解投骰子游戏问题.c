#include<stdio.h>
long long fun(int x)
{
	if(x == 1)
		return 1;
	else
		return 2*fun(x-1);
}

int main()
{
	int x = 0;
	while(~scanf("%d", &x))
	{
		printf("%lld\n", fun(x));
	}
	return 0;
}
