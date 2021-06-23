#include<stdio.h>
#include<string.h>

unsigned long long dp[100005];
unsigned long long tmp[100005];
unsigned long long n, k;
unsigned long long a[40];

unsigned long long buildDP()
{
	unsigned long long ret = 0;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int i;
	for (i = 0; i < n; ++i)
	{
		memset(tmp, 0, sizeof(tmp));
		int j;
		for (j = 0; j < 100005 - a[i]; ++j)
		{
			tmp[j + a[i]] = dp[j];
		}
		for (j = 0; j < 100005; ++j)
		{
			dp[j] += tmp[j];
		}
	}
	for (i = k; i < 100005; ++i)
	{
		ret += dp[i];
	}
	return ret;
}

int main()
{
	while (scanf("%llu%llu", &n, &k) != EOF)
	{
		int i;
		for (i = 0; i < n; ++i)
		{
			scanf("%llu", a + i);
		}
		printf("%llu\n", buildDP());
	}
}