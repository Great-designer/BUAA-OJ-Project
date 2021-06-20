#include<stdio.h>
#include<string.h>

#include<queue>

using namespace std;

int read()
{
	int k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

priority_queue<int> g[1010];

bool occur[1010];

int t;
int tmpA,tmpB;
int k,m;

void eraseMap()
{
	int i;
	for(i=0;i<1010;++i)
	{
		while(!g[i].empty())
		{
			g[i].pop();
		}
	}
	memset(occur,0,sizeof(occur));
}

void dfs(int x)
{
	occur[x]=true;
	printf("%d ",x);
	while(!g[x].empty())
	{
		int u=-g[x].top();
		if(!occur[u])
		{
			dfs(u);
		}
		g[x].pop();
	}
}

int main()
{
	t=read();
	while(t--)
	{
		eraseMap();
		k=read();
		m=read();
		while(m--)
		{
			tmpA=read();
			tmpB=read();
			g[tmpA].push(-tmpB);
			g[tmpB].push(-tmpA);
		}
		dfs(0);
		printf("\n");
	}
}
