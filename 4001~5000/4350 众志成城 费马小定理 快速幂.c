#include<stdio.h>

unsigned long long a, b, c;//a^b 100000007 m

void wr(unsigned long long x)
{
	if (x > 9)wr(x / 10);
	putchar(x % 10 + 48);
}

unsigned long long AmulBmodP(unsigned long long a, unsigned long long b, unsigned long long p)
{
	unsigned long long ret = 0;
	while (b)
	{
		if (b & 1)
			ret = (ret + a) % p;
		a = (a << 1) % p;
		b >>= 1;
	}
	return ret;
}

unsigned long long ApowBmodP(unsigned long long a, unsigned long long b, unsigned long long p)
{
	unsigned long long ret = 1;
	while (b)
	{
		if (b & 1)ret = (ret * a) % p;
		a = AmulBmodP(a, a, p);
		b >>= 1;
	}
	return ret % p;
}

int main()
{
	while (scanf("%llu%llu%llu", &a, &b, &c) != EOF)
		printf("%llu\n", ApowBmodP(a, ApowBmodP(b, c, 100000007 - 1), 100000007));
}