#include<stdio.h>

long long AmulBmodP(long long a,long long b,long long c)
{
	return (a*(b%c))%c;
}

long long a[100010];
long long ans;
int n;

int main()
{
	while(~scanf("%d",&n))
	{
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%lld",a+i);
		}
		ans=1;
        long long b=a[1],c=a[1]+1,d=(a[1]<<1)+1;
		if(b%2==0)
		{
			b>>=1;
		}
		else
		{
			c>>=1;
		}
		if(b%3==0)
		{
			b/=3;
		}
		else if(c%3==0)
		{
			c/=3;
		}
		else
		{
			d/=3;
		}
		ans=AmulBmodP(ans,b,1000000007);
		ans=AmulBmodP(ans,c,1000000007);
		ans=AmulBmodP(ans,d,1000000007);
		for(i=1;i<=n;++i)
		{
			ans=AmulBmodP(ans,a[i],1000000007);
		}
		printf("%lld\n",ans);
	}
}
