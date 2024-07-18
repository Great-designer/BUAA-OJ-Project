// 不知道为啥, 只有把数组都改成 long long 才能 AC，否则第一个点会 RE ，但是也没找出哪里出错了。
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
int rd()
{
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = 0;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? k : -k;
}
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}
const int N = 100010;
int a[N];
namespace bit
{
    int *rev_dfn;
    int n;
    int lowbit(int x) { return x & (-x); }
    int b[N];

    void build(int _n)
    {
        n = _n;
        for (int i = 1; i <= n; ++i)
        {
            int f = i + lowbit(i);
            b[i] += a[rev_dfn[i]];
            if (f <= n)
                b[f] += b[i];
        }
    }
    void modify(int pos, int val)
    {
        for (int p = pos; p <= n; p += lowbit(p))
            b[p] += val;
    }
    int query(int pos)
    {
        int ret = 0;
        for (int p = pos; p; p -= lowbit(p))
            ret += b[p];
        return ret;
    }
    int query(int l, int r) { return query(r) - query(l - 1); }
    void modify_real(int pos, int val)
    {
        for (int p = pos; p <= n; p += lowbit(p))
            b[p] += val - a[rev_dfn[pos]];
        a[rev_dfn[pos]] = val;
    }
}
namespace HLD
{
    int n, rt;
    struct edge
    {
        int to, w, nxt;
    } e[N << 1];
    int h[N], ecnt;
    std::pair<int, int> eg[N];
    void add_edge(int u, int v, int w) { e[++ecnt].to = v, e[ecnt].w = w, e[ecnt].nxt = h[u], h[u] = ecnt; }
    void link(int i, int u, int v, int w) { add_edge(u, v, w), add_edge(v, u, w), eg[i] = std::make_pair(u, v); }

    int f[N], sz[N], dep[N], son[N];
    int dfn[N], rev_dfn[N], top[N], dfs_t;

    void dfs1(int u, int fa)
    {
        f[u] = fa, sz[u] = 1, dep[u] = dep[fa] + 1;
        for (int i = h[u]; i; i = e[i].nxt)
        {
            int v = e[i].to, w = e[i].w;
            if (v == fa)
                a[u] = w;
            else
            {
                dfs1(v, u), sz[u] += sz[v];
                if (sz[son[u]] < sz[v])
                    son[u] = v;
            }
        }
    }
    void dfs2(int u, int topf) // initial rt, rt
    {
        top[u] = topf, dfn[u] = ++dfs_t, rev_dfn[dfs_t] = u;
        if (son[u])
            dfs2(son[u], topf);
        for (int i = h[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if (v == f[u] || v == son[u])
                continue;
            dfs2(v, v);
        }
    }
    void build(int _rt, int _n)
    {
        n = _n, rt = _rt;
        dfs1(rt, 0), dfs2(rt, rt), bit::rev_dfn = rev_dfn;
        bit::build(n);
    }
    void modify_edge(int id, int val)
    {
        int u = dep[eg[id].first] > dep[eg[id].second] ? eg[id].first : eg[id].second;
        bit::modify_real(dfn[u], val);
    }
    int lca(int u, int v)
    {
        while (top[u] ^ top[v])
        {
            if (dep[f[top[u]]] < dep[f[top[v]]])
                std::swap(u, v);
            u = f[top[u]];
        }
        if (dep[u] > dep[v])
            std::swap(u, v);
        return u;
    }
    int dis(int u, int v) { return dep[u] + dep[v] - (dep[lca(u, v)] << 1); }
    int query(int u, int v)
    {
        int ret = 0;
        while (top[u] ^ top[v])
        {
            if (dep[f[top[u]]] < dep[f[top[v]]])
                std::swap(u, v);
            ret += bit::query(dfn[top[u]], dfn[u]);
            u = f[top[u]];
        }
        if (dep[u] > dep[v])
            std::swap(u, v);
        ret += bit::query(dfn[u] + 1, dfn[v]);
        return ret;
    }
}
signed main()
{
    int n = rd();
    for (int i = 1; i < n; ++i)
    {
        int u = rd(), v = rd();
        HLD::link(i, u, v, 1);
    }
    HLD::build(1, n);
    int q = rd();
    int op = 0, u = 0, v = 0, d = 0;
    while (q--)
    {
        op = rd(), u = rd();
        switch (op)
        {
        case 1:
            HLD::modify_edge(u, 1);
            break;
        case 2:
            HLD::modify_edge(u, 0);
            break;
        case 3:
            v = rd(), d = HLD::query(u, v), wr(d < HLD::dis(u, v) ? -1 : d), putchar('\n');
            break;
        default:
            break;
        }
    }
}
