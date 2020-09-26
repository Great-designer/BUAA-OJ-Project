#include<stdio.h>

long long a[100010];

void init()
{
	a[0]=0;
	a[1]=a[2]=1;
	a[3]=2;
	a[4]=3;
	int i;
	for(i=5;i<100010;++i)
	{
		a[i]=(a[i-1]+a[i-2]);
	}
}

int n;

int main()
{
	init();
	while(~scanf("%d",&n))
	{
		printf("%lld\n",a[n]);
	}
}

