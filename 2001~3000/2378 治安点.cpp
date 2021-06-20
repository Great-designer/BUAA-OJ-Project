#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<queue>

using namespace std;

int g[1010][1010];
int point[1010],d[1010],d1[1010];
int n,m,cnt,k;
char vis[1010];
int gr[1010][1010];
int topgr[1010];

priority_queue<pair<int,int> > q;

void dij()
{
    memset(d,0x3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    int i;
    for(i=0;i<k;++i)
    {
    	pair<int,int> p;
    	p.first=0;
    	p.second=point[i];
        q.push(p);
		d[point[i]]=0;
    }
    while(!q.empty())
    {
        int x=q.top().second;
		q.pop();
        if(vis[x])
		{
			continue;
		}
        vis[x]=1;
        for(i=0;i<topgr[x];i++)
        {
            int y=gr[x][i];
			int z=g[x][gr[x][i]];
            if(d[y]>d[x]+z)
            {
                d[y]=d[x]+z;
                pair<int,int> p;
                p.first=-d[y];
    			p.second=y;
                q.push(p);
            }
        }
    }
}

int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(g,0x3f,sizeof(g));
        scanf("%d%d%d",&n,&m,&k);
        int i;
        for(i=0;i<k;++i)
        {
            scanf("%d",&point[i]);
        }
        int x,y,z;
        for(i=0;i<m;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(g[x][y]==0x3f3f3f3f)
            {
                gr[x][topgr[x]]=y;
				topgr[x]++;
                gr[y][topgr[y]]=x;
				topgr[y]++;
            }
            g[x][y]=min(g[x][y],z);
            g[y][x]=min(g[y][x],z);
        }
        dij();
        for(i=1;i<=n;++i)
        {
            printf("%d ",d[i]);
            topgr[i]=0;
        }
        printf("\n");
    }
    return 0;
}
