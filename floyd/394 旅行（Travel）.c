#include<stdio.h>
#include<limits.h>

int n,m,t;
int u,v,w;
long long dp[210][210];
long long res,tmp;

void floyd()
{
	int k;
	for(k=1;k<=n;++k)
	{
		int i;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				dp[i][j]=(dp[i][k]+dp[k][j])<dp[i][j]?(dp[i][k]+dp[k][j]):dp[i][j];
			}
		}
	}
}

int trans[15];
char occur[15];
int route[15];

void dfs(int level)
{
	if(level==t+1)
	{
		tmp+=dp[route[t]][route[t+1]];
		res=(res<tmp)?res:tmp;
		tmp-=dp[route[t]][route[t+1]];
		return;
	}
	int i;
	for(i=1;i<=t;++i)
	{
		if(!occur[i])
		{
			occur[i]=1;
			route[level]=trans[i];
			tmp+=dp[route[level-1]][route[level]];
			dfs(level+1);
			tmp-=dp[route[level-1]][route[level]];
			route[level]=0;
			occur[i]=0;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	trans[0]=route[0]=1;
	trans[t+1]=route[t+1]=n;
	int i;
	for(i=1;i<=t;++i)
	{
		scanf("%d",&trans[i]);
	}
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=n;++j)
		{
			dp[i][j]=(i==j)?0:0x3f3f3f3f;
		}
	}
	for(i=0;i<m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		dp[u][v]=dp[v][u]=(dp[u][v]<w)?dp[u][v]:w;
	}
	floyd();
	res=LLONG_MAX;
	tmp=0;
	dfs(1);
	printf("%lld\n",res);
}
