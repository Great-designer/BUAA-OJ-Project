#include<stdio.h>

long long fastpawer(long long a,int b)
{
	long long r=1;
	while(b>0)
	{
		if(b%2)
		{
			r=(r*a)%1000000007;
		}
		a=(a*a)%1000000007;
		b/=2;
	}
	return r;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		n=n-2;
		int a=(n/3)%500000003;
		long long b=2+(n%3);
		long long c=fastpawer(3,a);
		c=(c*b)%1000000007;
		printf("%lld\n",c);
	}
}
