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
queue<int> que;

bool occur[1010];

int t;
int tmpA,tmpB;
int k, m;

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
	while(!que.empty())
	{
		que.pop();
	}
	memset(occur,0,sizeof(occur));
}

void bfs()
{
	que.push(0);
	occur[0]=true;
	while(!que.empty())
	{
		int u=que.front();
		printf("%d ",u);
		que.pop();
		while(!g[u].empty())
		{
			int v=-g[u].top();
			g[u].pop();
			if(!occur[v])
			{
				que.push(v);
				occur[v]=true;
			}
		}
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
		bfs();
		printf("\n");
	}
}
