#include<stdio.h>
#include<string.h>

int read()
{
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k*f;
}

struct edge
{
	int u,v,w;
};

int compare(const void *p1,const void *p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	if(a->w>b->w)
	{
		return 1;
	}
	else if(a->w<b->w)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct edge edges[2505*2505/2];

int f[2505];
int n,cnt;

void initFather()
{
	int i; 
	for(i=1;i<=n;++i)
	{
		f[i]=i;
	}
}

int getFather(int x)
{
	return f[x]==x?x:(f[x]=getFather(f[x]));
}

char check(int x,int y)
{
	int a=getFather(x);
	int b=getFather(y);
	if(a!=b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void merge(int x,int y)
{
	int a=getFather(x);
	int b=getFather(y);
	if(a!=b)
	{
		f[a]=b;
	}
}

void addEdge(int u,int v,int w)
{
	edges[cnt].u=u;
	edges[cnt].v=v;
	edges[cnt++].w=w;
}

int a[2505][2505];
char flag;

int main()
{
	while(~scanf("%d",&n))
	{
		cnt=0;
		memset(edges,0,sizeof(edges));
		flag=1;
		int i;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				a[i][j]=read();
			}
		}
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<=n;++j)
			{
				if(i==j&&a[i][j])
				{
					flag=0;
					break;
				}
				if(a[i][j]!=a[j][i])
				{
					flag=0;
					break;
				}
			}
			if(!flag)
			{
				break;
			}
		}
		if(!flag)
		{
			puts("NOT MAGIC");
			continue;
		}
		initFather();
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=1;j<i;++j)
			{
				addEdge(i,j,a[i][j]);
			}
		}
		qsort(edges,cnt,sizeof(struct edge),compare);
		edges[cnt].w=-1;
		for(i=0;i<cnt;++i)
		{
			int j=i;
			while(edges[j+1].w==edges[i].w)
			{
				j++;
			}
			int k;
			for(k=i;k<=j;++k)
			{
				if(!(flag=check(edges[k].u,edges[k].v)))
				{
					break;
				}
			}
			if(!flag)
			{
				break;
			}
			for(k=i;k<=j;++k)
			{
				merge(edges[k].u,edges[k].v);
			}
			i=j;
		}
		if(flag)
		{
			puts("MAGIC");
		}
		else
		{
			puts("NOT MAGIC");
		}
	}
}
