#include<stdio.h>

long long n, ans;

long long mul(long long a, long long b)
{
	return (__int128)a * (__int128)b % (__int128)1000000007;
}

long long int_sqrt(long long x)
{
	if (x <= 1)
		return x;
	long long ret = x;
	long long rett = (ret + (x / ret)) >> 1;
	while (rett < ret)
	{
		ret = rett;
		rett = (ret + (x / ret)) >> 1;
	}
	return ret;
}

int main()
{
	scanf("%lld", &n);
	n = int_sqrt(n), ans = 1;
	long long b = n, c = n + 1, d = (n << 1) + 1;
	if (b % 2 == 0)
		b >>= 1;
	else
		c >>= 1;
	if (b % 3 == 0)
		b /= 3;
	else if (c % 3 == 0)
		c /= 3;
	else
		d /= 3;
	ans = mul(ans, b), ans = mul(ans, c), ans = mul(ans, d);
	printf("%lld", ans);
}