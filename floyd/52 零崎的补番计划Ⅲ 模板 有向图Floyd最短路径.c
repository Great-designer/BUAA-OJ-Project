#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//floyd板子题目:
//多次查询，那就一次算完，空间o(n^2)时间o(n^3)
//这个算法本质上也是DP思想，3维转2维
//最短路状态转移方程为
//floyd[i][j] = min{floyd[i][k]+floyd[k][j],floyd[i][j]}
//负权可以处理，所以这题-1要变成INF，但是负环不行
//但是这题兜圈的可能性只有自己到自己

unsigned int floyd[510][510];
int n;

void buildMap()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				floyd[i][j]=(floyd[i][k]+floyd[k][j])<floyd[i][j]?(floyd[i][k]+floyd[k][j]):floyd[i][j];
			}
		}
	}
}

int start,finish;

int main()
{
	int q;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				scanf("%d",&floyd[i][j]);
				if (floyd[i][j] == -1)
				{
					floyd[i][j] = 2147483647;
				}
			}
		}
		buildMap();
		while (q--)
		{
			scanf("%d%d",&start,&finish);
			if(start == finish || floyd[start][finish] >= 2147483647)
			{
				printf("jujue\n");
			}
			else
			{
				printf("%d\n",floyd[start][finish]);
			}
		}
	}
}