#include<stdio.h>
#include<string.h>
//floyd : 求所有点两两之间的最短路
/*
for (k = 0; k < n; ++k)
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
*/
//假定无穷距离
//maxs = 2 ^ 20 = 1048576
int dp[(1 << 16) + 3][16 + 3];
int a[16 + 3][16 + 3];
int i, j, k;
int n, maxs;
//maxs : 最多的状态数
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[1][0] = 0;
		maxs = (1 << n) - 1;
		for (i = 1; i <= maxs; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				if ((i >> j) & 1)
				{
					for (k = 0; k < n; ++k)
					{
						if (((i ^ (1 << j)) >> k) & 1)
						{
							dp[i][j] =dp[i][j]<(dp[i ^ (1 << j)][k] + a[k][j])?dp[i][j]:(dp[i ^ (1 << j)][k] + a[k][j]);
						}
					}
				}
			}
		}
		int ans = 0x3f3f3f3f;
		for (i = 1; i < n; ++i)
		{
			ans =ans<(dp[(1 << n) - 1][i] + a[i][0])?ans:(dp[(1 << n) - 1][i] + a[i][0]);
		}
		printf("%d\n", ans);
	}
}
