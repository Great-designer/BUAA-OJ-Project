#include<stdio.h>
#include<string.h>

int m,n;
int M[201][201];
int dp[2][201][201];

int MAX(int a,int b,int c,int d) 
{
    int minAns=a;
    if(minAns<b)
	{
		minAns=b;
	} 
    if(minAns<c)
	{
		minAns=c;
	} 
    if(minAns<d)
	{
		minAns=d;
	} 
    return minAns;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0,sizeof(dp));
        int i;
        for(i=1;i<=n;i++)//发现每一步只与前一步有关，可以滚动数组，把一维滚动掉。
        {
        	int j;
        	for(j=1;j<=m;j++)
        	{
        		scanf("%d",&M[i][j]);
			}
		}
        int cur=0;
        for(i=2;i<=n+m;i++) 
		{
            cur^=1;
            int j;
            for(j=1;j<=n&&i-j>=0;j++)
			{
				int k;
                for(k=1;k<=n&&i-k>=0;k++)//下下，下右，右下，右右四者取最大值
				{
                    dp[cur][j][k]=MAX(dp[cur^1][j-1][k-1],dp[cur^1][j][k-1],dp[cur^1][j-1][k],dp[cur^1][j][k]);
                    if(j==k)//走到同一行，必定在同一列，所以确定到A[j][i-j]一点
                    {
                    	dp[cur][j][k]+=M[j][i-j];
					}
                    else//走到不同行，所以确定到A[j][i-j]、A[k][i-k]两点。
                    {
                    	dp[cur][j][k]+=(M[j][i-j]+M[k][i-k]);//右右
					}
                }
            }
        }
        printf("%d\n",dp[cur][n][n]);
    }
    return 0;
}
