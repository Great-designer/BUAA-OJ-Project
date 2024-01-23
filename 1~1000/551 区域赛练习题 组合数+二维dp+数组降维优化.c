#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define max(a, b) (((a) > (b)) ? (a) : (b))

#define M 4010
#define N 100010
const int mod = 1000000007, inv2 = 500000004;

int rd()
{
    int k = 0, f = 1;
    char s = getchar();
    while (s < '0' || s > '9')
    {
        if (s == '-')
            f = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9')
    {
        k = (k << 1) + (k << 3) + (s ^ '0');
        s = getchar();
    }
    return f > 0 ? k : -k;
}
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar((x % 10) ^ '0');
}

int add(int a, int b) { return (a + b >= mod) ? (a + b - mod) : (a + b); }
int sub(int a, int b) { return (a < b) ? (a - b + mod) : (a - b); }
int mul(int a, int b) { return 1ll * a * b % mod; }
int inv(int a)
{
    int _a = a, _b = mod, u = 1, v = 0;
    while (_b)
    {
        const int t = _a / _b;
        _a -= t * _b;
        _a ^= _b, _b ^= _a, _a ^= _b;
        u -= t * v;
        u ^= v, v ^= u, u ^= v;
    }
    u += mod, u %= mod;
    return u;
}

int fac[M << 1], ifac[M << 1];
void build_fac()
{
    fac[0] = 1;
    for (int i = 1; i < (M << 1); ++i)
        fac[i] = mul(fac[i - 1], i);
    ifac[(M << 1) - 1] = inv(fac[(M << 1) - 1]);
    for (int i = (M << 1) - 2; i >= 0; --i)
        ifac[i] = mul(ifac[i + 1], i + 1);
}
int C(int n, int m)
{
    if (m > n || m < 0)
        return 0;
    else
        return mul(fac[n], mul(ifac[m], ifac[n - m]));
}


int T, n;
struct task { int a, b; } tasks[N];
int cmp(const void* p1, const void* p2)
{
    struct task* x = (struct task*)p1, * y = (struct task*)p2;
    if (x->a ^ y->a)
        return (x->a < y->a) ? -1 : 1;
    else
        return (x->b < y->b) ? -1 : (x->b == y->b) ? 0 : 1;
}
int st[N], ed[N];
int offset_a, offset_b, h, w;

int dp[M], ans;

void init() { T = rd(), build_fac(); }

void init_case()
{
    offset_a = offset_b = h = w = 0;
    n = rd();

    for (int i = 1; i <= n; ++i)
        tasks[i].a = rd(), tasks[i].b = rd(), offset_a = max(offset_a, tasks[i].a), offset_b = max(offset_b, tasks[i].b);
    ++offset_a, ++offset_b, h = (offset_a << 1) - 1, w = (offset_b << 1) - 1;

    memset(dp, 0, sizeof(dp)), memset(st, 0, sizeof(st)), memset(ed, 0, sizeof(ed));

    qsort(tasks + 1, n, sizeof(tasks[0]), cmp);

    for (int i = 1; i <= n; ++i)
        ed[offset_a - tasks[i].a] = ed[offset_a + tasks[i].a] = i;
    for (int i = n; i; --i)
        st[offset_a - tasks[i].a] = st[offset_a + tasks[i].a] = i;

}

void build_dp()
{
    ans = 0;
    for (int i = 1; i <= h; ++i)
    {
        if (i <= offset_a && st[i])
            for (int idx = st[i]; idx <= ed[i]; ++idx)
                dp[offset_b - tasks[idx].b] = add(dp[offset_b - tasks[idx].b], 1);
        for (int j = 1; j <= w; ++j)
            dp[j] = add(dp[j], dp[j - 1]);
        if (i >= offset_a && st[i])
            for (int idx = st[i]; idx <= ed[i]; ++idx)
                ans = add(ans, dp[offset_b + tasks[idx].b]);
    }
    for (int i = 1; i <= n; ++i)
        ans = sub(ans, C((tasks[i].a + tasks[i].b) << 1, tasks[i].b << 1));
    ans = mul(ans, inv2);
    wr(ans), putchar('\n');
}

int main()
{
    init();
    while (T--)
        init_case(), build_dp();
}
