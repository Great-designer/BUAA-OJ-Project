#include<stdio.h>

int main()
{
	int x; 
    scanf("%d",&x);
    if(x<4)
    {
    	printf("%d\n",x+1);
	}
    else if(x>3&&x<10)
    {
    	printf("5\n");
	}
	else if(x>9&&x<14)
    {
    	printf("%d\n",x-4);
	}
	else if(x>13&&x<20)
    {
    	printf("10\n");
	}
	else if(x>19)
    {
    	printf("%d\n",x-9);
	}
}
