#include<stdio.h>

long long a[500005];

int main()
{
	int n,x;
	a[1]=1;
	a[2]=1;
	a[3]=1;
	scanf("%d",&n);
	int i;
	for(i=4;i<500005;i++)
	{
		a[i]=(a[i-2]+a[i-3])%100000007;
	}
	while(n--)
	{
		scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
}
