#include <stdio.h>
int main()
{
	int d1, d2, D1, D2;
	scanf("%d%d", &d1, &d2);
	int i, n;
	scanf("%d", &n);
	int x, y, a, b;
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d", &a, &x, &b, &y);
		if(a+b==x) D1++;
		if(a+b==y) D2++;
		if(d1>=D1)
		printf("A\n%d", D2);
		break;
		if(d2>=D2)
		printf("B\n%d", D1);
		break;
	}

    return 0;
}
