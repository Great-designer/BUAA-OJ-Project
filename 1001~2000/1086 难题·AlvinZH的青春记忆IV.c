#include<stdio.h>
#include<string.h>

int A[10005];
int B[10005];
short int dp[10005];//dp[i]表示以B[i]结尾的LCIS，A的范围是[1~n]

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int ans=0;
		memset(dp,0,sizeof(dp));
		int i;
		for(i=1; i<=n; i++)
		{
			scanf("%d",&A[i]);
		}
		for(i=1; i<=m; i++)
		{
			scanf("%d",&B[i]);
		}
		for(i=1; i<=n; i++)
		{
			int maxx=0;
			int j;
			for(j=1; j<=m; j++)
			{
				if(A[i]==B[j])
				{
					dp[j]=maxx+1;
				}
				if(A[i]>B[j])
				{
					maxx=((maxx>(int)dp[j])?maxx:(int)dp[j]);
				}
			}
		}
		for(i=1; i<=m; i++)
		{
			if(ans<dp[i])
			{
				ans=dp[i];
			}
		}
		printf("%d\n",ans);
	}
}
