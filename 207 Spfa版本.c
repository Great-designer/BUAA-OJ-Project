#include<stdio.h>
#include<string.h>

int head[2090],to[100100],nex[100100],val[100100];
long long dis[2090][2090];
char vztd[2090][2090];

struct pairint
{
	int first;
	int second;
};

struct pairint Q[200100];
int front;
int rear;

void spfa(int n,int s)
{
	front=rear=0;
	int i;
	for(i=0;i<=n;i++)
	{ 
		int j;
		for(j=0;j<=n;j++)
		{ 
			dis[i][j]=4557430888798830399;
			vztd[i][j]=0;
		}
	} 
	dis[s][0]=0;
	vztd[s][0]=1;
	Q[rear].first=s;
	Q[rear].second=0;
	rear=(rear+1)%200000;
	while(front!=rear)
	{
		int x=Q[front].first;
		int ct=Q[front].second;
		front=(front+1)%200000;
		vztd[x][ct]=0;
		if(ct>=n-1)
		{
			continue;
		}	
		for(i=head[x];i;i=nex[i])
		{
			if(dis[x][ct]+val[i]<dis[to[i]][ct+1])
			{
				dis[to[i]][ct+1]=dis[x][ct]+val[i];
				if(!vztd[to[i]][ct+1])
				{
					Q[rear].first=to[i];
					Q[rear].second=ct+1;
					rear=(rear+1)%200000;
					vztd[to[i]][ct+1]=1;
				}
			}
		}
	}
}

struct pairlong
{
	int first;
	long long second;
};

long long ans[300005];
struct pairlong stk[2090];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(head,0,sizeof(head));
		memset(ans,0,sizeof(ans));
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		int i;
		for(i=1;i<=m;i++)
		{
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			to[i]=y;
			nex[i]=head[x];
			head[x]=i;
			val[i]=c;
		}
		int s,t;
		scanf("%d%d",&s,&t);
		spfa(n,s);
		int topp=0;
		for(i=1;i<=n;i++)
		{
			if(dis[t][i]<4557430888798830399)
			{
				stk[topp].first=i;
				stk[topp].second=dis[t][i];
				topp++;
			}
		}
		for(i=1;i<=q;i++)
		{
			int dt;
			scanf("%d",&dt);
			if(ans[dt])
			{
				printf("%lld\n",ans[dt]);
			}
			else
			{
				long long mmin=4557430888798830399;
				int j;
				for(j=0;j<topp;j++)
				{
					mmin=(mmin<((long long)stk[j].first*dt+stk[j].second)?mmin:((long long)stk[j].first*dt+stk[j].second));
				}
				ans[dt]=mmin;
				printf("%lld\n",mmin);
			}
		}
	}
	return 0;
}

