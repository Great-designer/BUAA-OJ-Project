#include<stdio.h>

int dp[510][510];
int p[510][510];
int f[510][510];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
		int i;
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<m;j++)
			{
				scanf("%d",&p[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<n;j++)
			{
				scanf("%d",&f[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			dp[i][0]=p[i][0];
		}
		int j;
		for(j=1;j<m;j++)
		{
			for(i=0;i<n;i++)
			{
				dp[i][j]=p[i][j];
				int ans=0x3f3f3f3f;
				int k;
				for(k=0;k<n;k++)
				{
					int tmp=dp[k][j-1]+f[k][i];
					if(ans>tmp)
					{
						ans=tmp;
					}
				}
				dp[i][j]+=ans;
			}
		}
		int ans=0x3f3f3f3f;
		for(j=0;j<n;j++)
		{
			if(ans>dp[j][m-1])
			{
				ans=dp[j][m-1];
			}
		}
		printf("%d\n",ans);
    }
}

