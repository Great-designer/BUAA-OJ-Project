#include<stdio.h>
#include<string.h>
#include<math.h>

#include<queue>

using namespace std;

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}
long long read()
{
	long long k = 0, f = 1;
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
int n, m;
int u[1919810], v[1919810];
long long w[1919810];

struct edge
{
	int next, to;
	long long w;
};

struct Maxflow_ISAP
{
	struct edge edges[1919810 << 1]; //双向边
	int head[2005], cnt;
	void addedge(int u, int v, long long w)
	{
		edges[cnt].next = head[u];
		edges[cnt].to = v;
		edges[cnt].w = w;
		head[u] = cnt++;
		edges[cnt].next = head[v];
		edges[cnt].to = u;
		edges[cnt].w = 0;
		head[v] = cnt++;
	}
	int n;
	int s, t;
	long long maxflow;
	int dep[2005], gap[2005], cur[2005];
	queue<int> q;
	void init(int n)
	{
		this->n = n;
		memset(head, 0xff, sizeof(head));
		while(q.size())q.pop();
		cnt = 0;
		memset(dep, 0, sizeof(dep));
		memset(gap, 0, sizeof(gap));
		memset(cur, 0, sizeof(cur));
		maxflow = 0;
	}

	//gap[i]指深度为i的点的数量
	//cur为当前弧优化
	void bfs()
	{
		for (int i = 0; i < 2005; ++i)
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

	long long dfs(int u, long long flow)
	{
		if (u == t)
		{
			maxflow += flow;
			return flow;
		}
		long long occured = 0;
		for (int& i = cur[u]; i >= 0; i = edges[i].next)
		{
			int v = edges[i].to;
			if (edges[i].w && dep[v] + 1 == dep[u])
			{
				long long d = dfs(v, min(flow - occured, edges[i].w));
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

	long long ISAP(int S, int T)
	{
		this->s = S, this->t = T;
		bfs();
		while (dep[s] < n)
		{
			memcpy(cur, head, sizeof(head));
			dfs(s, 1145141919810114514ll);
		}
		return maxflow;
	}
} solver;

struct edge edges[1919810 << 1];
int head[505], cnt;
long long dis[505];
long long c;
bool vis[505];
void addedge(int u, int v, long long w)
{
	edges[cnt].next = head[u];
	edges[cnt].to = v;
	edges[cnt].w = w;
	head[u] = cnt++;
	edges[cnt].next = head[v];
	edges[cnt].to = u;
	edges[cnt].w = w;
	head[v] = cnt++;
}
void init()
{
	memset(head, 0xff, sizeof(head));
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; ++i) dis[i] = 1145141919810114514ll;
}
struct node
{
	int v;
	long long w;
	node(int _v = 0, long long _w = 0)
	{
		v = _v, w = _w;
	}
	bool operator < (const node & o) const
	{
		return o.w < w;
	}
};
priority_queue<node> q;
void dijkstra(int s, long long* d)
{
	while(!q.empty()) q.pop();
	d[s] = 0;
	q.push(node(s, 0));
	while(!q.empty())
	{
		node tmp = q.top();
		q.pop();
		int u = tmp.v;
		if(vis[u])continue;
		vis[u] = true;
		for(int i = head[u]; ~i; i = edges[i].next)
		{
			int v = edges[i].to;
			long long w = edges[i].w;
			if(!vis[v] && d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				q.push(node(v, d[v]));
			}
		}
	}
}
int main()
{
	n = read(), m = read();
	solver.init(n << 1);
	init();
	for(int i = 1; i <= m; ++i)
	{
		u[i] = read(), v[i] = read(), w[i] = read();
		addedge(u[i], v[i], w[i]);
	}
	dijkstra(1, dis);
	for(int i = 1; i <= m; ++i)
	{
		if(dis[u[i]] + w[i] == dis[v[i]]) solver.addedge(u[i] + n, v[i], 1145141919810114514ll);
		if(dis[v[i]] + w[i] == dis[u[i]]) solver.addedge(v[i] + n, u[i], 1145141919810114514ll);
	}
	for(int i = 1; i <= n; ++i)
	{
		c = read();
		if(i != 1 && i != n) solver.addedge(i, i + n, c);
		else solver.addedge(i, i + n, 1145141919810114514ll);
	}
	write(solver.ISAP(1, n << 1));
}
