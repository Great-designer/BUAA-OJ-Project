#include<stdio.h>
#include<string.h>

#include<queue>

using namespace std;

struct edge
{
	int next, to, w;
};

struct edge edges[100010 << 1]; //双向边
int head[10010], cnt;

void addEdge(int u, int v, int w)
{
	edges[cnt].next = head[u];
	edges[cnt].to = v;
	edges[cnt].w = w;
	head[u] = cnt++;
}

int dis[10010], gap[10010], cur[10010];
queue<int> q;
//gap[i]指深度为i的点的数量
//cur为当前弧优化
void bfs(int t)
{
	for (int i = 0; i < 10010; ++i)
	{
		dis[i] = -1;
		gap[i] = 0;
	}
	q.push(t);
	dis[t] = 0, gap[0] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i >= 0; i = edges[i].next)
		{
			int v = edges[i].to;
			if (dis[v] != -1)continue;
			q.push(v);
			dis[v] = dis[u] + 1, gap[dis[v]]++;
		}
	}
}

int maxflow;

int dfs(int num,int start,int end,int u,int flow)
{
	if (u == end)
	{
		maxflow += flow;
		return flow;
	}
	int occured = 0;
	int i;
	for (i = cur[u]; i >= 0; i = edges[i].next)
	{
		int v = edges[i].to;
		if (edges[i].w && dis[v] + 1 == dis[u])
		{
			int d = dfs(num,start,end,v,min(flow - occured, edges[i].w));
			if (d > 0)
			{
				edges[i].w -= d;
				edges[i ^ 1].w += d;
				occured += d;
			}
			if (occured == flow)
			{
				return occured;
			}
		}
	}
	//前面和dinic一样
	//后面表示所有点都流过了而且还有剩余
	--gap[dis[u]];
	if (!gap[dis[u]])
	{
		dis[start] = num + 1;
	}
	dis[u]++;
	gap[dis[u]]++;
	return occured;
}

void ISAP(int num,int start,int end)
{
	bfs(end);
	while (dis[start] < num)
	{
		memcpy(cur, head, sizeof(head));
		dfs(num,start,end,start,0x3f3f3f3f);
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(head, -1, sizeof(head));
	int i;
	for (i = 1; i <= m; ++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);//无向图权值一样，有向图是0
	}
	ISAP(n,1,n);
	printf("%d\n", maxflow);
}
