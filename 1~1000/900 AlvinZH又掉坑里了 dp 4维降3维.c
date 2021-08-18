#include<stdio.h>
#include<string.h>

int mask[205][205];
long long dp[205][205][205];
//视为两个人同时走路，(i,j)是第一个人的坐标，k是第二个人的x坐标，此时y坐标即为i+j-k
int n, m;

void erase()
{
    memset(mask, 0, sizeof(mask));
    memset(dp, 0, sizeof(dp));
}

long long max(long long a, long long b, long long c, long long d)
{
    if (a >= b && a >= c && a >= d)
    {
        return a;
    }
    else if (b >= a && b >= c && b >= d)
    {
        return b;
    }
    else if (c >= a && c >= b && c >= d)
    {
        return c;
    }
    else
    {
        return d;
    }
}

void buildDP()
{
    dp[1][1][1] = 1ll * mask[1][1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 1; k <= n && k <= (i + j); k++)
            {
                int p = i + j - k;
                if (k != i)
                {
                    dp[i][j][k] = mask[i][j] + mask[k][p] +
                                  max(dp[i - 1][j][k - 1], dp[i - 1][j][k], dp[i][j - 1][k - 1], dp[i][j - 1][k]);
                }
                else
                {
                    dp[i][j][k] = mask[i][j] +
                                  max(dp[i - 1][j][k - 1], dp[i - 1][j][k], dp[i][j - 1][k - 1], dp[i][j - 1][k]);
                }
                //整个for循环其实不用考虑边界，0的地方自然就是0
            }
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        erase();
        int i;
        for (i = 1; i <= n; ++i)
        {
            int j;
            for (j = 1; j <= m; ++j)
            {
                scanf("%d", &mask[i][j]);
            }
        }
        buildDP();
        printf("%lld\n", dp[n][m][n]);
    }
}
