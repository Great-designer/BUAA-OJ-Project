#include<stdio.h>
#include<string.h>

/***********************************
成了，看过题解的复杂度分析之后
这题没办法，老老实实搜索做吧
***********************************/
int map[105][105];
char occur[105][105];
int tmp[105][105];
int dp[105][105];
int r, c;
int nx[4] = { 1,0,-1,0 };
int ny[4] = { 0,1,0,-1 };

char isLegal(int x, int y)
{
	return x > 0 && x <= r && y > 0 && y <= c;
}

char debug(int x, int y)
{
	return x == 3 && y == 2 && 0;
}

int dfs(int x, int y)
{
	if (occur[x][y])return dp[x][y];
	int ret = 1;
	for (int i = 0; i < 4; ++i)
	{
		int dx = x + nx[i];
		int dy = y + ny[i];
		if (isLegal(dx, dy) && map[dx][dy] > map[x][y])
		{
			int tmp = 1 + dfs(dx, dy);
			ret=(ret>tmp?ret:tmp);
		}
	}
	occur[x][y] = 1;
	dp[x][y] = ret;
	return ret;
}

int main()
{
	while (scanf("%d%d", &r, &c) != EOF)
	{
		for (int i = 1; i <= r; ++i)
			for (int j = 1; j <= c; ++j)
				scanf("%d", &map[i][j]);
		memset(occur, 0, sizeof(occur));
		int ans = 1;
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				int tmp = dfs(i, j);
				ans=(ans>tmp?ans:tmp);
			}
		}
		printf("%d\n", ans);
	}
}
