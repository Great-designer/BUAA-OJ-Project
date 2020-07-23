#include<stdio.h>
#include<string.h>

int t;
int ans;
int n,m;
int u,v;
char edge[1010][1010];
char occur[1010];
int q[1010];
int front;
int rear; 

int bfs(int x)
{
	int ret=0;
	front=rear=0;
	q[rear]=x;
	rear++;
	while(front!=rear)
	{
		int p=q[front];
		occur[p]=1;
		front++;
		int i;
		for(i=1;i<=n;++i)
		{
			if(edge[p][i]&&!occur[i])
			{
				q[rear]=i;
				rear++;
				occur[i]=1;
				ret++;
				edge[p][i]=edge[i][p]=0;
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(occur,0,sizeof(occur));
		memset(edge,0,sizeof(edge));
		ans=0;
		int i;
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&u,&v);
			edge[u][v]=edge[v][u]=1;
		}
		for(i=1;i<=n;++i)
		{
			if(!occur[i])
			{
				int tmp=bfs(i);
				ans=(tmp>ans?tmp:ans);
			}
		}
		printf("%d\n",ans);
	}
}
