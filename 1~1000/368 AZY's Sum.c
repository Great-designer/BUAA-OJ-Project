#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void*a,const void*b)
{
	return *(int*)a>*(int*)b?1:-1;
}

int a[751][751];
int pos[751];
int n;
int mid;
int sum;
int ans[1000];
int cnt=0;

void dfs(int i)
{
    if(sum>mid)
	{
		return;
	}
    ans[cnt++]=sum;
    if(cnt>n)
	{
        return;
    }
    for(;i<n&&cnt<n;i++)
    {
        if(pos[i]==n-1)
		{
			continue;
		}
        ++pos[i];
        sum+=a[i][pos[i]]-a[i][pos[i]-1];
        dfs(i);
        sum-=a[i][pos[i]]-a[i][pos[i]-1];
        --pos[i];
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
    	int i;
        for(i=0;i<n;i++)
        {
        	int j;
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
        for(i=0;i<n;i++)
        {
        	qsort(a[i],n,sizeof(int),compare);
		}
        memset(pos,0,sizeof(pos));
        int l=-1,r=n*1000000;
        while(r-l>1)
        {
            sum=0;
            for(i=0;i<n;i++)
            {
            	sum+=a[i][0];
			}
            cnt=0;
            mid=(l+r)/2;
            dfs(0);
            if(cnt>=n)
			{
				r=mid;
			}
            else
			{
				l=mid;
			}
        }
        cnt=0;
        sum=0;
        for(i=0;i<n;i++)
        {
        	sum+=a[i][0];
		}
        mid=r-1;
        dfs(0);
        qsort(ans,cnt,sizeof(int),compare);
        for(i=0;i<cnt;i++)
        {
        	printf("%d ",ans[i]);
		}
        for(i=cnt;i<n-1;i++)
        {
        	printf("%d ",r);
		}
        printf("%d\n",r);
    }
}

