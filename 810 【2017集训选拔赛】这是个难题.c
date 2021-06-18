#include<stdio.h>
#include<string.h>

struct Edge
{
	int dest;
	int next;
};

struct Edge edge[2007];

int head[1007];

int V1, V2, E1;
int max_v;

int dnt, dfn[1007], low[1007];
int stack[1007], top;
int belong[1007];
int ring[1007];

char vis[1007];
int dep[1007];
int queue[1007];

void Tarjan(const int u, const int fa)
{
	if (max_v >= 5)
		return;

	stack[top++] = u;
	dfn[u] = low[u] = ++dnt;

	for (int i=head[u]; i; i=edge[i].next)
	{
		const int v = edge[i].dest;
		if (v != fa)
		{
			if (!dfn[v])
			{
				Tarjan(v, u);
				if (low[u] > low[v])
					low[u] = low[v];
			}
			else
			{
				if (low[u] > dfn[v])
					low[u] = dfn[v];
			}
		}
	}
	if (dfn[u] == low[u])
	{
		++V2;
		int now = -1;
		while (now != u)
		{
			now = stack[--top];
			belong[now] = V2;
			++ring[V2];
		}
		if (max_v < ring[V2])
			max_v = ring[V2];
	}
}


void read_edge(void)
{
	memset(head+1, 0, sizeof(*head)*V1);
	for (int e=1, EE=2*E1; e<=EE; ++e)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		edge[e].next = head[u];
		edge[e].dest = v;
		head[u] = e;

		edge[++e].next = head[v];
		edge[e].dest = u;
		head[v] = e;
	}
}

int bfs(const int SRC)
{
	int f = -1, h = 0, t = 0;
	memset(vis+1, 0, sizeof(*vis)*V1);
	dep[SRC] = 1;
	queue[t++] = SRC, vis[SRC] = 1;
	while (h != t)
	{
		const int u = queue[h++];
		for (int i=head[u]; i; i=edge[i].next)
		{
			const int v = edge[i].dest;
			if (!vis[v])
			{
				queue[t++] = v, vis[v] = 1;
				dep[v] = dep[u] + 1;
				if (max_v < dep[v])
					max_v = dep[f = v];
				if (max_v >= 5)
					return f;
			}
		}
	}

	return f;
}


int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&V1,&E1);
		dnt = top = V2 = 0;
		max_v = 1;
		memset(dfn+1, 0, sizeof(*dfn)*V1);
		memset(low+1, 0, sizeof(*low)*V1);
		memset(ring+1, 0, sizeof(*ring)*V1);
		read_edge();
		Tarjan(1, 1);	// 连通图，一次 Tarjan 即可求出所有边双连通分量
		if (max_v < 5)
		{
			if (V2 == 1)
				puts("no");
			else
			{
				if (max_v == 4)
					puts("yes");
				else if (max_v == 3)
				{
					int t_cnt = 0, t_index = 0;
					for (int v=1; v<=V2 && t_cnt<2; ++v)
						if (ring[v] == 3)
							++t_cnt, t_index = v;
					if (t_cnt == 2)
						puts("yes");
					else
					{
						if (V2 == 2)
							puts("no");
						else
						{
							int out = 0;
							for (int u=1; u<=V1; ++u)
							{
								if (belong[u] == t_index)
								{
									for (int i=head[u]; i; i=edge[i].next)
										if (belong[edge[i].dest] != t_index)
										{
											++out;
											break;
										}
								}
							}
							puts(out >= 2 ? "yes" : "no");
						}
					}
				}
				else // 本题max_v不会为2，因不含重边。现在只会为1，即整个图是一棵无向树。
				{
					int f1 = bfs(1);
					if (max_v >= 5)
						puts("yes");
					else
					{
						bfs(f1);
						puts(max_v >= 5 ? "yes" : "no");
					}
				}
			}
		}
		else puts("yes");
	}
}
