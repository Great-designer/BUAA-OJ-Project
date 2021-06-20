#include<stdio.h>

int main()
{
	int t;
	long long a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&a);
		long long b=a%65536;
		long long c=a/65536;
		b=b*65536+c;
		printf("%lld\n",b);
	}
}
