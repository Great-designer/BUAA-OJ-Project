#include<stdio.h>
#include<bitset>

using namespace std;
 
int v[200004][54];
int vtop[200004];

long long p[200004];
 
struct node
{ 
	int ty,x,y,z; 
};

struct node op[200004];
 
int T;
int ret[200004];
int n,m,q;
int c[200004];
 
bitset<1002> a[1002];
 
int calc(int x)
{
	return (a[x]>>1).count()-(a[x]>>(m+1)).count();
}
 
void dfs(int x,int cnt)
{
    ret[x]=cnt;
    int u;
    for(u=0;u<vtop[x];u++)
	{
        if(op[v[x][u]].ty==1)
		{
            int nx=op[v[x][u]].x,ny=op[v[x][u]].y,nz=op[v[x][u]].z;
            if(c[nx]==0)
			{
                int z=a[nx][ny],num=calc(nx);
                a[nx][ny]=nz;
                dfs(v[x][u],cnt+calc(nx)-num);
                a[nx][ny]=z;
            }
            else
			{
                int z=a[nx][m-ny+1],num=calc(nx);
                a[nx][m-ny+1]=nz;
                dfs(v[x][u],cnt+calc(nx)-num);
                a[nx][m-ny+1]=z;
            }
        }
        else if(op[v[x][u]].ty==2)
		{
            int nx=op[v[x][u]].x;
            int num=calc(nx);
            a[nx].flip();
            dfs(v[x][u],cnt+calc(nx)-num);
            a[nx].flip();
        }
        else if(op[v[x][u]].ty==3)
		{
            int nx=op[v[x][u]].x;
            c[nx]^=1;
            dfs(v[x][u],cnt);
            c[nx]^=1;
        }
        else dfs(v[x][u],cnt);
    }
}
 
int main()
{
    p[0] = 1;
    int i;
	for(i=1;i<=2e5+1;++i)
	{
		p[i]=p[i-1]*813ll%100624;
	}
	scanf("%d",&T);
    while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
        for(i=0;i<=q+1;++i)
		{
			vtop[i]=0;
		}
        for(i=0;i<=n+1;++i)
		{
			a[i].reset();
		}
        for(i=1;i<=q;++i)
		{
            int et;
            scanf("%d",&et);
            if(et==1)
			{
				v[i-1][vtop[i-1]]=i;
				vtop[i-1]++;
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                op[i].ty=1;
                op[i].x=x;
                op[i].y=y;
                op[i].z=z;
            }
            else if(et==2)
			{
				v[i-1][vtop[i-1]]=i;
				vtop[i-1]++;
                int x;
                scanf("%d",&x);
                op[i].ty=2;
                op[i].x=x;
            }
            else if(et==3)
			{
				v[i-1][vtop[i-1]]=i;
				vtop[i-1]++;
                int x;
                scanf("%d",&x);
                op[i].ty=3;
                op[i].x=x;
            }
            else
			{
                int x;
                scanf("%d",&x);
                v[x][vtop[x]]=i;
				vtop[x]++;
                op[i].ty=4;
            }
        }
        dfs(0,0);
        long long ans=0;
        for(i=1;i<=q;++i)
		{
			ans=(ans+ret[i]*p[i]%100624)%100624;
		}
        printf("%lld\n",ans);
    }
    return 0;
}

