#include<stdio.h>
#include<string.h>

#include<vector>

using namespace std;

int dis[100010];
vector<int> g[100010];
int n, m;
int u, v;

void init()
{
	memset(dis, 0, sizeof(dis));
	for (int i = 1; i < 100010; ++i)g[i].clear();
}

void dfs(int u, int step)
{
	if (dis[u])return;
	dis[u] = step;
	for (int i = 0; i < g[u].size(); ++i)
	{
		dfs(g[u][i], step + 1);
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		init();
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d",&u,&v);
			if (v)
			{
				g[i].push_back(v);
				g[v].push_back(i);
			}
			if (u)
			{
				g[i].push_back(u);
				g[u].push_back(i);
			}
		}
		dfs(1, 1);
		int max = 0, maxIndex = 0;
		for (int i = 1; i <= n; ++i)
			if (dis[i] > max)
				max = dis[i], maxIndex = i;
		memset(dis, 0, sizeof(dis));
		dfs(maxIndex, 1);
		max = 0;
		for (int i = 1; i <= n; ++i)
			if (dis[i] > max)
				max = dis[i];
		printf("%d\n",max-1);
	}
}
