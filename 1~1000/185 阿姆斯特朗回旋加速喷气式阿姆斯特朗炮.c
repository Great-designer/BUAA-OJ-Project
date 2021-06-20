#include<stdio.h>
#include<string.h>

int G[1212][1212];
int top[1212];

char tempmp[1212];
int mp[1212][1212];
int lmarry[1212],rmarry[1212];
char visl[1212],visr[1212];
int dis[2][4]={0,-1,0,1,1,0,-1,0};
int n=1000,m=1000,k;

void clear()
{
    memset(lmarry,-1,sizeof(lmarry));
    memset(rmarry,-1,sizeof(rmarry));
    memset(visl,0,sizeof(visl));
    memset(visr,0,sizeof(visr));
    memset(mp,0,sizeof(mp));
    memset(top,0,sizeof(top));
}

char dfs(int x)
{
    visl[x]=1;
    int i;
    for(i=0;i<top[x];i++)
	{
        int v=G[x][i];
        if(!visr[v])
        {
            visr[v]=1;
            if(lmarry[v]==-1||dfs(lmarry[v]))
            {
                lmarry[v]=x;
                rmarry[x]=v;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while(~scanf("%d",&k))
    {
        clear();
        int u,v;
        int i;
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&u,&v);
            G[u][top[u]]=v;
            top[u]++;
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            memset(visr,0,sizeof(visr));
            if(dfs(i))
            {
            	ans++;
			}                
        }
        printf("%d",ans);
        memset(visl,0,sizeof(visl));
        memset(visr,0,sizeof(visr));
        printf("\n");
    }
}
