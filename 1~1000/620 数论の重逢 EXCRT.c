#include<stdio.h>
#include<string.h>

long long divisor[100015], remaind[100015];
int n;

long long AmulBmodP(long long a, long long b, long long p)
{
	long long ret = 0;
	while (b)
	{
		if (b & 1)
			ret = (ret + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	return ret;
}

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

long long EXCRT()
{
	long long x, y, M=divisor[1], ans=remaind[1];
	for(int i=2; i<=n; i++)
	{
		long long c=(remaind[i] - ans % divisor[i] + divisor[i]) % divisor[i];
		long long t=exgcd(M, divisor[i], &x, &y), bg = divisor[i] / t;
		if(c % t) return -1;
		x = AmulBmodP(x, c / t, bg);     //x可能是负的
		ans += x * M;
		M *= bg;
		ans = (ans % M + M ) % M;
	}
	return (ans % M + M) % M;
}

int main()
{
	n = 3;
	divisor[1] = 25, divisor[2] = 28, divisor[3] = 33;
	while (scanf("%lld%lld%lld", remaind + 1, remaind + 2, remaind + 3) != EOF)
		printf("%lld\n", EXCRT());
}
