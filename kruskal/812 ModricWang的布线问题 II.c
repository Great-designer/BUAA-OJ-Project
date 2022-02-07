#include<stdio.h>
#include<stdlib.h>

struct edge
{
	int u,v;
	int w;
};

struct edge edges[600100];

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

int f[10100];
int n,m,skip;
int u,v,w;
int mine;
char flag;
int p,q;
int cnt;
int top;
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
	cnt=0,res=flag?mine:0;
	int i;
	for(i=0;i<top;++i)
	{
		p=getFather(edges[i].u);
		q=getFather(edges[i].v);
		if(p!=q)
		{
			f[p]=q;
			res+=edges[i].w;
			cnt++;
		}
		if(cnt==n-2)
		{
			break;
		}
	}
}

int main()
{
	while(~scanf("%d%d%d",&n,&m,&skip))
	{
		mine=0x3f3f3f3f;
		flag=0;
		top=0;
		initFather();
		int i;
		for(i=0;i<m;++i)
		{
			u=read();
			v=read();
			w=read();
			if(u!=skip&&v!=skip)
			{
				edges[top].u=u;
				edges[top].v=v;
				edges[top++].w=w;
			}
			else
			{
				flag=1;
				mine=(mine<w?mine:w);
			}
		}
		qsort(edges,top,sizeof(struct edge),compare);
		kruskal();
		write(res);
		putchar('\n');
	}
}
