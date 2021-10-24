#include <stdio.h>
int fun(int x)
{
	if(x == 1)
		return 0;
	else if(x == 2)
		return 1;
	else if(x == 3)
		return 2;
	else
		return fun(x - 1) + fun(x - 2);
}

int main()
{
	int n = 0;
	int x = 0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &x);
		printf("%d\n", fun(x));
	}
	
	return 0;
 } 
