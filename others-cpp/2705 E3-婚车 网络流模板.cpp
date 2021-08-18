#include<stdio.h>
#include<string.h>

#include<queue>

using namespace std;

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int n, m, s, t;
long long maxflow;

struct edge
{
	int next, to, w;
} edges[100010 << 1]; //双向边

int head[10010], cnt;

void addEdge(int u, int v, int w)
{
	edges[cnt].next = head[u];
	edges[cnt].to = v;
	edges[cnt].w = w;
	head[u] = cnt++;
}

int pre[10010], gap[10010], cur[10010];
queue<int> q;
//gap[i]指深度为i的点的数量
//cur为当前弧优化
void bfs()
{
	memset(gap,0,sizeof(gap));
	memset(pre,-1,sizeof(pre));
	q.push(t);
	pre[t] = 0;
	gap[0] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i >= 0; i = edges[i].next)
		{
			int v = edges[i].to;
			if (pre[v] != -1)
			{
				continue;
			}
			q.push(v);
			pre[v] = pre[u] + 1;
			gap[pre[v]]++;
		}
	}
}

int dfs(int u, int flow)
{
	if (u == t)
	{
		maxflow += flow;
		return flow;
	}
	int occured = 0;
	for (int& i = cur[u]; i >= 0; i = edges[i].next)
	{
		int v = edges[i].to;
		if (edges[i].w && pre[v] + 1 == pre[u])
		{
			int d = dfs(v, min(flow - occured, edges[i].w));
			if (d > 0)
			{
				edges[i].w -= d;
				edges[i ^ 1].w += d;
				occured += d;
			}
			if (occured == flow)return occured;
		}
	}
	//前面和dinic一样
	//后面表示所有点都流过了而且还有剩余
	--gap[pre[u]];
	if (!gap[pre[u]])pre[s] = n + 1;
	pre[u]++;
	gap[pre[u]]++;
	return occured;
}

void ISAP(int s)
{
	bfs();
	while (pre[s] < n)
	{
		memcpy(cur, head, sizeof(head));
		dfs(s, 0x3f3f3f3f);
	}
}

int main()
{
	memset(head, -1, sizeof(head));
	n = read(), m = read();// s = read(), t = read();
	s = 1, t = n;
	int u, v, w;
	for (int i = 1; i <= m; ++i)
	{
		u = read(), v = read(), w = read();
		addEdge(u, v, w);
		addEdge(v, u, w);//无向图权值一样，有向图是0
	}
	ISAP(s);
	printf("%lld\n", maxflow);
}
