#include<stdio.h>

long long low[100010], up[100010];
long long inv[2000010];
long long a[1000010];//处理的前缀和
long long t;
long long n, a1;
long long max_up;
long long ans;

void buildINV()
{
	inv[1] = 1;
	for(int i = 2; i <= 2000000; ++i)
		inv[i] = (long long)(998244353 - 998244353 / i) * inv[998244353 % i] % 998244353;
}

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

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

int main()
{
	buildINV();
	t = read();
	while(t--)
	{
		n = read(), a1 = read();
		ans = a1;
		max_up = 0;
		for(int i = 1; i < n; ++i)
		{
			low[i] = read(), up[i] = read();
			if(up[i]>max_up)max_up=up[i];
		}
		for(int i = 1; i <= max_up; ++i)
			a[i] = 1ll * i * i % 998244353 * inv[a1+i] % 998244353;
		for(int i = 1; i <= max_up; ++i)
			a[i] = (a[i] + a[i - 1]) % 998244353;
		for(int i = 1; i < n; ++i)
			ans = (ans + (inv[up[i] - low[i] + 1] * (a[up[i]] - a[low[i] - 1] + 998244353) % 998244353) % 998244353) % 998244353;
		write((ans + 998244353 % 998244353));
		putchar('\n');
	}
}