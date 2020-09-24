#include<stdio.h>

long long n,ans,w[2047],v[2047],arr[2047*2];

int main()
{
	while(~scanf("%lld",&n))
	{
		long long i;
		for(i=1;i<=n+2047;i++)
		{
			arr[i]=204700000000000;
		}
		arr[0]=0LL;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&w[i],&v[i]);
			v[i]++;
		}
		for(i=0;i<n;i++)
		{
			long long j;
			for(j=n+2000;j>=v[i];j--)
			{
				arr[j]=(arr[j]<(arr[j-v[i]]+w[i])?arr[j]:(arr[j-v[i]]+w[i]));
			}
		}
		ans=204700000000000;
		for(i=n;i<=n+2000;i++)
		{
			ans=(ans<arr[i]?ans:arr[i]);
		}
		printf("%lld\n",ans);
	}
}


