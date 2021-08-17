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
	struct edge edges[1005 << 1]; //双向边
	int head[205], cnt;
	void addedge(int u, int v, int w)
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
	int n;
	int s, t;
	int maxflow;
	int dep[205], gap[205], cur[205];
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
		for (int i = 0; i < 205; ++i)
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
};

struct Maxflow_ISAP solver;
int u[105], v[105], w[105];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i = 1; i <= m; ++i)
	{
		solver.init(n);
		for(int j = 1; j <= m; ++j)
			if(w[j] < w[i])
				solver.addedge(u[j], v[j], 1);
		printf("%d ",solver.ISAP(u[i],v[i]));
	}
}
