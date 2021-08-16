#include<stdio.h>

long long read()
{
	long long k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

long long extgcd(long long a, long long b, long long *x, long long *y)  //Extend Euclid
{
	if (b == 0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	long long x1, y1;
	long long gcd = extgcd(b, a % b, &x1, &y1);
	*x = y1;
	*y = x1 - a / b * y1;
	return gcd;
}

long long a, b, MOD;
long long x, y;

int main()
{
	a = read(), b = read(), MOD = read();
	if(b == 0)
	{
		puts("Angry!");
		return 0;
	}
	//如果b mod 上述质数是0 那么必然是无解的
	extgcd(b, MOD, &x, &y);
	x = (x % MOD + MOD) % MOD;
	write(a * x % MOD);
}
