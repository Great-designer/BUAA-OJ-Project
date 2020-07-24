#include<stdio.h>
#include<string.h>

int lo,mi,hi;
int n,m;
int r[1000010],d[1000010],s[1000010],t[1000010];
int sum[1000010];

char judge(int x)
{
	memset(sum,0,sizeof(sum));
	int i;
	for(i=1;i<=x;++i)
	{
		sum[s[i]]+=d[i];
		sum[t[i]+1]-=d[i];
	}
	if(sum[1]>r[1])
	{
		return 1;
	}
	for(i=2;i<=n;++i)
	{
		sum[i]+=sum[i-1];
		if(sum[i]>r[i])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&r[i]);
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&d[i],&s[i],&t[i]);
	}
	lo=1;
	hi=m;
	while(lo<hi)
	{
		mi=(lo+hi)>>1;
		if(judge(mi))
		{
			hi=mi;
		}
		else
		{
			lo=mi+1;
		}
	}
	if(hi<m)
	{
		printf("-1\n%d\n",hi);
	}
	else
	{
		puts("0");
	}
}
