#include<stdio.h>

long long fib[100]= {1,1};

int main()
{
	int i;
	for(i=2; i<=50; i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	int n;
	scanf("%d",&n);
	printf("%lld %lld",fib[n],fib[n-1]);
	return 0;
}