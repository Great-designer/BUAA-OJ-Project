#include<stdio.h>

int main()
{
    int n;
    while(~scanf("%d",&n))
	{
		while(n--)
		{
			long long a,b;
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",a-b);
		}
    }
}
