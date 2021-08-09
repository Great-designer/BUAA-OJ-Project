#include<stdio.h>

long long divisor[15], remaind[15];
int n;

long long exgcd(long long a, long long b, long long *x, long long *y)
{
	if (!b)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	long long q = exgcd(b, a % b, y, x);
	(*y) -= a / b * (*x);
	return q;
}

long long chinaRemain()
{
	long long ret = 0, mod = 1;
	for (int i = 1; i <= n; ++i)mod *= divisor[i];
	for (int i = 1; i <= n; ++i)
	{
		long long m, p, y;
		m = mod / divisor[i];
		exgcd(m, divisor[i], &p, &y);
		ret = (ret + m * p * remaind[i]) % mod;
	}
	while(ret < 0)ret += mod;
	return ret;
}

void init()
{
	n = 3, divisor[1] = 25, divisor[2] = 28, divisor[3] = 33;
}

int main()
{
	init();
	while (scanf("%lld%lld%lld", remaind + 1, remaind + 2, remaind + 3) != EOF)
	{
		printf("%lld\n", chinaRemain());
	}
}