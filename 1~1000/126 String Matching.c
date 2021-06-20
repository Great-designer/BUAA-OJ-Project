#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{    
	int n;    
	char a[1000005],b[1000005];     
	while(~scanf("%s%s",a,b))
	{        
		char *s=a;        
		n=0;        
		while(s=strstr(s,b))
		{            
			s++;            
			n++;        
		}        
		printf("%d\n",n);    
	}    
	return 0;
}

