#include <stdio.h>
#include <string.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define M 4010
#define N 100010
#define max(a, b) (((a) > (b)) ? (a) : (b))

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
int a[N], b[N];

int offset_a, offset_b, h, w;
int coord(int x, int y) { return (h - 1) * x + y; }

int dp[M][M];

int ans;

void init() { T = rd(), build_fac(); }

void init_case()
{
    offset_a = offset_b = h = w = 0;
    n = rd();
    for (int i = 1; i <= n; ++i)
        a[i] = rd(), b[i] = rd(), offset_a = max(offset_a, a[i]), offset_b = max(offset_b, b[i]);
    ++offset_a, ++offset_b, h = (offset_a << 1) - 1, w = (offset_b << 1) - 1;
    for (int i = 1; i <= h; ++i)
        memset(dp[i], 0, (w + 1) * sizeof(int));

    for (int i = 1; i <= n; ++i)
        ++dp[-a[i] + offset_a][-b[i] + offset_b];
}

void build_dp()
{
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            dp[i][j] = add(dp[i][j], add(dp[i - 1][j], dp[i][j - 1]));
    ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = add(ans, dp[a[i] + offset_a][b[i] + offset_b]);
    for (int i = 1; i <= n; ++i)
        ans = sub(ans, C((a[i] + b[i]) << 1, b[i] << 1));
    ans = mul(ans, inv2);
    wr(ans), putchar('\n');
}

int main()
{
    init();
    while (T--)
        init_case(), build_dp();
}
