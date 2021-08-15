#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int h = 0;
	int n, u, d;
	int time = 0;
	scanf("%d%d%d", &n, &u, &d);
	while (1)
	{
		h = h + u;
		time++;
		if (h >= n)
			break;
		h = h - d;
		time++;
	}
	printf("%d\n", time);

	return 0;
}