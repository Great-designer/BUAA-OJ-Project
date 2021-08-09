#include<stdio.h>
#include<string.h>

#include<algorithm>
#include<queue>
#include<map>

using namespace std;

void write(unsigned long long st)
{
	if(st>9)
	{
		write(st/10);
	}
	putchar(st%10+48);
}

unsigned long long read()
{
	unsigned long long k=0;
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

unsigned long long dis[1010][1010];
unsigned long long cost[1010];

struct node
{
	unsigned long long v,w;
	node(unsigned long long vv=0,unsigned long long ww=0)
	{
		v=vv;
		w=ww;
	}
	bool operator <(const node &o)const
	{
		return o.w<w;
	}
};

map<unsigned long long,unsigned long long> g[1010];
unsigned long long n,m,start,finish,u,v,w,t,c;
bool occur[1010];

void init()
{
	memset(dis,0,sizeof(dis));
	memset(cost,0,sizeof(cost));
	int i;
	for(i=0;i<1010;++i)
	{
		g[i].clear();
	}
}

void initdis(unsigned long long *d)
{
	int i;
	for(i=1;i<=n;++i)
	{
		d[i]=1000000000000000000LL;
		occur[i]=false;
	}
}

void dijstra(unsigned long long s,unsigned long long* d)
{
	priority_queue<node>q;
	q.push(node(s,0));
	initdis(d);
	d[s]=0;
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		v = tmp.v;
		if(occur[v])
		{
			continue;
		}
		occur[v]=true;
		map<unsigned long long, unsigned long long>::iterator edge;
		for(edge=g[v].begin();edge!=g[v].end();edge++)
		{
			unsigned long long v2=edge->first;
			unsigned long long w=edge->second;
			if(!occur[v2]&&d[v2]>w+d[v])
			{
				d[v2]=w+d[v];
				q.push(node(v2,d[v2]));
			}
		}
	}
}

int main()
{
	while(~scanf("%llu%llu",&n,&m))
	{
		init();
		start=read();
		finish=read();
		unsigned long long i;
		for(i=0;i<m;++i)
		{
			u=read();
			v=read();
			w=read();
			if(u!=v)
			{
				if(!g[u].count(v)||g[u][v]>w)
				{
					g[u][v]=w;
				}
				if(!g[v].count(u)||g[v][u]>w)
				{
					g[v][u]=w;
				}
			}
		}
		for(i=1;i<=n;++i)
		{
			dijstra(i,dis[i]);
		}
		for(i=1;i<=n;++i)
		{
			g[i].clear();
		}
		for(i=1;i<=n;++i)
		{
			t=read();
			c=read();
			unsigned long long j;
			for(j=1;j<=n;++j) 
			{
				if(i!=j&&dis[i][j]<=t)
				{
					g[i][j]=c;
				}
			}
		}
		dijstra(start,cost);
		if(cost[finish]<1000000000000000000LL)
		{
			write(cost[finish]);
			putchar('\n');
		}
		else
		{
			puts("-1");
		}
	}
}
