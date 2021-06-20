#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int edge[110][1010];
int top[110];

int que[1010];
int front,rear;

int inDegree[110];
int n,m;
int u,v;

char topoSort()
{
	front=rear=0;
	int i;
	for(i=1;i<=n;++i)
	{
		if(!inDegree[i])
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
		for(i=0;i<top[newP];++i)
		{
			inDegree[edge[newP][i]]--;
			if(inDegree[edge[newP][i]]==0)
			{
				que[rear]=edge[newP][i];
				rear++;
			}
		}
	}
	return cnt==n;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(inDegree,0,sizeof(inDegree));
		memset(top,0,sizeof(top));
		while(m--)
		{
			scanf("%d%d",&u,&v);
			++inDegree[v];
			edge[u][top[u]]=v;
			top[u]++;
		}
		if(!topoSort())
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
}
