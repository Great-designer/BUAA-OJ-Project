#include<stdio.h>
#include<stdlib.h>

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

struct edge edges[60100];

int f[2010];
int n,m,r;
int p,q;
int cnt1;
long long res;
int cnt;
int u,v,w;

void initFather()
{
	int i;
	for(i=1;i<=n+m+1;++i)
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
	cnt1=0;
	res=0;
	int i;
	for(i=0;i<cnt;++i)
	{
		p=getFather(edges[i].u);
		q=getFather(edges[i].v);
		if(p!=q)
		{
			f[p]=q;
			res+=edges[i].w;
			cnt1++;
		}
		if(cnt1==n+m)
		{
			break;
		}
	}
}

void addEdge(int u,int v,int w)
{
	edges[cnt].u=2+u;
	edges[cnt].v=2+n+v;
	edges[cnt++].w=1000-w;
	edges[cnt].u=2+n+v;
	edges[cnt].v=2+u;
	edges[cnt++].w=1000-w;
}

void addOrigin()
{
	int i;
	for(i=2;i<=n+m+1;++i)
	{
		edges[cnt].u=1;
		edges[cnt].v=i;
		edges[cnt++].w=1000;
		edges[cnt].u=i;
		edges[cnt].v=1;
		edges[cnt++].w=1000;
	}
}

int t;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		r=read();
		initFather();
		cnt=0;
		int i;
		for(i=0;i<r;++i)
		{
			u=read();
			v=read();
			w=read();
			addEdge(u,v,w);
		}
		addOrigin();
		qsort(edges,cnt,sizeof(struct edge),compare);
		kruskal();
		write(res);
		putchar('\n');
	}
}


