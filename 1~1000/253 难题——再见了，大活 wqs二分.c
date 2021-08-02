#include<stdio.h>
#include<stdlib.h>

int n, k;
long long a[100010];
long long dp[100010], tp[100010], sum;//dp是在给定c下取到的权值  tp是用了多少对

int compare(const void*p1, const void*p2)
{
	long long *a=(long long*)p1;
	long long *b=(long long*)p2;
	if(*a>*b)
	{
		return 1;
	}
	else if(*a<*b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void write(long long x)
{
	if (x < 0)putchar('-'), x = -x;
	if (x > 9)write(x / 10);
	putchar(x % 10 + 48);
}

long long read()
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

char solve(long long c)
{
	tp[0] = dp[0] = 0;
	for(int i = 1; i <= n; ++i) dp[i] = sum, tp[i] = 0;
	dp[1] = 0;
	for(int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1], tp[i] = tp[i - 1];
		if(dp[i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]) + c < dp[i])
		{
			dp[i] = dp[i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]) + c;
			tp[i] = tp[i - 2] + 1;
		}
		else if(dp[i - 2] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]) + c == dp[i] && tp[i - 2] + 1 > tp[i])
			tp[i] = tp[i - 2] + 1;
	}
	return tp[n] >= k;
}

int main()
{
	while(scanf("%d%d", &n, &k) != EOF)
	{
		sum = 0;
		for(int i = 1; i <= n; ++i) a[i] = read(), sum += a[i] * a[i];
		qsort(a + 1,n,sizeof(long long),compare);
		long long lo = -1145141919810ll, mi, hi = 0;
		while(hi > lo)
		{
			mi = (hi + lo) >> 1;
			if(!solve(mi)) hi = mi;
			else lo = mi + 1;
		}
		solve(lo - 1);
		write(dp[n] - 1ll * k * (lo - 1)), putchar('\n');
	}
}
