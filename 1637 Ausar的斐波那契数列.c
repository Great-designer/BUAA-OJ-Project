#include<stdio.h>

long long a[500005];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	int i;
	for(i=3;i<500005;i++)
	{
		a[i]=(a[i-2]+a[i-3])%100000007;
	}
	printf("%lld\n",a[n]);
}
