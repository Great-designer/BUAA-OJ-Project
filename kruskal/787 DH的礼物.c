#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

struct edge
{
	int u,v;
	unsigned long long g,s;
	char occur;
};

int compare(const void *p1,const void *p2)
{
	struct edge *a=(struct edge*)p1;
	struct edge *b=(struct edge*)p2;
	if(a->g>b->g)
	{
		return 1;
	}
	else if(a->g<b->g)
	{
		return -1;
	}
	else
	{
		if(a->s>b->s)
		{
			return 1;
		}
		else if(a->s<b->s)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
}

struct edge edges[50010],mst[50010],tmp[50010];

int f[410];
unsigned long long n,m,cnt,ans,S,G;

void init()
{
	memset(edges,0,sizeof(edges));
	memset(mst,0,sizeof(mst));
	memset(tmp,0,sizeof(tmp));
	ans=ULLONG_MAX;
	cnt=0;
}

void initFather()
{
	int i;
	for(i=1; i<=n; ++i)
	{
		f[i]=i;
	}
}

int getFather(int x)
{
	return (f[x]==x)?x:(f[x]=getFather(f[x]));
}

void kruskal(unsigned long long maxg)
{
	int i;
	for(i=1; i<=cnt; ++i)
	{
		tmp[i]=mst[i],tmp[i].occur=0;
	}
	unsigned long long maxs=0,tot=0;
	initFather();
	for(i=1; i<=cnt; ++i)
	{
		int a=getFather(mst[i].u);
		int b=getFather(mst[i].v);
		if(a!=b)
		{
			maxs=(maxs>mst[i].s?maxs:mst[i].s);
			f[a]=b;
			tot++;
			tmp[i].occur=1;
		}
		if(tot==n-1)
		{
			int num = 0;
			int j;
			for(j=1; j<=cnt; ++j)
			{
				if(tmp[i].occur)
				{
					mst[++num]=tmp[j];
				}
			}
			cnt=num;
			ans=ans<(maxg+maxs)?ans:(maxg+maxs);
			break;
		}
	}
}

void solve()
{
	unsigned long long i;
	for(i=1; i<=m; ++i)
	{
		if(edges[i].g+edges[i].s>ans)
		{
			continue;
		}
		unsigned long long pos=cnt+1;
		unsigned long long j;
		for(j=1; j<=cnt; ++j)
		{
			if(mst[j].s>edges[i].s)
			{
				pos=j;
				break;
			}
		}
		if(pos==cnt+1)
		{
			mst[++cnt]=edges[i];
		}
		else
		{
			++cnt;
			for(j=cnt; j>=pos+1; --j)
			{
				mst[j]=mst[j-1];
			}
			mst[pos]=edges[i];
		}
		kruskal(edges[i].g);
	}
}

int main()
{
	while(~scanf("%llu%llu",&n,&m))
	{
		init();
		scanf("%llu%llu",&G,&S);
		unsigned long long i;
		for(i=1; i<=m; ++i)
		{
			scanf("%llu%llu%llu%llu",&edges[i].u,&edges[i].v,&edges[i].g,&edges[i].s);
			edges[i].g*=G;
			edges[i].s*=S;
		}
		qsort(edges+1,m,sizeof(struct edge),compare);
		solve();
		if(ans==ULLONG_MAX)
		{
			puts("-1");
		}
		else
		{
			printf("%llu\n",ans);
		}
	}
}
