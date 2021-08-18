#include<stdio.h>
#include<string.h>
#include<math.h>

#include<algorithm>
#include<queue>

using namespace std;

struct edge
{
	int next, to, w;
};

struct Maxflow_ISAP
{
	struct edge edges[1010000 << 1]; //双向边
	int head[2500], cnt;
	void addedge(int u, int v, int w)
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
	int maxflow;
	int dep[2500], gap[2500], cur[2500];
	queue<int> q;
	void init(int n)
	{
		this->n = n;
		memset(head, -1, sizeof(head));
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
		for (int i = 0; i < 2500; ++i)
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

	int ISAP(int S, int T)
	{
		this->s = S, this->t = T;
		bfs();
		while (dep[s] < n)
		{
			memcpy(cur, head, sizeof(head));
			dfs(s, 0x3f3f3f3f);
		}
		return maxflow;
	}
} solver;

int n, m, s, t;
int a[1010], b[1010];

void write(int x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

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

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		solver.init(n + m + 2);
		s = n + m + 1, t = s + 1;
		for(int i = 1; i <= n; ++i) a[i] = read(), solver.addedge(s, i, 1);
		for(int i = 1; i <= m; ++i)
		{
			b[i] = read();
			solver.addedge(n + i, t, 1);
			for (int j = 1; j <= n; ++j)
				if(!(b[i] % a[j]))
					solver.addedge(j, n + i, 1);
		}
		write(solver.ISAP(s, t)), putchar('\n');
	}
}
