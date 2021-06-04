#include<stdio.h>

int n, m, t;
char map[105][105];
char tmp[105][105];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

char illegal(int x, int y)
{
	return x < 0 || x >= n || y < 0 || y >= m;
}

int main()
{
	while (scanf("%d%d%d", &n, &m, &t) != EOF)
	{
		int i;
		for(i = 0; i < n; ++i)
		{
			scanf("%s", map[i]);
		}
		while (t--)
		{
			for(i = 0; i < n; ++i)
			{
				int j;
				for(j = 0; j < m; ++j)
				{
					int alive = 0, slept = 0;
					int k;
					for(k = 0; k < 8; ++k)
					{
						int nx = i + dx[k], ny = j + dy[k];
						if (!illegal(nx, ny))
						{
							if (map[nx][ny] == '0')
							{
								slept++;
							}
							else
							{
								alive++;
							}
						}
					}
					if (map[i][j] == '1')
					{
						if (alive < 2)
						{
							tmp[i][j] = '0';
						}
						else if (alive > 3)
						{
							tmp[i][j] = '0';
						}
						else
						{
							tmp[i][j] = '1';
						}
					}
					else
					{
						if (alive == 3)
						{
							tmp[i][j] = '1';
						}
						else
						{
							tmp[i][j] = map[i][j];
						}
					}
				}
			}
			for(i = 0; i < n; ++i)
			{
				int j;
				for(j = 0; j < m; ++j)
				{
					map[i][j] = tmp[i][j];
				}
			}
		}
		for(i = 0; i < n; ++i)
		{
			int j;
			for(j = 0; j < m; ++j)
			{
				putchar(map[i][j]);
			}
			puts("");
		}
	}
}