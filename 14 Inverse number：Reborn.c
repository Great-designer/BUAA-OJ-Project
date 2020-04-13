#include<stdio.h>
#include<stdlib.h>

int a[1000005],b[1000005];
long long ans;

void mergesort(int l,int r)
{
    if(l==r)
	{
		return;
	}
    int mid=(l+r)/2;
    mergesort(l,mid);
	mergesort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
		{
			b[k++]=a[i++];
		}
        else 
        {
            b[k++]=a[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)
	{
		b[k++]=a[i++];
	}
    while(j<=r)
	{
		b[k++]=a[j++];
	}
	int t;
    for(t=l;t<=r;++t)
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
        for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
        mergesort(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}
