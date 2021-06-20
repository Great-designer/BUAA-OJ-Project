#include<stdio.h>
#include<limits.h>
#include<string.h>

int f[10005];

int getFather(int x)
{
	return f[x]==x?x:(f[x]=getFather(f[x]));
}

int n,m;
int u,v;
int t;

int lala[10005];
int lalatop;

int compare(const void *a,const void *b)
{
	if(*(int*)a>*(int*)b)
	{
		return 1;
	}
	else if(*(int*)a<*(int*)b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		int i;
		for(i=0;i<n;++i)
		{
			f[i]=i;
		}
		while(m--)
		{
			lalatop=0;
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&u);
				lala[lalatop]=u;
				lalatop++;
			}
			qsort(lala,lalatop,sizeof(int),compare);
			int a=getFather(lala[0]);
			for(i=1;i<lalatop;++i)
			{
				int b=getFather(lala[i]);
				if(b<a)
				{
					f[a]=b;
				}
				else if(a<b)
				{
					f[b]=a;
				}
			}
		}
		int res=0;
		for(i=0;i<n;++i)
		{
			if(f[i]==0)
			{
				res++;
			}
		}
		printf("%d\n",res);
	}
}
