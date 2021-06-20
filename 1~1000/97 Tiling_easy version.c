#include<stdio.h>

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		double e=1ll<<(n+1);
		long long f=(long long)(e/3+0.5);
		printf("%lld\n",f);
	}
	return 0;
}

