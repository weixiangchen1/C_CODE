#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int is_prime(int x)
{
	int flag = 1;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			flag = 0;
		}
	}
	return flag;
}
int main()
{
	int n, m;
	int count = 0;
	scanf("%d%d", &n, &m);
	while (1)
	{
		for (int i = 2; count <= m; i++)
		{
			if (is_prime(i) == 1)
			{
				n--;
			}
			if (is_prime(i) == 1 && n <= 0)
			{
				printf("%d ", i);
				count++;
			}
			if (count % 10 == 0)
			{
				printf("\n");
			}
			if (count == m)
				break;
		}
		break;
	}

	return 0;
}