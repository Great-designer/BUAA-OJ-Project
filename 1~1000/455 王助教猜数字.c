#include<stdio.h>

int main()
{
    int x,count,n;
    while(~scanf("%d",&x))
	{
        count=0;
        while(~scanf("%d",&n))
		{
            count++;
            if(count>100)
			{
				break;
			}
            else if(n>x)
			{
				printf("greater than actual number\n");
			}
            else if(n<x)
			{
				printf("less than actual number\n");
			}
            else
			{
				printf("you get the number %d\n",x);
                break;
            }
        }
        if(count>100)
		{
			break;
		}
    }
}

