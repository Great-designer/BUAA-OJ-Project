#include<stdio.h>
#include<stdlib.h>

long long f[110000], inv[110000];
long long n, T, w;

long long C(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    long long res = (f[n] * inv[m]) % 1000000007;
    res = (res * inv[n - m]) % 1000000007;
    return res;
}

int main()
{
    f[0] = 1;
    int i;
    for (i = 1; i <= 100000; i++)
    {
        f[i] = (i * f[i - 1]) % 1000000007;
    }
    inv[1] = inv[0] = 1;
    for (i = 2; i <= 100000; i++)
    {
        inv[i] = (long long) (1000000007 - 1000000007 / i) * inv[1000000007 % i] % 1000000007;
        inv[i];
    }
    for (i = 2; i <= 100000; i++)
    {
        inv[i] = (inv[i] * inv[i - 1]) % 1000000007;
    }
    while (~scanf("%lld%lld%lld", &n, &T, &w))
    {
        long long ans = 0;
        for (i = 1; i <= n; i++)
        {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            long long d = llabs(w - x);
            long long num = 0;
            if (T % 2 == 0)
            {
                if (d % 2 == 1)
                {
                    continue;
                }
                long long pos = T / 2 + 1;
                pos += d / 2;
                num = (num + C(T, pos - 1)) % 1000000007;
            } else
            {
                if (d % 2 == 0)
                {
                    continue;
                }
                long long pos = (T + 1) / 2;
                pos += d / 2;
                num = (ans + C(T, pos - 1)) % 1000000007;
            }
            num = (num * y) % 1000000007;
            ans = (ans + num) % 1000000007;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


