#include<stdio.h>
#include<string.h>

struct pair
{
	int first;
	int second;
};

struct pair E[110][1000010];
int top[1000010];

int vis[110];
int inq[110];
int d[110];

int Q[1000010];
int front;
int rear;

int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		int flag = 0;
		int i;
		memset(top,0,sizeof(top));
		memset(d,0,sizeof(d));
		memset(vis,0,sizeof(vis));
		memset(inq,0,sizeof(inq));
		for(i=0; i<k; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			E[x][top[x]].first=n+y;
			E[x][top[x]].second=z;
			top[x]++;
			E[n+y][top[n+y]].first=x;
			E[n+y][top[n+y]].second=-z;
			top[n+y]++;
		}
		front=rear=0;
		for(i=1; i<=n+m; i++)
		{
			d[i]=999999;
			E[0][top[0]].first=i;
			E[0][top[0]].second=0;
			top[0]++;
		}
		Q[rear]=0;
		rear++;
		inq[0]=1;
		int step = 0;
		while(front!=rear)
		{
			step++;
			if(step>1000000)
			{
				flag = 1;
				break;
			}
			int now=Q[front];
			front++;
			vis[now]=1;
			inq[now]=0;
			for(i=0; i<top[now]; i++)
			{
				int next = E[now][i].first;
				if(d[next]>d[now]+E[now][i].second)
				{
					d[next]=d[now]+E[now][i].second;
					if(inq[next])
					{
						continue;
					}
					inq[next]=1;
					Q[rear]=next;
					rear++;
				}
			}
		}
		if(flag)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}