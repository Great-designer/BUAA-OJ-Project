#include<stdio.h>

int max(int x,int y)
{
	return x > y ? x : y;
}

int Nxt[300010], Pre[300010], n, a[300010], dep[300010];

void write(long long x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + 48);
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')
		{
			f = -1;
		}
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
	scanf("%d", &n);
	int i;
	for(i = 1; i <= n; ++i)
	{
		a[i] = read();
		Nxt[i] = i + 1;
		Pre[i] = i - 1;
	}
	Nxt[0] = 1;
	Pre[n + 1] = n;
	for(i = n; i >= 1; --i)
	{
		Nxt[Pre[a[i]]] = Nxt[a[i]];
		Pre[Nxt[a[i]]] = Pre[a[i]];
	}
	long long ans = 0;
	dep[0] = dep[n + 1] = -1;
	for(i = 1; i <= n; ++i)
	{
		dep[a[i]] = max(dep[Pre[a[i]]], dep[Nxt[a[i]]]) + 1;
		ans += dep[a[i]];
		write(ans),putchar('\n');
	}
}
