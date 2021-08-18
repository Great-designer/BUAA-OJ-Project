#include <stdio.h>

int dp[100010];

void buildDP()
{
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 104;
    dp[4] = 904;
    int i;
    for (i = 5; i < 100010; ++i)
    {
        dp[i] = 7ll * dp[i - 1] - 6ll * dp[i - 2] - 8ll * dp[i - 3] + 176ll;
        while (dp[i] < 0)
        {
            dp[i] += 7777777;
        }
        dp[i] %= 7777777;
    }
}
int rd()
{
    int k = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
void wr(int x)
{
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + 48);
}
int n, t;

int main()
{
    buildDP();
    t = rd();
    while (t--)
    {
        n = rd();
        wr(dp[n]), putchar('\n');
    }
}
