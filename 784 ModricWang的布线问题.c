#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct edge
{
	int u,v;
	int w;
};

int compare(const void*p1,const void*p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	return a->w>b->w;
}

struct edge edges[600100];

int f[10100];
int n,m;
int p,q;
int cnt;
long long res;

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

void write(long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

int read()
{
	int k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+c-48;
		c=getchar();
	}
	return k;
}

void kruskal()
{
	cnt=0,res=0;
	int i;
	for(i=0;i<m;++i)
	{
		p=getFather(edges[i].u);
		q=getFather(edges[i].v);
		if(p!=q)
		{
			f[p]=q;
			res+=edges[i].w;
			cnt++;
		}
		if(cnt==n-1)
		{
			break;
		}
	}
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		initFather();
		int i;
		for(i=0;i<m;++i)
		{
			edges[i].u=read();
			edges[i].v=read();
			edges[i].w=read();
		}
		qsort(edges,m,sizeof(struct edge),compare);
		kruskal();
		write(res);
		putchar('\n');
	}
}
