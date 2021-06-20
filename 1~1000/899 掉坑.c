#include<stdio.h>
#include<string.h>

int M[505][505];//矩阵数据
int dp[505][505];//到达点(i,j)时最大金币个数

int MAX(int i,int j) 
{
    if(dp[i-1][j]>dp[i][j-1])
	{ 
		return dp[i-1][j];
	}
	else
	{
		return dp[i][j-1];
	} 
}

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        memset(dp,-0x3f3f3f3f,sizeof(dp));
        int i;
        for(i=1;i<=n;++i)
        {
        	int j;
        	for(j=1;j<=m;++j)
        	{
        		scanf("%d",&M[i][j]);
			}
		}
        dp[1][1]=M[1][1];
        for(i=1;i<=n;++i)
        {
        	int j;
        	for(j=1;j<=m;++j)
        	{
        		if(dp[i][j]<0)
				{
					dp[i][j]=MAX(i,j)+M[i][j];
				} 
			}
		}
        printf("%d\n",dp[n][m]);
    }
}

