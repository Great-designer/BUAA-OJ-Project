#include<stdio.h>
#include<math.h>

#include<map>
#include<algorithm>

using namespace std;

map<unsigned long long, unsigned long long> costmap;

void write(unsigned long long x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
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

unsigned long long q;
unsigned long long op,u,v,w;
unsigned long long ret;

void addEdge(unsigned long long u,unsigned long long v,unsigned long long w)
{
	while(u!=v)
	{
		if(log(u)>log(v))
		{
			costmap[u]+=w;
			u>>=1;
		}
		else
		{
			costmap[v]+=w;
			v>>=1;
		}
	}
}

void getCost(unsigned long long u,unsigned long long v)
{
	ret=0;
	while(u!=v)
	{
		if(log(u)>log(v))
		{
			ret+=costmap[u];
			u>>=1;
		}
		else
		{
			ret+=costmap[v];
			v>>=1;
		}
	}
	write(ret),putchar('\n');
}

int main()
{
	while(~scanf("%llu",&q))
	{
		costmap.clear();
		while(q--)
		{
			op=read();
			if(op==1)
			{
				u=read(),v=read(),w=read();
				addEdge(u,v,w);
			}
			else
			{
				u=read(),v=read();
				getCost(u,v);
			}
		}
	}
}
