#include<stdio.h>

int main()
{
	long long a,b,c,m;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&m);
	printf("%lld\n",(a+b)%m*(c%m)%m);
}