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

struct edge edges[100010];

int compare(const void*p1,const void*p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	return a->w>b->w?1:-1;
}

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

int f[310];
int n,m;
int p,q;
int cnt;
int mstNum;
long long res;
int lalala[310];
char occur[310];
int maxWeight[310][310];

void initFather()
{
	int i;
	for(i=1;i<=n;++i)
	{
		f[i]=i;
	}
}

int getFather(int x)
{
	return f[x]==x?x:(f[x]=getFather(f[x]));
}

void write(long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

int read()
{
	int k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

void addEdge(int u,int v,int w)
{
	msTree[mstNum].rank=v;
	msTree[mstNum].w=w;
	msTree[mstNum].next=lalala[u];
	lalala[u]=mstNum++;
}

void printIndexAndMST()
{
	printf("MST:\n");
	int i;
	for(i=0;i<mstNum;++i)
	{
		printf("%d : %d %d %d\n",i,msTree[i].rank,msTree[i].w,msTree[i].next);
	}
	printf("Index:\n");
	for(i=1;i<=n;++i)
	{
		printf("%d : %d\n",i,lalala[i]);
	}
}

void kruskal()
{
	cnt=0;
	res=0;
	mstNum=0;
	int i;
	for(i=0;i<m;++i)
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

struct Node que[10010];
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
	que[rear]=now;
	rear++;
	occur[start]=1;
	while(front!=rear)
	{
		struct Node head=que[front];
		front++;
		int i;
		for(i=lalala[head.rank];i>=0;i=msTree[i].next)
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
	for(i=1;i<=n;++i)
	{
		bfs(i);
	}
	for(i=0;i<m;++i)
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

char isExistMST()
{
	int cnt=0;
	int i;
	for(i=1;i<=n;++i)
	{
		if(f[i]==i)
		{
			cnt++;
		}
	}
	return cnt==1;
}

int main()
{
	int t=read();
	while(t--)
	{
		n=read();
		m=read();
		initFather();
		int i;
		for(i=0;i<m;++i)
		{
			edges[i].u=read();
			edges[i].v=read();
			edges[i].w=read();
			edges[i].flag=0;
		}
		qsort(edges,m,sizeof(struct edge),compare);
		memset(lalala,-1,sizeof(lalala));
		kruskal();
		if(!isExistMST())
		{
			putchar('0');
			putchar('\n');
			continue;
		}
		if(getSecMST()==res)
		{
			printf("Not Unique!\n");
		}
		else
		{
			write(res);
			putchar('\n');
		}
	}
}
