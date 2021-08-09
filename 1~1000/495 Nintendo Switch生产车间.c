#include<stdio.h>

long long t1[1002][1002];

int compare(const void *p1,const void *p2)
{
	long long *a=(long long*)p1;
	long long *b=(long long*)p2;
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
    int t,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for(i=0;i<n;i++)
        {
        	int j;
            for(j=0;j<m;j++)
            {
            	scanf("%lld",&t1[j][i]);
			}
        }
        long long ans=0;
        for(i=0;i<m;i++)
        {
            long long temp=0x3f3f3f3f3f3f3f3f;
            int j;
            for(j=0;j<n;j++)
            {
            	if(t1[i][j]<temp)
            	{
            		temp=t1[i][j];
				}
			}
            ans+=temp;
        }
        printf("Case #%d: %lld\n",kase++,ans);
    }
}
