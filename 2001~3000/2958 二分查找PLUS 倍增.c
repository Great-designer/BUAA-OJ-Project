#include <stdio.h>
#define N 100010
#define LOG_N 18
int rd()
{
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? 0 : f, c = getchar();
    while (c >= '0' && c <= '9') k = (k << 1) + (k << 3) + (c ^ '0'), c = getchar();
    return f ? k : -k;
}
int n, q, x, id;
int a[N];
char lim[N];
int dp[N][LOG_N]; // dp[i][j] = a[i + 2^(j - 1)]
int lower_bound(int v)
{
    int cur = 1, step = 0;
    if (a[cur] >= v) return cur;
    while (1)
    {
        step = lim[cur];
        while (step && dp[cur][step] >= v) --step;
        if (!step) break;
        cur += 1 << (step - 1);
    }
    return cur + 1;
}
int upper_bound(int v)
{
    int cur = 1, step = 0;
    if (a[cur] > v) return cur;
    while (1)
    {
        step = lim[cur];
        while (step && dp[cur][step] > v) --step;
        if (!step) break;
        cur += 1 << (step - 1);
    }
    return cur + 1;
}
int main()
{
    n = rd();
    for (int i = 1; i <= n; ++i)
        a[i] = rd();
    for (int i = 1, j = 1; i <= n; ++i)
    {
        dp[i][0] = a[i], j = 1;
        while (i + (1 << (j - 1)) <= n)
            dp[i][j] = a[i + (1 << (j - 1))], ++j;
        lim[i] = j - 1;
    }
    q = rd();
    while (q--)
    {
        x = rd(), id = lower_bound(x);
        if (a[lower_bound(x)] ^ x) puts("No");
        else printf("Yes %d %d\n", id, upper_bound(x) - id);
    }
}
