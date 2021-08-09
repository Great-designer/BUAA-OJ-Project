#include<stdio.h>
#include<string.h>

#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct node
{
	int v,w;
	node(int vv=0,int ww=0)
	{
		v=vv;
		w=ww; 
	}
	bool operator <(const node &o)const
	{
		return o.w<w;
	}
};

vector<node> g[2333];

int n,m;
char s[2333][2333];
bool occur[2333];
int d[2333];

void init()
{
	int i;
	for(i=0;i<2333;++i)
	{
		g[i].clear();
	}
	memset(s,0,sizeof(s));
}

void dijkstra(int s)
{
	int i;
	for(i=0;i<2333;++i)
	{
		d[i]=0x3f3f3f3f;
		occur[i]=false;
	}
	priority_queue<node> q;
	q.push(node(s,0));
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
	while(~scanf("%d%d",&n,&m))
	{
		init();
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<n;++i)
		{
			int j;
			for(j=0;j<m;++j)
			{
				if(s[i][j]=='#')
				{
					g[i].push_back(node(j+n,1));
					g[j+n].push_back(node(i,1));
				}
			}
		}
		dijkstra(0);
		if(d[n-1]!=0x3f3f3f3f)
		{
			printf("%d\n",d[n-1]);
		}
		else
		{
			puts("-1");
		}
	}
}
