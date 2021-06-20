#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long a,b,p;
		scanf("%lld%lld%lld",&a,&b,&p);
		a=a%p;
		b=b%p;
		long long c=a*b;
		c=c%p;
		printf("%lld\n",c); 
	}
}

