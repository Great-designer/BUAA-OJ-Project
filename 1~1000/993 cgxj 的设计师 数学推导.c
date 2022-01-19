#include <stdio.h>
typedef long long ll;
ll t, n, m;
ll MOD = 1000000007;
ll ans;
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ans = 0;
        scanf("%lld%lld", &m, &n);
        ll h = m - n;
        ans = (n * h * (h + 1) / 2 + (h + 2) * (h + 1) * h / 6) % MOD;
        if (m <= (n << 1))
            ans = (ans + (n * h * (h + 1) / 2) % MOD) % MOD;
        else
            ans = (ans + n * n * (n + 1) / 2 + (((m * (m + 1) * (2 * m + 1) - (2 * n) * (2 * n + 1) * (4 * n + 1)) / 6 + n - m / 2) / 4) % MOD) % MOD;
        printf("%lld\n", ans % MOD);
    }
}
