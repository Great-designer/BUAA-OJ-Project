#include<stdio.h>
#include<string.h>

long long k,p;
long long f[50010][16][16];
long long c[20][20];
int T;
int n;

long long dp(int i,int j,int k)
{
	if(~f[i][j][k])
	{
		return f[i][j][k];
	}
	if(i<=3)
	{
		return f[i][j][k]=0;
	}
	long long ret=0;
	ret+=dp(i-1,2*j%k,k);
	ret%=1000000007;
	ret+=dp(i-1,(2*j+1)%k,k);
	ret%=1000000007;
	if(j%k==1)
	{
		ret+=c[8*j%k][k];
		ret%=1000000007;
	}
	return f[i][j][k]=ret;
}

int main()
{
	memset(f,-1,sizeof f);
	int i;
	for(i=0;i<=15;i++)
	{
		int k;
		for(k=1;k<=15;k++)
		{
			int j;
			for(j=i;j<=i+7;j++)
			{
				if(j%k==1)
				{
					++c[i][k];
				}
			}
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%d%lld",&k,&n,&p);
		if(k>=15)
		{
			puts("0");
			continue;
		}
		p%=k;
		printf("%lld\n",dp((int)n,(int)p,(int)k));
	}
	return 0;
}
