#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n,m,start,finish,cost;
int x,y,t;

struct Edges
{
	int u,v,w,next;
};

struct Edges edges[50010];

int que[10010],tail=0;
int inDegree[10010];
int inCount[10010],inTime[10010];
int link[10010];
int cnt;

void addEdge(int u,int v,int w)
{
	edges[++cnt].next=link[u];
	edges[cnt].u=u;
	edges[cnt].v=v;
	edges[cnt].w=w;
	link[u]=cnt;
	inDegree[v]++;
}

void topoSort()
{
	int i; 
	for(i=1;i<=n;++i)
	{
		if(inDegree[i]==0)
		{
			que[++tail]=i;
		}
	}
	for(i=1;i<=tail;++i)
	{
		int k;
		for(k=link[que[tail]];k>0;k=edges[k].next)
		{
			inDegree[edges[k].v]--;
			if(inDegree[edges[k].v]==0)
			{
				que[++tail]=edges[k].v;
			}
		}
		if(tail==n)
		{
			break;
		}
	}
}

void buildDP()
{
	inCount[start]=1;
	inTime[finish]=0;
	int j;
	for(j=1;j<=n;++j)
	{
		int k=que[j];
		if(link[k]>0)
		{
			int i;
			for(i=link[k];i>0;i=edges[i].next)
			{
				inCount[edges[i].v]=(inCount[edges[i].v]+inCount[k])%10000;
				inTime[edges[i].v]=(inTime[edges[i].v]+inTime[k]+edges[i].w*inCount[k])%10000;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&start,&finish,&cost);
	memset(edges,0,sizeof(edges));
	memset(link,-1,sizeof(link));
	memset(inDegree,0,sizeof(inDegree));
	memset(inCount,0,sizeof(inCount));
	memset(inTime,0,sizeof(inTime));
	int i;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&t);
		addEdge(x,y,t);
	}
	topoSort();
	buildDP();
	printf("%d\n",(inTime[finish]+(inCount[finish]-1)*cost)%10000);
}
