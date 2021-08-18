#include<stdio.h>
#include<string.h>

int maze[1100][1100];
int gap[1100],dis[1100],pre[1100],cur[1100];
int maxflow;

void dfs(int num,int start,int end,int *u,int *flow,int *flagg)
{
	int i;
	for(i=cur[*u]; i<num; i++)
	{
		if(maze[*u][i]&&dis[*u]==dis[i]+1)
		{
			if((*flow)==-1||(*flow)>maze[*u][i])
			{
				(*flow)=maze[*u][i];
			}
			pre[i]=(*u);
			(*u)=cur[*u]=i;
			if(i==end)
			{
				maxflow+=(*flow);
				for((*u)=pre[*u]; i!=start; i=(*u),(*u)=pre[*u])
				{
					maze[*u][i]-=(*flow);
					maze[i][*u]+=(*flow);
				}
				(*flow)=-1;
			}
			i=cur[*u]-1;
		}
	}
	int mindis=num-1;
	for(i=0; i<num; i++)
	{
		if(maze[*u][i]&&mindis>dis[i])
		{
			cur[*u]=i;
			mindis=dis[i];
		}
	}
	--gap[dis[*u]];
	if(gap[dis[*u]]!=0)
	{
		dis[*u]=mindis+1;
		gap[dis[*u]]++;
		(*u)=pre[*u];
	}
	else
	{
		(*flagg)=0;
	}
}

void sap(int num,int start,int end)
{
	memset(cur,0,sizeof(cur));
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	int u=pre[start]=start;
	int flow=-1;
	maxflow=0;
	gap[0]=num;
	int flagg=1;
	while(dis[start]<num&&flagg==1)
	{
		dfs(num,start,end,&u,&flow,&flagg);
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(maze,0,sizeof(maze));
	int i;
	for(i=0; i<m; i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		maze[a][b]=maze[b][a]=c;
	}
	sap(n+1,1,n);
	printf("%d\n",maxflow);
}
