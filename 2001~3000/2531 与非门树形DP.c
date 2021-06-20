#include<stdio.h> 

int a[100023],b[100023],c[100023]; 
long long dp[100023][2][2];/*当前在第i个节点，第二维表示与非门工作正常情况下的值，第三维表示与非门实际的值*/

void dfs(int p) 
{
	if(a[p])
	{
		dfs(a[p]);
	} 
	if(b[p]) 
	{
		dfs(b[p]);
	}
	int i;
	for(i=0;i<2;i++)
	{
		int j;
		for(j=0;j<2;j++)
		{
			int k;
			for(k=0;k<2;k++)
			{
				int l;
				for(l=0;l<2;l++)
				{
					int t1=(i&j)^1,t2=(k&l)^1;
					if(c[p]!=-1)
					{
						t2=c[p];
					}
					dp[p][t1][t2]+=dp[a[p]][i][k]*dp[b[p]][j][l];
					dp[p][t1][t2]%=1000000007;
				}
			}
		}
	}
} 

int main() 
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	dp[0][0][0]=dp[0][1][1]=1;
	dfs(1);
	printf("%lld",(dp[1][0][1]+dp[1][1][0])%1000000007); 
}
