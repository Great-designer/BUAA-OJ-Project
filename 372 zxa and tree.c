#include<stdio.h>
#include<string.h>

int n;
int a[110],b[110];
int e[210],pre[210],last[110],pp[110];
int f[110][110];
int g[110][110];
int nu[110];
int tot;

int min(int a,int b) 
{
	return a<b?a:b;
}

int max(int a,int b) 
{
	return a>b?a:b;
}

void work(int x)
{
    pp[x]=1;
    int i;
    for(i=last[x];i;i=pre[i])
    {
        if(!pp[e[i]])
        {
            work(e[i]);
            int j;
            for(j=0;j<=min(nu[x]+nu[e[i]],tot);j++)
            {
            	g[x][j]=0;
			}
            for(j=0;j<=nu[x];j++)
            {
            	int k;
            	for(k=0;k<=min(nu[e[i]],max(0,tot-j));k++)
                {
                    g[x][j+k]=max(g[x][j+k],f[x][j]+f[e[i]][k]);
                }
			}
            for(j=0;j<=min(nu[x]+nu[e[i]],tot);j++)
            {
            	f[x][j]=g[x][j];
			}
            nu[x]+=nu[e[i]];
        }
    }
    nu[x]++; 
    int j;
    for(j=0;j<=min(nu[x],tot);j++)
    {
        g[x][j]=0;
        if(j!=0)
		{
			g[x][j]=max(g[x][j],f[x][j-1]+a[x]);
		}
        if(j!=nu[x])
		{
			g[x][j]=max(g[x][j],f[x][j]+b[x]);
		}
    }
    for(i=0;i<=min(nu[x],tot);i++)
    {
    	f[x][i]=g[x][i]+i*((n-tot)-(nu[x]-i))+(nu[x]-i)*(tot-i);
	}
}   

int main()
{
    while(~scanf("%d",&n))
    {
        memset(last,0,sizeof(last));
        memset(nu,0,sizeof(nu));
        int i;
        for(i=1;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            e[i*2]=y;
            pre[i*2]=last[x];
            last[x]=i*2;
            e[i*2-1]=x;
            pre[i*2-1]=last[y];
            last[y]=i*2-1;
        }
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&a[i]);
		}
        for(i=1;i<=n;i++)
        {
        	scanf("%d",&b[i]);
		}
        for(i=0;i<=n;i++)
        {
            memset(pp,0,sizeof(pp));
            memset(f,0,sizeof(f));
            memset(nu,0,sizeof(nu));
            tot=i;
            work(1);
            printf("%d",f[1][i]);
            if(i==n)
			{
				printf("\n");
			}
            else
			{
				printf(" ");
			}
        }
    }
    return 0;
}

