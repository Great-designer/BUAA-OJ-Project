#include<stdio.h>

int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
int M[1001][1001];
int u[1001][1001];
int n,m;
int ax,ay,bx,by;

int c(int nx,int ny,int d,int o)
{
    if(nx<=0||nx>n||ny<=0||ny>m)
    {
        return 0;
    }
    if(o<0)
    {
        return 0;
    }
    if(nx==bx&&ny==by)
    {
        return 1;
    }
    if(M[nx][ny]>0&&(nx!=ax||ny!=ay))
    {
        return 0;
    }
    if(u[nx][ny]>0)
    {
        return 0;
    }
    u[nx][ny]=1;
    int i;
    for(i=0;i<=3;i++)
    {
        if(c(nx+xx[i],ny+yy[i],i,o-(d!=i)))
        {
            return 1;
        }
    }
    u[nx][ny]=0;
    return 0;
}

int main()
{
    int i,j,k,q;
    while (~scanf("%d%d",&n,&m))
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                scanf("%d",&M[i][j]);
            } 
        } 
        scanf("%d",&q);
        for (k=1;k<=q;k++)
        {
            scanf("%d%d%d%d",&ax,&ay,&bx,&by);
            if (M[ax][ay] != M[bx][by] || M[ax][ay] ==0)
            {
                printf("NO\n");
            } 
            else 
            {
                for (i=1;i<=n;i++) for (j=1;j<=m;j++) u[i][j]=0;
                if (c(ax,ay,0,2)) 
                {
                    printf("YES\n");
                    continue;
                }
                for (i=1;i<=n;i++) for (j=1;j<=m;j++) u[i][j]=0;
                if (c(ax,ay,1,2)) 
                {
                    printf("YES\n");
                    continue;
                }
                for (i=1;i<=n;i++) for (j=1;j<=m;j++) u[i][j]=0;
                if (c(ax,ay,2,2)) 
                {
                    printf("YES\n");
                    continue;
                }
                for (i=1;i<=n;i++) for (j=1;j<=m;j++) u[i][j]=0;
                if (c(ax,ay,3,2))
                {
                    printf("YES\n");
                    continue;
                }
                printf("NO\n");
            }
        }
    }
}
