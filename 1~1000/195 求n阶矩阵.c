#include<stdio.h>
#include<string.h>

int n;
int map[105][105];

char cur;
int dy[] = { 1,-1,0,1 };
int dx[] = { 0,1,1,-1 };

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		memset(map, 0, sizeof(map));
		int x = 1, y = 1;
		cur = 0;
		int i;
		for(i = 1; i < n * n; ++i)
		{
			int nx = x + dx[cur], ny = y + dy[cur];
			map[nx][ny] = i;
			if (cur == 0 && nx == 1)cur = 1;
			else if (cur == 0 && nx == n)cur = 3;
			else if (cur == 1 && ny == 1 && nx < n)cur = 2;
			else if (cur == 1 && nx == n)cur = 0;
			else if (cur == 2 && ny == 1)cur = 3;
			else if (cur == 2 && ny == n)cur = 1;
			else if (cur == 3 && nx == 1 && ny < n)cur = 0;
			else if (cur == 3 && ny == n)cur = 2;
			x = nx, y = ny;
		}
		for(i = 1; i <= n; ++i)
		{
			int j;
			for(j = 1; j <= n; ++j)
			{
				printf("%d%c", map[i][j], (j == n ? '\n' : ' '));
			}
		}
	}
}