#include<stdio.h>

int main()
{
    long long x,t;
    while(scanf("%lld",&x)==1)
	{
        t=0;
        while(x!=1&&++t)
		{
			if(x&1)
			{
				x=x*3+1;
			} 
			else
			{
				x/=2;
			} 
		}
        printf("%lld\n",t);
    }
}

