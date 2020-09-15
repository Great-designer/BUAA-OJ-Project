#include<stdio.h>
#include<string.h>

long long invpair(int a[],int n)
{
	if(n==1||n==0)
	{
		return 0;
	}
	long long sum=0;
	int mid=n/2;
	sum+=invpair(a,mid);
	sum+=invpair(a+mid,n-mid);
	int b[n+3];
	memcpy(b,a,n*sizeof(int));
	int i1,i2,i;
	for(i1=0,i2=mid,i=0;i1<mid||i2<n;++i)
	{
		if(i2==n)
		{
			a[i]=b[i1];            
			++i1;            
			sum+=i2-mid;        
		}
		else if(i1==mid)
		{
			a[i]=b[i2];
			++i2;
		}
		else if(b[i1]<=b[i2])
		{
			a[i]=b[i1];
			++i1;
			sum+=i2-mid;
		}
		else
		{
			a[i]=b[i2];
			++i2;
		}
	}
	return sum;
}

int n,k,l,r;
int nums[10007],back[10007];

int main()
{    
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&nums[i]);
		}
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d",&l,&r);
			memcpy(back,nums+l,(r-l+1)*sizeof(int));
			printf("%lld\n",invpair(back,r-l+1));
		}
	}
}

