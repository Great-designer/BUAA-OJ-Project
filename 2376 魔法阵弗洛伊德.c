#include<stdio.h>
#include<string.h>

int n,m;
int d[510][510];

int min(int x,int y)
{
	return x>y?y:x;
}

void floyd()/*�и��ߣ��޸���������ĳ������㷨��������������������̾���*/ 
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
    for(i=0;i<m;++i)/*x��y��һ��ȨֵΪz�ı�*/ 
    {
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        d[x][y]=z;
    }
    for(i=0;i<3;++i)/*�����ߣ���С�������·��ֵ����0��*/ 
    {
        floyd();/*�޸�����*/ 
        scanf("%d%d",&x,&y);
        x++,y++;
        z=d[y][x];
        d[x][y]=-z;/*�޸�����*/ 
        printf("%d\n",-z);
    }
    return 0;
}
