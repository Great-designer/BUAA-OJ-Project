#include <stdio.h>
#include <string.h>

const unsigned long long mask[64] =
{
	0x0000000000000001ull,0x0000000000000002ull,0x0000000000000004ull,0x0000000000000008ull,
	0x0000000000000010ull,0x0000000000000020ull,0x0000000000000040ull,0x0000000000000080ull,
	0x0000000000000100ull,0x0000000000000200ull,0x0000000000000400ull,0x0000000000000800ull,
	0x0000000000001000ull,0x0000000000002000ull,0x0000000000004000ull,0x0000000000008000ull,
	0x0000000000010000ull,0x0000000000020000ull,0x0000000000040000ull,0x0000000000080000ull,
	0x0000000000100000ull,0x0000000000200000ull,0x0000000000400000ull,0x0000000000800000ull,
	0x0000000001000000ull,0x0000000002000000ull,0x0000000004000000ull,0x0000000008000000ull,
	0x0000000010000000ull,0x0000000020000000ull,0x0000000040000000ull,0x0000000080000000ull,
	0x0000000100000000ull,0x0000000200000000ull,0x0000000400000000ull,0x0000000800000000ull,
	0x0000001000000000ull,0x0000002000000000ull,0x0000004000000000ull,0x0000008000000000ull,
	0x0000010000000000ull,0x0000020000000000ull,0x0000040000000000ull,0x0000080000000000ull,
	0x0000100000000000ull,0x0000200000000000ull,0x0000400000000000ull,0x0000800000000000ull,
	0x0001000000000000ull,0x0002000000000000ull,0x0004000000000000ull,0x0008000000000000ull,
	0x0010000000000000ull,0x0020000000000000ull,0x0040000000000000ull,0x0080000000000000ull,
	0x0100000000000000ull,0x0200000000000000ull,0x0400000000000000ull,0x0800000000000000ull,
	0x1000000000000000ull,0x2000000000000000ull,0x4000000000000000ull,0x8000000000000000ull
};

void mark(unsigned long long* s, int o)
{
	s[o >> 6] |= mask[o & 63];
}

int test(unsigned long long* s, int o)
{
	return (s[o >> 6] & mask[o & 63]) == 0;
}

int primes[6536];
unsigned long long sieve[4096];
unsigned long long pattern[15015];

void update_sieve(int base)
{
	int o = base % 15015;
	o = (o + ((o * 105) & 127) * 15015) >> 7;
	int i,k;
	for (i = 0; i < 4096; i += k, o = 0)
	{
		k=(15015 - o)<(4096 - i)?(15015 - o):(4096 - i);
		memcpy(sieve + i, pattern + o, sizeof(*pattern) * k);
	}
	if (base == 0)   // 标记1为非素数，标记3、5、7、11和13为素数
	{
		sieve[0] |= mask[0];
		sieve[0] &= ~(mask[1] | mask[2] | mask[3] | mask[5] | mask[6]);
	}
	for (i = 0; i < 6536; ++i)
	{
		int j = primes[i] * primes[i];
		if (j > base + 524288 - 1)
		{
			break;
		}
		if (j > base)
		{
			j = (j - base) >> 1;
		}
		else
		{
			j = primes[i] - base % primes[i];
			if ((j & 1) == 0)
			{
				j += primes[i];
			}
			j >>= 1;
		}
		while (j < 524288 >> 1)
		{
			mark(sieve, j);
			j += primes[i];
		}
	}
}

int all[50000000 + 524288], pcnt;

void fast_sieve(int lim)//sieve from [0, n)
{
	int i;
	for (i = 0; i < (65536 >> 7); ++i)
	{
		sieve[i] = 0;
	}
	for (i = 3; i < 256; i += 2)
	{
		if (test(sieve, i >> 1))
		{
			int j;
			for (j = (i * i) >> 1; j < 32768; j += i)
			{
				mark(sieve, j);
			}
		}
	}
	int m = 0;
	for (i = 8; i < 32768; ++i)
	{
		if (test(sieve, i))
		{
			primes[m++] = (i << 1) + 1;
		}
	}
	for (i = 0; i < 15015; ++i)
	{
		pattern[i] = 0;
	}
	for (i = 1; i < 15015 * 64; i += 3)
	{
		mark(pattern, i);
	}
	for (i = 2; i < 15015 * 64; i += 5)
	{
		mark(pattern, i);
	}
	for (i = 3; i < 15015 * 64; i += 7)
	{
		mark(pattern, i);
	}
	for (i = 5; i < 15015 * 64; i += 11)
	{
		mark(pattern, i);
	}
	for (i = 6; i < 15015 * 64; i += 13)
	{
		mark(pattern, i);
	}
	all[pcnt++] = 2;
	int now = 1;
	int base;
	for (base = 0; base < lim; base += 524288)
	{
		update_sieve(base);
		int u=(base + 524288)<lim?(base + 524288):lim;
		for (i = 0; i < 4096; ++i)
		{
			unsigned long long o = ~sieve[i];
			while (o)
			{
				int p = __builtin_ctzll(o);
				int u = base + (i << 7) + (p << 1) + 1;
				if (u >= lim)
				{
					break;
				}
				all[pcnt++] = u;
				o -= o & ((~o) + 1);
			}
		}
	}
}

int upper_bound(int a[], int lo, int hi, int val)
{
	if (val >= a[hi])
	{
		return hi + 1;
	}
	int mi = 0;
	while (lo < hi)
	{
		mi = (lo + hi) >> 1;
		if (a[mi] <= val)
		{
			lo = mi + 1;
		}
		else
		{
			hi = mi;
		}
	}
	return lo;
}

int n;

int main()
{
	fast_sieve(50033520);
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n",upper_bound(all, 0, pcnt - 1, n));
	}
	return 0;
}