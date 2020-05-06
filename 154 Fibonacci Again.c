#include<stdio.h>

int main()
{    
	int n;    
	while(~scanf("%d",&n))    
	{        
		if(n%4==2)            
		{
			printf("yes\n");
		}        
		else            
		{
			printf("no\n");
		}    
	}    
	return 0; 
}

