#include<stdio.h>
#include<string.h>

struct BigInteger
{
	unsigned long long num[110];
	int size;
};

struct BigInteger plus(struct BigInteger bi,struct BigInteger b)
{
	struct BigInteger c;
	memset(c.num,0,sizeof(c.num));
	c.size=bi.size;
	if(c.size<b.size)
	{
		c.size=b.size;
	}
	int i;
	for(i=1;i<=c.size;++i)
	{
		c.num[i]+=bi.num[i]+b.num[i];
		c.num[i+1]=c.num[i]/1000000000;
		c.num[i]%=1000000000;
	}
	if(c.num[c.size+1])
	{
		++c.size;
	}
	return c;
}

struct BigInteger mul(struct BigInteger bi,struct BigInteger b)
{
	struct BigInteger c;
	memset(c.num,0,sizeof(c.num));
	int i;
	for(i=1;i<=bi.size;++i)
	{
		int j;
		for(j=1;j<=b.size;++j)
		{
			c.num[i+j-1]+=(bi.num[i]*b.num[j]);
		}
	}
	c.size=bi.size+b.size+2;
	for(i=1;i<=c.size;++i)
	{
		c.num[i+1]+=c.num[i]/1000000000;
		c.num[i]%=1000000000;
	}
	while(!c.num[c.size])
	{
		--c.size;
	}
	return c;
}

void print(struct BigInteger bi)
{
	printf("%llu",bi.num[bi.size]);
	int i;
	for(i=bi.size-1;i>0;--i)
	{
		printf("%09llu",bi.num[i]);
	}
	putchar('\n');
}

struct BigInteger dp[255];
struct BigInteger two;

void buildDP()
{
	dp[0].num[1]=1;
	dp[0].size=1;
	dp[1].num[1]=1;
	dp[1].size=1;
	two.num[1]=2;
	two.size=1;
	int i;
	for(i=2;i<255;++i)
	{
		dp[i]=dp[i-2];
		dp[i]=mul(dp[i],two);
		dp[i]=plus(dp[i],dp[i-1]);
	}
}

int n;

int main()
{
	buildDP();
	while(~scanf("%d",&n))
	{
		print(dp[n/3]);
	}
}
