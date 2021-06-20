#include<stdio.h>

unsigned long long n;

int main()
{
	while(~scanf("%llu",&n))
	{
		int res=0;
		while(n)
		{
			n=n&(n-1);
			res++;
		}
		if(res==1)
		{
			puts("GzhIsSoHandsome");
		}
		else
		{
			puts("GzhIsHandsome");
		}
	}
}

