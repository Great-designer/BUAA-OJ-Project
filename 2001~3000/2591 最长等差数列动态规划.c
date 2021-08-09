#include<stdio.h>
#include<stdlib.h>

short int dp[10005][10005];
int a[10005];

int comp(const void *p1,const void*p2)
{
    int *a=(int *)p1;
    int *b=(int *)p2;
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
	while(~scanf("%d",&n))
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int),comp);
		for(i=0;i<n;++i)
		{
			int j; 
		    for(j=i+1;j<n;++j)
			{
				dp[i][j]=2;
			}
		}
		int ans=2;
		for(i=n-2;i>0;--i)
		{
			int j=i-1;
			int k=i+1;
			while(j>=0&&k<n)
			{
				if(a[j]+a[k]<2*a[i])
				{
					k++;
				}
				else if(a[j]+a[k]>2*a[i])
				{
					j--;
				}
				else
				{
					dp[j][i]=dp[i][k]+1;
					if(dp[j][i]>ans)
					{
						ans=dp[j][i];
					}
					j--;
					k++;
				}
			}
		}
		printf("%d\n",ans);
	}
}

