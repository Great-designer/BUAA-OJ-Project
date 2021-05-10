#include<stdio.h>

void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}

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

int n,m;
int Root;
int u,v;
int op,x,y;

struct Edge
{
	int u,v,next;
};

struct Edge edges[100010<<1];

int head[100010],cnt;

void addEdge(int x,int y)
{
	edges[++cnt].u=x;
	edges[cnt].v=y;
	edges[cnt].next=head[x];
	head[x]=cnt;
}

int inDegree[100010];
int topColor[100010];
int color[100010];
int curTop;
int top[100010],id[100010],time;

void dfs(int u,int fa)
{
	top[u]=curTop;
	id[u]=++time;
	int k; 
	for(k=head[u];k;k=edges[k].next)
	{
		if(edges[k].v!=fa)
		{
			dfs(edges[k].v,u);
		}
	}
}

int mapc[100010];

void init(int n)
{
	int i;
	for(i=0;i<=n;++i)
	{
		mapc[i]=0;
	}
}

void add(int loc,int v)
{
	while(loc<=time)
	{
		mapc[loc]+=v;
		loc+=loc&(-loc);
	}
}

int sum(int loc)
{
	int ret=0;
	while(loc)
	{
		ret+=mapc[loc];
		loc-=loc&(-loc);
	}
	return ret;
}

int query(int l,int r)
{
	return sum(r)-sum(l-1);
}

int main()
{
	n=read();
	Root=0;
	while(--n)
	{
		u=read();
		v=read();
		addEdge(v,u);
		addEdge(u,v);
		if(++inDegree[u]>inDegree[Root])
		{
			Root=u;
		}
		if(++inDegree[v]>inDegree[Root])
		{
			Root=v;
		}
	}
	int k;
	for(k=head[Root];k;k=edges[k].next)
	{
		curTop=edges[k].v;
		dfs(edges[k].v,Root);
	}
	init(time);
	m=read();
	while(m--)
	{
		op=read();
		if(op==1||op==2)
		{
			x=read();
			int realx=x<<1;
			if(edges[realx].u==Root)
			{
				topColor[edges[realx].v]=1-topColor[edges[realx].v];
			}
			else if(edges[realx].v==Root)
			{
				topColor[edges[realx].u]=1-topColor[edges[realx].u];
			}
			else
			{
				int addId=id[edges[realx].u]>id[edges[realx].v]?id[edges[realx].u]:id[edges[realx].v];
				add(addId,color[addId]==0?+1:-1);
				color[addId]=1-color[addId];
			}
		}
		else
		{
			int colorsum=0,dis=0;
			x=read();
			y=read();
			if(x==y)
			{
				puts("0");
			}
			else
			{
				if(top[x]==top[y])
				{
					int idx=id[x]<id[y]?id[x]:id[y];
					int idy=id[x]>id[y]?id[x]:id[y];
					colorsum=query(idx+1,idy);
					dis=idy-idx;
				}
				else
				{
					if(x!=Root)
					{
						colorsum+=query(id[top[x]],id[x])+topColor[x];
						dis+=id[x]-id[top[x]]+1;
					}
					if(y!=Root)
					{
						colorsum+=query(id[top[y]],id[y])+topColor[y];
						dis+=id[y]-id[top[y]]+1;
					}
				}
				if(colorsum)
				{
					puts("-1");
				}
				else
				{
					printf("%d\n",dis);
				}
			}
		}
	}
}
