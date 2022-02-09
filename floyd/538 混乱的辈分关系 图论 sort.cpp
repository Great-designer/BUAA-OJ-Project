#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>

using namespace std;
char occured_edge[110][110];
int n, m;
int u, v;
int graph[110][110];//graph[i][j]指j是否为i的子孙

void floyd()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				graph[i][j]=(graph[i][k] + graph[k][j])<graph[i][j]?(graph[i][k] + graph[k][j]):graph[i][j];
			}
		}
	}
}

struct Info
{
	int num;
	int babaZhi;
	int age;
	vector<int> sons;
	vector<int> fathers;
};

struct Info info[110];

char ifAcalledBsonsFather(Info a, Info b)
{
	int B = b.num;
	char flag = 0;
	for (int i = 0; i < a.fathers.size(); ++i)
	{
		if (graph[B][a.fathers[i]] < 0x3f3f3f3f)
		{
			flag = 1;
		}
		else if (a.fathers[i] == B)
		{
			flag = 1;
		}
	}
	return flag;
}

int cmp(const void *p1,const void *p2)
{
	struct Info *a=(struct Info *)p1;
	struct Info *b=(struct Info *)p2;
	if(a->babaZhi!=b->babaZhi)
	{
		return a->babaZhi<b->babaZhi;
	}
	char a2b=ifAcalledBsonsFather(*a,*b);
	char b2a=ifAcalledBsonsFather(*b,*a);
	if(a2b&&!b2a)
	{
		return 1;
	}
	if(!a2b&&b2a)
	{
		return -1;
	}
	else
	{
		return a->age<b->age;
	}
}

char cmpInt(int a, int b)
{
	if (info[a].babaZhi != info[b].babaZhi)
	{
		return info[a].babaZhi > info[b].babaZhi;
	}
	else
	{
		return info[a].age > info[b].age;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		info[i].num = i;
		for (int j = 1; j <= n; ++j)
		{
			graph[i][j] = 0x3f3f3f3f;
		}
	}
	while (m--)
	{
		scanf("%d%d", &u, &v);
		if (u != v)
		{
			if (!occured_edge[u][v])
			{
				info[u].fathers.push_back(v);
				info[v].sons.push_back(u);
				graph[v][u] = 1;
				occured_edge[u][v] = 1;
			}
			--info[u].babaZhi, ++info[v].babaZhi;
		}
	}
	floyd();
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &info[i].age);
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(info[i].sons.begin(), info[i].sons.end(), cmpInt);
	}
	qsort(info+1,n,sizeof(struct Info),cmp);
	printf("%d\n", info[1].num);
	for (int i : info[1].sons)
	{
		printf("%d ", i);
	}
}