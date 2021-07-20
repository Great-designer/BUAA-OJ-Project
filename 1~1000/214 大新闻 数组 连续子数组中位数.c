#include<stdio.h>
#include<string.h>

//防止负数的情况
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

int n, A[10010], B[10010], cnt[10010];

long long solve(int p)
{
	B[0] = 0;
	int t, ret = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++)
	{
		if (i == p) t = 0;
		else if (A[i] < A[p] || A[i] == A[p] && i < p) t = -1;
		else t = 1;
		B[i] = B[i - 1] + t;
	}
	cnt[5010] = 1;
	for (int i = 1; i <= p - 1; i++)
	{
		cnt[B[i] + 5010]++;
	}
	for (int i = p; i <= n; i++)
	{
		ret += cnt[B[i] + 5010] + cnt[B[i] + 5010 - 1];
	}
	return ret;
}

int main()
{
	while (scanf("%d", &n)!=EOF)
	{
		for (int i = 1; i <= n; i++)A[i] = read();
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += 1ll * A[i] * solve(i);
		}
		write(ans), putchar('\n');
	}
	return 0;
}