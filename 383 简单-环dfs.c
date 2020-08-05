#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int g[110][1010];
int top[110];

int n,m;
int u,v;
char flag;

char occur[110];

char dfs(int u)
{
	occur[u]=1;
	int v;
	for(v=0;v<top[u];v++)
	{
		if(occur[g[u][v]]==1||(occur[g[u][v]]==0&&!dfs(g[u][v])))
		{
			return 0;
		}
	}
	occur[u]=2;
	return 1;
}

char check()
{
	int i;
	for(i=1;i<=n;++i)
	{
		if(occur[i]==0&&!dfs(i))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		flag=1;
		memset(occur,0,sizeof(occur));
		memset(top,0,sizeof(top));
		while(m--)
		{
			scanf("%d%d",&u,&v);
			g[u][top[u]]=v;
			top[u]++;
		}
		puts(check()?"no":"yes");
	}
}
