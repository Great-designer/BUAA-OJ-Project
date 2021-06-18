#include<stdio.h>

int l[100010],r[100010];
int g[100010];
int f[100010];
int tmax=-1;

void DFS(int x)
{
    if(x!=0)
	{
        DFS(l[x]);
        DFS(r[x]);
        g[x]=((g[l[x]]>g[r[x]])?g[l[x]]:g[r[x]])+1;
    }
    else
	{
        g[x]=0;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
	{
        scanf("%d%d",&l[i],&r[i]);
    }
    DFS(1);
    for(i=1;i<=n;i++)
	{
        f[i]=1+g[l[i]]+g[r[i]];
        if(f[i]>tmax)
		{
            tmax=f[i];
        }
    }
    printf("%d",tmax-1);
}
