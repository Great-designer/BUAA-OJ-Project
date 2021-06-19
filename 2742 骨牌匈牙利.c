#include<stdio.h>
#include<string.h>

int vis[12100];
int a[12100];
int match[12100];
int ri[12100][100];
int top[12100];

char Hungary(int x) 
{
	if(a[x]==1) 
	{
		return 0;
	}
	int i;
	for(i=0;i<top[x];i++) 
	{
		int y=ri[x][i];
		if(a[y]!=1&&!vis[y]) 
		{
			vis[y]=1;
			if(!match[y]||Hungary(match[y])) 
			{
				match[y]=x; 
				return 1;
			}
		}
	}
	return 0;
}

int n,m,q;

int main() 
{
	scanf("%d%d%d",&n,&m,&q);
	int i;
	for(i=1;i<=m;i++) 
	{
		int j;
		for(j=1;j<=n;j++) 
		{
			if((i+j)&1)
			{
				if(i+1<=m)
				{
					ri[(i-1)*n+j][top[(i-1)*n+j]]=i*n+j;
					top[(i-1)*n+j]++;
				}
				if(i-1>=1)
				{
					ri[(i-1)*n+j][top[(i-1)*n+j]]=(i-2)*n+j;
					top[(i-1)*n+j]++;
				}
				if(j+1<=n)
				{
					ri[(i-1)*n+j][top[(i-1)*n+j]]=(i-1)*n+j+1;
					top[(i-1)*n+j]++;
				}
				if(j-1>=1) 
				{
					ri[(i-1)*n+j][top[(i-1)*n+j]]=(i-1)*n+j-1;
					top[(i-1)*n+j]++;
				}
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&y,&x);
		a[(x-1)*n+y]=1;
	}
	int ans=0;
	for(i=1;i<=n*m;i++)
	{
		memset(vis,0,sizeof(vis));
		ans+=Hungary(i);
	}
	printf("%d\n",ans);
}
