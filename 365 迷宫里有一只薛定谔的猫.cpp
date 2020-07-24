#include<stdio.h>
#include<string.h>

#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

bool occur[510];
unsigned short d[510];
int n,m;
unsigned short x,y,t;

struct node
{
	unsigned short v,w;
	node(short vv=0,short ww=0)
	{
		v=vv;
		w=ww;
	}
	bool operator < (const node& a) const
	{
		return a.w<w;
	}
};

vector<node> g[510];

void init()
{
	unsigned short i;
	for(i=0;i<510;++i)
	{
		g[i].clear();
		occur[i]=false;
		d[i]=50010;
	}
}

void dijkstra(int s)
{
	priority_queue<node>q;
	q.push(node(s,0));
	d[s]=0;
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		unsigned short v=tmp.v;
		if(occur[v])
		{
			continue;
		}
		occur[v]=true;
		int i;
		for(i=0;i<g[v].size();++i)
		{
			unsigned short v2=g[v][i].v;
			unsigned short w=g[v][i].w;
			if(!occur[v2]&&d[v2]>w+d[v])
			{
				d[v2]=w+d[v];
				q.push(node(v2,d[v2]));
			}
		}
	}
}

unsigned short read()
{
	short k=0;
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

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		init();
		int i;
		for(i=0;i<m;++i)
		{
			x=read();
			y=read();
			t=read();
			g[x].push_back(node(y,t));
		}
		if(n==1)
		{
			printf("0.00\n");
			continue;
		}
		dijkstra(1);
		double res=0;
		for(i=2;i<=n;++i)
		{
			res+=d[i];
		}
		res/=(n-1);
		printf("%.2lf\n",res);
	}
}
