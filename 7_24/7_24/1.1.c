#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap1(int x, int y) {
	int t = 0;
	t = x;
	x = y;
	y = t;
}
void Swap2(int* px, int* py) {
	int t = 0;
	t = *px;
	*px = *py;
	*py = t;
}
int main() {
	int a = 10;
	int b = 20;
	Swap1(a, b);
	printf("Swap1£ºa=%d,b=%d\n", a, b);
	Swap2(&a, &b);
	printf("Swap2£ºa=%d,b=%d\n", a, b);
	return 0;
}
