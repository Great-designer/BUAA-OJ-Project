#include<stdio.h>
#include<stdlib.h>

int g[100005][50];
int topg[100005];
int d[100005],n,m;
char vis[100005];
int q[100005];
int front;
int rear;

int main()
{
    int a,b;
    scanf("%d",&n);
    int i;
    for(i=0;i<n-1;++i)
    {
        scanf("%d%d",&a,&b);
        g[a][topg[a]]=b;
		topg[a]++;
        g[b][topg[b]]=a;
		topg[b]++;
    }
    for(i=1;i<=n;++i)
    {
        if(topg[i]==1)
        {
            q[rear]=i;
            rear++;
            vis[i]=1;
            d[i]=0;
        }
    }
    while(front!=rear)
    {
        int u=q[front];
		front++;
        for(i=0;i<topg[u];i++)
        {
            if(!vis[g[u][i]])
            {
                d[g[u][i]]=d[u]+1;
                q[rear]=g[u][i];
                rear++;
                vis[g[u][i]]=1;
            }
        }
    }
    double res=0;
    for(i=1;i<=n;++i)
    {
        res+=d[i];
    }
    printf("%.4lf",res/n);
    return 0;
}
