#include<stdio.h>

int sushu(long long x)
{
    if(x==1)
    {
        printf("jhljx is sangxinbingkuang!\n");
    }
    else
    {
    	int sum=0;
    	long long i;
    	for(i=1;i<=sqrt(x);i++)
    	{
        	if(x%i==0)
        	{
            	sum=sum+1;
        	}
    	}
    	if(sum==1)
    	{
        	printf("jhljx is good!\n");
    	}
    	else
    	{
        	printf("jhljx is sangxinbingkuang!\n");
    	}
    }
}

int main()
{
   long long x;
   while(~scanf("%lld",&x))
    {
       sushu(x);
    }
}

