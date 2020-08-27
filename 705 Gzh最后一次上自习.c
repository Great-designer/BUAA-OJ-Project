#include<stdio.h>

long long dp[100010];

void buildDP()
{
	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 104;
	dp[4] = 904;
	int i;
	for(i = 5; i < 100010; ++i)
	{
		dp[i] = 7 * dp[i - 1] - 6 * dp[i - 2] - 8 * dp[i - 3] + 176;
		while (dp[i] < 0)
		{
			dp[i] += 7777777;
		}
		dp[i] %= 7777777;
	}
}

int n,t;

int main()
{
	buildDP();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}
