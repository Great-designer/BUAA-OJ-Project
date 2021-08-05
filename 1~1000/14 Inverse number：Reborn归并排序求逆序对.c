#include<stdio.h>
#include<stdlib.h>

int a[1000005],b[1000005];
long long ans;

void merge(int lo,int hi)
{
	if(lo==hi)
	{
		return;
	}
	int mid=(lo+hi)/2;
	merge(lo,mid);
	merge(mid+1,hi);
	int lomark=lo;
	int himark=mid+1;
	int bmark=lo;
	while(lomark<=mid||himark<=hi)
	{
		if((himark>hi||a[lomark]<=a[himark])&&lomark<=mid)
		{
			b[bmark++]=a[lomark++];
		}
		else
		{
			b[bmark++]=a[himark++];
			ans+=mid-lomark+1;
		}
	}
	int t;
	for(t=lo; t<=hi; ++t)
	{
		a[t]=b[t];
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ans=0;
		int i;
		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
		}
		merge(0,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}
