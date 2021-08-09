#include<stdio.h>

long long a[100005];

int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i;
		long long ans=0;
		long long min=0x3f3f3f3f;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			ans+=a[i];
			if(a[i]<min)
			{
				min=a[i];
			}
		}
		ans+=min*(n-2);
		printf("%lld\n",ans);
	}
}
