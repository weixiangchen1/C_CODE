#include <stdio.h>
int fun(int x)
{
	if(x == 1)
		return 3;
	else if(x == 2)
		return 8;
	else
		return 2*fun(x-1) + 2*fun(x-2);
}

int main()
{
	int x = 0;
	while(~scanf("%d", &x))
	{
		printf("%d\n", fun(x));
	}
	
	return 0;
}
