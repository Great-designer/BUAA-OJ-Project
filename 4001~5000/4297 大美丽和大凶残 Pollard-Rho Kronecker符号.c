#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

char eof_flag;

char rd(long long *s)
{
	if (eof_flag)
		return 0;

	long long k = 0, f = 1;
	char c = getchar();

	while (c != '-' && (c < '0' || c > '9'))
	{
		if (c == EOF)
		{
			eof_flag = 1;
			return 0;
		}

		c = getchar();
	}

	f = (c == '-') ? -1 : 1;
	k = (c == '-') ? 0 : (c ^ 48);
	c = getchar();

	while (c >= '0' && c <= '9')
		k = (k << 1) + (k << 3) + (c ^ 48), c = getchar();

	if (c == EOF)
		eof_flag = 1;

	(*s) = f > 0 ? k : -k;
	return 1;
}

#define N 9
#define M ((1 << 7) - 1)
int test_prime[N + 7] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};
long long _abs(long long x)
{
	return x < 0 ? -x : x;
}

long long mod(long long a, long long p)
{
	if (p < 0)
		p = -p;
	while (a < 0)
		a += p;
	return a % p;
}

long long quick_pow(long long x, long long p, long long mod)
{
	long long ans = 1;
	while (p)
	{
		if (p & 1)
			ans = ans * x % mod;
		x = x * x % mod;
		p >>= 1;
	}
	return ans;
}

bool miller_rabin(long long n, long long k)
{
	long long nd = n - 1, m = nd;
	while (m)
	{
		long long x = quick_pow(k, m, n);
		if (x != 1 && x != nd)
			return false;
		if ((m & 1) == 1 || x == nd)
			return true;
		m >>= 1;
	}
	return true;
}

bool is_prime(long long n)
{
	if (n < 2)
		return false;
	for (register int i = 1; i <= N; i++)
	{
		if (n == test_prime[i])
			return true;
		if (!miller_rabin(n, test_prime[i]))
			return false;
	}
	return true;
}

long long floyd(long long a, long long b, long long p)
{
	return (a * a % p + b) % p;
}

long long gcd(long long a, long long b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -a;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int r = 0;
	while (!((a & 1) || (b & 1)))
		a >>= 1, b >>= 1, r++;

	long long ret = 0;
	while (1)
	{
		while (!(a & 1))
			a >>= 1;
		while (!(b & 1))
			b >>= 1;
		if (a > b)
			a = a - b;
		else
			b = b - a;
		if (0 == a)
		{
			ret = b << r;
			break;
		}
		if (0 == b)
		{
			ret = a << r;
			break;
		}
	}
	return ret;
}

long long pollard_pho(long long n)
{
	long long x = 0, c = rand() % (n - 1) + 1;
	for (register int i = 1;; i <<= 1)
	{
		long long y = 1, z = x, ans;
		for (register int j = 1; j <= i; j++)
		{
			x = floyd(x, c, n);
			y = y * _abs(x - z) % n;
			if (j % M == 0)
			{
				ans = gcd(n, y);
				if (ans > 1)
					return ans;
			}
		}
		ans = gcd(n, y);
		if (ans > 1)
			return ans;
	}
}

void min_factor(long long n, long long *ans)
{
	if (n < 2)
		return;
	if (is_prime(n))
	{
		if ((*ans) > n)
			(*ans) = n;
		return;
	}
	long long factor = 0;
	do
		factor = pollard_pho(n);
	while (factor == n);
	while (n % factor == 0)
	{
		n /= factor;
	}
	min_factor(n, ans);
	min_factor(factor, ans);
}

void factorization(long long *fac, long long x, int *sz)
{
	(*sz) = 0;
	if (x < 0)
		fac[++(*sz)] = -1, x = -x;
	while (x > 1)
	{
		int y = 0;
		long long factor = (long long)10000000000 * 10000000000;

		min_factor(x, &factor);
		while (x % factor == 0)
			x /= factor, ++y, fac[++(*sz)] = factor;
	}
}

long long fix(long long r, long long p)
{
	return r <= (p >> 1) ? r : r - p;
}

long long Legendre(long long a, long long p)
{
	if (p == -1)
		return a < 0 ? -1 : 1;
	if (p == 2)
	{
		if (!(a & 1))
			return 0;
		long long flag = mod(a, p);
		if (flag == 1 || flag == 7)
			return 1;
		else
			return -1;
	}
	return fix(quick_pow(mod(a, p), (p - 1) / 2, p), p);
}

long long fac_a[110], fac_b[110];
int sz_a, sz_b;

long long Kronecker(long long a, long long b)
{
	factorization(fac_a, a, &sz_a), factorization(fac_b, b, &sz_b);
	long long ret = 1, i = 0, j = 0;
	for (i = 1; i <= sz_a; ++i)
		for (j = 1; j <= sz_b; ++j)
			ret *= Legendre(fac_a[i], fac_b[j]);
	return ret;
}

long long a, b, ans;

int main()
{
	srand(NULL);
	while (rd(&a) && rd(&b))
	{
		ans = Kronecker(a, b);
		if (ans == 1)
			puts("Great beauty!");
		else if (ans == -1)
			puts("Great ferocity!");
		else
			puts("Nonsense.");
	}
}