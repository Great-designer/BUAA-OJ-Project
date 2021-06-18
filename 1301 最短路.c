#include <stdio.h>
#include <string.h>

struct Edge
{
	int dest;
	int dist;
	int next;
};

struct Edge edge[300007 * 4];

int head[300007], tot;

void add_edge(int e,int u,int v,int d)
{
	edge[e].next = head[u];
	edge[e].dest = v;
	edge[e].dist = d;
	head[u] = e;
}

int depth[300007], max_depth;

long long dist_src[300007];
char inq[300007];
int _queue[300007 * 10], *queue = _queue + 300007 * 5;

void read_edge(const int V)
{
	memset(head+1, 0, sizeof(*head) * 3 * V);
	tot = 2*(V-1);
	for (int e=1; e<=tot; ++e)
	{
		int u, v, d;
		scanf("%d%d%d",&u,&v,&d);
		add_edge(e, u, v, d);
		++e;
		add_edge(e, v, u, d);
	}
}

void bfs(const int V, const int root)
{
	memset(inq+1, 0, sizeof(*inq) * V);
	inq[root] = 1;
	depth[root] = 1;

	int h = 0, t = 0;
	queue[t++] = root;
	while (h != t)
	{
		const int u = queue[h++];
		for (int i=head[u]; i; i=edge[i].next)
		{
			const int v = edge[i].dest;
			if (!inq[v])
			{
				inq[v] = 1;
				queue[t++] = v;
				depth[v] = depth[u] + 1;
				if (max_depth < depth[v])
					max_depth = depth[v];
			}
		}
	}
}

void add_vertex(int *V, const int k)
{
	const int VV = *V + 2 * (max_depth - 1);
	int k1 = k>>1;
	int k2 = k-k1;
	for (int v=1; v<=*V; ++v)
	{
		const int LU = *V+depth[v]-1, RU = VV-depth[v]+2,
		          LD = *V+depth[v],   RD = VV-depth[v]+1;
		if (depth[v] != 1)
		{
			++tot;
			add_edge(tot, LU, v, k1);
			++tot;
			add_edge(tot, v, RU, k2);
		}
		if (depth[v] != max_depth)
		{
			++tot;
			add_edge(tot, RD, v, k1);
			++tot;
			add_edge(tot, v, LD, k2);
		}
	}
	*V = VV;
}

void spfa(const int V, const int s)
{
	memset(inq+1, 0, sizeof(*inq) * V);
	memset(dist_src+1, 0x3f, sizeof(*dist_src) * V);
	inq[s] = 1;
	dist_src[s] = 0;

	int h = 0, t = 0, q_size = 0;
	queue[t++] = s;
	long long sum;
	while (h != t)
	{
		while (dist_src[queue[h]] * q_size > sum)	// LLL
			queue[t++] = queue[h], ++h;

		const int u = queue[h++];
		inq[u] = 0;
		sum -= dist_src[u], --q_size;

		for (int i=head[u]; i; i=edge[i].next)
		{
			const int v = edge[i].dest;
			const int duv = edge[i].dist;
			if (dist_src[v] > dist_src[u] + duv)
			{
				dist_src[v] = dist_src[u] + duv;
				if (!inq[v])
				{
					inq[v] = 1;
					if (h < t && dist_src[queue[h]] > dist_src[v])	// SLF
						queue[--h] = v;
					else
						queue[t++] = v;
					sum += dist_src[v], ++q_size;
				}
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int _=1; _<=T; ++_)
	{
		int V, k, s, t;
		scanf("%d%d%d%d",&V,&k,&s,&t);
		read_edge(V);
		bfs(V, 1);
		add_vertex(&V, k);	// V changed
		spfa(V, s);

		printf("Case #%d: %lld\n", _, dist_src[t]);
	}
}
