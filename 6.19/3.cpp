#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, k, l, len=0;
	char s[100];
	while(scanf("%s", s)!=EOF)
	{
		char s1[100]={0}; 
	    char s2[100]={0};
		len=strlen(s);
		for(i=0;i<len;i++){
			if(s[i]=='B'||s[i]=='F'||s[i]=='P'||s[i]=='V')
		       s[i]='1';
		    else if(s[i]=='C'||s[i]=='G'||s[i]=='J'||s[i]=='K'||s[i]=='Q'||s[i]=='S'||s[i]=='X'||s[i]=='Z')
		       s[i]='2';
		    else if(s[i]=='D'||s[i]=='T')
		       s[i]='3';
		    else if(s[i]=='L')
		       s[i]='4';
		    else if(s[i]=='M'||s[i]=='N')
		       s[i]='5';
		    else if(s[i]=='R')
		       s[i]='6';
			else s[i]='7';
		 	}
		 k=0;	
		s1[0]=s[0];
		for(i=1,j=1;i<=len;i++)
		   if(s[i]!=s[i-1])
		     s1[j++]=s[i];
	    for(i=0;i<j;i++)
	       if(s1[i]!='7')
	         s2[k++]=s1[i];
		for(i=0;i<k;i++)
		   printf("%c", s2[i]);	
		printf("\n");
	}
}
    

		
