#include<stdio.h>

int main()
{
    long long n,m;
    while(scanf("%lld%lld",&n,&m)==2)
	{
		printf("%lld %lld\n",n/m,m*(n/m));
	} 
}

