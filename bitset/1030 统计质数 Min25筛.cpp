#include<stdio.h>
#include<math.h>

#include<bitset>

using namespace std;

//Euler Sieve
bitset<1000010> a;
unsigned int prime[80010], cnt;
unsigned int pi[1000010];

void get_prime(unsigned int n)
{
	cnt = 0;
	a.set(0);
	a.set(1);
	unsigned int i;
	for (i = 2; i <= n; ++i)
	{
		if (!a.test(i))
		{
			prime[++cnt] = i;
		}
		pi[i] = cnt;
		unsigned int j;
		for (j = 1; j <= cnt && prime[j] * i <= n; ++j)
		{
			a.set(i * prime[j]);
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
}

//Min_25 Sieve
int id1[1000010], id2[1000010], cntid;
long long n, m, num[1000010 << 1], f[1000010 << 1];

int Id(long long x)
{
	return x <= m ? id1[x] : id2[n / x];
}

void Min25(long long _n)
{
	n = _n;
	long long l = 1, v;
	cntid = 0;
	m = min(n, (long long)(floor(sqrt(1.0 * n)) + 1));
	if (n <= 1000000)
	{
		return;
	}
	while (l <= n)
	{
		v = n / l;
		if (v <= m)
		{
			id1[v] = ++cntid;
		}
		else
		{
			id2[n / v] = ++cntid;
		}
		num[cntid] = v;
		f[cntid] = v - 1;
		l = n / v + 1;
	}
	int i;
	for (i = 1; i <= cnt && 1ll * prime[i] * prime[i] <= n; ++i)
	{
		int j;
		for (v = 1ll * prime[i] * prime[i], j = 1; j <= cntid && num[j] >= v; ++j)
		{
			f[j] -= f[Id(num[j] / prime[i])] - (1ll * i - 1);
		}
	}
}

long long query(long long x)
{
	return (x <= 1000000) ? pi[x] : f[Id(x)];
}

int main()
{
	get_prime(1000000);
	Min25(10000000);
	while (scanf("%lld", &n) != EOF)
	{
		printf("%lld\n", query(n));
	}
}
