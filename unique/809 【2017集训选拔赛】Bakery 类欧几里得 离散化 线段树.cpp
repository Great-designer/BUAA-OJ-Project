#include <stdio.h>
#include <string.h>
#include <algorithm>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
typedef long long i64;
typedef __int128_t i128;
using namespace std;
const int N = 200100;
i64 T, n, q, b[N], w;
struct node
{
    i64 op, l, r, A, B;
} sh[N];
i128 rd()
{
    i128 k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return f == 1 ? k : -k;
}
void wr(i128 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}
i128 f(i64 a, i64 b, i64 c, i64 n)
{
    if (a == 0)
        return (i128)(n + 1) * (b / c);

    if (a >= c || b >= c)
        return (i128)n * (n + 1) / 2 * (a / c) + (i128)(n + 1) * (b / c) + f(a % c, b % c, c, n);

    i64 m = (a * n + b) / c;
    return (i128)n * m - f(c, c - b - 1, a, m - 1);
}
i128 ask(i64 A, i64 B, i64 l, i64 r)
{
    return (i128)(l + r) * (r - l + 1) / 2 * A - (i128)B * (f(A, 0, B, r) - f(A, 0, B, l - 1));
}
namespace seg
{
    struct node
    {
        i64 A, B, st, tag;
        i128 sum;
    } sh[N << 2];
    void init() { memset(sh, 0, sizeof(sh)); }
    inline int lc(int x) { return x << 1; }
    inline int rc(int x) { return (x << 1) | 1; }
    void pushup(int x) { sh[x].sum = sh[lc(x)].sum + sh[rc(x)].sum; }
    void pushdown(int x, int l, int mid, int r)
    {
        if (!sh[x].tag)
            return;

        sh[lc(x)] = sh[rc(x)] = sh[x];
        int st = b[sh[x].st];
        sh[lc(x)].sum = ask(sh[x].A, sh[x].B, b[l] - st + 1, b[mid + 1] - st);
        sh[rc(x)].sum = sh[x].sum - sh[lc(x)].sum;
        sh[x].tag = 0;
    }
    void change(int x, int l, int r, int ll, int rr, i64 A, i64 B)
    {
        if (ll <= l && rr >= r)
        {
            sh[x].A = A, sh[x].B = B, sh[x].st = ll;
            sh[x].sum = ask(A, B, b[l] - b[ll] + 1, b[r + 1] - b[ll]);
            sh[x].tag = 1;
            return;
        }

        int mid = (l + r) >> 1;
        pushdown(x, l, mid, r);

        if (ll <= mid)
            change(lc(x), l, mid, ll, rr, A, B);

        if (rr > mid)
            change(rc(x), mid + 1, r, ll, rr, A, B);

        pushup(x);
    }
    i128 query(int x, int l, int r, int ll, int rr)
    {
        if (ll <= l && rr >= r)
            return sh[x].sum;

        int mid = (l + r) >> 1;
        i128 ans = 0;
        pushdown(x, l, mid, r);

        if (ll <= mid)
            ans += query(lc(x), l, mid, ll, rr);

        if (rr > mid)
            ans += query(rc(x), mid + 1, r, ll, rr);

        return ans;
    }
}
signed main()
{
    T = rd();
    while (T--)
    {
        w = 0, memset(b, 0, sizeof(b));
        seg::init();
        n = rd(), q = rd();

        for (int i = 1; i <= q; i++)
        {
            sh[i].op = rd(), sh[i].l = rd(), sh[i].r = rd();
            b[++w] = sh[i].l, b[++w] = sh[i].r;
            b[++w] = sh[i].r + 1;
            if (sh[i].op == 1)
                sh[i].A = rd(), sh[i].B = rd();
        }

        sort(b + 1, b + 1 + w);
        w = unique(b + 1, b + 1 + w) - b - 1;

        for (int i = 1; i <= q; i++)
        {
            sh[i].l = lower_bound(b + 1, b + 1 + w, sh[i].l) - b;
            sh[i].r = lower_bound(b + 1, b + 1 + w, sh[i].r) - b;
            if (sh[i].op == 1)
                seg::change(1, 1, w, sh[i].l, sh[i].r, sh[i].A, sh[i].B);
            else
                wr(seg::query(1, 1, w, sh[i].l, sh[i].r)), seg::change(1, 1, w, sh[i].l, sh[i].r, 1, 1), putchar('\n');
        }
    }
}
