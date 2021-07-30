#include<stdio.h>
#include<string.h>

int n, k;
int a[510];
char dp[510][510];//前i个糖可以摆出值为j的

void erase()
{
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
}

void initDP()
{
	int i;
	for (i = 0; i <= n; ++i)
	{
		dp[i][0] = 1;
	}
}

void buildDP()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			if (j >= a[i])
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}

int main()
{
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		erase();
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d",&a[i]);
		}
		initDP();
		buildDP();
		printf((dp[n][k]) ? "Yes\n" : "No\n");
	}
}
