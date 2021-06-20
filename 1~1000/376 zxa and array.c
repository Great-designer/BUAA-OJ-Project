#include<stdio.h>
#include<stdlib.h>

long long a[1100];
int n;

int compare(const void*a,const void*b)
{
	return *(long long*)a>*(long long*)b?1:-1;
}

int main()
{
    while(~scanf("%d",&n))
    {
    	int i;
        for(i=1;i<=n;i++)
        {
        	scanf("%lld",&a[i]);
		}
        qsort(a+1,n,sizeof(long long),compare);
        long long ans=a[1];
        for(i=2;i<=n;i++)
        {
        	ans=(ans*((a[i]-i+1)>0LL?(a[i]-i+1):0LL))%1000000007;
		}
        printf("%lld\n",ans);
    }
    return 0;
}

