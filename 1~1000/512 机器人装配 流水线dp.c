#include<stdio.h>
#include<limits.h>
#include<string.h>

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

int m, n;
int pre, now;
long long dp[1010][2];
long long ans;
int work[1010];
int to[1010][1010];

void init()
{
	for (int i = 1; i <= n; ++i)dp[i][0] = LLONG_MAX, dp[i][1] = LLONG_MAX;
	memset(work, 0, sizeof(work));
	memset(to, 0, sizeof(to));
}

void buildDP()
{
	for (int i = 1; i <= n; ++i)dp[i][now] = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][now]=dp[i][now]<(work[i] + dp[j][pre] + to[j][i])?dp[i][now]:(work[i] + dp[j][pre] + to[j][i]);
		}
	}
	now = 1 - now, pre = 1 - pre;
}

void printAns()
{
	ans = LLONG_MAX;
	for (int i = 1; i <= n; ++i)
	{
		ans=ans<dp[i][pre]?ans:dp[i][pre];
	}
	write(ans), putchar('\n');
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		init();
		now = 1, pre = 0;
		for (int i = 1; i <= n; ++i)
			dp[i][pre] = read();
		for (int i = 2; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
				for (int k = 1; k <= n; ++k)
					to[j][k] = read();
			for (int j = 1; j <= n; ++j)
				work[j] = read();
			buildDP();
		}
		printAns();
	}
}
