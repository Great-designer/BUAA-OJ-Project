#include<stdio.h>
#include<string.h>

int ans;
int g[2010][2010];
int gtop[2010];

char occur[2010];

int n,op;

void eraseMap()
{
	memset(gtop,0,sizeof(gtop));
	memset(occur,0,sizeof(occur));
}

void dfs(int x,int dis)
{
	if(dis>ans)
	{
		ans=dis;
	}
	occur[x]=1;
	int a;
	for(a=0;a<gtop[x];a++)
	{
		if(!occur[g[x][a]])
		{
			dfs(g[x][a],dis+1);
		}
	}
}

int main()
{
	while(~scanf("%d",&n))
	{
		ans=0;
		eraseMap();
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&op);
			if(op==-1)
			{
				g[0][gtop[0]]=i;
				gtop[0]++;
			}
			else
			{
				g[op][gtop[op]]=i;
				gtop[op]++;
			}
		}
		dfs(0,0);
		printf("%d\n",ans);
	}
}

