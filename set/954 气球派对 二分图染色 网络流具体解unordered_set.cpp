#include<cstdio>
#include<queue>
#include<cstring>
#include<unordered_set>

int ox(int);
int oy(int);

namespace NetworkFlow
{
	struct edge
	{
		int v;
		long long c;
		edge *n;
		inline void flow(const long long &f);
	} ep[400010 * 2], *el[200005];

	inline void edge::flow(const long long &f)
	{
		c -= f;
		ep[(this - ep) ^ 1].c += f;
	}

	int V, E, epl;

	void addEdge(int u, int v, long long c)
	{
		if(c > 0)
		{
			el[u] = &(ep[epl] = {v, c, el[u]});
			el[v] = &(ep[epl + 1] = {u, 0, el[v]});
			epl += 2;
			++E;
		}
		V = std::max(V, std::max(u, v) + 1);
	}

	void clear(int _V = 200005)
	{
		V = E = epl = 0;
		memset(el, 0, sizeof(edge *) * _V);
	}
}

namespace ISAP
{
	using namespace NetworkFlow;

	edge *pi[200005], *cedge[200005];
	int d[200005], cntd[200005], S, T;

	void revBFS()
	{
		std::queue<int> q;
		memset(cntd, 0, sizeof(int) * (V + 1));

		std::fill(d, d + V, V);
		d[T] = 0;
		cntd[V] = V - 1;
		cntd[0] = 1;

		q.push(T);
		int u;
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			for(edge *e = el[u]; e; e = e->n)
				if(ep[(e - ep) ^ 1].c > 0 && d[e->v] >= V)
				{
					--cntd[d[e->v]];
					++cntd[d[e->v] = d[u] + 1];
					q.push(e->v);
				}
		}
	}

	long long augment()
	{
		long long f = 0x7fffffffffffffff;
		for(edge *e = pi[T]; e; e = pi[ep[(e - ep) ^ 1].v])
			if(f > e->c)
				f = e->c;
		for(edge *e = pi[T]; e; e = pi[ep[(e - ep) ^ 1].v])
			e->flow(f);
		return f;
	}

	int relabel(int u)
	{
		int &fm = cntd[d[u]], md = V - 1;
		for(edge *e = el[u]; e; e = e->n)
			if(e->c > 0 && md > d[e->v])
				md = d[e->v];
		--fm;
		++cntd[d[u] = md + 1];
		return fm;
	}

	long long flow;

	long long maxFlow(int _S, int _T)
	{
		S = _S;
		T = _T;
		flow = 0;
		revBFS();
		memcpy(cedge, el, sizeof(edge *) * V);
		pi[S] = NULL;
		for(int u = S; d[S] < V;)
		{
			edge *&e = cedge[u];
			for(; e; e = e->n)
				if(e->c > 0 && d[u] == d[e->v] + 1)
					break;
			if(e)
			{
				pi[e->v] = e;
				u = e->v;
				if(u == T)
				{
					flow += augment();
					u = S;
				}
			}
			else
			{
				e = el[u];
				if(relabel(u) > 0)
				{
					if(u != S)
						u = ep[(pi[u] - ep) ^ 1].v;
				}
				else
				{
					break;
				}
			}
		}
		return flow;
	}
}

typedef long long ll;

int A, B, S, T;

int opos(int x, int y)
{
	return (x + A) * (2 * B + 1) + (y + B);
}
int ox(int p)
{
	return p / (2 * B + 1) - A;
}

int oy(int p)
{
	return p % (2 * B + 1) - B;
}
bool ino(ll x, ll y)
{
	return -A <= x && x <= A && -B <= y && y <= B &&
	       B * (ll)B * x * x + A * (ll)A * y * y <= A * (ll)A * (ll)B * (ll)B;
}
ll oedge(int u, int v, int x, int y)
{
	if(!(u < x || (u == x && v < y)))
	{
		std::swap(u, x);
		std::swap(v, y);
	}
	return opos(u, v) * ll(T + 1) + (ll)opos(x, y);
}
const int dxy[4][2] =
{
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

std::unordered_set<ll> de;
int cl[200005];

void build()
{
	memset(cl, 0, sizeof(int) * (T + 1));
	std::queue<int> q;
	q.push(opos(0, 0));
	cl[opos(0, 0)] = 1;
	while(!q.empty())
	{
		int x = ox(q.front()), y = oy(q.front()), o = q.front();
		q.pop();
		for(int i = 0, u, v, p; i < 4; ++i)
		{
			u = x + dxy[i][0];
			v = y + dxy[i][1];
			p = opos(u, v);
			if(!ino(u, v))
				continue;
			if(de.find(oedge(u, v, x, y)) == de.end())
			{
				if(cl[o] == 1)
					NetworkFlow::addEdge(o, p, 1);
			}
			if(!cl[p])
			{
				cl[p] = cl[o] == 1 ? 2 : 1;
				q.push(p);
			}
		}
	}
}

bool vis[200005];

void resColor()
{
	memset(vis, 0, sizeof(bool) * (T + 1));
	std::queue<int> q;
	q.push(S);
	vis[S] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(NetworkFlow::edge *e = NetworkFlow::el[u]; e; e = e->n)
		{
			if(e->c && !vis[e->v])
			{
				q.push(e->v);
				vis[e->v] = 1;
			}
		}
	}
}

inline int read()
{
	char c=getchar_unlocked();
	int f=1,num=0;
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9')
		num=(num<<3)+(num<<1)+c-'0',c=getchar_unlocked();
	return num*f;
}
inline void write(ll x)
{
	if (x < 0)putchar_unlocked('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar_unlocked(x % 10 + 48);
}

int main()
{
	int t;
	t = read();
	while(t--)
	{
		A = read(), B = read();
		S = opos(-A, -B);
		T = opos(A, B);
		NetworkFlow::clear(T + 1);
		de.clear();
		int m;
		m = read();
		for(int i = 0, u, v, x, y; i < m; ++i)
		{
			u = read(), v = read(), x = read(), y = read();
			de.insert(oedge(u, v, x, y));
		}
		build();
		for(int i = 0; i <= T; ++i)
		{
			if(cl[i] == 1)
				NetworkFlow::addEdge(S, i, 1);
			else if(cl[i] == 2)
				NetworkFlow::addEdge(i, T, 1);
		}
		write(ISAP::maxFlow(S, T)), putchar_unlocked('\n');
		resColor();
		for(int i = T; i >= 0; --i)
			if((cl[i] == 1 && !vis[i]) || (cl[i] == 2 && vis[i]))
			{
				write(ox(i)), putchar_unlocked(' '), write(oy(i)), putchar_unlocked('\n');
			}
		putchar_unlocked('\n');
	}
	return 0;
}
