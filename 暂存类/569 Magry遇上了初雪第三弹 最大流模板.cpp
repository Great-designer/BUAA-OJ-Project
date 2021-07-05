#include<stdio.h>
#include<string.h>
#include<limits.h>

#include<algorithm>
#include<vector>
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
//此处加上堆优dij来判断是否能到

char occur_dij[10010];
int dis_dij[10010];

struct node
{
	int v, w;
	node(int _v = 0, int _w = 0)
	{
		v = _v;
		w = _w;
	}
	char operator < (const node& a) const
	{
		return a.w < w;//按照权值排序
	}
};

vector<node>g[10010];

void init_dij()
{
	for (int i = 0; i < 10010; ++i)
	{
		g[i].clear();
		occur_dij[i] = 0;
		dis_dij[i] = 0x3f3f3f3f;
	}
}

void dijkstra(int s)
{
	priority_queue<node>q;
	q.push(node(s, 0));
	dis_dij[s] = 0;
	while (!q.empty())
	{
		node tmp = q.top();
		q.pop();
		int v = tmp.v;
		if (occur_dij[v])continue;
		occur_dij[v] = 1;
		for (int i = 0; i < g[v].size(); ++i)
		{
			int v2 = g[v][i].v;
			int w = g[v][i].w;
			if (!occur_dij[v2] && dis_dij[v2] > w + dis_dij[v])
			{
				dis_dij[v2] = w + dis_dij[v];
				q.push(node(v2, dis_dij[v2]));
			}
		}
	}
}

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

void ISAP(int s, int t)
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
	while (scanf("%d%d", &n, &m) != EOF)
	{
		maxflow = 0;
		init_dij();
		memset(head, -1, sizeof(head));
		memset(edges, 0, sizeof(edges));
		cnt = 0;
		s = 1, t = n;
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
			g[u].push_back(node(v, w));
		}
		dijkstra(s);
		if (dis_dij[t] >= 0x3f3f3f3f)
		{
			puts("404 Not Found");
			continue;
		}
		ISAP(s, t);
		printf("%lld\n", maxflow);
	}
}
