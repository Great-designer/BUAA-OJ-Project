#include<stdio.h>
#include<string.h>

int n,m;
int d[510][510];

int min(int x,int y)
{
	return x>y?y:x;
}

void floyd()/*有负边，无负环，神奇的抄板子算法，返回数组中任两点最短距离*/ 
{
	int k,i,j; 
    for(k=1;k<=n;++k)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main()
{
    memset(d,0x3f,sizeof(d));
    scanf("%d%d",&n,&m);
    int x,y,z;
    int i;
    for(i=0;i<m;++i)/*x到y有一条权值为z的边*/ 
    {
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        d[x][y]=z;
    }
    for(i=0;i<3;++i)/*填三边，最小花费最短路负值，得0环*/ 
    {
        floyd();/*修改数组*/ 
        scanf("%d%d",&x,&y);
        x++,y++;
        z=d[y][x];
        d[x][y]=-z;/*修改数组*/ 
        printf("%d\n",-z);
    }
    return 0;
}
