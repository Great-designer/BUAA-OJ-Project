#include<stdio.h>
#include<stdlib.h>

#include<map>

using namespace std;

map<int,int> intMap;
int n;

int c[1000010];

void init(int n)
{
	int i;
	for(i=0;i<=n;++i)
	{
		c[i]=0;
	}
}

void add(int loc,int v)
{
	while(loc<=n)
	{
		c[loc]+=v;
		loc+=loc&(-loc);
	}
}

int sum(int loc)
{
	int ret=0;
	while(loc)
	{
		ret+=c[loc];
		loc-=loc&(-loc);
	}
	return ret;
}

struct query
{
	int l,r,id;
};

int compare(const void*p1,const void*p2)
{
	struct query *a=(struct query*)p1;
	struct query *b=(struct query*)p2;
	if(a->r<b->r)
	{
		return 1;
	}
	else if(a->r>b->r)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

struct query querys[1000010];

int ans[1000010];
int a[1000010];
int q;

int main()
{
	while(~scanf("%d%d",&n,&q))
	{
		intMap.clear();
		init(n);
		int i;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<q;++i)
		{
			scanf("%d",&querys[i].l);
			querys[i].r=n;
			querys[i].id=i;
		}
		qsort(querys,q,sizeof(struct query),compare);
		int cur=1;
		for(i=0;i<q;++i)
		{
			int j;
			for(j=cur;j<=querys[i].r;++j)
			{
				if(intMap.count(a[j]))
				{
					add(intMap[a[j]],-1);
				}
				add(j,1);
				intMap[a[j]]=j;
			}
			cur=querys[i].r+1;
			ans[querys[i].id]=sum(querys[i].r)-sum(querys[i].l-1);
		}
		for(i=0;i<q;++i)
		{
			printf("%d\n",ans[i]);
		}
	}
}
