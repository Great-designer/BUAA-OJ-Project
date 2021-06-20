#include<stdio.h>

long long a[1010];

int main()
{
	a[0]=1;
	a[1]=1;
	long long i;
	for(i=2;i<1005;i++)
	{
		a[i]=(a[i-2]*i)%10000007;
	}
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
}

