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

struct edge edges[600100];

int f[10100];
int n;

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
	return (f[x]==x)?x:(f[x]=getFather(f[x]));
}

int m;
int p,q;
int cnt;
long long res;

void kruskal()
{
	cnt=0;
	res=0;
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
			scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
		}
		qsort(edges,m,sizeof(struct edge),compare);
		kruskal();
		printf("%lld\n",res);
	}
}
