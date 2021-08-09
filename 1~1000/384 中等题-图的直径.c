#include<stdio.h>

int map[110][110];
int res;
int n,m;
int u,v,d;

void floyd()
{
	int k;
	for(k=1;k<=n;++k)
	{
		int i;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				map[i][j]=(map[i][k]+map[k][j])<map[i][j]?(map[i][k]+map[k][j]):map[i][j];
			}
		}
	}
}

void printAns()
{
	res=0;
	int i;
	for(i=1;i<=n;++i)
	{
		int j;
		for(j=1;j<=n;++j)
		{
			if(map[i][j]<res)
			{
				res=map[i][j];
			}
		}
	}
	printf("%d\n",-res);
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int i;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				if(i!=j)
				{
					map[i][j]=0x3f3f3f3f;
				}
				else map[i][j]=0;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&d);
			map[u][v]=-d;
		}
		floyd();
		printAns();
	}
}
