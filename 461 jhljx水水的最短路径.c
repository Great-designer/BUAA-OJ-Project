#include<stdio.h>
#include<string.h>

int n,m,x,y,k;

struct Edge
{
	int v;
	int cost;
};

struct Edge E[100007][107];
int top[100007];

void addedge(int u,int v,int w)
{
	E[u][top[u]].v=v;
	E[u][top[u]].cost=w;
	top[u]++;
}

char vis[100007];
int cnt[100007];
int dist[100007];

int que[400070];
int front,rear;

char SPFA(int start,int n)
{
	memset(vis,0,sizeof(vis));
	int i;
	for(i=1;i<=n;i++)
	{
		dist[i]=0x3f3f3f3f;
	}
	vis[start]=1;
	dist[start]=0;
	front=rear=0;
	que[rear]=start;
	rear=(rear+1)%4000000;
	memset(cnt,0,sizeof(cnt));
	cnt[start]=1;
	while(front!=rear)
	{
		int u=que[front];
		front=(front+1)%4000000;
		vis[u] = 0;
		for(i=0;i<top[u];i++)
		{
			int v=E[u][i].v;
			if(dist[v]>dist[u]+E[u][i].cost)
			{
				dist[v]=dist[u]+E[u][i].cost;
				if(!vis[v])
				{
					vis[v]=1;
					que[rear]=v;
					rear=(rear+1)%4000000;
					if(++cnt[v]>n)
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int i;
		memset(top,0,sizeof(top));
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&k);
			addedge(x,y,k);
			addedge(y,x,k);
		}
		SPFA(1,n);
		for(i=2;i<=n;i++)
		{
			if(dist[i]==0x3f3f3f3f)
			{
				dist[i]=-1;
			}
		}
		for(i=2;i<=n;i++)
		{
			printf("%d ",dist[i]);
		}
		printf("\n");
	}
}

