#include <stdio.h>
#include <string.h>
int main()
{
	int n, i;
	int cnt1 = 0;
	int cnt2 = 0;
	int flag = 0;
	char ch[100000];
	scanf("%d", &n);
	getchar();
	gets(ch);
	for(i=0; i<n; i++)
	{
		if(n % 2 != 0)
	    {
	    	flag = 1;
	    	break;
		}
		if(ch[i] == '(')
		{
			cnt1++;
			continue;
		}
		if(ch[i] == ')')
		{
			cnt1--;
			continue;
		}
		if(ch[i] == '{')
		{
			cnt2++;
			continue;
		}
		if(ch[i] == '}')
		{
			cnt2--;
			continue;
		}
	}
	if(!cnt1 && !cnt2 && !flag)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	return 0;
}
