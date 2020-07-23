#include<stdio.h>
#include<string.h>

#include<queue>
#include<vector>

using namespace std;

bool occur[1010];
int d[1010];
int cost[1010];
int n,m,k;
int x,y,t,p;
int start,finish;

struct node
{
	int v,w,c;
	node(int vv=0,int ww=0,int cc=0)
	{
		v=vv;
		w=ww;
		c=cc;
	}
	bool operator < (const node &a) const
	{
		if(a.w==w)
		{
			return a.c<c;
		}
		else
		{
			return a.w<w;
		}
	}
};

vector<node>g[1010];

void init()
{
	int i;
	for(i=0;i<1010;++i)
	{
		g[i].clear();
		occur[i]=false;
		d[i]=0x3f3f3f3f;
		cost[i]=0;
	}
}

void dijkstra(int s)
{
	priority_queue<node>q;
	q.push(node(s,0,cost[s]));
	d[s]=0;
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int v=tmp.v;
		if(occur[v])
		{
			continue;
		}
		occur[v]=true;
		int i;
		for(i=0;i<g[v].size();++i)
		{
			int v2=g[v][i].v;
			int w=g[v][i].w;
			int c=g[v][i].c;
			if(!occur[v2]&&d[v2]>w+d[v])
			{
				d[v2]=w+d[v];
				cost[v2]=c+cost[v];
				q.push(node(v2,d[v2],cost[v2]));
			}
			else if(!occur[v2]&&d[v2]==w+d[v])
			{
				if(cost[v2]>c+cost[v])
				{
					cost[v2]=c+cost[v];
				}
			}
		}
	}
}

void write(int x)
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

int main()
{
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		init();
		int i;
		for(i=0;i<m;++i)
		{
			x=read();
			y=read();
			t=read();
			p=read();
			g[x].push_back(node(y,t,p));
			g[y].push_back(node(x,t,p));
		}
		start=read();
		finish=read();
		dijkstra(start);
		write(d[finish]);
		putchar(' ');
		write(cost[finish]);
		putchar('\n');
	}
}
