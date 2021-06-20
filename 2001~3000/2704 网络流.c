#include<stdio.h>
#include<string.h>

int head[10010],Next[160160],to[160160],edge[160160];

int dep[10010];

int dfs(int now,int flow,int t)
{
    if(now==t)
	{
		return flow;
	} 
    int res=flow;
	int i;
    for(i=head[now];i&&res;i=Next[i])
    {
    	int v=to[i];
    	if(dep[v]==dep[now]+1&&edge[i])
        {
            int bee=dfs(v,(res<edge[i]?res:edge[i]),t);
            if(!bee)
			{
				dep[v]=0;
			}
            edge[i]-=bee;
			edge[i^1]+=bee;
            res-=bee;
        }
	}
    return flow-res;
}

int q[10010];

char bfs(int s,int t)
{
    memset(dep,0,sizeof dep);
    int l=1;
	int r=1;
	q[1]=s;
    dep[s]=1;
    while(l<=r)
    {
        int now=q[l];
        l++;
        int i;
        for(i=head[now];i!=0;i=Next[i])
        {
        	int v=to[i];
        	if(!dep[v]&&edge[i])
            {
                dep[v]=dep[now]+1;
                ++r;
                q[r]=v;
                if(v==t)
				{
					return 1;
				} 
            }
		}
    }
    return 0;
}

int cnt=1;

void add(int u,int v,int w)
{
	++cnt;
    to[cnt]=v,edge[cnt]=w,Next[cnt]=head[u],head[u]=cnt;
}

int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};

int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
    int s=n*m+1;
	int t=s+1;
    int sum;
    int i;
    for(i=1;i<=n;i++)
    {
    	int j;
        for(j=1;j<=m;j++)
        {
        	int x;
            scanf("%d",&x);
            sum+=x;
            int id=(i-1)*m+j;
            if((i+j)&1)
            {
                add(s,id,x);
                add(id,s,0);
                int k;
                for(k=1;k<=4;k++)
                {
                    int di=i+dx[k];
					int dj=j+dy[k];
                    if(di&&dj&&di<=n&&dj<=m)
                    {
                    	add(id,(di-1)*m+dj,0x3f3f3f3f);
                    	add((di-1)*m+dj,id,0);
					}
                }
            }
            else
			{
				add(id,t,x);
				add(t,id,0);
			}
        }
	}
    int maxflow=0;
    while(bfs(s,t))
    {
    	int flow=dfs(s,0x3f3f3f3f,t);
    	if(flow)
    	{
    		maxflow+=flow;
		}
	}
    printf("%d\n",sum-maxflow);
    return 0;
}
