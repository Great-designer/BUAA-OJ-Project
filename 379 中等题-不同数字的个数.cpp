#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<map>

using namespace std;

map<int,int> intMap;
int n;

struct bit
{
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
};

struct bit t;

void write(int first)
{
	if(first<0)
	{
		putchar('-');
		first=-first;
	}
	if(first>9)
	{
		write(first/10);
	}
	putchar(first%10+48);
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
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}

struct query
{
	int l,r,id;
};

int compare(const void*p1,const void*p2)
{
	struct query *a=(struct query*)p1;
	struct query *b=(struct query*)p2;
	return a->r<b->r;
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
		t.init(n);
		int i;
		for(i=1;i<=n;++i)
		{
			a[i]=read();
		}
		for(i=0;i<q;++i)
		{
			querys[i].l=read();
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
					t.add(intMap[a[j]],-1);
				}
				t.add(j,1);
				intMap[a[j]]=j;
			}
			cur=querys[i].r+1;
			ans[querys[i].id]=t.sum(querys[i].r)-t.sum(querys[i].l - 1);
		}
		for(i=0;i<q;++i)
		{
			printf("%d\n",ans[i]);
		}
	}
}
