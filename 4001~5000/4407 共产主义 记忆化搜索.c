#include<stdio.h>
#include<string.h>

char map[110][110];
char occur[110][110];
char target[10] = "communism";

struct node
{
	int x, y;
};

struct node route[110];
int nx[8] = { -1,-1,-1,0,0,1,1,1 };
int ny[8] = { -1,0,1,1,-1,-1,0,1 };
//坐标,方向,深度
int n;

char illegal(int x, int y)
{
	return x < 0 || x >= n || y < 0 || y >= n;
}

void dfs(int x, int y, int k, int dep)
{
	if (dep > 8)
		for (int i = 0; i <= 8; ++i)occur[route[i].x][route[i].y] = 1;
	if (illegal(x, y))return;
	if (map[x][y] != target[dep])return;
	else
	{
		int dx = x + nx[k], dy = y + ny[k];
		route[dep].x = x, route[dep].y = y;
		dfs(dx, dy, k, dep + 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", map[i]);
	memset(occur, 0, sizeof(occur));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < 8; ++k)
				dfs(i, j, k, 0);
	for (int i = 0; i < n; ++i, putchar('\n'))
		for (int j = 0; j < n; ++j)
			putchar(occur[i][j] ? map[i][j] : '*');
}