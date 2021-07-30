#include<stdio.h>

int t;
int a[100010], b[100010];
int n, m;
int x, y;
int c;
long long ans, l, r;

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
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
	t = read();
	while (t--)
	{
		n = read();
		for (int i = 0; i <= n; ++i)a[i] = read();
		m = read();
		for (int i = 0; i <= m; ++i)b[i] = read();
		c = read();
		while (c--)
		{
			x = read(), y = read();
			l = r = 0;
			for (int i = n; i >= 0; --i)l = ((l * x) % 10007 + a[i]) % 10007;
			for (int i = m; i >= 0; --i)r = ((r * y) % 10007 + b[i]) % 10007;
			ans = l * r % 10007;
			write(ans);
			putchar('\n');
		}
	}
}