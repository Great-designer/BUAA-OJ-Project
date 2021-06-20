#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct pp
{
	int first;
	int second;
};

struct Node
{
	int inDegree;
	struct pp edge[40];
	int top;
}; 

struct Node node[10010];

int que[10010];
int front,rear;

int inDegreeBackup[10010];
int n,m;
int u,v,w;
int Min,Max,Mid;
int t;

char topoSort(int skip)
{
	front=rear=0;
	int i;
	for(i=1;i<=n;++i)
	{
		node[i].inDegree=inDegreeBackup[i];
	}
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=0;j<node[i].top;++j)
		{
			if(node[i].edge[j].second<=skip)
			{
				node[node[i].edge[j].first].inDegree--;
			}
		}
	}
	for(i=1;i<=n;++i)
	{
		if(node[i].inDegree==0)
		{
			que[rear]=i;
			rear++;
		}
	}
	int cnt=0;
	while(front!=rear)
	{
		int newP=que[front];
		front++;
		++cnt;
		for(i=0;i<node[newP].top;++i)
		{
			if(node[newP].edge[i].second>skip)
			{
				node[node[newP].edge[i].first].inDegree--;
				if(node[node[newP].edge[i].first].inDegree==0)
				{
					que[rear]=node[newP].edge[i].first;
					rear++;
				}
			}
		}
	}
	return cnt==n;
}

void write(int first)
{
	if(first>9)
	{
		write(first/10);
	}
	putchar(first%10+48);
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

int main()
{
	t=read();
	while(t--)
	{
		Min=INT_MAX;
		Max=0;
		Mid=0;
		n=read()£»
		m=read();
		int i;
		for(i=1;i<=n;++i)
		{
			inDegreeBackup[i]=0;
			node[i].inDegree=0;
			node[i].top=0;
		}
		while(m--)
		{
			u=read();
			v=read();
			w=read();
			if(w>Max)
			{
				Max=w;
			}
			if(Min>w)
			{
				Min=w;
			}
			++inDegreeBackup[v];
			struct pp temp;
			temp.first=v;
			temp.second=w;
			node[u].edge[node[u].top]=temp;
			node[u].top++;
		}
		if(topoSort(Min-1))
		{
			write(0);
			putchar('\n');
			continue;
		}
		if(topoSort(Min))
		{
			write(Min);
			putchar('\n');
			continue;
		}
		while(Max>Min)
		{
			Mid=(Max+Min)>>1;
			if(topoSort(Mid))
			{
				Max=Mid;
			}
			else
			{
				Min=Mid+1;
			}
		}
		write(Min);
		putchar('\n');
	}
}
