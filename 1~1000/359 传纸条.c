#include<stdio.h>
#include<string.h>

int mask[51][51];
long long dp[51][51][51];

int n,m;

void erase()
{
	memset(mask,0,sizeof(mask));
	memset(dp,0,sizeof(dp));
}

long long max(long long a,long long b,long long c,long long d)
{
	if(a>=b&&a>=c&&a>=d)
	{
		return a;
	}
	if(b>=a&&b>=c&&b>=d)
	{
		return b;
	}
	if(c>=a&&c>=b&&c>=d)
	{
		return c;
	}
	if(d>=a&&d>=b&&d>=c)
	{
		return d;
	}
}

void buildDP()
{
	dp[1][1][1]=1ll*mask[1][1];
	int i;
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=m;++j)
		{
			int k;
			for(k=1;k<=n&&k<=(i+j);k++)
			{
				int p=i+j-k;
				if(k!=i)
				{
					dp[i][j][k]=mask[i][j]+mask[k][p]+max(dp[i-1][j][k-1],dp[i-1][j][k],dp[i][j-1][k-1],dp[i][j-1][k]);
				}
				else
				{
					dp[i][j][k]=mask[i][j]+max(dp[i-1][j][k-1],dp[i-1][j][k],dp[i][j-1][k-1],dp[i][j-1][k]);
				}
			}
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		erase();
		int i;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=m;++j)
			{
				scanf("%d",&mask[i][j]);
			}
		}
		buildDP();
		printf("%lld\n",dp[n][m][n]);
	}
}
