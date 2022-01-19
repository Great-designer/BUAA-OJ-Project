#include <stdio.h>
#include <string.h>
#define maxn 2010
#define max(a, b) ((a) > (b) ? (a) : (b))
typedef long long ll;
char s[maxn][maxn];
ll U[maxn], S[maxn], cur, c[maxn][maxn], n, m;
ll ans;
// c[i][j]  i行j列的矩形个数有多少
void wr(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;

    if (x > 9)
        wr(x / 10);

    putchar(x % 10 + '0');
}
ll solve(char flag)
{
    ll ret = 0;
    memset(U, 0, sizeof(U));
    memset(c, 0, sizeof(c));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            U[j] = s[i][j] == flag ? U[j] + 1 : 0;

        cur = 0;
        S[++cur] = 0;

        for (int j = 1; j <= m + 1; ++j)
        {
            while (U[j] < U[S[cur]])
            {
                c[max(U[S[cur - 1]], U[j]) + 1][j - S[cur - 1] - 1]++;
                c[U[S[cur]] + 1][j - S[cur - 1] - 1]--;
                --cur;
            }

            while (cur >= 1 && U[j] == U[S[cur]])
                --cur;

            S[++cur] = j;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            c[i][j] += c[i - 1][j];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = m - 1; j >= 1; --j)
            c[i][j] += c[i][j + 1];

        for (int j = m - 1; j >= 1; --j)
            c[i][j] += c[i][j + 1];
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ret += (ll)i * (ll)j * c[i][j];

    return ret;
}
int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%s", s[i] + 1);
        wr(solve('0') + solve('1')), putchar('\n');
    }
    return 0;
}