#include<stdio.h>

unsigned long long dp[40][40];

void buildDP()
{
	int i;
	for(i = 0; i <= 35; ++i)
	{
		dp[0][i] = 1;
	}
	for(i = 1; i <= 35; ++i)
	{
		int j;
		for(j = 1; j <= 35; ++j)
		{
			int k;
			for(k = 1; k <= i; ++k)
			{
				dp[i][j] += dp[k - 1][j - 1] * dp[i - k][j - 1];
			}
		}
	}
}

int n, h;

int main()
{
	buildDP();
	while(~scanf("%d%d", &n, &h))
	{
		printf("%llu\n", dp[n][n] - dp[n][h - 1]);
	}
}
