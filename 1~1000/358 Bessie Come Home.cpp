#include<stdio.h>
#include<ctype.h>

#include<queue>
#include<vector>

using namespace std;

int read()
{
	char c=getchar();
	while(isspace(c))
	{
		c=getchar();
	}
	if(islower(c))
	{
		return c-'a'+1;
	}
	else
	{
		return c-'A'+27;
	}
}

int Trans(int a)
{
	if(a<=26)
	{
		return a+'a'-1;
	}
	else
	{
		return a+'A'-27;
	}
}

bool occur[55];
int d[55];
int m;
int x,y,t;

struct node
{
	int v,w;
	node(int vv=0,int ww=0)
	{
		v=vv;
		w=ww;
	}
	bool operator < (const node& o) const
	{
		return o.w<w;
	}
};

vector<node> g[55];

void init()
{
	int i;
	for(i=0;i<55;++i)
	{
		g[i].clear();
		occur[i]=false;
		d[i]=0x3f3f3f3f;
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
	scanf("%d",&m);
	init();
	int i;
	for(i=0;i<m;++i)
	{
		x=read();
		y=read();
		scanf("%d",&t);
		g[x].push_back(node(y,t));
		g[y].push_back(node(x,t));
	}
	dijkstra(52);
	int ans=d[27],idx=27;
	for(i=27;i<52;++i)
	{
		if(ans>d[i])
		{
			ans=d[i];
			idx=i;
		}
	}
	putchar(Trans(idx));
	putchar(' ');
	printf("%d\n",d[idx]);
}
