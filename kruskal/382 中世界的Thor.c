#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct edge
{
	int u,v;
	int w;
	char flag;
};

int compare(const void *p1,const void *p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	if(a->w>b->w)
	{
		return 1;
	}
	else if(a->w<b->w)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct edge edges[100010];

struct mstNode
{
	int rank;
	int w;
	int next;
};

struct mstNode msTree[2*310];

struct Node
{
	int rank;
	int max;
};

int n;
int f[310];
int lalala[310];
char occur[310];
int maxWeight[310][310];

void initFather()
{
	int i;
	for(i=1; i<=n; ++i)
	{
		f[i]=i;
	}
}

int getFather(int x)
{
	return f[x]==x?x:(f[x]=getFather(f[x]));
}

int mstNum;

void addEdge(int u,int v,int w)
{
	msTree[mstNum].rank=v;
	msTree[mstNum].w=w;
	msTree[mstNum].next=lalala[u];
	lalala[u]=mstNum++;
}

int m;
int p,q;
int cnt;
long long res;

void kruskal()
{
	cnt=0;
	res=0;
	mstNum=0;
	int i;
	for(i=0; i<m; ++i)
	{
		p=getFather(edges[i].u);
		q=getFather(edges[i].v);
		if(p!=q)
		{
			f[p]=q;
			addEdge(edges[i].u,edges[i].v,edges[i].w);
			addEdge(edges[i].v,edges[i].u,edges[i].w);
			res+=edges[i].w;
			edges[i].flag=1;
			cnt++;
		}
		if(cnt==n)
		{
			break;
		}
	}
}

struct Node que[114514];
int front;
int rear;

void bfs(int start)
{
	memset(occur,0,sizeof(occur));
	front=rear=0;
	struct Node now;
	now.rank=start;
	now.max=0;
	struct Node adj;
	adj.rank=-1;
	adj.max=-1;
	que[rear]=now;
	rear++;
	occur[start]=1;
	while(front!=rear)
	{
		struct Node head=que[front];
		front++;
		int i;
		for(i=lalala[head.rank]; i>=0; i=msTree[i].next)
		{
			adj.rank=msTree[i].rank;
			adj.max=msTree[i].w;
			if(!occur[adj.rank])
			{
				if(head.max>adj.max)
				{
					adj.max=head.max;
				}
				maxWeight[start][adj.rank]=adj.max;
				occur[adj.rank]=1;
				que[rear]=adj;
				rear++;
			}
		}
	}
}

long long getSecMST()
{
	long long secondSum=LLONG_MAX;
	long long temp;
	int i;
	for(i=1; i<=n; ++i)
	{
		bfs(i);
	}
	for(i=0; i<m; ++i)
	{
		if(!edges[i].flag)
		{
			temp=res+edges[i].w-maxWeight[edges[i].u][edges[i].v];
			if(secondSum>temp)
			{
				secondSum=temp;
			}
		}
	}
	return secondSum;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		initFather();
		int i;
		for(i=0; i<m; ++i)
		{
			scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
			edges[i].flag=0;
		}
		qsort(edges,m,sizeof(struct edge),compare);
		memset(lalala,-1,sizeof(lalala));
		kruskal();
		printf("%lld\n",getSecMST());
	}
}
