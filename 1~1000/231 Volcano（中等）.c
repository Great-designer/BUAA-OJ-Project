#include<stdio.h>
#include<string.h>

int height[110][110];
int occur[110][110];
int n, m, k;
int u, v;

struct pair
{
	int first;
	int second;
};

struct pair q[100010];
int front;
int rear;

int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };

char islegal(int a, int b)
{
	return a <= n && a >= 1 && b <= m && b >= 1;
}

void bfs()
{
	while(front!=rear)
	{
		struct pair a = q[front];
		front++;
		int i;
		for (i = 0; i < 4; ++i)
		{
			if (!occur[a.first + nx[i]][a.second + ny[i]] && height[a.first][a.second] >= height[a.first + nx[i]][a.second + ny[i]] && islegal(a.first + nx[i], a.second + ny[i]))
			{
				occur[a.first + nx[i]][a.second + ny[i]] = 1;
				q[rear].first=a.first + nx[i];
				q[rear].second=a.second + ny[i];
				rear++;
			}
		}
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(occur, 0, sizeof(occur));
		int i;
		for (i = 1; i <= n; ++i)
		{
			int j;
			for (j = 1; j <= m; ++j)
			{
				scanf("%d", &height[i][j]);
			}
		}
		scanf("%d", &k);
		front=rear=0;
		while (k--)
		{
			scanf("%d%d", &u, &v);
			if (!occur[u][v])
			{
				occur[u][v] = 1;
				q[rear].first=u;
				q[rear].second=v;
				rear++;
			}
		}
		bfs();
		for (i = 1; i <= n; ++i)
		{
			int j;
			for (j = 1; j <= m; ++j)
			{
				printf("%d", occur[i][j]);
			}
			puts("");
		}
	}
}