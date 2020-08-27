#include<stdio.h>

int n;

int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0)
		{
			puts("0");
		}
		else
		{
			long long a=1;
			int i;
			for(i=1;i<=n;++i)
			{
				a*=(n+i);
				a/=i;
			}
			a/=(n+1);
			printf("%lld\n",a);
		}
	}
}
