#include<stdio.h>

int g[2000001],p[2000001],cut,pri[2000001],tot,head[2000001];
unsigned long long n,sum[2000001];

struct data
{
	int next;
	unsigned long long x,v;
};

struct data e[2000001];

void add(int u,unsigned long long v,unsigned long long x)
{
	e[++cut].v=v;
	e[cut].x=x;
	e[cut].next=head[u];
	head[u]=cut;
}

void build()
{
	g[1] = 5;
	int i;
	for (i = 2; i < 2000001; i++)
	{
		g[i] += (i*(1ll * i*i%1000000007 + 3 * i + 1) - g[1]) % 1000000007;
		if (g[i] >= 1000000007)
		{
			g[i] -= 1000000007;
		}
		int j;
		for (j = (i << 1); j < 2000001; j += i)
		{
			g[j] -= g[i];
			if (g[j] < 0)
			{
				g[j] += 1000000007;
			}
		}
		g[i] += g[i - 1];
		if (g[i] >= 1000000007)
		{
			g[i] -= 1000000007;
		}
	}
}

unsigned long long solve(unsigned long long x)
{
	if(x<2000001)
	{
		return g[x];
	}
	unsigned long long ans=0,k=x%23333,last;
	unsigned long long i;
	for(i=head[k]; i; i=e[i].next)
	{
		if(e[i].v==x)
		{
			return e[i].x;
		}
	}
	for(i=2; i<=x; i=last+1)
	{
		last=x/(x/i);
		ans=(ans+(last-i+1)%1000000007*solve(x/i)%1000000007)%1000000007;
	}
	ans=((x%1000000007*(x+1)%1000000007)%1000000007*((x+1)%1000000007*(x+4)%1000000007)%1000000007*250000002%1000000007-ans+1000000007)%1000000007;
	add(k,x,ans);
	return ans;
}

void wr(unsigned long long x)
{
	if (x > 9)
	{
		wr(x / 10);
	}
	putchar(x % 10 + 48);
}

int main()
{
	build();
	while(scanf("%llu", &n) != EOF)
	{
		wr(solve(n));
		putchar('\n');
	}
	return 0;
}