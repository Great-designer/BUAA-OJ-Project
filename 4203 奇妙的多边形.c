#include<stdio.h>

long long n, Ans;

int main()
{
	scanf("%lld", &n);
	Ans = n*(n-1)*(n-2)*(n-3)/24;
	printf("%lld", Ans);
	return 0;
}