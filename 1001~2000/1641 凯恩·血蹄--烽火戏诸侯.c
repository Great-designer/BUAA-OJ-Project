#include<stdio.h>
#include<stdlib.h>

struct tower
{
    int loc;
    int v;
};

struct tower a[200005];

int compare(const void*p1,const void*p2)
{
	return(*(struct tower*)p2).loc<(*(struct tower*)p1).loc?1:-1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i; 
    for(i=0;i<n;i++)
    {
    	scanf("%d%d",&a[i].loc,&a[i].v);
	}
    qsort(a,n,sizeof(struct tower),compare);
    long long ans=0;
    int minv=a[0].v;
    for(i=1;i<n-1;i++)
	{
        ans+=(long long)minv*(a[i].loc-a[i-1].loc);
        minv=((minv<a[i].v)?minv:a[i].v);
    }
    ans+=(long long)minv*(a[n-1].loc-a[n-2].loc);
    printf("%lld\n",ans);
}
