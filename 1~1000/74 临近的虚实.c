#include<stdio.h>

int main()
{
	int hour,minute,second;
    while(~scanf("%d:%d:%d",&hour,&minute,&second))
    {
    	if(hour<0||hour>23)
    	{
    		printf("No\n");
		}
		else if(minute<0||minute>59)
    	{
    		printf("No\n");
		}
		else if(second<0||second>59)
    	{
    		printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}

