#include<stdio.h>
#include<string.h>

int maze[1100][1100];
int gap[1100],dis[1100],pre[1100],cur[1100];

int sap(int start,int end,int nodenum) 
{
    memset(cur,0,sizeof(cur));
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(dis[start]<nodenum)
	{
        while(1)
        {
        	int flag=0;
        	int v;
        	for(v=cur[u];v<nodenum;v++)
        	{
        		if(maze[u][v]&&dis[u]==dis[v]+1) 
				{
                	if(aug==-1||aug>maze[u][v])
					{
						aug=maze[u][v];
					}
        	        pre[v]=u;
        	        u=cur[u]=v;
        	        if(v==end)
					{
        	            maxflow+=aug;
        	            for(u=pre[u];v!=start;v=u,u=pre[u])
						{
        	                maze[u][v]-=aug;
        	                maze[v][u]+=aug;
        	            }
        	            aug=-1;
        	        }
        	        flag=1;
        	        break;
        	    }
			}
			if(flag==1)
			{
				continue;
			}
			break;
		}
        int mindis=nodenum-1;
        int v;
        for(v=0;v<nodenum;v++)
        {
        	if(maze[u][v]&&mindis>dis[v])
			{
                cur[u]=v;
                mindis=dis[v];
            }
		}
        if((--gap[dis[u]])==0)
		{
			break;
		}
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(maze,0,sizeof(maze));
    int i;
    for(i=0;i<m;i++)
	{
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        maze[a][b]=maze[b][a]=c;
    }
    int ans=sap(1,n,n+1);
    printf("%d\n",ans);
}
