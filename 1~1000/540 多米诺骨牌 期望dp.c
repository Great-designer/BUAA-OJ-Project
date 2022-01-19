#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxn 505
double read_double()
{
    double k = 0.0, f = 1.0;
    char c = getchar_unlocked();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1.0;
        c = getchar_unlocked();
    }
    while (isdigit(c))
    {
        k = k * 10.0 + (c ^ 48);
        c = getchar_unlocked();
    }
    if (c == '.')
    {
        double fraction = 1;
        c = getchar_unlocked();
        while (isdigit(c))
        {
            fraction /= 10;
            k += (c ^ 48) * fraction;
            c = getchar_unlocked();
        }
    }
    return k * f;
}
int read_int()
{
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar_unlocked();
    }
    return k * f;
}
int t, n, m;
double down[maxn][maxn], right[maxn][maxn], dp[maxn][maxn];
int main()
{
    t = read_int();
    while (t--)
    {
        n = read_int(), m = read_int();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                down[i][j] = read_double();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                right[i][j] = read_double();
        double ans = 0.0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                ans += (1.0 - down[i - 1][j]) * (1.0 - right[i][j - 1]);
        printf("%.4f\n", ans);
    }
}