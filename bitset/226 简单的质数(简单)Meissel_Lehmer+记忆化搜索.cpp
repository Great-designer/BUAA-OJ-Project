#include<stdio.h>
#include<math.h>

#include<bitset>
#include<unordered_map>
using namespace std;

int prime[7000000], pi[7000000], phi[510510 + 7][14], product[14];
bitset<7000000> p;

void init()
{
	int cnt = 0;
	p.set(0), p.set(1);
	int i;
	for (i = 2; i < 7000000; ++i)
	{
		if (!p.test(i)) prime[++cnt] = i;
		pi[i] = cnt;
		int j;
		for (j = 1; j <= cnt && i * prime[j] < 7000000; ++j)
		{
			p.set(i * prime[j]);
			if (i % prime[j] == 0)
			{
				break;
			}
		}
	}
	product[0] = 1;
	for (i = 0; i <= 510510; ++i)
	{
		phi[i][0] = i;
	}
	for (i = 1; i <= 7; ++i)
	{
		product[i] = product[i - 1] * prime[i];
		int j;
		for (j = 1; j <= 510510; ++j)
		{
			phi[j][i] = phi[j][i - 1] - phi[j / prime[i]][i - 1];
		}
	}
}

long long sqrt_ll(long long n)
{
	long long ans = sqrt((double)n);
	while (ans * ans <= n)
	{
		ans++;
	}
	return ans - 1;
}

long long cbrt_ll(long long n)
{
	long long ans = cbrt((double)n);
	while (ans * ans * ans <= n)
	{
		ans++;
	}
	return ans - 1;
}

long long get_euler(long long n, long long m)
{
	if (m == 0)
	{
		return n;
	}
	if (m <= 7)
	{
		return phi[n % product[m]][m] + n / product[m] * phi[product[m]][m];
	}
	if (n <= prime[m] * prime[m])
	{
		return pi[n] - m + 1;
	}
	if (n <= prime[m] * prime[m] * prime[m] && n < 7000000)
	{
		long long t = pi[sqrt_ll(n)], ans = pi[n] - (m + t - 2) * (t - m + 1) / 2;
		long long i;
		for (i = m + 1; i <= t; i++)
		{
			ans += pi[n / prime[i]];
		}
		return ans;
	}
	return get_euler(n, m - 1) - get_euler(n / prime[m], m - 1);
}

unordered_map<long long, long long> mp;

long long query(long long n)
{
	if (n < 7000000)
	{
		return pi[n];
	}
	if (mp.count(n))
	{
		return mp[n];
	}
	long long a = query(cbrt_ll(n)), b, c, t = sqrt_ll(n), ans;
	b = query(sqrt_ll(t));
	c = query(t);
	ans = get_euler(n, b) + (b + c - 2) * (c - b + 1) / 2;
	long long i;
	for (i = b + 1; i <= c; i++)
	{
		long long x = n / prime[i];
		ans -= query(x);
		if (i <= a)
		{
			long long t = query(sqrt_ll(x));
			long long j;
			for (j = i; j <= t; j++)
			{
				ans -= query(x / prime[j]) - (j - 1);
			}
		}
	}
	return mp[n] = ans;
}

int main()
{
	init();
	long long n;
	while (scanf("%lld", &n) != EOF)
	{
		printf("%lld\n",query(n));
	}
}