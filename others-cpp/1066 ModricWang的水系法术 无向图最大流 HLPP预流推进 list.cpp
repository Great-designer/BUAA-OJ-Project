#include<stdio.h>
#include<limits.h>

#include<algorithm>
#include<queue>
#include<list>
#include<vector>

using namespace std;

struct edge
{
	int to,flow,next;
	edge(int to,int flow,int next):to(to),flow(flow),next(next) {}
};

vector<edge> a[1203];
vector<int> llist[1203],h,cnt,que,e;
vector<list<int>::iterator> iter;
list<int> dlist[1203];

int hst,nowh;

void addEdge(const int u,const int v,const int f)
{
	a[u].push_back(edge(v,f,a[v].size()));
	a[v].push_back(edge(u,f,a[u].size()-1));
}

void relabel(int n,int t)
{
	h.assign(n,n);
	h[t]=0;
	cnt.assign(n,0);
	que.clear();
	que.resize(n+1);
	int qh=0,qt=0;
	for(que[qt++]=t; qh<qt;)
	{
		int u=que[qh++],het=h[u]+1;
		for(vector<edge>::iterator p=a[u].begin(); p!=a[u].end(); ++p)
		{
			if(h[p->to]==n&&a[p->to][p->next].flow>0)
			{
				cnt[h[p->to]=het]++;
				que[qt++]=p->to;
			}
		}
	}
	for(int i=0; i<=n; ++i)
	{
		llist[i].clear();
		dlist[i].clear();
	}
	for(int u=0; u<n; ++u)
	{
		if(h[u]<n)
		{
			iter[u]=dlist[h[u]].insert(dlist[h[u]].begin(),u);
			if(e[u]>0)llist[h[u]].push_back(u);
		}
	}
	hst=(nowh=h[que[qt-1]]);
}

void push(int u,edge &ed)
{
	int v=ed.to;
	int df=::min(e[u],ed.flow);
	ed.flow-=df;
	a[v][ed.next].flow+=df;
	e[u]-=df;
	e[v]+=df;
	if(0<e[v]&&e[v]<=df)llist[h[v]].push_back(v);
}

void push(int n,int u)
{
	int nh=n;
	for(vector<edge>::iterator p=a[u].begin(); p!=a[u].end(); ++p)
	{
		if(p->flow>0)
		{
			if(h[u]==h[p->to]+1)
			{
				push(u,*p);
				if(e[u]==0)return;
			}
			else nh=min(nh,h[p->to]+1);
		}
	}
	int het=h[u];
	if(cnt[het]==1)
	{
		for(int i=het; i<=hst; ++i)
		{
			for(list<int>::iterator it=dlist[i].begin(); it!=dlist[i].end(); ++it)
			{
				cnt[h[*it]]--;
				h[*it]=n;
			}
			dlist[i].clear();
		}
		hst=het-1;
	}
	else
	{
		cnt[het]--;
		iter[u]=dlist[het].erase(iter[u]);
		h[u]=nh;
		if(nh==n)return;
		cnt[nh]++;
		iter[u]=dlist[nh].insert(dlist[nh].begin(),u);
		hst=max(hst,nowh=nh);
		llist[nh].push_back(u);
	}
}

int hlpp(int n,int s,int t)
{
	if(s==t)return 0;
	nowh=0;
	hst=0;
	h.assign(n,0);
	h[s]=n;
	iter.resize(n);
	for(int i=0; i<n; ++i)if(i!=s)iter[i]=dlist[h[i]].insert(dlist[h[i]].begin(),i);
	cnt.assign(n,0);
	cnt[0]=n-1;
	e.assign(n,0);
	e[s]=INT_MAX;
	e[t]=-INT_MAX;
	for(int i=0; i<(int)a[s].size(); ++i)push(s,a[s][i]);
	relabel(n,t);
	for(int u; nowh>=0;)
	{
		if(llist[nowh].empty())
		{
			nowh--;
			continue;
		}
		u=llist[nowh].back();
		llist[nowh].pop_back();
		push(n,u);
	}
	return e[t]+INT_MAX;
}

int read()
{
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}

int n,m,s,t,u,v,f;

int main()
{
	n=read(),m=read(),s=1,t=n;
	for(int i=m; i>0; --i)
	{
		u=read(),v=read(),f=read();
		addEdge(u,v,f);
	}
	printf("%d",hlpp(n+1,s,t));
	return 0;
}
