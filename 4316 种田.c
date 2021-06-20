#include<stdio.h>

long long x, y;

long long work(long long x, long long y)
{
	if(!x || !y)    return 0;
	if(x < y)   return 4*x*(y/x) + work(x, y%x);
	else    return 4*y*(x/y) + work(x%y, y);
}

int main()
{
	scanf("%lld%lld", &x, &y);
	printf("%lld", work(x, y));
	return 0;
}