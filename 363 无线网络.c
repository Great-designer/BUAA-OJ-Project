#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node
{
	double x,y;
};

struct node nodes[510];

struct edge
{
	int u,v;
	double w;
};

int compare(const void*p1,const void*p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	return a->w>b->w;
}

struct edge edges[250010];

int f[510];
int n,m,k;
int p,q;
int cnt;
double res;

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
			if(cnt==n-k)
			{
				printf("%.2lf\n",edges[i].w);
			}
		}
		if(cnt==n-1)
		{
			break;
		}
	}
}

int T;
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		initFather();
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%lf%lf",&nodes[i].x,&nodes[i].y);
		}
		m=0;
		for(i=1;i<=n;++i)
		{
			int j;
			for(j=i+1;j<=n;++j)
			{
				edges[m].u=i;
				edges[m].v=j;
				edges[m++].w=sqrt((nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y)+(nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x));
			}
		}
		qsort(edges,m,sizeof(struct edge),compare);
		if(n==k)
		{
			printf("0.00\n");
		}
		else
		{
			kruskal();
		}
	}
}


