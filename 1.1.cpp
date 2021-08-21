#include <stdio.h>
#include <string.h>
int main()
{
	char s[10000];
	int i, n, count=0;
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		getchar();
		int len=strlen(s);
		for(i=0;i<n;i++){
			if(s[i]=='C'&&s[i+1]=='i'&&s[i+2]=='n'&&s[i+3]=='g'&&s[i+4]=='e'&&s[i+5]=='r'){
				count++;
			}
		}
	}
	printf("%d", count);
 } 
