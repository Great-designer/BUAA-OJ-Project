#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
#include <unordered_map>

using namespace std;

typedef pair<int, int> PII;
typedef list<PII> blist;
typedef blist::iterator IT;
typedef blist::reverse_iterator RIT;

inline void write(long long x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
}

inline int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int t;
int n;
int u, v, w;

struct Edge
{
	int to, next;
} edges[100010];
int head[100010], cnt;
int fa[100010], we[100010], de[100010];
long long ans;

inline void addEdge(int u, int v, int w)
{
	edges[++cnt].to = v;
	edges[cnt].next = head[u];
	head[u] = cnt;
	fa[v] = u, we[v] = w;
}

inline void initGraph()
{
	memset(edges, 0, sizeof(edges));
	memset(head, 0, sizeof(head));
	cnt = 0;
	memset(fa, 0, sizeof(fa));
	memset(we, 0, sizeof(we));
	memset(de, 0, sizeof(de));
}

blist bl[100010];

inline void redefineBlist(blist &b)
{
	if (b.size() <= 1)
		return;
	for (IT i = b.begin(), j; i != b.end(); i = j)
	{
		j = i, ++j;
		while (j != b.end() && j->first == i->first)
			b.erase(j), j = i, ++j;
	}
}

unordered_map<int, int> a;

void dfs(int u)
{
	int prev_mp = -1;
	if (u > 1)
	{
		blist &b = (bl[u] = bl[fa[u]]);
		for (IT i = b.begin(); i != b.end(); ++i)
			i->first &= we[u];
		b.push_back(make_pair(we[u], de[u]));
		redefineBlist(b);

		if (a.count(we[u]))
			prev_mp = a[we[u]];
		a[we[u]] = de[u];

		int l, r = de[u] + 1, pos;
		for (RIT i = b.rbegin(); i != b.rend(); ++i)
		{
			l = i->second;
			if (a.count(i->first))
			{
				pos = a[i->first];
				if (l <= pos && pos <= r)
					ans += pos - l + 1;
			}
			r = l;
		}
	}
	for (int i = head[u]; i; i = edges[i].next)
	{
		de[edges[i].to] = de[u] + 1;
		dfs(edges[i].to);
	}
	if (u > 1)
	{
		if (prev_mp >= 0)
			a[we[u]] = prev_mp;
		else
			a.erase(we[u]);
	}
}

int main()
{
	t = read();
	while (t--)
	{
		n = read();
		initGraph();
		ans = 0;
		for (int i = 1; i < n; ++i)
		{
			v = read(), u = read(), w = read();
			addEdge(u, v, w);
		}
		dfs(1);
		write(ans), putchar('\n');
	}
}
