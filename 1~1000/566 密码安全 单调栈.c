#include<ctype.h>
#include<stdio.h>
#include<string.h>

int rd()
{
	int k = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c))
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

void wr(int x)
{
	if (x < 0)
	{
		putchar('-'), x = -x;
	}
	if (x > 9)
	{
		wr(x / 10);
	}
	putchar(x % 10 + '0');
}

int a[114514], xor_sum[114514], c[114514][30 + 2];
int lp[114514], rp[114514];
int sta[114514], top;
int T, n;
int ans;
int i, j;

int main()
{
	T = rd();
	while (T--)
	{
		n = rd();
		ans = 0;
		memset(c, 0, sizeof(c));
		for (i = 2; i <= n + 1; ++i)
		{
			scanf("%d", &a[i]), xor_sum[i] = xor_sum[i - 1] ^ a[i];
			for (j = 0; j < 30; j++)
			{
				c[i][j] = c[i - 1][j] + ((xor_sum[i] & (1 << j))!=0);
			}
		}
		top = 0, sta[top] = 1;
		for (i = 2; i <= n + 1; ++i)
		{
			while (top && a[sta[top]] < a[i])
			{
				--top;
			}
			lp[i] = sta[top], sta[++top] = i;
		}
		top = 0, sta[0] = n + 2;
		for (i = n + 1; i >= 2; i--)
		{
			while (top && a[sta[top]] <= a[i])
			{
				--top;
			}
			rp[i] = sta[top], sta[++top] = i;
		}
		for (i = 2; i <= n + 1; i++)
		{
			for (j = 0; j < 30; j++)
			{
				ans = (ans + ((long long)(c[i - 1][j] - c[lp[i] - 1][j]) * (rp[i] - i - c[rp[i] - 1][j] + c[i - 1][j])
				              + (long long)(i - lp[i] - c[i - 1][j] + c[lp[i] - 1][j]) * (c[rp[i] - 1][j] - c[i - 1][j])) % 1000000061ll
				       * (1 << j) % 1000000061ll * a[i]) % 1000000061ll;
			}
		}
		wr(ans), putchar('\n');
	}
}
