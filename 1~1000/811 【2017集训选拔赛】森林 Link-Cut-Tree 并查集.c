#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxn 100010
// Fast IO
char buf[1 << 21], *p1 = buf, *p2 = buf;
int nc() { return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++; }
int rd()
{
    int ret = 0;
    char ch = nc();

    while (ch < '0' || ch > '9')
        ch = nc();
    while (ch >= '0' && ch <= '9')
    {
        ret = (ret << 1) + (ret << 3) + (ch ^ 48);
        ch = nc();
    }
    return ret;
}
char Buf[1 << 21], out[20];
int P, out_size = -1;
void flush() { fwrite(Buf, 1, out_size + 1, stdout), out_size = -1; }
void wt(int x, char ch)
{
    if (out_size > 1 << 20)
        flush();

    if (x < 0)
        Buf[++out_size] = 45, x = -x;

    do
        out[++P] = (x % 10) ^ 48;
    while (x /= 10);

    do
        Buf[++out_size] = out[P];
    while (--P);

    Buf[++out_size] = ch;
}

int T;
int n, m, q;
int w, u, v;

// Link-Cut-Tree
struct Node
{
    int fa;
    int ch[2];
    bool mark;
} nodes[maxn];
void init() { memset(nodes, 0, sizeof(nodes)); }

bool nroot(int x) { return nodes[nodes[x].fa].ch[0] == x || nodes[nodes[x].fa].ch[1] == x; }

bool son(int x) { return nodes[nodes[x].fa].ch[1] == x; }

void rotate(int x)
{
    bool f = son(x);
    int y = nodes[x].fa, z = nodes[y].fa, w = nodes[x].ch[f ^ 1];
    if (nroot(y))
        nodes[z].ch[son(y)] = x;
    nodes[x].fa = z;
    nodes[x].ch[f ^ 1] = y;
    nodes[y].fa = x;
    nodes[y].ch[f] = w;
    if (w)
        nodes[w].fa = y;
}

void pushdown(int x)
{
    if (nodes[x].mark)
    {
        nodes[nodes[x].ch[0]].mark ^= 1;
        nodes[nodes[x].ch[1]].mark ^= 1;
        int tmp = nodes[x].ch[0];
        nodes[x].ch[0] = nodes[x].ch[1], nodes[x].ch[1] = tmp;
        nodes[x].mark = 0;
    }
}

void pushdown_all(int x)
{
    if (nroot(x))
        pushdown_all(nodes[x].fa);
    pushdown(x);
}

void Splay(int x)
{
    pushdown_all(x);
    while (nroot(x))
    {
        if (nroot(nodes[x].fa))
            rotate(son(x) == son(nodes[x].fa) ? nodes[x].fa : x);
        rotate(x);
    }
}

int access(int x)
{
    int y;
    for (y = 0; x; y = x, x = nodes[x].fa)
    {
        Splay(x);
        nodes[x].ch[1] = y;
    }
    return y;
}

void makeroot(int x)
{
    access(x);
    Splay(x);
    nodes[x].mark ^= 1;
}

void link(int x, int y)
{
    makeroot(x);
    nodes[x].fa = y;
}

void cut(int x)
{
    access(x);
    Splay(x);
    nodes[x].ch[0] = nodes[nodes[x].ch[0]].fa = 0;
}

int LCA(int x, int y)
{
    access(x);
    return access(y);
}

// Union set

int f[maxn], sz[maxn];
void initf()
{
    for (int i = 1; i <= n; ++i)
        f[i] = i, sz[i] = 1;
}
int getf(int x) { return f[x] == x ? x : getf(f[x]); }
bool check(int x, int y)
{
    int a = getf(x);
    int b = getf(y);
    if (a ^ b)
        return 0;
    else
        return 1;
}
void merge(int x, int y)
{
    int a = getf(x);
    int b = getf(y);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        f[b] = a, sz[a] += sz[b], sz[b] = 0;
    else
        f[a] = b, sz[b] += sz[a], sz[a] = 0;
}

int main()
{
    T = rd();
    while (T--)
    {
        n = rd(), m = rd(), q = rd();
        init(), initf();
        while (m--)
        {
            u = rd(), v = rd();
            merge(u, v), link(v, u);
        }
        while (q--)
        {
            w = rd(), u = rd(), v = rd();
            if (w & 1)
                wt(check(u, v) ? LCA(u, v) : -1, '\n');
            else
                merge(u, v), link(v, u);
        }
    }
    flush();
}