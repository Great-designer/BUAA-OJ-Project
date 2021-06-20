#include<stdio.h>
#include<string.h>

#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

bool occur[305];
int d[305];
int r[305];
int gas[305];
int n,m,oil;
int u,v,w;
int gassize;
int temp;

struct node
{
	int v, w;
	node(int vv=0,int ww=0)
	{
		v=vv;
		w=ww;
	}
	bool operator < (const node& o)const
	{
		return o.w<w;
	}
};

vector<node> g[305];

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

void init()
{
	int i;
	for(i=0;i<305;++i)
	{
		g[i].clear();
		occur[i]=false;
		d[i]=0x3f3f3f3f;
		r[i]=0;
		gas[i]=0;
	}
}

void dijkstra(int s)
{
	priority_queue<node> q;
	d[s]=0;
	r[s]=oil;
	occur[s]=true;
	for(node &a:g[s])
	{
		int v=a.v;
		int w=a.w;
		if(d[v]>w&&oil>=w)
		{
			d[v]=w;
			if(!gas[v])
			{
				r[v]=oil-w;
			}
			q.push(node(v,d[v]));
		}
	}
	while (!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int v=tmp.v;
		if(occur[v])
		{
			continue;
		}
		occur[v]=true;
		for(node &a:g[v])
		{
			int v2=a.v;
			int w=a.w;
			if(d[v2]>d[v]+w&&r[v]>=w)
			{
				d[v2]=w+d[v];
				if(!gas[v2])
				{
					r[v2]=r[v]-w;
				}
				q.push(node(v2,d[v2]));
			}
			else if(d[v2]==d[v]+w&&r[v2]<r[v]-w)
			{
				r[v2]=r[v]-w;
			}
		}
	}
}

int main()
{
	while(~scanf("%d%d%d",&n,&m,&oil))
	{
		oil*=5;
		init();
		while(m--)
		{
			u=read();
			v=read();
			w=read();
			g[u].push_back(node(v,w));
			g[v].push_back(node(u,w));
		}
		gassize=read();
		int i;
		for(i=0;i<gassize;++i)
		{
			temp=read();
			gas[temp]=1;
			r[temp]=oil;
		}
		dijkstra(1);
		if(d[n]!=0x3f3f3f3f&&r[n]>=0)
		{
			write(d[n]);
			putchar('\n');
		}
		else
		{
			write(-1);
			putchar('\n');
		}
	}
}
