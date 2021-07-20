#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<queue>
using namespace std;

char Vis[100010];//是否被访问过
int Dis[100010];//距离

pair<int,int> V[100010][42];
int top[100010];
priority_queue<pair<int,int> > Q;

void dijkstra(int s)
{
	memset(Dis,0x3f3f3f3f,sizeof(Dis));
	memset(Vis,0,sizeof(Vis));
	Dis[s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty())
	{
		pair<int,int> p=Q.top();
		Q.pop();
		if(Vis[p.second])
		{
			continue;
		}
		Vis[p.second]=1;
		int t;
		for(t=0; t<top[p.second]; t++)
		{
			int end=V[p.second][t].first;
			int Time=V[p.second][t].second;
			if(Dis[p.second]+Time<Dis[end])
			{
				Dis[end]=Dis[p.second]+Time;
				Q.push(make_pair(-Dis[end],end));
			}
		}
	}
}

int main()
{
	int n,m,k,des;
	int x,y,Time;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		int i;
		memset(top,0,sizeof(top));
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&Time);
			V[x][top[x]].first=y;
			V[x][top[x]].second=Time;
			top[x]++;
			V[y][top[y]].first=x;
			V[y][top[y]].second=Time;
			top[y]++;
		}
		dijkstra(1);
		int cnt=1;
		for(i=0; i<k; ++i)
		{
			scanf("%d",&des);
			if(Dis[des]==0x3f3f3f3f)
			{
				printf("Case %d:-1\n",cnt);
			}
			else
			{
				printf("Case %d:%d \n",cnt,Dis[des]);
			}
			cnt++;
		}
		printf("\n");
	}
}
