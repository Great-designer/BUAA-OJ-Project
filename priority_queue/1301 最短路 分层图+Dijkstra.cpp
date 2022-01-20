#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

inline void write(unsigned long long x)
{
	//if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

inline unsigned long long read()
{
	unsigned long long k = 0;// f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		//if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k;// *f;
}

int T;
unsigned long long n, p, s, t;
unsigned long long u, v, w;
unsigned long long realn;
int Case;

struct Edge
{
	int v;
	unsigned long long w;
	int next;
} edges[1919810];
int head[314514];
int edge_size;

inline void addEdge(int u, int v, unsigned long long w)
{
	edges[++edge_size].v = v;
	edges[edge_size].w = w;
	edges[edge_size].next = head[u];
	head[u] = edge_size;
}

int dep[314514];//记录深度
int maxDepth;
unsigned long long dis[314514];
bool occur[314514];
queue<int>q;//bfs用

struct node
{
	int v;
	unsigned long long w;
	node(int _v = 0, unsigned long long _w = 0)
	{
		v = _v, w = _w;
	}
	bool operator < (const node& o) const
	{
		return o.w < w;
	}
};

priority_queue<node>Q;

inline void init()
{
	for (int i = 1; i < 314514; ++i)dis[i] = 1145141919810171717LL;
	memset(occur, false, sizeof(occur));
	memset(dep, 0, sizeof(dep));
	memset(edges, 0, sizeof(edges));
	memset(head, 0, sizeof(head));
	edge_size = 0;
	while (!q.empty())q.pop();
	while (!Q.empty())Q.pop();
	maxDepth = 1;
}

inline void bfs()
{
	occur[1] = true;//1是根
	dep[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = edges[i].next)
		{
			int v = edges[i].v;
			if (occur[v])continue;
			occur[v] = true;
			dep[v] = dep[u] + 1;
			q.push(v);
			if (maxDepth < dep[v])maxDepth = dep[v];
		}
	}
}

inline void dijkstra(int s)
{
	memset(occur, false, sizeof(occur));
	Q.push(node(s, 0));
	dis[s] = 0;
	while (!Q.empty())
	{
		node tmp = Q.top();
		Q.pop();
		int v = tmp.v;
		if (occur[v])continue;
		occur[v] = true;
		for (int i = head[v]; i; i = edges[i].next)
		{
			int v2 = edges[i].v;
			int w = edges[i].w;
			if (!occur[v2] && dis[v2] > w + dis[v])
			{
				dis[v2] = w + dis[v];
				Q.push(node(v2, dis[v2]));
			}
		}
	}
}

int main()
{
	T = read();
	while (T--)
	{
		init();
		n = read(), p = read(), s = read(), t = read();
		for (unsigned long long i = 1; i < n; ++i)
		{
			//建立普通图
			u = read(), v = read(), w = read();
			addEdge(u, v, w), addEdge(v, u, w);
		}

		bfs();//得到最大的层数之后，建立分层图
		//节点数为n+2*(maxDepth-1)
		//直接确定他们该连哪个额外节点
		//左边表示从本层到下一层，右边表示从下一层到本层
		realn = n + 2 * (maxDepth - 1);
		for (unsigned long long i = 1; i <= n; ++i)
		{
			if (dep[i] != 1)
			{
				addEdge(n + dep[i] - 1, i, p);
				addEdge(i, realn - dep[i] + 2, 0);
			}
			if (dep[i] != maxDepth)
			{
				addEdge(realn - dep[i] + 1, i, p);
				addEdge(i, n + dep[i], 0);
			}
		}
		dijkstra(s);
		printf("Case #"), write(++Case), putchar(':'), putchar(' '), write(dis[t]), putchar('\n');
	}
}
