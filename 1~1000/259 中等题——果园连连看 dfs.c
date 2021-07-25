#include<stdio.h>
#include<string.h>

char map[110][110];
int nx[4] = { -1,0,1,0 };
int ny[4] = { 0,1,0,-1 };
int n, m;

void dfs(int x, int y, char target)
{
	map[x][y] = 'w';
	int i;
	for (i = 0; i < 4; ++i)
	{
		int nextx = nx[i] + x, nexty = ny[i] + y;
		if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && map[nextx][nexty] == target)
		{
			dfs(nextx, nexty, target);
		}
	}
}

int result;

int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		result = 0;
		memset(map, 0, sizeof(map));
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%s",map[i] + 1);
		}
		for (i = 1; i <= n; ++i)
		{
			int j;
			for (j = 1; j <= m; ++j)
			{
				if (map[i][j] != 'w')
				{
					char target = map[i][j];
					dfs(i, j, target);
					result++;
				}
			}
		}
		printf("%d\n",result);
	}
}