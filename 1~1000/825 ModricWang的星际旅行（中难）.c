#include<stdio.h>
#include<string.h>

int dp[65540][20];
int a[20][20];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		n--;
		int i;
		for(i=0;i<=n;i++)
		{
			int j;
			for(j=0;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		int k;
		for(k=0;k<=n;k++)
		{
			for(i=0;i<=n;i++)
			{
				int j;
				for(j=0;j<=n;j++)
				{
					a[i][j]=a[i][j]<(a[i][k]+a[k][j])?a[i][j]:(a[i][k]+a[k][j]);
				}
			}
		}
		int m=(1<<n)-1;
		int S;
		for(S=0;S<=m;S++)
		{
			int i;
			for(i=1;i<=n;i++)
			{
				if(S&(1<<(i-1)))
				{
					if(S==(1<<(i-1)))
					{
						dp[S][i]=a[0][i];
					}
					else
					{
						dp[S][i]=(1<<30);
						int j;
						for(j=1;j<=n;j++)
						{
							if(S&(1<<(j-1))&&j!=i)
							{
								dp[S][i]=dp[S][i]<(dp[S^(1<<(i-1))][j]+a[j][i])?dp[S][i]:(dp[S^(1<<(i-1))][j]+a[j][i]);
							}
						}
					}
				}
			}
		}
		int ans=(1<<31)-1;
		int j;
		for(j=1;j<=n;j++)
		{
			ans=ans<(dp[(1<<n)-1][j]+a[j][0])?ans:(dp[(1<<n)-1][j]+a[j][0]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
