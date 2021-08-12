#include <stdio.h>
int main()
{
	double h;
	int i, n;
	char x;
	scanf("%d", &n);
	while(n--){
		getchar();
		scanf("%c %lf", &x, &h);
		if(x=='M'){
			printf("%.2f", h/1.09);
		}
		else{
			printf("%.2f", h*1.09);
		} 
	}
}
