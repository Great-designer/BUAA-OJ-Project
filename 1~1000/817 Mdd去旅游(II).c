#include<stdio.h>
#include<limits.h>
#include<string.h>

int f[1105];

int getFather(int x)
{
	return f[x]==x?x:(f[x]=getFather(f[x]));
}

int n,m;
int u,v;

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
			scanf("%d%d",&u,&v);
			int a=getFather(u);
			int b=getFather(v);
			if(a!=b)
			{
				f[a]=b;
			}
		}
		int res=0;
		for(i=0;i<n;++i)
		{
			if(f[i]==i)
			{
				res++;
			}
		}
		printf(res==1?"Yes\n":"No\n");
	}
}

