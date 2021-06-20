#include<stdio.h>
#include<string.h>

char number[100009];

int main()
{
	unsigned int len;	
	while(~scanf("%s",number))
	{		
		len=strlen(number);		
		switch(((len>=2?(number[len-2]-'0')*10:0)+(number[len-1]-'0'))%4)
		{		
			case 0:		
			case 3:			
				printf("0\n");			
				break;		
			case 1:		
			case 2:			
				printf("1\n");		
		}	
	}	
	return 0;
}

