#include<stdio.h>
#include<string.h>

int s[105];
//pos sta
long long dp[105][105];

long long dfs(int pos, int sta, int limit)
{
	if (pos == -1) return sta;
	if (!limit && dp[pos][sta] != -1)
		return dp[pos][sta];
	long long ret = 0;
	int up = limit ? s[pos] : 9;//无限制则最高可以冲到9
	for (int i = 0; i <= up; ++i)
	{
		ret = (ret + dfs(pos - 1, sta + (i & 1), limit && (i == up))) % 998244353;
	}
	if (!limit) dp[pos][sta] = ret;
	return ret;
}

long long solve(char* x)
{
	memset(dp, 0xff, sizeof(dp));
	int len = strlen(x);
	for (int i = 0; i < len; ++i) s[i] = x[len - 1 - i] - 48;
	return dfs(len - 1, 0, 1);
}

char a[105];

int main()
{
	while (scanf("%s", a) != EOF)
		printf("%lld\n", solve(a));
}