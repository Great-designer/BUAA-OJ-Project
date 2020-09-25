#include<stdio.h>

int dp[105][105];

void buildDP()
{
	dp[1][1]=1;
	int i;
	for(i=2;i<105;++i)
	{
		dp[1][i]=dp[i][1]=1;
	}
	for(i=2;i<105;++i)
	{
		int j;
		for(j=2;j<i;++j)
		{
			dp[i][j]=((i-j>=j)?dp[i-j][j]:dp[i-j][i-j])+dp[i][j-1];
		}
		dp[i][i]=1+dp[i][i-1];
	}
}

int t,m,n;

int main()
{
	buildDP();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		if(m<n)
		{
			printf("%d\n",dp[m][m]);
		}
		else
		{
			printf("%d\n",dp[m][n]);
		}
	}
}
