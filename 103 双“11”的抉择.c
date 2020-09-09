#include<stdio.h>
#include<string.h>

int n,m,MOD;
int a[1010];

int dp[2][1010];
int now,pre;

void buildDP()
{
	memset(dp,0,sizeof(dp));
	pre=0;
	now=1;
	dp[pre][0]=dp[now][0]=1;
	int i;
	for(i=1;i<=n;++i)
	{
		dp[now][0]=1;
		int j;
		for(j=1;j<=m;++j)
		{
			if(j>a[i])
			{
				dp[now][j]=(dp[now][j-1]+dp[pre][j]-dp[pre][j-1-a[i]]+MOD)%MOD;
			}
			else
			{
				dp[now][j]=(dp[now][j-1]+dp[pre][j])%MOD;
			}
		}
		now=1-now;
		pre=1-pre;
	}
}

int main()
{
	while(~scanf("%d%d%d",&n,&m,&MOD))
	{
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
		}
		buildDP();
		printf("%d\n",dp[pre][m]);
	}
}
