#include<stdio.h>
#include<stdlib.h>

long long a[10005];

int compare(const void *p1,const void *p2)
{
	long long *a=(long long *)p1;
	long long *b=(long long *)p2;
	if(*a>*b)
	{
	    return 1;
	}
	else if(*a<*b)
	{
	    return -1;
	}
	else
	{
	    return 0;
	}
}

int main()
{
    int n;
	long long ans,s;
    while(~scanf("%d",&n))
	{
        ans=s=0;
        int i;
        for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
        qsort(a,n,sizeof(long long),compare);
        for(i=0;i<n;i++)
		{
            s+=a[i];
            ans+=s;
        }
        printf("%lld\n",ans);
    }
}

