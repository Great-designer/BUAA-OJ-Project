#include<stdio.h>
#include<string.h>

struct edge
{
    int to,cap,rev;
};

struct edge G[1010][1010];
int top[1010];
char used[1010];

void addedge(int from,int to,int cap)
{
	G[from][top[from]].to=to;
	G[from][top[from]].cap=cap;
	G[from][top[from]].rev=top[to];
	top[from]++;
	G[to][top[to]].to=to;
	G[to][top[to]].cap=cap;
	G[to][top[to]].rev=top[to];
	top[to]++;
}

int dfs(int v,int t,int f)
{
    if(v==t)
	{
		return f;
	}
    used[v]=1;
    int i;
    for(i=0;i<top[v];i++)
    {
        if(!used[G[v][i].to]&&G[v][i].cap>0)
        {
            int d=dfs(G[v][i].to,t,(f<G[v][i].cap?f:G[v][i].cap));
            if(d>0)
            {
                G[v][i].cap-=d;
                G[G[v][i].to][G[v][i].rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

int maxflow(int s,int t)
{
    int flow=0;
    while(1)
    {
        memset(used,0,sizeof(used));
        int f=dfs(s,t,99999999);
        if(f==0)
        {
        	return flow;
		}
        flow+=f;
    }
}

int main()
{
    int s,t,c,v,n,T,res;
    while(scanf("%d%d%d",&v,&n,&T)==3)
    {
    	memset(top,0,sizeof(top));
        while(n--)
        {
            scanf("%d%d%d",&s,&t,&c);
            addedge(s,t,c);
        }
        while(T--)
        {
            scanf("%d%d",&s,&t);
            res=maxflow(s,t);
            printf("%d\n",res);
        }
    }
    return 0;
}
