#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int arr[100][100] = { 0 };

void f(int n)
{
	int tmp = n;
	int ret = n;
	int x = 0;
	int y = 0;
	int x1 = 0;
	int y1 = 1;
	for (int i = 0; i < n * n; i++)
	{
		x += x1;
		y += y1;
		arr[x][y] = i;
		if (tmp == i)
		{
			if()
		}
	}
}

int main()
{
	
	int n = 0;
	while (~scanf("%d", &n))
	{
		if (n == 0)
		{
			break;
		}
		else
		{
			f(n);
		}
	}
	return 0;
}