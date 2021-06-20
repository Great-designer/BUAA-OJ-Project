#include<stdio.h>

int fab(int a)
{
	return ((a>=0)?a:-a);
}

int a[200010];
int n;
long long res;

int main()
{
    while(~scanf("%d",&n))
	{
        res=0;
        int i;
        for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
		}
        for(i=1;i<=n;++i)
		{
			res+=fab(a[i]-a[i-1]);
		}
        printf("%lld\n",res);
    }
}
