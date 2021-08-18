#include<stdio.h>
#include<string.h>

#include<queue>

using namespace std;

//须留意:多次查询的时候
//每次查询都会破坏原有路径的流量
//所以要存好原有路径，每次都把流注入进去
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
int query;
long long maxflow;

struct edge
{
	int next, to, w;
};

struct edge edges[100010 << 1],total_edges[10010]; //双向边
int head[10010], cnt;

void addEdge(int u, int v, int w)
{
	total_edges[cnt].next = head[u];
	total_edges[cnt].to = v;
	total_edges[cnt].w = w;
	head[u] = cnt++;
}

void saveEdge()
{
	for (int i = 0; i < cnt; ++i)
	{
		edges[i].next = total_edges[i].next;
		edges[i].to = total_edges[i].to;
		edges[i].w = total_edges[i].w;
	}
}

int dep[10010], gap[10010], cur[10010];
queue<int> q;
//gap[i]指深度为i的点的数量
//cur为当前弧优化

void bfs()
{
	for (int i = 0; i < 10010; ++i)
	{
		dep[i] = -1;
		gap[i] = 0;
	}
	q.push(t);
	dep[t] = 0, gap[0] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i >= 0; i = edges[i].next)
		{
			int v = edges[i].to;
			if (dep[v] != -1)continue;
			q.push(v);
			dep[v] = dep[u] + 1, gap[dep[v]]++;
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
		if (edges[i].w && dep[v] + 1 == dep[u])
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
	--gap[dep[u]];
	if (!gap[dep[u]])dep[s] = n + 1;
	dep[u]++;
	gap[dep[u]]++;
	return occured;
}

void ISAP(int s)
{
	bfs();
	while (dep[s] < n)
	{
		memcpy(cur, head, sizeof(head));
		dfs(s, 0x3f3f3f3f);
	}
}

int main()
{
	while (scanf("%d%d%d", &n, &m, &query) != EOF)
	{
		memset(head, -1, sizeof(head));
		memset(total_edges, 0, sizeof(total_edges));
		cnt = 0;
		int u, v, w;
		for (int i = 1; i <= m; ++i)
		{
			u = read(), v = read(), w = read();
			if (w)
			{
				addEdge(u, v, w);
				addEdge(v, u, 0);//无向图权值一样，有向图是0
				//如果边权为0则在计算网络流的时候应当视为不存在
			}
		}
		while (query--)
		{
			maxflow = 0;
			saveEdge();
			while (!q.empty())q.pop();
			s = read(), t = read();
			ISAP(s);
			printf("%lld\n", maxflow);
		}
	}
}